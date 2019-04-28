//
// Created by Ashwin Mishra on 2019-02-28.
//

#include "lag.h"
#include <stack>
#include <iostream>
#include <queue>
using namespace std;

NState::NState():endId(-1){}
NState::NState(vector<NState*>& v, int char_, NState* out1,
               NState* out2, int endId)
  : char_(char_), out1(out1), out2(out2), outNum(0), endId(endId){
  index = v.size();
  v.push_back(this);
}

NState::~NState() {}

NStateFrag::NStateFrag(){}
NStateFrag::NStateFrag(NState* start, NState** out1, NState** out2)
  : start(start), out1(out1), out2(out2) {
}

void NStateFrag::connectState(NState* state) {
  if (this->out1 != NULL) {
    *(this->out1) = state;
  }
  if (this->out2 != NULL) {
    *(this->out2) = state;
  }
}

NFA::~NFA() {
  BOOST_FOREACH(NState* it, _states) {
    delete it;
  }
}

NFA::NFA() {}

NFA::NFA(vector<int> regex, int endId) {
  vector<int>& postfix = _regToPostfix(regex);
  vector<NState*>& states = _states;
  NStateFrag sf1, sf2;
  stack<NStateFrag> nfragStack;
  #define POP(sf) \
    sf = nfragStack.top();\
    nfragStack.pop();
  #define PUSH(p, s1, s2) \
    nfragStack.push(NStateFrag(p, s1, s2));
  NState* state;
  NState* state1;
  #define STATE_NEW(state, char_, out1, out2)\
    state = new NState(states, char_, out1, out2);

  BOOST_FOREACH(int char_, postfix) {
    switch (char_) {
      default:
        STATE_NEW(state, char_, NULL, NULL);
        PUSH(state, &state->out1, &state->out2);
        break;
      case RegexEntry::CAT:
        POP(sf2);
        POP(sf1);
        sf1.connectState(sf2.start);
        PUSH(sf1.start, sf2.out1, sf2.out2);
        break;
      case RegexEntry::OR:
        POP(sf2);
        POP(sf1);
        STATE_NEW(state, NState::LAMBDA, sf1.start, sf2.start);
        STATE_NEW(state1, NState::LAMBDA, NULL, NULL);
        sf1.connectState(state1);
        sf2.connectState(state1);
        PUSH(state, &state1->out1, &state1->out2);
        break;
      case RegexEntry::QUEST:
        POP(sf1);
        STATE_NEW(state, NState::LAMBDA, sf1.start, NULL);
        PUSH(state, sf1.out1, &state->out1);
        break;
      case RegexEntry::STAR:
        POP(sf1);
        STATE_NEW(state, NState::LAMBDA, sf1.start, NULL);
        sf1.connectState(state);
        PUSH(state, &(state->out2), NULL);
        break;
      case RegexEntry::PLUS:
        POP(sf1);
        STATE_NEW(state, NState::LAMBDA, sf1.start, NULL);
        sf1.connectState(state);
        PUSH(sf1.start, &(state->out2), NULL);
        break;
    }
  }
  POP(sf1);
  assert(nfragStack.empty());
  _start.out1 = sf1.start;
  STATE_NEW(state, NState::END, NULL, NULL);
  state->endId = endId;
  sf1.connectState(state);
}

void NFA::_setFlag(int flag) {
  BOOST_FOREACH(NState* state, _states) {
    state->flag = flag;
  }
}

NFA* NFA::connectNFA(NFA* nfa1, NFA* nfa2) {
  NFA* nfa = new NFA();
  vector<NState*>& states = nfa->_states;
  nfa1->_setFlag(-1);
  nfa2->_setFlag(-1);
  NState* state = new NState(states, NState::LAMBDA, NULL, NULL);
  state->out1 = _connectNFAInner(states, nfa1->_start.out1);
  state->out2 = _connectNFAInner(states, nfa2->_start.out1);
  nfa->_start.out1 = state;
  return nfa;
}

NState* NFA::_connectNFAInner(vector<NState*>& states, NState* o_state) {
  if (o_state->flag != -1)
    return states[o_state->flag];
  NState* state = new NState(states, o_state->char_, NULL, NULL, o_state->endId);
  o_state->flag = state->index;
  if (o_state->out1 != NULL) {
    state->out1 = _connectNFAInner(states, o_state->out1);
  }
  if (o_state->out2 != NULL) {
    state->out2 = _connectNFAInner(states, o_state->out2);
  }
  return state;
}

NFA* NFA::connectNFA(vector<NFA*>& nfas) {
  NFA* nfa = NULL;
  BOOST_FOREACH(NFA* n, nfas) {
    nfa = nfa == NULL ? n : connectNFA(nfa, n);
  }
  return nfa;
}

vector<int>& NFA::_regToPostfix(vector<int>& reg) {
  stack<int> symbolStack;
  vector<int>  reg2;
  bool add = false;
  bool first = true;
  BOOST_FOREACH(int char_, reg) {
    if (add && !first
        && char_ != RegexEntry::RIGHT_PTH
        && char_ != RegexEntry::OR
        && char_ != RegexEntry::STAR
        && char_ != RegexEntry::PLUS
        && char_ != RegexEntry::QUEST) {
      reg2.push_back(RegexEntry::CAT);
    }
    reg2.push_back(char_);
    if (!add)
      add = true;
    if (char_ == RegexEntry::OR)
      add = false;
    if (first && char_)
      first = false;
    if (char_ == RegexEntry::LEFT_PTH)
      first = true;
  }
  #define POP_SYMBOL()\
    if (symbolStack.size() != 0\
        && symbolStack.top() != RegexEntry::LEFT_PTH) {\
      result.push_back(symbolStack.top());\
      symbolStack.pop();\
    }
  reg.clear();
  vector<int>& result = reg;
  BOOST_FOREACH(int c, reg2) {
    switch(c) {
      default:
        result.push_back(c); 
        break;
      case RegexEntry::RIGHT_PTH:
        POP_SYMBOL();
        while (symbolStack.top() != RegexEntry::LEFT_PTH ) {
          POP_SYMBOL();
        }
        symbolStack.pop();
        break;
      case RegexEntry::PLUS:
      case RegexEntry::STAR:
        result.push_back(c);
        POP_SYMBOL();
        break;
      case RegexEntry::OR:
      case RegexEntry::CAT:
        while (!symbolStack.empty()
               && symbolStack.top() != RegexEntry::LEFT_PTH
               && symbolStack.top() <= c) {
          POP_SYMBOL();
        }
        symbolStack.push(c);
        break;
      case RegexEntry::LEFT_PTH:
        symbolStack.push(c);
        break;
    }
  } 
  while(!symbolStack.empty()) {
    POP_SYMBOL();
  }
  assert(symbolStack.empty());
  return result;
}

void NFA::_nfaTravel(NState* state, _func func) {
  if (state->flag != 0)
    return;
  state->flag = 1;
  func(state);
  if (state->out1 != NULL)
    _nfaTravel(state->out1, func);
  if (state->out2 != NULL)
    _nfaTravel(state->out2, func);
}

void NFA::nfaTravel(_func func) {
  _setFlag(0);
  _nfaTravel(_start.out1, func);
}

set<int>& NFA::_getLambda(NState* state, set<int>& result) {
  if (result.find(state->index) != result.end())
    return result;
  
  map<int, set<int> >::iterator mapFind = _lambdaCache.find(state->index);
  if (mapFind != _lambdaCache.end()) {
    set<int>& fr = (*mapFind).second;
    result.insert(fr.begin(), fr.end());
    return fr;
  }
  result.insert(state->index);
  if (state->char_ == NState::LAMBDA) {
    if (state->out1 != NULL) {
      _getLambda(state->out1, result);
    }
    if (state->out2 != state->out1 && state->out2 != NULL) {
      _getLambda(state->out2, result);
    }
  }
  _lambdaCache[state->index] = result;
  return _lambdaCache[state->index];
}

set<int>& NFA::getLambda(NState* state) {
  map<int, set<int> >::iterator mapFind = _lambdaCache.find(state->index);
  if (mapFind != _lambdaCache.end()) {
    set<int>& fr = (*mapFind).second;
    return fr;
  }
  set<int> result;
  return _getLambda(state, result);
}

set<int>& NFA::getLambda(set<int>& states) {
  map<set<int>, set<int> >::iterator mapFind = _lambdaSetCache.find(states);
  if (mapFind != _lambdaSetCache.end()) {
    set<int>& fr = (*mapFind).second;
    return fr;
  }
  set<int> result;
  BOOST_FOREACH(int item, states) {
    _getLambda(_states[item], result);
  }
  _lambdaSetCache[states] = result;
  return _lambdaSetCache[states];
}

DFA* NFA::constructDFA() {

  map<set<int>, DState*> states;
  queue<set<int> > squeue;
  set<set<int> > dstateIdLogger;
  #define SQUEUE_PUSH(item)\
    squeue.push(item);\
    dstateIdLogger.insert(item);\

  NState* start = _start.out1;
  set<int>& result = getLambda(start);
  SQUEUE_PUSH(result);
  bool first = true;
  while(!squeue.empty()) {
    set<int>& s_set = squeue.front();
    DState* d_state = new DState(s_set);
    d_state->isFirst = first;
    first = false;
    map<int, set<int> >& next_states = d_state->nextStates;
    states[s_set] = d_state;
    BOOST_FOREACH(int item, s_set) {
      NState* state = _states[item];
      if (state->char_ == NState::LAMBDA)
        continue;
      int convertChar = state->char_;
      if (state->out1 != NULL) {
        set<int>& next_set = next_states[convertChar];
        next_set.insert(state->out1->index);
      } else {
        d_state->isEnd = true;
        if (d_state->endId == -1 || d_state->endId > state->endId) {
          d_state->endId = state->endId;
        }
      }
      if (state->out1 != NULL && state->out2 != NULL)
        assert(state->out1 == state->out2);
    }

    typedef map<int, set<int> > map_t;
    BOOST_FOREACH(map_t::value_type& item, next_states) {
      set<int>& tmp = getLambda(item.second);
      item.second = tmp;
      if (dstateIdLogger.find(tmp) == dstateIdLogger.end()) {
        SQUEUE_PUSH(tmp);
      }
    }
    squeue.pop();
  }

  DFA* dfa = new DFA(states);
  typedef map<set<int>, DState*> map_t;
  BOOST_FOREACH (map_t::value_type& item, states) {
    DState* ds = item.second;
    delete ds;
  }
  return dfa;
}

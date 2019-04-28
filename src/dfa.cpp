//
// Created by Ashwin Mishra on 2019-02-28.
//

#include "lag.h"
#include <iostream>
#include <queue>

const int BUFFER_SIZE = 128;
const int BUFFER_SIZE_SMALL = 64;

DFA::DFA(map<set<int>, DState*>& states) {
  #define GET_STATE_BY_ID(state, old_state)\
    if (id_map.find(old_state->identifier) == id_map.end()) {\
      state = new DFAState();\
      state->identifier = _states.size();\
      state->isEnd = old_state->isEnd;\
      state->isFirst = old_state->isFirst;\
      state->endId = old_state->endId;\
      if (state->isFirst)\
        _first = state->identifier;\
      _states.push_back(state);\
      id_map[old_state->identifier] = state->identifier;\
    } else {\
      state = _states[id_map[old_state->identifier]];\
    }

  typedef map<set<int>, DState*> map_t;
  map<set<int>, int> id_map;
  BOOST_FOREACH(map_t::value_type& item, states) {
    DState* dstate = item.second;
    DFAState* dfa_state;
    GET_STATE_BY_ID(dfa_state, dstate);
    typedef map<int, set<int> > map_set_t;
    BOOST_FOREACH(map_set_t::value_type& item_ms, dstate->nextStates) {
      const int convert_char = item_ms.first;
      const set<int>& next_id = item_ms.second;
      DFAState* next_dfa_state;
      GET_STATE_BY_ID(next_dfa_state, states[next_id]);
      dfa_state->nexts[convert_char] = next_dfa_state->identifier;
    }
  }
}

DFA::~DFA() {
  _releaseStates(_states);
}

int DFA::match(string input) {
  int id = _first;
  BOOST_FOREACH(char c, input) {
    DFAState* state = _states[id];
    if (state->nexts.find(c) == state->nexts.end())
      return false;
    id = state->nexts[c];
  }
  return _states[id]->endId;
}

void DFA::print(ostream& os, vector<DFAState*>& states) {
  os << endl << endl << endl;
  os << "================= SPLIT LINE ==============" <<endl;

  typedef map<int, int> map_t;
  int max = 0;
  BOOST_FOREACH (DFAState* state, states) {
    os << state->identifier << " end?:" << state->isEnd << "\t";
    os << state->identifier << " end_id:" << state->endId << "\t";
    os << " first?:" << state->isFirst<< "\t";
    BOOST_FOREACH(map_t::value_type item_m, state->nexts) {
      os << (char)item_m.first << " => " << item_m.second << "\n";
      if(item_m.second > max){
        max = item_m.second;
      }
    }
    os << endl;
  }
  cout << "MAX STATE " << max << endl;

  os << endl << endl << endl;
}

void DFA::minimize() {
  int setIterator = 256;
  int* setLog = new int[_states.size()];
  memset(setLog, setIterator, sizeof(int) * _states.size());
  _divideByEnd(setIterator, setLog);
  _divideByOutputKey(setIterator, setLog);
  _divideByNext(setIterator, setLog);
  vector<DFAState*> minStates;
  map<int, int> idMap;
  BOOST_FOREACH(DFAState* state, _states) {
    _constructMinDFA(state, minStates, idMap, setLog);
  }
  ofstream dfaFile;
  dfaFile.open("min_dfa.txt");
  print(dfaFile, minStates);
  dfaFile.close();
  _releaseStates(_states);
  _states.resize(minStates.size());
  copy(minStates.begin(), minStates.end(), _states.begin());
  delete[] setLog;
}

int DFA::_constructMinDFA(DFAState* o_state, vector<DFAState*>& minStates,
                           map<int, int>& idMap, int* setLog) {
  int o_id = o_state->identifier;
  map<int, int>::iterator result = idMap.find(setLog[o_id]);
  if (result != idMap.end()) {
    DFAState* tmp = minStates[(*result).second];
    if (o_state->endId < tmp->endId)
      tmp->endId = o_state->endId;
    if (o_state->isFirst)
      tmp->isFirst = true;
    return (*result).second;
  }
  int id = minStates.size();
  DFAState* state = new DFAState();
  state->identifier = id;
  idMap[setLog[o_id]] = id;
  state->isEnd = o_state->isEnd;
  state->isFirst = o_state->isFirst;
  state->endId = o_state->endId;
  if (state->isFirst)
    _first = state->identifier;
  minStates.push_back(state);
  typedef map<int, int> map_t;
  BOOST_FOREACH(map_t::value_type item_m, o_state->nexts) {
    int nextKey = item_m.first;
    DFAState* next = _states[item_m.second];
    int nextValue = _constructMinDFA(next, minStates, idMap, setLog);
    state->nexts[nextKey] = nextValue;
  }
  return id;
}

void DFA::_divideByEnd(int& setIterator, int* setLog) {
  setIterator++;
  BOOST_FOREACH(DFAState* state, _states) {
    int id = state->identifier;
    if (state->isEnd) {
      setLog[id] = setIterator;
    }
  }
}

void DFA::_divideByOutputKey(int& setIterator, int* setLog) {
  map<set<int>, int> outputLog;
  BOOST_FOREACH(DFAState* state, _states) {
    int id = state->identifier;
    map<int, int>& output = state->nexts;
    set<int> outputSet;
    typedef map<int, int> map_t;
    BOOST_FOREACH(map_t::value_type& item_m, output) {
      outputSet.insert(item_m.first);
    }
    if (state->isEnd)
      outputSet.insert(state->endId);
    outputSet.insert(setLog[id]);
    map<set<int>, int>::iterator result = outputLog.find(outputSet);
    if (result != outputLog.end()) {
      setLog[id] = (*result).second;
    } else {
      setIterator++;
      setLog[id] = setIterator;
      outputLog[outputSet] = setIterator;
    }
  }
}

void DFA::_divideByNext(int& setIterator, int* setLog) {
  map<int, set<int> > equalSets;
  for (unsigned int i = 0; i < _states.size(); i++) {
    map<int, set<int> >::iterator result = equalSets.find(setLog[i]);
    if (result != equalSets.end()) {
      (*result).second.insert(i);
    } else {
      set<int> tmp;
      tmp.insert(i);
      equalSets[setLog[i]] = tmp;
    }
  }
  typedef map<int, set<int> > map_t;
  BOOST_FOREACH(map_t::value_type& item, equalSets) {
    _divideByNextInner(setIterator, setLog, item.second);
  }
}

void DFA::_divideByNextInner(int& setIterator, int* setLog,
                               set<int>& equalSet) {
  if (equalSet.size() == 1)
    return;
  int* setLogOld = new int[_states.size()];
  memcpy(setLogOld, setLog, sizeof(int) * _states.size());
  map<map<int, int>, int> nextLog;
  map<int, set<int> > nextLogSet;
  BOOST_FOREACH(int item, equalSet) {
    DFAState* state = _states[item];
    typedef map<int, int> map_t;
    map<int, int> tmpMap;
    BOOST_FOREACH(map_t::value_type& item_m, state->nexts) {
      tmpMap[item_m.first] = setLogOld[item_m.second];
    }
    map<map<int, int>, int>::iterator result = nextLog.find(tmpMap);
    if (result != nextLog.end()) {
      setLog[item] = (*result).second;
      nextLogSet[(*result).second].insert(item);
    } else {
      setIterator++;
      setLog[item] = setIterator;
      nextLog[tmpMap] = setIterator;
      set<int> tmpSet;
      tmpSet.insert(item);
      nextLogSet[setIterator] = tmpSet;
    }
  }
  if (nextLogSet.size() <= 1)
    return;
  typedef map<int, set<int> > mapSet;
  BOOST_FOREACH(mapSet::value_type item_m, nextLogSet) {
    _divideByNextInner(setIterator, setLog, item_m.second);
  }
  delete[] setLogOld;
}

void DFA::_releaseStates(vector<DFAState*>& states) {
  BOOST_FOREACH(DFAState* state, states) {
    delete state;
  }
  states.clear();
}

void DFA::convertToC(ostream& os) {
  _printHeader(os);
  BOOST_FOREACH(DFAState* state, _states) {
    _printStateChange(os, state);
  }
  _printFooter(os);
}

void DFA::_printHeader(ostream& os) {
  c_code(os,
         "void parse(FILE* file) {",
         "  int state;",
         "  char c;",
         "  char buffer[1024];",
         "  char buffer_index;",
         "");
  _printStateReset(os);
  c_code(os,
         "while (EOF != (c = fgetc(file))) {",
         "  buffer[buffer_index] = c;",
         "  buffer_index++; buffer[buffer_index]='\\0';",
         "  switch(state) {",
         "");
}

void DFA::_printFooter(ostream& os) {
  c_code(os, "  }", "}", "}", "");
}

void DFA::_printStateReset(ostream& os) {
  char tmp[BUFFER_SIZE_SMALL];
  sprintf(tmp, "state = %d;", _first);
  c_code(os,
        "buffer[0] = '\\0';",
        "buffer_index = 0;",
         tmp,
         "");
}

void DFA::_printStateEnd(ostream& os, int endPoint) {
  char end[BUFFER_SIZE_SMALL];
  sprintf(end, "endHandler%d(token);", endPoint);
  c_code(os,
         "Token* token;",
         "NEW_TOKEN(token);",
         end,
         "if (strcmp(token->type, \"\") != 0",
         "   && strcmp(token->type, \"SKIP\") != 0) {",
         "  strcpy(token->value, buffer);",
         "  tail->next = token;",
         "  tail = token;",
         "} else {",
         "  free(token);",
         "}",
         "");
}

void DFA::_printStateChange(ostream& os, DFAState* state) {
  char bf1[BUFFER_SIZE], bf2[BUFFER_SIZE];
  sprintf(bf1, "case %d:", state->identifier);
  c_code(os, bf1, "  switch(c) {", "");
  typedef map<int, int> map_t;
  BOOST_FOREACH (map_t::value_type item, state->nexts) {
    char caseState[4];
    switch(item.first) {
      default:
        caseState[0] = (char)item.first;
        caseState[1] = '\0';
        break;
      case '\n':
        strcpy(caseState, "\\n");
        break;
      case '\r':
        strcpy(caseState, "\\r");
        break;
      case '\t':
        strcpy(caseState, "\\t");
        break;
    }
    sprintf(bf1, "    case '%s':", caseState);
    sprintf(bf2, "      state = %d;", item.second);
    c_code(os, bf1, bf2, "break;", "");
  }
  os   << "    default:" << endl;
  if (state->isEnd) {
    c_code(os,
           "      fseek(file, -1, SEEK_CUR);",
           "      buffer_index--;",
           "      buffer[buffer_index] = '\\0';",
           "");
    _printStateEnd(os, state->endId);
    _printStateReset(os);
  } else {
    c_code(os,
          "      fprintf(stdout, \"Error while parsing : %s\\n\", buffer);",
          "      fprintf(stdout, \"Error while parsing : %d\\n\", buffer[buffer_index - 1]);",
          "      fprintf(stderr, \"Error while parsing\\n\");",
          "      exit(1);", 
          "      break;",
          "");
  }
  c_code(os, "    }", "  break;", "");
}

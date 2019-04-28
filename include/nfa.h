//
// Created by Ashwin Mishra on 2019-02-28.
//

#ifndef LEX_ANALYZER_GENERATOR_NFA_H
#define LEX_ANALYZER_GENERATOR_NFA_H

#include <vector>
#include <map>
#include <set>
#include <string>

using namespace std;

class DFA;

struct NState {
  NState();
  ~NState();
  NState(vector<NState*>& v, int char_=0, NState* out1=NULL,
         NState* out2=NULL, int endId=-1);

  enum StateTag {LAMBDA=-1, END=0};
  int char_;
  int flag;
  NState*  out1;
  NState* out2;
  int index;
  int outNum;
  int endId;
};

struct NStateFrag {
  NState* start;
  NState** out1;
  NState** out2;
  NStateFrag();
  NStateFrag(NState* start, NState** out1, NState** out2=NULL);
  void connectState(NState* state);
};

struct DState {
  DState(){}
  DState(set<int> i, int endId=-1):identifier(i), isEnd(false), endId(endId){}
  set<int> identifier;
  map<int, set<int> > nextStates;
  bool isEnd;
  bool isFirst;
  int endId;
};

class NFA {
  public:
    NFA(vector<int> reg, int endId = 0);
    virtual ~NFA();
    typedef void (* _func)(NState * state);
    set<int>& getLambda(NState* state);
    set<int>& getLambda(set<int>& states);
    static NFA* connectNFA(NFA* nfa1, NFA* nfa2);
    static NFA* connectNFA(vector<NFA*>& nfas);
    void nfaTravel(_func func);
    DFA* constructDFA();
  private:
    NFA();
    NState _start;
    vector<NState*> _states;
    map<int, set<int> > _lambdaCache;
    map<set<int>, set<int> > _lambdaSetCache;
    set<int>& _getLambda(NState* state, set<int>& result);
    void _nfaTravel(NState* state, _func func);
    vector<int>& _regToPostfix(vector<int>& reg);
    void _setFlag(int flag);
    static NState* _connectNFAInner(vector<NState*>& states,
                               NState* o_state); 
};

#endif //LEX_ANALYZER_GENERATOR_NFA_H

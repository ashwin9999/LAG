//
// Created by Ashwin Mishra on 2019-02-28.
//

#ifndef LEX_ANALYZER_GENERATOR_DFA_H
#define LEX_ANALYZER_GENERATOR_DFA_H

#include <map>
#include <set>
#include <vector>
#include <string>

using namespace std;

struct DState;

struct DFAState {
  int identifier; //id of DFA
  map<int, int> nexts; //next states
  bool isEnd; 
  bool isFirst;
  int endId; //regex priority

};

class DFA {
  public:
    DFA(map<set<int>, DState*>& states);
    virtual ~DFA();
    int match(string input);
    void minimize();
    void convertToC(ostream& os);
    void print(ostream& ss, vector<DFAState*>&);
  private:
    vector<DFAState*> _states;
    int _first;
    void _divideByEnd(int& set_iterator, int* set_log);
    void _divideByOutputKey(int& set_iterator, int* set_log);
    void _divideByNext(int& set_iterator, int* set_log);
    void _divideByNextInner(int&, int*, set<int>&);
    int _constructMinDFA(DFAState* o_state, vector<DFAState*>& min_states,
                          map<int, int>& id_map, int* set_log);
    void _releaseStates(vector<DFAState*>& states);
    void _printHeader(ostream& os);
    void _printFooter(ostream& os);
    void _printStateChange(ostream& os, DFAState* state);
    void _printStateReset(ostream& os);
    void _printStateEnd(ostream& os, int end_point);
};

#endif //LEX_ANALYZER_GENERATOR_DFA_H

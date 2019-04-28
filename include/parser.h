//
// Created by Ashwin Mishra on 2019-02-28.
//

#ifndef LEX_ANALYZER_GENERATOR_PARSER_H
#define LEX_ANALYZER_GENERATOR_PARSER_H

#include <vector>
#include <string>
#include <iostream>

using namespace std;


/*
* RegexEntry struct stores the information about the entries in the .lex file
(input specifications).
*/

struct RegexEntry {

  vector<int> regex; //Stores the int value of the regex
  int priority; //The position of the regex in the .lex file
  string regexType; //The type of the regex entry
  RegexEntry(){}
  RegexEntry(string& raw);
  RegexEntry(vector<int>& regex, int priority, string regexType):
    regex(regex), priority(priority), regexType(regexType){}
  void convertToC(ostream& os);
  void setRegex(string& reg_str);
  vector<int> parseBracket(vector<int>& reg);
  // Map of Regex operators
  enum RegexTag {
    PLUS      = -1,  // '+'
    STAR      = -2,  // '*'
    OR        = -3,  // '|'
    CAT       = -4,  // '.'
    LEFT_PTH  = -5,  // '('
    RIGHT_PTH = -6,  // ')'
    QUEST     = -7,  // '?'
    LEFT_BCT  = -8,  // '['
    RIGHT_BCT = -9,  // ']'
    HYPHEN    = -10, // '-'
  };

};

class Parser {
  public:
    Parser(string& filename);
    virtual ~Parser();
    void convertToC(string& filename);
  private:
    vector<RegexEntry> _entries;
    DFA* _dfa;
    string _declaration;
    string _code;
    void _convertToC(ostream& os);
    DFA* _constructDFA(vector<RegexEntry>& entries);
    void _parse(istream& is);
    void _parseDeclaration(istream& is);
    void _parseEntries(istream& is);
    void _parseCode(istream& is);
    void _printInclude(ostream& os);
    void _printMain(ostream& os);
    void _printStructToken(ostream& os);
    void _printHelper(ostream& os);
};

#endif //LEX_ANALYZER_GENERATOR_PARSER_H

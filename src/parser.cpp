//
// Created by Ashwin Mishra on 2019-02-28.
//

#include "lag.h"
#include "parser.h"

const int BUFFER_SIZE = 128;
const int BUFFER_SIZE_SMALL = 64;

RegexEntry::RegexEntry(string& raw) {
  char buffer[BUFFER_SIZE];
  stringstream ss(raw);
  string reg;
  ss >> reg;
  setRegex(reg);
  ss.getline(buffer, BUFFER_SIZE);
  while(buffer[strlen(buffer) -1] != '}') {
    regexType.append(buffer);
    regexType.push_back('\n');
    ss.getline(buffer, BUFFER_SIZE);
  }
  regexType.append(buffer);
}

void RegexEntry::setRegex(string& reg) {
  bool escape = false;
  vector<int> _free;
  BOOST_FOREACH(char c, reg) {
    if (escape) {
      switch(c) {
        default:
          _free.push_back(c);
          break;
        case 'n':
          _free.push_back('\n');
          break;
        case 'r':
          _free.push_back('\r');
          break;
        case 's':
          _free.push_back(' ');
          break;
      }
      escape = false;
    } else {
      switch(c) {
        default:
          _free.push_back(c);
          break;
        case '\\':
          escape = true;
          break;
        case '+':
          _free.push_back(PLUS);
          break;
        case '*':
          _free.push_back(STAR);
          break;
        case '|':
          _free.push_back(OR);
          break;
        case '.':
          _free.push_back(CAT);
          break;
        case '?':
          _free.push_back(QUEST);
          break;
        case '(':
          _free.push_back(LEFT_PTH);
          break;
        case ')':
          _free.push_back(RIGHT_PTH);
          break;
        case '[':
          _free.push_back(LEFT_BCT);
          break;
        case ']':
          _free.push_back(RIGHT_BCT);
          break;
        case '-':
          _free.push_back(HYPHEN);
          break;
      }
    }
  }
  regex = parseBracket(_free);
}

vector<int> RegexEntry::parseBracket(vector<int>& reg) {
  bool bracket = false;
  bool hyphen = false;
  int lastChar;
  vector<int> result;
  BOOST_FOREACH(int c, reg) {
    if (bracket) {
      switch (c) {
        default:
          if (hyphen) {
            hyphen = false;
            for (int i = lastChar + 1; i != c;
                 lastChar < c ? i++ : i--) {
              result.push_back(i);
              result.push_back(OR);
            }
          } else {
            lastChar = c;
          }
          result.push_back(c);
          result.push_back(OR);
          break;
        case HYPHEN:
          hyphen = true;
          break;
        case RIGHT_BCT:
          bracket = false;
          result.pop_back();
          result.push_back(RIGHT_PTH);
          break;
      }
    } else {
      switch (c) {
        default:
          result.push_back(c);
          break;
        case LEFT_BCT:
          result.push_back(LEFT_PTH);
          bracket = true;
          break;
      }
    }
  }
  return result;
}

void RegexEntry::convertToC(ostream& os) {
  char tmp[BUFFER_SIZE];
  sprintf(tmp, "void endHandler%d(Token* token)", priority);
  c_code(os,
         tmp,
         regexType.c_str(),
         "");
}

Parser::Parser(string& filename) {
  ifstream ifs(filename.c_str());
  _parse(ifs);
  ifs.close();
  _dfa = _constructDFA(_entries);
}

Parser::~Parser() {
  delete _dfa;
}

void Parser::_parse(istream& is) {

  char buffer[BUFFER_SIZE_SMALL];
  fgetline(is, buffer, BUFFER_SIZE_SMALL);
  if (strcmp(buffer, "%{") == 0) {
    _parseDeclaration(is);
  } else {
    cerr << "WRONG LEX FORMAT" << endl;
    exit(1);
  }
  fgetline(is, buffer, BUFFER_SIZE_SMALL);
  if (strcmp(buffer, "%%") == 0) {
    _parseEntries(is);
  }
  _parseCode(is);
}

void Parser::_parseDeclaration(istream& is) {
  char buffer[BUFFER_SIZE];
  fgetline(is, buffer, BUFFER_SIZE);
  while (strcmp(buffer, "%}") != 0) {
    _declaration.append(buffer);
    _declaration.push_back('\n');
    fgetline(is, buffer, BUFFER_SIZE);
  }
}
void Parser::_parseEntries(istream& is) {
  char buffer[BUFFER_SIZE];
  fgetline(is, buffer, BUFFER_SIZE);
  int i = 0;
  while (strcmp(buffer, "%%") != 0) {
    string b_str(buffer);
    while(buffer[strlen(buffer) -1] != '}') {
      b_str.push_back('\n');
      fgetline(is, buffer, BUFFER_SIZE);
      b_str.append(buffer);
    }
    RegexEntry re(b_str);
    re.priority = i;
    _entries.push_back(re);
    fgetline(is, buffer, BUFFER_SIZE);
    i++;
  }
}

void Parser::_parseCode(istream& is) {
  char buffer[BUFFER_SIZE];
  while (!is.eof()) {
    fgetline(is, buffer, BUFFER_SIZE);
    _code.append(buffer);
    _code.push_back('\n');
  }
}

DFA* Parser::_constructDFA(vector<RegexEntry>& entries) {
  vector<NFA*> nfas;
  BOOST_FOREACH (RegexEntry& entry, entries) {
    nfas.push_back(new NFA(entry.regex, entry.priority));
  }
  NFA* nfa = NFA::connectNFA(nfas);
  if (nfas.size() > 1) {
    BOOST_FOREACH (NFA* n, nfas) {
      delete n;
    }
  }
  DFA* dfa = nfa->constructDFA();
  delete nfa;
  dfa->minimize();
  return dfa;
}

void Parser::convertToC(string& filename) {
  ofstream ofs(filename.c_str());
  _convertToC(ofs);
  ofs.close();
}

void Parser::_convertToC(ostream& os) {
  _printInclude(os);
  _printStructToken(os);
  BOOST_FOREACH (RegexEntry& entry, _entries) {
    entry.convertToC(os);
  }
  _dfa->convertToC(os);
  _printHelper(os);
  _printMain(os);
}
void Parser::_printInclude(ostream& os) {
  c_code(os,
        "#include <stdio.h>",
        "#include <stdlib.h>",
        "#include <string.h>",
        "");
  os << _declaration << endl;
}
void Parser::_printStructToken(ostream& os) {
  c_code(os,
         "typedef struct _token {",
         "  char type[32];",
         "  char value[32];",
         "  struct _token* next;",
         "} Token;",
         "Token token_list;",
         "Token* tail = &token_list;",
         "#define NEW_TOKEN(t)\\",
         "  t = (Token*)(malloc(sizeof(Token)));\\",
         "  t->next = 0;\\",
         "  strcpy(t->type, \"\");\\",
         "  strcpy(t->value, \"\");",
         "#define INIT_ITER(iter) \\",
         "  iter = token_list.next;",
         "#define ITER_NEXT(iter) (iter = iter->next)",
         "#define ITER_HASNEXT(iter) (iter != NULL && iter->next != NULL)",
         "#define ITER_ISEND(iter) (iter == NULL)",
         "");

}

void Parser::_printMain(ostream& os) {
  os << _code << endl;
}
void Parser::_printHelper(ostream& os) {
  c_code(os,
         "void print_token(Token* token) {",
         "  printf(\"('%s', '%s')\\n\", token->type, token->value);",
         "}",
         "void free_tokens() {",
         "  Token* iter;",
         "  INIT_ITER(iter);",
         "  while(!ITER_ISEND(iter)) {",
         "    Token* tmp = iter;",
         "    ITER_NEXT(iter);",
         "    free(tmp);",
         "  }",
         "}",
         "void yylex(char* input, void (*func)()) {",
         "  FILE* infile;",
         "  infile = fopen(input, \"r\");",
         "  parse(infile);",
         "  fclose(infile);",
         "  func();",
         "  free_tokens();",
         "}",
         "void iter_list(void (*trav_func)(Token*)) {",
         "  Token* iter;",
         "  INIT_ITER(iter);",
         "  while (!ITER_ISEND(iter)) {",
         "    trav_func(iter);",
         "    ITER_NEXT(iter);",
         "  }",
         "}",
         "");
}

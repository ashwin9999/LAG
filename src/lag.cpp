//
// Created by Ashwin Mishra on 2019-02-28.
//

#include "lag.h"
#include "dfa.h"
#include <iostream>

int main(int argc, char ** args) {
  if (argc < 2) {
    cout << "Please enter two files: " << endl;
    cout << "1. Input specifications (See files/input.specs)" << endl;
    cout << "2. An output file for Lexical Analyzer (eg: output.cpp or lexicalAnalyzer.cpp)" << endl;
  }
  cout << "LAG (Lexical Analzer Generator) - Project for Compiler Design by Ashwin Mishra" << endl;
  cout << "------------------------------------------------------------------------------" << endl;
  string input = args[1];
  string outfile = args[2];
  Parser p(input);
  p.convertToC(outfile);
  return 0;
}

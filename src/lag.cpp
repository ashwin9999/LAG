//
// Created by Ashwin Mishra on 2019-02-28.
//

#include "lag.h"
#include "dfa.h"
#include <iostream>

int main(int argc, char ** args) {
  if (argc < 2) {
    cout << "Please enter two files: \n";
    cout << "1. Input specifications (See files/input.specs) \n";
    cout << "2. An output file for Lexical Analyzer (eg: output.cpp or lexicalAnalyzer.cpp) \n";
  }

  cout << "LAG (Lexical Analzer Generator) - Project for Compiler Design by Ashwin Mishra \n";
  cout << "------------------------------------------------------------------------------ \n";

  string input = args[1];
  string outfile = args[2];

  Parser p(input);

  p.convertToC(outfile);
  
  return 0;
}

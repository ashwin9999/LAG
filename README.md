# LAG
Lexical Analyzer Generator

This is a Lexical Analyzer Generator implemented in C++. It reads input specifications and outputs a Lexical Analyzer which can parse C++ code into a token list. 

### How does it work?

(Regex -> Postfix -> NFA -> DFA)

1. Firstly, it parses the input specifications provided via the command-line (in the form of a .lex format file).
2. It then generates a list of NFA for the regex entries. 
3. It combines all the NFAs into one giant NFA. 
4. And then, it converts the NFA to a DFA. 
5. It attempts at minimizing the DFA and finally, generates a Lexical Analyzer (c++ code) from the DFA.


### References used:

https://swtch.com/~rsc/regexp/regexp1.html

https://en.wikipedia.org/wiki/Lex_(software)

https://www.epaperpress.com/lexandyacc/download/lex.pdf

### Compiling and running:


To compile and run the LAG:
```
make 
./lag files/input.specs output.cpp
```

<b> Note: running the make command will give a warning, but that warning can be ignored. It will not give any errors. </b>

This will generate the Lexical Analyzer in the file output.cpp. 
To run the Lexical Analyzer on the test samples.

```
g++ output.cpp -o lex
./lex files/test.cpp
```

### Format for input specifications:

```
%{
	[Declaration]
%}
%%
	[Entry]
%%
	[Code]
```

Reference for this format: https://en.wikipedia.org/wiki/Lex_(software)

### My input specs:

```
%{
#include <iostream>
using namespace std;
int lineNum = 1;
%}
%%
\s|\t|\r {
  strcpy(token->type, "SKIP");
}

\n {
  strcpy(token->type, "SKIP");
  lineNum++;
}

if|else|while|do|break|switch|for|case|struct|typedef|cout|cin {
  strcpy(token->type,"KEYWORD");
}

int|float|double|long|char {
  strcpy(token->type, "TYPE");
}

(un)?signed {
  strcpy(token->type, "TYPE_MODIFIER");
}

#(include|define|undef|ifdef|ifndef|if|endif|elif|else) {
  strcpy(token->type,"PREPROC_DERIV");
}

[a-zA-Z_][a-z0-9A-Z_]* {
  strcpy(token->type, "IDENTIFIER");
}

[1-9][0-9]*|[0-9] {
  strcpy(token->type, "INTEGER");
}

\+|\-|\*|/|% {
  strcpy(token->type, "ARITHMETIC_OP");
}

==|&&|(\|\|)|!|<|>|<=|>= {
  strcpy(token->type, "LOGICAL_OP");
}

^|&|~|\| {
  strcpy(token->type, "BIT_OP");
}

\-> {
  strcpy(token->type, "ACCESS_OP");
}

= {
  strcpy(token->type, "ASSIGN_OP");
}

; {
  strcpy(token->type, "SEMICOLON");
}

\. {
  strcpy(token->type, "DOT");
}

, {
  strcpy(token->type, "COMMA");
}

\[ {
  strcpy(token->type, "LEFT_SQBRAC");
}

\] {
  strcpy(token->type, "RIGHT_SQBRAC");
}

" {
   strcpy(token->type, "QUOTE");
}

<< {
    strcpy(token->type, "LEFT_SHIFT");
}

>> {
    strcpy(token->type, "RIGHT_SHIFT");
}

\( {
  strcpy(token->type, "LEFT_PAREN");
}

\) {
  strcpy(token->type, "RIGHT_PAREN");
}

} {
  strcpy(token->type, "BLOCK_END");
}

{ {
  strcpy(token->type, "BLOCK_START");
}
%%

void print() {
  iter_list(print_token);
  cout << "Number of lines: " <<  lineNum << endl;
}

int main(int argc, char** argv) {
  lexicalAnalyzer(argv[1], print);
  return 0;
}
```

<b>The only part you need to change is this:</b>

```
%%
\s|\t|\r {
  strcpy(token->type, "SKIP");
}

\n {
  strcpy(token->type, "SKIP");
  lineNum++;
}

if|else|while|do|break|switch|for|case|struct|typedef|cout|cin {
  strcpy(token->type,"KEYWORD");
}

int|float|double|long|char {
  strcpy(token->type, "TYPE");
}

(un)?signed {
  strcpy(token->type, "TYPE_MODIFIER");
}

#(include|define|undef|ifdef|ifndef|if|endif|elif|else) {
  strcpy(token->type,"PREPROC_DERIV");
}

[a-zA-Z_][a-z0-9A-Z_]* {
  strcpy(token->type, "IDENTIFIER");
}

[1-9][0-9]*|[0-9] {
  strcpy(token->type, "INTEGER");
}

\+|\-|\*|/|% {
  strcpy(token->type, "ARITHMETIC_OP");
}

==|&&|(\|\|)|!|<|>|<=|>= {
  strcpy(token->type, "LOGICAL_OP");
}

^|&|~|\| {
  strcpy(token->type, "BIT_OP");
}

\-> {
  strcpy(token->type, "ACCESS_OP");
}

= {
  strcpy(token->type, "ASSIGN_OP");
}

; {
  strcpy(token->type, "SEMICOLON");
}

\. {
  strcpy(token->type, "DOT");
}

, {
  strcpy(token->type, "COMMA");
}

\[ {
  strcpy(token->type, "LEFT_SQBRAC");
}

\] {
  strcpy(token->type, "RIGHT_SQBRAC");
}

" {
   strcpy(token->type, "QUOTE");
}

<< {
    strcpy(token->type, "LEFT_SHIFT");
}

>> {
    strcpy(token->type, "RIGHT_SHIFT");
}

\( {
  strcpy(token->type, "LEFT_PAREN");
}

\) {
  strcpy(token->type, "RIGHT_PAREN");
}

} {
  strcpy(token->type, "BLOCK_END");
}

{ {
  strcpy(token->type, "BLOCK_START");
}
%%
```

You can add or remove tokens as needed to test my program. Adding more tokens will increase the number of DFA states, and decreasing the tokens will reduce the number of states. Please do not change the code portion of the input specifications that contain (main and print) functions. 




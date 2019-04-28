# LAG_
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




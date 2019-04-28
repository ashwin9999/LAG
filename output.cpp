#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
int i = 0;

typedef struct _token {
  char type[32];
  char value[32];
  struct _token* next;
} Token;
Token token_list;
Token* tail = &token_list;
#define NEW_TOKEN(t)\
  t = (Token*)(malloc(sizeof(Token)));\
  t->next = 0;\
  strcpy(t->type, "");\
  strcpy(t->value, "");
#define INIT_ITER(iter) \
  iter = token_list.next;
#define ITER_NEXT(iter) (iter = iter->next)
#define ITER_HASNEXT(iter) (iter != NULL && iter->next != NULL)
#define ITER_ISEND(iter) (iter == NULL)
void endHandler0(Token* token)
 {
  strcpy(token->type, "SKIP");
}
void endHandler1(Token* token)
 {
  strcpy(token->type, "SKIP");
  i++;
}
void endHandler2(Token* token)
 {
  strcpy(token->type,"KEYWORD");
}
void endHandler3(Token* token)
 {
  strcpy(token->type, "TYPE");
}
void endHandler4(Token* token)
 {
  strcpy(token->type, "TYPE_MODIFIER");
}
void endHandler5(Token* token)
 {
  strcpy(token->type,"PREPROC_DERIV");
}
void endHandler6(Token* token)
 {
  strcpy(token->type, "IDENTIFIER");
}
void endHandler7(Token* token)
 {
  strcpy(token->type, "INTEGER");
}
void endHandler8(Token* token)
 {
  strcpy(token->type, "ARITHMETIC_OP");
}
void endHandler9(Token* token)
 {
  strcpy(token->type, "LOGICAL_OP");
}
void endHandler10(Token* token)
 {
  strcpy(token->type, "BIT_OP");
}
void endHandler11(Token* token)
 {
  strcpy(token->type, "ACCESS_OP");
}
void endHandler12(Token* token)
 {
  strcpy(token->type, "ASSIGN_OP");
}
void endHandler13(Token* token)
 {
  strcpy(token->type, "SEMICOLON");
}
void endHandler14(Token* token)
 {
  strcpy(token->type, "DOT");
}
void endHandler15(Token* token)
 {
  strcpy(token->type, "COMMA");
}
void endHandler16(Token* token)
 {
  strcpy(token->type, "LEFT_SQBRAC");
}
void endHandler17(Token* token)
 {
  strcpy(token->type, "RIGHT_SQBRAC");
}
void endHandler18(Token* token)
 {
   strcpy(token->type, "QUOTE");
}
void endHandler19(Token* token)
 {
    strcpy(token->type, "FEED_OUT");
}
void endHandler20(Token* token)
 {
    strcpy(token->type, "FEED_IN");
}
void endHandler21(Token* token)
 {
  strcpy(token->type, "LEFT_PAREN");
}
void endHandler22(Token* token)
 {
  strcpy(token->type, "RIGHT_PAREN");
}
void endHandler23(Token* token)
 {
  strcpy(token->type, "BLOCK_END");
}
void endHandler24(Token* token)
 {
  strcpy(token->type, "BLOCK_START");
}
void parse(FILE* file) {
  int state;
  char c;
  char buffer[1024];
  char buffer_index;
buffer[0] = '\0';
buffer_index = 0;
state = 0;
while (EOF != (c = fgetc(file))) {
  buffer[buffer_index] = c;
  buffer_index++; buffer[buffer_index]='\0';
  switch(state) {
case 0:
  switch(c) {
    case '\n':
      state = 1;
break;
    case '\r':
      state = 2;
break;
    case ' ':
      state = 2;
break;
    case '!':
      state = 3;
break;
    case '"':
      state = 4;
break;
    case '#':
      state = 5;
break;
    case '%':
      state = 25;
break;
    case '&':
      state = 26;
break;
    case '(':
      state = 27;
break;
    case ')':
      state = 28;
break;
    case '*':
      state = 25;
break;
    case '+':
      state = 25;
break;
    case ',':
      state = 29;
break;
    case '-':
      state = 30;
break;
    case '.':
      state = 32;
break;
    case '/':
      state = 25;
break;
    case '0':
      state = 33;
break;
    case '1':
      state = 34;
break;
    case '2':
      state = 34;
break;
    case '3':
      state = 34;
break;
    case '4':
      state = 34;
break;
    case '5':
      state = 34;
break;
    case '6':
      state = 34;
break;
    case '7':
      state = 34;
break;
    case '8':
      state = 34;
break;
    case '9':
      state = 34;
break;
    case ';':
      state = 35;
break;
    case '<':
      state = 36;
break;
    case '=':
      state = 38;
break;
    case '>':
      state = 39;
break;
    case 'A':
      state = 41;
break;
    case 'B':
      state = 41;
break;
    case 'C':
      state = 41;
break;
    case 'D':
      state = 41;
break;
    case 'E':
      state = 41;
break;
    case 'F':
      state = 41;
break;
    case 'G':
      state = 41;
break;
    case 'H':
      state = 41;
break;
    case 'I':
      state = 41;
break;
    case 'J':
      state = 41;
break;
    case 'K':
      state = 41;
break;
    case 'L':
      state = 41;
break;
    case 'M':
      state = 41;
break;
    case 'N':
      state = 41;
break;
    case 'O':
      state = 41;
break;
    case 'P':
      state = 41;
break;
    case 'Q':
      state = 41;
break;
    case 'R':
      state = 41;
break;
    case 'S':
      state = 41;
break;
    case 'T':
      state = 41;
break;
    case 'U':
      state = 41;
break;
    case 'V':
      state = 41;
break;
    case 'W':
      state = 41;
break;
    case 'X':
      state = 41;
break;
    case 'Y':
      state = 41;
break;
    case 'Z':
      state = 41;
break;
    case '[':
      state = 42;
break;
    case ']':
      state = 43;
break;
    case '^':
      state = 26;
break;
    case '_':
      state = 41;
break;
    case 'a':
      state = 41;
break;
    case 'b':
      state = 44;
break;
    case 'c':
      state = 49;
break;
    case 'd':
      state = 58;
break;
    case 'e':
      state = 63;
break;
    case 'f':
      state = 64;
break;
    case 'g':
      state = 41;
break;
    case 'h':
      state = 41;
break;
    case 'i':
      state = 69;
break;
    case 'j':
      state = 41;
break;
    case 'k':
      state = 41;
break;
    case 'l':
      state = 70;
break;
    case 'm':
      state = 41;
break;
    case 'n':
      state = 41;
break;
    case 'o':
      state = 41;
break;
    case 'p':
      state = 41;
break;
    case 'q':
      state = 41;
break;
    case 'r':
      state = 41;
break;
    case 's':
      state = 73;
break;
    case 't':
      state = 86;
break;
    case 'u':
      state = 41;
break;
    case 'v':
      state = 41;
break;
    case 'w':
      state = 92;
break;
    case 'x':
      state = 41;
break;
    case 'y':
      state = 41;
break;
    case 'z':
      state = 41;
break;
    case '{':
      state = 95;
break;
    case '|':
      state = 96;
break;
    case '}':
      state = 97;
break;
    case '~':
      state = 26;
break;
    default:
      fprintf(stdout, "Error while parsing : %s\n", buffer);
      fprintf(stdout, "Error while parsing : %d\n", buffer[buffer_index - 1]);
      fprintf(stderr, "Error while parsing\n");
      exit(1);
      break;
    }
  break;
case 1:
  switch(c) {
    default:
      fseek(file, -1, SEEK_CUR);
      buffer_index--;
      buffer[buffer_index] = '\0';
Token* token;
NEW_TOKEN(token);
endHandler1(token);
if (strcmp(token->type, "") != 0
   && strcmp(token->type, "SKIP") != 0) {
  strcpy(token->value, buffer);
  tail->next = token;
  tail = token;
} else {
  free(token);
}
buffer[0] = '\0';
buffer_index = 0;
state = 0;
    }
  break;
case 2:
  switch(c) {
    default:
      fseek(file, -1, SEEK_CUR);
      buffer_index--;
      buffer[buffer_index] = '\0';
Token* token;
NEW_TOKEN(token);
endHandler0(token);
if (strcmp(token->type, "") != 0
   && strcmp(token->type, "SKIP") != 0) {
  strcpy(token->value, buffer);
  tail->next = token;
  tail = token;
} else {
  free(token);
}
buffer[0] = '\0';
buffer_index = 0;
state = 0;
    }
  break;
case 3:
  switch(c) {
    default:
      fseek(file, -1, SEEK_CUR);
      buffer_index--;
      buffer[buffer_index] = '\0';
Token* token;
NEW_TOKEN(token);
endHandler9(token);
if (strcmp(token->type, "") != 0
   && strcmp(token->type, "SKIP") != 0) {
  strcpy(token->value, buffer);
  tail->next = token;
  tail = token;
} else {
  free(token);
}
buffer[0] = '\0';
buffer_index = 0;
state = 0;
    }
  break;
case 4:
  switch(c) {
    default:
      fseek(file, -1, SEEK_CUR);
      buffer_index--;
      buffer[buffer_index] = '\0';
Token* token;
NEW_TOKEN(token);
endHandler18(token);
if (strcmp(token->type, "") != 0
   && strcmp(token->type, "SKIP") != 0) {
  strcpy(token->value, buffer);
  tail->next = token;
  tail = token;
} else {
  free(token);
}
buffer[0] = '\0';
buffer_index = 0;
state = 0;
    }
  break;
case 5:
  switch(c) {
    case 'd':
      state = 6;
break;
    case 'e':
      state = 12;
break;
    case 'i':
      state = 17;
break;
    case 'u':
      state = 24;
break;
    default:
      fprintf(stdout, "Error while parsing : %s\n", buffer);
      fprintf(stdout, "Error while parsing : %d\n", buffer[buffer_index - 1]);
      fprintf(stderr, "Error while parsing\n");
      exit(1);
      break;
    }
  break;
case 6:
  switch(c) {
    case 'e':
      state = 7;
break;
    default:
      fprintf(stdout, "Error while parsing : %s\n", buffer);
      fprintf(stdout, "Error while parsing : %d\n", buffer[buffer_index - 1]);
      fprintf(stderr, "Error while parsing\n");
      exit(1);
      break;
    }
  break;
case 7:
  switch(c) {
    case 'f':
      state = 8;
break;
    default:
      fprintf(stdout, "Error while parsing : %s\n", buffer);
      fprintf(stdout, "Error while parsing : %d\n", buffer[buffer_index - 1]);
      fprintf(stderr, "Error while parsing\n");
      exit(1);
      break;
    }
  break;
case 8:
  switch(c) {
    case 'i':
      state = 9;
break;
    default:
      fprintf(stdout, "Error while parsing : %s\n", buffer);
      fprintf(stdout, "Error while parsing : %d\n", buffer[buffer_index - 1]);
      fprintf(stderr, "Error while parsing\n");
      exit(1);
      break;
    }
  break;
case 9:
  switch(c) {
    case 'n':
      state = 10;
break;
    default:
      fprintf(stdout, "Error while parsing : %s\n", buffer);
      fprintf(stdout, "Error while parsing : %d\n", buffer[buffer_index - 1]);
      fprintf(stderr, "Error while parsing\n");
      exit(1);
      break;
    }
  break;
case 10:
  switch(c) {
    case 'e':
      state = 11;
break;
    default:
      fprintf(stdout, "Error while parsing : %s\n", buffer);
      fprintf(stdout, "Error while parsing : %d\n", buffer[buffer_index - 1]);
      fprintf(stderr, "Error while parsing\n");
      exit(1);
      break;
    }
  break;
case 11:
  switch(c) {
    default:
      fseek(file, -1, SEEK_CUR);
      buffer_index--;
      buffer[buffer_index] = '\0';
Token* token;
NEW_TOKEN(token);
endHandler5(token);
if (strcmp(token->type, "") != 0
   && strcmp(token->type, "SKIP") != 0) {
  strcpy(token->value, buffer);
  tail->next = token;
  tail = token;
} else {
  free(token);
}
buffer[0] = '\0';
buffer_index = 0;
state = 0;
    }
  break;
case 12:
  switch(c) {
    case 'l':
      state = 13;
break;
    case 'n':
      state = 15;
break;
    default:
      fprintf(stdout, "Error while parsing : %s\n", buffer);
      fprintf(stdout, "Error while parsing : %d\n", buffer[buffer_index - 1]);
      fprintf(stderr, "Error while parsing\n");
      exit(1);
      break;
    }
  break;
case 13:
  switch(c) {
    case 'i':
      state = 14;
break;
    case 's':
      state = 10;
break;
    default:
      fprintf(stdout, "Error while parsing : %s\n", buffer);
      fprintf(stdout, "Error while parsing : %d\n", buffer[buffer_index - 1]);
      fprintf(stderr, "Error while parsing\n");
      exit(1);
      break;
    }
  break;
case 14:
  switch(c) {
    case 'f':
      state = 11;
break;
    default:
      fprintf(stdout, "Error while parsing : %s\n", buffer);
      fprintf(stdout, "Error while parsing : %d\n", buffer[buffer_index - 1]);
      fprintf(stderr, "Error while parsing\n");
      exit(1);
      break;
    }
  break;
case 15:
  switch(c) {
    case 'd':
      state = 16;
break;
    default:
      fprintf(stdout, "Error while parsing : %s\n", buffer);
      fprintf(stdout, "Error while parsing : %d\n", buffer[buffer_index - 1]);
      fprintf(stderr, "Error while parsing\n");
      exit(1);
      break;
    }
  break;
case 16:
  switch(c) {
    case 'i':
      state = 14;
break;
    default:
      fprintf(stdout, "Error while parsing : %s\n", buffer);
      fprintf(stdout, "Error while parsing : %d\n", buffer[buffer_index - 1]);
      fprintf(stderr, "Error while parsing\n");
      exit(1);
      break;
    }
  break;
case 17:
  switch(c) {
    case 'f':
      state = 18;
break;
    case 'n':
      state = 20;
break;
    default:
      fprintf(stdout, "Error while parsing : %s\n", buffer);
      fprintf(stdout, "Error while parsing : %d\n", buffer[buffer_index - 1]);
      fprintf(stderr, "Error while parsing\n");
      exit(1);
      break;
    }
  break;
case 18:
  switch(c) {
    case 'd':
      state = 6;
break;
    case 'n':
      state = 19;
break;
    default:
      fseek(file, -1, SEEK_CUR);
      buffer_index--;
      buffer[buffer_index] = '\0';
Token* token;
NEW_TOKEN(token);
endHandler5(token);
if (strcmp(token->type, "") != 0
   && strcmp(token->type, "SKIP") != 0) {
  strcpy(token->value, buffer);
  tail->next = token;
  tail = token;
} else {
  free(token);
}
buffer[0] = '\0';
buffer_index = 0;
state = 0;
    }
  break;
case 19:
  switch(c) {
    case 'd':
      state = 6;
break;
    default:
      fprintf(stdout, "Error while parsing : %s\n", buffer);
      fprintf(stdout, "Error while parsing : %d\n", buffer[buffer_index - 1]);
      fprintf(stderr, "Error while parsing\n");
      exit(1);
      break;
    }
  break;
case 20:
  switch(c) {
    case 'c':
      state = 21;
break;
    default:
      fprintf(stdout, "Error while parsing : %s\n", buffer);
      fprintf(stdout, "Error while parsing : %d\n", buffer[buffer_index - 1]);
      fprintf(stderr, "Error while parsing\n");
      exit(1);
      break;
    }
  break;
case 21:
  switch(c) {
    case 'l':
      state = 22;
break;
    default:
      fprintf(stdout, "Error while parsing : %s\n", buffer);
      fprintf(stdout, "Error while parsing : %d\n", buffer[buffer_index - 1]);
      fprintf(stderr, "Error while parsing\n");
      exit(1);
      break;
    }
  break;
case 22:
  switch(c) {
    case 'u':
      state = 23;
break;
    default:
      fprintf(stdout, "Error while parsing : %s\n", buffer);
      fprintf(stdout, "Error while parsing : %d\n", buffer[buffer_index - 1]);
      fprintf(stderr, "Error while parsing\n");
      exit(1);
      break;
    }
  break;
case 23:
  switch(c) {
    case 'd':
      state = 10;
break;
    default:
      fprintf(stdout, "Error while parsing : %s\n", buffer);
      fprintf(stdout, "Error while parsing : %d\n", buffer[buffer_index - 1]);
      fprintf(stderr, "Error while parsing\n");
      exit(1);
      break;
    }
  break;
case 24:
  switch(c) {
    case 'n':
      state = 19;
break;
    default:
      fprintf(stdout, "Error while parsing : %s\n", buffer);
      fprintf(stdout, "Error while parsing : %d\n", buffer[buffer_index - 1]);
      fprintf(stderr, "Error while parsing\n");
      exit(1);
      break;
    }
  break;
case 25:
  switch(c) {
    default:
      fseek(file, -1, SEEK_CUR);
      buffer_index--;
      buffer[buffer_index] = '\0';
Token* token;
NEW_TOKEN(token);
endHandler8(token);
if (strcmp(token->type, "") != 0
   && strcmp(token->type, "SKIP") != 0) {
  strcpy(token->value, buffer);
  tail->next = token;
  tail = token;
} else {
  free(token);
}
buffer[0] = '\0';
buffer_index = 0;
state = 0;
    }
  break;
case 26:
  switch(c) {
    case '&':
      state = 3;
break;
    default:
      fseek(file, -1, SEEK_CUR);
      buffer_index--;
      buffer[buffer_index] = '\0';
Token* token;
NEW_TOKEN(token);
endHandler10(token);
if (strcmp(token->type, "") != 0
   && strcmp(token->type, "SKIP") != 0) {
  strcpy(token->value, buffer);
  tail->next = token;
  tail = token;
} else {
  free(token);
}
buffer[0] = '\0';
buffer_index = 0;
state = 0;
    }
  break;
case 27:
  switch(c) {
    default:
      fseek(file, -1, SEEK_CUR);
      buffer_index--;
      buffer[buffer_index] = '\0';
Token* token;
NEW_TOKEN(token);
endHandler21(token);
if (strcmp(token->type, "") != 0
   && strcmp(token->type, "SKIP") != 0) {
  strcpy(token->value, buffer);
  tail->next = token;
  tail = token;
} else {
  free(token);
}
buffer[0] = '\0';
buffer_index = 0;
state = 0;
    }
  break;
case 28:
  switch(c) {
    default:
      fseek(file, -1, SEEK_CUR);
      buffer_index--;
      buffer[buffer_index] = '\0';
Token* token;
NEW_TOKEN(token);
endHandler22(token);
if (strcmp(token->type, "") != 0
   && strcmp(token->type, "SKIP") != 0) {
  strcpy(token->value, buffer);
  tail->next = token;
  tail = token;
} else {
  free(token);
}
buffer[0] = '\0';
buffer_index = 0;
state = 0;
    }
  break;
case 29:
  switch(c) {
    default:
      fseek(file, -1, SEEK_CUR);
      buffer_index--;
      buffer[buffer_index] = '\0';
Token* token;
NEW_TOKEN(token);
endHandler15(token);
if (strcmp(token->type, "") != 0
   && strcmp(token->type, "SKIP") != 0) {
  strcpy(token->value, buffer);
  tail->next = token;
  tail = token;
} else {
  free(token);
}
buffer[0] = '\0';
buffer_index = 0;
state = 0;
    }
  break;
case 30:
  switch(c) {
    case '>':
      state = 31;
break;
    default:
      fseek(file, -1, SEEK_CUR);
      buffer_index--;
      buffer[buffer_index] = '\0';
Token* token;
NEW_TOKEN(token);
endHandler8(token);
if (strcmp(token->type, "") != 0
   && strcmp(token->type, "SKIP") != 0) {
  strcpy(token->value, buffer);
  tail->next = token;
  tail = token;
} else {
  free(token);
}
buffer[0] = '\0';
buffer_index = 0;
state = 0;
    }
  break;
case 31:
  switch(c) {
    default:
      fseek(file, -1, SEEK_CUR);
      buffer_index--;
      buffer[buffer_index] = '\0';
Token* token;
NEW_TOKEN(token);
endHandler11(token);
if (strcmp(token->type, "") != 0
   && strcmp(token->type, "SKIP") != 0) {
  strcpy(token->value, buffer);
  tail->next = token;
  tail = token;
} else {
  free(token);
}
buffer[0] = '\0';
buffer_index = 0;
state = 0;
    }
  break;
case 32:
  switch(c) {
    default:
      fseek(file, -1, SEEK_CUR);
      buffer_index--;
      buffer[buffer_index] = '\0';
Token* token;
NEW_TOKEN(token);
endHandler14(token);
if (strcmp(token->type, "") != 0
   && strcmp(token->type, "SKIP") != 0) {
  strcpy(token->value, buffer);
  tail->next = token;
  tail = token;
} else {
  free(token);
}
buffer[0] = '\0';
buffer_index = 0;
state = 0;
    }
  break;
case 33:
  switch(c) {
    default:
      fseek(file, -1, SEEK_CUR);
      buffer_index--;
      buffer[buffer_index] = '\0';
Token* token;
NEW_TOKEN(token);
endHandler7(token);
if (strcmp(token->type, "") != 0
   && strcmp(token->type, "SKIP") != 0) {
  strcpy(token->value, buffer);
  tail->next = token;
  tail = token;
} else {
  free(token);
}
buffer[0] = '\0';
buffer_index = 0;
state = 0;
    }
  break;
case 34:
  switch(c) {
    case '0':
      state = 34;
break;
    case '1':
      state = 34;
break;
    case '2':
      state = 34;
break;
    case '3':
      state = 34;
break;
    case '4':
      state = 34;
break;
    case '5':
      state = 34;
break;
    case '6':
      state = 34;
break;
    case '7':
      state = 34;
break;
    case '8':
      state = 34;
break;
    case '9':
      state = 34;
break;
    default:
      fseek(file, -1, SEEK_CUR);
      buffer_index--;
      buffer[buffer_index] = '\0';
Token* token;
NEW_TOKEN(token);
endHandler7(token);
if (strcmp(token->type, "") != 0
   && strcmp(token->type, "SKIP") != 0) {
  strcpy(token->value, buffer);
  tail->next = token;
  tail = token;
} else {
  free(token);
}
buffer[0] = '\0';
buffer_index = 0;
state = 0;
    }
  break;
case 35:
  switch(c) {
    default:
      fseek(file, -1, SEEK_CUR);
      buffer_index--;
      buffer[buffer_index] = '\0';
Token* token;
NEW_TOKEN(token);
endHandler13(token);
if (strcmp(token->type, "") != 0
   && strcmp(token->type, "SKIP") != 0) {
  strcpy(token->value, buffer);
  tail->next = token;
  tail = token;
} else {
  free(token);
}
buffer[0] = '\0';
buffer_index = 0;
state = 0;
    }
  break;
case 36:
  switch(c) {
    case '<':
      state = 37;
break;
    case '=':
      state = 3;
break;
    default:
      fseek(file, -1, SEEK_CUR);
      buffer_index--;
      buffer[buffer_index] = '\0';
Token* token;
NEW_TOKEN(token);
endHandler9(token);
if (strcmp(token->type, "") != 0
   && strcmp(token->type, "SKIP") != 0) {
  strcpy(token->value, buffer);
  tail->next = token;
  tail = token;
} else {
  free(token);
}
buffer[0] = '\0';
buffer_index = 0;
state = 0;
    }
  break;
case 37:
  switch(c) {
    default:
      fseek(file, -1, SEEK_CUR);
      buffer_index--;
      buffer[buffer_index] = '\0';
Token* token;
NEW_TOKEN(token);
endHandler19(token);
if (strcmp(token->type, "") != 0
   && strcmp(token->type, "SKIP") != 0) {
  strcpy(token->value, buffer);
  tail->next = token;
  tail = token;
} else {
  free(token);
}
buffer[0] = '\0';
buffer_index = 0;
state = 0;
    }
  break;
case 38:
  switch(c) {
    case '=':
      state = 3;
break;
    default:
      fseek(file, -1, SEEK_CUR);
      buffer_index--;
      buffer[buffer_index] = '\0';
Token* token;
NEW_TOKEN(token);
endHandler12(token);
if (strcmp(token->type, "") != 0
   && strcmp(token->type, "SKIP") != 0) {
  strcpy(token->value, buffer);
  tail->next = token;
  tail = token;
} else {
  free(token);
}
buffer[0] = '\0';
buffer_index = 0;
state = 0;
    }
  break;
case 39:
  switch(c) {
    case '=':
      state = 3;
break;
    case '>':
      state = 40;
break;
    default:
      fseek(file, -1, SEEK_CUR);
      buffer_index--;
      buffer[buffer_index] = '\0';
Token* token;
NEW_TOKEN(token);
endHandler9(token);
if (strcmp(token->type, "") != 0
   && strcmp(token->type, "SKIP") != 0) {
  strcpy(token->value, buffer);
  tail->next = token;
  tail = token;
} else {
  free(token);
}
buffer[0] = '\0';
buffer_index = 0;
state = 0;
    }
  break;
case 40:
  switch(c) {
    default:
      fseek(file, -1, SEEK_CUR);
      buffer_index--;
      buffer[buffer_index] = '\0';
Token* token;
NEW_TOKEN(token);
endHandler20(token);
if (strcmp(token->type, "") != 0
   && strcmp(token->type, "SKIP") != 0) {
  strcpy(token->value, buffer);
  tail->next = token;
  tail = token;
} else {
  free(token);
}
buffer[0] = '\0';
buffer_index = 0;
state = 0;
    }
  break;
case 41:
  switch(c) {
    case '0':
      state = 41;
break;
    case '1':
      state = 41;
break;
    case '2':
      state = 41;
break;
    case '3':
      state = 41;
break;
    case '4':
      state = 41;
break;
    case '5':
      state = 41;
break;
    case '6':
      state = 41;
break;
    case '7':
      state = 41;
break;
    case '8':
      state = 41;
break;
    case '9':
      state = 41;
break;
    case 'A':
      state = 41;
break;
    case 'B':
      state = 41;
break;
    case 'C':
      state = 41;
break;
    case 'D':
      state = 41;
break;
    case 'E':
      state = 41;
break;
    case 'F':
      state = 41;
break;
    case 'G':
      state = 41;
break;
    case 'H':
      state = 41;
break;
    case 'I':
      state = 41;
break;
    case 'J':
      state = 41;
break;
    case 'K':
      state = 41;
break;
    case 'L':
      state = 41;
break;
    case 'M':
      state = 41;
break;
    case 'N':
      state = 41;
break;
    case 'O':
      state = 41;
break;
    case 'P':
      state = 41;
break;
    case 'Q':
      state = 41;
break;
    case 'R':
      state = 41;
break;
    case 'S':
      state = 41;
break;
    case 'T':
      state = 41;
break;
    case 'U':
      state = 41;
break;
    case 'V':
      state = 41;
break;
    case 'W':
      state = 41;
break;
    case 'X':
      state = 41;
break;
    case 'Y':
      state = 41;
break;
    case 'Z':
      state = 41;
break;
    case '_':
      state = 41;
break;
    case 'a':
      state = 41;
break;
    case 'b':
      state = 41;
break;
    case 'c':
      state = 41;
break;
    case 'd':
      state = 41;
break;
    case 'e':
      state = 41;
break;
    case 'f':
      state = 41;
break;
    case 'g':
      state = 41;
break;
    case 'h':
      state = 41;
break;
    case 'i':
      state = 41;
break;
    case 'j':
      state = 41;
break;
    case 'k':
      state = 41;
break;
    case 'l':
      state = 41;
break;
    case 'm':
      state = 41;
break;
    case 'n':
      state = 41;
break;
    case 'o':
      state = 41;
break;
    case 'p':
      state = 41;
break;
    case 'q':
      state = 41;
break;
    case 'r':
      state = 41;
break;
    case 's':
      state = 41;
break;
    case 't':
      state = 41;
break;
    case 'u':
      state = 41;
break;
    case 'v':
      state = 41;
break;
    case 'w':
      state = 41;
break;
    case 'x':
      state = 41;
break;
    case 'y':
      state = 41;
break;
    case 'z':
      state = 41;
break;
    default:
      fseek(file, -1, SEEK_CUR);
      buffer_index--;
      buffer[buffer_index] = '\0';
Token* token;
NEW_TOKEN(token);
endHandler6(token);
if (strcmp(token->type, "") != 0
   && strcmp(token->type, "SKIP") != 0) {
  strcpy(token->value, buffer);
  tail->next = token;
  tail = token;
} else {
  free(token);
}
buffer[0] = '\0';
buffer_index = 0;
state = 0;
    }
  break;
case 42:
  switch(c) {
    default:
      fseek(file, -1, SEEK_CUR);
      buffer_index--;
      buffer[buffer_index] = '\0';
Token* token;
NEW_TOKEN(token);
endHandler16(token);
if (strcmp(token->type, "") != 0
   && strcmp(token->type, "SKIP") != 0) {
  strcpy(token->value, buffer);
  tail->next = token;
  tail = token;
} else {
  free(token);
}
buffer[0] = '\0';
buffer_index = 0;
state = 0;
    }
  break;
case 43:
  switch(c) {
    default:
      fseek(file, -1, SEEK_CUR);
      buffer_index--;
      buffer[buffer_index] = '\0';
Token* token;
NEW_TOKEN(token);
endHandler17(token);
if (strcmp(token->type, "") != 0
   && strcmp(token->type, "SKIP") != 0) {
  strcpy(token->value, buffer);
  tail->next = token;
  tail = token;
} else {
  free(token);
}
buffer[0] = '\0';
buffer_index = 0;
state = 0;
    }
  break;
case 44:
  switch(c) {
    case '0':
      state = 41;
break;
    case '1':
      state = 41;
break;
    case '2':
      state = 41;
break;
    case '3':
      state = 41;
break;
    case '4':
      state = 41;
break;
    case '5':
      state = 41;
break;
    case '6':
      state = 41;
break;
    case '7':
      state = 41;
break;
    case '8':
      state = 41;
break;
    case '9':
      state = 41;
break;
    case 'A':
      state = 41;
break;
    case 'B':
      state = 41;
break;
    case 'C':
      state = 41;
break;
    case 'D':
      state = 41;
break;
    case 'E':
      state = 41;
break;
    case 'F':
      state = 41;
break;
    case 'G':
      state = 41;
break;
    case 'H':
      state = 41;
break;
    case 'I':
      state = 41;
break;
    case 'J':
      state = 41;
break;
    case 'K':
      state = 41;
break;
    case 'L':
      state = 41;
break;
    case 'M':
      state = 41;
break;
    case 'N':
      state = 41;
break;
    case 'O':
      state = 41;
break;
    case 'P':
      state = 41;
break;
    case 'Q':
      state = 41;
break;
    case 'R':
      state = 41;
break;
    case 'S':
      state = 41;
break;
    case 'T':
      state = 41;
break;
    case 'U':
      state = 41;
break;
    case 'V':
      state = 41;
break;
    case 'W':
      state = 41;
break;
    case 'X':
      state = 41;
break;
    case 'Y':
      state = 41;
break;
    case 'Z':
      state = 41;
break;
    case '_':
      state = 41;
break;
    case 'a':
      state = 41;
break;
    case 'b':
      state = 41;
break;
    case 'c':
      state = 41;
break;
    case 'd':
      state = 41;
break;
    case 'e':
      state = 41;
break;
    case 'f':
      state = 41;
break;
    case 'g':
      state = 41;
break;
    case 'h':
      state = 41;
break;
    case 'i':
      state = 41;
break;
    case 'j':
      state = 41;
break;
    case 'k':
      state = 41;
break;
    case 'l':
      state = 41;
break;
    case 'm':
      state = 41;
break;
    case 'n':
      state = 41;
break;
    case 'o':
      state = 41;
break;
    case 'p':
      state = 41;
break;
    case 'q':
      state = 41;
break;
    case 'r':
      state = 45;
break;
    case 's':
      state = 41;
break;
    case 't':
      state = 41;
break;
    case 'u':
      state = 41;
break;
    case 'v':
      state = 41;
break;
    case 'w':
      state = 41;
break;
    case 'x':
      state = 41;
break;
    case 'y':
      state = 41;
break;
    case 'z':
      state = 41;
break;
    default:
      fseek(file, -1, SEEK_CUR);
      buffer_index--;
      buffer[buffer_index] = '\0';
Token* token;
NEW_TOKEN(token);
endHandler6(token);
if (strcmp(token->type, "") != 0
   && strcmp(token->type, "SKIP") != 0) {
  strcpy(token->value, buffer);
  tail->next = token;
  tail = token;
} else {
  free(token);
}
buffer[0] = '\0';
buffer_index = 0;
state = 0;
    }
  break;
case 45:
  switch(c) {
    case '0':
      state = 41;
break;
    case '1':
      state = 41;
break;
    case '2':
      state = 41;
break;
    case '3':
      state = 41;
break;
    case '4':
      state = 41;
break;
    case '5':
      state = 41;
break;
    case '6':
      state = 41;
break;
    case '7':
      state = 41;
break;
    case '8':
      state = 41;
break;
    case '9':
      state = 41;
break;
    case 'A':
      state = 41;
break;
    case 'B':
      state = 41;
break;
    case 'C':
      state = 41;
break;
    case 'D':
      state = 41;
break;
    case 'E':
      state = 41;
break;
    case 'F':
      state = 41;
break;
    case 'G':
      state = 41;
break;
    case 'H':
      state = 41;
break;
    case 'I':
      state = 41;
break;
    case 'J':
      state = 41;
break;
    case 'K':
      state = 41;
break;
    case 'L':
      state = 41;
break;
    case 'M':
      state = 41;
break;
    case 'N':
      state = 41;
break;
    case 'O':
      state = 41;
break;
    case 'P':
      state = 41;
break;
    case 'Q':
      state = 41;
break;
    case 'R':
      state = 41;
break;
    case 'S':
      state = 41;
break;
    case 'T':
      state = 41;
break;
    case 'U':
      state = 41;
break;
    case 'V':
      state = 41;
break;
    case 'W':
      state = 41;
break;
    case 'X':
      state = 41;
break;
    case 'Y':
      state = 41;
break;
    case 'Z':
      state = 41;
break;
    case '_':
      state = 41;
break;
    case 'a':
      state = 41;
break;
    case 'b':
      state = 41;
break;
    case 'c':
      state = 41;
break;
    case 'd':
      state = 41;
break;
    case 'e':
      state = 46;
break;
    case 'f':
      state = 41;
break;
    case 'g':
      state = 41;
break;
    case 'h':
      state = 41;
break;
    case 'i':
      state = 41;
break;
    case 'j':
      state = 41;
break;
    case 'k':
      state = 41;
break;
    case 'l':
      state = 41;
break;
    case 'm':
      state = 41;
break;
    case 'n':
      state = 41;
break;
    case 'o':
      state = 41;
break;
    case 'p':
      state = 41;
break;
    case 'q':
      state = 41;
break;
    case 'r':
      state = 41;
break;
    case 's':
      state = 41;
break;
    case 't':
      state = 41;
break;
    case 'u':
      state = 41;
break;
    case 'v':
      state = 41;
break;
    case 'w':
      state = 41;
break;
    case 'x':
      state = 41;
break;
    case 'y':
      state = 41;
break;
    case 'z':
      state = 41;
break;
    default:
      fseek(file, -1, SEEK_CUR);
      buffer_index--;
      buffer[buffer_index] = '\0';
Token* token;
NEW_TOKEN(token);
endHandler6(token);
if (strcmp(token->type, "") != 0
   && strcmp(token->type, "SKIP") != 0) {
  strcpy(token->value, buffer);
  tail->next = token;
  tail = token;
} else {
  free(token);
}
buffer[0] = '\0';
buffer_index = 0;
state = 0;
    }
  break;
case 46:
  switch(c) {
    case '0':
      state = 41;
break;
    case '1':
      state = 41;
break;
    case '2':
      state = 41;
break;
    case '3':
      state = 41;
break;
    case '4':
      state = 41;
break;
    case '5':
      state = 41;
break;
    case '6':
      state = 41;
break;
    case '7':
      state = 41;
break;
    case '8':
      state = 41;
break;
    case '9':
      state = 41;
break;
    case 'A':
      state = 41;
break;
    case 'B':
      state = 41;
break;
    case 'C':
      state = 41;
break;
    case 'D':
      state = 41;
break;
    case 'E':
      state = 41;
break;
    case 'F':
      state = 41;
break;
    case 'G':
      state = 41;
break;
    case 'H':
      state = 41;
break;
    case 'I':
      state = 41;
break;
    case 'J':
      state = 41;
break;
    case 'K':
      state = 41;
break;
    case 'L':
      state = 41;
break;
    case 'M':
      state = 41;
break;
    case 'N':
      state = 41;
break;
    case 'O':
      state = 41;
break;
    case 'P':
      state = 41;
break;
    case 'Q':
      state = 41;
break;
    case 'R':
      state = 41;
break;
    case 'S':
      state = 41;
break;
    case 'T':
      state = 41;
break;
    case 'U':
      state = 41;
break;
    case 'V':
      state = 41;
break;
    case 'W':
      state = 41;
break;
    case 'X':
      state = 41;
break;
    case 'Y':
      state = 41;
break;
    case 'Z':
      state = 41;
break;
    case '_':
      state = 41;
break;
    case 'a':
      state = 47;
break;
    case 'b':
      state = 41;
break;
    case 'c':
      state = 41;
break;
    case 'd':
      state = 41;
break;
    case 'e':
      state = 41;
break;
    case 'f':
      state = 41;
break;
    case 'g':
      state = 41;
break;
    case 'h':
      state = 41;
break;
    case 'i':
      state = 41;
break;
    case 'j':
      state = 41;
break;
    case 'k':
      state = 41;
break;
    case 'l':
      state = 41;
break;
    case 'm':
      state = 41;
break;
    case 'n':
      state = 41;
break;
    case 'o':
      state = 41;
break;
    case 'p':
      state = 41;
break;
    case 'q':
      state = 41;
break;
    case 'r':
      state = 41;
break;
    case 's':
      state = 41;
break;
    case 't':
      state = 41;
break;
    case 'u':
      state = 41;
break;
    case 'v':
      state = 41;
break;
    case 'w':
      state = 41;
break;
    case 'x':
      state = 41;
break;
    case 'y':
      state = 41;
break;
    case 'z':
      state = 41;
break;
    default:
      fseek(file, -1, SEEK_CUR);
      buffer_index--;
      buffer[buffer_index] = '\0';
Token* token;
NEW_TOKEN(token);
endHandler6(token);
if (strcmp(token->type, "") != 0
   && strcmp(token->type, "SKIP") != 0) {
  strcpy(token->value, buffer);
  tail->next = token;
  tail = token;
} else {
  free(token);
}
buffer[0] = '\0';
buffer_index = 0;
state = 0;
    }
  break;
case 47:
  switch(c) {
    case '0':
      state = 41;
break;
    case '1':
      state = 41;
break;
    case '2':
      state = 41;
break;
    case '3':
      state = 41;
break;
    case '4':
      state = 41;
break;
    case '5':
      state = 41;
break;
    case '6':
      state = 41;
break;
    case '7':
      state = 41;
break;
    case '8':
      state = 41;
break;
    case '9':
      state = 41;
break;
    case 'A':
      state = 41;
break;
    case 'B':
      state = 41;
break;
    case 'C':
      state = 41;
break;
    case 'D':
      state = 41;
break;
    case 'E':
      state = 41;
break;
    case 'F':
      state = 41;
break;
    case 'G':
      state = 41;
break;
    case 'H':
      state = 41;
break;
    case 'I':
      state = 41;
break;
    case 'J':
      state = 41;
break;
    case 'K':
      state = 41;
break;
    case 'L':
      state = 41;
break;
    case 'M':
      state = 41;
break;
    case 'N':
      state = 41;
break;
    case 'O':
      state = 41;
break;
    case 'P':
      state = 41;
break;
    case 'Q':
      state = 41;
break;
    case 'R':
      state = 41;
break;
    case 'S':
      state = 41;
break;
    case 'T':
      state = 41;
break;
    case 'U':
      state = 41;
break;
    case 'V':
      state = 41;
break;
    case 'W':
      state = 41;
break;
    case 'X':
      state = 41;
break;
    case 'Y':
      state = 41;
break;
    case 'Z':
      state = 41;
break;
    case '_':
      state = 41;
break;
    case 'a':
      state = 41;
break;
    case 'b':
      state = 41;
break;
    case 'c':
      state = 41;
break;
    case 'd':
      state = 41;
break;
    case 'e':
      state = 41;
break;
    case 'f':
      state = 41;
break;
    case 'g':
      state = 41;
break;
    case 'h':
      state = 41;
break;
    case 'i':
      state = 41;
break;
    case 'j':
      state = 41;
break;
    case 'k':
      state = 48;
break;
    case 'l':
      state = 41;
break;
    case 'm':
      state = 41;
break;
    case 'n':
      state = 41;
break;
    case 'o':
      state = 41;
break;
    case 'p':
      state = 41;
break;
    case 'q':
      state = 41;
break;
    case 'r':
      state = 41;
break;
    case 's':
      state = 41;
break;
    case 't':
      state = 41;
break;
    case 'u':
      state = 41;
break;
    case 'v':
      state = 41;
break;
    case 'w':
      state = 41;
break;
    case 'x':
      state = 41;
break;
    case 'y':
      state = 41;
break;
    case 'z':
      state = 41;
break;
    default:
      fseek(file, -1, SEEK_CUR);
      buffer_index--;
      buffer[buffer_index] = '\0';
Token* token;
NEW_TOKEN(token);
endHandler6(token);
if (strcmp(token->type, "") != 0
   && strcmp(token->type, "SKIP") != 0) {
  strcpy(token->value, buffer);
  tail->next = token;
  tail = token;
} else {
  free(token);
}
buffer[0] = '\0';
buffer_index = 0;
state = 0;
    }
  break;
case 48:
  switch(c) {
    case '0':
      state = 41;
break;
    case '1':
      state = 41;
break;
    case '2':
      state = 41;
break;
    case '3':
      state = 41;
break;
    case '4':
      state = 41;
break;
    case '5':
      state = 41;
break;
    case '6':
      state = 41;
break;
    case '7':
      state = 41;
break;
    case '8':
      state = 41;
break;
    case '9':
      state = 41;
break;
    case 'A':
      state = 41;
break;
    case 'B':
      state = 41;
break;
    case 'C':
      state = 41;
break;
    case 'D':
      state = 41;
break;
    case 'E':
      state = 41;
break;
    case 'F':
      state = 41;
break;
    case 'G':
      state = 41;
break;
    case 'H':
      state = 41;
break;
    case 'I':
      state = 41;
break;
    case 'J':
      state = 41;
break;
    case 'K':
      state = 41;
break;
    case 'L':
      state = 41;
break;
    case 'M':
      state = 41;
break;
    case 'N':
      state = 41;
break;
    case 'O':
      state = 41;
break;
    case 'P':
      state = 41;
break;
    case 'Q':
      state = 41;
break;
    case 'R':
      state = 41;
break;
    case 'S':
      state = 41;
break;
    case 'T':
      state = 41;
break;
    case 'U':
      state = 41;
break;
    case 'V':
      state = 41;
break;
    case 'W':
      state = 41;
break;
    case 'X':
      state = 41;
break;
    case 'Y':
      state = 41;
break;
    case 'Z':
      state = 41;
break;
    case '_':
      state = 41;
break;
    case 'a':
      state = 41;
break;
    case 'b':
      state = 41;
break;
    case 'c':
      state = 41;
break;
    case 'd':
      state = 41;
break;
    case 'e':
      state = 41;
break;
    case 'f':
      state = 41;
break;
    case 'g':
      state = 41;
break;
    case 'h':
      state = 41;
break;
    case 'i':
      state = 41;
break;
    case 'j':
      state = 41;
break;
    case 'k':
      state = 41;
break;
    case 'l':
      state = 41;
break;
    case 'm':
      state = 41;
break;
    case 'n':
      state = 41;
break;
    case 'o':
      state = 41;
break;
    case 'p':
      state = 41;
break;
    case 'q':
      state = 41;
break;
    case 'r':
      state = 41;
break;
    case 's':
      state = 41;
break;
    case 't':
      state = 41;
break;
    case 'u':
      state = 41;
break;
    case 'v':
      state = 41;
break;
    case 'w':
      state = 41;
break;
    case 'x':
      state = 41;
break;
    case 'y':
      state = 41;
break;
    case 'z':
      state = 41;
break;
    default:
      fseek(file, -1, SEEK_CUR);
      buffer_index--;
      buffer[buffer_index] = '\0';
Token* token;
NEW_TOKEN(token);
endHandler2(token);
if (strcmp(token->type, "") != 0
   && strcmp(token->type, "SKIP") != 0) {
  strcpy(token->value, buffer);
  tail->next = token;
  tail = token;
} else {
  free(token);
}
buffer[0] = '\0';
buffer_index = 0;
state = 0;
    }
  break;
case 49:
  switch(c) {
    case '0':
      state = 41;
break;
    case '1':
      state = 41;
break;
    case '2':
      state = 41;
break;
    case '3':
      state = 41;
break;
    case '4':
      state = 41;
break;
    case '5':
      state = 41;
break;
    case '6':
      state = 41;
break;
    case '7':
      state = 41;
break;
    case '8':
      state = 41;
break;
    case '9':
      state = 41;
break;
    case 'A':
      state = 41;
break;
    case 'B':
      state = 41;
break;
    case 'C':
      state = 41;
break;
    case 'D':
      state = 41;
break;
    case 'E':
      state = 41;
break;
    case 'F':
      state = 41;
break;
    case 'G':
      state = 41;
break;
    case 'H':
      state = 41;
break;
    case 'I':
      state = 41;
break;
    case 'J':
      state = 41;
break;
    case 'K':
      state = 41;
break;
    case 'L':
      state = 41;
break;
    case 'M':
      state = 41;
break;
    case 'N':
      state = 41;
break;
    case 'O':
      state = 41;
break;
    case 'P':
      state = 41;
break;
    case 'Q':
      state = 41;
break;
    case 'R':
      state = 41;
break;
    case 'S':
      state = 41;
break;
    case 'T':
      state = 41;
break;
    case 'U':
      state = 41;
break;
    case 'V':
      state = 41;
break;
    case 'W':
      state = 41;
break;
    case 'X':
      state = 41;
break;
    case 'Y':
      state = 41;
break;
    case 'Z':
      state = 41;
break;
    case '_':
      state = 41;
break;
    case 'a':
      state = 50;
break;
    case 'b':
      state = 41;
break;
    case 'c':
      state = 41;
break;
    case 'd':
      state = 41;
break;
    case 'e':
      state = 41;
break;
    case 'f':
      state = 41;
break;
    case 'g':
      state = 41;
break;
    case 'h':
      state = 52;
break;
    case 'i':
      state = 55;
break;
    case 'j':
      state = 41;
break;
    case 'k':
      state = 41;
break;
    case 'l':
      state = 41;
break;
    case 'm':
      state = 41;
break;
    case 'n':
      state = 41;
break;
    case 'o':
      state = 56;
break;
    case 'p':
      state = 41;
break;
    case 'q':
      state = 41;
break;
    case 'r':
      state = 41;
break;
    case 's':
      state = 41;
break;
    case 't':
      state = 41;
break;
    case 'u':
      state = 41;
break;
    case 'v':
      state = 41;
break;
    case 'w':
      state = 41;
break;
    case 'x':
      state = 41;
break;
    case 'y':
      state = 41;
break;
    case 'z':
      state = 41;
break;
    default:
      fseek(file, -1, SEEK_CUR);
      buffer_index--;
      buffer[buffer_index] = '\0';
Token* token;
NEW_TOKEN(token);
endHandler6(token);
if (strcmp(token->type, "") != 0
   && strcmp(token->type, "SKIP") != 0) {
  strcpy(token->value, buffer);
  tail->next = token;
  tail = token;
} else {
  free(token);
}
buffer[0] = '\0';
buffer_index = 0;
state = 0;
    }
  break;
case 50:
  switch(c) {
    case '0':
      state = 41;
break;
    case '1':
      state = 41;
break;
    case '2':
      state = 41;
break;
    case '3':
      state = 41;
break;
    case '4':
      state = 41;
break;
    case '5':
      state = 41;
break;
    case '6':
      state = 41;
break;
    case '7':
      state = 41;
break;
    case '8':
      state = 41;
break;
    case '9':
      state = 41;
break;
    case 'A':
      state = 41;
break;
    case 'B':
      state = 41;
break;
    case 'C':
      state = 41;
break;
    case 'D':
      state = 41;
break;
    case 'E':
      state = 41;
break;
    case 'F':
      state = 41;
break;
    case 'G':
      state = 41;
break;
    case 'H':
      state = 41;
break;
    case 'I':
      state = 41;
break;
    case 'J':
      state = 41;
break;
    case 'K':
      state = 41;
break;
    case 'L':
      state = 41;
break;
    case 'M':
      state = 41;
break;
    case 'N':
      state = 41;
break;
    case 'O':
      state = 41;
break;
    case 'P':
      state = 41;
break;
    case 'Q':
      state = 41;
break;
    case 'R':
      state = 41;
break;
    case 'S':
      state = 41;
break;
    case 'T':
      state = 41;
break;
    case 'U':
      state = 41;
break;
    case 'V':
      state = 41;
break;
    case 'W':
      state = 41;
break;
    case 'X':
      state = 41;
break;
    case 'Y':
      state = 41;
break;
    case 'Z':
      state = 41;
break;
    case '_':
      state = 41;
break;
    case 'a':
      state = 41;
break;
    case 'b':
      state = 41;
break;
    case 'c':
      state = 41;
break;
    case 'd':
      state = 41;
break;
    case 'e':
      state = 41;
break;
    case 'f':
      state = 41;
break;
    case 'g':
      state = 41;
break;
    case 'h':
      state = 41;
break;
    case 'i':
      state = 41;
break;
    case 'j':
      state = 41;
break;
    case 'k':
      state = 41;
break;
    case 'l':
      state = 41;
break;
    case 'm':
      state = 41;
break;
    case 'n':
      state = 41;
break;
    case 'o':
      state = 41;
break;
    case 'p':
      state = 41;
break;
    case 'q':
      state = 41;
break;
    case 'r':
      state = 41;
break;
    case 's':
      state = 51;
break;
    case 't':
      state = 41;
break;
    case 'u':
      state = 41;
break;
    case 'v':
      state = 41;
break;
    case 'w':
      state = 41;
break;
    case 'x':
      state = 41;
break;
    case 'y':
      state = 41;
break;
    case 'z':
      state = 41;
break;
    default:
      fseek(file, -1, SEEK_CUR);
      buffer_index--;
      buffer[buffer_index] = '\0';
Token* token;
NEW_TOKEN(token);
endHandler6(token);
if (strcmp(token->type, "") != 0
   && strcmp(token->type, "SKIP") != 0) {
  strcpy(token->value, buffer);
  tail->next = token;
  tail = token;
} else {
  free(token);
}
buffer[0] = '\0';
buffer_index = 0;
state = 0;
    }
  break;
case 51:
  switch(c) {
    case '0':
      state = 41;
break;
    case '1':
      state = 41;
break;
    case '2':
      state = 41;
break;
    case '3':
      state = 41;
break;
    case '4':
      state = 41;
break;
    case '5':
      state = 41;
break;
    case '6':
      state = 41;
break;
    case '7':
      state = 41;
break;
    case '8':
      state = 41;
break;
    case '9':
      state = 41;
break;
    case 'A':
      state = 41;
break;
    case 'B':
      state = 41;
break;
    case 'C':
      state = 41;
break;
    case 'D':
      state = 41;
break;
    case 'E':
      state = 41;
break;
    case 'F':
      state = 41;
break;
    case 'G':
      state = 41;
break;
    case 'H':
      state = 41;
break;
    case 'I':
      state = 41;
break;
    case 'J':
      state = 41;
break;
    case 'K':
      state = 41;
break;
    case 'L':
      state = 41;
break;
    case 'M':
      state = 41;
break;
    case 'N':
      state = 41;
break;
    case 'O':
      state = 41;
break;
    case 'P':
      state = 41;
break;
    case 'Q':
      state = 41;
break;
    case 'R':
      state = 41;
break;
    case 'S':
      state = 41;
break;
    case 'T':
      state = 41;
break;
    case 'U':
      state = 41;
break;
    case 'V':
      state = 41;
break;
    case 'W':
      state = 41;
break;
    case 'X':
      state = 41;
break;
    case 'Y':
      state = 41;
break;
    case 'Z':
      state = 41;
break;
    case '_':
      state = 41;
break;
    case 'a':
      state = 41;
break;
    case 'b':
      state = 41;
break;
    case 'c':
      state = 41;
break;
    case 'd':
      state = 41;
break;
    case 'e':
      state = 48;
break;
    case 'f':
      state = 41;
break;
    case 'g':
      state = 41;
break;
    case 'h':
      state = 41;
break;
    case 'i':
      state = 41;
break;
    case 'j':
      state = 41;
break;
    case 'k':
      state = 41;
break;
    case 'l':
      state = 41;
break;
    case 'm':
      state = 41;
break;
    case 'n':
      state = 41;
break;
    case 'o':
      state = 41;
break;
    case 'p':
      state = 41;
break;
    case 'q':
      state = 41;
break;
    case 'r':
      state = 41;
break;
    case 's':
      state = 41;
break;
    case 't':
      state = 41;
break;
    case 'u':
      state = 41;
break;
    case 'v':
      state = 41;
break;
    case 'w':
      state = 41;
break;
    case 'x':
      state = 41;
break;
    case 'y':
      state = 41;
break;
    case 'z':
      state = 41;
break;
    default:
      fseek(file, -1, SEEK_CUR);
      buffer_index--;
      buffer[buffer_index] = '\0';
Token* token;
NEW_TOKEN(token);
endHandler6(token);
if (strcmp(token->type, "") != 0
   && strcmp(token->type, "SKIP") != 0) {
  strcpy(token->value, buffer);
  tail->next = token;
  tail = token;
} else {
  free(token);
}
buffer[0] = '\0';
buffer_index = 0;
state = 0;
    }
  break;
case 52:
  switch(c) {
    case '0':
      state = 41;
break;
    case '1':
      state = 41;
break;
    case '2':
      state = 41;
break;
    case '3':
      state = 41;
break;
    case '4':
      state = 41;
break;
    case '5':
      state = 41;
break;
    case '6':
      state = 41;
break;
    case '7':
      state = 41;
break;
    case '8':
      state = 41;
break;
    case '9':
      state = 41;
break;
    case 'A':
      state = 41;
break;
    case 'B':
      state = 41;
break;
    case 'C':
      state = 41;
break;
    case 'D':
      state = 41;
break;
    case 'E':
      state = 41;
break;
    case 'F':
      state = 41;
break;
    case 'G':
      state = 41;
break;
    case 'H':
      state = 41;
break;
    case 'I':
      state = 41;
break;
    case 'J':
      state = 41;
break;
    case 'K':
      state = 41;
break;
    case 'L':
      state = 41;
break;
    case 'M':
      state = 41;
break;
    case 'N':
      state = 41;
break;
    case 'O':
      state = 41;
break;
    case 'P':
      state = 41;
break;
    case 'Q':
      state = 41;
break;
    case 'R':
      state = 41;
break;
    case 'S':
      state = 41;
break;
    case 'T':
      state = 41;
break;
    case 'U':
      state = 41;
break;
    case 'V':
      state = 41;
break;
    case 'W':
      state = 41;
break;
    case 'X':
      state = 41;
break;
    case 'Y':
      state = 41;
break;
    case 'Z':
      state = 41;
break;
    case '_':
      state = 41;
break;
    case 'a':
      state = 53;
break;
    case 'b':
      state = 41;
break;
    case 'c':
      state = 41;
break;
    case 'd':
      state = 41;
break;
    case 'e':
      state = 41;
break;
    case 'f':
      state = 41;
break;
    case 'g':
      state = 41;
break;
    case 'h':
      state = 41;
break;
    case 'i':
      state = 41;
break;
    case 'j':
      state = 41;
break;
    case 'k':
      state = 41;
break;
    case 'l':
      state = 41;
break;
    case 'm':
      state = 41;
break;
    case 'n':
      state = 41;
break;
    case 'o':
      state = 41;
break;
    case 'p':
      state = 41;
break;
    case 'q':
      state = 41;
break;
    case 'r':
      state = 41;
break;
    case 's':
      state = 41;
break;
    case 't':
      state = 41;
break;
    case 'u':
      state = 41;
break;
    case 'v':
      state = 41;
break;
    case 'w':
      state = 41;
break;
    case 'x':
      state = 41;
break;
    case 'y':
      state = 41;
break;
    case 'z':
      state = 41;
break;
    default:
      fseek(file, -1, SEEK_CUR);
      buffer_index--;
      buffer[buffer_index] = '\0';
Token* token;
NEW_TOKEN(token);
endHandler6(token);
if (strcmp(token->type, "") != 0
   && strcmp(token->type, "SKIP") != 0) {
  strcpy(token->value, buffer);
  tail->next = token;
  tail = token;
} else {
  free(token);
}
buffer[0] = '\0';
buffer_index = 0;
state = 0;
    }
  break;
case 53:
  switch(c) {
    case '0':
      state = 41;
break;
    case '1':
      state = 41;
break;
    case '2':
      state = 41;
break;
    case '3':
      state = 41;
break;
    case '4':
      state = 41;
break;
    case '5':
      state = 41;
break;
    case '6':
      state = 41;
break;
    case '7':
      state = 41;
break;
    case '8':
      state = 41;
break;
    case '9':
      state = 41;
break;
    case 'A':
      state = 41;
break;
    case 'B':
      state = 41;
break;
    case 'C':
      state = 41;
break;
    case 'D':
      state = 41;
break;
    case 'E':
      state = 41;
break;
    case 'F':
      state = 41;
break;
    case 'G':
      state = 41;
break;
    case 'H':
      state = 41;
break;
    case 'I':
      state = 41;
break;
    case 'J':
      state = 41;
break;
    case 'K':
      state = 41;
break;
    case 'L':
      state = 41;
break;
    case 'M':
      state = 41;
break;
    case 'N':
      state = 41;
break;
    case 'O':
      state = 41;
break;
    case 'P':
      state = 41;
break;
    case 'Q':
      state = 41;
break;
    case 'R':
      state = 41;
break;
    case 'S':
      state = 41;
break;
    case 'T':
      state = 41;
break;
    case 'U':
      state = 41;
break;
    case 'V':
      state = 41;
break;
    case 'W':
      state = 41;
break;
    case 'X':
      state = 41;
break;
    case 'Y':
      state = 41;
break;
    case 'Z':
      state = 41;
break;
    case '_':
      state = 41;
break;
    case 'a':
      state = 41;
break;
    case 'b':
      state = 41;
break;
    case 'c':
      state = 41;
break;
    case 'd':
      state = 41;
break;
    case 'e':
      state = 41;
break;
    case 'f':
      state = 41;
break;
    case 'g':
      state = 41;
break;
    case 'h':
      state = 41;
break;
    case 'i':
      state = 41;
break;
    case 'j':
      state = 41;
break;
    case 'k':
      state = 41;
break;
    case 'l':
      state = 41;
break;
    case 'm':
      state = 41;
break;
    case 'n':
      state = 41;
break;
    case 'o':
      state = 41;
break;
    case 'p':
      state = 41;
break;
    case 'q':
      state = 41;
break;
    case 'r':
      state = 54;
break;
    case 's':
      state = 41;
break;
    case 't':
      state = 41;
break;
    case 'u':
      state = 41;
break;
    case 'v':
      state = 41;
break;
    case 'w':
      state = 41;
break;
    case 'x':
      state = 41;
break;
    case 'y':
      state = 41;
break;
    case 'z':
      state = 41;
break;
    default:
      fseek(file, -1, SEEK_CUR);
      buffer_index--;
      buffer[buffer_index] = '\0';
Token* token;
NEW_TOKEN(token);
endHandler6(token);
if (strcmp(token->type, "") != 0
   && strcmp(token->type, "SKIP") != 0) {
  strcpy(token->value, buffer);
  tail->next = token;
  tail = token;
} else {
  free(token);
}
buffer[0] = '\0';
buffer_index = 0;
state = 0;
    }
  break;
case 54:
  switch(c) {
    case '0':
      state = 41;
break;
    case '1':
      state = 41;
break;
    case '2':
      state = 41;
break;
    case '3':
      state = 41;
break;
    case '4':
      state = 41;
break;
    case '5':
      state = 41;
break;
    case '6':
      state = 41;
break;
    case '7':
      state = 41;
break;
    case '8':
      state = 41;
break;
    case '9':
      state = 41;
break;
    case 'A':
      state = 41;
break;
    case 'B':
      state = 41;
break;
    case 'C':
      state = 41;
break;
    case 'D':
      state = 41;
break;
    case 'E':
      state = 41;
break;
    case 'F':
      state = 41;
break;
    case 'G':
      state = 41;
break;
    case 'H':
      state = 41;
break;
    case 'I':
      state = 41;
break;
    case 'J':
      state = 41;
break;
    case 'K':
      state = 41;
break;
    case 'L':
      state = 41;
break;
    case 'M':
      state = 41;
break;
    case 'N':
      state = 41;
break;
    case 'O':
      state = 41;
break;
    case 'P':
      state = 41;
break;
    case 'Q':
      state = 41;
break;
    case 'R':
      state = 41;
break;
    case 'S':
      state = 41;
break;
    case 'T':
      state = 41;
break;
    case 'U':
      state = 41;
break;
    case 'V':
      state = 41;
break;
    case 'W':
      state = 41;
break;
    case 'X':
      state = 41;
break;
    case 'Y':
      state = 41;
break;
    case 'Z':
      state = 41;
break;
    case '_':
      state = 41;
break;
    case 'a':
      state = 41;
break;
    case 'b':
      state = 41;
break;
    case 'c':
      state = 41;
break;
    case 'd':
      state = 41;
break;
    case 'e':
      state = 41;
break;
    case 'f':
      state = 41;
break;
    case 'g':
      state = 41;
break;
    case 'h':
      state = 41;
break;
    case 'i':
      state = 41;
break;
    case 'j':
      state = 41;
break;
    case 'k':
      state = 41;
break;
    case 'l':
      state = 41;
break;
    case 'm':
      state = 41;
break;
    case 'n':
      state = 41;
break;
    case 'o':
      state = 41;
break;
    case 'p':
      state = 41;
break;
    case 'q':
      state = 41;
break;
    case 'r':
      state = 41;
break;
    case 's':
      state = 41;
break;
    case 't':
      state = 41;
break;
    case 'u':
      state = 41;
break;
    case 'v':
      state = 41;
break;
    case 'w':
      state = 41;
break;
    case 'x':
      state = 41;
break;
    case 'y':
      state = 41;
break;
    case 'z':
      state = 41;
break;
    default:
      fseek(file, -1, SEEK_CUR);
      buffer_index--;
      buffer[buffer_index] = '\0';
Token* token;
NEW_TOKEN(token);
endHandler3(token);
if (strcmp(token->type, "") != 0
   && strcmp(token->type, "SKIP") != 0) {
  strcpy(token->value, buffer);
  tail->next = token;
  tail = token;
} else {
  free(token);
}
buffer[0] = '\0';
buffer_index = 0;
state = 0;
    }
  break;
case 55:
  switch(c) {
    case '0':
      state = 41;
break;
    case '1':
      state = 41;
break;
    case '2':
      state = 41;
break;
    case '3':
      state = 41;
break;
    case '4':
      state = 41;
break;
    case '5':
      state = 41;
break;
    case '6':
      state = 41;
break;
    case '7':
      state = 41;
break;
    case '8':
      state = 41;
break;
    case '9':
      state = 41;
break;
    case 'A':
      state = 41;
break;
    case 'B':
      state = 41;
break;
    case 'C':
      state = 41;
break;
    case 'D':
      state = 41;
break;
    case 'E':
      state = 41;
break;
    case 'F':
      state = 41;
break;
    case 'G':
      state = 41;
break;
    case 'H':
      state = 41;
break;
    case 'I':
      state = 41;
break;
    case 'J':
      state = 41;
break;
    case 'K':
      state = 41;
break;
    case 'L':
      state = 41;
break;
    case 'M':
      state = 41;
break;
    case 'N':
      state = 41;
break;
    case 'O':
      state = 41;
break;
    case 'P':
      state = 41;
break;
    case 'Q':
      state = 41;
break;
    case 'R':
      state = 41;
break;
    case 'S':
      state = 41;
break;
    case 'T':
      state = 41;
break;
    case 'U':
      state = 41;
break;
    case 'V':
      state = 41;
break;
    case 'W':
      state = 41;
break;
    case 'X':
      state = 41;
break;
    case 'Y':
      state = 41;
break;
    case 'Z':
      state = 41;
break;
    case '_':
      state = 41;
break;
    case 'a':
      state = 41;
break;
    case 'b':
      state = 41;
break;
    case 'c':
      state = 41;
break;
    case 'd':
      state = 41;
break;
    case 'e':
      state = 41;
break;
    case 'f':
      state = 41;
break;
    case 'g':
      state = 41;
break;
    case 'h':
      state = 41;
break;
    case 'i':
      state = 41;
break;
    case 'j':
      state = 41;
break;
    case 'k':
      state = 41;
break;
    case 'l':
      state = 41;
break;
    case 'm':
      state = 41;
break;
    case 'n':
      state = 48;
break;
    case 'o':
      state = 41;
break;
    case 'p':
      state = 41;
break;
    case 'q':
      state = 41;
break;
    case 'r':
      state = 41;
break;
    case 's':
      state = 41;
break;
    case 't':
      state = 41;
break;
    case 'u':
      state = 41;
break;
    case 'v':
      state = 41;
break;
    case 'w':
      state = 41;
break;
    case 'x':
      state = 41;
break;
    case 'y':
      state = 41;
break;
    case 'z':
      state = 41;
break;
    default:
      fseek(file, -1, SEEK_CUR);
      buffer_index--;
      buffer[buffer_index] = '\0';
Token* token;
NEW_TOKEN(token);
endHandler6(token);
if (strcmp(token->type, "") != 0
   && strcmp(token->type, "SKIP") != 0) {
  strcpy(token->value, buffer);
  tail->next = token;
  tail = token;
} else {
  free(token);
}
buffer[0] = '\0';
buffer_index = 0;
state = 0;
    }
  break;
case 56:
  switch(c) {
    case '0':
      state = 41;
break;
    case '1':
      state = 41;
break;
    case '2':
      state = 41;
break;
    case '3':
      state = 41;
break;
    case '4':
      state = 41;
break;
    case '5':
      state = 41;
break;
    case '6':
      state = 41;
break;
    case '7':
      state = 41;
break;
    case '8':
      state = 41;
break;
    case '9':
      state = 41;
break;
    case 'A':
      state = 41;
break;
    case 'B':
      state = 41;
break;
    case 'C':
      state = 41;
break;
    case 'D':
      state = 41;
break;
    case 'E':
      state = 41;
break;
    case 'F':
      state = 41;
break;
    case 'G':
      state = 41;
break;
    case 'H':
      state = 41;
break;
    case 'I':
      state = 41;
break;
    case 'J':
      state = 41;
break;
    case 'K':
      state = 41;
break;
    case 'L':
      state = 41;
break;
    case 'M':
      state = 41;
break;
    case 'N':
      state = 41;
break;
    case 'O':
      state = 41;
break;
    case 'P':
      state = 41;
break;
    case 'Q':
      state = 41;
break;
    case 'R':
      state = 41;
break;
    case 'S':
      state = 41;
break;
    case 'T':
      state = 41;
break;
    case 'U':
      state = 41;
break;
    case 'V':
      state = 41;
break;
    case 'W':
      state = 41;
break;
    case 'X':
      state = 41;
break;
    case 'Y':
      state = 41;
break;
    case 'Z':
      state = 41;
break;
    case '_':
      state = 41;
break;
    case 'a':
      state = 41;
break;
    case 'b':
      state = 41;
break;
    case 'c':
      state = 41;
break;
    case 'd':
      state = 41;
break;
    case 'e':
      state = 41;
break;
    case 'f':
      state = 41;
break;
    case 'g':
      state = 41;
break;
    case 'h':
      state = 41;
break;
    case 'i':
      state = 41;
break;
    case 'j':
      state = 41;
break;
    case 'k':
      state = 41;
break;
    case 'l':
      state = 41;
break;
    case 'm':
      state = 41;
break;
    case 'n':
      state = 41;
break;
    case 'o':
      state = 41;
break;
    case 'p':
      state = 41;
break;
    case 'q':
      state = 41;
break;
    case 'r':
      state = 41;
break;
    case 's':
      state = 41;
break;
    case 't':
      state = 41;
break;
    case 'u':
      state = 57;
break;
    case 'v':
      state = 41;
break;
    case 'w':
      state = 41;
break;
    case 'x':
      state = 41;
break;
    case 'y':
      state = 41;
break;
    case 'z':
      state = 41;
break;
    default:
      fseek(file, -1, SEEK_CUR);
      buffer_index--;
      buffer[buffer_index] = '\0';
Token* token;
NEW_TOKEN(token);
endHandler6(token);
if (strcmp(token->type, "") != 0
   && strcmp(token->type, "SKIP") != 0) {
  strcpy(token->value, buffer);
  tail->next = token;
  tail = token;
} else {
  free(token);
}
buffer[0] = '\0';
buffer_index = 0;
state = 0;
    }
  break;
case 57:
  switch(c) {
    case '0':
      state = 41;
break;
    case '1':
      state = 41;
break;
    case '2':
      state = 41;
break;
    case '3':
      state = 41;
break;
    case '4':
      state = 41;
break;
    case '5':
      state = 41;
break;
    case '6':
      state = 41;
break;
    case '7':
      state = 41;
break;
    case '8':
      state = 41;
break;
    case '9':
      state = 41;
break;
    case 'A':
      state = 41;
break;
    case 'B':
      state = 41;
break;
    case 'C':
      state = 41;
break;
    case 'D':
      state = 41;
break;
    case 'E':
      state = 41;
break;
    case 'F':
      state = 41;
break;
    case 'G':
      state = 41;
break;
    case 'H':
      state = 41;
break;
    case 'I':
      state = 41;
break;
    case 'J':
      state = 41;
break;
    case 'K':
      state = 41;
break;
    case 'L':
      state = 41;
break;
    case 'M':
      state = 41;
break;
    case 'N':
      state = 41;
break;
    case 'O':
      state = 41;
break;
    case 'P':
      state = 41;
break;
    case 'Q':
      state = 41;
break;
    case 'R':
      state = 41;
break;
    case 'S':
      state = 41;
break;
    case 'T':
      state = 41;
break;
    case 'U':
      state = 41;
break;
    case 'V':
      state = 41;
break;
    case 'W':
      state = 41;
break;
    case 'X':
      state = 41;
break;
    case 'Y':
      state = 41;
break;
    case 'Z':
      state = 41;
break;
    case '_':
      state = 41;
break;
    case 'a':
      state = 41;
break;
    case 'b':
      state = 41;
break;
    case 'c':
      state = 41;
break;
    case 'd':
      state = 41;
break;
    case 'e':
      state = 41;
break;
    case 'f':
      state = 41;
break;
    case 'g':
      state = 41;
break;
    case 'h':
      state = 41;
break;
    case 'i':
      state = 41;
break;
    case 'j':
      state = 41;
break;
    case 'k':
      state = 41;
break;
    case 'l':
      state = 41;
break;
    case 'm':
      state = 41;
break;
    case 'n':
      state = 41;
break;
    case 'o':
      state = 41;
break;
    case 'p':
      state = 41;
break;
    case 'q':
      state = 41;
break;
    case 'r':
      state = 41;
break;
    case 's':
      state = 41;
break;
    case 't':
      state = 48;
break;
    case 'u':
      state = 41;
break;
    case 'v':
      state = 41;
break;
    case 'w':
      state = 41;
break;
    case 'x':
      state = 41;
break;
    case 'y':
      state = 41;
break;
    case 'z':
      state = 41;
break;
    default:
      fseek(file, -1, SEEK_CUR);
      buffer_index--;
      buffer[buffer_index] = '\0';
Token* token;
NEW_TOKEN(token);
endHandler6(token);
if (strcmp(token->type, "") != 0
   && strcmp(token->type, "SKIP") != 0) {
  strcpy(token->value, buffer);
  tail->next = token;
  tail = token;
} else {
  free(token);
}
buffer[0] = '\0';
buffer_index = 0;
state = 0;
    }
  break;
case 58:
  switch(c) {
    case '0':
      state = 41;
break;
    case '1':
      state = 41;
break;
    case '2':
      state = 41;
break;
    case '3':
      state = 41;
break;
    case '4':
      state = 41;
break;
    case '5':
      state = 41;
break;
    case '6':
      state = 41;
break;
    case '7':
      state = 41;
break;
    case '8':
      state = 41;
break;
    case '9':
      state = 41;
break;
    case 'A':
      state = 41;
break;
    case 'B':
      state = 41;
break;
    case 'C':
      state = 41;
break;
    case 'D':
      state = 41;
break;
    case 'E':
      state = 41;
break;
    case 'F':
      state = 41;
break;
    case 'G':
      state = 41;
break;
    case 'H':
      state = 41;
break;
    case 'I':
      state = 41;
break;
    case 'J':
      state = 41;
break;
    case 'K':
      state = 41;
break;
    case 'L':
      state = 41;
break;
    case 'M':
      state = 41;
break;
    case 'N':
      state = 41;
break;
    case 'O':
      state = 41;
break;
    case 'P':
      state = 41;
break;
    case 'Q':
      state = 41;
break;
    case 'R':
      state = 41;
break;
    case 'S':
      state = 41;
break;
    case 'T':
      state = 41;
break;
    case 'U':
      state = 41;
break;
    case 'V':
      state = 41;
break;
    case 'W':
      state = 41;
break;
    case 'X':
      state = 41;
break;
    case 'Y':
      state = 41;
break;
    case 'Z':
      state = 41;
break;
    case '_':
      state = 41;
break;
    case 'a':
      state = 41;
break;
    case 'b':
      state = 41;
break;
    case 'c':
      state = 41;
break;
    case 'd':
      state = 41;
break;
    case 'e':
      state = 41;
break;
    case 'f':
      state = 41;
break;
    case 'g':
      state = 41;
break;
    case 'h':
      state = 41;
break;
    case 'i':
      state = 41;
break;
    case 'j':
      state = 41;
break;
    case 'k':
      state = 41;
break;
    case 'l':
      state = 41;
break;
    case 'm':
      state = 41;
break;
    case 'n':
      state = 41;
break;
    case 'o':
      state = 59;
break;
    case 'p':
      state = 41;
break;
    case 'q':
      state = 41;
break;
    case 'r':
      state = 41;
break;
    case 's':
      state = 41;
break;
    case 't':
      state = 41;
break;
    case 'u':
      state = 41;
break;
    case 'v':
      state = 41;
break;
    case 'w':
      state = 41;
break;
    case 'x':
      state = 41;
break;
    case 'y':
      state = 41;
break;
    case 'z':
      state = 41;
break;
    default:
      fseek(file, -1, SEEK_CUR);
      buffer_index--;
      buffer[buffer_index] = '\0';
Token* token;
NEW_TOKEN(token);
endHandler6(token);
if (strcmp(token->type, "") != 0
   && strcmp(token->type, "SKIP") != 0) {
  strcpy(token->value, buffer);
  tail->next = token;
  tail = token;
} else {
  free(token);
}
buffer[0] = '\0';
buffer_index = 0;
state = 0;
    }
  break;
case 59:
  switch(c) {
    case '0':
      state = 41;
break;
    case '1':
      state = 41;
break;
    case '2':
      state = 41;
break;
    case '3':
      state = 41;
break;
    case '4':
      state = 41;
break;
    case '5':
      state = 41;
break;
    case '6':
      state = 41;
break;
    case '7':
      state = 41;
break;
    case '8':
      state = 41;
break;
    case '9':
      state = 41;
break;
    case 'A':
      state = 41;
break;
    case 'B':
      state = 41;
break;
    case 'C':
      state = 41;
break;
    case 'D':
      state = 41;
break;
    case 'E':
      state = 41;
break;
    case 'F':
      state = 41;
break;
    case 'G':
      state = 41;
break;
    case 'H':
      state = 41;
break;
    case 'I':
      state = 41;
break;
    case 'J':
      state = 41;
break;
    case 'K':
      state = 41;
break;
    case 'L':
      state = 41;
break;
    case 'M':
      state = 41;
break;
    case 'N':
      state = 41;
break;
    case 'O':
      state = 41;
break;
    case 'P':
      state = 41;
break;
    case 'Q':
      state = 41;
break;
    case 'R':
      state = 41;
break;
    case 'S':
      state = 41;
break;
    case 'T':
      state = 41;
break;
    case 'U':
      state = 41;
break;
    case 'V':
      state = 41;
break;
    case 'W':
      state = 41;
break;
    case 'X':
      state = 41;
break;
    case 'Y':
      state = 41;
break;
    case 'Z':
      state = 41;
break;
    case '_':
      state = 41;
break;
    case 'a':
      state = 41;
break;
    case 'b':
      state = 41;
break;
    case 'c':
      state = 41;
break;
    case 'd':
      state = 41;
break;
    case 'e':
      state = 41;
break;
    case 'f':
      state = 41;
break;
    case 'g':
      state = 41;
break;
    case 'h':
      state = 41;
break;
    case 'i':
      state = 41;
break;
    case 'j':
      state = 41;
break;
    case 'k':
      state = 41;
break;
    case 'l':
      state = 41;
break;
    case 'm':
      state = 41;
break;
    case 'n':
      state = 41;
break;
    case 'o':
      state = 41;
break;
    case 'p':
      state = 41;
break;
    case 'q':
      state = 41;
break;
    case 'r':
      state = 41;
break;
    case 's':
      state = 41;
break;
    case 't':
      state = 41;
break;
    case 'u':
      state = 60;
break;
    case 'v':
      state = 41;
break;
    case 'w':
      state = 41;
break;
    case 'x':
      state = 41;
break;
    case 'y':
      state = 41;
break;
    case 'z':
      state = 41;
break;
    default:
      fseek(file, -1, SEEK_CUR);
      buffer_index--;
      buffer[buffer_index] = '\0';
Token* token;
NEW_TOKEN(token);
endHandler2(token);
if (strcmp(token->type, "") != 0
   && strcmp(token->type, "SKIP") != 0) {
  strcpy(token->value, buffer);
  tail->next = token;
  tail = token;
} else {
  free(token);
}
buffer[0] = '\0';
buffer_index = 0;
state = 0;
    }
  break;
case 60:
  switch(c) {
    case '0':
      state = 41;
break;
    case '1':
      state = 41;
break;
    case '2':
      state = 41;
break;
    case '3':
      state = 41;
break;
    case '4':
      state = 41;
break;
    case '5':
      state = 41;
break;
    case '6':
      state = 41;
break;
    case '7':
      state = 41;
break;
    case '8':
      state = 41;
break;
    case '9':
      state = 41;
break;
    case 'A':
      state = 41;
break;
    case 'B':
      state = 41;
break;
    case 'C':
      state = 41;
break;
    case 'D':
      state = 41;
break;
    case 'E':
      state = 41;
break;
    case 'F':
      state = 41;
break;
    case 'G':
      state = 41;
break;
    case 'H':
      state = 41;
break;
    case 'I':
      state = 41;
break;
    case 'J':
      state = 41;
break;
    case 'K':
      state = 41;
break;
    case 'L':
      state = 41;
break;
    case 'M':
      state = 41;
break;
    case 'N':
      state = 41;
break;
    case 'O':
      state = 41;
break;
    case 'P':
      state = 41;
break;
    case 'Q':
      state = 41;
break;
    case 'R':
      state = 41;
break;
    case 'S':
      state = 41;
break;
    case 'T':
      state = 41;
break;
    case 'U':
      state = 41;
break;
    case 'V':
      state = 41;
break;
    case 'W':
      state = 41;
break;
    case 'X':
      state = 41;
break;
    case 'Y':
      state = 41;
break;
    case 'Z':
      state = 41;
break;
    case '_':
      state = 41;
break;
    case 'a':
      state = 41;
break;
    case 'b':
      state = 61;
break;
    case 'c':
      state = 41;
break;
    case 'd':
      state = 41;
break;
    case 'e':
      state = 41;
break;
    case 'f':
      state = 41;
break;
    case 'g':
      state = 41;
break;
    case 'h':
      state = 41;
break;
    case 'i':
      state = 41;
break;
    case 'j':
      state = 41;
break;
    case 'k':
      state = 41;
break;
    case 'l':
      state = 41;
break;
    case 'm':
      state = 41;
break;
    case 'n':
      state = 41;
break;
    case 'o':
      state = 41;
break;
    case 'p':
      state = 41;
break;
    case 'q':
      state = 41;
break;
    case 'r':
      state = 41;
break;
    case 's':
      state = 41;
break;
    case 't':
      state = 41;
break;
    case 'u':
      state = 41;
break;
    case 'v':
      state = 41;
break;
    case 'w':
      state = 41;
break;
    case 'x':
      state = 41;
break;
    case 'y':
      state = 41;
break;
    case 'z':
      state = 41;
break;
    default:
      fseek(file, -1, SEEK_CUR);
      buffer_index--;
      buffer[buffer_index] = '\0';
Token* token;
NEW_TOKEN(token);
endHandler6(token);
if (strcmp(token->type, "") != 0
   && strcmp(token->type, "SKIP") != 0) {
  strcpy(token->value, buffer);
  tail->next = token;
  tail = token;
} else {
  free(token);
}
buffer[0] = '\0';
buffer_index = 0;
state = 0;
    }
  break;
case 61:
  switch(c) {
    case '0':
      state = 41;
break;
    case '1':
      state = 41;
break;
    case '2':
      state = 41;
break;
    case '3':
      state = 41;
break;
    case '4':
      state = 41;
break;
    case '5':
      state = 41;
break;
    case '6':
      state = 41;
break;
    case '7':
      state = 41;
break;
    case '8':
      state = 41;
break;
    case '9':
      state = 41;
break;
    case 'A':
      state = 41;
break;
    case 'B':
      state = 41;
break;
    case 'C':
      state = 41;
break;
    case 'D':
      state = 41;
break;
    case 'E':
      state = 41;
break;
    case 'F':
      state = 41;
break;
    case 'G':
      state = 41;
break;
    case 'H':
      state = 41;
break;
    case 'I':
      state = 41;
break;
    case 'J':
      state = 41;
break;
    case 'K':
      state = 41;
break;
    case 'L':
      state = 41;
break;
    case 'M':
      state = 41;
break;
    case 'N':
      state = 41;
break;
    case 'O':
      state = 41;
break;
    case 'P':
      state = 41;
break;
    case 'Q':
      state = 41;
break;
    case 'R':
      state = 41;
break;
    case 'S':
      state = 41;
break;
    case 'T':
      state = 41;
break;
    case 'U':
      state = 41;
break;
    case 'V':
      state = 41;
break;
    case 'W':
      state = 41;
break;
    case 'X':
      state = 41;
break;
    case 'Y':
      state = 41;
break;
    case 'Z':
      state = 41;
break;
    case '_':
      state = 41;
break;
    case 'a':
      state = 41;
break;
    case 'b':
      state = 41;
break;
    case 'c':
      state = 41;
break;
    case 'd':
      state = 41;
break;
    case 'e':
      state = 41;
break;
    case 'f':
      state = 41;
break;
    case 'g':
      state = 41;
break;
    case 'h':
      state = 41;
break;
    case 'i':
      state = 41;
break;
    case 'j':
      state = 41;
break;
    case 'k':
      state = 41;
break;
    case 'l':
      state = 62;
break;
    case 'm':
      state = 41;
break;
    case 'n':
      state = 41;
break;
    case 'o':
      state = 41;
break;
    case 'p':
      state = 41;
break;
    case 'q':
      state = 41;
break;
    case 'r':
      state = 41;
break;
    case 's':
      state = 41;
break;
    case 't':
      state = 41;
break;
    case 'u':
      state = 41;
break;
    case 'v':
      state = 41;
break;
    case 'w':
      state = 41;
break;
    case 'x':
      state = 41;
break;
    case 'y':
      state = 41;
break;
    case 'z':
      state = 41;
break;
    default:
      fseek(file, -1, SEEK_CUR);
      buffer_index--;
      buffer[buffer_index] = '\0';
Token* token;
NEW_TOKEN(token);
endHandler6(token);
if (strcmp(token->type, "") != 0
   && strcmp(token->type, "SKIP") != 0) {
  strcpy(token->value, buffer);
  tail->next = token;
  tail = token;
} else {
  free(token);
}
buffer[0] = '\0';
buffer_index = 0;
state = 0;
    }
  break;
case 62:
  switch(c) {
    case '0':
      state = 41;
break;
    case '1':
      state = 41;
break;
    case '2':
      state = 41;
break;
    case '3':
      state = 41;
break;
    case '4':
      state = 41;
break;
    case '5':
      state = 41;
break;
    case '6':
      state = 41;
break;
    case '7':
      state = 41;
break;
    case '8':
      state = 41;
break;
    case '9':
      state = 41;
break;
    case 'A':
      state = 41;
break;
    case 'B':
      state = 41;
break;
    case 'C':
      state = 41;
break;
    case 'D':
      state = 41;
break;
    case 'E':
      state = 41;
break;
    case 'F':
      state = 41;
break;
    case 'G':
      state = 41;
break;
    case 'H':
      state = 41;
break;
    case 'I':
      state = 41;
break;
    case 'J':
      state = 41;
break;
    case 'K':
      state = 41;
break;
    case 'L':
      state = 41;
break;
    case 'M':
      state = 41;
break;
    case 'N':
      state = 41;
break;
    case 'O':
      state = 41;
break;
    case 'P':
      state = 41;
break;
    case 'Q':
      state = 41;
break;
    case 'R':
      state = 41;
break;
    case 'S':
      state = 41;
break;
    case 'T':
      state = 41;
break;
    case 'U':
      state = 41;
break;
    case 'V':
      state = 41;
break;
    case 'W':
      state = 41;
break;
    case 'X':
      state = 41;
break;
    case 'Y':
      state = 41;
break;
    case 'Z':
      state = 41;
break;
    case '_':
      state = 41;
break;
    case 'a':
      state = 41;
break;
    case 'b':
      state = 41;
break;
    case 'c':
      state = 41;
break;
    case 'd':
      state = 41;
break;
    case 'e':
      state = 54;
break;
    case 'f':
      state = 41;
break;
    case 'g':
      state = 41;
break;
    case 'h':
      state = 41;
break;
    case 'i':
      state = 41;
break;
    case 'j':
      state = 41;
break;
    case 'k':
      state = 41;
break;
    case 'l':
      state = 41;
break;
    case 'm':
      state = 41;
break;
    case 'n':
      state = 41;
break;
    case 'o':
      state = 41;
break;
    case 'p':
      state = 41;
break;
    case 'q':
      state = 41;
break;
    case 'r':
      state = 41;
break;
    case 's':
      state = 41;
break;
    case 't':
      state = 41;
break;
    case 'u':
      state = 41;
break;
    case 'v':
      state = 41;
break;
    case 'w':
      state = 41;
break;
    case 'x':
      state = 41;
break;
    case 'y':
      state = 41;
break;
    case 'z':
      state = 41;
break;
    default:
      fseek(file, -1, SEEK_CUR);
      buffer_index--;
      buffer[buffer_index] = '\0';
Token* token;
NEW_TOKEN(token);
endHandler6(token);
if (strcmp(token->type, "") != 0
   && strcmp(token->type, "SKIP") != 0) {
  strcpy(token->value, buffer);
  tail->next = token;
  tail = token;
} else {
  free(token);
}
buffer[0] = '\0';
buffer_index = 0;
state = 0;
    }
  break;
case 63:
  switch(c) {
    case '0':
      state = 41;
break;
    case '1':
      state = 41;
break;
    case '2':
      state = 41;
break;
    case '3':
      state = 41;
break;
    case '4':
      state = 41;
break;
    case '5':
      state = 41;
break;
    case '6':
      state = 41;
break;
    case '7':
      state = 41;
break;
    case '8':
      state = 41;
break;
    case '9':
      state = 41;
break;
    case 'A':
      state = 41;
break;
    case 'B':
      state = 41;
break;
    case 'C':
      state = 41;
break;
    case 'D':
      state = 41;
break;
    case 'E':
      state = 41;
break;
    case 'F':
      state = 41;
break;
    case 'G':
      state = 41;
break;
    case 'H':
      state = 41;
break;
    case 'I':
      state = 41;
break;
    case 'J':
      state = 41;
break;
    case 'K':
      state = 41;
break;
    case 'L':
      state = 41;
break;
    case 'M':
      state = 41;
break;
    case 'N':
      state = 41;
break;
    case 'O':
      state = 41;
break;
    case 'P':
      state = 41;
break;
    case 'Q':
      state = 41;
break;
    case 'R':
      state = 41;
break;
    case 'S':
      state = 41;
break;
    case 'T':
      state = 41;
break;
    case 'U':
      state = 41;
break;
    case 'V':
      state = 41;
break;
    case 'W':
      state = 41;
break;
    case 'X':
      state = 41;
break;
    case 'Y':
      state = 41;
break;
    case 'Z':
      state = 41;
break;
    case '_':
      state = 41;
break;
    case 'a':
      state = 41;
break;
    case 'b':
      state = 41;
break;
    case 'c':
      state = 41;
break;
    case 'd':
      state = 41;
break;
    case 'e':
      state = 41;
break;
    case 'f':
      state = 41;
break;
    case 'g':
      state = 41;
break;
    case 'h':
      state = 41;
break;
    case 'i':
      state = 41;
break;
    case 'j':
      state = 41;
break;
    case 'k':
      state = 41;
break;
    case 'l':
      state = 50;
break;
    case 'm':
      state = 41;
break;
    case 'n':
      state = 41;
break;
    case 'o':
      state = 41;
break;
    case 'p':
      state = 41;
break;
    case 'q':
      state = 41;
break;
    case 'r':
      state = 41;
break;
    case 's':
      state = 41;
break;
    case 't':
      state = 41;
break;
    case 'u':
      state = 41;
break;
    case 'v':
      state = 41;
break;
    case 'w':
      state = 41;
break;
    case 'x':
      state = 41;
break;
    case 'y':
      state = 41;
break;
    case 'z':
      state = 41;
break;
    default:
      fseek(file, -1, SEEK_CUR);
      buffer_index--;
      buffer[buffer_index] = '\0';
Token* token;
NEW_TOKEN(token);
endHandler6(token);
if (strcmp(token->type, "") != 0
   && strcmp(token->type, "SKIP") != 0) {
  strcpy(token->value, buffer);
  tail->next = token;
  tail = token;
} else {
  free(token);
}
buffer[0] = '\0';
buffer_index = 0;
state = 0;
    }
  break;
case 64:
  switch(c) {
    case '0':
      state = 41;
break;
    case '1':
      state = 41;
break;
    case '2':
      state = 41;
break;
    case '3':
      state = 41;
break;
    case '4':
      state = 41;
break;
    case '5':
      state = 41;
break;
    case '6':
      state = 41;
break;
    case '7':
      state = 41;
break;
    case '8':
      state = 41;
break;
    case '9':
      state = 41;
break;
    case 'A':
      state = 41;
break;
    case 'B':
      state = 41;
break;
    case 'C':
      state = 41;
break;
    case 'D':
      state = 41;
break;
    case 'E':
      state = 41;
break;
    case 'F':
      state = 41;
break;
    case 'G':
      state = 41;
break;
    case 'H':
      state = 41;
break;
    case 'I':
      state = 41;
break;
    case 'J':
      state = 41;
break;
    case 'K':
      state = 41;
break;
    case 'L':
      state = 41;
break;
    case 'M':
      state = 41;
break;
    case 'N':
      state = 41;
break;
    case 'O':
      state = 41;
break;
    case 'P':
      state = 41;
break;
    case 'Q':
      state = 41;
break;
    case 'R':
      state = 41;
break;
    case 'S':
      state = 41;
break;
    case 'T':
      state = 41;
break;
    case 'U':
      state = 41;
break;
    case 'V':
      state = 41;
break;
    case 'W':
      state = 41;
break;
    case 'X':
      state = 41;
break;
    case 'Y':
      state = 41;
break;
    case 'Z':
      state = 41;
break;
    case '_':
      state = 41;
break;
    case 'a':
      state = 41;
break;
    case 'b':
      state = 41;
break;
    case 'c':
      state = 41;
break;
    case 'd':
      state = 41;
break;
    case 'e':
      state = 41;
break;
    case 'f':
      state = 41;
break;
    case 'g':
      state = 41;
break;
    case 'h':
      state = 41;
break;
    case 'i':
      state = 41;
break;
    case 'j':
      state = 41;
break;
    case 'k':
      state = 41;
break;
    case 'l':
      state = 65;
break;
    case 'm':
      state = 41;
break;
    case 'n':
      state = 41;
break;
    case 'o':
      state = 68;
break;
    case 'p':
      state = 41;
break;
    case 'q':
      state = 41;
break;
    case 'r':
      state = 41;
break;
    case 's':
      state = 41;
break;
    case 't':
      state = 41;
break;
    case 'u':
      state = 41;
break;
    case 'v':
      state = 41;
break;
    case 'w':
      state = 41;
break;
    case 'x':
      state = 41;
break;
    case 'y':
      state = 41;
break;
    case 'z':
      state = 41;
break;
    default:
      fseek(file, -1, SEEK_CUR);
      buffer_index--;
      buffer[buffer_index] = '\0';
Token* token;
NEW_TOKEN(token);
endHandler6(token);
if (strcmp(token->type, "") != 0
   && strcmp(token->type, "SKIP") != 0) {
  strcpy(token->value, buffer);
  tail->next = token;
  tail = token;
} else {
  free(token);
}
buffer[0] = '\0';
buffer_index = 0;
state = 0;
    }
  break;
case 65:
  switch(c) {
    case '0':
      state = 41;
break;
    case '1':
      state = 41;
break;
    case '2':
      state = 41;
break;
    case '3':
      state = 41;
break;
    case '4':
      state = 41;
break;
    case '5':
      state = 41;
break;
    case '6':
      state = 41;
break;
    case '7':
      state = 41;
break;
    case '8':
      state = 41;
break;
    case '9':
      state = 41;
break;
    case 'A':
      state = 41;
break;
    case 'B':
      state = 41;
break;
    case 'C':
      state = 41;
break;
    case 'D':
      state = 41;
break;
    case 'E':
      state = 41;
break;
    case 'F':
      state = 41;
break;
    case 'G':
      state = 41;
break;
    case 'H':
      state = 41;
break;
    case 'I':
      state = 41;
break;
    case 'J':
      state = 41;
break;
    case 'K':
      state = 41;
break;
    case 'L':
      state = 41;
break;
    case 'M':
      state = 41;
break;
    case 'N':
      state = 41;
break;
    case 'O':
      state = 41;
break;
    case 'P':
      state = 41;
break;
    case 'Q':
      state = 41;
break;
    case 'R':
      state = 41;
break;
    case 'S':
      state = 41;
break;
    case 'T':
      state = 41;
break;
    case 'U':
      state = 41;
break;
    case 'V':
      state = 41;
break;
    case 'W':
      state = 41;
break;
    case 'X':
      state = 41;
break;
    case 'Y':
      state = 41;
break;
    case 'Z':
      state = 41;
break;
    case '_':
      state = 41;
break;
    case 'a':
      state = 41;
break;
    case 'b':
      state = 41;
break;
    case 'c':
      state = 41;
break;
    case 'd':
      state = 41;
break;
    case 'e':
      state = 41;
break;
    case 'f':
      state = 41;
break;
    case 'g':
      state = 41;
break;
    case 'h':
      state = 41;
break;
    case 'i':
      state = 41;
break;
    case 'j':
      state = 41;
break;
    case 'k':
      state = 41;
break;
    case 'l':
      state = 41;
break;
    case 'm':
      state = 41;
break;
    case 'n':
      state = 41;
break;
    case 'o':
      state = 66;
break;
    case 'p':
      state = 41;
break;
    case 'q':
      state = 41;
break;
    case 'r':
      state = 41;
break;
    case 's':
      state = 41;
break;
    case 't':
      state = 41;
break;
    case 'u':
      state = 41;
break;
    case 'v':
      state = 41;
break;
    case 'w':
      state = 41;
break;
    case 'x':
      state = 41;
break;
    case 'y':
      state = 41;
break;
    case 'z':
      state = 41;
break;
    default:
      fseek(file, -1, SEEK_CUR);
      buffer_index--;
      buffer[buffer_index] = '\0';
Token* token;
NEW_TOKEN(token);
endHandler6(token);
if (strcmp(token->type, "") != 0
   && strcmp(token->type, "SKIP") != 0) {
  strcpy(token->value, buffer);
  tail->next = token;
  tail = token;
} else {
  free(token);
}
buffer[0] = '\0';
buffer_index = 0;
state = 0;
    }
  break;
case 66:
  switch(c) {
    case '0':
      state = 41;
break;
    case '1':
      state = 41;
break;
    case '2':
      state = 41;
break;
    case '3':
      state = 41;
break;
    case '4':
      state = 41;
break;
    case '5':
      state = 41;
break;
    case '6':
      state = 41;
break;
    case '7':
      state = 41;
break;
    case '8':
      state = 41;
break;
    case '9':
      state = 41;
break;
    case 'A':
      state = 41;
break;
    case 'B':
      state = 41;
break;
    case 'C':
      state = 41;
break;
    case 'D':
      state = 41;
break;
    case 'E':
      state = 41;
break;
    case 'F':
      state = 41;
break;
    case 'G':
      state = 41;
break;
    case 'H':
      state = 41;
break;
    case 'I':
      state = 41;
break;
    case 'J':
      state = 41;
break;
    case 'K':
      state = 41;
break;
    case 'L':
      state = 41;
break;
    case 'M':
      state = 41;
break;
    case 'N':
      state = 41;
break;
    case 'O':
      state = 41;
break;
    case 'P':
      state = 41;
break;
    case 'Q':
      state = 41;
break;
    case 'R':
      state = 41;
break;
    case 'S':
      state = 41;
break;
    case 'T':
      state = 41;
break;
    case 'U':
      state = 41;
break;
    case 'V':
      state = 41;
break;
    case 'W':
      state = 41;
break;
    case 'X':
      state = 41;
break;
    case 'Y':
      state = 41;
break;
    case 'Z':
      state = 41;
break;
    case '_':
      state = 41;
break;
    case 'a':
      state = 67;
break;
    case 'b':
      state = 41;
break;
    case 'c':
      state = 41;
break;
    case 'd':
      state = 41;
break;
    case 'e':
      state = 41;
break;
    case 'f':
      state = 41;
break;
    case 'g':
      state = 41;
break;
    case 'h':
      state = 41;
break;
    case 'i':
      state = 41;
break;
    case 'j':
      state = 41;
break;
    case 'k':
      state = 41;
break;
    case 'l':
      state = 41;
break;
    case 'm':
      state = 41;
break;
    case 'n':
      state = 41;
break;
    case 'o':
      state = 41;
break;
    case 'p':
      state = 41;
break;
    case 'q':
      state = 41;
break;
    case 'r':
      state = 41;
break;
    case 's':
      state = 41;
break;
    case 't':
      state = 41;
break;
    case 'u':
      state = 41;
break;
    case 'v':
      state = 41;
break;
    case 'w':
      state = 41;
break;
    case 'x':
      state = 41;
break;
    case 'y':
      state = 41;
break;
    case 'z':
      state = 41;
break;
    default:
      fseek(file, -1, SEEK_CUR);
      buffer_index--;
      buffer[buffer_index] = '\0';
Token* token;
NEW_TOKEN(token);
endHandler6(token);
if (strcmp(token->type, "") != 0
   && strcmp(token->type, "SKIP") != 0) {
  strcpy(token->value, buffer);
  tail->next = token;
  tail = token;
} else {
  free(token);
}
buffer[0] = '\0';
buffer_index = 0;
state = 0;
    }
  break;
case 67:
  switch(c) {
    case '0':
      state = 41;
break;
    case '1':
      state = 41;
break;
    case '2':
      state = 41;
break;
    case '3':
      state = 41;
break;
    case '4':
      state = 41;
break;
    case '5':
      state = 41;
break;
    case '6':
      state = 41;
break;
    case '7':
      state = 41;
break;
    case '8':
      state = 41;
break;
    case '9':
      state = 41;
break;
    case 'A':
      state = 41;
break;
    case 'B':
      state = 41;
break;
    case 'C':
      state = 41;
break;
    case 'D':
      state = 41;
break;
    case 'E':
      state = 41;
break;
    case 'F':
      state = 41;
break;
    case 'G':
      state = 41;
break;
    case 'H':
      state = 41;
break;
    case 'I':
      state = 41;
break;
    case 'J':
      state = 41;
break;
    case 'K':
      state = 41;
break;
    case 'L':
      state = 41;
break;
    case 'M':
      state = 41;
break;
    case 'N':
      state = 41;
break;
    case 'O':
      state = 41;
break;
    case 'P':
      state = 41;
break;
    case 'Q':
      state = 41;
break;
    case 'R':
      state = 41;
break;
    case 'S':
      state = 41;
break;
    case 'T':
      state = 41;
break;
    case 'U':
      state = 41;
break;
    case 'V':
      state = 41;
break;
    case 'W':
      state = 41;
break;
    case 'X':
      state = 41;
break;
    case 'Y':
      state = 41;
break;
    case 'Z':
      state = 41;
break;
    case '_':
      state = 41;
break;
    case 'a':
      state = 41;
break;
    case 'b':
      state = 41;
break;
    case 'c':
      state = 41;
break;
    case 'd':
      state = 41;
break;
    case 'e':
      state = 41;
break;
    case 'f':
      state = 41;
break;
    case 'g':
      state = 41;
break;
    case 'h':
      state = 41;
break;
    case 'i':
      state = 41;
break;
    case 'j':
      state = 41;
break;
    case 'k':
      state = 41;
break;
    case 'l':
      state = 41;
break;
    case 'm':
      state = 41;
break;
    case 'n':
      state = 41;
break;
    case 'o':
      state = 41;
break;
    case 'p':
      state = 41;
break;
    case 'q':
      state = 41;
break;
    case 'r':
      state = 41;
break;
    case 's':
      state = 41;
break;
    case 't':
      state = 54;
break;
    case 'u':
      state = 41;
break;
    case 'v':
      state = 41;
break;
    case 'w':
      state = 41;
break;
    case 'x':
      state = 41;
break;
    case 'y':
      state = 41;
break;
    case 'z':
      state = 41;
break;
    default:
      fseek(file, -1, SEEK_CUR);
      buffer_index--;
      buffer[buffer_index] = '\0';
Token* token;
NEW_TOKEN(token);
endHandler6(token);
if (strcmp(token->type, "") != 0
   && strcmp(token->type, "SKIP") != 0) {
  strcpy(token->value, buffer);
  tail->next = token;
  tail = token;
} else {
  free(token);
}
buffer[0] = '\0';
buffer_index = 0;
state = 0;
    }
  break;
case 68:
  switch(c) {
    case '0':
      state = 41;
break;
    case '1':
      state = 41;
break;
    case '2':
      state = 41;
break;
    case '3':
      state = 41;
break;
    case '4':
      state = 41;
break;
    case '5':
      state = 41;
break;
    case '6':
      state = 41;
break;
    case '7':
      state = 41;
break;
    case '8':
      state = 41;
break;
    case '9':
      state = 41;
break;
    case 'A':
      state = 41;
break;
    case 'B':
      state = 41;
break;
    case 'C':
      state = 41;
break;
    case 'D':
      state = 41;
break;
    case 'E':
      state = 41;
break;
    case 'F':
      state = 41;
break;
    case 'G':
      state = 41;
break;
    case 'H':
      state = 41;
break;
    case 'I':
      state = 41;
break;
    case 'J':
      state = 41;
break;
    case 'K':
      state = 41;
break;
    case 'L':
      state = 41;
break;
    case 'M':
      state = 41;
break;
    case 'N':
      state = 41;
break;
    case 'O':
      state = 41;
break;
    case 'P':
      state = 41;
break;
    case 'Q':
      state = 41;
break;
    case 'R':
      state = 41;
break;
    case 'S':
      state = 41;
break;
    case 'T':
      state = 41;
break;
    case 'U':
      state = 41;
break;
    case 'V':
      state = 41;
break;
    case 'W':
      state = 41;
break;
    case 'X':
      state = 41;
break;
    case 'Y':
      state = 41;
break;
    case 'Z':
      state = 41;
break;
    case '_':
      state = 41;
break;
    case 'a':
      state = 41;
break;
    case 'b':
      state = 41;
break;
    case 'c':
      state = 41;
break;
    case 'd':
      state = 41;
break;
    case 'e':
      state = 41;
break;
    case 'f':
      state = 41;
break;
    case 'g':
      state = 41;
break;
    case 'h':
      state = 41;
break;
    case 'i':
      state = 41;
break;
    case 'j':
      state = 41;
break;
    case 'k':
      state = 41;
break;
    case 'l':
      state = 41;
break;
    case 'm':
      state = 41;
break;
    case 'n':
      state = 41;
break;
    case 'o':
      state = 41;
break;
    case 'p':
      state = 41;
break;
    case 'q':
      state = 41;
break;
    case 'r':
      state = 48;
break;
    case 's':
      state = 41;
break;
    case 't':
      state = 41;
break;
    case 'u':
      state = 41;
break;
    case 'v':
      state = 41;
break;
    case 'w':
      state = 41;
break;
    case 'x':
      state = 41;
break;
    case 'y':
      state = 41;
break;
    case 'z':
      state = 41;
break;
    default:
      fseek(file, -1, SEEK_CUR);
      buffer_index--;
      buffer[buffer_index] = '\0';
Token* token;
NEW_TOKEN(token);
endHandler6(token);
if (strcmp(token->type, "") != 0
   && strcmp(token->type, "SKIP") != 0) {
  strcpy(token->value, buffer);
  tail->next = token;
  tail = token;
} else {
  free(token);
}
buffer[0] = '\0';
buffer_index = 0;
state = 0;
    }
  break;
case 69:
  switch(c) {
    case '0':
      state = 41;
break;
    case '1':
      state = 41;
break;
    case '2':
      state = 41;
break;
    case '3':
      state = 41;
break;
    case '4':
      state = 41;
break;
    case '5':
      state = 41;
break;
    case '6':
      state = 41;
break;
    case '7':
      state = 41;
break;
    case '8':
      state = 41;
break;
    case '9':
      state = 41;
break;
    case 'A':
      state = 41;
break;
    case 'B':
      state = 41;
break;
    case 'C':
      state = 41;
break;
    case 'D':
      state = 41;
break;
    case 'E':
      state = 41;
break;
    case 'F':
      state = 41;
break;
    case 'G':
      state = 41;
break;
    case 'H':
      state = 41;
break;
    case 'I':
      state = 41;
break;
    case 'J':
      state = 41;
break;
    case 'K':
      state = 41;
break;
    case 'L':
      state = 41;
break;
    case 'M':
      state = 41;
break;
    case 'N':
      state = 41;
break;
    case 'O':
      state = 41;
break;
    case 'P':
      state = 41;
break;
    case 'Q':
      state = 41;
break;
    case 'R':
      state = 41;
break;
    case 'S':
      state = 41;
break;
    case 'T':
      state = 41;
break;
    case 'U':
      state = 41;
break;
    case 'V':
      state = 41;
break;
    case 'W':
      state = 41;
break;
    case 'X':
      state = 41;
break;
    case 'Y':
      state = 41;
break;
    case 'Z':
      state = 41;
break;
    case '_':
      state = 41;
break;
    case 'a':
      state = 41;
break;
    case 'b':
      state = 41;
break;
    case 'c':
      state = 41;
break;
    case 'd':
      state = 41;
break;
    case 'e':
      state = 41;
break;
    case 'f':
      state = 48;
break;
    case 'g':
      state = 41;
break;
    case 'h':
      state = 41;
break;
    case 'i':
      state = 41;
break;
    case 'j':
      state = 41;
break;
    case 'k':
      state = 41;
break;
    case 'l':
      state = 41;
break;
    case 'm':
      state = 41;
break;
    case 'n':
      state = 67;
break;
    case 'o':
      state = 41;
break;
    case 'p':
      state = 41;
break;
    case 'q':
      state = 41;
break;
    case 'r':
      state = 41;
break;
    case 's':
      state = 41;
break;
    case 't':
      state = 41;
break;
    case 'u':
      state = 41;
break;
    case 'v':
      state = 41;
break;
    case 'w':
      state = 41;
break;
    case 'x':
      state = 41;
break;
    case 'y':
      state = 41;
break;
    case 'z':
      state = 41;
break;
    default:
      fseek(file, -1, SEEK_CUR);
      buffer_index--;
      buffer[buffer_index] = '\0';
Token* token;
NEW_TOKEN(token);
endHandler6(token);
if (strcmp(token->type, "") != 0
   && strcmp(token->type, "SKIP") != 0) {
  strcpy(token->value, buffer);
  tail->next = token;
  tail = token;
} else {
  free(token);
}
buffer[0] = '\0';
buffer_index = 0;
state = 0;
    }
  break;
case 70:
  switch(c) {
    case '0':
      state = 41;
break;
    case '1':
      state = 41;
break;
    case '2':
      state = 41;
break;
    case '3':
      state = 41;
break;
    case '4':
      state = 41;
break;
    case '5':
      state = 41;
break;
    case '6':
      state = 41;
break;
    case '7':
      state = 41;
break;
    case '8':
      state = 41;
break;
    case '9':
      state = 41;
break;
    case 'A':
      state = 41;
break;
    case 'B':
      state = 41;
break;
    case 'C':
      state = 41;
break;
    case 'D':
      state = 41;
break;
    case 'E':
      state = 41;
break;
    case 'F':
      state = 41;
break;
    case 'G':
      state = 41;
break;
    case 'H':
      state = 41;
break;
    case 'I':
      state = 41;
break;
    case 'J':
      state = 41;
break;
    case 'K':
      state = 41;
break;
    case 'L':
      state = 41;
break;
    case 'M':
      state = 41;
break;
    case 'N':
      state = 41;
break;
    case 'O':
      state = 41;
break;
    case 'P':
      state = 41;
break;
    case 'Q':
      state = 41;
break;
    case 'R':
      state = 41;
break;
    case 'S':
      state = 41;
break;
    case 'T':
      state = 41;
break;
    case 'U':
      state = 41;
break;
    case 'V':
      state = 41;
break;
    case 'W':
      state = 41;
break;
    case 'X':
      state = 41;
break;
    case 'Y':
      state = 41;
break;
    case 'Z':
      state = 41;
break;
    case '_':
      state = 41;
break;
    case 'a':
      state = 41;
break;
    case 'b':
      state = 41;
break;
    case 'c':
      state = 41;
break;
    case 'd':
      state = 41;
break;
    case 'e':
      state = 41;
break;
    case 'f':
      state = 41;
break;
    case 'g':
      state = 41;
break;
    case 'h':
      state = 41;
break;
    case 'i':
      state = 41;
break;
    case 'j':
      state = 41;
break;
    case 'k':
      state = 41;
break;
    case 'l':
      state = 41;
break;
    case 'm':
      state = 41;
break;
    case 'n':
      state = 41;
break;
    case 'o':
      state = 71;
break;
    case 'p':
      state = 41;
break;
    case 'q':
      state = 41;
break;
    case 'r':
      state = 41;
break;
    case 's':
      state = 41;
break;
    case 't':
      state = 41;
break;
    case 'u':
      state = 41;
break;
    case 'v':
      state = 41;
break;
    case 'w':
      state = 41;
break;
    case 'x':
      state = 41;
break;
    case 'y':
      state = 41;
break;
    case 'z':
      state = 41;
break;
    default:
      fseek(file, -1, SEEK_CUR);
      buffer_index--;
      buffer[buffer_index] = '\0';
Token* token;
NEW_TOKEN(token);
endHandler6(token);
if (strcmp(token->type, "") != 0
   && strcmp(token->type, "SKIP") != 0) {
  strcpy(token->value, buffer);
  tail->next = token;
  tail = token;
} else {
  free(token);
}
buffer[0] = '\0';
buffer_index = 0;
state = 0;
    }
  break;
case 71:
  switch(c) {
    case '0':
      state = 41;
break;
    case '1':
      state = 41;
break;
    case '2':
      state = 41;
break;
    case '3':
      state = 41;
break;
    case '4':
      state = 41;
break;
    case '5':
      state = 41;
break;
    case '6':
      state = 41;
break;
    case '7':
      state = 41;
break;
    case '8':
      state = 41;
break;
    case '9':
      state = 41;
break;
    case 'A':
      state = 41;
break;
    case 'B':
      state = 41;
break;
    case 'C':
      state = 41;
break;
    case 'D':
      state = 41;
break;
    case 'E':
      state = 41;
break;
    case 'F':
      state = 41;
break;
    case 'G':
      state = 41;
break;
    case 'H':
      state = 41;
break;
    case 'I':
      state = 41;
break;
    case 'J':
      state = 41;
break;
    case 'K':
      state = 41;
break;
    case 'L':
      state = 41;
break;
    case 'M':
      state = 41;
break;
    case 'N':
      state = 41;
break;
    case 'O':
      state = 41;
break;
    case 'P':
      state = 41;
break;
    case 'Q':
      state = 41;
break;
    case 'R':
      state = 41;
break;
    case 'S':
      state = 41;
break;
    case 'T':
      state = 41;
break;
    case 'U':
      state = 41;
break;
    case 'V':
      state = 41;
break;
    case 'W':
      state = 41;
break;
    case 'X':
      state = 41;
break;
    case 'Y':
      state = 41;
break;
    case 'Z':
      state = 41;
break;
    case '_':
      state = 41;
break;
    case 'a':
      state = 41;
break;
    case 'b':
      state = 41;
break;
    case 'c':
      state = 41;
break;
    case 'd':
      state = 41;
break;
    case 'e':
      state = 41;
break;
    case 'f':
      state = 41;
break;
    case 'g':
      state = 41;
break;
    case 'h':
      state = 41;
break;
    case 'i':
      state = 41;
break;
    case 'j':
      state = 41;
break;
    case 'k':
      state = 41;
break;
    case 'l':
      state = 41;
break;
    case 'm':
      state = 41;
break;
    case 'n':
      state = 72;
break;
    case 'o':
      state = 41;
break;
    case 'p':
      state = 41;
break;
    case 'q':
      state = 41;
break;
    case 'r':
      state = 41;
break;
    case 's':
      state = 41;
break;
    case 't':
      state = 41;
break;
    case 'u':
      state = 41;
break;
    case 'v':
      state = 41;
break;
    case 'w':
      state = 41;
break;
    case 'x':
      state = 41;
break;
    case 'y':
      state = 41;
break;
    case 'z':
      state = 41;
break;
    default:
      fseek(file, -1, SEEK_CUR);
      buffer_index--;
      buffer[buffer_index] = '\0';
Token* token;
NEW_TOKEN(token);
endHandler6(token);
if (strcmp(token->type, "") != 0
   && strcmp(token->type, "SKIP") != 0) {
  strcpy(token->value, buffer);
  tail->next = token;
  tail = token;
} else {
  free(token);
}
buffer[0] = '\0';
buffer_index = 0;
state = 0;
    }
  break;
case 72:
  switch(c) {
    case '0':
      state = 41;
break;
    case '1':
      state = 41;
break;
    case '2':
      state = 41;
break;
    case '3':
      state = 41;
break;
    case '4':
      state = 41;
break;
    case '5':
      state = 41;
break;
    case '6':
      state = 41;
break;
    case '7':
      state = 41;
break;
    case '8':
      state = 41;
break;
    case '9':
      state = 41;
break;
    case 'A':
      state = 41;
break;
    case 'B':
      state = 41;
break;
    case 'C':
      state = 41;
break;
    case 'D':
      state = 41;
break;
    case 'E':
      state = 41;
break;
    case 'F':
      state = 41;
break;
    case 'G':
      state = 41;
break;
    case 'H':
      state = 41;
break;
    case 'I':
      state = 41;
break;
    case 'J':
      state = 41;
break;
    case 'K':
      state = 41;
break;
    case 'L':
      state = 41;
break;
    case 'M':
      state = 41;
break;
    case 'N':
      state = 41;
break;
    case 'O':
      state = 41;
break;
    case 'P':
      state = 41;
break;
    case 'Q':
      state = 41;
break;
    case 'R':
      state = 41;
break;
    case 'S':
      state = 41;
break;
    case 'T':
      state = 41;
break;
    case 'U':
      state = 41;
break;
    case 'V':
      state = 41;
break;
    case 'W':
      state = 41;
break;
    case 'X':
      state = 41;
break;
    case 'Y':
      state = 41;
break;
    case 'Z':
      state = 41;
break;
    case '_':
      state = 41;
break;
    case 'a':
      state = 41;
break;
    case 'b':
      state = 41;
break;
    case 'c':
      state = 41;
break;
    case 'd':
      state = 41;
break;
    case 'e':
      state = 41;
break;
    case 'f':
      state = 41;
break;
    case 'g':
      state = 54;
break;
    case 'h':
      state = 41;
break;
    case 'i':
      state = 41;
break;
    case 'j':
      state = 41;
break;
    case 'k':
      state = 41;
break;
    case 'l':
      state = 41;
break;
    case 'm':
      state = 41;
break;
    case 'n':
      state = 41;
break;
    case 'o':
      state = 41;
break;
    case 'p':
      state = 41;
break;
    case 'q':
      state = 41;
break;
    case 'r':
      state = 41;
break;
    case 's':
      state = 41;
break;
    case 't':
      state = 41;
break;
    case 'u':
      state = 41;
break;
    case 'v':
      state = 41;
break;
    case 'w':
      state = 41;
break;
    case 'x':
      state = 41;
break;
    case 'y':
      state = 41;
break;
    case 'z':
      state = 41;
break;
    default:
      fseek(file, -1, SEEK_CUR);
      buffer_index--;
      buffer[buffer_index] = '\0';
Token* token;
NEW_TOKEN(token);
endHandler6(token);
if (strcmp(token->type, "") != 0
   && strcmp(token->type, "SKIP") != 0) {
  strcpy(token->value, buffer);
  tail->next = token;
  tail = token;
} else {
  free(token);
}
buffer[0] = '\0';
buffer_index = 0;
state = 0;
    }
  break;
case 73:
  switch(c) {
    case '0':
      state = 41;
break;
    case '1':
      state = 41;
break;
    case '2':
      state = 41;
break;
    case '3':
      state = 41;
break;
    case '4':
      state = 41;
break;
    case '5':
      state = 41;
break;
    case '6':
      state = 41;
break;
    case '7':
      state = 41;
break;
    case '8':
      state = 41;
break;
    case '9':
      state = 41;
break;
    case 'A':
      state = 41;
break;
    case 'B':
      state = 41;
break;
    case 'C':
      state = 41;
break;
    case 'D':
      state = 41;
break;
    case 'E':
      state = 41;
break;
    case 'F':
      state = 41;
break;
    case 'G':
      state = 41;
break;
    case 'H':
      state = 41;
break;
    case 'I':
      state = 41;
break;
    case 'J':
      state = 41;
break;
    case 'K':
      state = 41;
break;
    case 'L':
      state = 41;
break;
    case 'M':
      state = 41;
break;
    case 'N':
      state = 41;
break;
    case 'O':
      state = 41;
break;
    case 'P':
      state = 41;
break;
    case 'Q':
      state = 41;
break;
    case 'R':
      state = 41;
break;
    case 'S':
      state = 41;
break;
    case 'T':
      state = 41;
break;
    case 'U':
      state = 41;
break;
    case 'V':
      state = 41;
break;
    case 'W':
      state = 41;
break;
    case 'X':
      state = 41;
break;
    case 'Y':
      state = 41;
break;
    case 'Z':
      state = 41;
break;
    case '_':
      state = 41;
break;
    case 'a':
      state = 41;
break;
    case 'b':
      state = 41;
break;
    case 'c':
      state = 41;
break;
    case 'd':
      state = 41;
break;
    case 'e':
      state = 41;
break;
    case 'f':
      state = 41;
break;
    case 'g':
      state = 41;
break;
    case 'h':
      state = 41;
break;
    case 'i':
      state = 74;
break;
    case 'j':
      state = 41;
break;
    case 'k':
      state = 41;
break;
    case 'l':
      state = 41;
break;
    case 'm':
      state = 41;
break;
    case 'n':
      state = 41;
break;
    case 'o':
      state = 41;
break;
    case 'p':
      state = 41;
break;
    case 'q':
      state = 41;
break;
    case 'r':
      state = 41;
break;
    case 's':
      state = 41;
break;
    case 't':
      state = 79;
break;
    case 'u':
      state = 41;
break;
    case 'v':
      state = 41;
break;
    case 'w':
      state = 82;
break;
    case 'x':
      state = 41;
break;
    case 'y':
      state = 41;
break;
    case 'z':
      state = 41;
break;
    default:
      fseek(file, -1, SEEK_CUR);
      buffer_index--;
      buffer[buffer_index] = '\0';
Token* token;
NEW_TOKEN(token);
endHandler6(token);
if (strcmp(token->type, "") != 0
   && strcmp(token->type, "SKIP") != 0) {
  strcpy(token->value, buffer);
  tail->next = token;
  tail = token;
} else {
  free(token);
}
buffer[0] = '\0';
buffer_index = 0;
state = 0;
    }
  break;
case 74:
  switch(c) {
    case '0':
      state = 41;
break;
    case '1':
      state = 41;
break;
    case '2':
      state = 41;
break;
    case '3':
      state = 41;
break;
    case '4':
      state = 41;
break;
    case '5':
      state = 41;
break;
    case '6':
      state = 41;
break;
    case '7':
      state = 41;
break;
    case '8':
      state = 41;
break;
    case '9':
      state = 41;
break;
    case 'A':
      state = 41;
break;
    case 'B':
      state = 41;
break;
    case 'C':
      state = 41;
break;
    case 'D':
      state = 41;
break;
    case 'E':
      state = 41;
break;
    case 'F':
      state = 41;
break;
    case 'G':
      state = 41;
break;
    case 'H':
      state = 41;
break;
    case 'I':
      state = 41;
break;
    case 'J':
      state = 41;
break;
    case 'K':
      state = 41;
break;
    case 'L':
      state = 41;
break;
    case 'M':
      state = 41;
break;
    case 'N':
      state = 41;
break;
    case 'O':
      state = 41;
break;
    case 'P':
      state = 41;
break;
    case 'Q':
      state = 41;
break;
    case 'R':
      state = 41;
break;
    case 'S':
      state = 41;
break;
    case 'T':
      state = 41;
break;
    case 'U':
      state = 41;
break;
    case 'V':
      state = 41;
break;
    case 'W':
      state = 41;
break;
    case 'X':
      state = 41;
break;
    case 'Y':
      state = 41;
break;
    case 'Z':
      state = 41;
break;
    case '_':
      state = 41;
break;
    case 'a':
      state = 41;
break;
    case 'b':
      state = 41;
break;
    case 'c':
      state = 41;
break;
    case 'd':
      state = 41;
break;
    case 'e':
      state = 41;
break;
    case 'f':
      state = 41;
break;
    case 'g':
      state = 75;
break;
    case 'h':
      state = 41;
break;
    case 'i':
      state = 41;
break;
    case 'j':
      state = 41;
break;
    case 'k':
      state = 41;
break;
    case 'l':
      state = 41;
break;
    case 'm':
      state = 41;
break;
    case 'n':
      state = 41;
break;
    case 'o':
      state = 41;
break;
    case 'p':
      state = 41;
break;
    case 'q':
      state = 41;
break;
    case 'r':
      state = 41;
break;
    case 's':
      state = 41;
break;
    case 't':
      state = 41;
break;
    case 'u':
      state = 41;
break;
    case 'v':
      state = 41;
break;
    case 'w':
      state = 41;
break;
    case 'x':
      state = 41;
break;
    case 'y':
      state = 41;
break;
    case 'z':
      state = 41;
break;
    default:
      fseek(file, -1, SEEK_CUR);
      buffer_index--;
      buffer[buffer_index] = '\0';
Token* token;
NEW_TOKEN(token);
endHandler6(token);
if (strcmp(token->type, "") != 0
   && strcmp(token->type, "SKIP") != 0) {
  strcpy(token->value, buffer);
  tail->next = token;
  tail = token;
} else {
  free(token);
}
buffer[0] = '\0';
buffer_index = 0;
state = 0;
    }
  break;
case 75:
  switch(c) {
    case '0':
      state = 41;
break;
    case '1':
      state = 41;
break;
    case '2':
      state = 41;
break;
    case '3':
      state = 41;
break;
    case '4':
      state = 41;
break;
    case '5':
      state = 41;
break;
    case '6':
      state = 41;
break;
    case '7':
      state = 41;
break;
    case '8':
      state = 41;
break;
    case '9':
      state = 41;
break;
    case 'A':
      state = 41;
break;
    case 'B':
      state = 41;
break;
    case 'C':
      state = 41;
break;
    case 'D':
      state = 41;
break;
    case 'E':
      state = 41;
break;
    case 'F':
      state = 41;
break;
    case 'G':
      state = 41;
break;
    case 'H':
      state = 41;
break;
    case 'I':
      state = 41;
break;
    case 'J':
      state = 41;
break;
    case 'K':
      state = 41;
break;
    case 'L':
      state = 41;
break;
    case 'M':
      state = 41;
break;
    case 'N':
      state = 41;
break;
    case 'O':
      state = 41;
break;
    case 'P':
      state = 41;
break;
    case 'Q':
      state = 41;
break;
    case 'R':
      state = 41;
break;
    case 'S':
      state = 41;
break;
    case 'T':
      state = 41;
break;
    case 'U':
      state = 41;
break;
    case 'V':
      state = 41;
break;
    case 'W':
      state = 41;
break;
    case 'X':
      state = 41;
break;
    case 'Y':
      state = 41;
break;
    case 'Z':
      state = 41;
break;
    case '_':
      state = 41;
break;
    case 'a':
      state = 41;
break;
    case 'b':
      state = 41;
break;
    case 'c':
      state = 41;
break;
    case 'd':
      state = 41;
break;
    case 'e':
      state = 41;
break;
    case 'f':
      state = 41;
break;
    case 'g':
      state = 41;
break;
    case 'h':
      state = 41;
break;
    case 'i':
      state = 41;
break;
    case 'j':
      state = 41;
break;
    case 'k':
      state = 41;
break;
    case 'l':
      state = 41;
break;
    case 'm':
      state = 41;
break;
    case 'n':
      state = 76;
break;
    case 'o':
      state = 41;
break;
    case 'p':
      state = 41;
break;
    case 'q':
      state = 41;
break;
    case 'r':
      state = 41;
break;
    case 's':
      state = 41;
break;
    case 't':
      state = 41;
break;
    case 'u':
      state = 41;
break;
    case 'v':
      state = 41;
break;
    case 'w':
      state = 41;
break;
    case 'x':
      state = 41;
break;
    case 'y':
      state = 41;
break;
    case 'z':
      state = 41;
break;
    default:
      fseek(file, -1, SEEK_CUR);
      buffer_index--;
      buffer[buffer_index] = '\0';
Token* token;
NEW_TOKEN(token);
endHandler6(token);
if (strcmp(token->type, "") != 0
   && strcmp(token->type, "SKIP") != 0) {
  strcpy(token->value, buffer);
  tail->next = token;
  tail = token;
} else {
  free(token);
}
buffer[0] = '\0';
buffer_index = 0;
state = 0;
    }
  break;
case 76:
  switch(c) {
    case '0':
      state = 41;
break;
    case '1':
      state = 41;
break;
    case '2':
      state = 41;
break;
    case '3':
      state = 41;
break;
    case '4':
      state = 41;
break;
    case '5':
      state = 41;
break;
    case '6':
      state = 41;
break;
    case '7':
      state = 41;
break;
    case '8':
      state = 41;
break;
    case '9':
      state = 41;
break;
    case 'A':
      state = 41;
break;
    case 'B':
      state = 41;
break;
    case 'C':
      state = 41;
break;
    case 'D':
      state = 41;
break;
    case 'E':
      state = 41;
break;
    case 'F':
      state = 41;
break;
    case 'G':
      state = 41;
break;
    case 'H':
      state = 41;
break;
    case 'I':
      state = 41;
break;
    case 'J':
      state = 41;
break;
    case 'K':
      state = 41;
break;
    case 'L':
      state = 41;
break;
    case 'M':
      state = 41;
break;
    case 'N':
      state = 41;
break;
    case 'O':
      state = 41;
break;
    case 'P':
      state = 41;
break;
    case 'Q':
      state = 41;
break;
    case 'R':
      state = 41;
break;
    case 'S':
      state = 41;
break;
    case 'T':
      state = 41;
break;
    case 'U':
      state = 41;
break;
    case 'V':
      state = 41;
break;
    case 'W':
      state = 41;
break;
    case 'X':
      state = 41;
break;
    case 'Y':
      state = 41;
break;
    case 'Z':
      state = 41;
break;
    case '_':
      state = 41;
break;
    case 'a':
      state = 41;
break;
    case 'b':
      state = 41;
break;
    case 'c':
      state = 41;
break;
    case 'd':
      state = 41;
break;
    case 'e':
      state = 77;
break;
    case 'f':
      state = 41;
break;
    case 'g':
      state = 41;
break;
    case 'h':
      state = 41;
break;
    case 'i':
      state = 41;
break;
    case 'j':
      state = 41;
break;
    case 'k':
      state = 41;
break;
    case 'l':
      state = 41;
break;
    case 'm':
      state = 41;
break;
    case 'n':
      state = 41;
break;
    case 'o':
      state = 41;
break;
    case 'p':
      state = 41;
break;
    case 'q':
      state = 41;
break;
    case 'r':
      state = 41;
break;
    case 's':
      state = 41;
break;
    case 't':
      state = 41;
break;
    case 'u':
      state = 41;
break;
    case 'v':
      state = 41;
break;
    case 'w':
      state = 41;
break;
    case 'x':
      state = 41;
break;
    case 'y':
      state = 41;
break;
    case 'z':
      state = 41;
break;
    default:
      fseek(file, -1, SEEK_CUR);
      buffer_index--;
      buffer[buffer_index] = '\0';
Token* token;
NEW_TOKEN(token);
endHandler6(token);
if (strcmp(token->type, "") != 0
   && strcmp(token->type, "SKIP") != 0) {
  strcpy(token->value, buffer);
  tail->next = token;
  tail = token;
} else {
  free(token);
}
buffer[0] = '\0';
buffer_index = 0;
state = 0;
    }
  break;
case 77:
  switch(c) {
    case '0':
      state = 41;
break;
    case '1':
      state = 41;
break;
    case '2':
      state = 41;
break;
    case '3':
      state = 41;
break;
    case '4':
      state = 41;
break;
    case '5':
      state = 41;
break;
    case '6':
      state = 41;
break;
    case '7':
      state = 41;
break;
    case '8':
      state = 41;
break;
    case '9':
      state = 41;
break;
    case 'A':
      state = 41;
break;
    case 'B':
      state = 41;
break;
    case 'C':
      state = 41;
break;
    case 'D':
      state = 41;
break;
    case 'E':
      state = 41;
break;
    case 'F':
      state = 41;
break;
    case 'G':
      state = 41;
break;
    case 'H':
      state = 41;
break;
    case 'I':
      state = 41;
break;
    case 'J':
      state = 41;
break;
    case 'K':
      state = 41;
break;
    case 'L':
      state = 41;
break;
    case 'M':
      state = 41;
break;
    case 'N':
      state = 41;
break;
    case 'O':
      state = 41;
break;
    case 'P':
      state = 41;
break;
    case 'Q':
      state = 41;
break;
    case 'R':
      state = 41;
break;
    case 'S':
      state = 41;
break;
    case 'T':
      state = 41;
break;
    case 'U':
      state = 41;
break;
    case 'V':
      state = 41;
break;
    case 'W':
      state = 41;
break;
    case 'X':
      state = 41;
break;
    case 'Y':
      state = 41;
break;
    case 'Z':
      state = 41;
break;
    case '_':
      state = 41;
break;
    case 'a':
      state = 41;
break;
    case 'b':
      state = 41;
break;
    case 'c':
      state = 41;
break;
    case 'd':
      state = 78;
break;
    case 'e':
      state = 41;
break;
    case 'f':
      state = 41;
break;
    case 'g':
      state = 41;
break;
    case 'h':
      state = 41;
break;
    case 'i':
      state = 41;
break;
    case 'j':
      state = 41;
break;
    case 'k':
      state = 41;
break;
    case 'l':
      state = 41;
break;
    case 'm':
      state = 41;
break;
    case 'n':
      state = 41;
break;
    case 'o':
      state = 41;
break;
    case 'p':
      state = 41;
break;
    case 'q':
      state = 41;
break;
    case 'r':
      state = 41;
break;
    case 's':
      state = 41;
break;
    case 't':
      state = 41;
break;
    case 'u':
      state = 41;
break;
    case 'v':
      state = 41;
break;
    case 'w':
      state = 41;
break;
    case 'x':
      state = 41;
break;
    case 'y':
      state = 41;
break;
    case 'z':
      state = 41;
break;
    default:
      fseek(file, -1, SEEK_CUR);
      buffer_index--;
      buffer[buffer_index] = '\0';
Token* token;
NEW_TOKEN(token);
endHandler6(token);
if (strcmp(token->type, "") != 0
   && strcmp(token->type, "SKIP") != 0) {
  strcpy(token->value, buffer);
  tail->next = token;
  tail = token;
} else {
  free(token);
}
buffer[0] = '\0';
buffer_index = 0;
state = 0;
    }
  break;
case 78:
  switch(c) {
    case '0':
      state = 41;
break;
    case '1':
      state = 41;
break;
    case '2':
      state = 41;
break;
    case '3':
      state = 41;
break;
    case '4':
      state = 41;
break;
    case '5':
      state = 41;
break;
    case '6':
      state = 41;
break;
    case '7':
      state = 41;
break;
    case '8':
      state = 41;
break;
    case '9':
      state = 41;
break;
    case 'A':
      state = 41;
break;
    case 'B':
      state = 41;
break;
    case 'C':
      state = 41;
break;
    case 'D':
      state = 41;
break;
    case 'E':
      state = 41;
break;
    case 'F':
      state = 41;
break;
    case 'G':
      state = 41;
break;
    case 'H':
      state = 41;
break;
    case 'I':
      state = 41;
break;
    case 'J':
      state = 41;
break;
    case 'K':
      state = 41;
break;
    case 'L':
      state = 41;
break;
    case 'M':
      state = 41;
break;
    case 'N':
      state = 41;
break;
    case 'O':
      state = 41;
break;
    case 'P':
      state = 41;
break;
    case 'Q':
      state = 41;
break;
    case 'R':
      state = 41;
break;
    case 'S':
      state = 41;
break;
    case 'T':
      state = 41;
break;
    case 'U':
      state = 41;
break;
    case 'V':
      state = 41;
break;
    case 'W':
      state = 41;
break;
    case 'X':
      state = 41;
break;
    case 'Y':
      state = 41;
break;
    case 'Z':
      state = 41;
break;
    case '_':
      state = 41;
break;
    case 'a':
      state = 41;
break;
    case 'b':
      state = 41;
break;
    case 'c':
      state = 41;
break;
    case 'd':
      state = 41;
break;
    case 'e':
      state = 41;
break;
    case 'f':
      state = 41;
break;
    case 'g':
      state = 41;
break;
    case 'h':
      state = 41;
break;
    case 'i':
      state = 41;
break;
    case 'j':
      state = 41;
break;
    case 'k':
      state = 41;
break;
    case 'l':
      state = 41;
break;
    case 'm':
      state = 41;
break;
    case 'n':
      state = 41;
break;
    case 'o':
      state = 41;
break;
    case 'p':
      state = 41;
break;
    case 'q':
      state = 41;
break;
    case 'r':
      state = 41;
break;
    case 's':
      state = 41;
break;
    case 't':
      state = 41;
break;
    case 'u':
      state = 41;
break;
    case 'v':
      state = 41;
break;
    case 'w':
      state = 41;
break;
    case 'x':
      state = 41;
break;
    case 'y':
      state = 41;
break;
    case 'z':
      state = 41;
break;
    default:
      fseek(file, -1, SEEK_CUR);
      buffer_index--;
      buffer[buffer_index] = '\0';
Token* token;
NEW_TOKEN(token);
endHandler4(token);
if (strcmp(token->type, "") != 0
   && strcmp(token->type, "SKIP") != 0) {
  strcpy(token->value, buffer);
  tail->next = token;
  tail = token;
} else {
  free(token);
}
buffer[0] = '\0';
buffer_index = 0;
state = 0;
    }
  break;
case 79:
  switch(c) {
    case '0':
      state = 41;
break;
    case '1':
      state = 41;
break;
    case '2':
      state = 41;
break;
    case '3':
      state = 41;
break;
    case '4':
      state = 41;
break;
    case '5':
      state = 41;
break;
    case '6':
      state = 41;
break;
    case '7':
      state = 41;
break;
    case '8':
      state = 41;
break;
    case '9':
      state = 41;
break;
    case 'A':
      state = 41;
break;
    case 'B':
      state = 41;
break;
    case 'C':
      state = 41;
break;
    case 'D':
      state = 41;
break;
    case 'E':
      state = 41;
break;
    case 'F':
      state = 41;
break;
    case 'G':
      state = 41;
break;
    case 'H':
      state = 41;
break;
    case 'I':
      state = 41;
break;
    case 'J':
      state = 41;
break;
    case 'K':
      state = 41;
break;
    case 'L':
      state = 41;
break;
    case 'M':
      state = 41;
break;
    case 'N':
      state = 41;
break;
    case 'O':
      state = 41;
break;
    case 'P':
      state = 41;
break;
    case 'Q':
      state = 41;
break;
    case 'R':
      state = 41;
break;
    case 'S':
      state = 41;
break;
    case 'T':
      state = 41;
break;
    case 'U':
      state = 41;
break;
    case 'V':
      state = 41;
break;
    case 'W':
      state = 41;
break;
    case 'X':
      state = 41;
break;
    case 'Y':
      state = 41;
break;
    case 'Z':
      state = 41;
break;
    case '_':
      state = 41;
break;
    case 'a':
      state = 41;
break;
    case 'b':
      state = 41;
break;
    case 'c':
      state = 41;
break;
    case 'd':
      state = 41;
break;
    case 'e':
      state = 41;
break;
    case 'f':
      state = 41;
break;
    case 'g':
      state = 41;
break;
    case 'h':
      state = 41;
break;
    case 'i':
      state = 41;
break;
    case 'j':
      state = 41;
break;
    case 'k':
      state = 41;
break;
    case 'l':
      state = 41;
break;
    case 'm':
      state = 41;
break;
    case 'n':
      state = 41;
break;
    case 'o':
      state = 41;
break;
    case 'p':
      state = 41;
break;
    case 'q':
      state = 41;
break;
    case 'r':
      state = 80;
break;
    case 's':
      state = 41;
break;
    case 't':
      state = 41;
break;
    case 'u':
      state = 41;
break;
    case 'v':
      state = 41;
break;
    case 'w':
      state = 41;
break;
    case 'x':
      state = 41;
break;
    case 'y':
      state = 41;
break;
    case 'z':
      state = 41;
break;
    default:
      fseek(file, -1, SEEK_CUR);
      buffer_index--;
      buffer[buffer_index] = '\0';
Token* token;
NEW_TOKEN(token);
endHandler6(token);
if (strcmp(token->type, "") != 0
   && strcmp(token->type, "SKIP") != 0) {
  strcpy(token->value, buffer);
  tail->next = token;
  tail = token;
} else {
  free(token);
}
buffer[0] = '\0';
buffer_index = 0;
state = 0;
    }
  break;
case 80:
  switch(c) {
    case '0':
      state = 41;
break;
    case '1':
      state = 41;
break;
    case '2':
      state = 41;
break;
    case '3':
      state = 41;
break;
    case '4':
      state = 41;
break;
    case '5':
      state = 41;
break;
    case '6':
      state = 41;
break;
    case '7':
      state = 41;
break;
    case '8':
      state = 41;
break;
    case '9':
      state = 41;
break;
    case 'A':
      state = 41;
break;
    case 'B':
      state = 41;
break;
    case 'C':
      state = 41;
break;
    case 'D':
      state = 41;
break;
    case 'E':
      state = 41;
break;
    case 'F':
      state = 41;
break;
    case 'G':
      state = 41;
break;
    case 'H':
      state = 41;
break;
    case 'I':
      state = 41;
break;
    case 'J':
      state = 41;
break;
    case 'K':
      state = 41;
break;
    case 'L':
      state = 41;
break;
    case 'M':
      state = 41;
break;
    case 'N':
      state = 41;
break;
    case 'O':
      state = 41;
break;
    case 'P':
      state = 41;
break;
    case 'Q':
      state = 41;
break;
    case 'R':
      state = 41;
break;
    case 'S':
      state = 41;
break;
    case 'T':
      state = 41;
break;
    case 'U':
      state = 41;
break;
    case 'V':
      state = 41;
break;
    case 'W':
      state = 41;
break;
    case 'X':
      state = 41;
break;
    case 'Y':
      state = 41;
break;
    case 'Z':
      state = 41;
break;
    case '_':
      state = 41;
break;
    case 'a':
      state = 41;
break;
    case 'b':
      state = 41;
break;
    case 'c':
      state = 41;
break;
    case 'd':
      state = 41;
break;
    case 'e':
      state = 41;
break;
    case 'f':
      state = 41;
break;
    case 'g':
      state = 41;
break;
    case 'h':
      state = 41;
break;
    case 'i':
      state = 41;
break;
    case 'j':
      state = 41;
break;
    case 'k':
      state = 41;
break;
    case 'l':
      state = 41;
break;
    case 'm':
      state = 41;
break;
    case 'n':
      state = 41;
break;
    case 'o':
      state = 41;
break;
    case 'p':
      state = 41;
break;
    case 'q':
      state = 41;
break;
    case 'r':
      state = 41;
break;
    case 's':
      state = 41;
break;
    case 't':
      state = 41;
break;
    case 'u':
      state = 81;
break;
    case 'v':
      state = 41;
break;
    case 'w':
      state = 41;
break;
    case 'x':
      state = 41;
break;
    case 'y':
      state = 41;
break;
    case 'z':
      state = 41;
break;
    default:
      fseek(file, -1, SEEK_CUR);
      buffer_index--;
      buffer[buffer_index] = '\0';
Token* token;
NEW_TOKEN(token);
endHandler6(token);
if (strcmp(token->type, "") != 0
   && strcmp(token->type, "SKIP") != 0) {
  strcpy(token->value, buffer);
  tail->next = token;
  tail = token;
} else {
  free(token);
}
buffer[0] = '\0';
buffer_index = 0;
state = 0;
    }
  break;
case 81:
  switch(c) {
    case '0':
      state = 41;
break;
    case '1':
      state = 41;
break;
    case '2':
      state = 41;
break;
    case '3':
      state = 41;
break;
    case '4':
      state = 41;
break;
    case '5':
      state = 41;
break;
    case '6':
      state = 41;
break;
    case '7':
      state = 41;
break;
    case '8':
      state = 41;
break;
    case '9':
      state = 41;
break;
    case 'A':
      state = 41;
break;
    case 'B':
      state = 41;
break;
    case 'C':
      state = 41;
break;
    case 'D':
      state = 41;
break;
    case 'E':
      state = 41;
break;
    case 'F':
      state = 41;
break;
    case 'G':
      state = 41;
break;
    case 'H':
      state = 41;
break;
    case 'I':
      state = 41;
break;
    case 'J':
      state = 41;
break;
    case 'K':
      state = 41;
break;
    case 'L':
      state = 41;
break;
    case 'M':
      state = 41;
break;
    case 'N':
      state = 41;
break;
    case 'O':
      state = 41;
break;
    case 'P':
      state = 41;
break;
    case 'Q':
      state = 41;
break;
    case 'R':
      state = 41;
break;
    case 'S':
      state = 41;
break;
    case 'T':
      state = 41;
break;
    case 'U':
      state = 41;
break;
    case 'V':
      state = 41;
break;
    case 'W':
      state = 41;
break;
    case 'X':
      state = 41;
break;
    case 'Y':
      state = 41;
break;
    case 'Z':
      state = 41;
break;
    case '_':
      state = 41;
break;
    case 'a':
      state = 41;
break;
    case 'b':
      state = 41;
break;
    case 'c':
      state = 57;
break;
    case 'd':
      state = 41;
break;
    case 'e':
      state = 41;
break;
    case 'f':
      state = 41;
break;
    case 'g':
      state = 41;
break;
    case 'h':
      state = 41;
break;
    case 'i':
      state = 41;
break;
    case 'j':
      state = 41;
break;
    case 'k':
      state = 41;
break;
    case 'l':
      state = 41;
break;
    case 'm':
      state = 41;
break;
    case 'n':
      state = 41;
break;
    case 'o':
      state = 41;
break;
    case 'p':
      state = 41;
break;
    case 'q':
      state = 41;
break;
    case 'r':
      state = 41;
break;
    case 's':
      state = 41;
break;
    case 't':
      state = 41;
break;
    case 'u':
      state = 41;
break;
    case 'v':
      state = 41;
break;
    case 'w':
      state = 41;
break;
    case 'x':
      state = 41;
break;
    case 'y':
      state = 41;
break;
    case 'z':
      state = 41;
break;
    default:
      fseek(file, -1, SEEK_CUR);
      buffer_index--;
      buffer[buffer_index] = '\0';
Token* token;
NEW_TOKEN(token);
endHandler6(token);
if (strcmp(token->type, "") != 0
   && strcmp(token->type, "SKIP") != 0) {
  strcpy(token->value, buffer);
  tail->next = token;
  tail = token;
} else {
  free(token);
}
buffer[0] = '\0';
buffer_index = 0;
state = 0;
    }
  break;
case 82:
  switch(c) {
    case '0':
      state = 41;
break;
    case '1':
      state = 41;
break;
    case '2':
      state = 41;
break;
    case '3':
      state = 41;
break;
    case '4':
      state = 41;
break;
    case '5':
      state = 41;
break;
    case '6':
      state = 41;
break;
    case '7':
      state = 41;
break;
    case '8':
      state = 41;
break;
    case '9':
      state = 41;
break;
    case 'A':
      state = 41;
break;
    case 'B':
      state = 41;
break;
    case 'C':
      state = 41;
break;
    case 'D':
      state = 41;
break;
    case 'E':
      state = 41;
break;
    case 'F':
      state = 41;
break;
    case 'G':
      state = 41;
break;
    case 'H':
      state = 41;
break;
    case 'I':
      state = 41;
break;
    case 'J':
      state = 41;
break;
    case 'K':
      state = 41;
break;
    case 'L':
      state = 41;
break;
    case 'M':
      state = 41;
break;
    case 'N':
      state = 41;
break;
    case 'O':
      state = 41;
break;
    case 'P':
      state = 41;
break;
    case 'Q':
      state = 41;
break;
    case 'R':
      state = 41;
break;
    case 'S':
      state = 41;
break;
    case 'T':
      state = 41;
break;
    case 'U':
      state = 41;
break;
    case 'V':
      state = 41;
break;
    case 'W':
      state = 41;
break;
    case 'X':
      state = 41;
break;
    case 'Y':
      state = 41;
break;
    case 'Z':
      state = 41;
break;
    case '_':
      state = 41;
break;
    case 'a':
      state = 41;
break;
    case 'b':
      state = 41;
break;
    case 'c':
      state = 41;
break;
    case 'd':
      state = 41;
break;
    case 'e':
      state = 41;
break;
    case 'f':
      state = 41;
break;
    case 'g':
      state = 41;
break;
    case 'h':
      state = 41;
break;
    case 'i':
      state = 83;
break;
    case 'j':
      state = 41;
break;
    case 'k':
      state = 41;
break;
    case 'l':
      state = 41;
break;
    case 'm':
      state = 41;
break;
    case 'n':
      state = 41;
break;
    case 'o':
      state = 41;
break;
    case 'p':
      state = 41;
break;
    case 'q':
      state = 41;
break;
    case 'r':
      state = 41;
break;
    case 's':
      state = 41;
break;
    case 't':
      state = 41;
break;
    case 'u':
      state = 41;
break;
    case 'v':
      state = 41;
break;
    case 'w':
      state = 41;
break;
    case 'x':
      state = 41;
break;
    case 'y':
      state = 41;
break;
    case 'z':
      state = 41;
break;
    default:
      fseek(file, -1, SEEK_CUR);
      buffer_index--;
      buffer[buffer_index] = '\0';
Token* token;
NEW_TOKEN(token);
endHandler6(token);
if (strcmp(token->type, "") != 0
   && strcmp(token->type, "SKIP") != 0) {
  strcpy(token->value, buffer);
  tail->next = token;
  tail = token;
} else {
  free(token);
}
buffer[0] = '\0';
buffer_index = 0;
state = 0;
    }
  break;
case 83:
  switch(c) {
    case '0':
      state = 41;
break;
    case '1':
      state = 41;
break;
    case '2':
      state = 41;
break;
    case '3':
      state = 41;
break;
    case '4':
      state = 41;
break;
    case '5':
      state = 41;
break;
    case '6':
      state = 41;
break;
    case '7':
      state = 41;
break;
    case '8':
      state = 41;
break;
    case '9':
      state = 41;
break;
    case 'A':
      state = 41;
break;
    case 'B':
      state = 41;
break;
    case 'C':
      state = 41;
break;
    case 'D':
      state = 41;
break;
    case 'E':
      state = 41;
break;
    case 'F':
      state = 41;
break;
    case 'G':
      state = 41;
break;
    case 'H':
      state = 41;
break;
    case 'I':
      state = 41;
break;
    case 'J':
      state = 41;
break;
    case 'K':
      state = 41;
break;
    case 'L':
      state = 41;
break;
    case 'M':
      state = 41;
break;
    case 'N':
      state = 41;
break;
    case 'O':
      state = 41;
break;
    case 'P':
      state = 41;
break;
    case 'Q':
      state = 41;
break;
    case 'R':
      state = 41;
break;
    case 'S':
      state = 41;
break;
    case 'T':
      state = 41;
break;
    case 'U':
      state = 41;
break;
    case 'V':
      state = 41;
break;
    case 'W':
      state = 41;
break;
    case 'X':
      state = 41;
break;
    case 'Y':
      state = 41;
break;
    case 'Z':
      state = 41;
break;
    case '_':
      state = 41;
break;
    case 'a':
      state = 41;
break;
    case 'b':
      state = 41;
break;
    case 'c':
      state = 41;
break;
    case 'd':
      state = 41;
break;
    case 'e':
      state = 41;
break;
    case 'f':
      state = 41;
break;
    case 'g':
      state = 41;
break;
    case 'h':
      state = 41;
break;
    case 'i':
      state = 41;
break;
    case 'j':
      state = 41;
break;
    case 'k':
      state = 41;
break;
    case 'l':
      state = 41;
break;
    case 'm':
      state = 41;
break;
    case 'n':
      state = 41;
break;
    case 'o':
      state = 41;
break;
    case 'p':
      state = 41;
break;
    case 'q':
      state = 41;
break;
    case 'r':
      state = 41;
break;
    case 's':
      state = 41;
break;
    case 't':
      state = 84;
break;
    case 'u':
      state = 41;
break;
    case 'v':
      state = 41;
break;
    case 'w':
      state = 41;
break;
    case 'x':
      state = 41;
break;
    case 'y':
      state = 41;
break;
    case 'z':
      state = 41;
break;
    default:
      fseek(file, -1, SEEK_CUR);
      buffer_index--;
      buffer[buffer_index] = '\0';
Token* token;
NEW_TOKEN(token);
endHandler6(token);
if (strcmp(token->type, "") != 0
   && strcmp(token->type, "SKIP") != 0) {
  strcpy(token->value, buffer);
  tail->next = token;
  tail = token;
} else {
  free(token);
}
buffer[0] = '\0';
buffer_index = 0;
state = 0;
    }
  break;
case 84:
  switch(c) {
    case '0':
      state = 41;
break;
    case '1':
      state = 41;
break;
    case '2':
      state = 41;
break;
    case '3':
      state = 41;
break;
    case '4':
      state = 41;
break;
    case '5':
      state = 41;
break;
    case '6':
      state = 41;
break;
    case '7':
      state = 41;
break;
    case '8':
      state = 41;
break;
    case '9':
      state = 41;
break;
    case 'A':
      state = 41;
break;
    case 'B':
      state = 41;
break;
    case 'C':
      state = 41;
break;
    case 'D':
      state = 41;
break;
    case 'E':
      state = 41;
break;
    case 'F':
      state = 41;
break;
    case 'G':
      state = 41;
break;
    case 'H':
      state = 41;
break;
    case 'I':
      state = 41;
break;
    case 'J':
      state = 41;
break;
    case 'K':
      state = 41;
break;
    case 'L':
      state = 41;
break;
    case 'M':
      state = 41;
break;
    case 'N':
      state = 41;
break;
    case 'O':
      state = 41;
break;
    case 'P':
      state = 41;
break;
    case 'Q':
      state = 41;
break;
    case 'R':
      state = 41;
break;
    case 'S':
      state = 41;
break;
    case 'T':
      state = 41;
break;
    case 'U':
      state = 41;
break;
    case 'V':
      state = 41;
break;
    case 'W':
      state = 41;
break;
    case 'X':
      state = 41;
break;
    case 'Y':
      state = 41;
break;
    case 'Z':
      state = 41;
break;
    case '_':
      state = 41;
break;
    case 'a':
      state = 41;
break;
    case 'b':
      state = 41;
break;
    case 'c':
      state = 85;
break;
    case 'd':
      state = 41;
break;
    case 'e':
      state = 41;
break;
    case 'f':
      state = 41;
break;
    case 'g':
      state = 41;
break;
    case 'h':
      state = 41;
break;
    case 'i':
      state = 41;
break;
    case 'j':
      state = 41;
break;
    case 'k':
      state = 41;
break;
    case 'l':
      state = 41;
break;
    case 'm':
      state = 41;
break;
    case 'n':
      state = 41;
break;
    case 'o':
      state = 41;
break;
    case 'p':
      state = 41;
break;
    case 'q':
      state = 41;
break;
    case 'r':
      state = 41;
break;
    case 's':
      state = 41;
break;
    case 't':
      state = 41;
break;
    case 'u':
      state = 41;
break;
    case 'v':
      state = 41;
break;
    case 'w':
      state = 41;
break;
    case 'x':
      state = 41;
break;
    case 'y':
      state = 41;
break;
    case 'z':
      state = 41;
break;
    default:
      fseek(file, -1, SEEK_CUR);
      buffer_index--;
      buffer[buffer_index] = '\0';
Token* token;
NEW_TOKEN(token);
endHandler6(token);
if (strcmp(token->type, "") != 0
   && strcmp(token->type, "SKIP") != 0) {
  strcpy(token->value, buffer);
  tail->next = token;
  tail = token;
} else {
  free(token);
}
buffer[0] = '\0';
buffer_index = 0;
state = 0;
    }
  break;
case 85:
  switch(c) {
    case '0':
      state = 41;
break;
    case '1':
      state = 41;
break;
    case '2':
      state = 41;
break;
    case '3':
      state = 41;
break;
    case '4':
      state = 41;
break;
    case '5':
      state = 41;
break;
    case '6':
      state = 41;
break;
    case '7':
      state = 41;
break;
    case '8':
      state = 41;
break;
    case '9':
      state = 41;
break;
    case 'A':
      state = 41;
break;
    case 'B':
      state = 41;
break;
    case 'C':
      state = 41;
break;
    case 'D':
      state = 41;
break;
    case 'E':
      state = 41;
break;
    case 'F':
      state = 41;
break;
    case 'G':
      state = 41;
break;
    case 'H':
      state = 41;
break;
    case 'I':
      state = 41;
break;
    case 'J':
      state = 41;
break;
    case 'K':
      state = 41;
break;
    case 'L':
      state = 41;
break;
    case 'M':
      state = 41;
break;
    case 'N':
      state = 41;
break;
    case 'O':
      state = 41;
break;
    case 'P':
      state = 41;
break;
    case 'Q':
      state = 41;
break;
    case 'R':
      state = 41;
break;
    case 'S':
      state = 41;
break;
    case 'T':
      state = 41;
break;
    case 'U':
      state = 41;
break;
    case 'V':
      state = 41;
break;
    case 'W':
      state = 41;
break;
    case 'X':
      state = 41;
break;
    case 'Y':
      state = 41;
break;
    case 'Z':
      state = 41;
break;
    case '_':
      state = 41;
break;
    case 'a':
      state = 41;
break;
    case 'b':
      state = 41;
break;
    case 'c':
      state = 41;
break;
    case 'd':
      state = 41;
break;
    case 'e':
      state = 41;
break;
    case 'f':
      state = 41;
break;
    case 'g':
      state = 41;
break;
    case 'h':
      state = 48;
break;
    case 'i':
      state = 41;
break;
    case 'j':
      state = 41;
break;
    case 'k':
      state = 41;
break;
    case 'l':
      state = 41;
break;
    case 'm':
      state = 41;
break;
    case 'n':
      state = 41;
break;
    case 'o':
      state = 41;
break;
    case 'p':
      state = 41;
break;
    case 'q':
      state = 41;
break;
    case 'r':
      state = 41;
break;
    case 's':
      state = 41;
break;
    case 't':
      state = 41;
break;
    case 'u':
      state = 41;
break;
    case 'v':
      state = 41;
break;
    case 'w':
      state = 41;
break;
    case 'x':
      state = 41;
break;
    case 'y':
      state = 41;
break;
    case 'z':
      state = 41;
break;
    default:
      fseek(file, -1, SEEK_CUR);
      buffer_index--;
      buffer[buffer_index] = '\0';
Token* token;
NEW_TOKEN(token);
endHandler6(token);
if (strcmp(token->type, "") != 0
   && strcmp(token->type, "SKIP") != 0) {
  strcpy(token->value, buffer);
  tail->next = token;
  tail = token;
} else {
  free(token);
}
buffer[0] = '\0';
buffer_index = 0;
state = 0;
    }
  break;
case 86:
  switch(c) {
    case '0':
      state = 41;
break;
    case '1':
      state = 41;
break;
    case '2':
      state = 41;
break;
    case '3':
      state = 41;
break;
    case '4':
      state = 41;
break;
    case '5':
      state = 41;
break;
    case '6':
      state = 41;
break;
    case '7':
      state = 41;
break;
    case '8':
      state = 41;
break;
    case '9':
      state = 41;
break;
    case 'A':
      state = 41;
break;
    case 'B':
      state = 41;
break;
    case 'C':
      state = 41;
break;
    case 'D':
      state = 41;
break;
    case 'E':
      state = 41;
break;
    case 'F':
      state = 41;
break;
    case 'G':
      state = 41;
break;
    case 'H':
      state = 41;
break;
    case 'I':
      state = 41;
break;
    case 'J':
      state = 41;
break;
    case 'K':
      state = 41;
break;
    case 'L':
      state = 41;
break;
    case 'M':
      state = 41;
break;
    case 'N':
      state = 41;
break;
    case 'O':
      state = 41;
break;
    case 'P':
      state = 41;
break;
    case 'Q':
      state = 41;
break;
    case 'R':
      state = 41;
break;
    case 'S':
      state = 41;
break;
    case 'T':
      state = 41;
break;
    case 'U':
      state = 41;
break;
    case 'V':
      state = 41;
break;
    case 'W':
      state = 41;
break;
    case 'X':
      state = 41;
break;
    case 'Y':
      state = 41;
break;
    case 'Z':
      state = 41;
break;
    case '_':
      state = 41;
break;
    case 'a':
      state = 41;
break;
    case 'b':
      state = 41;
break;
    case 'c':
      state = 41;
break;
    case 'd':
      state = 41;
break;
    case 'e':
      state = 41;
break;
    case 'f':
      state = 41;
break;
    case 'g':
      state = 41;
break;
    case 'h':
      state = 41;
break;
    case 'i':
      state = 41;
break;
    case 'j':
      state = 41;
break;
    case 'k':
      state = 41;
break;
    case 'l':
      state = 41;
break;
    case 'm':
      state = 41;
break;
    case 'n':
      state = 41;
break;
    case 'o':
      state = 41;
break;
    case 'p':
      state = 41;
break;
    case 'q':
      state = 41;
break;
    case 'r':
      state = 41;
break;
    case 's':
      state = 41;
break;
    case 't':
      state = 41;
break;
    case 'u':
      state = 41;
break;
    case 'v':
      state = 41;
break;
    case 'w':
      state = 41;
break;
    case 'x':
      state = 41;
break;
    case 'y':
      state = 87;
break;
    case 'z':
      state = 41;
break;
    default:
      fseek(file, -1, SEEK_CUR);
      buffer_index--;
      buffer[buffer_index] = '\0';
Token* token;
NEW_TOKEN(token);
endHandler0(token);
if (strcmp(token->type, "") != 0
   && strcmp(token->type, "SKIP") != 0) {
  strcpy(token->value, buffer);
  tail->next = token;
  tail = token;
} else {
  free(token);
}
buffer[0] = '\0';
buffer_index = 0;
state = 0;
    }
  break;
case 87:
  switch(c) {
    case '0':
      state = 41;
break;
    case '1':
      state = 41;
break;
    case '2':
      state = 41;
break;
    case '3':
      state = 41;
break;
    case '4':
      state = 41;
break;
    case '5':
      state = 41;
break;
    case '6':
      state = 41;
break;
    case '7':
      state = 41;
break;
    case '8':
      state = 41;
break;
    case '9':
      state = 41;
break;
    case 'A':
      state = 41;
break;
    case 'B':
      state = 41;
break;
    case 'C':
      state = 41;
break;
    case 'D':
      state = 41;
break;
    case 'E':
      state = 41;
break;
    case 'F':
      state = 41;
break;
    case 'G':
      state = 41;
break;
    case 'H':
      state = 41;
break;
    case 'I':
      state = 41;
break;
    case 'J':
      state = 41;
break;
    case 'K':
      state = 41;
break;
    case 'L':
      state = 41;
break;
    case 'M':
      state = 41;
break;
    case 'N':
      state = 41;
break;
    case 'O':
      state = 41;
break;
    case 'P':
      state = 41;
break;
    case 'Q':
      state = 41;
break;
    case 'R':
      state = 41;
break;
    case 'S':
      state = 41;
break;
    case 'T':
      state = 41;
break;
    case 'U':
      state = 41;
break;
    case 'V':
      state = 41;
break;
    case 'W':
      state = 41;
break;
    case 'X':
      state = 41;
break;
    case 'Y':
      state = 41;
break;
    case 'Z':
      state = 41;
break;
    case '_':
      state = 41;
break;
    case 'a':
      state = 41;
break;
    case 'b':
      state = 41;
break;
    case 'c':
      state = 41;
break;
    case 'd':
      state = 41;
break;
    case 'e':
      state = 41;
break;
    case 'f':
      state = 41;
break;
    case 'g':
      state = 41;
break;
    case 'h':
      state = 41;
break;
    case 'i':
      state = 41;
break;
    case 'j':
      state = 41;
break;
    case 'k':
      state = 41;
break;
    case 'l':
      state = 41;
break;
    case 'm':
      state = 41;
break;
    case 'n':
      state = 41;
break;
    case 'o':
      state = 41;
break;
    case 'p':
      state = 88;
break;
    case 'q':
      state = 41;
break;
    case 'r':
      state = 41;
break;
    case 's':
      state = 41;
break;
    case 't':
      state = 41;
break;
    case 'u':
      state = 41;
break;
    case 'v':
      state = 41;
break;
    case 'w':
      state = 41;
break;
    case 'x':
      state = 41;
break;
    case 'y':
      state = 41;
break;
    case 'z':
      state = 41;
break;
    default:
      fseek(file, -1, SEEK_CUR);
      buffer_index--;
      buffer[buffer_index] = '\0';
Token* token;
NEW_TOKEN(token);
endHandler6(token);
if (strcmp(token->type, "") != 0
   && strcmp(token->type, "SKIP") != 0) {
  strcpy(token->value, buffer);
  tail->next = token;
  tail = token;
} else {
  free(token);
}
buffer[0] = '\0';
buffer_index = 0;
state = 0;
    }
  break;
case 88:
  switch(c) {
    case '0':
      state = 41;
break;
    case '1':
      state = 41;
break;
    case '2':
      state = 41;
break;
    case '3':
      state = 41;
break;
    case '4':
      state = 41;
break;
    case '5':
      state = 41;
break;
    case '6':
      state = 41;
break;
    case '7':
      state = 41;
break;
    case '8':
      state = 41;
break;
    case '9':
      state = 41;
break;
    case 'A':
      state = 41;
break;
    case 'B':
      state = 41;
break;
    case 'C':
      state = 41;
break;
    case 'D':
      state = 41;
break;
    case 'E':
      state = 41;
break;
    case 'F':
      state = 41;
break;
    case 'G':
      state = 41;
break;
    case 'H':
      state = 41;
break;
    case 'I':
      state = 41;
break;
    case 'J':
      state = 41;
break;
    case 'K':
      state = 41;
break;
    case 'L':
      state = 41;
break;
    case 'M':
      state = 41;
break;
    case 'N':
      state = 41;
break;
    case 'O':
      state = 41;
break;
    case 'P':
      state = 41;
break;
    case 'Q':
      state = 41;
break;
    case 'R':
      state = 41;
break;
    case 'S':
      state = 41;
break;
    case 'T':
      state = 41;
break;
    case 'U':
      state = 41;
break;
    case 'V':
      state = 41;
break;
    case 'W':
      state = 41;
break;
    case 'X':
      state = 41;
break;
    case 'Y':
      state = 41;
break;
    case 'Z':
      state = 41;
break;
    case '_':
      state = 41;
break;
    case 'a':
      state = 41;
break;
    case 'b':
      state = 41;
break;
    case 'c':
      state = 41;
break;
    case 'd':
      state = 41;
break;
    case 'e':
      state = 89;
break;
    case 'f':
      state = 41;
break;
    case 'g':
      state = 41;
break;
    case 'h':
      state = 41;
break;
    case 'i':
      state = 41;
break;
    case 'j':
      state = 41;
break;
    case 'k':
      state = 41;
break;
    case 'l':
      state = 41;
break;
    case 'm':
      state = 41;
break;
    case 'n':
      state = 41;
break;
    case 'o':
      state = 41;
break;
    case 'p':
      state = 41;
break;
    case 'q':
      state = 41;
break;
    case 'r':
      state = 41;
break;
    case 's':
      state = 41;
break;
    case 't':
      state = 41;
break;
    case 'u':
      state = 41;
break;
    case 'v':
      state = 41;
break;
    case 'w':
      state = 41;
break;
    case 'x':
      state = 41;
break;
    case 'y':
      state = 41;
break;
    case 'z':
      state = 41;
break;
    default:
      fseek(file, -1, SEEK_CUR);
      buffer_index--;
      buffer[buffer_index] = '\0';
Token* token;
NEW_TOKEN(token);
endHandler6(token);
if (strcmp(token->type, "") != 0
   && strcmp(token->type, "SKIP") != 0) {
  strcpy(token->value, buffer);
  tail->next = token;
  tail = token;
} else {
  free(token);
}
buffer[0] = '\0';
buffer_index = 0;
state = 0;
    }
  break;
case 89:
  switch(c) {
    case '0':
      state = 41;
break;
    case '1':
      state = 41;
break;
    case '2':
      state = 41;
break;
    case '3':
      state = 41;
break;
    case '4':
      state = 41;
break;
    case '5':
      state = 41;
break;
    case '6':
      state = 41;
break;
    case '7':
      state = 41;
break;
    case '8':
      state = 41;
break;
    case '9':
      state = 41;
break;
    case 'A':
      state = 41;
break;
    case 'B':
      state = 41;
break;
    case 'C':
      state = 41;
break;
    case 'D':
      state = 41;
break;
    case 'E':
      state = 41;
break;
    case 'F':
      state = 41;
break;
    case 'G':
      state = 41;
break;
    case 'H':
      state = 41;
break;
    case 'I':
      state = 41;
break;
    case 'J':
      state = 41;
break;
    case 'K':
      state = 41;
break;
    case 'L':
      state = 41;
break;
    case 'M':
      state = 41;
break;
    case 'N':
      state = 41;
break;
    case 'O':
      state = 41;
break;
    case 'P':
      state = 41;
break;
    case 'Q':
      state = 41;
break;
    case 'R':
      state = 41;
break;
    case 'S':
      state = 41;
break;
    case 'T':
      state = 41;
break;
    case 'U':
      state = 41;
break;
    case 'V':
      state = 41;
break;
    case 'W':
      state = 41;
break;
    case 'X':
      state = 41;
break;
    case 'Y':
      state = 41;
break;
    case 'Z':
      state = 41;
break;
    case '_':
      state = 41;
break;
    case 'a':
      state = 41;
break;
    case 'b':
      state = 41;
break;
    case 'c':
      state = 41;
break;
    case 'd':
      state = 90;
break;
    case 'e':
      state = 41;
break;
    case 'f':
      state = 41;
break;
    case 'g':
      state = 41;
break;
    case 'h':
      state = 41;
break;
    case 'i':
      state = 41;
break;
    case 'j':
      state = 41;
break;
    case 'k':
      state = 41;
break;
    case 'l':
      state = 41;
break;
    case 'm':
      state = 41;
break;
    case 'n':
      state = 41;
break;
    case 'o':
      state = 41;
break;
    case 'p':
      state = 41;
break;
    case 'q':
      state = 41;
break;
    case 'r':
      state = 41;
break;
    case 's':
      state = 41;
break;
    case 't':
      state = 41;
break;
    case 'u':
      state = 41;
break;
    case 'v':
      state = 41;
break;
    case 'w':
      state = 41;
break;
    case 'x':
      state = 41;
break;
    case 'y':
      state = 41;
break;
    case 'z':
      state = 41;
break;
    default:
      fseek(file, -1, SEEK_CUR);
      buffer_index--;
      buffer[buffer_index] = '\0';
Token* token;
NEW_TOKEN(token);
endHandler6(token);
if (strcmp(token->type, "") != 0
   && strcmp(token->type, "SKIP") != 0) {
  strcpy(token->value, buffer);
  tail->next = token;
  tail = token;
} else {
  free(token);
}
buffer[0] = '\0';
buffer_index = 0;
state = 0;
    }
  break;
case 90:
  switch(c) {
    case '0':
      state = 41;
break;
    case '1':
      state = 41;
break;
    case '2':
      state = 41;
break;
    case '3':
      state = 41;
break;
    case '4':
      state = 41;
break;
    case '5':
      state = 41;
break;
    case '6':
      state = 41;
break;
    case '7':
      state = 41;
break;
    case '8':
      state = 41;
break;
    case '9':
      state = 41;
break;
    case 'A':
      state = 41;
break;
    case 'B':
      state = 41;
break;
    case 'C':
      state = 41;
break;
    case 'D':
      state = 41;
break;
    case 'E':
      state = 41;
break;
    case 'F':
      state = 41;
break;
    case 'G':
      state = 41;
break;
    case 'H':
      state = 41;
break;
    case 'I':
      state = 41;
break;
    case 'J':
      state = 41;
break;
    case 'K':
      state = 41;
break;
    case 'L':
      state = 41;
break;
    case 'M':
      state = 41;
break;
    case 'N':
      state = 41;
break;
    case 'O':
      state = 41;
break;
    case 'P':
      state = 41;
break;
    case 'Q':
      state = 41;
break;
    case 'R':
      state = 41;
break;
    case 'S':
      state = 41;
break;
    case 'T':
      state = 41;
break;
    case 'U':
      state = 41;
break;
    case 'V':
      state = 41;
break;
    case 'W':
      state = 41;
break;
    case 'X':
      state = 41;
break;
    case 'Y':
      state = 41;
break;
    case 'Z':
      state = 41;
break;
    case '_':
      state = 41;
break;
    case 'a':
      state = 41;
break;
    case 'b':
      state = 41;
break;
    case 'c':
      state = 41;
break;
    case 'd':
      state = 41;
break;
    case 'e':
      state = 91;
break;
    case 'f':
      state = 41;
break;
    case 'g':
      state = 41;
break;
    case 'h':
      state = 41;
break;
    case 'i':
      state = 41;
break;
    case 'j':
      state = 41;
break;
    case 'k':
      state = 41;
break;
    case 'l':
      state = 41;
break;
    case 'm':
      state = 41;
break;
    case 'n':
      state = 41;
break;
    case 'o':
      state = 41;
break;
    case 'p':
      state = 41;
break;
    case 'q':
      state = 41;
break;
    case 'r':
      state = 41;
break;
    case 's':
      state = 41;
break;
    case 't':
      state = 41;
break;
    case 'u':
      state = 41;
break;
    case 'v':
      state = 41;
break;
    case 'w':
      state = 41;
break;
    case 'x':
      state = 41;
break;
    case 'y':
      state = 41;
break;
    case 'z':
      state = 41;
break;
    default:
      fseek(file, -1, SEEK_CUR);
      buffer_index--;
      buffer[buffer_index] = '\0';
Token* token;
NEW_TOKEN(token);
endHandler6(token);
if (strcmp(token->type, "") != 0
   && strcmp(token->type, "SKIP") != 0) {
  strcpy(token->value, buffer);
  tail->next = token;
  tail = token;
} else {
  free(token);
}
buffer[0] = '\0';
buffer_index = 0;
state = 0;
    }
  break;
case 91:
  switch(c) {
    case '0':
      state = 41;
break;
    case '1':
      state = 41;
break;
    case '2':
      state = 41;
break;
    case '3':
      state = 41;
break;
    case '4':
      state = 41;
break;
    case '5':
      state = 41;
break;
    case '6':
      state = 41;
break;
    case '7':
      state = 41;
break;
    case '8':
      state = 41;
break;
    case '9':
      state = 41;
break;
    case 'A':
      state = 41;
break;
    case 'B':
      state = 41;
break;
    case 'C':
      state = 41;
break;
    case 'D':
      state = 41;
break;
    case 'E':
      state = 41;
break;
    case 'F':
      state = 41;
break;
    case 'G':
      state = 41;
break;
    case 'H':
      state = 41;
break;
    case 'I':
      state = 41;
break;
    case 'J':
      state = 41;
break;
    case 'K':
      state = 41;
break;
    case 'L':
      state = 41;
break;
    case 'M':
      state = 41;
break;
    case 'N':
      state = 41;
break;
    case 'O':
      state = 41;
break;
    case 'P':
      state = 41;
break;
    case 'Q':
      state = 41;
break;
    case 'R':
      state = 41;
break;
    case 'S':
      state = 41;
break;
    case 'T':
      state = 41;
break;
    case 'U':
      state = 41;
break;
    case 'V':
      state = 41;
break;
    case 'W':
      state = 41;
break;
    case 'X':
      state = 41;
break;
    case 'Y':
      state = 41;
break;
    case 'Z':
      state = 41;
break;
    case '_':
      state = 41;
break;
    case 'a':
      state = 41;
break;
    case 'b':
      state = 41;
break;
    case 'c':
      state = 41;
break;
    case 'd':
      state = 41;
break;
    case 'e':
      state = 41;
break;
    case 'f':
      state = 48;
break;
    case 'g':
      state = 41;
break;
    case 'h':
      state = 41;
break;
    case 'i':
      state = 41;
break;
    case 'j':
      state = 41;
break;
    case 'k':
      state = 41;
break;
    case 'l':
      state = 41;
break;
    case 'm':
      state = 41;
break;
    case 'n':
      state = 41;
break;
    case 'o':
      state = 41;
break;
    case 'p':
      state = 41;
break;
    case 'q':
      state = 41;
break;
    case 'r':
      state = 41;
break;
    case 's':
      state = 41;
break;
    case 't':
      state = 41;
break;
    case 'u':
      state = 41;
break;
    case 'v':
      state = 41;
break;
    case 'w':
      state = 41;
break;
    case 'x':
      state = 41;
break;
    case 'y':
      state = 41;
break;
    case 'z':
      state = 41;
break;
    default:
      fseek(file, -1, SEEK_CUR);
      buffer_index--;
      buffer[buffer_index] = '\0';
Token* token;
NEW_TOKEN(token);
endHandler6(token);
if (strcmp(token->type, "") != 0
   && strcmp(token->type, "SKIP") != 0) {
  strcpy(token->value, buffer);
  tail->next = token;
  tail = token;
} else {
  free(token);
}
buffer[0] = '\0';
buffer_index = 0;
state = 0;
    }
  break;
case 92:
  switch(c) {
    case '0':
      state = 41;
break;
    case '1':
      state = 41;
break;
    case '2':
      state = 41;
break;
    case '3':
      state = 41;
break;
    case '4':
      state = 41;
break;
    case '5':
      state = 41;
break;
    case '6':
      state = 41;
break;
    case '7':
      state = 41;
break;
    case '8':
      state = 41;
break;
    case '9':
      state = 41;
break;
    case 'A':
      state = 41;
break;
    case 'B':
      state = 41;
break;
    case 'C':
      state = 41;
break;
    case 'D':
      state = 41;
break;
    case 'E':
      state = 41;
break;
    case 'F':
      state = 41;
break;
    case 'G':
      state = 41;
break;
    case 'H':
      state = 41;
break;
    case 'I':
      state = 41;
break;
    case 'J':
      state = 41;
break;
    case 'K':
      state = 41;
break;
    case 'L':
      state = 41;
break;
    case 'M':
      state = 41;
break;
    case 'N':
      state = 41;
break;
    case 'O':
      state = 41;
break;
    case 'P':
      state = 41;
break;
    case 'Q':
      state = 41;
break;
    case 'R':
      state = 41;
break;
    case 'S':
      state = 41;
break;
    case 'T':
      state = 41;
break;
    case 'U':
      state = 41;
break;
    case 'V':
      state = 41;
break;
    case 'W':
      state = 41;
break;
    case 'X':
      state = 41;
break;
    case 'Y':
      state = 41;
break;
    case 'Z':
      state = 41;
break;
    case '_':
      state = 41;
break;
    case 'a':
      state = 41;
break;
    case 'b':
      state = 41;
break;
    case 'c':
      state = 41;
break;
    case 'd':
      state = 41;
break;
    case 'e':
      state = 41;
break;
    case 'f':
      state = 41;
break;
    case 'g':
      state = 41;
break;
    case 'h':
      state = 93;
break;
    case 'i':
      state = 41;
break;
    case 'j':
      state = 41;
break;
    case 'k':
      state = 41;
break;
    case 'l':
      state = 41;
break;
    case 'm':
      state = 41;
break;
    case 'n':
      state = 41;
break;
    case 'o':
      state = 41;
break;
    case 'p':
      state = 41;
break;
    case 'q':
      state = 41;
break;
    case 'r':
      state = 41;
break;
    case 's':
      state = 41;
break;
    case 't':
      state = 41;
break;
    case 'u':
      state = 41;
break;
    case 'v':
      state = 41;
break;
    case 'w':
      state = 41;
break;
    case 'x':
      state = 41;
break;
    case 'y':
      state = 41;
break;
    case 'z':
      state = 41;
break;
    default:
      fseek(file, -1, SEEK_CUR);
      buffer_index--;
      buffer[buffer_index] = '\0';
Token* token;
NEW_TOKEN(token);
endHandler6(token);
if (strcmp(token->type, "") != 0
   && strcmp(token->type, "SKIP") != 0) {
  strcpy(token->value, buffer);
  tail->next = token;
  tail = token;
} else {
  free(token);
}
buffer[0] = '\0';
buffer_index = 0;
state = 0;
    }
  break;
case 93:
  switch(c) {
    case '0':
      state = 41;
break;
    case '1':
      state = 41;
break;
    case '2':
      state = 41;
break;
    case '3':
      state = 41;
break;
    case '4':
      state = 41;
break;
    case '5':
      state = 41;
break;
    case '6':
      state = 41;
break;
    case '7':
      state = 41;
break;
    case '8':
      state = 41;
break;
    case '9':
      state = 41;
break;
    case 'A':
      state = 41;
break;
    case 'B':
      state = 41;
break;
    case 'C':
      state = 41;
break;
    case 'D':
      state = 41;
break;
    case 'E':
      state = 41;
break;
    case 'F':
      state = 41;
break;
    case 'G':
      state = 41;
break;
    case 'H':
      state = 41;
break;
    case 'I':
      state = 41;
break;
    case 'J':
      state = 41;
break;
    case 'K':
      state = 41;
break;
    case 'L':
      state = 41;
break;
    case 'M':
      state = 41;
break;
    case 'N':
      state = 41;
break;
    case 'O':
      state = 41;
break;
    case 'P':
      state = 41;
break;
    case 'Q':
      state = 41;
break;
    case 'R':
      state = 41;
break;
    case 'S':
      state = 41;
break;
    case 'T':
      state = 41;
break;
    case 'U':
      state = 41;
break;
    case 'V':
      state = 41;
break;
    case 'W':
      state = 41;
break;
    case 'X':
      state = 41;
break;
    case 'Y':
      state = 41;
break;
    case 'Z':
      state = 41;
break;
    case '_':
      state = 41;
break;
    case 'a':
      state = 41;
break;
    case 'b':
      state = 41;
break;
    case 'c':
      state = 41;
break;
    case 'd':
      state = 41;
break;
    case 'e':
      state = 41;
break;
    case 'f':
      state = 41;
break;
    case 'g':
      state = 41;
break;
    case 'h':
      state = 41;
break;
    case 'i':
      state = 94;
break;
    case 'j':
      state = 41;
break;
    case 'k':
      state = 41;
break;
    case 'l':
      state = 41;
break;
    case 'm':
      state = 41;
break;
    case 'n':
      state = 41;
break;
    case 'o':
      state = 41;
break;
    case 'p':
      state = 41;
break;
    case 'q':
      state = 41;
break;
    case 'r':
      state = 41;
break;
    case 's':
      state = 41;
break;
    case 't':
      state = 41;
break;
    case 'u':
      state = 41;
break;
    case 'v':
      state = 41;
break;
    case 'w':
      state = 41;
break;
    case 'x':
      state = 41;
break;
    case 'y':
      state = 41;
break;
    case 'z':
      state = 41;
break;
    default:
      fseek(file, -1, SEEK_CUR);
      buffer_index--;
      buffer[buffer_index] = '\0';
Token* token;
NEW_TOKEN(token);
endHandler6(token);
if (strcmp(token->type, "") != 0
   && strcmp(token->type, "SKIP") != 0) {
  strcpy(token->value, buffer);
  tail->next = token;
  tail = token;
} else {
  free(token);
}
buffer[0] = '\0';
buffer_index = 0;
state = 0;
    }
  break;
case 94:
  switch(c) {
    case '0':
      state = 41;
break;
    case '1':
      state = 41;
break;
    case '2':
      state = 41;
break;
    case '3':
      state = 41;
break;
    case '4':
      state = 41;
break;
    case '5':
      state = 41;
break;
    case '6':
      state = 41;
break;
    case '7':
      state = 41;
break;
    case '8':
      state = 41;
break;
    case '9':
      state = 41;
break;
    case 'A':
      state = 41;
break;
    case 'B':
      state = 41;
break;
    case 'C':
      state = 41;
break;
    case 'D':
      state = 41;
break;
    case 'E':
      state = 41;
break;
    case 'F':
      state = 41;
break;
    case 'G':
      state = 41;
break;
    case 'H':
      state = 41;
break;
    case 'I':
      state = 41;
break;
    case 'J':
      state = 41;
break;
    case 'K':
      state = 41;
break;
    case 'L':
      state = 41;
break;
    case 'M':
      state = 41;
break;
    case 'N':
      state = 41;
break;
    case 'O':
      state = 41;
break;
    case 'P':
      state = 41;
break;
    case 'Q':
      state = 41;
break;
    case 'R':
      state = 41;
break;
    case 'S':
      state = 41;
break;
    case 'T':
      state = 41;
break;
    case 'U':
      state = 41;
break;
    case 'V':
      state = 41;
break;
    case 'W':
      state = 41;
break;
    case 'X':
      state = 41;
break;
    case 'Y':
      state = 41;
break;
    case 'Z':
      state = 41;
break;
    case '_':
      state = 41;
break;
    case 'a':
      state = 41;
break;
    case 'b':
      state = 41;
break;
    case 'c':
      state = 41;
break;
    case 'd':
      state = 41;
break;
    case 'e':
      state = 41;
break;
    case 'f':
      state = 41;
break;
    case 'g':
      state = 41;
break;
    case 'h':
      state = 41;
break;
    case 'i':
      state = 41;
break;
    case 'j':
      state = 41;
break;
    case 'k':
      state = 41;
break;
    case 'l':
      state = 51;
break;
    case 'm':
      state = 41;
break;
    case 'n':
      state = 41;
break;
    case 'o':
      state = 41;
break;
    case 'p':
      state = 41;
break;
    case 'q':
      state = 41;
break;
    case 'r':
      state = 41;
break;
    case 's':
      state = 41;
break;
    case 't':
      state = 41;
break;
    case 'u':
      state = 41;
break;
    case 'v':
      state = 41;
break;
    case 'w':
      state = 41;
break;
    case 'x':
      state = 41;
break;
    case 'y':
      state = 41;
break;
    case 'z':
      state = 41;
break;
    default:
      fseek(file, -1, SEEK_CUR);
      buffer_index--;
      buffer[buffer_index] = '\0';
Token* token;
NEW_TOKEN(token);
endHandler6(token);
if (strcmp(token->type, "") != 0
   && strcmp(token->type, "SKIP") != 0) {
  strcpy(token->value, buffer);
  tail->next = token;
  tail = token;
} else {
  free(token);
}
buffer[0] = '\0';
buffer_index = 0;
state = 0;
    }
  break;
case 95:
  switch(c) {
    default:
      fseek(file, -1, SEEK_CUR);
      buffer_index--;
      buffer[buffer_index] = '\0';
Token* token;
NEW_TOKEN(token);
endHandler24(token);
if (strcmp(token->type, "") != 0
   && strcmp(token->type, "SKIP") != 0) {
  strcpy(token->value, buffer);
  tail->next = token;
  tail = token;
} else {
  free(token);
}
buffer[0] = '\0';
buffer_index = 0;
state = 0;
    }
  break;
case 96:
  switch(c) {
    case '&':
      state = 3;
break;
    case '|':
      state = 3;
break;
    default:
      fseek(file, -1, SEEK_CUR);
      buffer_index--;
      buffer[buffer_index] = '\0';
Token* token;
NEW_TOKEN(token);
endHandler10(token);
if (strcmp(token->type, "") != 0
   && strcmp(token->type, "SKIP") != 0) {
  strcpy(token->value, buffer);
  tail->next = token;
  tail = token;
} else {
  free(token);
}
buffer[0] = '\0';
buffer_index = 0;
state = 0;
    }
  break;
case 97:
  switch(c) {
    default:
      fseek(file, -1, SEEK_CUR);
      buffer_index--;
      buffer[buffer_index] = '\0';
Token* token;
NEW_TOKEN(token);
endHandler23(token);
if (strcmp(token->type, "") != 0
   && strcmp(token->type, "SKIP") != 0) {
  strcpy(token->value, buffer);
  tail->next = token;
  tail = token;
} else {
  free(token);
}
buffer[0] = '\0';
buffer_index = 0;
state = 0;
    }
  break;
  }
}
}
void print_token(Token* token) {
  printf("('%s', '%s')\n", token->type, token->value);
}
void free_tokens() {
  Token* iter;
  INIT_ITER(iter);
  while(!ITER_ISEND(iter)) {
    Token* tmp = iter;
    ITER_NEXT(iter);
    free(tmp);
  }
}
void yylex(char* input, void (*func)()) {
  FILE* infile;
  infile = fopen(input, "r");
  parse(infile);
  fclose(infile);
  func();
  free_tokens();
}
void iter_list(void (*trav_func)(Token*)) {
  Token* iter;
  INIT_ITER(iter);
  while (!ITER_ISEND(iter)) {
    trav_func(iter);
    ITER_NEXT(iter);
  }
}
void print() {
  iter_list(print_token);
  printf("line number: %d", i);
}
int main(int argc, char** argv) {
  yylex(argv[1], print);
  return 0;
}



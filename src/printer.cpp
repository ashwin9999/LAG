//
// Created by Ashwin Mishra on 2019-03-20.
//

#include "lag.h"
#include <stdarg.h>

void printCode(ostream& os, ...) {
    va_list ap;
    const char* s;
    va_start(ap, os);
    while (strcmp("", s = va_arg(ap, char*)) != 0) {
        os << s << endl;
    }
    va_end(ap);
}

void fgetline(istream& is, char* buffer, int size) {
    do {
        is.getline(buffer, size);
    } while (strcmp(buffer, "") == 0 && !is.eof());
}

#include "calculator.h"

int TypeOfOperation(char sign) {
    if (sign == '+') return 2;
    if (sign == '-') return -2;
    if (sign == '*') return 3;
    if (sign == '/') return -3;
    if (sign == '^') return 4;
    if (sign == '(') return 1;
    if (sign == ')') return -1;
    else return 0;
}

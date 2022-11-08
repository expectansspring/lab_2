#include "calculator.h"
#include <cmath>

double PerformingOperation(double number_1, double number_2, int type_of_operation) {
    if (type_of_operation == 2) return number_1 + number_2;
    if (type_of_operation == -2) return number_1 - number_2;
    if (type_of_operation == 3) return number_1 * number_2;
    if (type_of_operation == -3) return number_1 / number_2;
    if (type_of_operation == 4) return pow(number_1, number_2);
    else return 0;
}
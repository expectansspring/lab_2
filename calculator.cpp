#include <iostream>
#include <cstring>
#include <fstream>
#include "calculator.h"

using std::cout;
using std::cin;
using std::endl;

int main(int argc, char *argv[]) {
    int i = 0, j = 0, n = 50;
    double *numbers = new double[n], value, res;
    char *signs = new char[n], arg = ' ', end = ' ';
    bool first_flag = true;
    if (argc == 2 && (strcmp(argv[1], "--forward") == 0 || strcmp(argv[1], "--reverse") == 0)) {
        end = '\n';
        while (arg != end) {
            arg = cin.peek();
            if (arg == ' ') {
                cin.ignore();
                continue;
            }
            if (arg >= '0' && arg <= '9') {
                cin >> value;
                numbers[i] = value;
                i += 1;
                continue;
            }
            if (arg == '+' || arg == '-' || arg == '*' || arg == '/' || arg == '(' || arg == ')' || arg == '^') {
                if (j == 0 || (abs(TypeOfOperation(arg)) > abs(TypeOfOperation(signs[j - 1]))) ||
                    TypeOfOperation(arg) == 1) {
                    if ((j == 0 || j > 0 && TypeOfOperation(arg) == -2 && TypeOfOperation(signs[j - 1]) == 1) &&
                        TypeOfOperation(arg) == -2 && strcmp(argv[1], "--forward") == 0) {
                        numbers[i] = 0;
                        i += 1;
                        signs[j] = arg;
                        j += 1;
                    } else {
                        signs[j] = arg;
                        j += 1;
                    }
                    cin.ignore();
                } else {
                    if (TypeOfOperation(arg) == -1) {
                        while (abs(TypeOfOperation(arg)) != abs(TypeOfOperation(signs[j - 1]))) {
                            res = PerformingOperation(numbers[i - 2], numbers[i - 1], TypeOfOperation(signs[j - 1]));
                            numbers[i - 2] = res; // i - 2
                            j -= 1;
                            i -= 1;
                        }
                        j -= 1;
                        cin.ignore();
                    } else {
                        while (first_flag && abs(TypeOfOperation(arg)) <= abs(TypeOfOperation(signs[j - 1]))) {
                            res = PerformingOperation(numbers[i - 2], numbers[i - 1], TypeOfOperation(signs[j - 1]));
                            numbers[i - 2] = res; // i - 2
                            j -= 1;
                            i -= 1;
                            if (j == 0) {
                                signs[j] = arg;
                                j += 1;
                                cin.ignore();
                                first_flag = false;
                            }
                        }
                    }

                }
                continue;
            }
        }

        if (j == 0) {
            cout << numbers[0] << endl;
        } else {
            j -= 1;
            i -= 1;
            while (j != -1) {
                res = PerformingOperation(numbers[i - 1], numbers[i], TypeOfOperation(signs[j]));
                numbers[i - 1] = res;
                j -= 1;
                i -= 1;
            }
            cout << numbers[0] << endl;
        }
    } else if (argc >= 2 && strcmp("--file", argv[2]) == 0) {
        std::ifstream input(argv[3]);
        cin.rdbuf(input.rdbuf());
        end = EOF;
        while (arg != end) {
            arg = cin.peek();
            if (arg == ' ') {
                cin.ignore();
                continue;
            }
            if (arg >= '0' && arg <= '9') {
                cin >> value;
                numbers[i] = value;
                i += 1;
                continue;
            }
            if (arg == '+' || arg == '-' || arg == '*' || arg == '/' || arg == '(' || arg == ')' || arg == '^') {
                if (j == 0 || (abs(TypeOfOperation(arg)) > abs(TypeOfOperation(signs[j - 1]))) ||
                    TypeOfOperation(arg) == 1) {
                    if ((j == 0 || j > 0 && TypeOfOperation(arg) == -2 && TypeOfOperation(signs[j - 1]) == 1) &&
                        TypeOfOperation(arg) == -2 &&
                        strcmp(argv[1], "--forward") == 0) {
                        numbers[i] = 0;
                        i += 1;
                        signs[j] = arg;
                        j += 1;
                    } else {
                        signs[j] = arg;
                        j += 1;
                    }
                    cin.ignore();
                } else {
                    if (TypeOfOperation(arg) == -1) {
                        while (abs(TypeOfOperation(arg)) != abs(TypeOfOperation(signs[j - 1]))) {
                            res = PerformingOperation(numbers[i - 2], numbers[i - 1], TypeOfOperation(signs[j - 1]));
                            numbers[i - 2] = res; // i - 2
                            j -= 1;
                            i -= 1;
                        }
                        j -= 1;
                        cin.ignore();
                    } else {
                        while (first_flag && abs(TypeOfOperation(arg)) <= abs(TypeOfOperation(signs[j - 1]))) {
                            res = PerformingOperation(numbers[i - 2], numbers[i - 1], TypeOfOperation(signs[j - 1]));
                            numbers[i - 2] = res; // i - 2
                            j -= 1;
                            i -= 1;
                            if (j == 0) {
                                signs[j] = arg;
                                j += 1;
                                cin.ignore();
                                first_flag = false;
                            }
                        }
                    }

                }
                continue;
            }
        }

        if (j == 0) {
            cout << numbers[0] << endl;
        } else {
            j -= 1;
            i -= 1;
            while (j != -1) {
                res = PerformingOperation(numbers[i - 1], numbers[i], TypeOfOperation(signs[j]));
                numbers[i - 1] = res;
                j -= 1;
                i -= 1;
            }
            cout << numbers[0] << endl;
        }
        input.close();
    }
    delete[] numbers;
    delete[] signs;
}
/*
* Math Functions Implementation
* @author Krish Galani
* @file math.c
* 26/9/2021
*/

#include "math.h"

double add (double lhs, double rhs){
    return lhs+rhs;
}
double subtract(double lhs, double rhs){
    return lhs-rhs;
}
double multiply(double lhs, double rhs){
    return lhs*rhs;
}
double divide(double num, double denom){
    return num/denom;
}
double power (double left, double right) {
    if (right == 0) {
        return 1;
    }
    else {
        return left * power(left, right - 1);
    }
}

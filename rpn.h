/* RPN Header File
 * @author Krish Galani
 * @file rpn.h
 * 22/11/2021
 */
#ifndef FUNCTIONS_RPN_H
#include "stack.h"
#include "math.h"
#define FUNCTIONS_RPN_H
double evaluate(char*,int*);
void infixToPostfix(char*,char*,int*);
#endif

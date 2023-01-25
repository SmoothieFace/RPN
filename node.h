/*
 *  Node Header File 
 *  @author Krish Galani
 *  @file node.h 
 *  22/11/2021
 * 
 */
#ifndef FUNCTIONS_NODE_H 
#include "errors.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#define FUNCTIONS_NODE_H 
enum type {opType,numType,openPType, closedPType};
enum associativity {left,right};
typedef struct node {
    union {
        double value;
        char op;
    } contents;
    int type;
    int precedence;
    struct node* next;
} n;
n* createNumberNode(double, int);
n* createOperatorNode(char, int);
#endif

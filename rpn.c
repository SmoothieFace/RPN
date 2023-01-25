/* RPN Implementation File
 * @author Krish Galanni
 * @file rpn.c
 * 22/11/2021
 */
#include "rpn.h"
//Adapted from Perry Donham rpn.c 
double evaluate (char* expression, int* status) {
    //start with an empty stack
    clear();

    if (expression == NULL) {
        *status = SUCCESS;
        return 0.0;
    }

    char operatorsString[] = "+-*/^";

    //get the first token
    char* token = strtok(expression, " ");

    //if the first token is an operator, we don't have enough operands
    if (strstr(operatorsString, token)) {
        *status = MALFORMAT;
        return 0.0;
    }

    else {
        n* numNode = createNumberNode(atof(token), numType);
        push(numNode);
    }

    while (token != NULL) {

        if (strstr(operatorsString, token)) {
            n* opNode = createOperatorNode((double) *token,opType);
            //pop and store the first two values on stack
            n* firstOperand = pop();
            n* secondOperand = pop();
            //if the first pop returned a null value, we had too few operands in the stack
            if (firstOperand == NULL) {
                *status = ERRNULLPTR;
                return 0.0;
            }
            double numResult;

            switch(*token) {
                case '+':
                    numResult = add(firstOperand->contents.value, secondOperand->contents.value);
                    break;
                case '-':
                    numResult = subtract(secondOperand->contents.value,firstOperand->contents.value);
                    break;
                case '*':
                    numResult = multiply(firstOperand->contents.value,secondOperand->contents.value);
                    break;
                case '/':
                    //divide by zero error
                    if (secondOperand->contents.value == 0) {
                        *status = ERRDIVZERO;
                        return 0.0;
                    }
                    numResult = divide(firstOperand->contents.value,secondOperand->contents.value);
                    break;
                case '^':
                    numResult = power(secondOperand->contents.value, firstOperand->contents.value);
                    break;
            }
            //create a node that stores the result of the operation and push it to the stack
            n* result = createNumberNode(numResult, numType);
            push(result);

            //free the pointers of the values we popped
            free(firstOperand);
            free(secondOperand);
        }

            //if token is a number, push it to the stack
        else {
            n* numNode = createNumberNode(atof(token),numType);
            push(numNode);
        }

        token = strtok(NULL, " ");
    
   }
	if (peek()->next || !peek() || !(peek()->type == numType) ) { //peek()->next is non-null if there is more than one node remaining
		*status = ERRNULLPTR;                // and peek() is NULL if the stack is empty
		return 0;
	} else {
		*status = SUCCESS;
		return pop()->contents.value;
	}
}
void infixToPostfix(char* src,char* dest,int* status){

    return;
}

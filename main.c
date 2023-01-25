/* Driver File
 * @author Krish Galani 
 * @file main.c
 * 13/11/2021
 * */
#include "rpn.h"
#define MAX_LENGTH 100
//Adapted from Perry's Example
int main(int argc, char* argv[]) {
    int status;
    char inputExpression[MAX_LENGTH] = {0};
    char postfix[MAX_LENGTH] = {0};
    double result;
    //Open files specified on command line (input, output)
    FILE *inputFile = fopen(argv[1], "r");
    FILE *outputFile = fopen(argv[2], "w"); 
    //Error checking file
    if(inputFile == NULL || outputFile == NULL){
	puts("File opening error");
	exit(FILEERROR);
    }

    //While the file is not empty
    while (fgets(inputExpression, 100, inputFile)) {
        printf("%s\n", inputExpression);
        fprintf(outputFile, "Infix: %s\n", inputExpression);
        infixToPostfix(inputExpression, postfix, &status);
        fprintf(outputFile, "Postfix: %s\n", postfix);
        result = evaluate(postfix, &status);
        fprintf(outputFile, "Result: %f\n\n", result);
        memset(postfix,0,MAX_LENGTH);
    }
    if(fclose(inputFile)==EOF || fclose(outputFile)==EOF){
	puts("File closing ERROR");
	exit(FILEERROR);
    }
    
    return 0;
}

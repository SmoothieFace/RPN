/*
* Node Functions Implementation
* @author Krish Galani
* @file node.c 
* 22/11/2021
*/
#include "node.h"
n* createNumberNode(double value1, int type1){
	n* newNode = (n*)calloc(1,sizeof(n));
	if(!newNode){
		puts("No memory");
		exit(-1);
	}
	else{
		newNode->contents.value = value1;
		newNode->type = type1;
		newNode->next = NULL;
	}
	return newNode;
}

n* createOperatorNode(char operator1, int type1){
	n* newNode = (n*)calloc(1,sizeof(n));
	if(!newNode){
		puts("No memory");
		exit(-1);
	}
	else{
		newNode->contents.op = operator1;
		newNode->type = type1;
		newNode->next = NULL;
	}
	return newNode;
}

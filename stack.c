/* List Functions File
 * @author Krish Galani
 * @file stack.c 
 * 22/11/2021
 */
#include "stack.h"

n* top = NULL;

int theStackIsEmpty(){
 return (top == NULL);
}

void push(n* nodeToPush){
 if(theStackIsEmpty()){
	top = nodeToPush;
	return;
 }
 else{
	nodeToPush->next = top;
	top = nodeToPush;
	return;
 }
}

n* pop(void){
 if(theStackIsEmpty()){
	return NULL;
 }
 else{
	n* nodeToPop = top;
	top->next = top;
	return nodeToPop;
 }
}

n* peek(void){
 if(theStackIsEmpty()){
	return NULL;
 }
 else{
	return top;
 }
}

void clear(){
    n* nodeToFree = NULL;
    if (!theStackIsEmpty()) {
	nodeToFree = pop();
        while (nodeToFree) {
            free(nodeToFree);
        }
    }   
    return;
}

void toString(){
 n* step = top;
 while(step){
  if(step->type == opType){ 
   printf("%c ",(step->contents.op));
  }
  else{
   printf("%f ",(step->contents.value));
  }
  }
   printf("\n");
  return;
}

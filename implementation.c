
#include <stdio.h>
#include <math.h>
#include <string.h>


void push(StackNodePtr *topPtr, BizarreNumber_t info)
{
	//using Malloc()
	StackNodePtr nstacknode = malloc(sizeof(StackNode));
	if(nstacknode != NULL){
        	nstacknode->data = info;
        	nstacknode->nextPtr = *topPtr;
        	*topPtr = nstacknode;
    }
   else
       printf("empty.\n");
}
BizarreNumber_t pop(StackNodePtr *topPtr)
{	//pop to stack
	StackNodePtr tempPtr = *topPtr;
	BizarreNumber_t popValue = (*topPtr)->data;
    	*topPtr = (*topPtr)->nextPtr;
    	void free(tempPtr);
    	return popValue;
}
int isEmpty(StackNodePtr topPtr)
{
	return topPtr == NULL;
}
void printStack(StackNodePtr currentPtr)
{
	if(currentPtr == NULL)
        printf("empty.\n");
    	else{
		printf("TOP --> ");
        	while(currentPtr != NULL){
			if(currentPtr->data.number == -1)
				printf("NULL --> ");
            		else
				printf("%d --> ", currentPtr->data.number);
            		currentPtr = currentPtr->nextPtr;
        }
       	puts("BOTTOM\n");
    }
}
void printStackDetailed(StackNodePtr currentPtr)
{
	printf(" **********TOP*********\n");
	while(currentPtr != NULL){
		printf("%d, %d, %s\n",currentPtr->data.number,currentPtr->data.nrOfOpr,currentPtr->data.type);
		currentPtr = currentPtr->nextPtr;
	}
	printf("*******BOTTOM********\n\n");
}
StackNodePtr reverseStack(StackNodePtr currentPtr)
{
	StackNodePtr revnum = NULL;
	while(currentPtr != NULL){
		push(&revnum, pop(&currentPtr));
	}
	return revnum;
}
//chek to AbudantNumber
int isAbundantNumber(int number)
{
	int maxdivnumber = (number / 2) + 1, sum = 0;
	for(int i = 1; i < maxdivnumber; i++){
		if(number % i == 0)
			sum += i;
	}
	if(number > sum)
		return -1;
	else if(number < sum)
		return 1;
	else
		return 0;
	return 0;
}


int isPrime(int number)
{	//chek to Prime Number
	for(int i = 2; i < number; i++){
		if(number % i == 0 && i != number)
			return 0;
	}
	return 1;
}
int isPerfectSquare(int number)
{	//chek to Perfect Square Number
	for(int i = 1; i <= ((int)sqrt(number)); i++){
		if (number == i * i)
            return 1;
	}
	return 0;
}
StackNodePtr recoverCipher(StackNodePtr mainStack, StackNodePtr helperStack)
{	//recover to stack
	StackNodePtr rec = NULL;
	BizarreNumber_t deep;
	while(mainStack != NULL)
 
	{	//prime number
		if(strcmp(mainStack->data.type,"PR") == 0){
			strcpy(d.type,"PR");
			deep.nrOfOpr = 0;
			deep.number = sqrt(mainStack->data.number);
			push(&rec,deep);
		}
		//perfect number
		else if(strcmp(mainStack->data.type,"PF") == 0){
            strcpy(deep.type,"PF");
            deep.nrOfOpr = 0;
            deep.number = mainStack->data.number;
            push(&rec,deep);
        }	// perfect square number
		else if(strcmp(mainStack->data.type,"SQ") == 0){
			int oInt = mainStack->data.number;
			for(int i = mainStack->data.nrOfOpr; i > 0; i--){
				oInt *= oInt;
			}
		
			strcpy(deep.type,"SQ");
            deep.nrOfOpr = mainStack->data.nrOfOpr;
			deep.number = oInt;
           push(&rec,deep);
        }	// abundant number
		else if(strcmp(mainStack->data.type,"AB") == 0){
            strcpy(deep.type,"AB");
            deep.nrOfOpr = 0;
            deep.number = mainStack->data.number + helperStack->data.number;
            push(&rec,deep);
        }
		else{
		//deficient number
            strcpy(deep.type,"DF");
            deep.nrOfOpr = 0;
            deep.number = helperStack->data.number;

            push(&rec,deep);
        }
		mainStack = mainStack->nextPtr;
		helperStack = helperStack->nextPtr;
	}
	StackNodePtr revnum= reverseStack(rec);
	return revnum;
}



#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
//crate type of typedef struct
typedef struct {
	char type[3];
	int nrOfOpr;
	int num;
}BizarreNumber_t;
struct stackNode {
	BizarreNumber_t data;
	struct stackNode *nextPtr;
};
typedef struct stackNode StackNode;
typedef StackNode *StackNodePtr;
void push(StackNodePtr *topPtr, BizarreNumber_t info);
BizarreNumber_t pop(StackNodePtr *topPtr);
int isEmpty(StackNodePtr topPtr);
void printStack(StackNodePtr currentPtr);
void printStackDetailed(StackNodePtr currentPtr);
StackNodePtr reverseStack(StackNodePtr currentPtr);
int isAbundantNumber(int number);
int isPrime(int number);
int isPerfectSquare(int number);
StackNodePtr recoverCipher(StackNodePtr mainStack, StackNodePtr helperStack);
#endif

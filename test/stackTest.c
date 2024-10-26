#include "../lcds.h"
#include "stdio.h"

typedef struct example{
    int dato1;
    char dato2;
}example;

int main(int argc, char** argv){
    example* data1 = malloc(sizeof(example));
    example* data2 = malloc(sizeof(example));
    example* data3 = malloc(sizeof(example));
    example* data4 = malloc(sizeof(example));
    
    data1->dato1 = 1;
    data1->dato2 = 'X';

    data2->dato1 = 2;
    data2->dato2 = 'Y';

    data3->dato1 = 3;
    data3->dato2 = 'Z';

    data4->dato1 = 4;
    data4->dato2 = 'A';

    Stack* myStack = stackCreate(sizeof(example));

    stackPush(myStack,stackCreateNode(sizeof(example),data4));
    printf("ID: %i - Char: %c\n",((example*) getStackNodeData(stackPeek(myStack)))->dato1, ((example*) getStackNodeData(stackPeek(myStack)))->dato2);

    stackPush(myStack,stackCreateNode(sizeof(example),data1));
    printf("ID: %i - Char: %c\n",((example*) getStackNodeData(stackPeek(myStack)))->dato1, ((example*) getStackNodeData(stackPeek(myStack)))->dato2);

    stackPush(myStack,stackCreateNode(sizeof(example),data2));
    printf("ID: %i - Char: %c\n",((example*) getStackNodeData(stackPeek(myStack)))->dato1, ((example*) getStackNodeData(stackPeek(myStack)))->dato2);

    stackPush(myStack,stackCreateNode(sizeof(example),data3));
    printf("ID: %i - Char: %c\n",((example*) getStackNodeData(stackPeek(myStack)))->dato1, ((example*) getStackNodeData(stackPeek(myStack)))->dato2);

    // 4A 1X 2Y 3Z

    stackPop(myStack);
    printf("ID: %i - Char: %c\n",((example*) getStackNodeData(stackPeek(myStack)))->dato1, ((example*) getStackNodeData(stackPeek(myStack)))->dato2);

    stackPop(myStack);
    printf("ID: %i - Char: %c\n",((example*) getStackNodeData(stackPeek(myStack)))->dato1, ((example*) getStackNodeData(stackPeek(myStack)))->dato2);

    stackPop(myStack);
    printf("ID: %i - Char: %c\n",((example*) getStackNodeData(stackPeek(myStack)))->dato1, ((example*) getStackNodeData(stackPeek(myStack)))->dato2);

    stackPop(myStack);
    printf("ID: %i - Char: %c\n",((example*) getStackNodeData(stackPeek(myStack)))->dato1, ((example*) getStackNodeData(stackPeek(myStack)))->dato2);
    return 0;
}
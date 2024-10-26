#ifndef LCDS
#define LCDS

#include "stdlib.h"
#include "string.h"

// Lambda C Data Structures
// Library by Rafael Espinosa

/*
    Stack
    Queue
    Linked Lists:
        Simply Linked List (SLL)
        Double Linked List (DLL)
        Simply Circular Linked List (SCLL)
        Double Circular Linked List (DCLL)
    Trees:
        (Coming Soon)
*/

//////////////////////////////////////////////
//                   STACK                  //
//////////////////////////////////////////////

// Structure that defines de stack node data
typedef struct StackNode
{
    void* Data;
    struct StackNode* PrevNode;
} StackNode;
//Structure that defines the Stack.
typedef struct Stack
{
    size_t dataSize;
    StackNode* Top;
} Stack;

// FUNCTIONS TO MANAGE STACK
Stack* stackCreate(size_t stackSize){ 
    if(stackSize <= stackSize){
        return NULL;
    }
    Stack* newStack = (Stack*) malloc(sizeof(Stack));
    if(newStack == NULL){
        return NULL;
    }
    newStack->dataSize = stackSize;
    newStack->Top = NULL;
    return newStack;
}

void stackClear(Stack* myStack){
    if(myStack == NULL){
        return;
    }
    StackNode* aux = myStack->Top;
    while(aux){
        myStack->Top = aux->PrevNode;
        free(aux);
        aux = myStack->Top;
    }
    return;
}

void stackDelete(Stack* myStack){
    if(myStack == NULL){
        return;
    }
    StackNode* aux = myStack->Top;
    while(aux){
        myStack->Top = aux->PrevNode;
        free(aux);
        aux = myStack->Top;
    }
    free(myStack);
    return;
}

int stackIsEmpty(Stack* myStack){
    return myStack->Top == NULL;
}

StackNode* stackPeek(Stack* myStack){
    return myStack->Top;
}

void stackPush(Stack* myStack, StackNode* newStack){
    if(myStack == NULL || newStack == NULL){
        return;
    }
    if(myStack->Top == NULL){
        myStack->Top = newStack;
        return;
    }else{
        newStack->PrevNode = myStack->Top;
        myStack->Top = newStack;
        return;
    }
}

StackNode* stackPop(Stack* myStack){
    if(myStack == NULL){
        return;
    }
    if(myStack->Top == NULL){
        return NULL;
    }else{
        StackNode* aux = myStack->Top;
        myStack->Top = aux->PrevNode;
        free(aux);
    }
}

StackNode* stackCreateNode(size_t size, void* data){
    if(size <= 0 || data == NULL){
        return NULL;
    }
    StackNode* newNode = (StackNode*) malloc(sizeof(StackNode));
    if (newNode == NULL) {
        return NULL;
    }
    newNode->Data = malloc(size);
    if (newNode->Data == NULL) {
        free(newNode);
        return NULL;
    }
    memcpy(newNode->Data, data, size);
    newNode->PrevNode = NULL;
    return newNode;
}

void* getStackNodeData(StackNode* node){
    if(node == NULL){
        return;
    }
    return node->Data;
}

#endif
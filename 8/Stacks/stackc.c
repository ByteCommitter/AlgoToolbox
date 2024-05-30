//stacks:
//insertionas and deletions are allwoed only at the end of the array, 
//otherwise similar to arrays   
//similar to a stack of books or coins in a glass jar...
//LIFO: Last in First Out

//operations:
//push: insert an element at the top of the stack
//pop: remove an element from the top of the stack
//peek: get the top element of the stack without removing it
//isEmpty: check if the stack is empty
//isFull: check if the stack is full
//top: get the top element of the stack

//does top remove the top element of the stack? no, it just returns the top element of the stack
//does pop remove the top element of the stack? yes, it removes the top element of the stack

#include <stdio.h>
#include <stdlib.h>

//array implementation of stack
#define size 5
int stack[size];
int top=-1;

void push(int x){
    if(top==size-1){
        printf("Stack is full\n");
        return;
    }
    else{
        top++;
        stack[top]=x;
    }
}

int pop(){
    int x;
    if(top==-1){//can replace with isEmpty function
        printf("Underflow!!");
        return -1;
    }
    else{
        x=stack[top];
        printf("%d",x);
        top--;
    }
    return x;
}

void printStack(){
    for(int i=0;i<=top;i++){
        printf("%d ",stack[i]);
    }
    printf("\n");
}

bool isFull(){
    if(top==size-1){//can replace with isFull function
        return true;
    }
    else{
        return false;
    }
}

bool isEmpty(){
    if(top==-1){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    push(5);
    push(3);
    push(2);
    push(1);
    int x=pop();
    printf("\nWhole Stack!\n");
    printStack();
}
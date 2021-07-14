#include<stdio.h>
#include<stdlib.h>

typedef struct Stack{
    int size;
    int* values;
}stack;

stack new_stack(){
    stack temp;
    temp.size = 0;
    temp.values = (int*)malloc(sizeof(int)*temp.size);
    return temp;
}

void push(stack* s,int n){
    s->size++;
    s->values = (int *)realloc(s->values,(sizeof(int) * s->size));
    s->values[s->size-1] = n;
}

int pop(stack* s){
    s->size--;
    int temp=s->values[s->size];
    realloc(s->values,sizeof(int)*s->size);
    return temp;
}

int peek(stack* s){
    return s->values[s->size - 1 ];
}

void main(void){
    stack current_stack = new_stack();
    push(&current_stack,1);
    printf("%d ",peek(&current_stack));   
}
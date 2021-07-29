#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int size;
    int* arr;
}Queue;

void enqueue(Queue* q,int n){
    q->size++;
    realloc(q->arr,q->size * sizeof(int));
    q->arr[q->size - 1] = n;
}

int dequeue(Queue* q){
    int out = q->arr[0];
    q->size--;
    q->arr = (q->arr)+1;
    return out;
}

void display(Queue* q){
    for(int i=0;i<q->size;i++){
        printf("%d\n",q->arr[i]);
    }
}

int front(Queue* q){
    return q->arr[0];
}

Queue* new_queue(){
    Queue* q = (Queue*) malloc(1 * sizeof(Queue));
    q->size = 0;
    q->arr = (int*) malloc(q->size * sizeof(0));
    return q;
}

void main(void){
    Queue* q = new_queue();
    enqueue(q,1);
    enqueue(q,2);
    enqueue(q,3);
    enqueue(q,4);
    enqueue(q,5);

    display(q);

    int x = dequeue(q);

    display(q);
}
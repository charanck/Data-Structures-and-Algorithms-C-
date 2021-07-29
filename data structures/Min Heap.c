#include <stdio.h>
#include <stdlib.h>

typedef struct minheap{
    int size;
    int* arr;
}Minheap;

void bubbleup(Minheap* minheap){
    int index = minheap->size - 1;
    while(index != 0){
        if(minheap->arr[(index - 1) / 2] > minheap->arr[index]){
            int temp = minheap->arr[(index - 1) / 2];
            minheap->arr[(index - 1) / 2] = minheap->arr[index];
            minheap->arr[index] = temp;
        }
        index = (index - 1) / 2;
    }
}

void bubbledown(Minheap* minheap){
    int index = (minheap->arr[1] < minheap->arr[2]) ? 1 : 2;
    if(minheap->size <= 1) return;
    else if(minheap->size == 2){
        if(minheap->arr[0] > minheap->arr[1]){
            int temp = minheap->arr[0];
            minheap->arr[0] = minheap->arr[1];
            minheap->arr[1] = temp;
        }
        return;
    }
    if(minheap->arr[0] > minheap->arr[index]){
        int temp = minheap->arr[0];
        minheap->arr[0] = minheap->arr[index];
        minheap->arr[index] = temp;
    }
    if(minheap->size > 3){
        while(index != minheap->size){
            if(((index * 2) + 1) < minheap->size && minheap->arr[index] > minheap->arr[(index * 2) + 1 ]){
                int temp = minheap->arr[index];
                minheap->arr[index] = minheap->arr[(index * 2) + 1];
                minheap->arr[(index * 2) + 1] = temp;
            }
            index++;
        }
    }
}

void display(Minheap* minheap){
    for(int i=0;i<minheap->size;i++){
        printf("%d ",minheap->arr[i]);
    }
}

void add(Minheap* minheap,int n){
    minheap->size++;
    realloc(minheap->arr,minheap->size * sizeof(int));
    minheap->arr[minheap->size - 1] = n;
    bubbleup(minheap);
}

Minheap* new_minheap(){
    Minheap* minheap = (Minheap*) malloc(1 * sizeof(Minheap));
    minheap->size = 0;
    minheap->arr = (int*) malloc(minheap->size * sizeof(int));
    return minheap;
}

int pop(Minheap* minheap){
    int out = minheap->arr[0];
    minheap->arr[0] = minheap->arr[minheap->size - 1];
    minheap->size--;
    realloc(minheap->arr,minheap->size * sizeof(int));
    bubbledown(minheap);
    return out;
}

int main(void){
    Minheap* minheap = new_minheap();
    add(minheap,7);
    add(minheap,1);
    add(minheap,2);
    add(minheap,3);
    add(minheap,4);
    add(minheap,5);
    add(minheap,6);
    add(minheap,0);
    display(minheap);

    printf("\n%d\n",pop(minheap));
    display(minheap);
    printf("\n%d\n",pop(minheap));
    display(minheap);
    printf("\n%d\n",pop(minheap));
    display(minheap);

    return 0;
}
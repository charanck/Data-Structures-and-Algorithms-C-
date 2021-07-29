#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    struct node* prev;
    struct node* next;
    int value;
}Node;

typedef struct doublylinkedlist{
    Node* head;
    int size;
}DoublyLinkedList;

DoublyLinkedList* new_doublylinkedlist(int n){
    DoublyLinkedList* dll = (DoublyLinkedList*)(malloc(1 * sizeof(DoublyLinkedList)));
    Node* head = (Node*) malloc(1 * sizeof(Node));
    head->value = n;
    head->next = 0;
    head->prev = 0;

    dll->size = 1;
    dll->head = head;
    return dll;
}

void add(DoublyLinkedList* dll,int n){
    Node* temp = (Node*) malloc(1 * sizeof(Node));
    temp->value = n;
    temp->next = 0;
    Node* cur = dll->head;
    while(cur->next != 0){
        cur = cur->next;
    }
    cur->next = temp;
    temp->prev = cur;
    dll->size++;
}

void display(DoublyLinkedList* dll){
    Node* cur = dll->head;
    printf("\n");
    printf("Head => ");
    while(cur != 0){
        printf("%d <-> ",cur->value);
        cur = cur->next;
    }
}

void delete(DoublyLinkedList* dll,int n){
    Node* cur = dll->head;
    if(cur->value == n){
        dll->head = cur->next;
        dll->head->prev = 0;
        free(cur);
        return;
    }else{
        while(cur != 0 && cur->value != n){
            cur = cur->next;
        }
        if(cur != 0){
            cur->prev->next = cur->next;
            free(cur);
        }
    }
}

int main(void){
    DoublyLinkedList* dll = new_doublylinkedlist(1);
    add(dll,2);
    add(dll,3);
    add(dll,4);
    add(dll,5);
    add(dll,6);

    display(dll);
    delete(dll,3);
    display(dll);
    delete(dll,1);
    display(dll);
    return 0;
};
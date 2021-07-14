#include <stdio.h>
#include <stdlib.h>
struct Node{
    int value;
    struct Node* next;
};

void display(struct Node* n){
    while(n!=0){
        printf("%d ",n->value);
        n = n->next;
    }
    printf("\n");
}

void add(struct Node* ll ,int n){
    struct Node* cur = ll;
    while(cur->next != 0){
        cur = cur->next;
    }
    struct Node* temp = (struct Node*) malloc(1*sizeof(struct Node));
    (*temp).value = n;
    (*temp).next = 0;
    cur->next = temp;
}

void deleteNode(struct Node* ll ,int n){
    struct Node* prev = ll;
    struct Node* cur = ll->next;

    if(cur == 0){
        return;
    }

    while(cur->value != n){
        prev = cur;
        cur = cur->next;
    }

    prev->next = cur->next;
    free(cur);

}

struct Node* deleteHead(struct Node* ll ){
    struct Node* temp = ll->next;
    free(ll);
    return temp;
}

int main()
{
    int n;
    printf("Enter No of Elements: ");
    scanf("%d",&n);
    struct Node* prev = (struct Node*)malloc(1*sizeof(struct Node));
    struct Node* head = (struct Node*)malloc(1*sizeof(struct Node));
    head->value = 0;
    head->next = 0;
    for(int i=1;i<=n;i++){
        add(head,i);
    }
    display(head);
    head = deleteHead(head);
    display(head);
    return 0;
}

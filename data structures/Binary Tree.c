#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int value;
    struct node* left;
    struct node* right;
}Node;

typedef struct binarytree{
    Node* head;
}BinaryTree;

BinaryTree* new_binarytree(int n){
    BinaryTree* bt = (BinaryTree*) malloc(1 * sizeof(BinaryTree));
    Node* temp = (Node*)malloc(1 * sizeof(Node));
    temp->value = n;
    temp->left = 0;
    temp->right = 0;
    bt->head = temp;
    return bt;
}

void add(BinaryTree*  bt,int n){
    Node* cur = bt->head;
    Node* temp = 0;
    while(1){
        if(n <= cur->value){
            if(cur->left == 0){
                break;
            }
            cur = cur->left;
        }else{
            if(cur->right == 0){
                break;
            }
            cur = cur->right;
        }
    }
    temp = (Node*)malloc(1 * sizeof(Node));
    temp->value = n;
    temp->left = 0;
    temp->right = 0;
    if(n <= cur->value) cur->left = temp;
    else cur->right = temp;
}

void inorderdisplay(Node* node){
    if(node->left !=0)inorderdisplay(node->left);
    printf("%d ",node->value);
    if(node->right !=0)inorderdisplay(node->right);
}

void preorderdisplay(Node* node){
    printf("%d ",node->value);
    if(node->left !=0)preorderdisplay(node->left);
    if(node->right !=0)preorderdisplay(node->right);
}

void postorderdisplay(Node* node){
    if(node->left !=0)postorderdisplay(node->left);
    if(node->right !=0)postorderdisplay(node->right);
    printf("%d ",node->value);
}

void display(BinaryTree* bt,int choice){
    switch (choice)
    {
    case 0:inorderdisplay(bt->head);break;
    case 1:preorderdisplay(bt->head);break;
    case 2:postorderdisplay(bt->head);break;
    default:
        break;
    }
    
}

int main(void){
    BinaryTree* bt = new_binarytree(5);
    add(bt,1);
    add(bt,2);
    add(bt,8);
    add(bt,10);
    add(bt,7);

    display(bt,2);

    return 0;
}
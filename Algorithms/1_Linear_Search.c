#include <stdio.h>

int search(int arr[],int required,int size){
    for(int i =0;i<size;i++){
        if(arr[i] == required) return 1;
    }
    return 0;
}
int main(void){
    int arr[]={1,5,4,6,9,8,7,3};
    int size =8;
    int required = 3;
    printf("%d",search(arr,required,size));
    return 0;
}

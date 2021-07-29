#include <stdio.h>
#define TRUE 1;
#define FALSE 0;

int binary_search(int arr[],int size,int required) {
    int i=0,j=size-1,mid=size/2;
    int isfound = FALSE;
    while(!isfound && i<j){
        if(arr[mid] == required){
            isfound = TRUE;
            break;
        }else if(required > arr[mid]){
            i= mid;
        }else{
            j=mid;
        }
        mid = (i+j)/2;
    }

    return isfound;
}
int main(void){
    int arr[] = {1,2,3,4,5,6,7,8,9};
    printf("%d",binary_search(arr,9,9));
    return 0;
}

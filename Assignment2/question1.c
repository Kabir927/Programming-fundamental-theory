/*
kabir
24k-0927
question1
*/
#include<stdio.h>

int main(){
    int n,smallest;
    printf("enter the size of array");
    scanf("%d",&n);
    int array[n];
    for(int i=0;i<n;i++){
        printf("enter the %d element of array",i+1);
        scanf("%d",&array[i]);
        while(array[i]>9999){
            printf("the number should be less than 9999");
            scanf("%d",&array[i]);
        }
    }
    smallest=array[0];
    for(int i=0;i<n;i++){
        if(array[i]<smallest){
            smallest=array[i];
        }
    }
    for(int i=0;i<n;i++){
        if(array[i]==smallest){
            array[i]=9999;
        }
    }
    smallest=array[0];
    for(int i=0;i<n;i++){
        if(array[i]<smallest){
            smallest=array[i];
        }
    }
    printf("2nd smallest:%d",smallest);

    return 0;
}

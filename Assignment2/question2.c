/*
kabir
24k-0927
question2
*/
#include <stdio.h>

void countLetters(char str[][50], int n);
void frequency(char str[][50], int n, int i, int j);

int main(){
    int n;
    printf("Enter number of slogans: ");
    scanf("%d", &n);
    char str[n][50];

    for(int i=0; i<n; i++){
        printf("Slogan %d: ", i+1);
        fgets(str[i], 50, stdin);
    }

    for(int i=0; i<n; i++){
        printf("\nFor %s", str[i]);
        countLetters(str, i);
    }
}

void countLetters(char str[][50], int n){
    int i, j;
    for(j=0; str[n][j]!='\0'; j++){
        if(str[n][j]==' '){
            i=j;
        }
    }
    j=j-i-2;
    frequency(str, n, i, j);
    return;
}

void frequency(char str[][50], int n, int a, int b){
    int s=a+b+1, fre[s];
    for(int i=0; i<s; i++){
        fre[i]=1;
    }
    for(int i=0; i<s; i++){
        for(int j=i+1; j<s; j++){
            if(str[n][i]==str[n][j]) fre[i]++;
            if(i<a && j<a) if(str[n][i]==str[n][j]) fre[i]--;
            if(i>b && j>b) if(str[n][i]==str[n][j]) fre[i]--;
            if(str[n][i]==str[n][j]) str[n][j]='0';
        }
        if(str[n][i]!='0') printf("'%c': %d", str[n][i], fre[i]);
    }
    return;
}
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#define MAX 100

int main (){

    int i, n;

    char a[MAX][MAX], b[MAX];

    printf("Numero de palavras: ")  ;
    scanf("%d", &n);

    for(i=0; i<n; i++){
        printf("Digita a %da palavra:  ", i+1);
        fflush(stdin);
        gets(a[i]);
        fflush(stdin);
    }

    printf("\n\n\nTRANSIÇÃO!!!!\n\n\n");
    getch();
    clrscr();
    
    for(i=0; i<n; i++){
        printf("%s\n", a[i]);
    }

    return 0;
}
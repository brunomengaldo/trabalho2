#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

int main (int argc, char *argv[]){

    int m[MAX][MAX], *point[MAX][MAX];

    for(int i=0; i<MAX; i++){
        for(int j=0; j<MAX; j++){
            m[i][j]=i+j+64;
        }
    }

    for(int i=0; i<MAX; i++){
        for(int j=0; j<MAX; j++){
            point[i][j]=m[i][j];
            if(i==j){
                point[i][j]='!';
            }
        }
    }

    char vetor[MAX*3];
    int cont=0;

    for(int i=0; i<MAX; i++){
        for(int j=0; j<MAX; j++){
            vetor[cont]=point[i][j];
            cont++;
            vetor[cont]='\t';
            cont++;
        }
        vetor[cont] = '\n';
        cont++;
    }//*/

    printf("%s\n", vetor);
    

    return 0;
}
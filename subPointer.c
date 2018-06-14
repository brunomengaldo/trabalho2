#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>


#define MAX 10

int main (int argc, char *argv[]){

//=====================================================
    // Inicializa/Cria variaveis
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;

    // Salva a cor atual da tela
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;
//=====================================================

    int m[MAX][MAX], *point[MAX][MAX];

    for(int i=0; i<MAX; i++){
        for(int j=0; j<MAX; j++){
            m[i][j]=i+j+64;
        }
    }

    for(int i=0; i<MAX; i++){
        for(int j=0; j<MAX; j++){
            point[i][j]=&m[i][j];
            if(i==j){
                *point[i][j]='!';
            }
        }
    }

    char vetor[MAX*3];
    int cont=0;

    for(int i=0; i<MAX; i++){
        for(int j=0; j<MAX; j++){
            vetor[cont]=*point[i][j];
            cont++;
        }
        vetor[cont] = '\n';
        cont++;
    }//*/

    vetor[cont]='\0';


    // kkk
    //for(int k=0; k<MAX; k++){
    //    for(int j=0; j<MAX; j++){
            //for(int i=0; i<cont; i++){        
                // if(vetor[i]=='!'){
                //     SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                //     printf("%c", vetor[i]);
                //     SetConsoleTextAttribute(hConsole, saved_attributes);      
                // }
                //else
                //printf("%s", vetor);
            //}
    //    }
    //}
    char *x;

    x=strstr(vetor, "NOPQ");

    if(x!=NULL){
        printf("aqui oh %s\n", x);
    }


    SetConsoleTextAttribute(hConsole, saved_attributes);



    return 0;
}
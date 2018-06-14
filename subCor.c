#include <stdio.h>
#include <windows.h>

#define MAX 100

typedef struct{
    int nLinhas, nColunas;
    char matriz[MAX][MAX], *point[MAX][MAX];
}infos;

// Prototipos
void subFor(infos *);
void subColor(infos *);

// Programa Principal
int main (int argc, char *argv[]){

    infos valores;

    printf("num linhas: ");
    scanf("%d", &valores.nLinhas);

    printf("num colunas: ");
    scanf("%d", &valores.nColunas);

    fflush(stdin);

    subFor(&valores);

    subColor(&valores);

    return 0;
}

//===============================================

void subFor(infos *p){

    int i, j;
    
    for(i=0; i<p->nLinhas; i++){
        for(j=0; j<p->nColunas; j++){
            p->matriz[i][j]='A';
        }
    }
    
    for(i=0; i<p->nLinhas; i++){
        for(j=0; j<p->nColunas; j++){
            p->point[i][j]=p->matriz[i][j];
        }
    }

    return;
}


void subColor(infos *p){

    int i, j;


    // Inicializa/Cria variaveis
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;

    // Salva a cor atual da tela
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;

    
    // Muda cor
    printf("\ntestando\n\n");

    for(i=0; i<p->nLinhas; i++){
        for(j=0; j<p->nColunas; j++){
            if(i==j){
                p->point[i][j]='J';
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                printf("%c ", p->point[i][j]);
                SetConsoleTextAttribute(hConsole, saved_attributes);
            }
            else{
                printf("%c ", p->point[i][j]);
            }
        }
        printf("\n");
    }


    // SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
 
    // Restore original attributes
    SetConsoleTextAttribute(hConsole, saved_attributes);

    return;
}
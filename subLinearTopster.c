//Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Constante Global
#define MAX 100

// Tipos de Dados
typedef struct{
    int nColunas;
    int nLinhas;
    int nPalavras;
    char matriz[MAX][MAX];
    char transposta[MAX][MAX];
    char lista[MAX][MAX];
    char randW[MAX][MAX];
    char vetor[MAX*MAX*10];
    char faltam[MAX][MAX];
} infos;

// Prototipos
void subDimencoes(infos *);
void subAleat(infos *);
void subLinear(infos *);
void impr(infos *);


// Funcao Principal
int main (int argc, char *argv[]){

    infos val;
    
    //char op[2];
    //printf("deseja gerar aleat? (y/n)\n");
    //scanf("%c", &op[0]);
    //fflush(stdin);

    if(1){         //(op[0]='y'){
        subDimencoes(&val);
        subAleat(&val);
        subLinear(&val); 
        impr(&val);
    }
    
    return 0;
}




// Objetivo: Definir dimenções do caça palavras
// Parâmetros formais
// - p: conjunto de dados (parâmentro de saída de dados)
// Valor de Retorno:
// - não há (procedimento)
void subDimencoes(infos *p){

    // Ler tamanho da matriz
    printf("Informe o numero de linhas: ");
    scanf("%d", &p->nLinhas);
    printf("Informe o numero de colunas: ");
    scanf("%d", &p->nColunas);

    // Ler número de palavras
    //printf("Informe o numero de palavras: ");
    //scanf("%d", &p->nPalavras);
    
    printf("\n");

    return;
}


// Objetivo: Criar uma matriz totalmente aleatória e sua transposta
// Parâmetros formais
// - p: conjunto de dados (parâmentro de saída de dados)
// Valor de Retorno:
// - não há (procedimento)
void subAleat(infos *p){

    // Inicializar gerador de números aleatórios
    srand(time(NULL));

    // Contadores
    int i, j;

    // Criação da matriz de inteiros correspondentes às letras maiúsculas da tabela ASCII
    for(i=0; i<p->nLinhas; i++){
        for(j=0; j<p->nColunas; j++){
            p->matriz[i][j]=(rand()%26)+(65);
        }
    }

}


// Objetivo: Linearizar a matriz principal em um vetor tanto em linhas, como em colunas
// Parâmetros formais
// - p: conjunto de dados (parâmentro de saída de dados)
// Valor de Retorno:
// - não há (procedimento)
void subLinear(infos *p){

    // Contadores
    int i, j, k;

    // Variável Local
    int cont0=0, temp=p->nColunas-1;

    // Linearização em linhas
    for(i=0; i<p->nLinhas; i++){
        for(j=0; j<p->nColunas; j++){
            p->vetor[cont0] = p->matriz[i][j];
            cont0++;
        }
        p->vetor[cont0] = '\n';
        cont0++;
    }

    // Linearização em colunas
    for(i=0; i<p->nColunas; i++){
        for(j=0; j<p->nLinhas; j++){
            p->vetor[cont0] = p->matriz[j][i];
            cont0++;
        }
        p->vetor[cont0] = '\n';
        cont0++;
    }

    //Oposta Linh
    for(i=0; i<p->nLinhas; i++){
        for(j=p->nColunas-1; j>=0; j--){
            p->vetor[cont0] = p->matriz[i][j];
            cont0++;
        }
        p->vetor[cont0] = '\n';
        cont0++;
    }

    //Opost Vertical
    for(i=0; i<p->nColunas; i++){
        for(j=p->nLinhas-1; j>=0; j--){
            p->vetor[cont0] = p->matriz[j][i];
            cont0++;
        }
        p->vetor[cont0] = '\n';
        cont0++;
    }

    //DIAGONAL direita
    for(i=0; i<p->nLinhas+p->nColunas-1; i++){        
        for(j=0; j<p->nLinhas; j++){
            for(k=p->nColunas-1; k>=0; k--){
                if(k-j==temp){
                    p->vetor[cont0] = p->matriz[j][k];
                    cont0++;
                }
            }
        }        
        p->vetor[cont0] = '\n';
        temp--;
        cont0++;
    }
    
    //OPOSTA DIAG DIR
    temp=p->nColunas-1;

    for(i=0; i<p->nLinhas+p->nColunas-1; i++){
        for(k=p->nColunas-1; k>=0; k--){
            for(j=0; j<p->nLinhas; j++){
                if(k-j==temp){
                    p->vetor[cont0] = p->matriz[j][k];
                    cont0++;
                }
            }
        }        
        p->vetor[cont0] = '\n';
        temp--;
        cont0++;
    }

    //DIAGONAL esquerda
    for(i=0; i<p->nLinhas+p->nColunas-1; i++){
        for(j=0; j<p->nLinhas; j++){
            for(k=0; k<p->nColunas; k++){
                if(k+j==i){
                    p->vetor[cont0] = p->matriz[j][k];
                    cont0++;
                }
            }
        }
        p->vetor[cont0] = '\n';
        cont0++;
    }

    //OPOSTA DIAG ESQ
    for(i=0; i<p->nLinhas+p->nColunas-1; i++){
        for(k=0; k<p->nColunas; k++){
            for(j=0; j<p->nLinhas; j++){
                if(k+j==i){
                    p->vetor[cont0] = p->matriz[j][k];
                    cont0++;
                }
            }
        }
        p->vetor[cont0] = '\n';
        cont0++;
    }

    // Finalização do vetor
    p->vetor[cont0] = '\0';

    return;
}


//Objetivo: kkk.
// Parâmetros formais
// - p: conjunto de dados (parâmentro de saída de dados)
// Valor de Retorno:
// - não há (procedimento)
void impr(infos *p){

    // Contadores
    int i, j;

    // Impressão da matriz aleatória
    printf("\nMatriz de Palavras Aleatorias:\n");
    for(i=0; i<p->nLinhas; i++){
        for(j=0; j<p->nColunas; j++){
            printf("%c%c", p->matriz[i][j], j==p->nColunas-1?'\n':' ');
        }
    }

    printf("\n\n\n");

    printf("%s\n", p->vetor);
}
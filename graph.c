/*

Autor: Bruno Fonseca Mengaldo, Fernando Marubayashi, Thiago Diaz
Revisor: Prof. Ricardo Rodrigues Ciferri
Data: 27/05/18

Objetivo: Criar um programa capaz de determinar se um caça
          palavras está completo e até criar um aleatoriamente.

*/

// Bibliotecas
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// Constante Global
#define MAX 100

// Tipos de Dados
typedef struct{
    int nColunas;
    int nLinhas;
    int nPalavras;
    int c;
    int flagado;
    char matriz[MAX][MAX];
    char transposta[MAX][MAX];
    char lista[MAX][MAX];
    char randW[MAX][MAX];
    char vetor[MAX*MAX*10];
    char faltam[MAX][MAX];
} infos;


// Protótipos
void subLeitura(infos *);
void subImprimir(infos *);
void subMecanismo(infos *);
void subLinear(infos *);
void fim(infos *);

// Programa principal

int main(int argc, char *argv[]){

    // Declarações Locais
    infos valores;

    valores.c=0;
    valores.flagado=1;

    getch();

    subLeitura(&valores);
    subLinear(&valores);
    subImprimir(&valores);
    subMecanismo(&valores);
    //fim(&valores);

    // Finalização do programa
    return 0;
}


// Objetivo: Ler os arquivos que contém o caça palavras completo
// Parâmetros formais
// - p: conjunto de dados (parâmentro de saída de dados)
// Valor de Retorno:
// - não há (procedimento)
void subLeitura(infos *p){

    // Contadores
    int i, j;

    // Variável Local
    char nome[2][MAX];

    // Armazenamento do nome dos arquivos
    fflush(stdin);
    printf("Insira o nome do arquivo da matriz (sem extensao):\n");
    gets(nome[0]);
    printf("Insira o nome do arquivo da lista de palavras (sem extensao):\n");
    gets(nome[1]);
    fflush(stdin);

    for(i=0; i<2; i++){
        strcat(nome[i], ".txt");
    }

    // Leitura arquivo da matriz
    FILE *arquivoX;
    arquivoX = fopen(nome[0], "r");

    fscanf(arquivoX, "%d", &p->nLinhas);
    fscanf(arquivoX, "%d", &p->nColunas);
    fgetc(arquivoX);

    for(i=0; i<p->nLinhas; i++){
        for(j=0; j<p->nColunas; j++){
            fscanf(arquivoX ,"%c ", &p->matriz[i][j]);
        }
    }
    fclose(arquivoX);


    // Leitura arquivo de palavras
    arquivoX = fopen(nome[1], "r");

    fscanf(arquivoX, "%d", &p->nPalavras);

    for(i=0; i<p->nPalavras; i++){
        fscanf(arquivoX, "%s", &p->lista[i]);
    }
    fclose(arquivoX);

    return;
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
    for(j=0; j<p->nColunas; j++){
        for(i=0; i<p->nLinhas; i++){
            p->vetor[cont0] = p->matriz[i][j];
            cont0++;
        }
        p->vetor[cont0] = '\n';
        cont0++;
    }

    //Linearização Oposta em Linhas
    for(i=0; i<p->nLinhas; i++){
        for(j=p->nColunas-1; j>=0; j--){
            p->vetor[cont0] = p->matriz[i][j];
            cont0++;
        }
        p->vetor[cont0] = '\n';
        cont0++;
    }

    //Linearização Oposta em Colunas
    for(i=0; i<p->nColunas; i++){
        for(j=p->nLinhas-1; j>=0; j--){
            p->vetor[cont0] = p->matriz[j][i];
            cont0++;
        }
        p->vetor[cont0] = '\n';
        cont0++;
    }

    //Linearização em Diagonal direita
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
    
    //Linearização Oposta em Diagonal direita
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

    //Linearização em Diagonal esquerda
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

    // Linearização Oposta em Diagonal esquerda
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


// Objetivo: Identificar se o caça palavras está em ordem ou quais as palavras que faltam
// Parâmetros formais
// - p: conjunto de dados (parâmentro de saída de dados)
// Valor de Retorno:
// - não há (procedimento)
void subMecanismo(infos *p){

    // Contadores
    int i;

    // Identificar se faltam palavras
    for(i=0; i<p->nPalavras; i++){
        if(strstr(p->vetor, p->lista[i]) == NULL){
            strcpy(p->faltam[p->c], p->lista[i]);
            p->c++;
            p->flagado=0;
        }
    }

    if(p->flagado==0){
        //
    }

    return;
}



//Objetivos: finalizar td
//kkkkk
void fim(infos *p){

    int i;

    // Imprimir a existência ou não do caça palavras
    if(p->flagado==1){
        printf("\nCaca palavras contem todas as palavras!!\n");
    }
    else if (p->flagado==0){
        printf("\nCaca palavras NAO contem todas as palavras!!\n\nPalavras nao achadas:\n");
        for(i=0; i<p->c; i++){
            printf("%s\n", p->faltam[i]);
        }
    }

}


// Objetivo: Imprimir a matriz aleatória e a lista de palavras obtidas dela
// Parâmetros formais
// - p: conjunto de dados (parâmentro de saída de dados)
// Valor de Retorno:
// - não há (procedimento)
void subImprimir(infos *p){

    // Contadores
    int i, j;

    // Impressão da matriz aleatória
    printf("\nMatriz de Palavras Aleatorias:\n");
    for(i=0; i<p->nLinhas; i++){
        for(j=0; j<p->nColunas; j++){
            printf("%c%c", p->matriz[i][j], j==p->nColunas-1?'\n':' ');
        }
    }
    
    
    /*// Impressão da lista de palavras obtida
    printf("\nLista de Palavras Aleatorias:\n");
    for(i=0; i<p->nPalavras; i++){
        printf("%s\n", p->randW[i]);
    }*/
    
    return;
}

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
    char matriz[MAX][MAX];
    char transposta[MAX][MAX];
    char lista[MAX][MAX];
    char randW[MAX][MAX];
    char vetor[MAX*MAX*10];
    char faltam[MAX][MAX];
} infos;


// Protótipos
int subStart();
void subDimencoes(infos *);
void subLeitura(infos *);
void subImprimir(infos *);
void subAleat(infos *);
void subPalavras(infos *);
void subMecanismo(infos *);
void subManual(infos *);
void subLinear(infos *);


// Programa principal

int main(int argc, char *argv[]){

    // Variável local com valor da subrotina subStart
    int x=subStart();

	  // Declarações Locais
    infos valores;


    // Avaliação de casos para criação do caça palavras

    if(x==0){       // Caso aleatório
        subDimencoes(&valores);
        subAleat(&valores);
        //subPalavras(&valores);
        //subImprimir(&valores);
    }
    else if(x==1){  // Leitura de arquivos
        subLeitura(&valores);
        subLinear(&valores);
        subMecanismo(&valores);
    }
    else if(x==2){  // Inserção manual
        subDimencoes(&valores);
        subManual(&valores);
        subLinear(&valores);
        subMecanismo(&valores);
    }
    else{           // Nenhuma das opções disponíveis
        printf("Opcao nao valida!\n");
        return 0;
    }

    // Finalização do programa
    return 0;
}



// Objetivo: Definição de como o programa realizará o caça palavras
// Parâmetros formais
// - não há (parâmetro de saída de dados)
// Valor de Retorno:
// - opcao: opção escolhida pelo usuário
int subStart(){

    // Variáveis Locais
    int opcao;

    // Impressão das possíveis opções do caça palavras
    printf("Escolha o modo de criacao do caca palavras:\n");
    printf("\t - Criar matriz e palavras aleatorias (0)\n");
    printf("\t - Abrir arquivos de matriz e palavras (1)\n");
    printf("\t - Inserir dados manualmente (2)\n\n");

    // Análise da escolha do usuário
    scanf("%d", &opcao);

    return opcao;
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
    printf("Informe o numero de palavras: ");
    scanf("%d", &p->nPalavras);
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

    return;
}


/*
// Objetivo: Extrair palavras pertencentes à matriz principal ou à sua transposta
// Parâmetros formais
// - p: conjunto de dados (parâmentro de saída de dados)
// Valor de Retorno:
// - não há (procedimento)
void subPalavras(infos *p){

    // Inicializar gerador de números aleatórios
    srand(time(NULL));

    // Variáveis Locais
    int i, j, indL, indC, c=0;

    // Obtenção das palavras pertencentes às matrizes (principal e transposta)
    for(i=0; i<p->nPalavras; i++){

        indL=(rand()%p->nLinhas-1);
        indC=(rand()%p->nColunas-1);

        for(j=0; j<p->nPalavras; j++){
            if(i<p->nLinhas){
                p->randW[i][j] = p->matriz[i][indC];
                indC++;
            }
            else{
                p->randW[i][j] = p->transposta[i][indL];
                indL++;
                c++;
            }
        }
    }

    return;
}*/


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


// Objetivo: Inserir a matriz do caça palaras e pesquisar suas palavras manualmente
// Parâmetros formais
// - p: conjunto de dados (parâmentro de saída de dados)
// Valor de Retorno:
// - não há (procedimento)
void subManual(infos *p){

    // Contadores
    int i, j;

    // Inserção da matriz
    for (i=0; i<p->nLinhas; i++) {
        printf("Digite as letras da %da linha\n", i+1);
        for (j=0; j <p->nColunas; j++) {
        scanf(" %c", &p->matriz[i][j]);
        }
    }

    // Quebra de linha estética
    printf("\n");

    // Inserção das palavras
    for (i=0; i<p->nPalavras; i++){
		printf("Digite a %da palavra: ", i+1);
		fflush (stdin);
		gets(p->lista[i]);
		fflush (stdin);
	}

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

    // Variáveis Locais
    int c=0, flag=1;

    // Identificar se faltam palavras
    for(i=0; i<p->nPalavras; i++){
        if(strstr(p->vetor, p->lista[i]) == NULL){
            strcpy(p->faltam[c], p->lista[i]);
            c++;
            flag=0;
        }
    }

    //printf("\n\n%s\n\n", p->vetor);

    // Imprimir a existência ou não do caça palavras
    if(flag==1){
        printf("\nCaca palavras contem todas as palavras!!\n");
    }
    else if (flag==0){
        printf("\nCaca palavras NAO contem todas as palavras!!\n\nPalavras nao achadas:\n");
        for(i=0; i<c; i++){
            printf("%s\n", p->faltam[i]);
        }
    }

    return;
}

/*
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

    // Impressão da lista de palavras obtida
    printf("\nLista de Palavras Aleatorias:\n");
    for(i=0; i<p->nPalavras; i++){
        printf("%s\n", p->randW[i]);
    }

    return;
}*/

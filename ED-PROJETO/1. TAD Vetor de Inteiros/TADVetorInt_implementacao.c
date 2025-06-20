/*
** Função : Implementação do TAD Vetor de Inteiros
** Autor  : Alex verissimo 3ºF
** Data   : 13/06/2025
** Observações: Implementação das funções para manipulação dinâmica de vetor de inteiros
*/

#include <stdio.h>
#include <stdlib.h>
#include "TADVetorInt_interface.h"

struct VetorInt {
    int *dados;
    int capacidade;
    int tamanho;
};

VetorInt* criaVetor(int capacidade) {
    VetorInt* v = (VetorInt*) malloc(sizeof(VetorInt));
    if (v == NULL) {
        printf("Erro ao alocar memoria para vetor.\n");
        exit(1);
    }
    v->dados = (int*) malloc(capacidade * sizeof(int));
    if (v->dados == NULL) {
        printf("Erro ao alocar memoria para dados do vetor.\n");
        free(v);
        exit(1);
    }
    v->capacidade = capacidade;
    v->tamanho = 0;
    return v;
}

void insereElemento(VetorInt* v, int elemento) {
    if (v->tamanho == v->capacidade) {
        v->capacidade *= 2;
        v->dados = (int*) realloc(v->dados, v->capacidade * sizeof(int));
        if (v->dados == NULL) {
            printf("Erro ao realocar memoria.\n");
            exit(1);
        }
    }
    v->dados[v->tamanho++] = elemento;
}

void removeElemento(VetorInt* v, int elemento) {
    int i, j;
    for (i = 0; i < v->tamanho; i++) {
        if (v->dados[i] == elemento) {
            for (j = i; j < v->tamanho - 1; j++) {
                v->dados[j] = v->dados[j+1];
            }
            v->tamanho--;
            return;
        }
    }
    printf("Elemento %d nao encontrado para remover.\n", elemento);
}

int consultaElemento(VetorInt* v, int posicao) {
    if (posicao < 0 || posicao >= v->tamanho) {
        printf("Posicao %d invalida.\n", posicao);
        return -1; 
    }
    return v->dados[posicao];
}

void imprimeVetor(VetorInt* v) {
    int i;
    printf("Vetor: ");
    for (i = 0; i < v->tamanho; i++) {
        printf("%d ", v->dados[i]);
    }
    printf("\n");
}

void destroiVetor(VetorInt* v) {
    free(v->dados);
    free(v);
}

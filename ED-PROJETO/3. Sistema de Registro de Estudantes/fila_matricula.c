/*
** Função : Implementação da fila para matrícula de estudantes
** Autor  : Alex verissimo 3ºF
** Data   : 18/06/2025
** Observações: Funções para manipular fila
*/

#include <stdio.h>
#include <stdlib.h>
#include "fila_matricula.h"

FilaMatricula* criar_fila() {
    FilaMatricula* fila = (FilaMatricula*) malloc(sizeof(FilaMatricula));
    if (!fila) return NULL;
    fila->inicio = NULL;
    fila->fim = NULL;
    return fila;
}

void enfileirar(FilaMatricula* fila, Estudante* est) {
    if (!fila || !est) return;
    NoFila* no = (NoFila*) malloc(sizeof(NoFila));
    if (!no) return;
    no->est = est;
    no->prox = NULL;
    if (fila->fim == NULL) {
        fila->inicio = no;
        fila->fim = no;
    } else {
        fila->fim->prox = no;
        fila->fim = no;
    }
}

Estudante* desenfileirar(FilaMatricula* fila) {
    if (!fila || fila->inicio == NULL) return NULL;
    NoFila* temp = fila->inicio;
    fila->inicio = temp->prox;
    if (fila->inicio == NULL) fila->fim = NULL;
    Estudante* est = temp->est;
    free(temp);
    return est;
}

int fila_vazia(FilaMatricula* fila) {
    return (fila == NULL || fila->inicio == NULL);
}

void imprimir_fila(FilaMatricula* fila) {
    if (!fila) {
        printf("Fila nao inicializada.\n");
        return;
    }
    NoFila* aux = fila->inicio;
    if (!aux) {
        printf("Fila vazia.\n");
        return;
    }
    printf("Fila de matricula:\n");
    while (aux) {
        printf("Matricula: %d, Nome: %s\n", aux->est->matricula, aux->est->nome);
        aux = aux->prox;
    }
}

void liberar_fila(FilaMatricula* fila) {
    if (!fila) return;
    while (!fila_vazia(fila)) {
        desenfileirar(fila);
    }
    free(fila);
}

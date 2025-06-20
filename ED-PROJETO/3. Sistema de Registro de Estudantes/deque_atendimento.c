/*
** Função : Implementação do deque para atendimento de estudantes
** Autor  : Alex Verissimo - 3-F
** Data   : 18/06/2025
** Observações: Funções para manipular deque
*/

#include <stdio.h>
#include <stdlib.h>
#include "deque_atendimento.h"

DequeAtendimento* criar_deque() {
    DequeAtendimento* d = (DequeAtendimento*) malloc(sizeof(DequeAtendimento));
    if (!d) return NULL;
    d->inicio = NULL;
    d->fim = NULL;
    return d;
}

void inserir_inicio(DequeAtendimento* d, Estudante* est) {
    if (!d || !est) return;
    NoDeque* no = (NoDeque*) malloc(sizeof(NoDeque));
    if (!no) return;
    no->est = est;
    no->ant = NULL;
    no->prox = d->inicio;
    if (d->inicio != NULL)
        d->inicio->ant = no;
    d->inicio = no;
    if (d->fim == NULL)
        d->fim = no;
}

void inserir_fim(DequeAtendimento* d, Estudante* est) {
    if (!d || !est) return;
    NoDeque* no = (NoDeque*) malloc(sizeof(NoDeque));
    if (!no) return;
    no->est = est;
    no->prox = NULL;
    no->ant = d->fim;
    if (d->fim != NULL)
        d->fim->prox = no;
    d->fim = no;
    if (d->inicio == NULL)
        d->inicio = no;
}

Estudante* remover_inicio(DequeAtendimento* d) {
    if (!d || d->inicio == NULL) return NULL;
    NoDeque* temp = d->inicio;
    d->inicio = temp->prox;
    if (d->inicio != NULL)
        d->inicio->ant = NULL;
    else
        d->fim = NULL;
    Estudante* est = temp->est;
    free(temp);
    return est;
}

Estudante* remover_fim(DequeAtendimento* d) {
    if (!d || d->fim == NULL) return NULL;
    NoDeque* temp = d->fim;
    d->fim = temp->ant;
    if (d->fim != NULL)
        d->fim->prox = NULL;
    else
        d->inicio = NULL;
    Estudante* est = temp->est;
    free(temp);
    return est;
}

int deque_vazio(DequeAtendimento* d) {
    return (d == NULL || d->inicio == NULL);
}

void imprimir_deque(DequeAtendimento* d) {
    if (!d) {
        printf("Deque nao inicializado.\n");
        return;
    }
    NoDeque* aux = d->inicio;
    if (!aux) {
        printf("Deque vazio.\n");
        return;
    }
    printf("Deque de atendimento:\n");
    while (aux) {
        printf("Matricula: %d, Nome: %s\n", aux->est->matricula, aux->est->nome);
        aux = aux->prox;
    }
}

void liberar_deque(DequeAtendimento* d) {
    if (!d) return;
    while (!deque_vazio(d)) {
        remover_inicio(d);
    }
    free(d);
}

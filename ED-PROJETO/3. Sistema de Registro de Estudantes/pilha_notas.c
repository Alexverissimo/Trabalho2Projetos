/*
** Função : Implementação da pilha para histórico de notas
** Autor  : Alex verissimo 3ºF
** Data   : 18/06/2025
** Observações: Funções para manipular pilha de notas
*/

#include <stdio.h>
#include <stdlib.h>
#include "pilha_notas.h"

PilhaNotas* criar_pilha() {
    PilhaNotas* p = (PilhaNotas*) malloc(sizeof(PilhaNotas));
    if (!p) return NULL;
    p->topo = NULL;
    return p;
}

void empilhar_notas(PilhaNotas* p, float notas[]) {
    if (!p) return;
    NoPilha* no = (NoPilha*) malloc(sizeof(NoPilha));
    if (!no) return;
    for(int i=0; i < MAX_NOTAS; i++) {
        no->notas[i] = notas[i];
    }
    no->prox = p->topo;
    p->topo = no;
}

int pilha_vazia(PilhaNotas* p) {
    return (p->topo == NULL);
}

void desempilhar_notas(PilhaNotas* p, float notas[]) {
    if (!p || pilha_vazia(p)) return;
    NoPilha* temp = p->topo;
    for(int i=0; i < MAX_NOTAS; i++) {
        notas[i] = temp->notas[i];
    }
    p->topo = temp->prox;
    free(temp);
}

void liberar_pilha(PilhaNotas* p) {
    if (!p) return;
    while(!pilha_vazia(p)) {
        float notas[MAX_NOTAS];
        desempilhar_notas(p, notas);
    }
    free(p);
}

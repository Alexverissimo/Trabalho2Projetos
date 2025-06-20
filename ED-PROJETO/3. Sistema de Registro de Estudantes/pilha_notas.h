/*
** Função : Declaração da pilha para histórico de notas
** Autor  : Alex verissimo 3ºF
** Data   : 18/06/2025
** Observações: Protótipos e estrutura da pilha
*/

#ifndef PILHA_NOTAS_H
#define PILHA_NOTAS_H

#define MAX_NOTAS 3

typedef struct NoPilha {
    float notas[MAX_NOTAS];
    struct NoPilha* prox;
} NoPilha;

typedef struct {
    NoPilha* topo;
} PilhaNotas;


PilhaNotas* criar_pilha();


void empilhar_notas(PilhaNotas* p, float notas[]);

int pilha_vazia(PilhaNotas* p);

void desempilhar_notas(PilhaNotas* p, float notas[]);

void liberar_pilha(PilhaNotas* p);

#endif

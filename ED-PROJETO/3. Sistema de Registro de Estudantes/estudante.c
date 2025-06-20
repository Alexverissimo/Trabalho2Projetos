/*
** Função : Implementação do TAD Estudante
** Autor  : Alex verissimo 3ºF
** Data   : 18/06/2025
** Observações: Implementa funções para manipulação do estudante
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estudante.h"

Estudante* criar_estudante(const char* nome, int matricula, float notas[]) {
    Estudante* e = (Estudante*) malloc(sizeof(Estudante));
    if (!e) return NULL;
    strncpy(e->nome, nome, MAX_NOME);
    e->nome[MAX_NOME - 1] = '\0'; 
    e->matricula = matricula;
    for(int i = 0; i < MAX_NOTAS; i++) {
        e->notas[i] = notas[i];
    }
    return e;
}

void destruir_estudante(Estudante* e) {
    if (e) free(e);
}

void imprimir_estudante(const Estudante* e) {
    if (!e) return;
    printf("Nome: %s\n", e->nome);
    printf("Matricula: %d\n", e->matricula);
    printf("Notas: ");
    for(int i = 0; i < MAX_NOTAS; i++) {
        printf("%.2f ", e->notas[i]);
    }
    printf("\n");
}

void atualizar_notas(Estudante* e, float novas_notas[]) {
    if (!e) return;
    for(int i = 0; i < MAX_NOTAS; i++) {
        e->notas[i] = novas_notas[i];
    }
}

float calcular_media(const Estudante* e) {
    if (!e) return 0.0;
    float soma = 0.0;
    for(int i = 0; i < MAX_NOTAS; i++) {
        soma += e->notas[i];
    }
    return soma / MAX_NOTAS;
}

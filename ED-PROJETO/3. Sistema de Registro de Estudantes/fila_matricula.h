/*
** Função : Declaração da fila para matrícula de estudantes
** Autor  : Alex verissimo 3ºF
** Data   : 18/06/2025
** Observações: Protótipos e estrutura da fila
*/

#ifndef FILA_MATRICULA_H
#define FILA_MATRICULA_H

#include "estudante.h"

typedef struct NoFila {
    Estudante* est;
    struct NoFila* prox;
} NoFila;

typedef struct {
    NoFila* inicio;
    NoFila* fim;
} FilaMatricula;

FilaMatricula* criar_fila();

void enfileirar(FilaMatricula* fila, Estudante* est);

Estudante* desenfileirar(FilaMatricula* fila);


int fila_vazia(FilaMatricula* fila);


void imprimir_fila(FilaMatricula* fila);

/
void liberar_fila(FilaMatricula* fila);

#endif

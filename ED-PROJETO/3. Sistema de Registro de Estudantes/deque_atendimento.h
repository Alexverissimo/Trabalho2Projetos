/*
** Função : Declaração do deque para atendimento de estudantes
** Autor  : Alex Verissimo - 3-F
** Data   : 18/06/2025
** Observações: Protótipos e estrutura do deque
*/

#ifndef DEQUE_ATENDIMENTO_H
#define DEQUE_ATENDIMENTO_H

#include "estudante.h"

typedef struct NoDeque {
    Estudante* est;
    struct NoDeque* prox;
    struct NoDeque* ant;
} NoDeque;

typedef struct {
    NoDeque* inicio;
    NoDeque* fim;
} DequeAtendimento;

DequeAtendimento* criar_deque();

void inserir_inicio(DequeAtendimento* d, Estudante* est);

void inserir_fim(DequeAtendimento* d, Estudante* est);

Estudante* remover_inicio(DequeAtendimento* d);

Estudante* remover_fim(DequeAtendimento* d);

int deque_vazio(DequeAtendimento* d);

void imprimir_deque(DequeAtendimento* d);

void liberar_deque(DequeAtendimento* d);

#endif

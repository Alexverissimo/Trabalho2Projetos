/*
** Função : Declaração da lista encadeada de Estudantes
** Autor  : Alex verissimo 3ºF
** Data   : 18/06/2025
** Observações: Protótipos e estrutura para lista encadeada
*/

#ifndef LISTA_ESTUDANTE_H
#define LISTA_ESTUDANTE_H

#include "estudante.h"

typedef struct NoLista {
    Estudante* est;
    struct NoLista* prox;
} NoLista;

typedef struct {
    NoLista* inicio;
} ListaEstudante;

ListaEstudante* criar_lista();

void inserir_estudante(ListaEstudante* lista, Estudante* est);

NoLista* buscar_estudante(ListaEstudante* lista, int matricula);

void remover_estudante(ListaEstudante* lista, int matricula);

void imprimir_lista(ListaEstudante* lista);


void liberar_lista(ListaEstudante* lista);

#endif

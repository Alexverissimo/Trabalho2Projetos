/*
** Função : Implementação da lista encadeada de Estudantes
** Autor  : Alex verissimo 3ºF
** Data   : 18/06/2025
** Observações: Funções para manipulação da lista
*/

#include <stdio.h>
#include <stdlib.h>
#include "lista_estudante.h"

ListaEstudante* criar_lista() {
    ListaEstudante* lista = (ListaEstudante*) malloc(sizeof(ListaEstudante));
    if (!lista) return NULL;
    lista->inicio = NULL;
    return lista;
}

void inserir_estudante(ListaEstudante* lista, Estudante* est) {
    if (!lista || !est) return;
    NoLista* no = (NoLista*) malloc(sizeof(NoLista));
    if (!no) return;
    no->est = est;
    no->prox = lista->inicio;
    lista->inicio = no;
}

NoLista* buscar_estudante(ListaEstudante* lista, int matricula) {
    if (!lista) return NULL;
    NoLista* aux = lista->inicio;
    while(aux) {
        if(aux->est->matricula == matricula) return aux;
        aux = aux->prox;
    }
    return NULL;
}

void remover_estudante(ListaEstudante* lista, int matricula) {
    if (!lista) return;
    NoLista* aux = lista->inicio;
    NoLista* ant = NULL;
    while(aux) {
        if(aux->est->matricula == matricula) {
            if(ant) ant->prox = aux->prox;
            else lista->inicio = aux->prox;
            
            free(aux->est);
            free(aux);
            printf("Estudante removido.\n");
            return;
        }
        ant = aux;
        aux = aux->prox;
    }
    printf("Estudante nao encontrado.\n");
}

void imprimir_lista(ListaEstudante* lista) {
    if (!lista) {
        printf("Lista nao inicializada.\n");
        return;
    }
    NoLista* aux = lista->inicio;
    if (!aux) {
        printf("Lista vazia.\n");
        return;
    }
    while(aux) {
        imprimir_estudante(aux->est);
        printf("----------------------\n");
        aux = aux->prox;
    }
}

void liberar_lista(ListaEstudante* lista) {
    if (!lista) return;
    NoLista* aux = lista->inicio;
    while(aux) {
        NoLista* temp = aux;
        aux = aux->prox;
        destruir_estudante(temp->est);
        free(temp);
    }
    free(lista);
}

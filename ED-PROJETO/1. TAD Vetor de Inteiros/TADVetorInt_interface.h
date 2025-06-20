/*
** Função : Interface do TAD Vetor de Inteiros
** Autor  : Alex verissimo 3ºF
** Data   : 13/06/2025
** Observações: Definição das funções do TAD para manipulação dinâmica de vetor de inteiros
*/

#ifndef TADVETORINT_INTERFACE_H
#define TADVETORINT_INTERFACE_H

typedef struct VetorInt VetorInt;

VetorInt* criaVetor(int capacidade);
void insereElemento(VetorInt* v, int elemento);
void removeElemento(VetorInt* v, int elemento);
int consultaElemento(VetorInt* v, int posicao);
void imprimeVetor(VetorInt* v);
void destroiVetor(VetorInt* v);

#endif

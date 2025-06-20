/*
** Função : Programa de teste para o TAD Vetor de Inteiros
** Autor  : Alex verissimo 3ºF
** Data   : 13/06/2025
** Observações: Testa criação, inserção, remoção, consulta, impressão e destruição do vetor
*/

#include <stdio.h>
#include "TADVetorInt_interface.h"

int main() {
    VetorInt* v = criaVetor(5);

    insereElemento(v, 10);
    insereElemento(v, 20);
    insereElemento(v, 30);
    insereElemento(v, 40);
    insereElemento(v, 50);

    imprimeVetor(v);

    printf("Elemento na posicao 2: %d\n", consultaElemento(v, 2));

    removeElemento(v, 30);
    imprimeVetor(v);

    removeElemento(v, 100); 

    destroiVetor(v);

    return 0;
}

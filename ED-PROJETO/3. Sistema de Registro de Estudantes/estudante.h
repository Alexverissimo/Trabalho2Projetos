/*
** Função : Declaração do TAD Estudante
** Autor  : Alex verissimo 3ºF
** Data   : 18/06/2025
** Observações: Cabeçalho com estrutura e protótipos das funções
*/

#ifndef ESTUDANTE_H
#define ESTUDANTE_H

#define MAX_NOTAS 3
#define MAX_NOME 50

typedef struct {
    char nome[MAX_NOME];
    int matricula;
    float notas[MAX_NOTAS];
} Estudante;


Estudante* criar_estudante(const char* nome, int matricula, float notas[]);


void destruir_estudante(Estudante* e);

void imprimir_estudante(const Estudante* e);

void atualizar_notas(Estudante* e, float novas_notas[]);

float calcular_media(const Estudante* e);

#endif

/*
** Função : Interface do Sistema de Agendamento de Consultas
** Autor  : Alex verissimo 3ºF
** Data   : 13/06/2025
*/

#ifndef SISTEMAAGENDAMENTO_INTERFACE_H
#define SISTEMAAGENDAMENTO_INTERFACE_H

#define MAX_MEDICO 5
#define NOME_MAX 100

typedef struct {
    char nomePaciente[NOME_MAX];
    char dataHora[20];
} Consulta;

typedef struct {
    Consulta filaMedico[MAX_MEDICO];
    int inicioMedico;
    int fimMedico;
    int qtdMedico;
} FilaMedico;

typedef struct NodoEnfermagem {
    Consulta consulta;
    struct NodoEnfermagem* prox;
} NodoEnfermagem;

typedef struct {
    NodoEnfermagem* inicioEnfermagem;
    NodoEnfermagem* fimEnfermagem;
} FilaEnfermagem;

void inicializaFilaMedico(FilaMedico* f);
int enfileiraMedico(FilaMedico* f, Consulta c);
int desenfileiraMedico(FilaMedico* f, Consulta* c);
void imprimeFilaMedico(FilaMedico* f);

void inicializaFilaEnfermagem(FilaEnfermagem* f);
int enfileiraEnfermagem(FilaEnfermagem* f, Consulta c);
int desenfileiraEnfermagem(FilaEnfermagem* f, Consulta* c);
void imprimeFilaEnfermagem(FilaEnfermagem* f);
void liberaFilaEnfermagem(FilaEnfermagem* f);

#endif

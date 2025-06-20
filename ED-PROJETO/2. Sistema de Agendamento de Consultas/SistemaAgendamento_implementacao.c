/*
** Função : Implementação do Sistema de Agendamento de Consultas
** Autor  : Alex verissimo 3 ºF
** Data   : 13/06/2025
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SistemaAgendamento_interface.h"

void inicializaFilaMedico(FilaMedico* f) {
    f->inicioMedico = 0;
    f->fimMedico = -1;
    f->qtdMedico = 0;
}

int enfileiraMedico(FilaMedico* f, Consulta c) {
    if (f->qtdMedico == MAX_MEDICO) {
        return 0;
    }
    f->fimMedico = (f->fimMedico + 1) % MAX_MEDICO;
    f->filaMedico[f->fimMedico] = c;
    f->qtdMedico++;
    return 1;
}

int desenfileiraMedico(FilaMedico* f, Consulta* c) {
    if (f->qtdMedico == 0) {
        return 0;
    }
    *c = f->filaMedico[f->inicioMedico];
    f->inicioMedico = (f->inicioMedico + 1) % MAX_MEDICO;
    f->qtdMedico--;
    return 1;
}

void imprimeFilaMedico(FilaMedico* f) {
    printf("Fila de medico (%d pacientes):\n", f->qtdMedico);
    for (int i = 0, idx = f->inicioMedico; i < f->qtdMedico; i++) {
        Consulta c = f->filaMedico[idx];
        printf("Paciente: %s, Data/Hora: %s\n", c.nomePaciente, c.dataHora);
        idx = (idx + 1) % MAX_MEDICO;
    }
}

void inicializaFilaEnfermagem(FilaEnfermagem* f) {
    f->inicioEnfermagem = NULL;
    f->fimEnfermagem = NULL;
}

int enfileiraEnfermagem(FilaEnfermagem* f, Consulta c) {
    NodoEnfermagem* novo = (NodoEnfermagem*) malloc(sizeof(NodoEnfermagem));
    if (!novo) return 0;
    novo->consulta = c;
    novo->prox = NULL;
    if (f->fimEnfermagem == NULL) {
        f->inicioEnfermagem = novo;
    } else {
        f->fimEnfermagem->prox = novo;
    }
    f->fimEnfermagem = novo;
    return 1;
}

int desenfileiraEnfermagem(FilaEnfermagem* f, Consulta* c) {
    if (f->inicioEnfermagem == NULL) {
        return 0;
    }
    NodoEnfermagem* aux = f->inicioEnfermagem;
    *c = aux->consulta;
    f->inicioEnfermagem = aux->prox;
    if (f->inicioEnfermagem == NULL) {
        f->fimEnfermagem = NULL;
    }
    free(aux);
    return 1;
}

void imprimeFilaEnfermagem(FilaEnfermagem* f) {
    printf("Fila de enfermagem:\n");
    NodoEnfermagem* aux = f->inicioEnfermagem;
    int cont = 0;
    while (aux != NULL) {
        printf("Paciente: %s, Data/Hora: %s\n", aux->consulta.nomePaciente, aux->consulta.dataHora);
        aux = aux->prox;
        cont++;
    }
    if (cont == 0) {
        printf("Nenhum agendamento.\n");
    }
}

void liberaFilaEnfermagem(FilaEnfermagem* f) {
    NodoEnfermagem* aux = f->inicioEnfermagem;
    while (aux != NULL) {
        NodoEnfermagem* tmp = aux;
        aux = aux->prox;
        free(tmp);
    }
    f->inicioEnfermagem = NULL;
    f->fimEnfermagem = NULL;
}

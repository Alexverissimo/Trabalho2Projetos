/*
** Função : Programa de teste do Sistema de Agendamento de Consultas
** Autor  : Alex verissimo 3ºF
** Data   : 13/06/2025
*/

#include <stdio.h>
#include <string.h>
#include "SistemaAgendamento_interface.h"

void agendarMedico(FilaMedico* f) {
    if (f->qtdMedico == MAX_MEDICO) {
        printf("Limite de agendamentos com medico atingido.\n");
        return;
    }
    Consulta c;
    printf("Nome do paciente (medico): ");
    fgets(c.nomePaciente, NOME_MAX, stdin);
    c.nomePaciente[strcspn(c.nomePaciente, "\n")] = '\0';
    printf("Data e hora: ");
    fgets(c.dataHora, 20, stdin);
    c.dataHora[strcspn(c.dataHora, "\n")] = '\0';
    if (enfileiraMedico(f, c)) {
        printf("Agendamento realizado com sucesso!\n");
    } else {
        printf("Erro ao agendar.\n");
    }
}

void agendarEnfermagem(FilaEnfermagem* f) {
    Consulta c;
    printf("Nome do paciente (enfermagem): ");
    fgets(c.nomePaciente, NOME_MAX, stdin);
    c.nomePaciente[strcspn(c.nomePaciente, "\n")] = '\0';
    printf("Data e hora: ");
    fgets(c.dataHora, 20, stdin);
    c.dataHora[strcspn(c.dataHora, "\n")] = '\0';
    if (enfileiraEnfermagem(f, c)) {
        printf("Agendamento realizado com sucesso!\n");
    } else {
        printf("Erro ao agendar.\n");
    }
}

int main() {
    FilaMedico fMedico;
    FilaEnfermagem fEnfermagem;
    int opc;

    inicializaFilaMedico(&fMedico);
    inicializaFilaEnfermagem(&fEnfermagem);

    do {
        printf("\n--- Sistema de Agendamento ---\n");
        printf("1 - Agendar consulta com medico\n");
        printf("2 - Agendar consulta com enfermagem\n");
        printf("3 - Mostrar agendamentos medico\n");
        printf("4 - Mostrar agendamentos enfermagem\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d%*c", &opc);

        switch (opc) {
            case 1: agendarMedico(&fMedico); break;
            case 2: agendarEnfermagem(&fEnfermagem); break;
            case 3: imprimeFilaMedico(&fMedico); break;
            case 4: imprimeFilaEnfermagem(&fEnfermagem); break;
            case 0: printf("Saindo...\n"); break;
            default: printf("Opcao invalida!\n");
        }
    } while (opc != 0);

    liberaFilaEnfermagem(&fEnfermagem);
    return 0;
}

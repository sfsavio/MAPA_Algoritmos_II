#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define MAX 10

struct Ingresso {
    char name[30];
    char date[12];
    char id[11];
};

void iniciar_venda (struct Ingresso *tickets[], int *count) {
    system("cls");
    if (*count >= MAX) {
        printf("Ingressos esgotados\n");
        return;
    }

    tickets[*count] = (struct Ingresso *)malloc(sizeof(struct Ingresso));
    if (tickets[*count] == NULL) {
        printf("Erro ao alocar memória!\n");
        return;
    }

    printf("Nome: ");
    scanf(" %[^\n]s", tickets[*count]->name);

    printf("Data de nascimento (dd/mm/aa): ");
    scanf(" %[^\n]s", tickets[*count]->date);

    printf("CPF: ");
    scanf(" %[^\n]s", tickets[*count]->id);
    system("cls");

    (*count)++;

    printf("\n\tIngresso vendido com sucesso!\n\n");
    printf("--------------------------------------------------\n");
}

void listar_ingressos(struct Ingresso *tickets[], int count) {
    system("cls");
    if (count == 0) {
        printf("Nenhum ingresso vendido ainda.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        printf("\tNome.....................  %s\n", tickets[i]->name);
        printf("\tCPF......................  %s\n", tickets[i]->id);
        printf("\tAno de Nascimento........  %s\n", tickets[i]->date);
        printf("------------------------------------------------------------------------------\n");
    }
}

void validar_ingresso(struct Ingresso *tickets[], int count) {
    system("cls");
    if (count == 0) {
        printf("Nenhum ingresso vendido ainda.\n");
        printf("\n");
        return;
    }

    char id[11];
    printf("Digite o CPF do ingresso para checar: ");
    scanf(" %[^\n]s", id);
    system("cls");
    for (int i = 0; i < count; i++) {
        if (strcmp(tickets[i]->id, id) == 0) {
            printf("\n\tIngresso existe, CPF pertece à:  %s\n\n", tickets[i]->name);
            printf("------------------------------------------------------------------------------\n");
            return;
        }
    }

    printf("Ingresso não encontrado.\n");

}

void imprimir_menu (struct Ingresso *tickets[], int *count) {
    system("cls");
    int op;
    do {
        printf(" | Menu:\n | 1. Vender \n | 2. Listar \n | 3. Validar \n | 4. Sair\n -------------\n");
        scanf("%d", &op);
        switch (op) {
        case 1:
            iniciar_venda(tickets, count);
            break;
        case 2:
            listar_ingressos(tickets, *count);
            break;
        case 3:
            validar_ingresso(tickets, *count);
            break;
        case 4:
            system("cls");
            printf("Saindo...\n.\n.\n.\n.\n.");
            break;
        default:
            printf("Selecione uma opção existente!\n");
        }
    } while (op != 4);
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    struct Ingresso *tickets[MAX];
    int count = 0;

    imprimir_menu(tickets, &count);


    for (int i = 0; i < count; i++) {
        free(tickets[i]);
    }

    return 0;
}

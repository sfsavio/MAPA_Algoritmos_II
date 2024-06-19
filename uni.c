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


void start_sell(struct Ingresso *tickets[], int *count) {
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

    (*count)++;

    printf("Ingresso vendido com sucesso!\n\n");
    printf("--------------------------------------------------\n");
}


void listar_ingressos(struct Ingresso *tickets[], int count) {
    system("cls");
    if (count == 0) {
        printf("Nenhum ingresso vendido ainda.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        printf("Nome.....................  %s\n", tickets[i]->name);
        printf("CPF......................  %s\n", tickets[i]->id);
        printf("Ano de Nascimento........  %s\n", tickets[i]->date);
        printf("----------------------------------------------------\n");
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

    for (int i = 0; i < count; i++) {
        if (strcmp(tickets[i]->id, id) == 0) {
            printf("Ingresso existe em nome de:  %s\n\n\n", tickets[i]->name);
            return;
        }
    }

    printf("Ingresso não encontrado.\n");
}


void show_menu(struct Ingresso *tickets[], int *count) {
    system("cls");
    int op;
    do {
        printf(" Menu:\n 1. Vender \n 2. Listar \n 3. Validar \n 4. Sair\n");
        scanf("%d", &op);
        switch (op) {
        case 1:
            start_sell(tickets, count);
            break;
        case 2:
            listar_ingressos(tickets, *count);
            break;
        case 3:
            validar_ingresso(tickets, *count);
            break;
        case 4:
            printf("Saindo...\n");
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

    show_menu(tickets, &count);


    for (int i = 0; i < count; i++) {
        free(tickets[i]);
    }

    return 0;
}

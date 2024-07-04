// Repositório com o código no github
// Ele está documentado
// https://github.com/sfsavio/MAPA_Algoritmos_II
// https://github.com/sfsavio/MAPA_Algoritmos_II

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <unistd.h> // to use sleep()

#define MAX 100

struct Ingresso
{
    char name[30];
    char date[12];
    char id[11];
};

void iniciar_venda (struct Ingresso *tickets[], int *count)
{
    system("cls");
    if (*count >= MAX)
    {
        printf("\n");
        printf("\tIngressos esgotados!!!\n");
        printf("\n\n==============================================\n\n");
        return;
    }

    tickets[*count] = (struct Ingresso *)malloc(sizeof(struct Ingresso)); // memory allocation
    if (tickets[*count] == NULL)
    {
        printf("Erro ao alocar novo ingresso na memória!\n");
        return;
    }

    printf("Nome: ");
    scanf(" %[^\n]s", tickets[*count]->name);

    printf("Ano de Nascimento: ");
    scanf(" %[^\n]s", tickets[*count]->date);

    printf("CPF: ");
    scanf(" %[^\n]s", tickets[*count]->id);
    system("cls");

    (*count)++;

    printf("\n\tIngresso vendido com sucesso!\n\n");
    printf("\n==============================================\n\n");
}

void listar_ingressos(struct Ingresso *tickets[], int count)
{
    system("cls");
    printf("\n");
    if (count == 0)
    {
        printf("Nenhum ingresso vendido ainda.\n");
        return;
    }

    for (int i = 0; i < count; i++)
    {
        printf("\tNome.....................  %s\n", strupr (tickets[i]->name)); // uppercase strupr(string);
        printf("\tCPF......................  %s\n", tickets[i]->id);
        printf("\tAno de Nascimento........  %s\n", tickets[i]->date);
        printf("\n==============================================\n\n");
    }
}

void validar_ingresso(struct Ingresso *tickets[], int count)
{
    system("cls");
    if (count == 0)
    {
        printf("Nenhum ingresso vendido ainda.\n");
        printf("\n");
        return;
    }

    char id[11];
    printf("Digite o CPF do ingresso para checar: ");
    scanf(" %[^\n]s", id);
    system("cls");
    for (int i = 0; i < count; i++)
    {
        if (strcmp(tickets[i]->id, id) == 0)
        {
            printf("\n\tIngresso existe, pertece à:  %s\n\n", strupr(tickets[i]->name));
            printf("\n==============================================\n\n");
            return;
        }
    }

    printf(".", sleep(1));
    printf(".", sleep(1));
    printf("."), sleep(1);
    system("cls");
    printf(".", sleep(1));
    printf(".", sleep(1));
    printf(".", sleep(1));
    printf("\nNâo encontrado.\n\n", sleep(1));

}

void imprimir_menu (struct Ingresso *tickets[], int *count)
{
    system("cls");
    int op;
    do
    {
        printf(" | Menu:\n | 1. Vender \n | 2. Listar \n | 3. Validar \n | 4. Sair\n -------------\n --> ");
        scanf("%d", &op);
        switch (op)
        {
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

            printf ("\nMeu perfil do github: https://github.com/sfsavio/MAPA_Algoritmos_II");
            sleep(3);
            printf("\nSaindo...");
            printf("\n\t0------------------------------100\n\t");
            for (int g = 0; g<17; g++)
            {

                printf("==");
                sleep(1);
            }


            break;
        default:
            printf("Selecione uma opção existente!\n");
        }
    }
    while (op != 4);
}

int main()
{
    system("color a");
    setlocale(LC_ALL, "Portuguese");
    printf("Iniciando:\n\t0------------------------------100\n\t");
    for (int g = 0; g<17; g++)
    {
        printf("==");
        sleep(1);
    }
    system("cls");
    printf("\n\n\t\t\tPROGRAMA INICIADO");

    sleep(3);
    system("cls");


    struct Ingresso *tickets[MAX];
    int count = 0;

    imprimir_menu(tickets, &count);


    for (int i = 0; i < count; i++)
    {
        free(tickets[i]);
    }

    return 0;
}

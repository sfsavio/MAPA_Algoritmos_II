# MAPA - ALGORITMOS E LÓGICA DE PROGRAMAÇÃO II - 52_2024
> Programa desenvolvido em C para a materia do curso de Engenharia de Software. Tem como objetivo Vender, Listar e Validar ingressos/tickets. 

## Bibliotecas Incluídas

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

// stdio.h:  Biblioteca padrão de entrada e saída de dados.
// stdlib.h: Biblioteca padrão que inclui funções para alocação de memória, controle de processos, conversões e outras.
// string.h: Biblioteca para manipulação de strings.
// locale.h: Biblioteca para permitir a utilização de caracteres especiais.
```
## Constante MAX

```c
#define MAX 10

// Define o máximo de ingressos a serem vendidos.
```

## Declaração da "Struct Ingresso"
```c
struct Ingresso {
    char name[30];
    char date[11];
    char id[10];
    };
```

> Contém as variáveis presentes no objeto.


## Funções implementadas
### iniciar_venda () <br></br> 
A função iniciar_venda gerencia a venda de um ingresso no sistema. Ela aloca memória dinamicamente para armazenar as informações do ingresso e utiliza ponteiros para manipular e acessar esses dados de forma eficiente. 
```c
// cabeçalho da função
void iniciar_venda(struct Ingresso *tickets[], int *count);
```
> Recebe o struct e o contador como parâmetros.

1. Parâmetros
> ```struct Ingresso *tickets[]```: Array de ponteiros para a estrutura Ingresso. Este array armazena os ponteiros para cada ingresso vendido.
> ```*int count```: Ponteiro para um inteiro que mantém o número atual de ingressos vendidos. Esse valor é atualizado conforme novos ingressos são vendidos.
2. Funcionamento
> Verifica se o limite de ingressos já foi atendido.
```c
if (*count >= MAX) {
printf("Ingressos esgotados\n");
return;
} 
```
> Checa se o limite de ingressos definidos pela ```#define MAX n ``` foi atingido.

> ```*count``` é o valor apontado pelo ponteiro count. Se o número de ingressos vendidos (*count) for maior ou igual ao máximo permitido (MAX), a função imprime "Ingressos esgotados" e retorna, não permitindo a venda de mais ingressos.

3. Alocação de maneira dinâmica na memória
```c
tickets[*count] = (struct Ingresso *)malloc(sizeof(struct Ingresso));
if (tickets[*count] == NULL) {
    printf("Erro ao alocar memória!\n");
    return;
}
```
> A função aloca memória dinamicamente para um novo ingresso usando ```malloc```.
> ```tickets[*count]``` é um **ponteiro** que aponta para a nova estrutura Ingresso alocada.
> Se a alocação de memória falhar (ou seja, malloc retorna NULL), a função imprime "Erro ao alocar memória!" e retorna.

> [!NOTE] 
> ```malloc``` é uma função da biblioteca padrão do C que aloca dinamicamente um bloco de memória durante a execução do programa. O nome **malloc** é uma abreviação de "memory allocation" (alocação de memória).
> A função ```malloc``` é amplamente usada quando a quantidade de memória necessária não é conhecida em tempo de compilação e precisa ser determinada em tempo de execução. Isso é comum em situações como alocação de arrays de tamanho variável, estruturas de dados dinâmicas, etc.<br></br>
#### Incremento do contador para definir o número de objetos criados
```c
(*count)++;
```
<hr></hr>

### listar_ingressos ()  
> Exibir todos os ingressos vendidos 

 ```c
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
```

Assinatura da função ```void listar_ingressos(struct Ingresso *tickets[], int count);```

Uso de Ponteiros
Manipulação de Arrays de Estruturas com Ponteiros

    struct Ingresso *tickets[]: Um array de ponteiros é usado para armazenar os ingressos vendidos. Cada elemento do array tickets é um ponteiro para uma estrutura Ingresso.
    Isso permite acessar diretamente as informações dos ingressos usando os ponteiros armazenados no array.

Acesso a Campos da Estrutura

    tickets[i]->name: O operador -> é utilizado para acessar os membros da estrutura apontada por tickets[i]. Isso é necessário porque tickets[i] é um ponteiro para uma estrutura Ingresso.

<hr></hr>

### validar_ingresso ()
> A função ```validar_ingresso()``` verifica se um ingresso com um determinado CPF existe no sistema.
1. Parâmetros
```c
   void validar_ingresso(struct Ingresso *tickets[], int count);
```
> struct Ingresso *tickets[]: Array de ponteiros para a estrutura Ingresso. Este array contém os ponteiros para cada ingresso vendido.
> int count: Número de ingressos vendidos. Este valor é utilizado para controlar a iteração sobre o array de ingressos.

2. Funcionamento
> A função verifica se há ingressos vendidos verificando se ```count``` é igual a 0.

```c
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
```
>[!NOTE]
> ```strcmp(tickets[i]->id, id) == 0```: A função ```strcmp``` é usada para comparar duas strings.

<hr></hr>

### imprimir_menu
> Essa função realiza a impressão do menu para o usuário e faz a chamada das funções de acordo com a escolha do mesmo.

```c
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
        }
    while (op != 4);
    }

```
Parâmetros
```c
   void validar_ingresso(struct Ingresso *tickets[], int count);
```

## Main
> Ponto de partida do programa.
```c
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

```

>[!TIP]
> ```setlocale(LC_ALL, "Portuguese")```  configura a localidade para permitir a exibição de caracteres específicos da língua portuguesa, como acentos e cedilha.

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
### Constante MAX

```c
#define MAX 10

// Define o máximo de ingressos a serem vendidos.
```

### Declaração da "Struct Ingresso"
```c
struct Ingresso {
    char name[30];
    char date[11];
    char id[10];
    };
```

> Contém as variáveis presentes no objeto.


## Funções implementadas
 ```iniciar_venda ( ) ``` <br></br> 
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
> A função ```malloc``` é amplamente usada quando a quantidade de memória necessária não é conhecida em tempo de compilação e precisa ser determinada em tempo de execução. Isso é comum em situações como alocação de arrays de tamanho variável, estruturas de dados dinâmicas, etc.

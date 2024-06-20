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
#### iniciar_venda ( ) 
A função iniciar_venda gerencia a venda de um ingresso no sistema. Ela aloca memória dinamicamente para armazenar as informações do ingresso e utiliza ponteiros para manipular e acessar esses dados de forma eficiente. 
```c
// cabeçalho da função
void iniciar_venda(struct Ingresso *tickets[], int *count);
```
> Recebe o struct e o contador como parâmetros.

1. Parâmetros
   + struct Ingresso *tickets[]: Array de ponteiros para a estrutura Ingresso. Este array armazena os ponteiros para cada ingresso vendido.
   + 

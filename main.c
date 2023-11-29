#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

// Função para trocar os valores apontados pelos ponteiros
void trocar(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Função para escolher o elemento pivô e reajar a matriz, mantendo os valores menores que o pivô a sua esquerda, e os maiores a sua direita até ordenar toda a matriz
int particionar(int **matriz, int inicio, int fim)
{
    int pivo = matriz[1][fim];
    int i = (inicio - 1);
    int j;

    for (j = inicio; j <= fim - 1; j++)
    {
        if (matriz[1][j] < pivo)
        {
            i++;
            trocar(&matriz[1][i], &matriz[1][j]);
            trocar(&matriz[0][i], &matriz[0][j]);
        }
    }
    trocar(&matriz[1][i + 1], &matriz[1][fim]);
    trocar(&matriz[0][i + 1], &matriz[0][fim]);
    return (i + 1);
}

void quickSort(int **matriz, int inicio, int fim)
{
    if (inicio < fim)
    {
        int pi = particionar(matriz, inicio, fim);

        quickSort(matriz, inicio, pi - 1);
        quickSort(matriz, pi + 1, fim);
    }
}

// Função para sortear os números das equipes
void sortearEquipes(int n)
{

    int **matriz;
    matriz = (int **)malloc(2 * sizeof(int *));
    matriz[0] = (int *)malloc(n * sizeof(int));
    matriz[1] = (int *)malloc(n * sizeof(int));

    int i, j, numero_sorteado;

    // Inicializa a matriz com os números das equipes
    for (i = 0; i < n; i++)
    {
        matriz[0][i] = i + 1;
        matriz[1][i] = 0; // Garantir
    }

    for (i = 0; i < n; i++)
    {
        int se_repetir;

        do
        {
            se_repetir = 0;

            // Sorteia um número no intervalo de 1 até o número digitado pelo usuário
            numero_sorteado = rand() % n + 1;

            for (j = 0; j < i; j++)
            {
                // Verifica número sorteado está sendo repetido
                if (numero_sorteado == matriz[1][j])
                {
                    se_repetir = 1;
                    break;
                }
            }
        } while (se_repetir != 0);

        // Guarda na matriz os valores sorteados não repetidos
        matriz[1][i] = numero_sorteado;
    }

    // PARTE DEMONSTRATIVA: ANTES DA ORDENAÇÃO
    // printf("\n");
    // for (i = 0; i < 2; i++) {
    //     for (j = 0; j < n; j++) {
    //         printf("%d ", matriz[i][j]);
    //     }
    //     printf("\n");
    // }

    // Chama a função de ordenação passando a matriz e a quantidade de equipes(n)
    quickSort(matriz, 0, n - 1);

    // Mostra a ordem sorteada
    printf("\n---------------------------------------------------------------------------\n\n");
    printf("ORDEM SORTEADA: \n\n");
    for (i = 0; i < n; i++)
    {
        printf("%dª equipe sorteada é: %d\n", i + 1, matriz[0][i]);
    }

    // PARTE DEMONSTRATIVA: APÓS A ORDENAÇÃO
    // printf("\n");
    // for (i = 0; i < 2; i++) {
    //     for (j = 0; j < n; j++) {
    //         printf("%d ", matriz[i][j]);
    //     }
    //     printf("\n");
    // }

    printf("\n---------------------------------------------------------------------------");
}

int main()
{

    // Define a localidade para exibição correta de caracteres especiais no idioma
    setlocale(LC_ALL, "Portuguese_Brazil.1252");

    // Inicializa a semente do gerador de números aleatórios (rand) com o tempo atual
    srand(time(NULL));

    // Inicializa o programa dando boas vindas ao usuário
    printf("\n\n------- Olá, usuário! Seja bem vindo ao nosso SORTEADOR DE EQUIPES! -------");

    // Variável usada para verificar a escolha do usuário: 1 para sortear e 2 para sair do programa
    int escolha;
    int quantidade_equipes;

    do
    {
        // Mostra ao usuário as opções e solicita que digite o número da opção desejada
        printf("\n\nDigite a opção desejada: \n\n1 - Sortear equipes; \n2 - Sair do programa.\n\n");
        scanf("%d", &escolha);

        // Verifica a escolha do usuário e toma decisões a partir disso
        switch (escolha)
        {
        // Caso queira sortear números
        case 1:            
            do
            {
                printf("\n\n---------------------------------------------------------------------------\n\n");
                printf("Digite a quantidade de equipes que deseja sortear: ");
                scanf("%d", &quantidade_equipes);

                if (quantidade_equipes <= 0) {
                    printf("\n\nValor não aceito! Tente novamente!\n\n");
                }                

                // Chamaa a função que sorteia as equipes
                sortearEquipes(quantidade_equipes);
            } while (quantidade_equipes <= 0);
            break;

        // Caso queira finalizar o programa, mostra a mensagem de FIM DO PROGRAMA
        case 2:
            printf("\n\n----------------------------- FIM DO PROGRAMA -----------------------------\n\n");
            break;

        // Em um caso onde o usuário digite um número que não está entre as opções, mostra o erro
        default:
            printf("\n---------------------------- Tente novamente! -----------------------------");
            break;
        }
    } while (escolha != 2);
    
}

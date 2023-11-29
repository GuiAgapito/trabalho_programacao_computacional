#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <ctype.h>

// Função para trocar valores de duas variáveis usando ponteiros
void trocar(int *a, int *b)
{
  int temp = *a; // Armazena o valor de 'a' temporariamente em 'temp'
  *a = *b;       // Atribui o valor de 'b' a 'a'
  *b = temp;     // Atribui o valor armazenado em 'temp' a 'b'
}

// Função que particiona a matriz para o algoritmo QuickSort
int particionar(int **matriz, int inicio, int fim)
{
  int pivo = matriz[1][fim]; // Define o último elemento como pivô
  int i = (inicio - 1);      // Inicializa o índice do menor elemento

  for (int j = inicio; j <= fim - 1; j++)
  {
    if (matriz[1][j] < pivo)
    {
      i++;                                  // Incrementa o índice do menor elemento
      trocar(&matriz[1][i], &matriz[1][j]); // Troca os elementos das equipes
      trocar(&matriz[0][i], &matriz[0][j]); // Troca os números das equipes correspondentes
    }
  }
  trocar(&matriz[1][i + 1], &matriz[1][fim]); // Coloca o pivô na posição correta
  trocar(&matriz[0][i + 1], &matriz[0][fim]); // Coloca o número da equipe correspondente na posição correta
  return (i + 1);                             // Retorna o índice do pivô
}

// Algoritmo QuickSort recursivo para ordenar as equipes
void quickSort(int **matriz, int inicio, int fim)
{
  if (inicio < fim)
  {
    int pi = particionar(matriz, inicio, fim);

    quickSort(matriz, inicio, pi - 1); // Ordena os elementos antes do pivô
    quickSort(matriz, pi + 1, fim);    // Ordena os elementos após o pivô
  }
}

// Função para sortear os números das equipes
void sortearEquipes(int n)
{
  int **matriz;                               // Declara uma matriz de ponteiros
  matriz = (int **)malloc(2 * sizeof(int *)); // Aloca memória para dois ponteiros na matriz
  matriz[0] = (int *)malloc(n * sizeof(int)); // Aloca memória para armazenar os números das equipes
  matriz[1] = (int *)malloc(n * sizeof(int)); // Aloca memória para armazenar os números sorteados

  int t, i, j, numero_sorteado;

  // Inicializa a matriz com os números das equipes
  for (i = 0; i < n; i++)
  {
    matriz[0][i] = i + 1; // Número da equipe
    matriz[1][i] = 0;     // Valor inicial para garantir integridade
  }

  // Sorteio dos números das equipes sem repetição
  for (i = 0; i < n; i++)
  {
    int se_repetir;

    do
    {
      se_repetir = 0;
      numero_sorteado = rand() % n + 1;

      // Verifica se o número já foi sorteado
      for (j = 0; j < i; j++)
      {
        if (numero_sorteado == matriz[1][j])
        {
          se_repetir = 1;
          break;
        }
      }
      matriz[1][i] = numero_sorteado; // Atribui o número sorteado à equipe
    } while (se_repetir != 0);
  }

  t = clock(); //armazena tempo
  quickSort(matriz, 0, n - 1); // Chama o algoritmo QuickSort para ordenar as equipes
  t = clock() - t; //tempo final - tempo inicial

   
  // Exibição da ordem sorteada das equipes
  printf("\n---------------------------------------------------------------------------\n\n");
  printf("ORDEM SORTEADA: \n\n");
  for (i = 0; i < n; i++)
  {
    printf("%dª equipe sorteada é: %d\n", i + 1, matriz[0][i]);
  }
  printf("\n---------------------------------------------------------------------------\n");
  printf("Tempo de execução do algoritmo QuickSort: %lf em milissegundos", ((double)t)/((CLOCKS_PER_SEC)));
}

int main()
{
  setlocale(LC_ALL, "Portuguese_Brazil.1252");
  srand(time(NULL)); // Inicializa a semente do gerador de números aleatórios
  printf("\n\n------- Olá, usuário! Seja bem vindo ao nosso SORTEADOR DE EQUIPES! -------");

  int escolha, quantidade_equipes;

  do
  {
    printf("\n\nDigite a opção desejada: \n\n1 - Sortear equipes; \n2 - Sair do programa.\n\n");
    scanf("%d", &escolha);

    switch (escolha)
    {
    case 1:
      do
      {
        printf("\n\n---------------------------------------------------------------------------\n\n");
        printf("Digite a quantidade de equipes que deseja sortear: ");
        scanf("%d", &quantidade_equipes);

        if (quantidade_equipes <= 0)
        {
          printf("\n\nValor não aceito! Tente novamente!\n\n");
        }

        // Chama a função para sortear as equipes
        sortearEquipes(quantidade_equipes);
      } while (quantidade_equipes <= 0);
      break;

    case 2:
      printf("\n\n----------------------------- FIM DO PROGRAMA -----------------------------\n\n");
      break;

    default:
      printf("\n---------------------------- Tente novamente! -----------------------------");
      break;
    }
  } while (escolha != 2); // Loop principal enquanto a escolha do usuário não for sair do programa
}

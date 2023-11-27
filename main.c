#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

// Função para ordenar a matriz
void bubbleSort(int matriz[2][1000], int n)
{
  int i, j, variavel_auxiliar;

  for (i = 0; i < n - 1; i++)
  {
    for (j = 0; j < n - i - 1; j++)
    {
      if (matriz[1][j] > matriz[1][j + 1])
      {
        // Ordena pela segunda linha da matriz
        
        variavel_auxiliar = matriz[1][j];
        matriz[1][j] = matriz[1][j + 1];
        matriz[1][j + 1] = variavel_auxiliar;

        variavel_auxiliar = matriz[0][j];
        matriz[0][j] = matriz[0][j + 1];
        matriz[0][j + 1] = variavel_auxiliar;
      }
    }
  }
}

// Função para sortear os números das equipes
void sortearEquipes(int n)
{
  int matriz[2][n], i, j, numero_sorteado;

  // Inicializa a matriz com os números das equipes
  for (i = 0; i < n; i++)
  {
    matriz[0][i] = i + 1;
  }


  for (i = 0; i < n; i++)
  {
    int se_repetir;

    do
    {
      se_repetir = 0;

      // Sorteia um número no intervalo de 0 até o número digitado pelo usuário
      numero_sorteado = rand() % n + 1;

      for (j = 0; j < i; j++)
      {
        // Verifica se algum número sorteado está sendo repetido
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

  // Chama a função de ordenação passando a matriz e a quantidade de equipes(n)
  bubbleSort(matriz, n);

  // Mostra a ordem sorteada
  printf("\n---------------------------------------------------------------------------\n\n");
  printf("ORDEM SORTEADA: \n\n");
  for (i = 0; i < n; i++)
  {
    printf("%dª equipe sorteada é: %d\n", i + 1, matriz[1][i]);
  }
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
      int quantidade_equipes;
      do
      {
        printf("\n\n---------------------------------------------------------------------------\n\n");
        printf("Digite a quantidade de equipes que deseja sortear: ");
        scanf("%d", &quantidade_equipes);        

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

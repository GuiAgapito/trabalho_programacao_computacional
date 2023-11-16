#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{

  char continuar;

  do
  {

    int quant_eq;
    printf("\n\nDigite a quantidade de equipes: ");
    scanf("%d%*c", &quant_eq);

    int min = 1;
    int max = quant_eq;

    printf("\n\n");

    // Inicialize a matriz
    long int matrix[2][quant_eq];

    for (int i = 0; i < quant_eq; i++)
    {
      printf("Digite a numeração da %ldª equipe: ", i + 1);
      scanf("%ld%*c", &matrix[0][i]);
    }

    printf("\n\n");

    // Inicialize o gerador de números aleatórios com uma semente diferente
    srand(time(NULL));

    for (int i = 0; i < max; i++)
    {
      int numero_aleatorio;
      do
      {
        numero_aleatorio = rand() % (max - min + 1) + min; // Gera um número entre 1 e quant_eq
        // Verifica se o número já foi sorteado antes
        int repetido = 0;
        for (int j = 0; j < i; j++)
        {
          if (numero_aleatorio == matrix[1][j])
          {
            repetido = 1;
            break;
          }
        }
        if (!repetido)
        {
          matrix[1][i] = numero_aleatorio;
          break;
        }
      } while (1);
    }

    // Imprimindo por equipe
    printf("Números sorteados: \n");
    for (int i = 0; i < quant_eq; i++)
    {
      printf("%ld ", matrix[0][i]);
    }
    printf("\t# numero equipe \n");
    for (int i = 0; i < quant_eq; i++)
    {
      printf("%ld ", matrix[1][i]);
    }
    printf("\t# ordem apresentacao\n");

    // BubbleSort
    int temp;
    int ordenada;

    for (int i = 0; i < quant_eq - 1; i++)
    {
      ordenada = 0; // Variável otimizadora

      for (int j = 0; j < quant_eq - 1 - i; j++)
      {
        if (matrix[1][j] > matrix[1][j + 1])
        {
          // Troca os elementos da segunda linha
          temp = matrix[1][j];
          matrix[1][j] = matrix[1][j + 1];
          matrix[1][j + 1] = temp;

          // Troca os elementos correspondentes da primeira linha
          temp = matrix[0][j];
          matrix[0][j] = matrix[0][j + 1];
          matrix[0][j + 1] = temp;

          ordenada = 1;
        }
      }

      // Se nenhum elemento foi trocado, a matriz está ordenada
      if (ordenada == 0)
      {
        break;
      }
    }

    // Imprimindo por ordem de apresentacao
    printf("\nOrdem das apresentacoes: \n");

    for (int i = 0; i < quant_eq; i++)
    {
      printf("%ld ", matrix[0][i]);
    }
    printf("\t# numero equipe \n");

    for (int i = 0; i < quant_eq; i++)
    {
      printf("%ld ", matrix[1][i]);
    }
    printf("\t# ordem apresentacao\n");

    printf("\n\nVocê deseja sortear novamente(S/N)? ");
    scanf("%c%*c", &continuar);

  } while (continuar == 'S' || continuar == 's');

  printf("\n\nPrograma finalizado!\n\n");

  return 0;
}

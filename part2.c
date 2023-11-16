#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (){

    int quant_eq;
    printf ("Digite a quantidade de equipes: ");
    scanf ("%d", &quant_eq);
      
    int min = 1;
    int max = quant_eq;
    
    // Inicialize a matriz
    int matrix[2][quant_eq];

    // Inicialize o gerador de números aleatórios com uma semente diferente
    srand(time(NULL));

    for (int i = 1; i <= max; i++) {
        printf ("DIgite o numero da equipe %d: ", i);
        scanf ("%d", &matrix[0][i]);
        int numero_aleatorio;
        do {
            numero_aleatorio = rand() % (max - min + 1) + min; // Gera um número entre 1 e quant_eq
            // Verifica se o número já foi sorteado antes
            int repetido = 0;
            for (int j = 0; j < i; j++) {
                if (numero_aleatorio == matrix[1][j]) {
                    repetido = 1;
                    break;
                }
            }
            if (!repetido) {
                matrix[0][i] = i;
                matrix[1][i] = numero_aleatorio;
                break;
            }
        } while (1);
    }
  
    // Imprimindo por equipe
    printf("Números sorteados: \n");
    for (int i = 0; i < quant_eq; i++) {
        printf("%d ", matrix[0][i]);
    }
    printf("\t# numero equipe \n");
    for (int i = 0; i < quant_eq; i++) {
        printf("%d ", matrix[1][i]);
    }
    printf("\t# ordem apresentacao\n");

    // BubbleSort
    int temp;
    int ordenada;

    for (int i = 0; i < quant_eq - 1; i++) {
        ordenada = 0; // Variável otimizadora

        for (int j = 0; j < quant_eq - 1 - i; j++) {
            if (matrix[1][j] > matrix[1][j + 1]) {
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
        if (ordenada == 0) {
            break;
        }
    }

    // Imprimindo por ordem de apresentacao
    printf("\nOrdem das apresentacoes: \n");
    for (int i = 0; i < quant_eq; i++) {
        printf("%d ", matrix[1][i]);
    }
    printf("\t# ordem apresentacao\n");
    for (int i = 0; i < quant_eq; i++) {
        printf("%d ", matrix[0][i]);
    }
    printf("\t# numero equipe \n");

    return 0;
}

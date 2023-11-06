#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (){

    int quant_eq;
    printf ("Digite a quantidade de equipes: ");
    scanf ("%d", &quant_eq);
    
    int num_eq[quant_eq], posicao[quant_eq];
    for (int i=1; i<=quant_eq; i++){
    printf ("\nDigite a numeração da equipe %d:", i);
    scanf ("%d", &num_eq[i]);
    }
    
    // for (int j=1; j<=quant_eq; j++){
    // posicao[j] = (1 + rand() % quant_eq);
    // printf ("%d", posicao[j]);
    // //printf("Equipe %d: %d ", j, rand() % (quant_eq + 1));
    // }

    int numeros_sorteados[quant_eq];
    int min = 1;
    int max = quant_eq;

    // Inicialize o gerador de números aleatórios com uma semente diferente
    srand(time(NULL));

    for (int i = 0; i < max; i++) {
        int numero_aleatorio;
        do {
            numero_aleatorio = rand() % (max - min + 1) + min; // Gera um número entre 1 e 7
            // Verifica se o número já foi sorteado antes
            int repetido = 0;
            for (int j = 0; j < i; j++) {
                if (numero_aleatorio == numeros_sorteados[j]) {
                    repetido = 1;
                    break;
                }
            }
            if (!repetido) {
                numeros_sorteados[i] = numero_aleatorio;
                break;
            }
        } while (1);
    }

    printf("Números sorteados: ");
    for (int i = 0; i < quant_eq; i++) {
        printf("%d ", numeros_sorteados[i]);
    }
    printf("\n");

    int matriz[2][quant_eq]; 
    for (int i = 1; i <= 2; i++) {
        for (int j = 1; j <= quant_eq; j++) {
            // if (i == 1 && j == 1) {
            //     printf("Equipes: ");
            // }
            // if (i == 2  && j == 1) {
            //     printf("Ordem:   ");
            // }
            if (i == 1) {
                matriz[1][j] = num_eq[j];                
                printf("%d  ", matriz[i][j]);
            } else {
                printf("%d  ", j);
            }
        }
        printf("\n");        
    }
    return 0;
}

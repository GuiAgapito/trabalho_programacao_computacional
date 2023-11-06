#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  char continuar;

  do {
    int quantidade_equipes;

    printf("\n\n");

    do {
      printf("Digite a quantidade de equipes que você deseja sortear: ");
      scanf("%d%*c", &quantidade_equipes);      
    } while (quantidade_equipes <= 0);

    int matriz[2][quantidade_equipes];

    printf("\n\n");

    for (int i = 1; i <= quantidade_equipes; i++) {
      printf("Digite a numeração da %dª equipe: ", i);
      scanf("%d%*c", &matriz[0][i]);
    }

    printf("\n\n");
    for (int i = 1; i <= 2; i++) {
      for (int j = 1; j <=quantidade_equipes; j++) {
        if (i == 1) {
          printf("%d ", matriz[0][j]);
        } else {
          printf("%d ", j);
        }
        
      }
      printf("\n");
    }


    printf("\n\nVocê deseja sortear novamente(S/N)? ");
    scanf("%c%*c", &continuar);

  } while (continuar == 'S' || continuar == 's');

  printf("\n\nPrograma finalizado!\n\n");

  return 0;
}
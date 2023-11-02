#include <stdio.h>

int main() {
  int quantidade_equipes;

  scanf("%d", &quantidade_equipes);

  int num_equipe[quantidade_equipes];

  int mat[2][quantidade_equipes];

  for (int i = 1; i <= 2; i++) {
    for (int j = 1; j <= quantidade_equipes; j++) {
      mat[i][j] = 1;      
    }
  }

  for (int i = 1; i <= 2; i++) {
    for (int j = 1; j <= quantidade_equipes; j++) {
      printf("%d ", mat[i][j]);
    }

    printf("\n");
  }
  return 0;
}
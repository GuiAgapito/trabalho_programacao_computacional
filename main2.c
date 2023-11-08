#include <stdio.h>
#include <stdlib.h>

int main() {
  char pergunta;

  do {  
    printf("Voce deseja sortear novamente? (S/N)  ");
    scanf("%c%*c", &pergunta);
  } while (pergunta == 'S' || pergunta == 's');

  return 0;
}
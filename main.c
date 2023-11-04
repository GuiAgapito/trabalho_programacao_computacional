#include <stdio.h>

int teste01() {

    int quantidade_equipes;

    printf("Digite a quantidade de equipes que você deseja sortear: ");
    scanf("%d", &quantidade_equipes);

    int numeros_equipes[quantidade_equipes];

    printf("\n");

    for (int i = 1; i <= quantidade_equipes; i++) {
        printf("Digite a numeração da %dª equipe: ", i);
        scanf("%d", &numeros_equipes[i]);
    }

    int matriz[2][quantidade_equipes];

    printf("\n");

    for (int i = 1; i <= 2; i++) {
        for (int j = 1; j <= quantidade_equipes; j++) {
            if (i == 1 && j == 1) {
                printf("Equipes: ");
            }
            if (i == 2  && j == 1) {
                printf("Ordem:   ");
            }
            if (i == 1) {
                matriz[1][j] = numeros_equipes[j];                
                printf("%d  ", matriz[i][j]);
            } else {
                printf("%d  ", j);
            }
        }
        printf("\n");        
    }

    printf("\n");    

    return 0;
}

int teste02() {

    int quantidade_equipes;

    printf("Digite a quantidade de equipes que você deseja sortear: ");
    scanf("%d", &quantidade_equipes);

    int numeros_equipes[quantidade_equipes];

    printf("\n");

    for (int i = 1; i <= quantidade_equipes; i++) {
        printf("Digite a numeração da %dª equipe: ", i);
        scanf("%d", &numeros_equipes[i]);
    }

    int matriz[2][quantidade_equipes];

    printf("\nOrdem inicial para o sorteio: \n\n");

    for (int i = 1; i <= 2; i++) {
        for (int j = 1; j <= quantidade_equipes; j++) {
            if (i == 1 && j == 1) {
                printf("Equipes: ");
            }
            if (i == 2  && j == 1) {
                printf("Ordem:   ");
            }
            if (i == 1) {
                matriz[1][j] = numeros_equipes[j];                
                printf("%d  ", matriz[i][j]);
            } else {
                printf("%d  ", j);
            }
        }
        printf("\n");        
    }

    printf("\n");    

    return 0;   

}

int main() {
    
    teste02();

    return 0;
}

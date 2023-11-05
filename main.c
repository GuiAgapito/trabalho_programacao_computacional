#include <stdio.h>

int main()
{    
    char pergunta;
    
    do {
        // Variável que irá receber a quantidade de equipes a serem sorteadas
        int quantidade_equipes; 

        // Recebe e verifica se a quantidade de valores que o usuário digitou é um valor positivo, se não for repete a pergunta até ele retornar um valor positivo
        do {
            printf("\nDigite a quantidade de equipes que deseja sortear: ");
            scanf("%d", &quantidade_equipes);
        } while (quantidade_equipes <= 0);
            
        printf("\n");

        // Vetor que irá receber a numeração das equipes
        int equipes[quantidade_equipes];

        // Recebe e guarda as numerações das equipes no vetor equipes
        for (int i = 1; i <= quantidade_equipes; i++)
        {
            printf("Digite a numeração da %dª equipe: ", i);
            scanf("%d%*c", &equipes[i]);
        }       

        // Matriz que irá mostrar a ordem e a numeração das equipes
        int matriz[2][quantidade_equipes];

        // Mostra a ordem inicial antes do sorteio
        printf("\nNumeração e ordem das equipes antes do sorteio: \n");
        for (int linha = 1; linha <= 2; linha++) {
            for (int coluna = 1; coluna <= quantidade_equipes; coluna++) {
                if (linha == 1) {
                    matriz[1][coluna] = equipes[coluna];
                    printf("%d  ", matriz[linha][coluna]);
                }
                else {
                    printf("%d  ", coluna);
                }
            }
            printf("\n");
        }        

        
        for (int i = 1; i <= quantidade_equipes; i++) {
            for (int j = 1; j <= quantidade_equipes - 1 - i; j++) {
                if (equipes[j] < equipes[j + 1]) {
                    int aux = equipes[j];
                    equipes[j] = equipes[j + 1];
                    equipes[j + 1] = aux;
                }
            }
        }

        printf("\nOrdem de apresentação após o sorteio: \n");
        for (int linha = 1; linha <= 2; linha++) {
            for (int coluna = 1; coluna <= quantidade_equipes; coluna++) {
                if (linha == 1) {
                    matriz[1][coluna] = equipes[coluna];
                    printf("%d  ", matriz[linha][coluna]);
                }
                else {
                    printf("%d  ", coluna);
                }
            }
            printf("\n");
        }
        
        printf("\nVocê deseja sortear novamente (S para SIM / N para NÃO )? ");
        scanf(" %c", &pergunta);

    } while (pergunta == 'S' || pergunta == 's');
    

    return 0;
}
#include <stdio.h>
int main (){

    int quant_eq;
    printf ("Digite a quantidade de equipes: ");
    scanf ("%d", &quant_eq);
    
    int num_eq[quant_eq];
    for (int i=1; i<=quant_eq; i++){
    printf ("\nDigite a numeração da equipe %d:", i);
    scanf ("%d", &num_eq[i]);
    }
}
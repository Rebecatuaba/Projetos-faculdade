#include <stdio.h>

int main() {
    char nome[100];
    float peso, altura, imc;

    printf("Digite seu nome: ");
    scanf(" %99[^\n]", nome);

    printf("Digite seu peso em kg: ");
    scanf("%f", &peso);

    printf("Digite sua altura em metros: ");
    scanf("%f", &altura);

    imc = peso / (altura * altura);

    printf("%s, seu IMC e de %.4f\n", nome, imc);

    return 0;
}

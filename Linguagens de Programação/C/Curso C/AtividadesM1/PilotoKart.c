#include <stdio.h>

int main() {
    float pista, distancia, tempo, previsao;

    int voltas;

    printf("Tamanho da pista em metros: ");
    scanf("%f", &pista);

    printf("Quantidade de voltas: ");
    scanf("%d", &voltas);

    printf("Tempo da primeira volta em segundos: ");
    scanf("%f", &tempo);

    distancia = (pista * voltas) / 1000;
    previsao = (tempo * voltas) / 60;

    printf("\nAnalise Preditiva Concluida\n");
    printf("Distancia total a ser percorrida: %.2f km.\n", distancia);
    printf("Previsao de conclusao: %.1f minutos.\n", previsao);

    return 0;
}

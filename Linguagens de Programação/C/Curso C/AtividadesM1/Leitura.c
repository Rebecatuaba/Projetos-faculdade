#include <stdio.h>

int main() {
    char nome[100];
    char livro[100];
    int paginas, segundosPorPagina;
    float tempoHoras;

    printf("Digite seu nome: ");
    scanf(" %99[^\n]", nome);

    printf("Digite o nome do livro: ");
    scanf(" %99[^\n]", livro);

    printf("Digite o total de paginas: ");
    scanf("%d", &paginas);

    printf("Digite o tempo de leitura por pagina (em segundos): ");
    scanf("%d", &segundosPorPagina);

    tempoHoras = (float)(paginas * segundosPorPagina) / 3600;

    printf("%s, voce finalizara a leitura do livro %s\n", nome, livro);
    printf("em aproximadamente %.2f horas.\n", tempoHoras);

    return 0;
}

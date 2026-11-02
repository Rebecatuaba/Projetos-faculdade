#include <stdio.h>

int main() {
    char nome[100];
    float compra, desconto, valorDesconto, total;

    printf("Digite o nome do cliente: ");
    scanf(" %99[^\n]", nome);

    printf("Digite o valor da compra: ");
    scanf("%f", &compra);

    printf("Digite a porcentagem de desconto: ");
    scanf("%f", &desconto);

    valorDesconto = compra * desconto / 100;
    total = compra - valorDesconto;

    printf("\nOla %s, sua compra de R$ %.2f foi confirmada!\n", nome, compra);
    printf("Foi aplicado um desconto de %.1f%%.\n", desconto);
    printf("O total final ficou em R$ %.2f\n", total);

    return 0;
}

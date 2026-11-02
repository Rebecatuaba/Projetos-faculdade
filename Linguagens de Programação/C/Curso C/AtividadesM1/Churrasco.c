#include <stdio.h>

int main() {
    int pessoas;
    float carne, linguica, frango;
    float custoCarne, custoLinguica, custoFrango;
    float custoTotal, contribuicao;

    printf("Digite a quantidade de pessoas: ");
    scanf("%d", &pessoas);

    carne = pessoas * 0.3;
    linguica = pessoas * 0.2;
    frango = pessoas * 0.15;

    custoCarne = carne * 50.00;
    custoLinguica = linguica * 28.00;
    custoFrango = frango * 22.00;

    custoTotal = custoCarne + custoLinguica + custoFrango;
    contribuicao = custoTotal / pessoas;

    printf("\nQuantidades:\n");
    printf("Carne: %.1f kg\n", carne);
    printf("Linguica: %.1f kg\n", linguica);
    printf("Frango: %.1f kg\n", frango);

    printf("\nCusto total:\n");
    printf("Carne: R$ %.2f\n", custoCarne);
    printf("Linguica: R$ %.2f\n", custoLinguica);
    printf("Frango: R$ %.2f\n", custoFrango);

    printf("\nCusto total do churrasco: R$ %.2f\n", custoTotal);
    printf("Cada pessoa deve contribuir com: R$ %.2f\n", contribuicao);

    return 0;
}

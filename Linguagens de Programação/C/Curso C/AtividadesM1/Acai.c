#include <stdio.h>

int main() {
    int pequeno, medio, grande;
    float desconto, subtotal, total;

    printf("Quantidade de acai pequeno: ");
    scanf("%d", &pequeno);

    printf("Quantidade de acai medio: ");
    scanf("%d", &medio);

    printf("Quantidade de acai grande: ");
    scanf("%d", &grande);

    printf("Desconto em porcentagem: ");
    scanf("%f", &desconto);

    subtotal = pequeno * 13.50 + medio * 15.00 + grande * 17.50;
    total = subtotal - (subtotal * desconto / 100);

    printf("\nSeu pedido foi registrado.\n");
    printf("- Acai P: %d\n", pequeno);
    printf("- Acai M: %d\n", medio);
    printf("- Acai G: %d\n", grande);
    printf("\nDesconto de %.1f%% aplicado.\n", desconto);
    printf("Total R$ %.2f\n", total);

    return 0;
}

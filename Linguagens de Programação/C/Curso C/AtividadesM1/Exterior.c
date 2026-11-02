#include <stdio.h>

int main() {
    float real, dolar;

    printf("Digite o valor em reais: ");
    scanf("%f", &real);

    dolar = real / 5.42;

    printf("Valor em real R$ %.2f.\n", real);
    printf("Valor em dolar $ %.2f.\n", dolar);

    return 0;
}

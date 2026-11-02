#include <stdio.h>

int main() {
    char meta[100];
    float valorMeta, salario, despesas;
    float saldo, reserva, disponivel, meses;

    printf("Descricao da meta: ");
    scanf(" %99[^\n]", meta);

    printf("Valor necessario para a meta: ");
    scanf("%f", &valorMeta);

    printf("Salario mensal: ");
    scanf("%f", &salario);

    printf("Total das despesas mensais: ");
    scanf("%f", &despesas);

    saldo = salario - despesas;
    reserva = saldo * 0.30;
    disponivel = saldo - reserva;

    if (saldo <= 0 || disponivel <= 0) {
        printf("Nao ha saldo disponivel para a meta.\n");
    } else {
        meses = valorMeta / disponivel;

        printf("\nMeta: %s (R$ %.2f)\n", meta, valorMeta);
        printf("Salario: R$ %.2f - Despesas: R$ %.2f\n",
               salario, despesas);

        printf("\nSaldo apos despesas: R$ %.2f\n", saldo);
        printf("Reserva fixa (30%%): R$ %.2f\n", reserva);
        printf("Valor disponivel para a meta: R$ %.2f por mes\n",
               disponivel);
        printf("Prazo estimado para atingir a meta: %.2f meses\n",
               meses);
    }

    return 0;
}

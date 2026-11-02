#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese_Brasil.1252");

    int num1, num2;

    printf("--- Calculadora Muito Loka ---\n");
    printf("Digita um número aí: ");
    scanf("%d", &num1);
    printf("Digita oto: ");
    scanf("%d", &num2);

    int soma = num1 + num2;
    int sub = num1 - num2;
    int mult = num1 * num2;
    float div = (float) num1 / num2;

    printf("\n--- Resultados ---\n");
    printf("%d + %d = %d\n", num1, num2, soma);
    printf("%d - %d = %d\n", num1, num2, sub);
    printf("%d * %d = %d\n", num1, num2, mult);
    printf("%d / %d = %2f\n", num1, num2, div);

    return 0;
}
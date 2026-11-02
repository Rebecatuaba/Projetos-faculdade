#include <stdio.h>

int main() {
    char nome[100];
    float nota1, nota2, nota3, media;

    printf("Digite o nome do aluno: ");
    scanf(" %99[^\n]", nome);

    printf("Digite a primeira nota: ");
    scanf("%f", &nota1);

    printf("Digite a segunda nota: ");
    scanf("%f", &nota2);

    printf("Digite a terceira nota: ");
    scanf("%f", &nota3);

    media = (nota1 + nota2 + nota3) / 3;

    printf("O(A) estudante %s ficou com media %.1f\n", nome, media);

    return 0;
}

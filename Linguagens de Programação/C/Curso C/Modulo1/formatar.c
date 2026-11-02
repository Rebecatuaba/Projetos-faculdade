#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Portuguese_Brasil.1252");

    //realizar tabela: TAB (\\t)
    printf("--- TABELA ---\n");
    printf("Jogador\t\tPontos\n");
    printf("Ana\t\t1500\n");
    printf("Carol\t\t800\n");
    printf("Pedro\t\t500\n");
    printf("------------------------\n\n");


    //realizar tabela - Forma mais precisa: %
    printf("--- TABELA ---\n");
    printf("%-15s %10s\n", "Jogador", "Pontos");
    printf("%-15s %10d\n", "Ana", 1500);
    printf("%-15s %10d\n", "Carol", 800);
    printf("%-15s %10d\n", "Pedro", 500);
    printf("------------------------\n\n");

    // o 15s representa os espaços de caracter da direita e o 10d da esquerda
    // se for mais que essa quantidade precisa aumentar o valor



    return 0;
}

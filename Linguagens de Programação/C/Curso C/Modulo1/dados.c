//gcc helloWorld.c -o helloWorld
//.\helloWorld
// cls - para limpar o terminal

#include <stdio.h>
#include <locale.h>  // Para uso de acento, usar a gramatica local
#include <string.h>

int main(){
    setlocale(LC_ALL, "");

    char nomePersonagem[50]; //%s
    int idade; //%d
    float altura; //%f
    
    printf("Digite o nome do Personagem: ");
    scanf("%s", nomePersonagem);

    printf("Digite a idade do Personagem: ");
    scanf("%d", &idade);

    printf("Digite a altura do Personagem: ");
    scanf("%f", &altura);

    printf("Nosso personagem se chama %s e tem %d anos de idade!\n Ele tem %.2f metros de altura.", nomePersonagem, idade, altura);

    
    return 0;
}

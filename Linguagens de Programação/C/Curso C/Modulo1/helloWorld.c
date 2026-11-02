//gcc helloWorld.c -o helloWorld
//.\helloWorld
// cls - para limpar o terminal

#include <stdio.h>
#include <locale.h>  // Para uso de acento, usar a gramatica local
//#include <windows.h>
#include <string.h>

int main(){
    setlocale(LC_ALL, "");
    //SetConsoleOutputCP(65001);
    const char curso[] = "Eng. Computação"; // constante imutavel string
    char name[] = "Rebeca"; //variavel string
    printf("HELLO WORLD!!! %s do curso de %s. \n", name, curso); //concatenação

    //concatenado com a função strcat 
    char s1[] = "Eae "; //dentro de [] vc coloca o tamanho de caracteres que s1 pode receber 
    char s2[] = "rapaziada!!!";
    char s3[] = "Tudo em cima? \"Boara comer um sanduba?\"";

    strcat (s1, s2);//aqui juntou o s2 no s1. O strcat aceita apenas 2 strings por vez
    printf("%s\n", s1);

    //Receber dados do usuario - scanf (ele não le depois de um espaço)
    char nomePersonagem[50];
    printf("Digite o nome do Personagem: ");
    scanf("%s", nomePersonagem);
    printf("O nome do personagem é: %s\n", nomePersonagem);

    // fgets - para leituras com espaço
    char nomeProtagonista[50];
    printf("Digite o nome do Protagonista: ");
    getchar();
    fgets(nomeProtagonista, sizeof(nomeProtagonista), stdin);
    printf("O nome do Protagonista é: %s !", nomeProtagonista);

    
    return 0;
}

//Obs. A acentuação nao funcionou!
// Prox Aula 12
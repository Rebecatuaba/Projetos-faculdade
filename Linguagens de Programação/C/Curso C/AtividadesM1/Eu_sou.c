#include <stdio.h>
#include <locale.h> 

int main(){
    setlocale(LC_ALL, "Portuguese_Brasil.1252");

    char nome [100]; //%s
    char curso [100];
    int semestre; //%d
    char hobby [100]; //%f
    
    printf("Digite o seu nome: ");
    scanf("%s", &nome);

    printf("Digite o seu curso: ");
    scanf("%s", &curso);

    printf("Digite o seu semestre atual: ");
    scanf("%d", &semestre);

    printf("Digite o seu hobby favorito: ");
    scanf("%s", &hobby);

    printf("Prazer, eu sou o(a) %s!\n Atualmente estou %d semestre de %s e meu hobby favorito é %s", nome, semestre, curso, hobby);

    
    return 0;
}

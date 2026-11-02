import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws Exception {
       Scanner scanner = new Scanner(System.in); 
       System.out.println("Digite seu nome: ");
       String nome = scanner.next();
       System.out.println("Digite o nome da pessoa ao seu lado: ");
       String nomeLado = scanner.next();
       System.out.println("Digite a sua idade: ");
       int idade = scanner.nextInt();
       System.out.println("Digite a idade da pessoa ao seu lado: ");
       int idadeLado = scanner.nextInt();

       int diferenca =  idade-idadeLado;

       System.out.printf("A difrença de idade entre as duas pessoas é: %s", diferenca);

    }
}

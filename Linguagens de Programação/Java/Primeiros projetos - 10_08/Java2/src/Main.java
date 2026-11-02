import java.util.Scanner; //Importa a classe Scanner, usada para ler dados digitados pelo usuário no console


public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);//Cria um objeto scanner que vai capturar a entrada do usuário pelo teclado
        System.out.println("Olá meu amigo, me diga o seu nome!");
        String name = scanner.next();
        System.out.println("Agora me informe a sua idade!");
        int age = scanner.nextInt();
        System.out.println("Por gentileza, me diga o número do seu cartão!");
        var card = scanner.nextInt(); //outra forma de declara uma variavel 
        System.out.println("Olá "+name+" sua idade é "+age);
        System.out.printf("Olá %s a senha do seu catão é %s", name,  card);
        // Duas formas de printar um valor de uma variavel junto com um comentario
        
        System.out.println();// pulou para a proxima linha
        System.out.println();// pulou uma linha
        System.out.println("Digite um número");
        var number1 = scanner.nextInt();
        System.out.println("Digite outro número");
        var numerber2 = scanner.nextInt();
        System.out.printf("%s + %s = %s", number1,  numerber2, number1*numerber2);

        System.out.println();
        System.out.printf("A raiz de %s é %s\n", number1, Math.sqrt(number1));
        System.out.println();
        System.out.printf("A potencia de %s é %s\n", number1, Math.pow(number1, 2));
        System.out.println();
        System.out.println(++numerber2); // é o mesmo que value/int *=1 ou value = value+1
     
    }

}

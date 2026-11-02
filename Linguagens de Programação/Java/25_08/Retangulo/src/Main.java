import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws Exception {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Escreva um valor: ");
        int lado1 = scanner.nextInt();
        System.out.println("Escreva outro valor: ");
        int lado2 = scanner.nextInt();
        int area = lado1*lado2;

        System.out.printf("A área do retângulo é: %s", area);
    }
}

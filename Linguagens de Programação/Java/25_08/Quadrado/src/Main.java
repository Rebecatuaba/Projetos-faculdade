import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Digite um valor");
        int lado = scanner.nextInt();
        int area = lado*lado;
        System.out.printf("A área do quadrado é: %s", area);
    }
}

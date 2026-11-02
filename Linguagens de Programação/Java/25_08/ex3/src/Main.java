import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws Exception {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Informe um número: ");
        int n1 = scanner.nextInt();
        System.out.println("Informe outro número maior que o anterior: ");
        int n2 = scanner.nextInt();
        System.out.println("Escolha entre par ou impar: ");
        boolean escolhaPar = scanner.next().equalsIgnoreCase("par");

        // Garante que n1 seja o maior e n2 seja o menor
        int maior = Math.max(n1, n2);
        int menor = Math.min(n1, n2);

        System.out.println("\nNúmeros " + (escolhaPar ? "pares" : "ímpares") +
                           " entre " + menor + " e " + maior + " em ordem decrescente:");

        for (int i = maior; i >= menor; i--) {
            if (escolhaPar && i % 2 == 0) {
                System.out.print(i + " ");
            } else if (!escolhaPar && i % 2 != 0) {
                System.out.print(i + " ");
            }
        }

        scanner.close();
    }
}

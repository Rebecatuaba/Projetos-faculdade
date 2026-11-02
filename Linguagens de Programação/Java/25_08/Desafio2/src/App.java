import java.util.Scanner;
import java.text.DecimalFormat;

public class App {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Informe o valor original do produto: ");
        double valor = scanner.nextDouble();

        System.out.println("Informe a porcentagem de desconto: ");
        double desconto = scanner.nextDouble();

        if (desconto < 0 || desconto > 100) {
            System.out.println("Desconto invalido");
        } else {
            double valorFinal = valor * (1 - desconto / 100);

            // Formata e exibe o valor com duas casas decimais
            DecimalFormat df = new DecimalFormat("0.00");
            System.out.println(df.format(valorFinal));
        }

        scanner.close();
    }
}

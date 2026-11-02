import java.util.Locale;
import java.util.Scanner;

public class Main {
  
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        // TODO: Leia o peso em quilos:
        System.out.println("Informe o peso da carga em quilos: ");
        var peso = scanner.nextDouble();
        // TODO: Leia o valor do frete por quilo:
        System.out.println("Informe o valor do frete por quilo: ");
        var frete = scanner.nextDouble();

        // TODO: Calcule o valor total do frete:
        var valorTotal = peso*frete;
        
        // TODO: Exiba o valor formatado com duas casas decimais:
       System.out.printf(Locale.US, "O valor total do frete é %.2f%n", valorTotal);


        scanner.close();
    }
}
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws Exception {
      var scanner = new Scanner(System.in);
      System.out.println("Escreva a sua altura: ");
      var altura = scanner.nextDouble();
      System.out.println("Escreva o seu peso: ");
      var peso = scanner.nextDouble();

      var imc = peso / (altura * altura);

      if (imc <= 18.5) {
        System.out.println("Abaixo do peso");
      } else if (imc >= 18.6 && imc <= 24.9) {
        System.out.println("Peso ideal");
      } else if (imc >= 25.0 && imc <= 29.9) {
        System.out.println("Levemente acima do peso");
      } else if (imc >= 30.0 && imc <= 34.9) {
        System.out.println("Obesidade Grau 1");
      } else if (imc >= 35.0 && imc <= 39.9) {
        System.out.println("Obesidade Grau 2 (Severa)");
      }else if (imc > 40.0) {
        System.out.println("Obesidade Grau 3 (Mórbida)");
      }
    } 
}


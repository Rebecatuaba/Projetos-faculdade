import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws Exception {
        var scanner = new Scanner(System.in);
        System.out.println("Digite um número: ");
        var numero = scanner.nextInt();
   
        while (true){
            System.out.println("Informe o número para verificação: ");
            var verificar = scanner.nextInt();
            if (verificar < numero){
                System.out.printf("Informe um número maior que %s \n", numero);
                continue;
            }
            var resultado = verificar % numero;
            System.out.printf("%s %% %s = %s", verificar, numero, resultado);
            if (resultado != 0) break;
        }
    }
}

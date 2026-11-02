import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws Exception {
        var scanner = new Scanner(System.in);
        var name = "";
        while (!name.equals("exit")){//ao escrever exit o while para de rodar
            System.out.println("Informe um nome");
            name = scanner.next();
        }

        /*Outra forma:
            while (true){
            System.out.println("Informe um nome");
            name = scanner.next();
            System.out.println(name);

            if (name.equalsIgnomeCase("exit")) break;
            }
         
         */

         /*Outra forma: Do While -- primeiro executa e só depois faz a verificação
            var scanner = new Scanner(System.in);
            var name = "exit";   
            do {
                System.out.println("Informe um nome");
                name = scanner.next();
                System.out.println(name);

            }while (name.equalsIgnomeCase("exit"));
         
         */
    }
}

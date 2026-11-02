import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws Exception {
        var scanner = new Scanner(System.in);
        System.out.println("Escreva um número: ");
        var n = scanner.nextInt();

        System.out.printf("Tabuada do %s: \n", n);
        for(var i = 0; i <=10; i++){
            System.out.printf("%s x %s = %s \n", n, i, n*i);
        }
    }
}

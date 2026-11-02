import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws Exception {
        /*for(var i = 0; i <= 100; i++){//tem que ter sempre uma condição, dentro do () sempre ter 3 ;
            if (i % 2 == 0){// verifica se i é divisível por 2 (ou seja, se é par)
                continue; // se for par, pula o resto do laço e vai para a próxima iteração
            }
            System.out.println(i); // só chega aqui se i for ímpar → imprime o valor de i
        }*/
        
        //lista
        for(var i = 0; i < args.length; i++){
            System.out.println(args[i]);
    }
}
}

import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws Exception {
        var scanner = new Scanner(System.in);
        System.out.println("Informe seu nome: ");
        var nome = scanner.next();
        System.out.println("Informe a sua idade: ");
        var idade = scanner.nextInt();
        System.out.println("Você assite televisão? (s/n)");
        var assite = scanner.next().equalsIgnoreCase("s"); 

        //por ser apenas uma linha de código não precisa de chaves
        if (idade >=18) System.out.printf("%s tem %s anos, você pode se matar \n", nome, idade);
        
        else if (idade >= 16 && assite){
             System.out.printf("%s, apeasar de você ter %s, não pode se matar \n", nome, idade);
        }
        else{ 
            System.out.println("Você ainda é muito novo para se matar!");
        }
        /*outra forma de usar booleana: Elvis operator
        var canDie = (idade >= 18) || (idade >= 16 && assite):
        var message = canDie ?
            nome + ", você pode morrer \n":
            nome + ", você não pode morrer \n":
         */
    }
}

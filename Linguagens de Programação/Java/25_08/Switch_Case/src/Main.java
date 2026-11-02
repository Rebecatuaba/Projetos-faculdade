import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws Exception {
        var scanner =  new Scanner(System.in);
        System.out.println("Informe um número de 1 até 7: ");
        var numero = scanner.nextInt();

        switch (numero) {
            case 1: //System.out.println("Domingo");
            case 7:
                System.out.println("Fim de Semana");// dois cases (1,7) com mesmo valor
                break;
            case 2:
                System.out.println("Segunda");
                break;
            case 3:
                System.out.println("Terça");
                break;
            case 4:
                System.out.println("Quarta");
                break;
            case 5:
                System.out.println("Quinta");
                break;
            case 6:
                System.out.println("Sexta");
                break;
            /*case 7:
                System.out.println("Sábado");                        
                break;*/
            default:
                System.out.println("De 1 até 7, por favor!");
                break;
        }

        /*Outra forma de usar Switch Case:
            switch (numero){
                //case 1 -> System.out.println("Domingo");
                case 1,7 -> System.out.println("Fim de Semana!");
                case 2 -> System.out.println("Segunda");
                case 3 -> System.out.println("Terça");
                case 4 -> System.out.println("Quarta");
                case 5 -> System.out.println("Quinta");
                case 6 -> System.out.println("Sexta");
                //case 7 -> System.out.println("Sábado");
                default -> System.out.println("De 1 até 7, por favor!");
            }
         */

         /*Outra forma de usar Switch Case: Atrinuição
            var message = switch (numero){
                //case 1 -> "Domingo";
                case 1,7 -> "Fim de Semana!";
                case 2 -> "Segunda";
                case 3 -> "Terça"; (...)
                case 4, 5 -> {
                    var dia = numero == 1 ? "Quarta" : "Quinta";
                    yield String.format ("Ir para academia!", dia);

                }
                
            };
         */
    }
}

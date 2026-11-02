import java.util.Scanner;

public class Main {

    private final static Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws Exception {
        int option;
        Forma forma = null;

        while (true){
            System.out.println("Escolha uma forma geométrica!");
            System.out.println("1 - Quadrado");
            System.out.println("2 - Retângulo");
            System.out.println("3 - Circulo");
            System.out.println("4 - Sair");
            option = scanner.nextInt();
            
             if (option == 1){
                forma = createSquare();
             }else if (option == 2){
                forma = createRetangulo();
             }else if (option == 3){
                forma = createCirculo();
             }else if (option == 4){
                break;
             }else{
                System.out.println("Opção inválida!");
                continue;
             }
             System.out.println("O resultado do cálculo da área foi de " + forma.getArea());
        }
    }

    private static Forma createSquare() {
    System.out.println("Informe o tamanho dos lados: ");
    int side = (int) scanner.nextDouble();  // converte double para int
    return new Square(side);
}

    private static Forma createRetangulo(){
        System.out.println("Informe a base: ");
        var base = scanner.nextDouble();
        System.out.println("Informe a altura: ");
        var altura = scanner.nextDouble();
        return new Retangulo(altura, base);
    }

    private static Forma createCirculo(){
        System.out.println("Informe o raio: ");
        var radius = scanner.nextDouble();
        return new Circulo(radius);
    }
}

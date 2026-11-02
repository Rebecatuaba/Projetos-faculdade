import java.util.Scanner;

public class OutroLoop {
    public OutroLoop() {
    }

    public static void main(String[] args) {
        Scanner leitura = new Scanner(System.in);
        double mediaAvalicao = 0.0;
        double nota = 0.0;
        int totalNotas = 0;

        while (nota != -1) {
            System.out.println("Diga a sua avaliação para o filme ou -1 para encerrar: ");
            nota = leitura.nextDouble();
            if (nota != -1) {
                mediaAvalicao += nota;
                totalNotas++;
            }
        }

        System.out.println("Média de Avaliações: " + mediaAvalicao / totalNotas);
    }
}

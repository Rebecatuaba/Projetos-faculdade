import java.util.Scanner;

public class Loop {
    static void main(String[] args) {
        Scanner leitura = new Scanner(System.in);
        // System.out.println("Digite sua avaliação: ");
        //double avaliacao = leitura.nextDouble();
        double mediaAvalicao = 0;
        double nota = 0;

        for (int i = 0; i < 3; i++){
            System.out.println("Diga a sua avaliação para o filme: ");
            nota = leitura.nextDouble();
            mediaAvalicao += nota; // soma a nota com o valor da mediaAvaliação inicial
        }
        System.out.println("Média de Avaliações: " + mediaAvalicao/3);
    }
}

public class Filme {

    String nome;
    int anoDeLancamento;
    boolean incluidoNoPlano;
    double avaliacao;
    int totalDeAvaliacoes;
    int duracaoEmMinutos;

        void exibeFichaTecnica(){
            System.out.println(nome);
            System.out.println(anoDeLancamento);
            System.out.println(duracaoEmMinutos);
        }

}
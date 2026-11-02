// shift + F6 em cima do nome ou valor que eu quero alterar, pois vai alterar em td

public class Filme {

    String nome;
    int anoDeLancamento;
    boolean incluidoNoPlano;
    double somaDasAvaliações;
    int totalDeAvaliacoes;
    int duracaoEmMinutos;

    void exibeFichaTecnica(){
        System.out.println("Nome do Filme:" + nome);
        System.out.println("Ano do Lançamento" + anoDeLancamento);
        System.out.println("Duração em Minutos:" + duracaoEmMinutos);
    }

    void avalia(double nota){
        somaDasAvaliações += nota;
        totalDeAvaliacoes ++;
    }

}
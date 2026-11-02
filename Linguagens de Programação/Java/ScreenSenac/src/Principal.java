public class Principal {
    static void main(String[] args) {
        Filme meuFilme = new Filme();
        meuFilme.nome = "As Branquelas";
        meuFilme.anoDeLancamento = 2004;
        meuFilme.duracaoEmMinutos = 109;
        meuFilme.somaDasAvaliações = 55.7;

        meuFilme.exibeFichaTecnica();
        meuFilme.avalia();
        //System.out.println(meuFilme); //representação textual padrão de um objeto na memória do Java. Classe Filme
    }

}

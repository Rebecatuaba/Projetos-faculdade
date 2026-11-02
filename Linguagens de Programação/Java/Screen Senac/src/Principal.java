public class Principal {
    static void main(String[] args) {
        Filme meuFilme = new Filme();
        meuFilme.nome = "As Branquelas";
        meuFilme.anoDeLancamento = 2004;
        meuFilme.duracaoEmMinutos = 109;

        System.out.println(meuFilme.nome);
        System.out.println(meuFilme.anoDeLancamento);
        System.out.println(meuFilme.duracaoEmMinutos);
        System.out.println(meuFilme); //representação textual padrão de um objeto na memória do Java. Classe Filme
    }
}

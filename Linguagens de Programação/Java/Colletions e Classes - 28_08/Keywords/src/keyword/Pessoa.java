package keyword;

// "abstract" → esta classe não pode ser instanciada diretamente
public abstract class Pessoa {

    protected String nome;

    protected int idade;

    // Construtor da classe base
    public Pessoa(String nome, int idade) {
        this.nome = nome;
        this.idade = idade;
    }

    // Método comum a todas as pessoas
    public void mostrarDadosBasicos() {
        System.out.println("Nome: " + nome);
        System.out.println("Idade: " + idade);
    }
}

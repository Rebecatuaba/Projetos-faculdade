public class Main {
    public static void main(String[] args) {

//comparação para strings, o == verifica variaveis e não o conteudo entre duas strings
        String senha = "12345";
        if (senha.equals("12345")) {
            System.out.println("Acesso Autorizado!");
        } else {
            System.out.println("Senha incorreta!");
        }
//usar % para printar o valor da variavel
        String nome = "Becks";
        int age = 19;
        double valor = 800;
        System.out.println(String.format("Meu nome é %s, eu tenho %d anos e hoje gastei %.2f reais", nome, age, valor));

//Casting é o processo de converter um valor de um tipo de dado em outro
//Casting implícito é a conversão automática de um tipo menor para um maior sem perda de dados
//Casting explícito exige que o desenvolvedor force manualmente a conversão de um tipo maior para um menor, correndo o risco de perder informações

    }
}
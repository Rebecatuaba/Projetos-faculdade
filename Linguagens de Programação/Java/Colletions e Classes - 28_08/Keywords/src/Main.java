// Main NÃO pertence ao pacote "keywords"
// Por isso, precisamos importar as classes de dentro do pacote
import keyword.Client;
import keyword.Address;

// public - quer dizer que qualquer parte do nosso código tem acesso(classe/metodo)
public class Main {
    // "public static void main" é o ponto de entrada da aplicação
    public static void main(String[] args) throws Exception {
        // Criando um cliente
        Client cliente = new Client("Rebeca", 18);

        // Criando um endereço
        Address endereco = new Address("Rua das Flores", 123);

        // Associando endereço ao cliente
        cliente.setAddress(endereco);

        // Mostrando as informações
        cliente.mostrarInfo();

        // "return" encerra o método main
        return;
    }
}

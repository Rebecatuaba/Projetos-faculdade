// "package" define o pacote ao qual a classe pertence
package keyword;

// "extends" → Cliente herda de Pessoa
public class Client extends Pessoa {

    protected Address address;

    // "final" define uma constante
    private final String tipo = "CLIENTE";

    // Construtor usando "this"
    public Client(String nome, int idade) {
        super(nome, idade);
    }

    public void setAddress(Address address) {
        this.address = address;
    }

    public void mostrarInfo() {
        System.out.println("Tipo: " + tipo);

         // Chamando método da classe mãe com "super"
        super.mostrarDadosBasicos();

        if (address != null) {
            System.out.println("Endereço: " + address.getRua() + ", " + address.getNumero());
        } else {
            System.out.println("Sem endereço cadastrado.");
        }
    }

}

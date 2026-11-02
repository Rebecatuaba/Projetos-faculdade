import java.util.Objects;

public class User {

    private int id;
    private String name;

    // Construtor vazio (caso precise criar o objeto sem passar valores ainda)
    public User() {
    }

    // Construtor que já recebe id e nome do usuário
    public User(int id, String name) {
        this.id = id;
        this.name = name;
    }

    // Getters e Setters (formas de acessar e mudar valores dos atributos privados)
    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    // Quando o objeto for impresso, vai aparecer no formato abaixo
    @Override
    public String toString() {
        return String.format("{'id': %s, 'name': '%s'}", id, name);
    }

    // Dois usuários são considerados iguais se tiverem mesmo id e mesmo nome
    @Override
    public boolean equals(final Object obj) {
        if (this == obj) return true; // é o mesmo objeto na memória
        if (obj == null || !(obj instanceof User)) return false; // se for null ou tipo diferente
        User user = (User) obj;
        return this.id == user.getId() && Objects.equals(this.name, user.getName());
    }

    // Necessário para coleções baseadas em "Hash", como HashSet
    @Override
    public int hashCode() {
        return Objects.hash(id, name);
    }
}

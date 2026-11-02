public class User {
    // Atributos da classe
    private String name;
    private int age;

    // Construtor
    public User(String name, int age) {
        this.name = name;
        this.age = age;
    }

    // Getters e Setters (para acessar e modificar os atributos)
    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        this.age = age;
    }

    // Método toString para facilitar a impressão do objeto
    @Override
    public String toString() {
        return name + " (" + age + " anos)";
    }
}

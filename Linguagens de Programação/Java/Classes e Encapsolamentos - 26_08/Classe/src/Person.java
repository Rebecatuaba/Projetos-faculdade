// Definição da classe -> define atributos e comportamentos de objetos
public class Person {

    // Atributos privados -> portegem os dados; só podem ser acessados pelos métodos da própria classe
    private String name;
    private int age;

    // Construtor (método especial para criar objetos)
    public Person(String name, int age) {
        this.name = name;  // inicializa o atributo name
        this.age = age;    // inicializa o atributo age
    }

    // Métodos getters e setters -> permitem ler e alterar atributos de forma controlada
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
        if (age >= 0) {      // validação simples
            this.age = age;
        }
    }

    // Método da classe (comportamento do objeto)
    public void sayHello() {
        System.out.println("Hello! My name is " + name + " and I am " + age + " years old.");
    }
}

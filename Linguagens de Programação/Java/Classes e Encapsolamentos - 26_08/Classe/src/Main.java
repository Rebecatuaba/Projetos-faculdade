// Classe principal para testar a clase Person
public class Main {
    public static void main(String[] args) {
        // Criando objetos da classe Person usando o construtor
        Person male = new Person("João", 12);
        Person female = new Person("Maria", 10);

        // Usando métodos da classe (chama o método)
        male.sayHello();
        female.sayHello();

        // Usando setters para mudar atributos
        male.setAge(13);
        female.setName("Ana");

        System.out.println(male.getName() + " now is " + male.getAge() + " years old.");
        System.out.println(female.getName() + " still is " + female.getAge() + " years old.");
    }
}

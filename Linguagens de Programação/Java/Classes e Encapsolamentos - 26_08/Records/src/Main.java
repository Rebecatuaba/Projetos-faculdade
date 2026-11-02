// Classe principal para testar o record Person
public class Main {
    public static void main(String[] args) {

        // Criando objetos do record Person
        Person male = new Person("João", 12);
        Person female = new Person("Maria", 20);

        // Usando métodos do record
        male.sayHello();    // Chama o método sayHello do objeto male
        female.sayHello();  // Chama o método sayHello do objeto female

        // Usando método de validação
        System.out.println(female.name() + " is adult? " + female.isAdult());

        // Observe que não é possível mudar os atributos:
        // female.name = "Ana";  -> Isso daria erro, pois records são imutáveis
    }
}

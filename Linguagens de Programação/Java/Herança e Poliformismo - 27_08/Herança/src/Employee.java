/*Herança é quando uma classe “filha” (subclasse) herda características (atributos e métodos) de uma classe “mãe” (superclasse).
 * Nesse caso a classe Employee vai ser a clase mãe da classe Manager e salesMan
*/

public class Employee {

    private String name;

    private String adress;

    private int age;

    private String code;

    private double salary;

    //Para criar getters and setters, clique na variavel com o btn direto no mouse (atalho: alt shift s)
    //Crique em Source action e em seguina gereate getters and setters
    public double getSalary() {
        return salary;
    }

    public void setSalary(double salary) {
        this.salary = salary;
    }
    public String getCode() {
        return code;
    }

    public void setCode(String code) {
        this.code = code;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getAdress() {
        return adress;
    }

    public void setAdress(String adress) {
        this.adress = adress;
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        this.age = age;
    } 
}
/*
abstract:
- Uma classe abstrata NÃO pode ser criada com "new".
- Serve como molde/base.
- Pode ter métodos sem corpo (abstratos), e as classes filhas são obrigadas a completar.

Exemplo:
abstract class Animal {
    abstract void som(); // sem corpo
}

class Cachorro extends Animal {
    void som() { System.out.println("Au au!"); } // é obrigado a implementar
}


sealed (Java 17+):
- Uma classe selada controla QUEM pode herdar dela.
- Só as classes listadas podem ser filhas.
- As filhas precisam ser: final (não herda mais), sealed (continua limitando) ou non-sealed (abre pra qualquer um).

Exemplo:
sealed class Forma permits Circulo, Quadrado { }

final class Circulo extends Forma { }       // não pode ser herdada
non-sealed class Quadrado extends Forma { } // pode ser herdada normalmente
*/



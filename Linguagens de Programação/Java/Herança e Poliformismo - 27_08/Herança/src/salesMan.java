//A classe salesMan é filha da clsse Emplyee

public class salesMan extends Employee{

    private double percentePerSold;

    public double getPercentePerSold() {
        return percentePerSold;
    }

    public void setPercentePerSold(double percentePerSold) {
        this.percentePerSold = percentePerSold;
    }  
}

/*
instanceof:
- Operador que verifica se um objeto é de um determinado tipo.
- Retorna true ou false.
Exemplo:
    Animal a = new Cachorro();
    System.out.println(a instanceof Animal);   // true
    System.out.println(a instanceof Cachorro); // true
    System.out.println(a instanceof Gato);     // false

Sobrecarga de método (Overloading):
- Vários métodos com o mesmo nome, mas parâmetros diferentes.
- O compilador escolhe qual usar conforme os argumentos.
Exemplo:
    class Calculadora {
        int somar(int a, int b) { return a + b; }
        double somar(double a, double b) { return a + b; }
        int somar(int a, int b, int c) { return a + b + c; }
    }
*/


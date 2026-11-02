/*Polimorfismo → O mesmo método pode se comportar de diferentes formas:
- Sobrecarga (mesmo nome, parâmetros diferentes).
- Sobrescrita (mesmo nome e parâmetros, mas comportamento redefinido na subclasse). */

public class Main {
    public static void main(String[] args) throws Exception {
        Employee employee = new Employee();
        Manager manager = new Manager();

        manager.setName("João");
        manager.setLogin(("joao"));
        manager.setPassword(("123456"));

        System.out.println(manager.getName());
        System.out.println(manager.getLogin());
        System.out.println(manager.getPassword());

        /* Exemplo de Polimorfismo de Sobrescrita
         * Mesmo que Employee, Manager e salesMan sejam tipos diferentes,
         * todos podem ser tratados como "Employee" (classe mãe).
         * O método getName() existe em Employee, mas quem executa
         * é a versão correspondente ao objeto instanciado.
         */

        Employee e1 = new Manager();  // Polimorfismo → objeto Manager tratado como Employee
        e1.setName("Maria");
        System.out.println("Nome (via Employee, mas objeto é Manager): " + e1.getName());

        Employee e2 = new salesMan(); // Polimorfismo → objeto salesMan tratado como Employee
        e2.setName("Carlos");
        System.out.println("Nome (via Employee, mas objeto é salesMan): " + e2.getName());

        /* Exemplo de Polimorfismo de Sobrecarga (Overloading)
         * Não existe ainda na sua classe, mas poderia ser criado
         * um método setSalary() que aceita int e outro que aceita double.
         * Como não podemos alterar o código, o exemplo vai apenas em comentário:
         *
         *   public void setSalary(int salary) {
         *       this.salary = (double) salary;
         *   }
         *
         * Assim teríamos dois métodos com mesmo nome (setSalary),
         * mas aceitando parâmetros diferentes → SOBRECARGA.
         */
    }
}

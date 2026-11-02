/*Um record em Java é como uma classe simplificada para guardar dados de forma prática e segura. 
Ele já cria automaticamente os campos, os “getters” para pegar os valores, e até métodos como toString e equals, 
além de um construtor para definir os valores na hora de criar o objeto. Você pode adicionar métodos próprios, 
tipo uma saudação ou alguma verificação, mas não dá para mudar os valores depois (sem setters) nem estender outra classe. 
É ótimo para quando você só quer um objeto que guarde informações, sem precisar escrever muito código, mas se precisar de comportamentos
 complexos ou herança, aí é melhor usar uma classe normal.*/

// Definição do record Person
public record Person(String name, int age) {

    // Método normal dentro do record
    // Mostra uma saudação com o nome e a idade
    public void sayHello() {
        System.out.println("Hello! My name is " + name + " and I am " + age + " years old.");
    }

    // Método de validação ou cálculo
    // Retorna true se a pessoa for adulta (18 anos ou mais)
    public boolean isAdult() {
        return age >= 18;
    }
}

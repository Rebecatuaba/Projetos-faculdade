/*- Uma interface funcional é uma interface que possui exatamente um único método abstrato.
Ela pode ter também métodos default e métodos static, mas só pode haver um método abstrato principal.
Isso é importante porque esse tipo de interface é usado como base para expressões lambda e method references no Java. 
- Uma expressão lambda é uma forma curta de escrever uma função sem precisar criar uma classe.*/

import java.util.List;
import java.util.function.Function;

public class Main {
    public static void main(String[] args) throws Exception {
        List<User> users = List.of(new User("Maria", 21), new User("João", 32),
        new User("Eduardo", 40), new User("Ana", 19));
    printStringValue(Record::toString, users);

    }

    private static void printStringValue(Function<User, String> callback, List<User> users){
        users.forEach(u -> System.out.println(callback.apply(u)));//expressão lambda (->)
    }
}
/*O Java já traz várias interfaces funcionais prontas como:
- Predicate<T> → retorna boolean (ex.: filtros)
- Function<T, R> → recebe um tipo e retorna outro
- Consumer<T> → recebe um tipo e não retorna nada
- Supplier<T> → não recebe nada, mas retorna um valor
- UnaryOperator<T> → recebe e retorna o mesmo tipo */

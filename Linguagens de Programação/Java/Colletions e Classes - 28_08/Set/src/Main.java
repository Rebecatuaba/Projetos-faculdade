import java.util.Set;
import java.util.HashSet;
import java.util.LinkedHashSet;
import java.util.TreeSet;
import java.util.LinkedList;

public class Main {
    public static void main(String[] args) {
        
        /*
         * O que é Set?
         * - É uma coleção que não permite elementos duplicados.
         * - Se você tentar adicionar o mesmo objeto mais de uma vez, ele não entra de novo.
         *
         * TIPOS DE SET:
         * - HashSet: mais rápido, mas não garante ordem.
         * - LinkedHashSet: mantém a ordem que você adicionou os elementos, mas não aceita duplicados.
         * - TreeSet: mantém em ordem "natural" (númerica ou alfabética), mas precisa que os objetos
         *   sejam comparáveis.
         *
         * DIFERENÇA ENTRE LinkedHashSet e LinkedList:
         * - LinkedList → é uma LISTA: aceita duplicados e você pode acessar por índice (ex: get(0)).
         * - LinkedHashSet → é um CONJUNTO: não aceita duplicados, não tem índice, mas mantém a ordem de inserção.
         */
        
        // ------------------------------
        // 1) Exemplo com HashSet (não garante ordem)
        // ------------------------------
        Set<User> users = new HashSet<>();
        users.add(new User(1, "João"));
        users.add(new User(2, "Maria"));
        users.add(new User(3, "Juca"));
        users.add(new User(4, "Leo"));
        users.add(new User(5, "Flávia"));

        // Tentando adicionar duplicado
        users.add(new User(1, "João")); // não entra de novo

        System.out.println("---- HashSet (sem ordem garantida) ----");
        users.forEach(System.out::println);

        // ------------------------------
        // 2) Verificando se existe um usuário
        // ------------------------------
        System.out.println("\nContém João? " + users.contains(new User(1, "João"))); // true
        System.out.println("Contém Pedro? " + users.contains(new User(6, "Pedro"))); // false

        // ------------------------------
        // 3) Removendo um usuário
        // ------------------------------
        users.remove(new User(2, "Maria")); 
        System.out.println("\nApós remover Maria:");
        users.forEach(System.out::println);

        // ------------------------------
        // 4) LinkedHashSet (mantém ordem de inserção)
        // ------------------------------
        Set<User> linkedUsers = new LinkedHashSet<>();
        linkedUsers.add(new User(10, "Ana"));
        linkedUsers.add(new User(11, "Beto"));
        linkedUsers.add(new User(12, "Carla"));
        linkedUsers.add(new User(10, "Ana")); // duplicado, ignorado

        System.out.println("\n---- LinkedHashSet (ordem de inserção) ----");
        linkedUsers.forEach(System.out::println);

        // ------------------------------
        // 5) TreeSet (ordem automática) 
        // Aqui usaremos String por simplicidade
        // ------------------------------
        Set<String> names = new TreeSet<>();
        names.add("Zeca");
        names.add("Ana");
        names.add("João");

        System.out.println("\n---- TreeSet (ordem alfabética) ----");
        names.forEach(System.out::println);

        // ------------------------------
        // 6) LinkedList (para comparar com LinkedHashSet)
        // ------------------------------
        LinkedList<String> list = new LinkedList<>();
        list.add("A");
        list.add("B");
        list.add("A"); // duplicado permitido

        System.out.println("\n---- LinkedList (aceita duplicados e acessa por índice) ----");
        System.out.println(list); // [A, B, A]
        System.out.println("Primeiro elemento da lista: " + list.get(0));
    }
}

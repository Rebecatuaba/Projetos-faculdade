import java.util.Map;
import java.util.HashMap;
import java.util.LinkedHashMap;
import java.util.TreeMap;

public class Main {
    public static void main(String[] args) {

        // ==================================================
        // O que é um Map?
        // ==================================================
        // Map é uma coleção de pares chave-valor (key-value). -> quando você quer procurar algo rapidamente a partir de uma chave.
        // Cada chave é única, mas os valores podem se repetir.
        // Exemplos de implementações:
        // - HashMap: não mantém ordem, permite null como chave e valor
        // - LinkedHashMap: mantém a ordem de inserção
        // - TreeMap: mantém as chaves ordenadas
        // ==================================================

        // Criando um HashMap
        Map<String, User> users = new HashMap<>();

        // Adicionando elementos ao Map
        users.put("joao@joao.com", new User("João", 22));
        users.put("maria@maria.com", new User("Maria", 32));
        users.put("juca@juca.com", new User("Juca", 18));
        users.put("leo@leo.com", new User("Leo", 40));

        // Imprime se o Map está vazio
        System.out.println("O Map está vazio? " + users.isEmpty());

        // Acessando um valor a partir da chave
        System.out.println("Usuário joao@joao.com: " + users.get("joao@joao.com"));

        // Tentando adicionar apenas se não existir
        users.putIfAbsent("ana@ana.com", new User("Ana", 25));

        // Merge: combina valores se a chave existir, ou adiciona se não existir
        users.merge("maria@maria.com", new User("Mariazinha", 33), (oldUser, newUser) -> {
            System.out.println("Merge chamado para chave existente:");
            System.out.println("Antigo: " + oldUser);
            System.out.println("Novo: " + newUser);
            return oldUser; // você pode escolher manter o antigo ou substituir
        });

        // Removendo um elemento pelo valor da chave
        users.remove("juca@juca.com");

        // Verificando se uma chave ou valor existe
        System.out.println("Contém chave leo@leo.com? " + users.containsKey("leo@leo.com"));
        System.out.println("Contém valor João (22)? " + users.containsValue(new User("João", 22))); 
        // Obs: containsValue vai retornar false aqui porque User precisa de equals() para comparar corretamente

        // Iterando sobre o Map
        System.out.println("\nIterando sobre o Map:");
        for (Map.Entry<String, User> entry : users.entrySet()) {
            System.out.println("Chave: " + entry.getKey() + " -> Valor: " + entry.getValue());
        }

        // Impressão final do Map
        System.out.println("\nMap final: " + users);

        // ==================================================
        // Outras funções úteis de Map (comentadas para estudo):
        // ==================================================
        // users.clear();           // remove todos os elementos do Map
        // users.size();            // retorna o número de elementos
        // users.keySet();          // retorna um Set com todas as chaves
        // users.values();          // retorna uma Collection com todos os valores
        // users.entrySet();        // retorna um Set com todas as entradas (key-value)
        // users.replace(key, newValue); // substitui o valor da chave se existir
        // users.compute(key, (k, v) -> ... ); // recalcula o valor de uma chave
        // users.forEach((k,v) -> ... );      // iterando de forma funcional
    }
}

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Main {
    public static void main(String[] args) {

        /*
         * ===================== ARRAYS =====================
         * - Estrutura de dados fixa (não muda de tamanho depois de criada).
         * - Mais performático que listas, pois está em memória contígua. -> Memória contígua significa que os elementos de um array ficam armazenados lado a lado na memória.
         * - Precisa definir o tamanho ao criar.
         * - Pode armazenar tipos primitivos (int, double, char) e objetos.
         */

        // Criando um array de inteiros com tamanho 5
        int[] numeros = new int[5];

        // Inserindo valores (índices começam em 0)
        numeros[0] = 10;
        numeros[1] = 20;
        numeros[2] = 30;
        numeros[3] = 40;
        numeros[4] = 50;

        // Acessando valores do array
        System.out.println("Primeiro elemento do array: " + numeros[0]);
        System.out.println("Último elemento do array: " + numeros[numeros.length - 1]);

        // Percorrendo o array com for tradicional
        System.out.println("\nElementos do array com for:");
        for (int i = 0; i < numeros.length; i++) {
            System.out.println("Índice " + i + " -> " + numeros[i]);
        }

        // Percorrendo com for-each (mais simples)
        System.out.println("\nElementos do array com for-each:");
        for (int valor : numeros) {
            System.out.println(valor);
        }

        // Criando array com valores pré-definidos
        String[] frutas = {"Maçã", "Banana", "Uva"};

        System.out.println("\nArray de frutas: " + Arrays.toString(frutas));

        /*
         * Limitações do array:
         * - Tamanho fixo
         * - Dificuldade para adicionar/remover elementos
         * - Precisa criar um novo array para aumentar a capacidade
         */


        /*
         * ===================== LISTAS (ArrayList) =====================
         * - O java tem várias implementações de listas dentro do pacote java.util, cada uma com suas características.
         * - Estrutura de dados dinâmica (cresce e diminui de tamanho automaticamente).
         * - Mais flexível, mas um pouco menos performática que arrays.
         * - Só aceita objetos (não aceita primitivos diretamente).
         *   -> Exemplo: usamos Integer em vez de int, Double em vez de double.
         * - Faz parte do pacote java.util.
         */

        // Criando uma lista de inteiros
        List<Integer> listaNumeros = new ArrayList<>();

        // Adicionando elementos
        listaNumeros.add(10);
        listaNumeros.add(20);
        listaNumeros.add(30);

        // Acessando elementos (método get)
        System.out.println("\nPrimeiro elemento da lista: " + listaNumeros.get(0));
        System.out.println("Tamanho da lista: " + listaNumeros.size());

        // Alterando elemento
        listaNumeros.set(1, 99); // substitui o elemento no índice 1
        System.out.println("Lista após alteração: " + listaNumeros);

        // Removendo elemento por índice
        listaNumeros.remove(0);
        System.out.println("Lista após remover índice 0: " + listaNumeros);

        // Percorrendo a lista com for tradicional
        System.out.println("\nElementos da lista com for:");
        for (int i = 0; i < listaNumeros.size(); i++) {
            System.out.println("Índice " + i + " -> " + listaNumeros.get(i));
        }

        // Percorrendo a lista com for-each
        System.out.println("\nElementos da lista com for-each:");
        for (Integer valor : listaNumeros) {
            System.out.println(valor);
        }

        // Lista com Strings
        List<String> nomes = new ArrayList<>();
        nomes.add("Ana");
        nomes.add("João");
        nomes.add("Maria");

        System.out.println("\nLista de nomes: " + nomes);

        /*
         * Diferenças principais:
         * ARRAY:
         * - Estrutura fixa, mais rápida, aceita primitivos.
         * - Bom quando já sabemos o tamanho fixo dos dados.
         *
         * LISTA (ArrayList):
         * - Estrutura dinâmica, mais flexível, não aceita primitivos diretamente.
         * - Permite adicionar/remover elementos facilmente.
         * - Bom quando não sabemos o tamanho final dos dados.
         */
    }
}

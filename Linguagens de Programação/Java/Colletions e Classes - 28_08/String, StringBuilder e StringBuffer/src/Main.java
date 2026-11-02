// ================================================
// Objetivo: Processar textos usando String, StringBuilder e StringBuffer
// Mostrando manipulações, comparações, métodos e boas práticas
// ================================================

public class Main {
    public static void main(String[] args) {

        // ==================================================
        // 1️⃣ Trabalhando com String
        // ==================================================
        // String é imutável. Toda alteração cria um novo objeto.
        String text = "Aprendendo Java";
        String name = "João";

        // Concatenação
        String greeting = "Olá, " + name + "! " + text; // cria nova String
        System.out.println("String:");
        System.out.println(greeting);

        // Métodos importantes
        System.out.println("Tamanho da String: " + greeting.length());
        System.out.println("Maiúsculas: " + greeting.toUpperCase());
        System.out.println("Minúsculas: " + greeting.toLowerCase());
        System.out.println("SubString (a partir do índice 5): " + greeting.substring(5));
        System.out.println("Contém 'Java'? " + greeting.contains("Java"));
        System.out.println("Índice de 'João': " + greeting.indexOf("João"));

        // ==================================================
        // 2️⃣ Trabalhando com StringBuilder
        // ==================================================
        // StringBuilder é mutável, eficiente para várias alterações
        StringBuilder sb = new StringBuilder();
        sb.append("Texto inicial");
        sb.append(" e mais texto");
        sb.insert(0, "Mensagem: ");     // insere no início
        sb.replace(10, 16, "MODIFICADO"); // substitui parte do texto
        sb.delete(5, 10);               // remove parte do texto
        System.out.println("\nStringBuilder:");
        System.out.println(sb);

        // Métodos úteis
        System.out.println("Tamanho: " + sb.length());
        System.out.println("Capacidade interna: " + sb.capacity());
        sb.reverse(); // inverte o texto
        System.out.println("Invertido: " + sb);
        sb.reverse(); // volta ao normal

        // ==================================================
        // 3️⃣ Trabalhando com StringBuffer
        // ==================================================
        // StringBuffer é igual ao StringBuilder, mas é thread-safe
        StringBuffer sbuf = new StringBuffer("Buffer inicial");
        sbuf.append(" + adicionando texto");
        sbuf.insert(0, "Aviso: ");
        System.out.println("\nStringBuffer:");
        System.out.println(sbuf);

        // Métodos úteis (mesmos que StringBuilder)
        System.out.println("Tamanho: " + sbuf.length());
        System.out.println("Capacidade: " + sbuf.capacity());
        sbuf.reverse();
        System.out.println("Invertido: " + sbuf);
        sbuf.reverse(); // volta ao normal

        // ==================================================
        // 4️⃣ Objetivo prático do programa
        // ==================================================
        // Vamos criar uma pequena rotina de "processamento de texto":
        // - Receber um texto inicial (String)
        // - Modificar com StringBuilder (inserir, substituir)
        // - Criar versão thread-safe com StringBuffer
        // - Contar palavras, verificar ocorrência de uma palavra específica

        String input = "Java é incrível. Java é poderoso. Java é divertido.";
        StringBuilder sbProcess = new StringBuilder(input);

        // Substituir "Java" por "JAVA" usando StringBuilder
        int index = sbProcess.indexOf("Java");
        while(index != -1) {
            sbProcess.replace(index, index + 4, "JAVA");
            index = sbProcess.indexOf("Java", index + 4); // procura próximo
        }

        System.out.println("\nStringBuilder processado (Java -> JAVA):");
        System.out.println(sbProcess);

        // Criar versão segura para threads com StringBuffer
        StringBuffer safeBuffer = new StringBuffer(sbProcess.toString());

        // Contar palavras
        String[] words = safeBuffer.toString().split(" ");
        System.out.println("\nContagem de palavras: " + words.length);

        // Verificar ocorrência de "JAVA"
        int countJava = 0;
        for(String word : words) {
            if(word.contains("JAVA")) {
                countJava++;
            }
        }
        System.out.println("Número de vezes que 'JAVA' aparece: " + countJava);

        // ==================================================
        // 5️⃣ Observações e boas práticas
        // ==================================================
        // - Use String para textos curtos e poucas alterações
        // - Use StringBuilder para muitas alterações de texto (melhor desempenho)
        // - Use StringBuffer quando precisar de thread-safe
        // - Métodos importantes:
        //   String: length(), substring(), contains(), indexOf(), toUpperCase(), toLowerCase()
        //   StringBuilder/StringBuffer: append(), insert(), replace(), delete(), reverse(), capacity(), length()
        // - Para grandes projetos, evite concatenações repetidas com String, prefira StringBuilder

        // ==================================================
        // 6️⃣ Possibilidades extras (comentadas)
        // ==================================================
        // - Converter StringBuilder/StringBuffer para String: sb.toString()
        // - Substituir palavras usando replaceAll() em String
        // - Remover espaços extras usando trim()
        // - Transformar todas palavras para maiúsculas/minúsculas
        // - Comparar Strings usando equals() ou equalsIgnoreCase()
        // - Iterar sobre caracteres: charAt(i)
    }
}

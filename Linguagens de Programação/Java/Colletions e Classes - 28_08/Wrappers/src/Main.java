// ================================================
// Arquivo: Main.java
// ================================================
public class Main {
    public static void main(String[] args) {

        // ==================================================
        // Tipos Primitivos - são os tipos de váriaveis basicamente
        // ==================================================
        // São tipos básicos da linguagem, ocupam menos memória e não possuem métodos.
        // Exemplos:
        int idade = 25;           // número inteiro
        double altura = 1.75;     // número decimal
        char sexo = 'F';          // caractere
        boolean estudante = true; // verdadeiro ou falso
        byte pequeno = 10;        // inteiro pequeno (-128 a 127)
        short curto = 30000;      // inteiro curto
        long grande = 1000000000L;// inteiro grande
        float decimal = 3.14f;    // decimal simples

        System.out.println("Tipos primitivos:");
        System.out.println("Idade: " + idade);
        System.out.println("Altura: " + altura);
        System.out.println("Sexo: " + sexo);
        System.out.println("Estudante? " + estudante);
        System.out.println("Byte: " + pequeno + ", Short: " + curto + ", Long: " + grande + ", Float: " + decimal);

        // ==================================================
        // Classes Wrapper
        // ==================================================
        // Cada tipo primitivo tem uma classe equivalente chamada Wrapper
        // Ela "embrulha" o valor primitivo em um objeto, permitindo usar métodos.
        // Exemplo:
        Integer idadeWrapper = Integer.valueOf(25);
        Double alturaWrapper = Double.valueOf(1.75);
        Character sexoWrapper = Character.valueOf('F');
        Boolean estudanteWrapper = Boolean.valueOf(true);

        // Autoboxing: conversão automática de primitivo para wrapper
        Integer idadeAuto = idade;  // int -> Integer
        Double alturaAuto = altura; // double -> Double

        // Unboxing: conversão automática de wrapper para primitivo
        int idadeUnbox = idadeWrapper; // Integer -> int
        double alturaUnbox = alturaWrapper; // Double -> double

        System.out.println("\nClasses Wrapper:");
        System.out.println("Idade Wrapper: " + idadeWrapper);
        System.out.println("Altura Wrapper: " + alturaWrapper);
        System.out.println("Sexo Wrapper: " + sexoWrapper);
        System.out.println("Estudante Wrapper: " + estudanteWrapper);

        // ==================================================
        // Métodos importantes das classes Wrapper
        // ==================================================
        String numeroString = "123";
        int numero = Integer.parseInt(numeroString); // Converte String para int
        double numeroDouble = Double.parseDouble("3.1415"); // Converte String para double

        // Converte wrapper para String
        String idadeString = idadeWrapper.toString();

        // Valores máximos e mínimos de cada tipo
        System.out.println("\nValores máximos e mínimos:");
        System.out.println("Integer max: " + Integer.MAX_VALUE + ", min: " + Integer.MIN_VALUE);
        System.out.println("Double max: " + Double.MAX_VALUE + ", min: " + Double.MIN_VALUE);

        // Comparação de wrappers
        Integer a = 1000;
        Integer b = 1000;
        System.out.println("\nComparação de Wrappers:");
        System.out.println("a == b ? " + (a == b)); // Falso, pois compara referências
        System.out.println("a.equals(b) ? " + a.equals(b)); // Verdadeiro, compara valores

        // ==================================================
        // Outras funções úteis
        // ==================================================
        // Boolean.parseBoolean("true") -> true
        // Byte.parseByte("127") -> 127
        // Short.parseShort("32767") -> 32767
        // Long.parseLong("1000000000") -> 1000000000L
        // Float.parseFloat("3.14") -> 3.14f
        // Character.isDigit('5') -> true
        // Character.isLetter('A') -> true
        // Integer.sum(10, 20) -> 30
        // Double.compare(3.14, 2.71) -> >0
    }
}

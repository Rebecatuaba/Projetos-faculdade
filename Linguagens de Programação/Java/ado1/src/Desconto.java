public class Desconto {
    static void main(String[] args) {
        double precoOriginal = 45.99;
        double percentualDesconto = 10;

        precoOriginal = (precoOriginal * percentualDesconto)/100 - precoOriginal;

        System.out.println("Valor c/ desconto: " + precoOriginal);
    }
}

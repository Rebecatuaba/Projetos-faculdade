public class Condicional {
    public static void main(String[] args) {
        int anoDeLancamento = 2009; //2025
        boolean incluidoNoPlano = true;
        double notaDoFilme = 7.9;
        String tipoPlano = "plus"; // ou "normal"

        if (anoDeLancamento >= 2024){
            System.out.println("Lançamento que os clientes estão curtindo!");
        }else{
            System.out.println("Filme retrô que vale apena assistir!");
        }

        if (incluidoNoPlano == true && tipoPlano.equals("plus")){ // da pra usar == e .equals
            System.out.println("Filme liberado!");
        }else {
            System.out.println("Deve pagar a locação!");
        }
    }
}

import java.time.OffsetDateTime;//importação da classe para pegar o ano atual
import java.util.Scanner;//importação da clase scanner

public class Main {
    public static void main(String[] args) {
        var nasc = OffsetDateTime.now().getYear();//OffsetDateTime.now() pega a data e hora atuais/.getYear() extrai só o ano
        Scanner scanner = new Scanner(System.in);  
        System.out.println("Digite o seu nome:");  
        String name = scanner.next();  

        System.out.println("Digite o seu ano de nascimento:");  
        int year = scanner.nextInt();  
        var age = nasc - year; 
        System.out.printf("Olá %s você tem %d anos\n", name, age);  
    }

}

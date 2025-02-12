import java.util.Scanner;

public class Palindromo{
    public static boolean palindromo(String string) {
        
        boolean palindromo = true;
        int inicio = 0;
        int fim = string.length() - 1;
        
        while (inicio < fim) {
            if (string.charAt(inicio) != string.charAt(fim)){
                palindromo = false;
            }
            inicio++;
            fim--;
        }
        return palindromo;
    }

    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);
        String entrada = scanner.nextLine();
        
        while (!entrada.equals("FIM")){
            System.out.println(palindromo(entrada) ? "SIM" : "NAO");
            entrada = scanner.nextLine();
        }
        
        scanner.close();
    }
}

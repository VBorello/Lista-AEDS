import java.util.*;

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
        
        while(!(entrada.length() == 3 && entrada.charAt(0) == 'F' && entrada.charAt(1) == 'I' && entrada.charAt(2) == 'M')){

            if(palindromo(entrada)){
                System.out.println("SIM");  
            }
            else{
                System.out.println("NAO");
            }
            entrada = scanner.nextLine();
        }

        scanner.close();
    }
}

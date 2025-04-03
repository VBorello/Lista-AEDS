import java.util.Scanner;

public class PalindromoRec {

    public static boolean palindromo(String string, int tam, int index) {

        if(index >= tam) {
            return true;
        }

        if(string.charAt(index) != string.charAt(tam)) {
            return false;
        }
        return palindromo(string, tam - 1, index + 1);
    }

    public static void main(String[] args) {
        
        Scanner scanner = new Scanner(System.in);
        String entrada = scanner.nextLine();
        

        while(!(entrada.length() == 3 && entrada.charAt(0) == 'F' && entrada.charAt(1) == 'I' && entrada.charAt(2) == 'M')){ 

            
            int tam = entrada.length() - 1;
            if(palindromo(entrada, tam, 0)){
                
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

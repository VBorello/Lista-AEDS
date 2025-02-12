import java.util.*;

public class AlfabetoAlienigena{

    public static void apresentacao(){
        System.out.println("\nAlfabeto Alienigena");
    }

    public static String lerKey(){
        
        Scanner scanner = new Scanner(System.in);
        System.out.printf("\nDigite uma key: ");
        String key = scanner.nextLine();

        return key;
    }

    public static String lerFrase(){

        Scanner scanner = new Scanner(System.in);
        System.out.printf("\nDigite uma frase: ");
        String frase = scanner.nextLine();

        scanner.close();

        return frase;
    }

    public static int comparar(String key, String frase){
        
        int iguais = 0;

        for(int i = 0; i < key.length(); i++){
            for(int j = 0; j < frase.length(); j++){
                if(key.charAt(i) == frase.charAt(j)){
                    iguais++;
                }
            }
        }

        return iguais;

    }
     public static void main(String[] args) {
        
        apresentacao();

        String key = lerKey();
        String frase = lerFrase();

        int iguais = comparar(key, frase);
    
    
        System.out.println("\nNúmero de caracteres iguais: " + iguais);
    }

}
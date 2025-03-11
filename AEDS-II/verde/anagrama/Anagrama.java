import java.util.Scanner;

public class Anagrama{
    
    public static boolean anagrama(String string1, String string2){

        string1 = string1.toLowerCase();
        string2 = string2.toLowerCase();

        if (string1.length() != string2.length()){
            return false;
        }

        int[] letras = new int[Character.MAX_VALUE + 1];

        for (int i = 0; i < string1.length(); i++){
            letras[string1.charAt(i)]++; 
            letras[string2.charAt(i)]--; 
        }

        for (int i = 0; i < 256; i++){
            if (letras[i] != 0){
                return false;
            }
        }

        return true;
    }

    public static void main(String[] args){

        Scanner scanner = new Scanner(System.in, "UTF-8");

        String entrada = scanner.nextLine();


        while(!(entrada.length() == 3 && entrada.charAt(0) == 'F' && entrada.charAt(1) == 'I' && entrada.charAt(2) == 'M')){

            String[] partes = entrada.split(" - ");
            if(partes.length == 2){
                String string1 = partes[0];
                String string2 = partes[1];

                if (anagrama(string1, string2)){
                    System.out.println("SIM");
                }
                else{
                    System.out.println("NÃO");
                }
            }
            entrada = scanner.nextLine();
        }

        scanner.close();
    }
}

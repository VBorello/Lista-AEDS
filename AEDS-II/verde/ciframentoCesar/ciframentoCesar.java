import java.util.*;

public class ciframentoCesar{

    public static String cifrarCesar(String frase){

        String cesar = "";

        for(int i = 0; i < frase.length(); i++){

            char caractere = frase.charAt(i);
            cesar += (char) (caractere + 3);
        }

        return cesar;
    }

    public static void main(String[] args){
        
        Scanner scanner = new Scanner(System.in);

        while(scanner.hasNextLine()){
            String linha = scanner.nextLine();
            System.out.println(cifrarCesar(linha)); 
        }
    
        scanner.close();
    }
}
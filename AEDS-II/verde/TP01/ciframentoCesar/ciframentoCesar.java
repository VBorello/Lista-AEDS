import java.util.*;

public class ciframentoCesar{

    public static String cifrarCesar(String palavra){

        char[] cifrada = new char[palavra.length()];

        for(int i = 0; i < palavra.length(); i++){
            
            cifrada[i] = palavra.charAt(i);

            if(palavra.charAt(i) >= 0 && palavra.charAt(i) <= 127)
                cifrada[i] += 3;
        }

        return new String(cifrada);
    }

    public static void main(String[] args){
        
        Scanner scanner = new Scanner(System.in);
        String linha = scanner.nextLine();

        while(!(linha.length() == 3 && linha.charAt(0) == 'F' && linha.charAt(1) == 'I' && linha.charAt(2) == 'M')){
            
            System.out.println(cifrarCesar(linha)); 
            linha = scanner.nextLine();
        }
    
        scanner.close();
    }
}
import java.util.*;

public class ContagemDePalavras{

    public static int contarPalavras(String string){

        int palavras = 0;
        boolean mesmaPalavra = false;

        for(int i = 0; i < string.length(); i++){
            
            char c = string.charAt(i);

            if(c == ' '){
                mesmaPalavra = false;
            }
            else if(!(mesmaPalavra)){
                palavras++;
                mesmaPalavra = true;
            }
        }

        return palavras;
    }

    public static void main(String[] args){
        
        Scanner scanner = new Scanner(System.in);

        String string = scanner.nextLine();

        System.out.println(contarPalavras(string));

        scanner.close();
    }
}
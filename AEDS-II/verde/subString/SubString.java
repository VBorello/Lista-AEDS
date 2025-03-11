import java.util.*;

public class SubString{

    public static String contarRepeticoes(String string){

        int qtdDif = 0;

        for(int i = 0; i < string.length(); i++){
            char c = string.charAt(i);

            String diferentes[];

            c = diferentes[i];
            qtdDif++;
            if(c == diferentes[i - 1]){
                qtdDif--;
            }
        }
    
        return qtdDif;
    }

    public static void main(String[] args){

        Scanner scanner = new Scanner(Sytem.in);
        String string = scanner.nextLine();

        if(!(string.length() == 3 && string.charAt(0) == 'F' && string.charAt(1) == 'I' && string.charAt(2) == 'M')){
            
        }
    }

}
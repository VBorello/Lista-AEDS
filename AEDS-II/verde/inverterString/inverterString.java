import java.util.*;

public class inverterString{

    public static String inverterString(String palavra){

        String palvaraInvertida = "";
        int tamanho = palavra.length();

        for(int i = tamanho - 1; i >= 0; i--){
            palvaraInvertida += palavra.charAt(i);
        }

        return palvaraInvertida;
    }

    public static void main(String[] args){

        Scanner scanner = new Scanner(System.in);
        String palavra = scanner.nextLine();

        String palvaraInvertida = inverterString(palavra);

        System.out.println("\ninvertida: " + palvaraInvertida);

        scanner.close();
    }
}
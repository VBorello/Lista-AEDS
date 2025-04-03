import java.util.*;

public class SubString {

    public static int contarRepeticoes(String string){

        boolean[] unicas = new boolean[256];//tabela ASCII
        int qtdDif = 0;//quantidade de caracteres diferentes
        int tamMaiorSubstring = 0;//maior subString de caracteres diferentes

        for (int i = 0; i < string.length(); i++) {
            char c = string.charAt(i);

            if (!unicas[c]){
                unicas[c] = true;
                qtdDif++;

                //atualiza tamMaiorSubstring manualmente
                if (qtdDif > tamMaiorSubstring){

                    tamMaiorSubstring = qtdDif;
                }
            } 
            else{

                i = i - qtdDif;
                qtdDif = 0;
                unicas = new boolean[256];
            }
        }

        return tamMaiorSubstring;
    }

    public static void main(String[] args){

        Scanner scanner = new Scanner(System.in);
        String string = scanner.nextLine();

        while (!(string.length() == 3 && string.charAt(0) == 'F' && string.charAt(1) == 'I' && string.charAt(2) == 'M')){
            System.out.println(contarRepeticoes(string));
            string = scanner.nextLine();
        }

        scanner.close();
    }
}

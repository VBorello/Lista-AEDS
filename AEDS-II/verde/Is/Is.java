import java.util.*;

public class Is{

    public static boolean isApenasVogais(String palavra){

        boolean soVogais = true;
        int i = 0;
        while(i < palavra.length()){

            char c = palavra.charAt(i);
            if(c != 'a' && c != 'A' &&
                c != 'e' && c != 'E' &&
                c != 'i' && c != 'I' &&
                c != 'o' && c != 'O' &&
                c != 'u' && c != 'U'){
                    soVogais = false;
                }

                i++;
        }

        return soVogais;
    }

    public static boolean isApenasConso(String palavra){

        boolean soConso = true;
        int i = 0;
        while(i < palavra.length()){

            char c = palavra.charAt(i);
            if(c == 'a' || c == 'A' ||
                c == 'e' || c == 'E' ||
                c == 'i' || c == 'I' ||
                c == 'o' || c == 'O' ||
                c == 'u' || c == 'U'){
                    soConso = false;
                }

                i++;
        }

        return soConso;
    }

    public static boolean isInteiro(String palavra){

        int i = 0;
        boolean inteiro = true;
    
        while(i < palavra.length()){
            if(!(palavra.charAt(i) >= '0' && palavra.charAt(i) <= '9')){
                inteiro = false;
            }
            i++;
        }
    
        return inteiro;
    }

    public static boolean isReal(String palavra){

        int i = 0;
        boolean isReal = true;
    
        while(i < palavra.length()){
            if(!(palavra.charAt(i) >= '0' && palavra.charAt(i) <= '9' ||
                (palavra.charAt(i) == ',' || palavra.charAt(i) == '.'))){
                isReal = false;
            }
            i++;
        }
    
        return isReal;
    }

    public static void main(String[] args){

        Scanner scanner = new Scanner (System.in);
        String palavra = scanner.nextLine();

        String sim = "SIM";
        String nao = "NAO";

        String x1, x2, x3, x4;

        while(!(palavra.length() == 3 &&
            palavra.charAt(0) == 'F' &&
            palavra.charAt(1) == 'I' &&
            palavra.charAt(2) == 'M')) {

                if(isApenasVogais(palavra)){
                    x1 = sim;
                } 
                else{
                    x1 = nao;
                } 
                if(isApenasConso(palavra)){
                    x2 = sim;
                } 
                else{
                     x2 = nao;
                }
                if(isInteiro(palavra)){
                     x3 = sim;
                }
                else{
                     x3 = nao;
                }
                if(isReal(palavra)){
                     x4 = sim;
                }
                else{
                     x4 = nao;
                }
                
            System.out.println(x1 + " " + x2 + " " + x3 + " " + x4);
            palavra = scanner.nextLine();
        }

        scanner.close();

    }
}
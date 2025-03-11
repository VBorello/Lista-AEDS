import java.util.*;

public class IsRec {

    public static boolean isApenasVogais(String palavra) {
        return isApenasVogaisRec(palavra, 0);
    }
    
    private static boolean isApenasVogaisRec(String palavra, int i) {
        if(i >= palavra.length()) {
            return true;
        }
        char c = palavra.charAt(i);
        if(!(c == 'a' || c == 'A' ||
             c == 'e' || c == 'E' ||
             c == 'i' || c == 'I' ||
             c == 'o' || c == 'O' ||
             c == 'u' || c == 'U')) {
            return false;
        }
        return isApenasVogaisRec(palavra, i + 1);
    }

    public static boolean isApenasConso(String palavra) {
        return isApenasConsoRec(palavra, 0);
    }
    
    private static boolean isApenasConsoRec(String palavra, int i) {
        if(i >= palavra.length()) {
            return true;
        }
        char c = palavra.charAt(i);
        if(c == 'a' || c == 'A' ||
           c == 'e' || c == 'E' ||
           c == 'i' || c == 'I' ||
           c == 'o' || c == 'O' ||
           c == 'u' || c == 'U') {
            return false;
        }
        return isApenasConsoRec(palavra, i + 1);
    }

    public static boolean isInteiro(String palavra) {
        return isInteiroRec(palavra, 0);
    }
    
    private static boolean isInteiroRec(String palavra, int i) {
        if(i >= palavra.length()) {
            return true;
        }
        char c = palavra.charAt(i);
        if(c < '0' || c > '9') {
            return false;
        }
        return isInteiroRec(palavra, i + 1);
    }

    public static boolean isReal(String palavra) {
        return isRealRec(palavra, 0);
    }
    
    private static boolean isRealRec(String palavra, int i) {
        if(i >= palavra.length()) {
            return true;
        }
        char c = palavra.charAt(i);
        if(!((c >= '0' && c <= '9') || c == ',' || c == '.')) {
            return false;
        }
        return isRealRec(palavra, i + 1);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String palavra = scanner.nextLine();
        
        String sim = "SIM";
        String nao = "NAO";

        while(!(palavra.length() == 3 &&
                palavra.charAt(0) == 'F' &&
                palavra.charAt(1) == 'I' &&
                palavra.charAt(2) == 'M')) {
            
            String x1 = isApenasVogais(palavra) ? sim : nao;
            String x2 = isApenasConso(palavra) ? sim : nao;
            String x3 = isInteiro(palavra) ? sim : nao;
            String x4 = isReal(palavra) ? sim : nao;
            
            System.out.println(x1 + " " + x2 + " " + x3 + " " + x4);
            
            palavra = scanner.nextLine();
        }
        
        scanner.close();
    }
}

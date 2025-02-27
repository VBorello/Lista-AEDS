import java.util.*;

public class CiframentoCesarRec{

    public static String ciframento(String string, int index, char[] cifrada){

        if(index < string.length()){
            
            cifrada[index] = (char) (string.charAt(index) + 3);
            return ciframento(string, index + 1, cifrada);
        }
        else{
            return new String(cifrada);
        }
    }

    public static void main(String[] args){

        Scanner scanner = new Scanner(System.in);
        String string = scanner.nextLine();

        while(!(string.length() == 3 && string.charAt(0) == 'F' && string.charAt(1) == 'I' && string.charAt(2) == 'M')){
            
            char[] cifrada = new char[string.length()];
            System.out.println(ciframento(string, 0, cifrada)); 
            
            string = scanner.nextLine();
        }

        scanner.close();
    }
}
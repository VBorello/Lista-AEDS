import java.util.*;

public class CiframentoCesarRec{

    public static String ciframento(String string, char[] cifrada, int index){

        if(index == string.length()){
            return new String(cifrada);
        }

        cifrada[index] = string.charAt(index);

        if(string.charAt(index) >= 0 && string.charAt(index) <= 127){
            cifrada[index] += 3;
        }

        return ciframento(string, cifrada, index + 1);
    }

    public static void main(String[] args){

        Scanner scanner = new Scanner(System.in);
        String string = scanner.nextLine();

        while(!(string.length() == 3 && string.charAt(0) == 'F' && string.charAt(1) == 'I' && string.charAt(2) == 'M')){
            
            char[] cifrada = new char[string.length()];
            System.out.println(ciframento(string, cifrada, 0)); 
            
            string = scanner.nextLine();
        }

        scanner.close();
    }
}
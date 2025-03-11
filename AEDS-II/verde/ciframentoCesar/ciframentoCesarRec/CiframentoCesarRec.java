import java.util.*;

public class CiframentoCesarRec{

    public static String ciframento(String string, int index){

        int tam = string.length();
        char[] cifrada = new char[string.length()];

        if(index < tam){
            
            cifrada[index] = string.charAt(index);
            
            if(string.charAt(index) >= 0 && string.charAt(index) <= 127){
                cifrada[index] += 3;
            }
        }
        else{
            return new String(cifrada);
        }

        return ciframento(string, index + 1);
    }

    public static void main(String[] args){

        Scanner scanner = new Scanner(System.in);
        String string = scanner.nextLine();

        while(!(string.length() == 3 && string.charAt(0) == 'F' && string.charAt(1) == 'I' && string.charAt(2) == 'M')){
            
            System.out.println(ciframento(string, 0)); 
            
            string = scanner.nextLine();
        }

        scanner.close();
    }
}
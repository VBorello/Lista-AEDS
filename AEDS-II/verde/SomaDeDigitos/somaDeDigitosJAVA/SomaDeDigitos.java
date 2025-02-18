import java.util.*;

public class SomaDeDigitos{

    public static int somarDigitos(int n){
        
        if(n == 0){
            return 0;
        }

        return(n % 10) + somarDigitos(n / 10);

    }

    public static void main(String[] args){

        Scanner scanner = new Scanner(System.in);
        
        while(scanner.hasNextInt()){
            int n = scanner.nextInt();
            System.out.println(somarDigitos(n));
        }

        scanner.close();
    }
}
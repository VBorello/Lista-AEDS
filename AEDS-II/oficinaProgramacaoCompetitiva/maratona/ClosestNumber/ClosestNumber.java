import java.util.*;

public class ClosestNumber{

    public static void main(String[] args){

        Scanner scanner = new Scanner(System.in);

        int testes = scanner.nextInt();

        while(testes-- > 0){

            int a = scanner.nextInt();
            int b = scanner.nextInt();
            int x = scanner.nextInt();

            long elevar = (long) Math.pow(a, b);

            long multiploInferior = (elevar / x) * x; 
            long multiploSuperior = multiploInferior + x; 

            if(Math.abs(elevar - multiploInferior) <= Math.abs(elevar - multiploSuperior)){
                System.out.println(multiploInferior);
            } 
            else{
                System.out.println(multiploSuperior);
            }
        }
        
        scanner.close();
    }
}
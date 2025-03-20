import java.util.*;

public class SequenciaEspelho{

    public static void espelhamento(String nums, int limiteI, int limiteS){
        
        nums = "";

        for(int i = limiteI; i <= limiteS; i++){
            
            nums += i;
        }

        System.out.print(nums);

        for(int i = nums.length() - 1; i >= 0; i--){
            
            System.out.print(nums.charAt(i));
            nums += nums.charAt(i);
        }

        System.out.println();
    }

    public static void main(String[] args){

        Scanner scanner = new Scanner(System.in);

        while(scanner.hasNextInt()){

            int limiteI = scanner.nextInt();
            int limiteS = scanner.nextInt();
            String nums = "";

            espelhamento(nums, limiteI, limiteS);

        }

        scanner.close();
    }
}
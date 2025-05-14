/*
A: “I have x Rupees more than B.”
B: “I have y rupees more than C.”
C: “I have z rupees more than A.” 
*/

import java.util.*;

public class Rupees{

    public static void main(String[] args){

        Scanner scanner = new Scanner(System.in);

        int testes = scanner.nextInt();

        while(testes > 0){
            
            testes--;

            int x = scanner.nextInt();
            int y = scanner.nextInt();
            int z = scanner.nextInt();

            if((x + y >= z) && (y + z >= x) && (z + x >= y) && ((x + y + z) % 2 == 0)){
                System.out.println("yes");
            }
            else{
                System.out.println("no");
            }
        }
        scanner.close();
    }
}
            

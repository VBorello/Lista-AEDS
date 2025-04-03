import java.util.*;

public class ClimbingStairs {

    public static void printSolucoes(int degraus, int[] passos, int indice){
        
        if (degraus == 0){
            
            System.out.print((indice + 1) + ". ");
            
            for (int i = 0; i < indice; i++){

                System.out.print(passos[i] + " degrau(s)");
                if(passos[i] > 1){
                    System.out.print("s");
                }
                if(i < indice - 1){
                    System.out.print(" + ");
                }
            }
            
            System.out.println();
            return;
        }
        
        if (degraus >= 1){
            passos[indice] = 1;
            printSolucoes(degraus - 1, passos, indice + 1);
        }
        if (degraus >= 2){
            passos[indice] = 2;
            printSolucoes(degraus - 2, passos, indice + 1);
        }
    }

    public static int qtdSolucoes(int degraus){

        if (degraus == 0 || degraus == 1){
            return 1;
        }

        return qtdSolucoes(degraus - 1) + qtdSolucoes(degraus - 2);
    }
    
    public static void main(String[] args){

        Scanner scanner = new Scanner(System.in);

        int degraus = scanner.nextInt();
        scanner.close();

        System.out.println("Input: n = " + degraus);

        int totalSolucoes = qtdSolucoes(degraus);
        System.out.println("Output: " + totalSolucoes);
        
        System.out.println("Explanation:");
        int[] passos = new int[degraus];

        printSolucoes(degraus, passos, 0);
    }
}

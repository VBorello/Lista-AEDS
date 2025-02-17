import java.util.*;

public class OrdenarCrescenteDecrescente{


    public static void ordenador(int[] array, boolean ordem){

        int tamanho = array.length;
        for(int i = 0; i < tamanho -  1; i++){
            for(int j = 0; j < tamanho - 1; j++){
                
                if(ordem && array[j] > array[j + 1] ||
                    (!ordem && array[j] < array[j + 1])){
                        int aux = array[j];
                        array[j] = array[j + 1];
                        array[j + 1] = aux;
                }
            }
        }
    }

    public static void main(String[] args){

        Scanner scanner = new Scanner(System.in);

        int[] array = {10, 4, -3, -19, 49, 80, 24, 12, -5};

        System.out.println("\n1_ para crescente\n0_ para decrescente\n: ");
        boolean ordem = scanner.nextInt() == 1;

        ordenador(array, ordem);
        System.out.println("\nNumeros ordenados:\n ");
        for(int n : array){
            System.out.print(n + " ");
        }
    
        scanner.close();
    }
}
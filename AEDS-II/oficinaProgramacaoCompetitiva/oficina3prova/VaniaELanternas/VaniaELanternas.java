import java.util.*;

public class VaniaELanternas{

    public static void insertionSort(int[] array){
        
        int n = array.length;

        for(int i = 1; i < n; i++){

            int key = array[i];
            int j = i - 1;

            while(j >= 0 && array[j] > key){
                array[j + 1] = array[j];
                j--;
            }

            array[j + 1] = key;
        }
    }

    public static void main(String[] args){
        
        Scanner scanner = new Scanner(System.in);

        int qtdLanternas = scanner.nextInt();
        int tamanho = scanner.nextInt();

        int[] lanternas = new int[qtdLanternas];

        for(int i = 0; i < qtdLanternas; i++){
            lanternas[i] = scanner.nextInt();
        }

        insertionSort(lanternas);

        double maxRaio = 0;

        for(int i = 1; i < lanternas.length; i++){
            maxRaio = Math.max(maxRaio, lanternas[i] - lanternas[i - 1]);
        }

        double maxDistancia = Math.max(lanternas[0], tamanho - lanternas[qtdLanternas - 1]);
        double minRaio = Math.max(maxRaio / 2.0, maxDistancia);

        System.out.printf("%.9f\n", minRaio);

        scanner.close();
    }
}
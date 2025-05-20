import java.util.*;

public class MarkEbrinquedos{

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


    public static void insertionSort(int[] array){
        int n = array.length;
        for (int i = 1; i < n; i++) {
            int key = array[i];
            int j = i - 1;

            while (j >= 0 && array[j] > key) {
                array[j + 1] = array[j];
                j--;
            }
            array[j + 1] = key;
        }
    }

    public static int qtdBrinquedos(int[] precos, int orcamento) {
     
        insertionSort(precos);

        int qtd = 0; 
        int precoTotal = 0; 

        for(int preco : precos){
            
            if(precoTotal + preco <= orcamento){
                precoTotal += preco;
                qtd++;
            } 
            else{
                break; 
            }
        }

        return qtd;
    }

    public static void main(String[] args){
        
        Scanner scanner = new Scanner(System.in);

        int brinquedos = scanner.nextInt();
        int denero = scanner.nextInt();

        int[] precos = new int[brinquedos];
   
        for(int i = 0; i < brinquedos; i++){
            precos[i] = scanner.nextInt();
        }

        int totalBrinquedos = qtdBrinquedos(precos, denero);

        System.out.println(totalBrinquedos);

        scanner.close();
    }
}
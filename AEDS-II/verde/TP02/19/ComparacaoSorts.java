import java.util.Random;

public class ComparacaoSorts{

    public static void main(String[] args){
        
        int[] tamanhos ={100, 1000, 10000, 100000};

        for(int tamanho : tamanhos){
            
            System.out.println("vetor: " + tamanho + "\n");
            int[] original = vetorRandom(tamanho);

            testarAlgoritmo("Inserção", original, ComparacaoSorts::insercao);
            testarAlgoritmo("Bolha", original, ComparacaoSorts::bolha);
            
            testarAlgoritmo("Seleção", original, ComparacaoSorts::selecao);
            System.out.println();
        }
    }

    public static int[] vetorRandom(int tamanho){

        Random aleatorio = new Random();
        int[] vetor = new int[tamanho];

        for(int i = 0; i < tamanho; i++){
            vetor[i] = aleatorio.nextInt(1_000_000);
        }

        return vetor;
    }

    public static void testarAlgoritmo(String nome, int[] vetorOriginal, AlgoritmoOrdenacao algoritmo){

        int[] vetor = vetorOriginal.clone();
        Contador contador = new Contador();

        long inicio = System.currentTimeMillis();
        
        algoritmo.ordenar(vetor, contador);
        
        long fim = System.currentTimeMillis();

        System.out.println("Algoritmo: " + nome);
        System.out.println("Tempo (ms): " + (fim - inicio));
        System.out.println("Comparações: " + contador.comparacoes);
        System.out.println("Movimentações: " + contador.movimentacoes);

        System.out.println("--------------------------------");
    }

    @FunctionalInterface

    interface AlgoritmoOrdenacao{

        void ordenar(int[] vetor, Contador contador);
    }

    static class Contador {
       
        long comparacoes = 0;
        long movimentacoes = 0;
    }


    // Seleção
    public static void selecao(int[] array, Contador contador){

        int n = array.length;
        
        for(int i = 0; i < n - 1; i++){
            int min = i;
            
            for(int j = i + 1; j < n; j++){
                contador.comparacoes++;
        
                if(array[j] < array[min]){
                    min = j;
                }
            }
            if(min != i){
        
                int temp = array[i];
        
                array[i] = array[min];
                array[min] = temp;
                contador.movimentacoes += 3;
            }
        }
    }

    //bolha
    public static void bolha(int[] array, Contador contador){
        
        int n = array.length;
        boolean trocou;
        
        for(int i = 0; i < n - 1; i++){
            trocou = false;

            for(int j = 0; j < n - i - 1; j++){
                contador.comparacoes++;

                if(array[j] > array[j + 1]){
                    
                    int temp = array[j];
                    
                    array[j] = array[j + 1];
                    array[j + 1] = temp;
                    
                    contador.movimentacoes += 3;
                    trocou = true;
                }
            }
            if(!trocou){
                break;
            }
        }
    }

    //inserção
    public static void insercao(int[] array, Contador contador){
       
        for(int i = 1; i < array.length; i++){

            int chave = array[i];
            int j = i - 1;
            
            while(j >= 0){
                contador.comparacoes++;
                
                if(array[j] > chave){
                    
                    array[j + 1] = array[j];
                    contador.movimentacoes++;
                    j--;
                }
                else{
                    break;
                }
            }
            array[j + 1] = chave;

            contador.movimentacoes++;
        }
    }
}

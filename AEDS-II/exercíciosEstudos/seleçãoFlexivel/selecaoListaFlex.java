import java.util.ArrayList;

public class SelecaoListaFlex {

    public static void selectionSort(ArrayList<Integer> lista){
        
        int n = lista.size();

        for (int i = 0; i < n - 1; i++){
            
            int minIndex = i;

            for (int j = i + 1; j < n; j++){
                if (lista.get(j) < lista.get(minIndex)){
                    minIndex = j;
                }
            }

            if(minIndex != i){

                int temp = lista.get(i);
                lista.set(i, lista.get(minIndex));
                lista.set(minIndex, temp);
            }
        }
    }

    public static void main(String[] args){

        Arraylista<Integer> lista = new Arraylista<>();

        lista.add(1);
        lista.add(2);
        lista.add(5);
        lista.add(4);
        lista.add(6);
        lista.add(3);

        System.out.println("lista antes da ordenação:");
        System.out.println(lista);

        selectionSort(lista);

        System.out.println("lista após a ordenação:");
        System.out.println(lista);
    }
}
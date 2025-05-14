import java.util.*;

public class Mandiocas{

    public static void main(String[] args){

        Scanner scanner = new Scanner(System.in);

        int qtd = scanner.nextInt();

        int[] sacas = new int[qtd];
        for(int i = 0; i < qtd; i++){
            sacas[i] = scanner.nextInt();
        }

        int posicao = scanner.nextInt();
        int mandiocas = sacas[posicao - 1];

        int removidas = 0;
        int copia = mandiocas;

        while(copia > 0){

            int digito = copia % 10;
            if(digito % 2 == 0 && digito != 0){
                removidas++;
            }

            copia /= 10;
        }

        int resultado =  mandiocas - removidas;

        System.out.println(removidas + " " + resultado);

        scanner.close();
    }
}
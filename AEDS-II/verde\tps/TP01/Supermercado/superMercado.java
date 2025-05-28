import java.util.*;

public class superMercado{

    public static void main(String[] args){

        Scanner scanner = new Scanner(System.in).useLocale(Locale.US);

        int qtdMercados = scanner.nextInt();

        double menorPreco = Double.MAX_VALUE;
    
        for(int i = 0; i < qtdMercados; i++){
            double preco = scanner.nextDouble();
            int gramas = scanner.nextInt();

            double precoPorG = (preco / gramas) * 1000; 

            if(precoPorG < menorPreco){
                menorPreco = precoPorG;
            }
        }


        System.out.printf("%.2f\n", menorPreco);

        scanner.close();
    }
}


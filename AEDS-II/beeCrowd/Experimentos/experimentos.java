import java.util.*;

public class experimentos {

    public static void estatisticas(int n) {
        Scanner scanner = new Scanner(System.in);
        
        int total = 0;
        int coelho = 0, rato = 0, sapo = 0;
        
        for (int i = 0; i < n; i++) {
            int quantidade = scanner.nextInt();
            char bicho = scanner.next().charAt(0);
            
            total += quantidade;
            
            if (bicho == 'C' || bicho == 'c') {
                coelho += quantidade;
            } else if (bicho == 'R' || bicho == 'r') {
                rato += quantidade;
            } else if (bicho == 'S' || bicho == 's') {
                sapo += quantidade;
            } else {
                System.out.println("Animal Inválido");
            }
        }
        
        float percentualC = (coelho * 100) / total;
        float percentualR = (rato * 100) / total;
        float percentualS = (sapo * 100) / total;
        
        System.out.println("Total: " + total + " cobaias");
        System.out.println("Total de coelhos: " + coelho);
        System.out.println("Total de ratos: " + rato);
        System.out.println("Total de sapos: " + sapo);
        System.out.printf("Percentual de coelhos: %.2f %%\n", percentualC);
        System.out.printf("Percentual de ratos: %.2f %%\n", percentualR);
        System.out.printf("Percentual de sapos: %.2f %%\n", percentualS);
        
        scanner.close();
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        estatisticas(n);
        scanner.close();
    }
}

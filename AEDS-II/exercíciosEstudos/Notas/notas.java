import java.util.Scanner;

public class notas {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        System.out.print("Digite um valor: ");
        String input = scanner.next();
        
        double valor = Double.parseDouble(input.replace(',', '.'));
        
        int[] notas = {200, 100, 50, 20, 10, 5, 2};
        double[] moedas = {1.00, 0.50, 0.25, 0.10, 0.05, 0.01};
        
        System.out.println("Notas:");
        for (int nota : notas) {
            int quantidade = (int) (valor / nota);
            if (quantidade > 0) {
                System.out.printf("nota %d: %d%n", nota, quantidade);
                valor -= quantidade * nota;
                valor = Math.round(valor * 100.0) / 100.0; // Arredondamento para 2 casas
            }
        }
        
        System.out.println("Moedas:");
        for (double moeda : moedas) {
            int quantidade = (int) ((valor + 0.001) / moeda);
            if (quantidade > 0) {
                String moedaStr = String.format("%.2f", moeda).replace('.', ',');
                System.out.printf("moeda %s: %d%n", moedaStr, quantidade);
                valor -= quantidade * moeda;
                valor = Math.round(valor * 100.0) / 100.0;
            }
        }
        
        if (valor > 0.001) {
            System.out.println("moeda 0,01: 1");
        }
        
        scanner.close();
    }
}
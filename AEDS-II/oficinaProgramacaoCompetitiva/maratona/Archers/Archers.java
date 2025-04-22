import java.util.Scanner;

public class Archers {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int a = scanner.nextInt();
        int b = scanner.nextInt();
        int c = scanner.nextInt();
        int d = scanner.nextInt();

        double SmallR = (double) a / b; 
        double Zanoes = (double) c / d; 

        double chanceSmallRwins = SmallR / (1 - (1 - SmallR) * (1 - Zanoes));

        System.out.printf("%.6f\n", chanceSmallRwins);

        scanner.close();
    }
}
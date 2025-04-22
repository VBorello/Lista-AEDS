import java.util.Scanner;

public class RedBlueShuffle{

    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);

        int testes = scanner.nextInt();

        for (int t = 0; t < testes; t++){
            int n = scanner.nextInt();

            String R = scanner.next();
            String B = scanner.next();

            int redWins = 0;
            int blueWins = 0;

            for (int i = 0; i < n; i++){
                int Red = R.charAt(i) - '0';
                int Blue = B.charAt(i) - '0';

                if (Red > Blue){
                    redWins++;
                } else if (Blue > Red){
                    blueWins++;
                }
            }

            if (redWins > blueWins){
                System.out.println("RED");
            } else if (blueWins > redWins){
                System.out.println("BLUE");
            } else{
                System.out.println("EQUAL");
            }
        }

        scanner.close();
    }
}
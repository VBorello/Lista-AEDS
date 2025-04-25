import java.util.Scanner;

public class RandonEvents {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int t = scanner.nextInt();

        while (t-- > 0) {
            int n = scanner.nextInt();
            int m = scanner.nextInt();

           int[] a = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = scanner.nextInt();
            }

           int lastUnsorted = n;
            for (int i = n - 1; i >= 0; i--) {
                if (a[i] != i + 1) {
                    lastUnsorted = i + 1;
                    break;
                }
            }

           if (lastUnsorted == n) {
                System.out.println(1.0);
                continue;
            }

           double probabilityNotSorted = 1.0;
            for (int i = 0; i < m; i++) {
                int r = scanner.nextInt();
                double p = scanner.nextDouble();

               if (r >= lastUnsorted) {
                    probabilityNotSorted *= (1 - p);
                }
            }

          double probabilitySorted = 1 - probabilityNotSorted;

            System.out.printf("%.6f\n", probabilitySorted);
        }

        scanner.close();
    }
}
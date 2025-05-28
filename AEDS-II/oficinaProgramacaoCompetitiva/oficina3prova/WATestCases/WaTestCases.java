import java.util.*;

public class WaTestCases{

    public static void main(String[] args){
        
        Scanner scanner = new Scanner(System.in);

        int T = scanner.nextInt();

        while (T-- > 0){

            int N = scanner.nextInt();

            int[] sizes = new int[N];
            
            for(int i = 0; i < N; i++){
                sizes[i] = scanner.nextInt();
            }

            String V = scanner.next();

            int minSize = Integer.MAX_VALUE;
            
            for(int i = 0; i < N; i++){
                if (V.charAt(i) == '0'){ 
                    minSize = Math.min(minSize, sizes[i]);
                }
            }

            System.out.println(minSize);
        }

        scanner.close();
    }
}
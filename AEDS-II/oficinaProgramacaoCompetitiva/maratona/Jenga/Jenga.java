import java.util.*;

public class Jenga{

    public static void main(String[] args){
        
        Scanner scanner = new Scanner(System.in);

        int T = scanner.nextInt();

        while(T-- > 0){ 
            int N = scanner.nextInt();
            int X = scanner.nextInt();

            if(X % N == 0){
                System.out.println("YES");
            }
            else{
                System.out.println("NO");
            }
        }

        scanner.close();
    }
}
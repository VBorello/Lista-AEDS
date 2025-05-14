import java.util.*;

public class MakeThemEqual{

    public static void main(String[] args){
        
        Scanner scanner = new Scanner(System.in);

        int t = scanner.nextInt();

        while(t-- > 0){
            
            int n = scanner.nextInt();
            char c = scanner.next().charAt(0);

            String s = scanner.next();

            boolean tudoIgual = true;
            
            for(int i = 0; i < n && tudoIgual; i++){
                if(s.charAt(i) != c){
                    tudoIgual = false;
                }
            }

            if(tudoIgual){
                System.out.println(0);
            } 
            else{

                int x = -1;

                for(int i = n; i >= 1 && x == -1; i--){
                    boolean valido = true;

                    for(int j = i; j <= n; j += i){
                        if(s.charAt(j - 1) != c){
                            valido = false;
                        }
                    }

                    if(valido){
                        x = i;
                    }
                }

                if(x != -1){
                    System.out.println(1);
                    System.out.println(x);
                } 
                else{
                    System.out.println(2);
                    System.out.println(n + " " + (n - 1));
                }
            }
        }

        scanner.close();
    }
}
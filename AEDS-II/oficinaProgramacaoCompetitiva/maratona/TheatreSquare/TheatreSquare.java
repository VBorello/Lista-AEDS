import java.util.*;

public class TheatreSquare{

    public static void main(String[] args){

        Scanner scanner = new Scanner(System.in);

        long n = scanner.nextLong(); 
        long m = scanner.nextLong(); 
        long a = scanner.nextLong(); 

        long comprimentoPedras = (n + a - 1) / a;
        long larguraPedras = (m + a - 1) / a;  
        
        long totalPedras = comprimentoPedras * larguraPedras;

        System.out.println(totalPedras);

        scanner.close();
    }
}
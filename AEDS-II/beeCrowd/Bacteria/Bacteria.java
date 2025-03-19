import java.util.*;

public class Bacteria {

    public static boolean resistente(String DNA, String sequencia){

        boolean resistente = false;
        
        int DNAtam = DNA.length();
        int sequenciaTam = sequencia.length();

        for(int i = 0; i <= DNAtam - sequenciaTam; i++){
            int j;
            for(j = 0; j < sequenciaTam; j++){
                if(DNA.charAt(i + j) != sequencia.charAt(j)){
                    break;
                }
            }
            if(j == sequenciaTam){
                resistente = true;
            }
        }

        return resistente;
    }
    
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);

        while(scanner.hasNext()){
            
            String DNA = scanner.next();
            String sequencia = scanner.next();

            if(resistente(DNA, sequencia)){
                System.out.println("Resistente");
            }
            else{
                System.out.println("Nao resistente");
            }
        }

        scanner.close();
    }
}
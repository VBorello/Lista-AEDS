import java.util.*;

public class Anagrama{

    public static boolean anagrama(String p1, String p2){

        if(p1.length() != p2.length()){
            return false;
        }

        //usando um array para contar a ocorrência dos caracteres
        int[] qtdCaracteres = new int[256];//256 tabela ascii

        for(int i = 0; i < p1.length(); i++){
            qtdCaracteres[p1.charAt(i)]++;
        }

        //subtraindo a contagem dos caracteres da segunda string
        for(int i = 0; i < p2.length(); i++){
            //se algum caractere aparecer mais vezes na segunda string, não é anagrama
            qtdCaracteres[p2.charAt(i)]--; 
            if(qtdCaracteres[p2.charAt(i)] < 0){
                return  false;
            }
        }

        return true;
    }

    public static void main(String[] args){

        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        scanner.nextLine();

        for(int i = 0; i < n; i++){
            
            String line = scanner.nextLine();
            
            String[] parts = line.split(" ");

            String p1 = parts[0];
            String p2 = parts[1];

            if(anagrama(p1, p2)){
                System.out.println("SIM");
            }
            else{
                System.out.println("NÃO");
            }
        }

        scanner.close();
    }

}
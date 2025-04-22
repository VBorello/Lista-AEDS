import java.util.*;

public class Password{

    public static void main(String[] args){

        Scanner scanner = new Scanner(System.in);

        int qtd = scanner.nextInt();

        for(int i = 0; i < qtd; i++){

            int passwordChar = scanner.nextInt();

            boolean[] characters;
            characters = new boolean[10];

            for(int j = 0; j < passwordChar; j++){
            
                int num = scanner.nextInt();
                characters[num] = true;
            }

            int[] possiveis;
            possiveis = new int[10];

            int count = 0;

            for (int k = 0; k <= 9; k++) {

                if (!characters[k]) {
                    possiveis[count++] = k;
                }
            }

            int senhaValida = 0;
            for (int x = 0; x < count; x++) {
                for (int y = x + 1; y < count; y++) {
                    senhaValida += 6; 
                }
            }
            System.out.println(senhaValida);
        }
    
        scanner.close();
    }
}
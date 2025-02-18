import java.util.*;

public class AvancandoLetras{

    public static int contabilizarAvancos(char[] string1, char[] string2){

        int qtdAvancos = 0;
        int tamanho = string1.length;

        
        for(int i = 0; i < tamanho; i++){
        
            int avancoDireto = string2[i] - string1[i];
            if(avancoDireto < 0){
                avancoDireto += 26;
            }
            qtdAvancos += avancoDireto;
        }
        
        return qtdAvancos;
    }

    public static void main(String[] args){

        Scanner scanner = new Scanner(System.in);
        int qtdStrings = scanner.nextInt();
        scanner.nextLine();
        
        for(int i = 0; i < qtdStrings; i++){
            
            String string1 = scanner.next();
            String string2 = scanner.next();
            
            char[] array1 = string1.toCharArray();
            char[] array2 = string2.toCharArray();

            int qtdAvancos = contabilizarAvancos(array1, array2);
            System.out.println(qtdAvancos); 
        }

        scanner.close();
    }
}
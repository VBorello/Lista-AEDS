import java.util.*;

public class criptografia{

    public static void apresentacao(){
        System.out.println("\nCriptografia");
    }

    public static String lerFrase(){
        
        Scanner scanner = new Scanner(System.in);
        System.out.printf("Digite uma frase: ");
        String frase = scanner.nextLine();

        return frase;
    } 

    public static String criptografar(String frase){

        char[] criptografada = new char[frase.length()];

        for(int i = 0; i < frase.length(); i++){

            char c = frase.charAt(i);
            if(Character.isLetter(c)){
                criptografada[i] = (char) (c + 3);
            }
            else{
                criptografada[i] = c;
            }
        }


        int n = criptografada.length;
        for(int i = 0; i < n / 2; i++){
            char aux = criptografada[i];
            criptografada[i] = criptografada[n - i -1];
            criptografada[n - i - 1] = aux;
        }

        int metade = n / 2;
        for(int i = metade; i < n; i++){
            criptografada[i] = (char) (criptografada[i] - 1);
        }

        return new String(criptografada);
    }

    public static void main(String[] args){

        apresentacao();

        Scanner scanner = new Scanner(System.in);
        System.out.printf("Digite a quantidade de frases: ");
        int n = scanner.nextInt();
        scanner.nextLine();

        for(int i = 0; i < n; i++){
            String frase = lerFrase();
            String criptografada = criptografar(frase);
            System.out.println("Frase criptografada: " + criptografada);
        }

        scanner.close();

    }
}
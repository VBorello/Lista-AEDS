import java.util.*;

public class alteracaoAleatoria{

    //inicializa um objeto Tipo 'random' para gerar numeros aleatórios
    public static Random gerador = new Random();

    public static String sortearEsubstituir(String palavra){
        
        int tamanho = palavra.length();
        char[] palavraAlterada = new char[palavra.length()];//array de caracteres para armazenar a palavra modificada

        char letraAnterior = (char) ('a' + (Math.abs(gerador.nextInt()) % 26));
        char letraSorteada = (char) ('a' + (Math.abs(gerador.nextInt()) % 26));

        for(int i = 0; i < tamanho; i++){
            if(palavra.charAt(i) == letraAnterior){
                palavraAlterada[i] = letraSorteada; //trocam as letras sorteadas
            }
            else{
                palavraAlterada[i] = palavra.charAt(i); //mantem a letra original
            }
        }

        return new String(palavraAlterada);
    }

    public static void main(String[] args){

        Scanner scanner = new Scanner(System.in);
        String linha = scanner.nextLine();

        gerador.setSeed(4);//define uma semente para o gerador.

        while(!(linha.length() == 3 && linha.charAt(0) == 'F' && linha.charAt(1) == 'I' && linha.charAt(2) == 'M')){

            System.out.println(sortearEsubstituir(linha));
            linha = scanner.nextLine();
        }

        scanner.close();
    }
}
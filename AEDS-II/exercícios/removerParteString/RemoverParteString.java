import java.util.*;

public class RemoverParteString {
             
    public static String removerParte(String frase, String parte){

        int tamFrase = frase.length();
        int tamPalavra = parte.length();

        char[] fraseAlterada = new char[tamFrase];//armazenar a frase gerada
        int indice = 0;//indice para preencher o resultado

        boolean espacoAnterior = true; //evitar espaços extras no final
        
        for(int i = 0; i < tamFrase; i++){
            
            boolean encontrou = true;
            
            for(int j = 0; j < tamPalavra; j++){
                if(i + j >= tamFrase || frase.charAt(i + j) != parte.charAt(j)){
                    encontrou = false;
                }
            }
            // se encontrou isola a palavra
            if(encontrou){
                boolean espacoAntes = (i == 0 || frase.charAt(i - 1) == ' ');
                boolean espacoDepois = (i + tamPalavra == tamFrase || frase.charAt(i + tamPalavra) == ' ');
            
                if(espacoAntes && espacoDepois){
                    i += tamPalavra - 1; //pula a palavra removida
                    espacoAnterior = true;//possibilita que um espaço pode ser usado depois
                }
                else{
                    fraseAlterada[indice] = frase.charAt(i);
                    indice++;
                }
            }
            else{//adiciona o caractere ao novo array
                if(frase.charAt(i) == ' ' && espacoAnterior){
                    //evita espaços duplos
                }
                else{
                    fraseAlterada[indice] = frase.charAt(i);
                    indice++;
                    espacoAnterior = (frase.charAt(i) == ' ');
                }
            }
        }

        String novaFrase = "";//cria a ultima string sem espaços extras
        for(int i = 0; i < indice; i++){
            novaFrase += fraseAlterada[i];
        }

        return novaFrase;
    }

    public static void main(String[] args){

        Scanner scanner = new Scanner(System.in);
        
        System.out.printf("\nDigite a frase: ");
        String frase = scanner.nextLine();

        System.out.printf("\nDigite a parte a ser removida: ");
        String parte = scanner.nextLine();

        String fraseAlterada = removerParte(frase, parte);
        System.out.println("\nFrase resultada: " + fraseAlterada);

        scanner.close();
    }

}
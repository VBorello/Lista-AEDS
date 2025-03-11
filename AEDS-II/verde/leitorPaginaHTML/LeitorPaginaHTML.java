import java.util.*;
import java.net.*;
import java.io.BufferedReader;
import java.io.InputStream;
import java.io.InputStreamReader;


public class LeitorPaginaHTML {
    
    public static String requisicao(String url){
        
        URL site;
        InputStream inputstream;
        BufferedReader bufferedReader;
        String response = "";
        String line;
    
        try{

            site = new URI(url).toURL();
            inputstream = site.openStream();
            bufferedReader = new BufferedReader(new InputStreamReader(inputstream));
    
            while ((line = bufferedReader.readLine()) != null){
                response += line + "\n";
            }
    
            inputstream.close();

        } catch (Exception e){ }
    
        return response;
    }

    public static void contarVogais(String site, char[] vogais, int[] tag){
        
        int[] qtdVogais = new int[vogais.length];

        for(int j = 0 ; j < vogais.length ; j ++){
            for(int i = 0 ; i < site.length() ; i++){

                if(site.charAt(i) == vogais[j]){

                    qtdVogais[j]++;
                }
            }

            qtdVogais[0] -= (1 * tag[1]);
            qtdVogais[1] -= (0.5 * tag[1]);
            
            System.out.print(vogais[j] + "(" + qtdVogais[j] + ") ");
        }
    }

    public static void contarConsoantes(String site, char[] consoantes, int[] tag){

        int qtdConsoantes = 0;

        for(int j = 0 ; j < consoantes.length ; j++){
            for(int i = 0 ; i < site.length() ; i++){

                if(site.charAt(i) == consoantes[j]){

                    qtdConsoantes++;
                }
            }
        }

        qtdConsoantes -= (2 * tag[0]);
        qtdConsoantes -= (3 * tag[1]);
        
        System.out.print("consoante(" + qtdConsoantes + ") ");
    }

    public static int[] contarTags(String site, String[] tags){

        int[] qtdTags = new int[tags.length];

        for(int j = 0 ; j < tags.length ; j++){
            for(int i = 0 ; i < site.length() ; i++){

                if(site.charAt(i) == tags[j].charAt(0) && i + tags[j].length() <= site.length()){

                    int check = tags[j].length();
                    boolean ehIgual = true;

                    for (int k = 0; k < check; k++){

                        if (tags[j].charAt(k) != site.charAt(i + k)){

                            ehIgual = false;
                        }
                    }
                    if (ehIgual){

                        qtdTags[j]++;
                    }
                }
            }
            
        }     

        return qtdTags;
    }

    public static void qtdElementos(String titulo, String url){

        String site = requisicao(url);

        char[] vogais ={ 'a', 'e', 'i', 'o', 'u', '\u00E1', '\u00E9', '\u00ED', '\u00F3', '\u00FA', '\u00E0', '\u00E8', '\u00EC', '\u00F2', '\u00F9', '\u00E3', '\u00F5', '\u00E2', '\u00EA', '\u00EE', '\u00F4', '\u00FB' };
        
        char[] consoantes ={ 'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p', 'q', 'r', 's', 't', 'v', 'w', 'x', 'y', 'z' };
        
        String[] tags ={"<br>", "<table>"};
        
        int[] tag = contarTags(site, tags);

        contarVogais(site, vogais, tag);

        contarConsoantes(site, consoantes, tag);

        for (int i = 0 ; i < tag.length ; i++){
            System.out.print(tags[i] + "(" + tag[i] + ") ");
        }
            
        System.out.println(titulo);

    }

    public static void main(String [] args){

        Scanner scanner = new Scanner(System.in);

        String titulo = scanner.nextLine();
        String url;

        while(!(titulo.length() == 3 && titulo.charAt(0) == 'F' && titulo.charAt(1) == 'I' && titulo.charAt(2) == 'M')){
            
            url = scanner.nextLine();
            qtdElementos(titulo, url);
            
            titulo = scanner.nextLine();
        }

        scanner.close();
    }
}
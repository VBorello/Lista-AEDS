import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;

public class Show {

    private String SHOW_ID;
    private String TYPE;
    private String TITLE;
    private String DIRECTOR;
    private String[] CAST;
    private String COUNTRY;
    private String DATE_ADDED;
    private int RELEASE_YEAR;
    private String RATING;
    private String DURATION;
    private String[] LISTED_IN;

    private static int comparacoes = 0;
    private static int movimentacoes = 0;

    public Show(){
        
        this.SHOW_ID = this.TYPE = this.TITLE = this.DIRECTOR = this.COUNTRY = this.DATE_ADDED = this.RATING = this.DURATION = "NaN";
        this.RELEASE_YEAR = 0;
        this.CAST = new String[]{"NaN"};
        this.LISTED_IN = new String[]{"NaN"};
    }

    public Show(String SHOW_ID, String TYPE, String TITLE, String DIRECTOR, String[] CAST, String COUNTRY,
                String DATE_ADDED, int RELEASE_YEAR, String RATING, String DURATION, String[] LISTED_IN) {
        this.SHOW_ID = SHOW_ID;
        this.TYPE = TYPE;
        this.TITLE = TITLE;
        this.DIRECTOR = DIRECTOR;
        this.CAST = CAST;
        this.COUNTRY = COUNTRY;
        this.DATE_ADDED = DATE_ADDED;
        this.RELEASE_YEAR = RELEASE_YEAR;
        this.RATING = RATING;
        this.DURATION = DURATION;
        this.LISTED_IN = LISTED_IN;
    }

    public Show clone(){
        return new Show(SHOW_ID, TYPE, TITLE, DIRECTOR, CAST.clone(), COUNTRY, DATE_ADDED, RELEASE_YEAR, RATING, DURATION, LISTED_IN.clone());
    }

    public void imprimir(){

        System.out.print("=> " + SHOW_ID + " ## " + TITLE + " ## " + TYPE + " ## " + DIRECTOR + " ## [");
        
        for(int i = 0; i < CAST.length; i++){
            System.out.print(CAST[i]);
            
            if(i < CAST.length - 1) System.out.print(", ");
        }

        System.out.print("] ## " + COUNTRY + " ## " + DATE_ADDED + " ## " + RELEASE_YEAR + " ## " + RATING + " ## " + DURATION + " ## [");
        
        for(int i = 0; i < LISTED_IN.length; i++){
            System.out.print(LISTED_IN[i]);
            
            if(i < LISTED_IN.length - 1) System.out.print(", ");
        }
        System.out.println("] ##");
    }

    public void ler(String linha){

        String[] partes = new String[12];
        boolean dentroAspas = false;
        StringBuilder atual = new StringBuilder();
        int indice = 0;

        for(int i = 0; i < linha.length(); i++){
            char c = linha.charAt(i);
            
            if(c == '"'){
                dentroAspas = !dentroAspas;
            } 
            else if(c == ',' && !dentroAspas){
                partes[indice++] = atual.toString();
                atual.setLength(0);
            } 
            else{
                atual.append(c);
            }
        }
        partes[indice] = atual.toString();

        this.SHOW_ID = partes[0];
        this.TYPE = partes[1];
        this.TITLE = partes[2];
        this.DIRECTOR = partes[3].isEmpty() ? "NaN" : partes[3];
        this.CAST = partes[4].isEmpty() ? new String[]{"NaN"} : partes[4].split("\\s*,\\s*");
        Arrays.sort(this.CAST);
        this.COUNTRY = partes[5].isEmpty() ? "NaN" : partes[5];
        this.DATE_ADDED = partes[6].isEmpty() ? "March 1, 1900" : partes[6];
        this.RELEASE_YEAR = partes[7].isEmpty() ? 0 : Integer.parseInt(partes[7]);
        this.RATING = partes[8].isEmpty() ? "NaN" : partes[8];
        this.DURATION = partes[9].isEmpty() ? "NaN" : partes[9];
        this.LISTED_IN = partes[10].isEmpty() ? new String[]{"NaN"} : partes[10].split("\\s*,\\s*");
        Arrays.sort(this.LISTED_IN);
    }

    private static int parseDuration(String duration){
        
        if(duration == null || duration.equals("NaN")) return -1;
        if(duration.contains("Season")){
            return Integer.parseInt(duration.split(" ")[0]) * 1000;
        }

        else if(duration.contains("min")){
            return Integer.parseInt(duration.split(" ")[0]);
        }
        return -1;

    }

    private static boolean menor(Show a, Show b){

        comparacoes++;
        int da = parseDuration(a.DURATION);
        int db = parseDuration(b.DURATION);
        if (da != db) return da < db;
        return a.TITLE.compareTo(b.TITLE) < 0;
    }

    public static void mergeSort(Show[] array, int esq, int dir){
        
        if (esq < dir){
            int meio = (esq + dir) / 2;
            mergeSort(array, esq, meio);
            mergeSort(array, meio + 1, dir);
            intercalar(array, esq, meio, dir);
        }
    }

    public static void intercalar(Show[] array, int esq, int meio, int dir){
        
        Show[] temp = new Show[dir - esq + 1];
        int i = esq, j = meio + 1, k = 0;
        
        while(i <= meio && j <= dir) {
            if(menor(array[i], array[j])){
                temp[k++] = array[i++];
            }
             else{
                temp[k++] = array[j++];
            }
            movimentacoes++;
        }

        while(i <= meio) temp[k++] = array[i++];
        while(j <= dir) temp[k++] = array[j++];
        
        for(i = esq, k = 0; i <= dir; i++, k++) array[i] = temp[k];
    }

    public static void main(String[] args) throws Exception{

        BufferedReader br = new BufferedReader(new FileReader("/tmp/disneyplus.csv"));


        String linha;
        Show[] shows = new Show[1368];

        int total = 0;
        br.readLine();
        
        while((linha = br.readLine()) != null){

            shows[total] = new Show();
            shows[total].ler(linha);
            total++;
        }

        br.close();

        BufferedReader in = new BufferedReader(new java.io.InputStreamReader(System.in));
        Show[] entrada = new Show[1000];
        
        int n = 0;
        
        while(true){
            String id = in.readLine();
            
            if(id.equals("FIM")) break;

            for(int i = 0; i < total; i++){
                if(shows[i].SHOW_ID.equals(id)){
                    entrada[n++] = shows[i].clone();
                    break;
                }
            }
        }

        in.close();

        long inicio = System.nanoTime();
        
        mergeSort(entrada, 0, n - 1);
        long fim = System.nanoTime();

        for (int i = 0; i < n; i++) entrada[i].imprimir();

        FileWriter fw = new FileWriter("matricula_mergesort.txt");

        fw.write("792219\t" + comparacoes + "\t" + movimentacoes + "\t" + (fim - inicio) / 1000000.0 + "ms\n");
        fw.close();
    }
}

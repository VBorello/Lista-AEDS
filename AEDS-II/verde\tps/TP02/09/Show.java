import java.io.BufferedReader;
import java.io.FileReader;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Show{

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

    public Show(){

        this.SHOW_ID = this.TYPE = this.TITLE = this.DIRECTOR = this.COUNTRY = this.DATE_ADDED = this.RATING = this.DURATION = "NaN";
        this.CAST = new String[0];
        this.LISTED_IN = new String[0];
        this.RELEASE_YEAR = 0;
    }

    public Show(String SHOW_ID, String TYPE, String TITLE, String DIRECTOR, String[] CAST,
                String COUNTRY, String DATE_ADDED, int RELEASE_YEAR, String RATING,
                String DURATION, String[] LISTED_IN){

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

        System.out.print("=> " + SHOW_ID + " ## " + TITLE + " ## " + TYPE + " ## " + DIRECTOR + " ## ");
        System.out.print(Arrays.toString(CAST) + " ## " + COUNTRY + " ## " + DATE_ADDED + " ## ");
        System.out.print(RELEASE_YEAR + " ## " + RATING + " ## " + DURATION + " ## ");
        System.out.println(Arrays.toString(LISTED_IN) + " ##");
    }

    public void ler(String linha){

        String[] campos = new String[12];
        int pos = 0;
        boolean dentroAspas = false;
        StringBuilder campo = new StringBuilder();

        for(int i = 0; i < linha.length(); i++){
           
            char c = linha.charAt(i);
            if (c == '\"') dentroAspas = !dentroAspas;
            else if(c == ',' && !dentroAspas){
                campos[pos++] = campo.toString().trim();
                campo.setLength(0);
            }
            else campo.append(c);
        }
        campos[pos] = campo.toString().trim();

        this.SHOW_ID = campos[0].isEmpty() ? "NaN" : campos[0];
        this.TYPE = campos[1].isEmpty() ? "NaN" : campos[1];
        this.TITLE = campos[2].isEmpty() ? "NaN" : campos[2];
        this.DIRECTOR = campos[3].isEmpty() ? "NaN" : campos[3];
        this.CAST = campos[4].isEmpty() ? new String[] { "NaN" } : campos[4].split(", ");
        Arrays.sort(this.CAST);
        this.COUNTRY = campos[5].isEmpty() ? "NaN" : campos[5];
        this.DATE_ADDED = campos[6].isEmpty() ? "March 1, 1900" : campos[6];
        
        try{
            this.RELEASE_YEAR = Integer.parseInt(campos[7]);
        }
        catch (Exception e){

            this.RELEASE_YEAR = 0;
        }

        this.RATING = campos[8].isEmpty() ? "NaN" : campos[8];
        this.DURATION = campos[9].isEmpty() ? "NaN" : campos[9];
        this.LISTED_IN = campos[10].isEmpty() ? new String[] { "NaN" } : campos[10].split(", ");
        Arrays.sort(this.LISTED_IN);
    }

    public String getDIRECTOR(){
        return this.DIRECTOR;
    }

    public String getTITLE(){
        return this.TITLE;
    }

    public static void main(String[] args) throws Exception{

        BufferedReader teclado = new BufferedReader(new InputStreamReader(System.in));
        String linha;
        String[] entradas = new String[1000];
        int n = 0;

        while(!(linha = teclado.readLine()).equals("FIM")){
            entradas[n++] = linha;
        }

        String[] csv = new String[10000];
        int m = 0;
        BufferedReader br = new BufferedReader(new FileReader("/tmp/disneyplus.csv"));
        //home/vicenzo/Documentos/GitHub/Lista-AEDS/AEDS-II/verde/TP02/disneyplus.csv
        
        br.readLine();
        while((linha = br.readLine()) != null){
            csv[m++] = linha;
        }

        br.close();

        Show[] lista = new Show[n];
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(csv[j].startsWith(entradas[i] + ",")){
                
                    lista[i] = new Show();
                    lista[i].ler(csv[j]);
                    break;
                }
            }
        }

        //heap
        int comp = 0, mov = 0;

        for(int tam = 2; tam <= n; tam++){
            for(int i = tam - 1; i > 0 && (comp++) >= 0; i = (i - 1) / 2){
                if(compare(lista[i], lista[(i - 1) / 2]) > 0){
                
                    Show tmp = lista[i]; mov++;
                    lista[i] = lista[(i - 1) / 2];
                    lista[(i - 1) / 2] = tmp;
                }
            }
        }

        for(int tam = n; tam > 1; tam--){
           
            Show tmp = lista[0]; mov++;
            lista[0] = lista[tam - 1];
            lista[tam - 1] = tmp;

            reconstroi(lista, tam - 1, comp, mov);
        }

        for(int i = 0; i < n; i++){

            lista[i].imprimir();
        }

        long tempo = System.currentTimeMillis();
        
        java.io.FileWriter fw = new java.io.FileWriter("matricula_heapsort.txt");
        fw.write("802305\t" + comp + "\t" + mov + "\t" + tempo + "\n");
        fw.close();
    }

    public static void reconstroi(Show[] array, int tam, int comp, int mov){

        int i = 0;
        while(i < tam / 2){
            
            int filho = getMaiorFilho(array, i, tam, comp);
            if(compare(array[filho], array[i]) > 0){

                Show tmp = array[i]; mov++;
                array[i] = array[filho];
                array[filho] = tmp;
                i = filho;
            } 
            else{
                break;
            }
        }
    }

    public static int getMaiorFilho(Show[] array, int i, int tam, int comp){

        int filhoEsq = 2 * i + 1;
        int filhoDir = 2 * i + 2;

        if (filhoDir < tam && compare(array[filhoDir], array[filhoEsq]) > 0){
            
            return filhoDir;
        }

        return filhoEsq;
    }

    public static int compare(Show a, Show b){
        
        int c = a.getDIRECTOR().compareTo(b.getDIRECTOR());
        if (c != 0) return c;
        return a.getTITLE().compareTo(b.getTITLE());
    }
}

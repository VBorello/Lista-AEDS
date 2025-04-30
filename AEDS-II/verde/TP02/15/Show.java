import java.io.BufferedReader;
import java.io.FileReader;
import java.io.InputStreamReader;
import java.text.SimpleDateFormat;
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

            if (c == '"') dentroAspas = !dentroAspas;
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

        this.CAST = campos[4].isEmpty() ? new String[]{ "NaN" } : campos[4].split(", ");
        Arrays.sort(this.CAST);

        this.COUNTRY = campos[5].isEmpty() ? "NaN" : campos[5];
        this.DATE_ADDED = campos[6].isEmpty() ? "March 1, 1900" : campos[6];

        try{
            this.RELEASE_YEAR = Integer.parseInt(campos[7]);
        } 
        catch(Exception e){
            this.RELEASE_YEAR = 0;
        }

        this.RATING = campos[8].isEmpty() ? "NaN" : campos[8];
        this.DURATION = campos[9].isEmpty() ? "NaN" : campos[9];

        this.LISTED_IN = campos[10].isEmpty() ? new String[0] : campos[10].split(", ");
        Arrays.sort(this.LISTED_IN);
    }

    public String getTITLE(){
        return TITLE;
    }

    public static void main(String[] args) throws Exception{

        BufferedReader teclado = new BufferedReader(new InputStreamReader(System.in));
        String entrada;

        String[] linhasCSV = new String[10000];
        int totalCSV = 0;

        BufferedReader br = new BufferedReader(new FileReader("/tmp/disneyplus.csv"));
        //home/vicenzo/Documentos/GitHub/Lista-AEDS/AEDS-II/verde/TP02/disneyplus.csv
        
        br.readLine(); 
        
        while((entrada = br.readLine()) != null && totalCSV < linhasCSV.length){
            
            linhasCSV[totalCSV++] = entrada;
        }
        br.close();

        String[] idsEntrada = new String[1000];
        int totalEntrada = 0;

        while(!(entrada = teclado.readLine()).equals("FIM")){
            idsEntrada[totalEntrada++] = entrada;
        }

        Show[] shows = new Show[totalEntrada];
        int count = 0;

        for(int i = 0; i < totalEntrada; i++){
            for(int j = 0; j < totalCSV; j++){
                
                if(linhasCSV[j].startsWith(idsEntrada[i] + ",")){
                    shows[count] = new Show();
                    shows[count].ler(linhasCSV[j]);
                    count++;
                    break;
                }
            }
        }

        int comparacoes = 0, movimentacoes = 0;

        int limite = Math.min(10, count); //limitacao

        for(int i = 0; i < limite; i++){
            int min = i;

            for(int j = i + 1; j < count; j++){

                comparacoes++;
                
                if (shows[j].getTITLE().compareTo(shows[min].getTITLE()) < 0) {
                    min = j;
                }
            }

            if(i != min){
                Show temp = shows[i];
                shows[i] = shows[min];
                shows[min] = temp;
                movimentacoes += 3;
            }
        }

        for(int i = 0; i < limite; i++){
            shows[i].imprimir();
        }

        long timestamp = System.currentTimeMillis();

        java.io.FileWriter log = new java.io.FileWriter("matricula_selecao.txt");
        log.write("802305\t" + comparacoes + "\t" + movimentacoes + "\t" + timestamp + "\n");
        log.close();
    }
}

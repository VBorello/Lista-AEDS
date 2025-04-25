import java.util.*;
import java.io.*;
import java.text.*;

public class Show{

    static SimpleDateFormat ddf = new SimpleDateFormat("MMMM d, yyyy", Locale.ENGLISH);

    private String SHOW_ID;
    private String TYPE;
    private String TITLE;
    private String[] DIRECTOR;
    private String[] CAST;
    private String COUNTRY;
    private String DATE_ADDED;
    private int RELEASE_YEAR;
    private String RATING;
    private String DURATION;
    private String[] LISTED_IN;

    public Show(){
        this.SHOW_ID = "NaN";
        this.TYPE = "NaN";
        this.TITLE = "NaN";
        this.DIRECTOR = new String[0];
        this.CAST = new String[0];
        this.COUNTRY = "NaN";
        this.DATE_ADDED = "NaN";
        this.RELEASE_YEAR = -1;
        this.RATING = "NaN";
        this.DURATION = "NaN";
        this.LISTED_IN = new String[0];
    }

    public Show(String SHOW_ID, String TYPE, String TITLE, String[] DIRECTOR, String[] CAST,
                String COUNTRY, String DATE_ADDED, int RELEASE_YEAR, String RATING, String DURATION, String[] LISTED_IN){
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

    public String getSHOW_ID(){
        return this.SHOW_ID;
    }

    public void print(){
        Arrays.sort(DIRECTOR);
        Arrays.sort(CAST);
        Arrays.sort(LISTED_IN);

        String diretorStr = (DIRECTOR.length == 0) ? "NaN" : String.join(", ", DIRECTOR);
        String castStr = (CAST.length == 0) ? "NaN" : String.join(", ", CAST);
        String listedInStr = (LISTED_IN.length == 0) ? "NaN" : String.join(", ", LISTED_IN);

        System.out.println("=> " + (SHOW_ID != null ? SHOW_ID : "NaN") + " ## " +
                (TITLE != null ? TITLE : "NaN") + " ## " +
                (TYPE != null ? TYPE : "NaN") + " ## " +
                diretorStr + " ## " +
                "[" + castStr + "] ## " +
                (COUNTRY != null ? COUNTRY : "NaN") + " ## " +
                (DATE_ADDED != null ? DATE_ADDED : "NaN") + " ## " +
                (RELEASE_YEAR != -1 ? RELEASE_YEAR : "NaN") + " ## " +
                (RATING != null ? RATING : "NaN") + " ## " +
                (DURATION != null ? DURATION : "NaN") + " ## " +
                "[" + listedInStr + "] ##");
    }

    public static Show parseLinha(String linha){
        String[] campos = new String[12];
        int index = 0;
        boolean dentroAspas = false;
        StringBuilder sb = new StringBuilder();

        for (int i = 0; i < linha.length(); i++){
            char c = linha.charAt(i);

            if (c == '"'){
                dentroAspas = !dentroAspas;
            } else if (c == ',' && !dentroAspas){
                campos[index++] = sb.toString().trim();
                sb.setLength(0);
            } else{
                sb.append(c);
            }
        }
        campos[index] = sb.toString().trim();

        String[] dir = campos[3] != null && !campos[3].isEmpty() ? campos[3].split(", ") : new String[0];
        String[] cast = campos[4] != null && !campos[4].isEmpty() ? campos[4].split(", ") : new String[0];
        String[] listed = campos[10] != null && !campos[10].isEmpty() ? campos[10].split(", ") : new String[0];

        int year = -1;
        try{ year = Integer.parseInt(campos[7]); } catch (Exception ignored){}

        return new Show(
                campos[0], campos[1], campos[2],
                dir, cast,
                campos[5],
                campos[6],
                year,
                campos[8],
                campos[9],
                listed
        );
    }

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String entrada = sc.nextLine();

        while (!entrada.equals("FIM")){
            boolean encontrado = false;

            try (BufferedReader br = new BufferedReader(new FileReader("/home/vicenzo/Documentos/GitHub/Lista-AEDS/AEDS-II/verde/TP02/disneyplus.csv"))){
                br.readLine(); // pular cabeçalho
                String linha;

                while ((linha = br.readLine()) != null){
                    Show show = parseLinha(linha);

                    if (show.getSHOW_ID().equals(entrada)){
                        show.print();
                        encontrado = true;
                        break;
                    }
                }
            } catch (IOException e){
                e.printStackTrace();
            }

            if (!encontrado){
                System.out.println("Show não encontrado.");
            }

            entrada = sc.nextLine();
        }

        sc.close();
    }
}

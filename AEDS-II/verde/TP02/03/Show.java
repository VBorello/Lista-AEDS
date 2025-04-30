import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

class Celula{
    public Show elemento;
    public Celula prox;

    public Celula(Show elemento){

        this.elemento = elemento;
        this.prox = null;
    }
}

class Lista{
    private Celula primeiro, ultimo;

    public Lista(){
        primeiro = ultimo = null;
    }

    public void inserirFim(Show elemento){

        Celula nova = new Celula(elemento);
        if(primeiro == null){

            primeiro = ultimo = nova;
        }
        else{
            ultimo.prox = nova;
            ultimo = nova;
        }
    }

    public boolean pesquisar(String titulo, int[] comparacoes){

        Celula i = primeiro;
        while(i != null){
            comparacoes[0]++;
            if (i.elemento.getTITLE().equals(titulo)){

                return true;
            }
            i = i.prox;
        }
        return false;
    }
}

public class Show{
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
        return SHOW_ID;
    }
    public String getTYPE(){
        return TYPE;
    }
    public String getTITLE(){
        return TITLE;
    }
    public String[] getDIRECTOR(){
        return DIRECTOR;
    }
    public String[] getCAST(){
        return CAST;
    }
    public String getCOUNTRY(){
        return COUNTRY;
    }
    public String getDATE_ADDED(){
        return DATE_ADDED;
    }
    public int getRELEASE_YEAR(){
        return RELEASE_YEAR;
    }
    public String getRATING(){
        return RATING;
    }
    public String getDURATION(){
        return DURATION;
    }
    public String[] getLISTED_IN(){
        return LISTED_IN;
    }

    public void setSHOW_ID(String SHOW_ID){
        this.SHOW_ID = SHOW_ID;
    }
    public void setTYPE(String TYPE){
        this.TYPE = TYPE;
    }
    public void setTITLE(String TITLE){
        this.TITLE = TITLE;
    }
    public void setDIRECTOR(String[] DIRECTOR){
        this.DIRECTOR = DIRECTOR;
    }
    public void setCAST(String[] CAST){
        this.CAST = CAST;
    }
    public void setCOUNTRY(String COUNTRY){
        this.COUNTRY = COUNTRY;
    }
    public void setDATE_ADDED(String DATE_ADDED){
        this.DATE_ADDED = DATE_ADDED;
    }
    public void setRELEASE_YEAR(int RELEASE_YEAR){
        this.RELEASE_YEAR = RELEASE_YEAR;
    }
    public void setRATING(String RATING){
        this.RATING = RATING;
    }
    public void setDURATION(String DURATION){
        this.DURATION = DURATION;
    }
    public void setLISTED_IN(String[] LISTED_IN){
        this.LISTED_IN = LISTED_IN;
    }

    public static Show parseLinha(String linha){
        
        String[] campos = new String[12];
        int index = 0;
        boolean dentroAspas = false;
        StringBuilder sb = new StringBuilder();

        for(int i = 0; i < linha.length(); i++){
            
            char c = linha.charAt(i);

            if(c == '"'){
                dentroAspas = !dentroAspas;
            } 
            else if(c == ',' && !dentroAspas){
                campos[index++] = sb.toString().trim();
                sb.setLength(0);
            } 
            else{
                sb.append(c);
            }
        }
        campos[index] = sb.toString().trim();

        String[] dir = campos[3] != null && !campos[3].isEmpty() ? campos[3].split(", ") : new String[0];
        String[] cast = campos[4] != null && !campos[4].isEmpty() ? campos[4].split(", ") : new String[0];
        String[] listed = campos[10] != null && !campos[10].isEmpty() ? campos[10].split(", ") : new String[0];

        int year = -1;
        try{
            year = Integer.parseInt(campos[7]);
        }
        catch (Exception ignored){}

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
        Lista lista = new Lista();
        int[] comparacoes = new int[1];
        long inicio = System.nanoTime();

        try(BufferedReader leitor = new BufferedReader(new FileReader("/tmp/disneyplus.csv"))){
            ///home/vicenzo/Documentos/GitHub/Lista-AEDS/AEDS-II/verde/TP02/disneyplus.csv

            leitor.readLine();
            String linha;
            while ((linha = leitor.readLine()) != null){
                Show show = parseLinha(linha);
                lista.inserirFim(show);
            }
        } 
        catch (IOException e){

            e.printStackTrace();
        }

        String entrada = sc.nextLine();
        while (!entrada.equals("FIM")){
            boolean achou = lista.pesquisar(entrada, comparacoes);
            System.out.println(achou ? "SIM" : "NAO");
            entrada = sc.nextLine();
        }

        sc.close();
        long fim = System.nanoTime();
        long tempoExecucao = (fim - inicio);

        try (PrintWriter escrita = new PrintWriter("matricula_sequencial.txt")){
            escrita.println("803217\t" + tempoExecucao + "\t" + comparacoes[0]);
        } catch (IOException e){
            e.printStackTrace();
        }
    }
}

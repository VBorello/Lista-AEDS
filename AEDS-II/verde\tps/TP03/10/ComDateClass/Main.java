import java.io.*;
import java.util.*;

class Data{

    int dia;
    int mes;
    int ano;

    private static final Map<String, Integer> meses = Map.ofEntries(

        Map.entry("January", 1), Map.entry("February", 2), Map.entry("March", 3),
        Map.entry("April", 4), Map.entry("May", 5), Map.entry("June", 6),
        Map.entry("July", 7), Map.entry("August", 8), Map.entry("September", 9),
        Map.entry("October", 10), Map.entry("November", 11), Map.entry("December", 12)
    );

    public Data(String stringData){

        if(stringData == null || stringData.trim().isEmpty()){
            this.dia = 0;
            this.mes = 0;
            this.ano = 0;

            return;
        }

        try{
            stringData = stringData.trim();
            String[] partes = stringData.split(" ");

            if(partes.length == 3){
                this.mes = meses.getOrDefault(partes[0], 0);
                this.dia = Integer.parseInt(partes[1].replace(",", ""));
                this.ano = Integer.parseInt(partes[2]);
            } 
            else{
                this.dia = 0;
                this.mes = 0;
                this.ano = 0;
            }

        } 
        catch(Exception e){
            this.dia = 0;
            this.mes = 0;
            this.ano = 0;
        }
}

    public boolean dataValida(){
        return (dia != 0 && mes != 0 && ano != 0);
    }

    public int comparar(Data other){

        if(!this.dataValida() && !other.dataValida()){
            return 0;
        } 
        if(!this.dataValida()){
            return 1; 
        } 
        if(!other.dataValida()){
            return -1;
        }

        if(this.ano != other.ano){
            return this.ano - other.ano;
        } 
        if(this.mes != other.mes){
            return this.mes - other.mes;
        } 
        
        return this.dia - other.dia;
    }

    public String stringOriginal(){

        if(!dataValida()){
            return "";
        } 

        String stringMes = "";
        
        for(Map.Entry<String, Integer> entry : meses.entrySet()){
            
            if(entry.getValue() == this.mes){
                stringMes = entry.getKey();

                break;
            }
        }

        return String.format("%s %d, %d", stringMes, dia, ano);
    }

    public String formatarString(){

        if(!dataValida()){
            return "";
        } 

        return String.format("%02d/%02d/%04d", dia, mes, ano);
    }
}

class Show{

    String SHOW_ID;
    String TYPE;
    String TITLE;
    String DIRECTOR;
    String CAST;
    String COUNTRY;
    Data DATE_ADDED;   
    int RELEASE_YEAR;
    String RATING;
    String DURATION;
    String LISTED_IN;
    String DESCRIPTION;

    public Show(String SHOW_ID, String TYPE, String TITLE,
                String DIRECTOR, String CAST, String COUNTRY,
                String DATE_ADDED, int RELEASE_YEAR, String RATING,
                String DURATION, String LISTED_IN, String DESCRIPTION){

        this.SHOW_ID = SHOW_ID;
        this.TYPE = TYPE;
        this.TITLE = TITLE;
        this.DIRECTOR = DIRECTOR;
        this.CAST = CAST;
        this.COUNTRY = COUNTRY;
        this.DATE_ADDED = new Data(DATE_ADDED);
        this.RELEASE_YEAR = RELEASE_YEAR;
        this.RATING = RATING;
        this.DURATION = DURATION;
        this.LISTED_IN = LISTED_IN;
        this.DESCRIPTION = DESCRIPTION;
    }

    public void print(){

        System.out.print("=> " + SHOW_ID + " ## " + TITLE + " ## " + TYPE + " ## ");
        System.out.print(isNAN(DIRECTOR) + " ## ");

        System.out.print("[");

        if(CAST != null && !CAST.trim().isEmpty()){

            String[] cast = CAST.split(", ");
            Arrays.sort(cast);

            for(int i = 0; i < cast.length; i++){
                System.out.print(cast[i]);
                
                if(i < cast.length - 1){
                    System.out.print(", ");
                } 
            }
        }
        else{
            System.out.print("NaN");
        }
        
        System.out.print("] ## ");

        System.out.print(isNAN(COUNTRY) + " ## ");

        String stringData = DATE_ADDED.dataValida() ? DATE_ADDED.stringOriginal() : "NaN";
        System.out.print(stringData + " ## ");

        System.out.print(RELEASE_YEAR + " ## ");
        System.out.print(isNAN(RATING) + " ## ");
        System.out.print(isNAN(DURATION) + " ## ");

        System.out.print("[");

        if(LISTED_IN != null && !LISTED_IN.trim().isEmpty()){
            String[] listed = LISTED_IN.split(", ");
            
            for(int i = 0; i < listed.length; i++){
                System.out.print(listed[i]);

                if(i < listed.length - 1){
                    System.out.print(", ");
                } 
            }
        } 
        else{
            System.out.print("NaN");
        }

        System.out.println("] ##");
    }

    private String isNAN(String s){

        if(s == null || s.trim().isEmpty()){
            return "NaN";
        } 

        return s;
    }
}

class No{

    Show show;
    No ant, prox;

    No(Show show){

        this.show = show;
    }
}

class listaDupla{

    No cabeca, calda;

    static int comparacoes = 0;
    static int movimentos = 0;

    public void inserirFim(Show show){

        No novo = new No(show);
        
        if(cabeca == null){
            cabeca = calda = novo;
        } 
        else{
         
            calda.prox = novo;
            novo.ant = calda;
            calda = novo;
        }
    }

    public void printLista(){

        No aux = cabeca;

        while(aux != null){
            aux.show.print();
            aux = aux.prox;
        }
    }

    public int compararShows(Show a, Show b){

        comparacoes++;
        int comparar = a.DATE_ADDED.comparar(b.DATE_ADDED);
        
        if(comparar != 0){
            return comparar;
        } 

        comparacoes++;
        comparar = a.TITLE.compareTo(b.TITLE);

        if(comparar != 0){
            return comparar;
        } 

        comparacoes++;
        comparar = a.RELEASE_YEAR - b.RELEASE_YEAR;

        if(comparar != 0){
            return comparar;
        } 

        comparacoes++;
        return a.SHOW_ID.compareTo(b.SHOW_ID);
    }

    public No separar(No baixo, No cima){

        Show pivo = cima.show;
        No i = baixo.ant;

        for(No j = baixo; j != cima; j = j.prox){

            if(compararShows(j.show, pivo) <= 0){

                i = (i == null) ? baixo : i.prox;
                
                Show aux = i.show;
                i.show = j.show;
                j.show = aux;
                movimentos += 3;
            }
        }

        i = (i == null) ? baixo : i.prox;

        Show temp = i.show;
        i.show = cima.show;
        cima.show = temp;
        movimentos += 3;

        return i;
    }

    private void trocarNo(No a, No b){
        
        Show aux = a.show;
        a.show = b.show;
        b.show = aux;
    }

    public void quick(No baixo, No cima){

        if(cima != null && baixo != cima && baixo != cima.prox){
            
            No p = separar(baixo, cima);
            quick(baixo, p.ant);
            quick(p.prox, cima);
        }
    }
}

class limparAspas{

    public static Show parseShow(String line){

        String[] campos = new String[12];
        int indexCampos = 0;

        boolean entreAspas = false;

        StringBuilder atual = new StringBuilder();

        for(int i = 0; i < line.length(); i++){
            char c = line.charAt(i);
            
            if(c == '"'){
                entreAspas = !entreAspas;
            } 
            else if(c == ',' && !entreAspas){
                campos[indexCampos++] = atual.toString().trim();
                atual.setLength(0);
            } 
            else{
                atual.append(c);
            }
        }
        campos[indexCampos] = atual.toString().trim();

        while(indexCampos < 11){
            campos[++indexCampos] = "";
        }

        int RELEASE_YEAR = campos[7].equals("") ? 0 : Integer.parseInt(campos[7]);

        return new Show(campos[0], campos[1], campos[2], campos[3], campos[4], campos[5],
                        campos[6], RELEASE_YEAR, campos[8], campos[9], campos[10], campos[11]);
    }
}

public class Main{

    public static void main(String[] args){

        long startTime = System.currentTimeMillis();

        Map<String, Show> showMap = new HashMap<>();

        try(BufferedReader br = new BufferedReader(new FileReader("/tmp/disneyplus.csv"))){

            String linha = br.readLine();

            while((linha = br.readLine()) != null){

                Show show = limparAspas.parseShow(linha);
                showMap.put(show.SHOW_ID, show);
            }
        } 

        catch(IOException e){
            e.printStackTrace();
        }

        Scanner sc = new Scanner(System.in);
        listaDupla lista = new listaDupla();

        while(true){

            String id = sc.nextLine();
            if(id.equals("FIM")) break;
            Show s = showMap.get(id);

            if(s != null){
                lista.inserirFim(s);
            } 
        }

        lista.quick(lista.cabeca, lista.calda);

        lista.printLista();

        long endTime = System.currentTimeMillis();

        try(PrintWriter pw = new PrintWriter(new FileWriter("matricula_quick.txt"))){
            
            pw.printf("matricula\t%d\t%d\t%d\n", listaDupla.comparacoes, listaDupla.movimentos, (endTime - startTime));
        }
        catch(IOException e){
            e.printStackTrace();
        }

        sc.close();
    }
}

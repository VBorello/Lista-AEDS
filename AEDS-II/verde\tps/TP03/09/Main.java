import java.io.*;
import java.util.*;

public class Main{

    static class Data{

        int dia;
        int mes;
        int ano;

        public Data(int dia, int mes, int ano){

            this.dia = dia;
            this.mes = mes;
            this.ano = ano;
        }

        public String formatar(){

            if(ano == 0) return "NaN";
            
            String[] meses ={"January", "February", "March", "April", "May", "June",
                              "July", "August", "September", "October", "November", "December"};
            
            return meses[mes - 1] + " " + dia + ", " + ano;
        }
    }

    static class Show{

        String SHOW_ID;
        String TYPE;
        String TITLE;
        String DIRECTOR;
        List<String> CAST = new ArrayList<>();
        String COUNTRY;
        Data DATE_ADDED;
        int RELEASE_YEAR;
        String RATING;
        String DURATION;
        List<String> LISTED_IN = new ArrayList<>();

        public void imprimir(){

            System.out.print("=> " + (SHOW_ID != null ? SHOW_ID : "NaN") + " ## ");
            System.out.print((TITLE != null ? TITLE : "NaN") + " ## ");
            System.out.print((TYPE != null ? TYPE : "NaN") + " ## ");
            System.out.print((DIRECTOR != null && !DIRECTOR.isEmpty() ? DIRECTOR : "NaN") + " ## ");

            if(CAST != null && !CAST.isEmpty()){
                System.out.print("[");
                
                for(int i = 0; i < CAST.size(); i++){
                    System.out.print(CAST.get(i));
                    
                    if(i < CAST.size() - 1){
                        System.out.print(", ");
                    } 
                }

                System.out.print("]");
            } 
            else{
                System.out.print("[NaN]");
            }

            System.out.print(" ## ");
            System.out.print((COUNTRY != null && !COUNTRY.isEmpty() ? COUNTRY : "NaN") + " ## ");
            System.out.print((DATE_ADDED != null ? DATE_ADDED.formatar() : "NaN") + " ## ");
            System.out.print((RELEASE_YEAR != 0 ? RELEASE_YEAR : "NaN") + " ## ");
            System.out.print((RATING != null && !RATING.isEmpty() ? RATING : "NaN") + " ## ");
            System.out.print((DURATION != null && !DURATION.isEmpty() ? DURATION : "NaN") + " ## ");

            if(LISTED_IN != null && !LISTED_IN.isEmpty()){
                System.out.print("[");
                
                for(int i = 0; i < LISTED_IN.size(); i++){
                    System.out.print(LISTED_IN.get(i));
                    
                    if(i < LISTED_IN.size() - 1){
                        System.out.print(", ");
                    } 
                }
                
                System.out.println("] ##");
            } 
            else{
                System.out.println("[NaN] ##");
            }
        }
    }

    static class Pilha{

        Stack<Show> pilha = new Stack<>();

        public void inserir(Show s){
            pilha.push(s);
        }

        public Show remover(){

            return pilha.pop();
        }

        public void mostrar(){

            for(int i = pilha.size() - 1; i >= 0; i--){

                System.out.print("[" + i + "] ");
                pilha.get(i).imprimir();
            }
        }
    }

    static Show[] shows = new Show[1368];

    public static void main(String[] args) throws Exception{

        lerCSV("/tmp/disneyplus.csv");

        Scanner sc = new Scanner(System.in);
        Pilha pilha = new Pilha();

        while(true){

            String linha = sc.nextLine();
            if(linha.equals("FIM")){
                break;
            } 
            
            int index = acharIndex(linha);
            pilha.inserir(shows[index]);
        }

        int n = Integer.parseInt(sc.nextLine());

        for(int i = 0; i < n; i++){

            String linha = sc.nextLine();
            
            if(linha.startsWith("I ")){

                String id = linha.substring(2);
                pilha.inserir(shows[acharIndex(id)]);
            } 
            else if(linha.equals("R")){

                Show removido = pilha.remover();
                System.out.println("(R) " + removido.TITLE);
            }
        }

        pilha.mostrar();
    }

    static int acharIndex(String id){

        return Integer.parseInt(id.substring(1)) - 1;
    }

    static String limparAspas(String s){

        if(s == null || s.equals("NaN")){
            return "NaN";
        } 
        if(s.startsWith("\"") && s.endsWith("\"")){
            s = s.substring(1, s.length() - 1);
        }

        return s.replace("\"\"", "\"").trim();
    }

    static List<String> ordenarLista(String s){

        List<String> lista = new ArrayList<>();
        
        if(s.equals("NaN")) return lista;
        
        for(String item : s.split(",")){

            item = item.trim();
            if(!item.isEmpty()){
                lista.add(item);
            } 
        }

        Collections.sort(lista);
        
        return lista;
    }

    static Data separarData(String date){
        
        if(date.equals("NaN")){
            return new Data(0, 0, 0);
        } 

        String[] partes = date.split("[ ,]+");
        
        if(partes.length != 3){
            return new Data(0, 0, 0);
        } 

        String[] meses = {"January", "February", "March", "April", "May", "June",
                          "July", "August", "September", "October", "November", "December"};
        int mes = 0;
        
        for(int i = 0; i < meses.length; i++){
        
            if(meses[i].equals(partes[0])){
                mes = i + 1;
                
                break;
            }
        }

        return new Data(Integer.parseInt(partes[1]), mes, Integer.parseInt(partes[2]));
    }

    static void lerCSV(String caminho) throws Exception{
        
        BufferedReader bufferedReader = new BufferedReader(new FileReader(caminho));
        bufferedReader.readLine();
        String linha;

        while((linha = bufferedReader.readLine()) != null){
            
            String[] campos = new String[12];
            
            int i = 0;
            
            boolean entreAspas = false;
            
            StringBuilder stringBuilder = new StringBuilder();
            
            for(int j = 0; j < linha.length(); j++){
                char c = linha.charAt(j);
                if(c == '"'){
                    entreAspas = !entreAspas;
                } 
                else if(c == ',' && !entreAspas){
                    campos[i++] = limparAspas(stringBuilder.toString());
                    stringBuilder.setLength(0);
                } 
                else{
                    stringBuilder.append(c);
                }
            }
            campos[i] = limparAspas(stringBuilder.toString());
            
            for(int k = i + 1; k < 12; k++){
                campos[k] = "NaN";
            } 

            int index = acharIndex(campos[0]);

            Show show = new Show();

            show.SHOW_ID = campos[0];
            show.TYPE = campos[1];
            show.TITLE = campos[2];
            show.DIRECTOR = campos[3];
            show.CAST = ordenarLista(campos[4]);
            show.COUNTRY = campos[5];
            show.DATE_ADDED = separarData(campos[6]);
            show.RELEASE_YEAR = campos[7].equals("NaN") ? 0 : Integer.parseInt(campos[7]);
            show.RATING = campos[8];
            show.DURATION = campos[9];
            show.LISTED_IN = ordenarLista(campos[10]);

            shows[index] = show;
        }

        bufferedReader.close();
    }
}

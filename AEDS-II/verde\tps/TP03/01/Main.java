import java.io.*;
import java.util.*;

class Show{

    String SHOW_ID;
    String TYPE;
    String TITLE;
    String DIRECTOR;
    String CAST;
    String COUNTRY;
    String DATE_ADDED;
    String RATING;
    String RELEASE_YEAR;
    String DURATION;
    String LISTED_IN;
    String DESCRIPTION;

    public Show(){}

    public Show(String linha){
        
        ArrayList<String> campos = new ArrayList<>();

        boolean entreAspas = false;
        StringBuilder stringBuilder = new StringBuilder();

        for(int i = 0; i < linha.length(); i++){
            char c = linha.charAt(i);

            if(c == '"'){
                entreAspas = !entreAspas;
            } 
            else if (c == ',' && !entreAspas){
                campos.add(stringBuilder.toString().trim());
                stringBuilder.setLength(0);
            } 
            else{
                stringBuilder.append(c);
            }
        }

        campos.add(stringBuilder.toString().trim());

        int i = 0;

        this.SHOW_ID = vazio(campos.get(i++));
        this.TYPE = vazio(campos.get(i++));
        this.TITLE = vazio(campos.get(i++));
        this.DIRECTOR = vazio(campos.get(i++));

        String elenco = campos.get(i++);
        
        if(elenco.isEmpty()){
            this.CAST = "NaN";
        } 
        else{
        
            String[] nomes = elenco.split(",\\s*");
            Arrays.sort(nomes);
            this.CAST = String.join(", ", nomes);
        }

        this.COUNTRY = vazio(campos.get(i++));
        this.DATE_ADDED = vazio(campos.get(i++));
        this.RELEASE_YEAR = vazio(campos.get(i++));
        this.RATING = vazio(campos.get(i++));
        this.DURATION = vazio(campos.get(i++));
        this.LISTED_IN = vazio(campos.get(i++));
        this.DESCRIPTION = vazio(campos.get(i++));
    }

    private String vazio(String campo){
        
        return campo.isEmpty() ? "NaN" : campo;
    }


    public void imprimir(){

        String[] categorias = LISTED_IN.split(",\\s*");
        
        Arrays.sort(categorias);
        String categoriasOrdenadas = String.join(", ", categorias);

        System.out.println("=> " + SHOW_ID + " ## " + TITLE + " ## " + TYPE + " ## " + DIRECTOR + " ## " +
                           "[" + CAST + "] ## " + COUNTRY + " ## " + DATE_ADDED + " ## " + RELEASE_YEAR + " ## " +
                           RATING + " ## " + DURATION + " ## [" + categoriasOrdenadas + "] ##");
    }

    public String getTITLE(){

        return this.TITLE;
    }
}


class Lista{
    
    private Show[] array;
    private int n;

    public Lista(int tamanho){
        
        array = new Show[tamanho];
        n = 0;
    }

    public void inicio(Show show) throws Exception{
        
        if(n >= array.length) throw new Exception("Erro ao inserir!");
        
        for(int i = n; i > 0; i--){
            array[i] = array[i - 1];
        }

        array[0] = show;
        n++;
    }

    public void fim(Show show) throws Exception{
        
        if(n >= array.length) throw new Exception("Erro ao inserir");
        array[n++] = show;
    }

    public void inserir(Show show, int pos) throws Exception{
        
        if(n >= array.length || pos < 0 || pos > n) throw new Exception("Erro ao inserir");
        
        for(int i = n; i > pos; i--){
            array[i] = array[i - 1];
        }

        array[pos] = show;
        n++;
    }

    public Show removerInicio() throws Exception{
        
        if(n == 0) throw new Exception("Erro ao remover!");
        Show resp = array[0];
        
        for(int i = 0; i < n - 1; i++){
            array[i] = array[i + 1];
        } 

        n--;
        
        return resp;
    }

    public Show removerFim() throws Exception{
        
        if(n == 0) throw new Exception("Erro ao remover!");
        
        return array[--n];
    }

    public Show remover(int pos) throws Exception{
        
        if(n == 0 || pos < 0 || pos >= n) throw new Exception("Erro ao remover!");
        Show resp = array[pos];
        
        for(int i = pos; i < n - 1; i++){
            array[i] = array[i + 1];
        } 
        n--;

        return resp;
    }

    public void mostrar(){
        
        for(int i = 0; i < n; i++){
            array[i].imprimir();
        }
    }
}

public class Main{
    
    static HashMap<String, String> mapa = new HashMap<>();

    public static void carregarCSV() throws Exception{
    
        BufferedReader br = new BufferedReader(new FileReader("/tmp/disneyplus.csv"));
    
        br.readLine();
        String linha;
    
        while((linha = br.readLine()) != null){
            String id = linha.split(",", 2)[0];
            mapa.put(id, linha);
        }

        br.close();
    }

    public static Show buscarPorId(String id){
        
        if(mapa.containsKey(id)){
            return new Show(mapa.get(id));
        }
        
        return null;
    }

    public static void main(String[] args) throws Exception{
        
        Scanner scanner = new Scanner(System.in);
        carregarCSV();

        Lista lista = new Lista(1000);

        while(true){
            String entrada = scanner.nextLine();
            if(entrada.equals("FIM")) break;
        
            Show s = buscarPorId(entrada);
            if(s != null) lista.fim(s);
        }

        int n = Integer.parseInt(scanner.nextLine());
        
        for(int i = 0; i < n; i++){
        
            String linha = scanner.nextLine();

            String[] partes = linha.split(" ");
            String cmd = partes[0];

            if(cmd.equals("II")){
            
                Show s = buscarPorId(partes[1]);
                lista.inicio(s);
            } 
            else if(cmd.equals("IF")){
            
                Show s = buscarPorId(partes[1]);
                lista.fim(s);
            } 
            else if(cmd.equals("I*")){
            
                int pos = Integer.parseInt(partes[1]);
                Show s = buscarPorId(partes[2]);
                lista.inserir(s, pos);
            } 
            else if(cmd.equals("RI")){
            
                Show r = lista.removerInicio();
                System.out.println("(R) " + r.getTITLE());
            }
            else if(cmd.equals("RF")){
            
                Show r = lista.removerFim();
                System.out.println("(R) " + r.getTITLE());
            }
            else if(cmd.equals("R*")){
            
                int pos = Integer.parseInt(partes[1]);
                Show r = lista.remover(pos);
            
                System.out.println("(R) " + r.getTITLE());
            }
        }

        lista.mostrar();
        
        scanner.close();
    }
}

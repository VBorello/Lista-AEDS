import java.io.*;
import java.util.*;

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
        this.RELEASE_YEAR = 0;
        this.CAST = new String[]{"NaN"};
        this.LISTED_IN = new String[]{"NaN"};
    }

    public void read(String line){

        List<String> fields = new ArrayList<>();
        
        boolean insideQuotes = false;
        StringBuilder currentField = new StringBuilder();

        for(int i = 0; i < line.length(); i++){
            
            char c = line.charAt(i);
            
            if (c == '"'){
                insideQuotes = !insideQuotes;
            }
            else if (c == ',' && !insideQuotes){
            
                fields.add(currentField.toString());
                currentField.setLength(0);
            } 
            else{
                currentField.append(c);
            }
        }

        fields.add(currentField.toString());

        this.SHOW_ID = fields.get(0);
        this.TYPE = fields.get(1);
        this.TITLE = fields.get(2);
        this.DIRECTOR = fields.get(3).isEmpty() ? "NaN" : fields.get(3);
        this.CAST = fields.get(4).isEmpty() ? new String[]{"NaN"} : fields.get(4).split(";\\s*");
        this.COUNTRY = fields.get(5).isEmpty() ? "NaN" : fields.get(5);
        this.DATE_ADDED = fields.get(6).isEmpty() ? "NaN" : fields.get(6);
        this.RELEASE_YEAR = fields.get(7).isEmpty() ? 0 : Integer.parseInt(fields.get(7));
        this.RATING = fields.get(8).isEmpty() ? "NaN" : fields.get(8);
        this.DURATION = fields.get(9).isEmpty() ? "NaN" : fields.get(9);
        this.LISTED_IN = fields.get(10).isEmpty() ? new String[]{"NaN"} : fields.get(10).split(";\\s*");
    }

    public String getTITLE(){
        return TITLE;
    }

    public String toString(){

        return "=> " + SHOW_ID + " ## " + TITLE + " ## " + TYPE + " ## " + DIRECTOR + " ## " + Arrays.toString(CAST)
                + " ## " + COUNTRY + " ## " + DATE_ADDED + " ## " + RELEASE_YEAR + " ## " + RATING + " ## " + DURATION
                + " ## " + Arrays.toString(LISTED_IN) + " ##";
    }

    public static void main(String[] args) throws Exception{
    
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        
        String path = "/tmp/disneyplus.csv";
        BufferedReader csvReader = new BufferedReader(new FileReader(path));

        String line;
        List<Show> list = new ArrayList<>();

        csvReader.readLine(); 

        while((line = csvReader.readLine()) != null){
        
            Show show = new Show();
            show.read(line);
            list.add(show);
        }
        
        csvReader.close();

        Show[] vetor = new Show[3000];
        int n = 0;
        String input;

        while(!(input = in.readLine()).equals("FIM")){
            
            for(Show s : list){
                if(s.SHOW_ID.equals(input)){
                    
                    vetor[n++] = s;
                    break;
                }
            }
        }

        List<String> consultas = new ArrayList<>();

        while((input = in.readLine()) != null && !input.equals("FIM")){    
            consultas.add(input);
        }

        int comparacoes = 0;
        long inicio = System.nanoTime();

        for(String idConsulta : consultas){
            
            boolean encontrado = false;
            
            for(int i = 0; i < n; i++){   
                comparacoes++;
                
                if(vetor[i].SHOW_ID.equals(idConsulta)){
                    encontrado = true;
                    break;
                }
            }
            System.out.println(encontrado ? "SIM" : "NAO");
        }

        long fim = System.nanoTime();
        double tempo = (fim - inicio) / 1e6;

        PrintWriter log = new PrintWriter("matricula_sequencial.txt");

        log.printf("1234567\t%.3f\t%d\n", tempo, comparacoes);
        log.close();
    }
}
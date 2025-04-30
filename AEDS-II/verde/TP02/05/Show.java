import java.io.*;
import java.text.*;
import java.util.*;

public class Show{
    private String showId;
    private String type;
    private String title;
    private String director;
    private String[] cast;
    private String country;
    private Date dateAdded;
    private int releaseYear;
    private String rating;
    private String duration;
    private String[] listedIn;

    //construtores
    public Show(){
        this.showId = "NaN";
        this.type = "NaN";
        this.title = "NaN";
        this.director = "NaN";
        this.cast = new String[]{"NaN"};
        this.country = "NaN";
        this.dateAdded = new Date(0);
        this.releaseYear = 0;
        this.rating = "NaN";
        this.duration = "NaN";
        this.listedIn = new String[]{"NaN"};
    }

    public Show(String showId, String title){
        this();
        this.showId = showId;
        this.title = title;
    }

    //setts getts
    public String getShowId(){
        return showId;
    }
    public void setShowId(String showId){
        this.showId = showId;
    }

    public String getType(){
        return type;
    }
    public void setType(String type){
        this.type = type;
    }

    public String getTitle(){
        return title;
    }
    public void setTitle(String title){
        this.title = title;
    }

    public String getDirector(){
        return director;
    }
    public void setDirector(String director){
        this.director = director;
    }

    public String[] getCast(){
        return cast;
    }
    public void setCast(String[] cast){ 
        this.cast = cast;
        Arrays.sort(this.cast);
    }

    public String getCountry(){
        return country;
    }
    public void setCountry(String country){
        this.country = country;
    }

    public Date getDateAdded(){
        return dateAdded;
    }
    public void setDateAdded(Date dateAdded){
        this.dateAdded = dateAdded;
    }

    public int getReleaseYear(){
        return releaseYear;
    }
    public void setReleaseYear(int releaseYear){
        this.releaseYear = releaseYear;
    }

    public String getRating(){
        return rating;
    }
    public void setRating(String rating){
        this.rating = rating;
    }

    public String getDuration(){
        return duration;
    }
    public void setDuration(String duration){
        this.duration = duration;
    }

    public String[] getListedIn(){
        return listedIn;
    }
    public void setListedIn(String[] listedIn){ 
        this.listedIn = listedIn;
        Arrays.sort(this.listedIn);
    }

    //clone
    public Show clone(){
        Show cloned = new Show();
        cloned.showId = this.showId;
        cloned.type = this.type;
        cloned.title = this.title;
        cloned.director = this.director;
        cloned.cast = this.cast.clone();
        cloned.country = this.country;
        cloned.dateAdded = (Date) this.dateAdded.clone();
        cloned.releaseYear = this.releaseYear;
        cloned.rating = this.rating;
        cloned.duration = this.duration;
        cloned.listedIn = this.listedIn.clone();
        return cloned;
    }

    //ler
    public void ler(String line){

        String[] parts = line.split(",(?=(?:[^\"]*\"[^\"]*\")*[^\"]*$)", -1);
        
        try{
            this.showId = parts[0].isEmpty() ? "NaN" : parts[0];
            this.type = parts[1].isEmpty() ? "NaN" : parts[1];
            this.title = parts[2].isEmpty() ? "NaN" : parts[2];
            this.director = parts[3].isEmpty() ? "NaN" : parts[3];
            
            //cast
            if(parts[4].isEmpty() || parts[4].equals("\"\"")){
                this.cast = new String[]{"NaN"};
            }
            else{
                String castStr = parts[4].replace("\"", "");
                this.cast = castStr.split(",\\s*");
                Arrays.sort(this.cast);
            }
            
            this.country = parts[5].isEmpty() ? "NaN" : parts[5];
            
            //date
            if(parts[6].isEmpty()){
                this.dateAdded = new Date(0);
            }
            else{
                try{
                    SimpleDateFormat format = new SimpleDateFormat("MMMM d, yyyy");
                    this.dateAdded = format.parse(parts[6]);
                }
                catch(Exception e){
                    this.dateAdded = new Date(0);
                }
            }
            
            this.releaseYear = parts[7].isEmpty() ? 0 : Integer.parseInt(parts[7]);
            this.rating = parts[8].isEmpty() ? "NaN" : parts[8];
            this.duration = parts[9].isEmpty() ? "NaN" : parts[9];
            
            //listed_in
            if(parts[10].isEmpty() || parts[10].equals("\"\"")){
                this.listedIn = new String[]{"NaN"};
            } 
            else{
                String listedInStr = parts[10].replace("\"", "");
                this.listedIn = listedInStr.split(",\\s*");
                Arrays.sort(this.listedIn);
            }
        }
        catch (ArrayIndexOutOfBoundsException e){
            // Handle error if needed
        }
    }

    //print
    public void imprimir(){

        SimpleDateFormat dateFormat = new SimpleDateFormat("MMMM d, yyyy");
        String dateStr = (dateAdded.getTime() == 0) ? "NaN" : dateFormat.format(dateAdded);
        
        System.out.print(
            "[=> " + showId + " ## " + title + " ## " + type + " ## " + director + " ## " + 
            Arrays.toString(cast) + " ## " + country + " ## " + dateStr + " ## " + 
            (releaseYear == 0 ? "NaN" : releaseYear) + " ## " + rating + " ## " + duration + " ## " + 
            Arrays.toString(listedIn) + " ##"
        );
        
        System.out.println();
    }

    //seleção
    public static void main(String[] args){

        ArrayList<Show> shows = new ArrayList<>();
        String line;
        
        try(BufferedReader br = new BufferedReader(new FileReader("/tmp/disneyplus.csv"))){
///home/vicenzo/Documentos/GitHub/Lista-AEDS/AEDS-II/verde/TP02/disneyplus.csv

            br.readLine(); 
            
            while((line = br.readLine()) != null){

                Show show = new Show();
                show.ler(line);
                shows.add(show);
            }
        }
        catch(IOException e){
            System.err.println("Erro ao ler o arquivo: " + e.getMessage());
            return;
        }
        
        Scanner scanner = new Scanner(System.in);
        ArrayList<String> ids = new ArrayList<>();
        
        while(scanner.hasNextLine()){

            String id = scanner.nextLine().trim();
            if (id.equals("FIM")) break;
            ids.add(id);
        }
        scanner.close();
        
        //filtrar
        ArrayList<Show> filteredShows = new ArrayList<>();
        for(String id : ids){
            for (Show show : shows){

                if(show.getShowId().equals(id)){
                    filteredShows.add(show);
                    break;
                }
            }
        }
        
        Show[] showsArray = filteredShows.toArray(new Show[0]);
        
        long startTime = System.currentTimeMillis();
        int comparisons = 0;
        int movements = 0;
        
        for(int i = 0; i < showsArray.length - 1; i++){

            int minIndex = i;
            for(int j = i + 1; j < showsArray.length; j++){

                comparisons++;
                if(showsArray[j].getTitle().compareTo(showsArray[minIndex].getTitle()) < 0){
                    minIndex = j;
                }
            }
            if(minIndex != i){
                Show temp = showsArray[i];
                showsArray[i] = showsArray[minIndex];
                showsArray[minIndex] = temp;
                movements += 3;
            }
        }
        
        long endTime = System.currentTimeMillis();
        long executionTime = endTime - startTime;
        
        //arquivo log
        try(PrintWriter writer = new PrintWriter("matricula_selecao.txt")){
            writer.println("123456" + "\t" + comparisons + "\t" + movements + "\t" + executionTime);
        }
        catch(FileNotFoundException e){
            System.err.println("Erro ao criar arquivo de log: " + e.getMessage());
        }
        
        for (Show show : showsArray){
            show.imprimir();
        }
    }
}
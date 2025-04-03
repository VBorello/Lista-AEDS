import java.util.*;

//path ="./home/vicenzo/Documentos/GitHub/Lista-AEDS/AEDS-II/verde/TP02/disneyplus.csv";
//path ="/tmp/disneyplus.csv";

public class Show{

    static SimpleDateFormat ddf = new SimpleDateFormat("dd-MM-yyyy");

    private string SHOW_ID;
    private string TYPE;
    private string TITLE;
    private ArrayList<string> DIRECTOR;
    private ArrayList<string> CAST;
    private string COUNTRY;
    private string DATE_ADDED;
    private int RELEASE_YEAR;
    private string DURATION;
    private ArrayList<string> LISTED_IN;

    //construtor vasio
    public Show(){

        this.SHOW_ID = "";
        this.TYPE = "";
        this.TITLE = "";
        this.DIRECTOR =  new ArrayList<string>();
        this.CAST = new ArrayList<string>();
        this.COUNTRY = "";
        this.DATE_ADDED = "";
        this.RELEASE_YEAR = 0;
        this.DURATION = "";
        this.LISTED_IN = new ArrayList<string>();
    }

    //construtor 
    public Show( string SHOW_ID, string TYPE, string TITLE, ArrayList<string> DIRECTOR, ArrayList<string> CAST, string COUNTRY, string DATE_ADDED, int RELEASE_YEAR, string DURATION, ArrayList<string> LISTED_IN){

        this.SHOW_ID = SHOW_ID;
        this.TYPE = TYPE;
        this.TITLE = TITLE;
        this.DIRECTOR = DIRECTOR;
        this.CAST = CAST;
        this.COUNTRY = COUNTRY;
        this.DATE_ADDED = DATE_ADDED;
        this.RELEASE_YEAR = RELEASE_YEAR;
        this.DURATION = DURATION;
        this.LISTED_IN = LISTED_IN;
    }

    //sets
    public void setSHOW_ID(String SHOW_ID){
        this.SHOW_ID = SHOW_ID;
    }
    public void setTYPE(String TYPE){ 
        this.TYPE = TYPE; 
    }
    public void setTITLE(ArrayList<string> DIRECTOR){
        this.DIRECTOR = DIRECTOR;
    }
    public void setCast(ArrayList<string> CAST){
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
    public void setDURATION(String DURATION){
        this.DURATION = DURATION;
    }
    public void setLISTED_IN(ArrayList<string> LISTED_IN){
        this.LISTED_IN = LISTED_IN;
    }

    //gets
    public String SHOW_ID(){
        return this.SHOW_ID;
    }
    public String TYPE(){
        return this.TYPE;
    }
    public ArrayList<string> TITLE(){
        return this.TITLE;
    }
    public ArrayList<string> DIRECTOR(){
        return this.DIRECTOR;
    }
    public ArrayList<string> CAST(){
        return this.CAST;
    }
    public String COUNTRY(){
        return this.COUNTRY;
    }
    public String DATE_ADDED(){
        return this.DATE_ADDED;
    }
    public int RELEASE_YEAR(){
        return this.RELEASE_YEAR;
    }
    public String DURATION(){
        return this.DURATION;
    }
    public ArrayList<string> LISTED_IN(){
        return this.LISTED_IN;
    }


    
}
import java.util.*;
import java.io.*;

class Date{
    String dia;
    String mes;
    String ano;
}

class Jogadores{
    public String nome;
    public String foto;
    public Date nascimento;
    public int id;
    public int[] times;

    public void imprimir(){
        
        System.out.print(this.id + " " + this.nome + " " + this.nascimento.dia + "/" + this.nascimento.mes + "/" + this.nascimento.ano + " " + this.foto + " " + "(");

        for(int i = 0; i < times.length; i++){
            
            System.out.print(times[i]);
            
            if (i != times.length - 1) {
                System.out.print(", ");
            }
        }
        
        System.out.println(")");
    }

    public void ler(String input){

        int i = 0;

        String index = separar(input, i, ',');
        i += index.length() + 1;

        this.nome = separar(input, i, ',');
        i += nome.length() + 1;

        this.foto = separar(input, i, ',');
        i += foto.length() + 1;

        this.nascimento = new Date();
        this.nascimento.dia = separar(input, i, '/');
        i += nascimento.dia.length() + 1;

        this.nascimento.mes = separar(input, i, '/');
        i += nascimento.mes.length() + 1;

        this.nascimento.ano = separar(input, i, ',');
        i += nascimento.ano.length() + 1;

        index = separar(input, i, ',');
        i += index.length() + 1;

        String idString = separar(input, i, ',');
        
        this.id = Integer.parseInt(idString);
        i += idString.length() + 1;

        int n = contarTimes(input, i);
        
        if (input.charAt(i) == '"') i += 2;
        else i++;

        this.times = new int[n];

        for(int j = 0; j < n - 1; j++){
           
            String timeString = separar(input, i, ',');
            this.times[j] = Integer.parseInt(timeString);
            
            i += timeString.length() + 2;
        }
        
        String timeString = separar(input, i, ']');
        this.times[n - 1] = Integer.parseInt(timeString);
    }

    public String separar(String input, int i, char delimiter){
        
        StringBuilder stringer = new StringBuilder();
        
        while(input.charAt(i) != delimiter){
            stringer.append(input.charAt(i));
            i++;
        }

        return stringer.toString();
    }

    public int contarTimes(String input, int i) {
        
        int times = 1;
        
        while(input.charAt(i) != ']'){
            if(input.charAt(i) == ','){
                times++;
            }
            i++;
        }

        return times;
    }
}

public class Jogador{

    public static void main(String[] args){
    
        Scanner scanner = new Scanner(System.in);

        ArrayList<Jogadores> lista = new ArrayList<>();

        while(scanner.hasNextLine()){
            
            String linha = scanner.nextLine();
            
            if(linha.equals("FIM")){
                break;
            } 

            Jogadores jogador = new Jogadores();
            jogador.ler(linha);
        
            lista.add(jogador);
        }


        Jogadores[] jogadores = new Jogadores[lista.size()];
        jogadores = lista.toArray(jogadores);

        //selecao id
        for(int i = 0; i < jogadores.length - 1; i++){
            int min = i;
            
            for(int j = i + 1; j < jogadores.length; j++){
                if(jogadores[j].id < jogadores[min].id){
                    min = j;
                }
            }

            Jogadores temp = jogadores[i];
            jogadores[i] = jogadores[min];
            
            jogadores[min] = temp;
        }

        for(Jogadores j : jogadores) {
            j.imprimir();
        }
    }
}
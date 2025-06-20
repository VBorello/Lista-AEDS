import java.io.*;
import java.util.*;

class No{

    String nome;
    No esquerda, direita;

    No(String nome){

        this.nome = nome;
        this.esquerda = this.direita = null;
    }
}

public class ArvoreBinaria{

    static No raiz = null;
    static int comparacoes = 0;
    static final String MATRICULA = "123456"; 

    static No inserir(No No, String nome){
        
        if(No == null){
            return new No(nome);
        }

        int cmp = nome.compareTo(No.nome);
        
        if(cmp < 0){

            No.esquerda = inserir(No.esquerda, nome);
        } 
        else if(cmp > 0){

            No.direita = inserir(No.direita, nome);
        }
        
        return No;
    }

    static boolean exists(No No, String nome){
        
        while(No != null){
            
            int cmp = nome.compareTo(No.nome);
            
            if(cmp == 0){
                return true;
            } 
            else if(cmp < 0){
                No = No.esquerda;
            } 
            else{
                No = No.direita;
            } 
        }

        return false;
    }

    static void pesquisar(No No, String nome){

        No atual = No;
        boolean achou = false;

        System.out.print("raiz ");

        while (atual != null){

            comparacoes++;
            
            int cmp = nome.compareTo(atual.nome);

            if(cmp == 0){

                achou = true;
                break;
            } 
            else if(cmp < 0){

                System.out.print("esq ");
                atual = atual.esquerda;
            } 
            else{

                System.out.print("dir ");
                atual = atual.direita;
            }
        }

        if(achou){
            System.out.println("SIM");
        }
        else{
            System.out.println("NAO");
        }
    }

    public static void main(String[] args) throws IOException{

        Scanner scanner = new Scanner(System.in);
        long tempoInicio = System.nanoTime();

        while(scanner.hasNext()){
            
            String entrada = scanner.next();
            
            if(entrada.equals("FIM")){
                break;
            } 

            if(!exists(raiz, entrada)){
                raiz = inserir(raiz, entrada);
            }
        }

        while(scanner.hasNext()){

            String entrada = scanner.next();

            if(entrada.equals("FIM")){
                break;
            } 

            pesquisar(raiz, entrada);
        }

        long tempoFim = System.nanoTime();
        double totalTime = (tempoFim - tempoInicio) / 1e9; 

        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(MATRICULA + "_arvoreBinaria.txt"));
        bufferedWriter.write(MATRICULA + "\t" + String.format("%.8f", totalTime) + "\t" + comparacoes);

        bufferedWriter.newLine();
        bufferedWriter.close();
    }
}

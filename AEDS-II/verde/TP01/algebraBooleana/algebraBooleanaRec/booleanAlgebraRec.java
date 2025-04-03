import java.util.Scanner;

public class booleanAlgebraRec{

    public static String trocaBinaria(int[] binarios, String booleana, String troca, int index){

        if (index < booleana.length()){
            if (booleana.charAt(index) != ' '){
                if (booleana.charAt(index) == 'A'){

                    troca += binarios[0]; 
                }
                else if (booleana.charAt(index) == 'B'){

                    troca += binarios[1]; 
                }
                else if (booleana.charAt(index) == 'C'){

                    troca += binarios[2]; 
                }
                else{

                    troca += booleana.charAt(index); 
                }
            }

            troca = trocaBinaria(binarios, booleana, troca, index + 1);
        }

        return troca;
    }

    public static String NOT(String booleana, String not, int index){

        if (index < booleana.length()){
            if (booleana.charAt(index) == 'n' && (booleana.charAt(index + 4) == '1' ||
                booleana.charAt(index + 4) == '0')){

                not += booleana.charAt(index + 4) == '1' ? 0 : 1; 

                index += 5;
            }
            else{

                not += booleana.charAt(index);
            }

            not = NOT(booleana, not, index + 1);
        }

        return not;
    }

    public static String AND(String booleana, String and, int index){

        if (index < booleana.length()){
            if (booleana.charAt(index) == 'a' && (booleana.charAt(index + 4) == '1' ||
                booleana.charAt(index + 4) == '0') && (booleana.charAt(index + 6) == '1' ||
                booleana.charAt(index + 6) == '0')){

                if(booleana.charAt(index + 7) == ')'){

                    and += (booleana.charAt(index + 4) == '1' && booleana.charAt(index + 6) == '1') ? 1 : 0;

                    index += 7; //passa essa operacao
                }
                else if (booleana.charAt(index + 9) == ')'){

                    and += (booleana.charAt(index + 4) == '1' && booleana.charAt(index + 6) == '1' &&
                    booleana.charAt(index + 8) == '1') ? 1 : 0; 
                    
                    index += 9; 
                }
                else if (booleana.charAt(index + 11) == ')'){

                    and += (booleana.charAt(index + 4) == '1' && booleana.charAt(index + 6) == '1' &&
                    booleana.charAt(index + 8) == '1' && booleana.charAt(index + 10) == '1') ? 1 : 0;

                    index += 11; 
                }
                else{

                    and += booleana.charAt(index);
                }
            }
            else{

                and += booleana.charAt(index);
            }
            
            and = AND(booleana, and, index + 1);
        }
        
        return and;
    }

    public static String OR(String booleana, String or, int index){

        if (index < booleana.length()){
            if (booleana.charAt(index) == 'o' && booleana.charAt(index + 1) == 'r' &&
                (booleana.charAt(index + 3) == '1' || booleana.charAt(index + 3) == '0') &&
                (booleana.charAt(index + 5) == '1' || booleana.charAt(index + 5) == '0')){
                
                if (booleana.charAt(index + 6) == ')'){
                    or += (booleana.charAt(index + 3) == '1' || booleana.charAt(index + 5) == '1') ? 1 : 0;
                    
                    index += 6;
                }
                else if (booleana.charAt(index + 8) == ')'){
                    or += (booleana.charAt(index + 3) == '1' ||
                    booleana.charAt(index + 5) == '1' || booleana.charAt(index + 7) == '1') ? 1 : 0;
                    
                    index += 8; 
                }
                else if (booleana.charAt(index + 10) == ')'){

                    or += (booleana.charAt(index + 3) == '1' ||
                    booleana.charAt(index + 5) == '1' || booleana.charAt(index + 7) == '1' ||
                    booleana.charAt(index + 9) == '1') ? 1 : 0;

                    index += 10;
                }
            }
            else{

                or += booleana.charAt(index);
            }

            or = OR(booleana, or, index + 1);
        }
        
        return or;
    }

    public static String contaParenteses(String booleana, int operacao){
        
        int tam = booleana.length() - 1;
        String funcao = "";
    
        if (operacao == tam){
          
          funcao = booleana;
        }
        else if (booleana.charAt(operacao) == 'n'){
        
            funcao = NOT(contaParenteses(booleana, operacao + 4), "", 0);
        }
        else if (booleana.charAt(operacao) == 'a'){
            
            funcao = AND(contaParenteses(booleana, operacao + 4), "", 0);
        }
        else if (booleana.charAt(operacao) == 'o'){
            
            funcao = OR(contaParenteses(booleana, operacao + 3), "", 0);
        }
        else{
            funcao = contaParenteses(booleana, ++operacao);
        }

        return funcao;
        
    }

    public static void main (String[] args){

        Scanner scanner = new Scanner(System.in);
        
        int qtdB = scanner.nextInt();
        
        String booleana;
        int[] binarios = new int[3];

        while(qtdB != 0){
            for(int i = 0 ; i < qtdB ; i++){
                binarios[i] = scanner.nextInt();
            }

            booleana = scanner.nextLine();

            booleana = trocaBinaria(binarios, booleana, "", 0);
            
            booleana = contaParenteses(booleana, 0);

            System.out.println(booleana);

            qtdB = scanner.nextInt();
        }
        scanner.close();
    }
}
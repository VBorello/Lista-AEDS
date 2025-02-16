import java.util.*;

public class algebraBooleana{

    public static String trocaBinaria(int[] binarios, String booleana){
        
        String troca = "";

        for(int i = 0; i < booleana.length(); i++){

            if(booleana.charAt(i) != ' '){
                
                //remove o A pelo primeiro valor binario
                if(booleana.charAt(i) == 'A'){
                    troca += binarios[0];
                }
                //remove o B pelo segundo valor binario
                else if(booleana.charAt(i) == 'B'){
                    troca += binarios[1];
                }
                //remove o C pelo terceiro valor binario
                else if(booleana.charAt(i) == 'C'){
                    troca += binarios[2];
                }
                else{//remover espaços
                    troca += booleana.charAt(i);
                }
            }
        }

        return troca;
    }

    public static String NOT(String booleana){

        String not = "";

        for(int i = 0; i < booleana.length(); i++){

            if (booleana.charAt(i) == 'n' &&
                (booleana.charAt(i + 4) == '1' ||
                booleana.charAt(i + 4) == '0')){

                if(booleana.charAt(i + 4) == '1'){

                    not += "0";
                }
                else{

                    not += "1";
                }

                i += 5;

            }
            else{

                not += booleana.charAt(i);
            }
        }

        return not;
    }

    private static String AND(String booleana){

        String and = "";

        for(int i = 0; i < booleana.length(); i++){

            if(booleana.charAt(i) == 'a' &&
                (booleana.charAt(i + 4) == '1' ||
                booleana.charAt(i + 4) == '0') &&
                (booleana.charAt(i + 6) == '1' ||
                booleana.charAt(i + 6) == '0')){

                if(booleana.charAt(i + 7) == ')'){

                    if(booleana.charAt(i + 4) == '1' &&
                        booleana.charAt(i + 6) == '1'){

                            and += "1";
                    }
                    else{

                        and += "0";
                    }

                    i += 7;
                
                }
                else if(booleana.charAt(i + 9) == ')'){

                    if(booleana.charAt(i + 4) == '1' &&
                        booleana.charAt(i + 6) == '1' &&
                        booleana.charAt(i + 8) == '1'){

                        and += "1";
                    }
                    else{

                        and += "0";
                    }

                    i += 9;

                }
                else if(booleana.charAt(i + 11) == ')'){

                    if(booleana.charAt(i + 4) == '1' &&
                        booleana.charAt(i + 6) == '1' &&
                        booleana.charAt(i + 8) == '1' &&
                        booleana .charAt(i + 10) ==  '1'){

                        and += "1";
                    }
                    else{

                        and += "0";
                    }

                    i += 11;

                }
                else{

                    and += booleana.charAt(i);
                }
            }
            else{

                and += booleana.charAt(i);
            }
        }
    
        return and;
    }

    public static String OR(String booleana){

        String or = "";

        for(int i = 0; i < booleana.length(); i++){

            if(booleana.charAt(i) == 'o' &&
                booleana.charAt(i + 1) == 'r' &&
                (booleana.charAt(i + 3) == '1' ||
                booleana.charAt(i + 3) == '0') &&
                (booleana.charAt(i + 5) == '1' ||
                booleana.charAt(i + 5) == '0')){
                
                if(booleana.charAt(i + 6) == ')'){
                    
                    if(booleana.charAt(i + 3) == '1' ||
                        booleana.charAt(i + 5) == '1' ){
                            
                            or += "1";
                    }
                    else{

                        or += "0";
                    }

                    i += 6;

                }
                else if(booleana.charAt(i + 8) == ')'){
                    
                    if(booleana.charAt(i + 3) == '1' ||
                        booleana.charAt(i + 5) == '1' ||
                        booleana.charAt(i + 7) == '1'){
                            
                            or += "1";
                        }
                        else{

                            or += "0";
                        }

                        i += 8;

                }
                else if(booleana.charAt(i + 10) == ')'){
                    
                    if(booleana.charAt(i + 3) == '1' ||
                        booleana.charAt(i + 5) == '1' ||
                        booleana.charAt(i + 7) == '1' ||
                        booleana.charAt(i + 9) == '1'){
                            
                            or += "1"; 
                        }
                        else{

                            or += "0";
                        }

                        i += 10;

                }
            }
            else{
                or += booleana.charAt(i);
            }
        }
    
        return or;
    }

    private static String parenteses(String booleana){

        int operacao = 0;

        for(int i = 0; i < booleana.length(); i++){
            if(booleana.charAt(i) == ')'){
                operacao++;
            }
        }

        char[] funcao = new char[operacao];
    
        for(int i = 0; i < booleana.length() - 2; i++){
            if(booleana.charAt(i + 2) == 't'){
                funcao[--operacao] = 'n';
            }
            else if(booleana.charAt(i + 2) == 'd'){
                funcao[--operacao] = 'a';
            }
            else if(booleana.charAt(i + 1) == 'r'){
                funcao[--operacao] = 'o';
            }
        }

        for(int i = 0; i < funcao.length; i++){
            if(funcao[i] == 'n'){
                booleana = NOT(booleana); 
            }
            else if(funcao[i] == 'a'){
                booleana = AND(booleana);
            }
            else{
                booleana = OR(booleana);
            }
        }

        return booleana;
    }

    public static void main(String[] args){
        
        Scanner scanner = new Scanner(System.in);
        
        int qtdValores = scanner.nextInt();
        String booleana;

        int[] binarios = new int[3];

        while(qtdValores != 0){
            for(int i = 0; i < qtdValores; i++){
                binarios[i] = scanner.nextInt();
            }

            booleana = scanner.nextLine();
            booleana = trocaBinaria(binarios, booleana);
            booleana = parenteses(booleana);

            System.out.println(booleana);
        
            qtdValores = scanner.nextInt();
        }

        scanner.close();
    }
}
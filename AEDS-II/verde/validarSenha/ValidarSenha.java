//Senha valida inclui pelo menos uma letra maiuscula,
//uma letra minuscula, um número e um caractere especial
import java.util.*;

public class ValidarSenha{

    public static boolean validarSenha(String senha){
    
            boolean maiuscula = false;
            boolean numero = false;
            boolean especial = false;
            boolean minuscula = false;

            char[] caracteresEspeciais = {'!', '@', '#', '$', '%', '^', '&',
                '*', '(', ')', '_', '+', '-', '=', '<', '>', '?', '/'};

            for(int i = 0; i < senha.length(); i++){
                
                char c = senha.charAt(i);

                if(c >= 'A' && c <= 'Z'){
                    maiuscula = true;
                }
                else if(c >= 'a' && c <= 'z'){
                    minuscula = true;
                }
                else if(c >= '0' && c <= '9'){
                    numero = true;
                }
                else{
                    for(int j = 0; j < senha.length(); j++){
                        if(c == caracteresEspeciais[j]){
                            especial = true;
                            break;
                        }
                    }
                } 
            }        

        return maiuscula && minuscula && especial && numero;
    }

    public static void main(String[] args){
        
        Scanner scanner = new Scanner(System.in);
        
        while(scanner.hasNextLine()){

            String senha = scanner.nextLine();

            if(senha.length() == 3 && senha.charAt(0) == 'F' && senha.charAt(1) == 'I' && senha.charAt(2) == 'M'){
                break;
            }

            if(validarSenha(senha)){
                System.out.println("SIM");
            }
            else{
                System.out.println("NÃO");
            }
        }

        scanner.close();
    }
}
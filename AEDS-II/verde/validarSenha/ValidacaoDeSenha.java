import java.util.*;

public class ValidacaoDeSenha {

    public static boolean validarSenha(String senha){

        if(senha.length() < 8){
            return false;
        }

        boolean maiuscula = false;
        boolean numero = false;
        boolean especial = false;
        boolean minuscula = false;

        char[] caracteresEspeciais = {'!', '@', '#', '$', '%', '^', '&',
                '*', '(', ')', '_', '+', '-', '=', '<', '>', '?', '/', '{', '}'
        };

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
                for(int j = 0; j < caracteresEspeciais.length; j++){
                    if (c == caracteresEspeciais[j]) {
                        especial = true;
                        break;
                    }
                }
            }
        }

        return maiuscula && minuscula && especial && numero;
    }

    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);
        String senha = scanner.nextLine();

        while (!(senha.length() == 3 && senha.charAt(0) == 'F' && senha.charAt(1) == 'I' && senha.charAt(2) == 'M')){

            if (validarSenha(senha)) {
                System.out.println("SIM");
            } else {
                System.out.println("NAO");
            }

            senha = scanner.nextLine();
        }

        scanner.close();
    }
}

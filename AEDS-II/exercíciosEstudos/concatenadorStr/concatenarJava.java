import java.util.*;

public class concatenarJava{

    public static void apresentacao(){
        System.out.println("\nConcatenador");
    }


    public static void main(String[] args){

        apresentacao();
        Scanner scanner = new Scanner(System.in); 


    while(scanner.hasNextLine()){
        String entrada = scanner.nextLine();
        String[] partes = entrada.split(" ", 2);
        
        if (partes.length < 2) {
            System.out.println("Erro: Digite exatamente duas palavras separadas por espaço.");
        } 
        else{
            String resultado = partes[0] + partes[1];
            System.out.println(resultado);
        }
    }

        scanner.close();
    }
}
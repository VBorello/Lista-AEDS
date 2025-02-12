import java.util.*;

public class listaTelefonica {

    public static void apresentacao(){
        System.out.println("\nLista Telefônica econômica");
    }

    public static int calcularIguais(String atual, String anterior){

        int tamanho = 0;
        int i = 0;
        while(i < atual.length() && i < anterior.length() && atual.charAt(i) == anterior.charAt(i)){
            tamanho ++;
            i++;
        }
        
        return tamanho;
    }
    
    public static int calcularEconomia(int tam, String[] telefones){

        int economia = 0;

        for(int i = 1; i < tam; i++){
            economia += calcularIguais(telefones[i], telefones[i - 1]);
        }
    
        return economia;
    }


    public static void main(String[] args){

        apresentacao();
        Scanner scanner = new Scanner(System.in);

        while (scanner.hasNext()){
            int lista = scanner.nextInt();
            scanner.nextLine();
            
            String[] telefones = new String[lista];
        
            for(int i = 0; i < lista; i++){
                
                telefones[i] = scanner.nextLine();
            }
            
            int iguais = calcularEconomia(lista, telefones);
                
            System.out.println("\n" + iguais);

        }

        scanner.close();
    }        
}

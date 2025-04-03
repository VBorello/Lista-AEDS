import java.util.*;
import java.io.RandomAccessFile;

public class ArquivoJava{

    public static void main(String[] args){

        Scanner scanner = new Scanner(System.in);
        int num = scanner.nextInt();
        
        scanner.nextLine();

        try{
            RandomAccessFile arquivo = new RandomAccessFile("arq.txt", "rw");

            for(int i = 0; i < num; i++){
                double a = scanner.nextDouble();
                arquivo.writeDouble(a);
            }

            arquivo.close();

            arquivo = new RandomAccessFile("arq.txt", "r");
            long pos = arquivo.length();

            while(pos >= 0){
                pos -= 8;
                arquivo.seek(pos);
                Double numero = arquivo.readDouble();
                
                int inteiro = numero.intValue();

                if(num - inteiro == 0){
                    System.out.println(inteiro);
                }
                else{
                    System.out.println(numero);
                }
            }

            arquivo.close();
        }

        catch (Exception e) {}

        scanner.close();
    }
}
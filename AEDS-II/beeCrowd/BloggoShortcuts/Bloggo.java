import java.util.Scanner;

public class Bloggo{

    public static void main(String[] args){
        
        Scanner scanner = new Scanner(System.in);

        while(scanner.hasNextLine()){
            
            String line = scanner.nextLine();
            StringBuilder result = new StringBuilder();

            boolean italico = false;

            boolean bold = false;   

            for(char c : line.toCharArray()){
                
                if(c == '_'){
                    if(italico){
                        result.append("</i>");
                    } 
                    else{
                        result.append("<i>");
                    }

                    italico = !italico;

                } 
                
                else if(c == '*'){
                    if (bold){
                        result.append("</b>");
                    } 
                    else{
                        result.append("<b>");
                    }
                    bold = !bold;
                } 
                else{
                    result.append(c);
                }
            }

            System.out.println(result);
        }

        scanner.close();
    }
}
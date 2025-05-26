import java.util.*;

class Show{
    
    String title;
    String metadata;

    public Show(String title, String metadata){
    
        this.title = title;
        this.metadata = metadata;
    }

    @Override
    
    public String toString(){
        return title + " ## " + metadata;
    }
}

public class ListaDeAlocacaoSequencial{

    private Show[] lista;
    private int tamanho;

    public ListaDeAlocacaoSequencial(int capacidade){
        
        lista = new Show[capacidade];
        tamanho = 0;
    }

    public void inserirInicio(Show show){
        
        if(tamanho >= lista.length){
            throw new IllegalStateException("Lista cheia!");
        }
        
        for(int i = tamanho; i > 0; i--){
            lista[i] = lista[i - 1];
        }
        
        lista[0] = show;
        tamanho++;
    }

    public void inserir(Show show, int posicao){
        
        if(tamanho >= lista.length){
            throw new IllegalStateException("Lista cheia!");
        }
        if(posicao < 0 || posicao > tamanho){
            throw new IndexOutOfBoundsException("Posição inválida!");
        }
        
        for(int i = tamanho; i > posicao; i--){
            lista[i] = lista[i - 1];
        }
        
        lista[posicao] = show;
        tamanho++;
    }

    public void inserirFim(Show show){
        
        if(tamanho >= lista.length){
            throw new IllegalStateException("Lista cheia!");
        }
        
        lista[tamanho] = show;
        tamanho++;
    }

    public Show removerInicio(){
        
        if(tamanho == 0){
            throw new IllegalStateException("Lista vazia!");
        }
        Show removido = lista[0];
        
        for(int i = 0; i < tamanho - 1; i++){
            lista[i] = lista[i + 1];
        }
        
        lista[tamanho - 1] = null;
        tamanho--;
        
        return removido;
    }

    public Show remover(int posicao){
        
        if(tamanho == 0){
            throw new IllegalStateException("Lista vazia!");
        }
        
        if(posicao < 0 || posicao >= tamanho){
            throw new IndexOutOfBoundsException("Posição inválida!");
        }
        
        Show removido = lista[posicao];
        
        for(int i = posicao; i < tamanho - 1; i++){
            lista[i] = lista[i + 1];
        }
        
        lista[tamanho - 1] = null;
        tamanho--;
        
        return removido;
    }

    public Show removerFim(){
        
        if(tamanho == 0){
            throw new IllegalStateException("Lista vazia!");
        }
        
        Show removido = lista[tamanho - 1];
        
        lista[tamanho - 1] = null;
        tamanho--;
        
        return removido;
    }

    public void mostrar(){
        
        for(int i = 0; i < tamanho; i++){
            System.out.println("=> " + lista[i]);
        }
    }

    public static void main(String[] args){
        
        Scanner scanner = new Scanner(System.in);

        Map<String, String> metadados = carregarMetadados();

        ListaDeAlocacaoSequencial lista = new ListaDeAlocacaoSequencial(100);

        while(true){
            
            String linha = scanner.nextLine();
            
            if(linha.equals("FIM")){
                break;
            }
            
            String metadata = metadados.getOrDefault(linha, "Metadados não encontrados");
            lista.inserirFim(new Show(linha, metadata));
        }

        int n = scanner.nextInt();
        scanner.nextLine(); 

        for(int i = 0; i < n; i++){
            String comando = scanner.nextLine();

            if(comando.startsWith("II")){
                
                String titulo = comando.substring(3);
                String metadata = metadados.getOrDefault(titulo, "Metadados não encontrados");
                
                lista.inserirInicio(new Show(titulo, metadata));
            } 
            else if(comando.startsWith("IF")){
            
                String titulo = comando.substring(3);
                String metadata = metadados.getOrDefault(titulo, "Metadados não encontrados");
                lista.inserirFim(new Show(titulo, metadata));
            } 
            else if(comando.startsWith("I*")){
            
                String[] partes = comando.split(" ");
                int posicao = Integer.parseInt(partes[1]);
            
                String titulo = partes[2];
                String metadata = metadados.getOrDefault(titulo, "Metadados não encontrados");
                lista.inserir(new Show(titulo, metadata), posicao);
            }
            else if(comando.equals("RI")){
            
                Show removido = lista.removerInicio();
                System.out.println("(R) " + removido.title);
            } 
            else if(comando.equals("RF")){
            
                Show removido = lista.removerFim();
                System.out.println("(R) " + removido.title);
            }
            else if(comando.startsWith("R*")){
    
                int posicao = Integer.parseInt(comando.split(" ")[1]);
                Show removido = lista.remover(posicao);
                
                System.out.println("(R) " + removido.title);
            }
        }

        lista.mostrar();

        scanner.close();
    }
}
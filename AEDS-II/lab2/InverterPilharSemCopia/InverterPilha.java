import java.util.*;
//el último a entrare és tambien el último a saire!
public class InverterPilha{

    static class Celula{
        
        int valor;
        Celula proximo;

        Celula (int valor){
            this.valor = valor;
            this.proximo = null;
        }
    }

    static class Pilha{

        private Celula topo;

        public void empilhar(int valor){

            Celula nova = new Celula(valor);
            nova.proximo = topo;
            topo = nova;
        }
    

        public void imprimir(){
        
            Celula atual = topo;

            while (atual != null){
                System.out.print(atual.valor + " ");
                atual = atual.proximo;
            }
            System.out.println();
        }


        public void inverter() throws Exception{
            
            if(topo == null){
                throw new Exception("pilha vazia.");
            }
            
            Celula anterior = null;
            Celula atual = topo;
            Celula proximo;

            while (atual != null){
                
                proximo = atual.proximo; 
                atual.proximo = anterior; 
                anterior = atual; 
                atual = proximo;
            }

            topo = anterior;
        }
    }

    public static void main(String[] args){
        
        //Scanner scanner = new Scanner(System.in);
        //int tamanho = scanner.nextInt(); 
        
        Pilha pilha = new Pilha();

        pilha.empilhar(1);
        pilha.empilhar(2);
        pilha.empilhar(3);
        pilha.empilhar(4);
        pilha.empilhar(5);

        //for(int i = 0; i < tamanho; i++){
        //    int valor = scanner.nextInt();
        //    pilha.empilhar(valor);
        //}
        
        System.out.println("Pilha antes de inverter:");
        pilha.imprimir();

        try{
            pilha.inverter();
        }
        catch (Exception e){
            System.out.println("Erro: " + e.getMessage());
        }

        System.out.println("Pilha após inverter:");
        pilha.imprimir();

        //scanner.close();
    }
}
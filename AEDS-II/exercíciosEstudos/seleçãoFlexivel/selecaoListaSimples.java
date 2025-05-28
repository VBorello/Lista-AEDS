import java.util.*;

public class SelecaoListaSimples {

    static class Celula{

        int valor;
        Celula proximo;

        Celula(int valor){

            this.valor = valor;
            this.proximo = null;
        }
    }

    private Celula primeiro;
    private Celula ultimo;

    public SelecaoListaSimples(){

        primeiro = null;
        ultimo = null;
    }

    public void inserir(int valor){

        Celula nova = new Celula(valor);
        
        if(primeiro == null){
            primeiro = nova;
            ultimo = nova;
        }
        else {
            ultimo.proximo = nova;
            ultimo = nova;
        }
    }

    public void imprimir(){
    
        Celula atual = primeiro;
        while (atual != null) {
            System.out.print(atual.valor + " ");
            atual = atual.proximo;
        }
        System.out.println();
    }

    public void selecao(){
    
        for(Celula i = primeiro; i != null; i = i.proximo){
            
            Celula menor = i;
            
            for(Celula j = i.proximo; j != null; j = j.proximo){
                if (j.valor < menor.valor) {
                    menor = j;
                }
            }
            
            int temp = i.valor;
            i.valor = menor.valor;
            menor.valor = temp;
        }
    }

    public static void main(String[] args){
        
        SelecaoListaSimples lista = new SelecaoListaSimples();

        lista.inserir(64);
        lista.inserir(25);
        lista.inserir(12);
        lista.inserir(22);
        lista.inserir(11);

        System.out.println("Lista antes da ordenação:");
        lista.imprimir();

        lista.selecao();

        System.out.println("Lista após a ordenação:");
        lista.imprimir();
    }
}
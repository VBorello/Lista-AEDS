import java.util.*;

public class ListaSofreMeiose{

    static class Celula{
        
        int valor;
        Celula proximo;

        Celula(int valor){
        
            this.valor = valor;
            this.proximo = null;
        }
    }

    static class Lista{
        
        private Celula primeiro;
        private Celula ultimo;

        public Lista(){
            
            primeiro = null;
            ultimo = null;
        }

        public void inserir(int valor){
            
            Celula nova = new Celula(valor);
            
            if(primeiro == null){
                primeiro = nova;
                ultimo = nova;
            } 
            else{
                ultimo.proximo = nova;
                ultimo = nova;
            }
        }

        public void imprimir(){
            
            Celula atual = primeiro;
            while(atual != null){
            
                System.out.print(atual.valor + " ");
                atual = atual.proximo;
            }
            
            System.out.println();
        }

        public void meiose(){
            
            Celula atual = primeiro;
            Celula anterior = null;

            while(atual != null){

                int valorOriginal = atual.valor;
                int valorMeio = valorOriginal / 2;

                Celula nova1 = new Celula(valorMeio);
                Celula nova2 = new Celula(valorMeio);

                if(anterior == null){

                    primeiro = nova1;
                } 
                else{
                    anterior.proximo = nova1;
                }

                nova1.proximo = nova2;
                nova2.proximo = atual.proximo;

                anterior = nova2;
                atual = atual.proximo;
            }
        }
    }

    public static void main(String[] args){

        Lista lista = new Lista();

        lista.inserir(9);
        lista.inserir(8);
        lista.inserir(7);
        lista.inserir(6);
        lista.inserir(5);
        lista.inserir(4);
        lista.inserir(3);
        lista.inserir(2);
        lista.inserir(1);


        System.out.println("Lista antes da meiose:");
        lista.imprimir();

        lista.meiose();

        System.out.println("Lista após meiose:");
        lista.imprimir();
    }
}
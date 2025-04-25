public class PilhaParRemover{

    static class Celula{
        int valor;
        Celula proximo;

        Celula(int valor){
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

        public int desempilhar(){
            if (topo == null){
                throw new Exception("A pilha está vazia.");
            }
            int valor = topo.valor;
            topo = topo.proximo;
            return valor;
        }

        public boolean estaVazia(){
            return topo == null;
        }

        public void removerPares(){
            Celula atual = topo;
            Celula anterior = null;

            while (atual != null){
                if (atual.valor % 2 == 0){ 
                    if (anterior == null){
                        topo = atual.proximo;
                    }
                    else{
                        
                        anterior.proximo = atual.proximo;
                    }
                }
                else{
                    anterior = atual;
                }
                atual = atual.proximo;
            }
        }

        public void imprimir(){
            Celula atual = topo;
            while (atual != null){
                System.out.print(atual.valor + " ");
                atual = atual.proximo;
            }
            System.out.println();
        }
    }

    public static void main(String[] args){
        Pilha pilha = new Pilha();

        pilha.empilhar(1);
        pilha.empilhar(2);
        pilha.empilhar(3);
        pilha.empilhar(4);
        pilha.empilhar(5);

        System.out.println("Pilha antes de remover pares:");
        pilha.imprimir();

        pilha.removerPares();

        System.out.println("Pilha após remover pares:");
        pilha.imprimir();
    }
}
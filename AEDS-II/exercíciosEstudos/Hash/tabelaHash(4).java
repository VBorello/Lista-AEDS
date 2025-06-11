import java.util.LinkedList;

class No{

    int chave;
    No esquerda, direita;

    public No(int chave){
        this.chave = chave;
        this.esquerda = null;
        this.direita = null;
    }
}

class ArvoreBinaria{
    
    private No raiz;

    public void inserir(int chave){
    
        raiz = inserirRec(raiz, chave);
    }

    private No inserirRec(No raiz, int chave){
        
        if(raiz == null){
            raiz = new No(chave);

            return raiz;
        }
        if(chave < raiz.chave){
            
            raiz.esquerda = inserirRec(raiz.esquerda, chave);
        } 
        else if(chave > raiz.chave){
            raiz.direita = inserirRec(raiz.direita, chave);
        }
        
        return raiz;
    }

    public boolean pesquisar(int chave){
        
        return pesquisarRec(raiz, chave);
    }

    private boolean pesquisarRec(No raiz, int chave){
        
        if(raiz == null){
        
            return false;
        }
        if(raiz.chave == chave){
        
            return true;
        }
        if(chave < raiz.chave){
        
            return pesquisarRec(raiz.esquerda, chave);
        }
        
        return pesquisarRec(raiz.direita, chave);
    }

    public void mostrar(){
        mostrarRec(raiz);
    }

    private void mostrarRec(No raiz){
        
        if(raiz != null){
            mostrarRec(raiz.esquerda);
            System.out.print(raiz.chave + " ");
            mostrarRec(raiz.direita);
        }
    }

    public No remover(int chave){
        
        return removerRec(raiz, chave);
    }

    private No removerRec(No raiz, int chave){
        
        if(raiz == null){
        
            return raiz;
        }
        if(chave < raiz.chave){
            raiz.esquerda = removerRec(raiz.esquerda, chave);
        } 
        else if(chave > raiz.chave){
        
            raiz.direita = removerRec(raiz.direita, chave);
        } 
        else{
        
            if(raiz.esquerda == null){
        
                return raiz.direita;
            }
            else if(raiz.direita == null){
            
                return raiz.esquerda;
            }
            raiz.chave = minValor(raiz.direita);
            raiz.direita = removerRec(raiz.direita, raiz.chave);
        }

        return raiz;
    }

    private int minValor(No raiz){
        
        int minv = raiz.chave;
        
        while(raiz.esquerda != null){
            minv = raiz.esquerda.chave;
            raiz = raiz.esquerda;
        }
        
        return minv;
    }
}

class TabelaHash{

    private LinkedList<Integer>[] T1;
    private LinkedList<Integer> T2;
    private ArvoreBinaria T3;
    private int capacidade;

    public TabelaHash(int capacidade){

        this.capacidade = capacidade;
        T1 = new LinkedList[capacidade];
        
        for(int i = 0; i < capacidade; i++){
            T1[i] = new LinkedList<>();
        }
        T2 = new LinkedList<>();
        T3 = new ArvoreBinaria();
    }

    private int hash(int chave){

        return chave % capacidade;
    }

    private int rehash(int chave){

        return (chave / capacidade) % capacidade;
    }

    public void inserir(int chave){

        int indice = hash(chave);
        
        if(T1[indice].size() < 2){
            T1[indice].add(chave);
        } 
        else if(T2.size() < capacidade){
            T2.add(chave);
        } 
        else{
            T3.inserir(chave);
        }
    }

    public boolean pesquisar(int chave){
        
        int indice = hash(chave);
        
        if(T1[indice].contains(chave)){
        
            return true;
        } 
        else if(T2.contains(chave)){
            return true;
        } 
        else{
        
            return T3.pesquisar(chave);
        }
    }

    public void mostrar(){

        System.out.println("Tabela Hash T1:");
        
        for(int i = 0; i < capacidade; i++){
            System.out.print("Índice " + i + ": ");
        
            for(int chave : T1[i]){
                System.out.print(chave + " ");
            }
            System.out.println();
        }

        System.out.println("\nÁrea de Reserva T2:");
        
        for(int chave : T2){

            System.out.print(chave + " ");
        }
        
        System.out.println();

        System.out.println("\nÁrvore Binária T3:");
        T3.mostrar();
        
        System.out.println();
    }

    public void remover(int chave){

        int indice = hash(chave);
        
        if(T1[indice].remove((Integer) chave)){
        
            return;
        } 
        else if(T2.remove((Integer) chave)){
        
            return;
        } 
        else{
            T3.remover(chave);
        }
    }

    public static void main(String[] args){
        
        TabelaHash tabela = new TabelaHash(5);

        tabela.inserir(10);
        tabela.inserir(15);
        tabela.inserir(20);
        tabela.inserir(25);
        tabela.inserir(30);
        tabela.inserir(35);
        tabela.inserir(40);

        tabela.mostrar();

        System.out.println("\nPesquisando 25: " + tabela.pesquisar(25));
        System.out.println("Pesquisando 50: " + tabela.pesquisar(50));

        tabela.remover(25);
        System.out.println("\nApós remover 25:");
        tabela.mostrar();
    }
}

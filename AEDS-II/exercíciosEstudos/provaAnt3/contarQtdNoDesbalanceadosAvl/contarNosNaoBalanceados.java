class Arvore {
    
    private No raiz;

    public int contarNosNaoBalanceados(){
        //iniciar contagem dos nós não balanceados a partir da raiz
        return contarNosNaoBalanceados(raiz);
    }

    private int contarNosNaoBalanceados(No no){

        if(no == null){
            return 0;
        }

        //calcular altura do no
        int alturaEsq = altura(no.esq);
        int alturaDir = altura(no.dir);
        //calcular balanceamento(entre -1 e 1)
        int fatorBalanceamento = alturaEsq - alturaDir;

        int naoBalanceado;

        if(fatorBalanceamento < -1 || fatorBalanceamento > 1){
            naoBalanceado = 1;//desbalanceado
        }
        else{
            naoBalanceado = 0;//balanceado
        }

        //soma da quantidade de nós não balanceados esq e dir
        return naoBalanceado + contarNosNaoBalanceados(no.esq) + contarNosNaoBalanceados(no.dir);
    }

    //metodo para calcular a altura de uma subArvore
    private int altura(No no){

        if (no == null) {
            return 0;
        }

        //calcula altura da subArvore esq e dir
        int alturaEsq = altura(no.esq);
        int alturaDir = altura(no.dir)

        //retorna a maior altura entre o no da esquerda e o da direita + 1(o próprio nó)
        return 1 + Math.max(alturaEsq, alturaDir);
    }
}

class No{

    public int elemento;
    public No esq, dir;
}


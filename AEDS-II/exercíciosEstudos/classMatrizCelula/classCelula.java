import java.util.*;

public class classCelula {

    static class Celula{

        int valor;
        Celula direita, abaixo, esquerda, acima;

        Celula(int valor){

            this.valor = valor;
            this.direita = null;
            this.abaixo = null;
            this.esquerda = null;
            this.acima = null;
        }
    }

    static class Matriz{

        private Celula inicio;
        private int linha, coluna;

        public Matriz() {
            this(3, 3);
        }

        public Matriz(int l, int c) {
            this.linha = l;
            this.coluna = c;

        Celula linhaAnterior = null;

        for(int i = 0; i < l; i++){
            Celula colunaAnterior = null;
            Celula linhaAtual = null;

        for(int j = 0; j < c; j++){
            Celula nova = new Celula(0); 
            
            if(j == 0){
                if(i == 0){
                    inicio = nova; 
                } 
                else {
                    linhaAnterior.abaixo = nova;
                    nova.acima = linhaAnterior;
                    linhaAnterior = linhaAnterior.direita;
                }
            
                linhaAtual = nova;
            } 
            else{
                
                colunaAnterior.direita = nova;
                nova.esquerda = colunaAnterior;

                if(linhaAtual != null){

                    linhaAtual.abaixo = nova;
                    nova.acima = linhaAtual;
                    linhaAtual = linhaAtual.direita;
                }
            }

            colunaAnterior = nova; 
        }

        linhaAnterior = inicio;
        
        for(int k = 0; k < i; k++){
            linhaAnterior = linhaAnterior.abaixo;
        }
    }
}

        public void setValor(int l, int c, int valor){
            
            Celula atual = inicio;

            for(int i = 0; i < l; i++){
                atual = atual.abaixo;
            }

            for(int j = 0; j < c; j++){
                atual = atual.direita;
            }

            atual.valor = valor;
        }

        public void imprimir(){
        
            Celula linhaAtual = inicio;

            while(linhaAtual != null){
                Celula colunaAtual = linhaAtual;

                while(colunaAtual != null){
                    System.out.print(colunaAtual.valor + " ");
                    colunaAtual = colunaAtual.direita;
                }

                System.out.println();
                linhaAtual = linhaAtual.abaixo;
            }
        }
    }

    public static void main(String[] args) {
        
        Matriz matriz = new Matriz(3, 3);

        matriz.setValor(0, 0, 1);
        matriz.setValor(0, 1, 2);
        matriz.setValor(0, 2, 3);
        matriz.setValor(1, 0, 4);
        matriz.setValor(1, 1, 5);
        matriz.setValor(1, 2, 6);
        matriz.setValor(2, 0, 7);
        matriz.setValor(2, 1, 8);
        matriz.setValor(2, 2, 9);

        // Imprime a matriz
        System.out.println("Matriz:");
        matriz.imprimir();
    }
}
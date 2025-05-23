import java.util.*;

public class CalcularAlturaCadaSubArvore{

    static class No{
    
        int valor;
        No esquerda, direita;

        No(int valor){
    
            this.valor = valor;
            this.esquerda = null;
            this.direita = null;
        }
    }

    public static int calcularAltura(No raiz){
        
        if(raiz == null){
            return -1;
        }

        int alturaEsquerda = calcularAltura(raiz.esquerda);
        int alturaDireita = calcularAltura(raiz.direita);

        int alturaAtual = Math.max(alturaEsquerda, alturaDireita) + 1;

        System.out.println("Altura da subárvore com raiz " + raiz.valor + ": " + alturaAtual);

        return alturaAtual;
    }

    public static void main(String[] args){
        
        No raiz = new No(1);
        raiz.esquerda = new No(2);
        raiz.direita = new No(3);
        raiz.esquerda.esquerda = new No(4);
        raiz.esquerda.direita = new No(5);
        raiz.direita.direita = new No(6);
        raiz.direita.direita.esquerda = new No(7);

        System.out.println("Altura total da árvore: " + calcularAltura(raiz));
    }
}

/*
int altura(no i.elemento){

    int resp = 0;

    if(i != null){
        int hightEsquerda = altura(i.esq);
        int hightDireita = altura(i.dir);

        resp = i + (hihightEsquerda >hightDireita ?hightEsquerda :hightDireita);
    }

    return resp;
}
*/



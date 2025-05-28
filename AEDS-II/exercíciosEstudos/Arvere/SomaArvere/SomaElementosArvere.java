import java.util.*;

public class SomaElementosArvere {

    static class No{
        
        int value;
        No left, right;

        No(int value) {
            this.value = value;
            this.left = null;
            this.right = null;
        }
    }

    public static int somarElementos(No raiz){
    
        if (raiz == null){
            return 0;
        }

        return raiz.value + somarElementos(raiz.left) + somarElementos(raiz.right);
    }

    public static void main(String[] args){
        
        No raiz = new No(1);
        raiz.left = new No(2);
        raiz.right = new No(3);
        raiz.left.left = new No(4);
        raiz.left.right = new No(5);
        raiz.right.right = new No(6);
        raiz.right.right.left = new No(7);

        System.out.println("Soma dos elementos da árvore: " + somarElementos(raiz));
    }
}
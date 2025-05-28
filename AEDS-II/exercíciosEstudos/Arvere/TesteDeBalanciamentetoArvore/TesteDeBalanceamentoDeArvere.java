import java.util.*;

public class TesteDeBalanceamentoDeArvere {

    static class Node {
        
        int valor;
        Node esquerda, direita;

        Node(int valor) {
            this.valor = valor;
            this.esquerda = null;
            this.direita = null;
        }
    }

    public static int alturaEBalanceamento(Node root) {
        
        if (root == null) {
            return 0; 
        }

        int alturaEsquerda = alturaEBalanceamento(root.esquerda);
        int alturaDireita = alturaEBalanceamento(root.direita);

        if (Math.abs(alturaEsquerda - alturaDireita) > 1) {
            System.out.println("A subárvore com raiz " + root.valor + " NÃO está balanceada.");
        } else {
            System.out.println("A subárvore com raiz " + root.valor + " está balanceada.");
        }

        return Math.max(alturaEsquerda, alturaDireita) + 1;
    }

    public static void main(String[] args){
 
        Node root = new Node(1);
        root.esquerda = new Node(2);
        root.direita = new Node(3);
        root.esquerda.esquerda = new Node(4);
        root.esquerda.direita = new Node(5);
        root.direita.direita = new Node(6);
        root.direita.direita.esquerda = new Node(7);

        alturaEBalanceamento(root);
    }
}
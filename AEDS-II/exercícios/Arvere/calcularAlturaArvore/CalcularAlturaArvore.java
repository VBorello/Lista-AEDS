import java.util.*;

public class CalcularAlturaArvore {

    static class Node{
        
        int value;
        Node left, right;

        Node(int value){
    
            this.value = value;
            this.left = null;
            this.right = null;
        }
    }
    
    public static int calcularAltura(Node root) {
        
        if(root == null){
            return 0; 
        }

        int alturaEsquerda = calcularAltura(root.left);
        int alturaDireita = calcularAltura(root.right);

        return Math.max(alturaEsquerda, alturaDireita) + 1;
    }

    public static void main(String[] args){

        Node root = new Node(1);
        root.left = new Node(2);
        root.right = new Node(3);
        root.left.left = new Node(4);
        root.left.right = new Node(5);
        root.right.right = new Node(6);
        root.right.right.left = new Node(7);

        System.out.println("Altura da árvore: " + calcularAltura(root));
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



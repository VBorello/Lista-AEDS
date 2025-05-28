/*
faça o metodo No toAB(Celula p1, CelulaDupla p2) que recebe o nó cabeça de uma lista simples e o de outra
dupla. Em seguida, crie ima árvore binária contendo os elementos intercalados das duas listas e retorne
o endereço do nó raiz da árvore criada 
*/

import java.util.*;

public class NoToAB{

    public static void main(String[] args){


    }
}


class No {
    int valor;
    No esquerda, direita;

    No(int valor) {
        this.valor = valor;
        this.esquerda = null;
        this.direita = null;
    }
}

class Celula {
    int valor;
    Celula proximo;

    Celula(int valor) {
        this.valor = valor;
        this.proximo = null;
    }
}

class CelulaDupla {
    int valor;
    CelulaDupla proximo, anterior;

    CelulaDupla(int valor) {
        this.valor = valor;
        this.proximo = null;
        this.anterior = null;
    }
}

public class NoToAB {

    public static No toAB(Celula p1, CelulaDupla p2) {
        Queue<No> fila = new LinkedList<>();
        No raiz = null;

        while (p1 != null || p2 != null) {
            // Adiciona o elemento da lista simples na árvore
            if (p1 != null) {
                No novoNo = new No(p1.valor);
                if (raiz == null) {
                    raiz = novoNo;
                } else {
                    inserirNaArvore(raiz, novoNo);
                }
                fila.add(novoNo);
                p1 = p1.proximo;
            }

            // Adiciona o elemento da lista dupla na árvore
            if (p2 != null) {
                No novoNo = new No(p2.valor);
                if (raiz == null) {
                    raiz = novoNo;
                } else {
                    inserirNaArvore(raiz, novoNo);
                }
                fila.add(novoNo);
                p2 = p2.proximo;
            }
        }

        return raiz;
    }

/*
    public static No ToAB(Celula p1, Celula p2){

        No resp = null;
        p1 = p1.prox;
        p2 = p2.prox;

        while(p1 != null && p2 != null){
            resp = inserir(resp p1.elemento)
        }
        
    }
/*
    private static void inserirNaArvore(No raiz, No novoNo) {
        Queue<No> fila = new LinkedList<>();
        fila.add(raiz);

        while (!fila.isEmpty()) {
            No atual = fila.poll();

            if (atual.esquerda == null) {
                atual.esquerda = novoNo;
                return;
            } else {
                fila.add(atual.esquerda);
            }

            if (atual.direita == null) {
                atual.direita = novoNo;
                return;
            } else {
                fila.add(atual.direita);
            }
        }
    }

    public static void main(String[] args) {
        // Exemplo de lista simples
        Celula listaSimples = new Celula(1);
        listaSimples.proximo = new Celula(3);
        listaSimples.proximo.proximo = new Celula(5);

        // Exemplo de lista dupla
        CelulaDupla listaDupla = new CelulaDupla(2);
        listaDupla.proximo = new CelulaDupla(4);
        listaDupla.proximo.anterior = listaDupla;
        listaDupla.proximo.proximo = new CelulaDupla(6);
        listaDupla.proximo.proximo.anterior = listaDupla.proximo;

        // Criação da árvore binária
        No raiz = toAB(listaSimples, listaDupla);

        // Exibe a árvore em ordem (para ver o resultado)
        imprimirEmOrdem(raiz);
    }

    private static void imprimirEmOrdem(No raiz) {
        if (raiz != null) {
            imprimirEmOrdem(raiz.esquerda);
            System.out.print(raiz.valor + " ");
            imprimirEmOrdem(raiz.direita);
        }
    }
}
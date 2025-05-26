import java.util.Scanner;

class Matriz{
    
    private int[][] elementos;
    private int lin;
    private int col;

    public Matriz(int lin, int col){
        
        this.lin = lin;
        this.col = col;
        elementos = new int[lin][col];
    }

    public void ler(Scanner sc){
        
        for(int i = 0; i < lin; i++){
            for(int j = 0; j < col; j++){
                elementos[i][j] = sc.nextInt();
            }
        }
    }

    public void mostrarDiagonalPrincipal(){
        
        for(int i = 0; i < Math.min(lin, col); i++){
            System.out.print(elementos[i][i] + " ");
        }
        System.out.println();
    }

    public void mostrarDiagonalSecundaria(){
        
        for(int i = 0; i < Math.min(lin, col); i++){
            System.out.print(elementos[i][col - 1 - i] + " ");
        }
        System.out.println();
    }

    public Matriz soma(Matriz outra){
        
        if(this.lin != outra.lin || this.col != outra.col){
            throw new IllegalArgumentException("Dimensões incompatíveis para soma.");
        }

        Matriz resultado = new Matriz(lin, col);

        for(int i = 0; i < lin; i++){
            
            for(int j = 0; j < col; j++){
                resultado.elementos[i][j] = this.elementos[i][j] + outra.elementos[i][j];
            }
        }

        return resultado;
    }

    public Matriz multiplicacao(Matriz outra){
        
        if(this.col != outra.lin){
            throw new IllegalArgumentException("Dimensões incompatíveis para multiplicação.");
        }

        Matriz resultado = new Matriz(this.lin, outra.col);

        for(int i = 0; i < this.lin; i++){
            
            for(int j = 0; j < outra.col; j++){
            
                for(int k = 0; k < this.col; k++){
                    resultado.elementos[i][j] += this.elementos[i][k] * outra.elementos[k][j];
                }
            }
        }

        return resultado;
    }

    public void mostrar(){

        for(int i = 0; i < lin; i++){

            for(int j = 0; j < col; j++){
                System.out.print(elementos[i][j] + " ");
            }
            System.out.println();
        }
    }
}


public class Main{

    public static void main(String[] args){
        
        Scanner sc = new Scanner(System.in);

        int casos = sc.nextInt();

        for(int t = 0; t < casos; t++){
            
            int l1 = sc.nextInt();
            int c1 = sc.nextInt();
            
            Matriz m1 = new Matriz(l1, c1);
            m1.ler(sc);

            int l2 = sc.nextInt();
            int c2 = sc.nextInt();
            
            Matriz m2 = new Matriz(l2, c2);
            m2.ler(sc);

            m1.mostrarDiagonalPrincipal();
            m1.mostrarDiagonalSecundaria();

            if(l1 == l2 && c1 == c2){
                Matriz soma = m1.soma(m2);
                soma.mostrar();
            } 
            else{
                System.out.println("Dimenções incompativeis das matrizes para soma");
            }

            if(c1 == l2){
                Matriz mult = m1.multiplicacao(m2);
                mult.mostrar();
            }
            else{
                System.out.println("Dimenções incompativeis das matrizes para multiplicar");
            }
        }

        sc.close();
    }
}

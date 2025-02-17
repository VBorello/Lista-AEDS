import java.util.*;

public class BUSCABINARIAREC{

	public static boolean conferir(int[] array, int x){

		return buscaBinariaRec(array, x, 0, array.length - 1);
	}

	public static boolean buscaBinariaRec(int[] array, int x, int esquerda, int direita){

		if(esquerda > direita){
			return false;
		}
		
		int meio = esquerda + (direita - esquerda) / 2;
		
		if(array[meio] == x){
			return true;
		}
		else if(array[meio] < esquerda){
		
			return buscaBinariaRec(array, x, meio + 1, direita);
		}
		else{
			
			return buscaBinariaRec(array, x, esquerda, direita - 1);
		}
	}
	
	public static void main(String[] args){
	
		Scanner scanner = new Scanner(System.in);
		
		int[] array = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
		int x = scanner.nextInt();
	
		boolean resposta = conferir(array, x);
		System.out.println("O valor: " + x + "esta no array? " + resposta);
		
		System.out.print("\nArray:");
		for(int n : array){
		
			System.out.print(n + " ");
		}
		
			scanner.close();
	}
}

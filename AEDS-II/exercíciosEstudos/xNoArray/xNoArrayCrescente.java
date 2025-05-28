public class xNoArrayCrescente{


	public static boolean verificar(int[] array, int x){
	
		int esquerda = 0;
		int direita = array.length -1;

		while(esquerda <= direita){
			int meio = esquerda  + (direita - esquerda) / 2;
			
			if(array[meio] == x){
				return true;
			}
			else if(array[meio] < x){
				esquerda = meio + 1;
			}
			else{
				direita = meio - 1;
			}
		}		
		
		return false;
	}


	public static void main(String[] args){
	
		int[] array = {2,3,4,5,6,7};
		int x = 1;
		
	 	boolean resultado = verificar(array, x);
		System.out.println("O número " + x + " está no array? " + resultado);
		
		System.out.printf("\nArray: ");
		for(int i = 0; i < array.length; i++){
			System.out.print(array[i] + "");
		}
	}
}


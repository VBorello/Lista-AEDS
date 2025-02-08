public class maiorEmenorArray{

	public static int[] indentificarExtremos(int[] array){

		int maior = Integer.MIN_VALUE;
		int menor = Integer.MAX_VALUE;

		for(int valor : array){
			if(valor > maior){
				maior = valor;
			}
			if(valor < menor){
				menor = valor;
			}
		}

		return new int[]{maior, menor};
	}

	public static void main(String[] args){

		int[] array = {1,2,3,4,5,6,7,8,9,10};

		int[] extremos = indentificarExtremos(array);

		System.out.printf("\nMaior do array = %d, menor do array = %d.", extremos[0], extremos[1]);


		System.out.printf("\nArray: ");
		for(int i = 0; i < array.length; i++){
			System.out.print(array[i] + " ");
		}
	}
}

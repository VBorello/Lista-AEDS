public class xNoArray{

	public static boolean verificar(int[] array, int x){
		for(int elemento : array){
			if(elemento == x){
				return true;
			}
		}
		return false;
	}
	
	public static void main(String[] args){
		
		int[] array = {1,2,3,4,5};
		int x = 3;

		if(verificar(array, x)){
			System.out.println("\nO elemento " + x + " x está contido no array!");
		}
		else{
			System.out.println("\nO elemento " + x + " x não está no array!");
		}
	}
}

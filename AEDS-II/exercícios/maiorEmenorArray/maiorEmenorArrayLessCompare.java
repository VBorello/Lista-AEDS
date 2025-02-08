import java.util.*;

public class maiorEmenorArrayLessCompare{


	public static void main(String[] args){

		Scanner sc = new Scanner(System.in);
		int tam = 6;
		int []array = new int[tam];

		for(int i = 0; i < tam; i++){
			array[i] = sc.nextInt();
			sc.nextLine();
		}

		if(array.length == 0){
			System.out.println("O array ta vazio");
			return;
		}

		int menor = array[0];
		int maior = array[0];

		for(int i = 1; i < array.length - 1; i += 2){

			int minAtual;
			int maxAtual;

			if(array[i] < array[i + 1]){
				minAtual =  array[i];
				maxAtual =  array[i + 1];
			}
			else{
				minAtual = array[i + 1];
				maxAtual = array[i];
			}

			if(minAtual < menor) menor = minAtual;
			if(maxAtual > maior) maior = maxAtual;
		}

		if(array.length % 2 != 0){
			int ultimoElemento;

			ultimoElemento = array[array.length - 1];
			if(ultimoElemento > menor) menor = ultimoElemento;
			if(ultimoElemento < maior) maior = ultimoElemento;
		}

		System.out.println("Menor elemento: " + menor);
		System.out.println("Maior elemento: " + maior);
	}
}

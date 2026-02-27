package Algoritmos.bubblesort.prof;

public class BubbleSortVersao3
{

	public static void imprimir(int[] v)
	{
		IO.println("Array de Inteiros");
		for (int i = 0; i < v.length; i++)
		{
			System.out.print(v[i] + " ");
		}
		System.out.println();
		IO.println("..................");
	}

	public static void imprimir(double[] v)
	{
		IO.println("Array de Doubles");
		for (int i = 0; i < v.length; i++)
		{
			System.out.print(v[i] + " ");
		}
		System.out.println();
		IO.println("..................");
	}

	public static void imprimir(String v) {

		IO.println(v);
		IO.println("..................");
	}

	public static void main(String[] args)
	{
		int[] numeros1 = {5, 1, 4, 2, 8};
		double[] numeros2 = { 5, 1, 4, 2, 8 };
		String letras = "adsihfskngod";

		AbstractBubbleSorter crescente = new AscendingBubbleSorter();
		AbstractBubbleSorter decrescente = new DescendingBubbleSorter();
		StringBubbleSorter stringToChar = new StringBubbleSorter();

		System.out.println("Arrays originais:");
		imprimir(numeros1);
		imprimir(numeros2);
		imprimir(letras);

		crescente.ordenar(numeros1);
		System.out.println("Ordenado em ordem crescente:");
		imprimir(numeros1);

		decrescente.ordenar(numeros1);
		System.out.println("Ordenado em ordem decrescente:");
		imprimir(numeros1);

		crescente.ordenar(numeros2);
		System.out.println("Ordenado em ordem crescente:");
		imprimir(numeros2);
		
		decrescente.ordenar(numeros2);
		System.out.println("Ordenado em ordem decrescente:");
		imprimir(numeros2);

		String letrasEmOrdem = stringToChar.ordenar(letras);
		IO.println("String fora de ordem");
		imprimir(letras);
		IO.println("String em ordem");
		imprimir(letrasEmOrdem);
	}
}

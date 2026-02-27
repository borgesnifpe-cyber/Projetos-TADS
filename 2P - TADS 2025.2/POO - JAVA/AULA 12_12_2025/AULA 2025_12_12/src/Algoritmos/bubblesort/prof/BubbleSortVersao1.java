package Algoritmos.bubblesort.prof;

public class BubbleSortVersao1
{
	public static void bubbleSort(int[] v)
	{
		int n = v.length;
		boolean trocou;

		do
		{
			//assume que terminou e tenta
			// provar o contrário.
			trocou = false;
			
			for (int i = 0; i < n - 1; i++)
			{
				if (v[i] > v[i + 1]) {
					int aux = v[i];
					v[i] = v[i + 1];
					v[i + 1] = aux;
					trocou = true;
				}
			}
			n--; // otimização: o maior elemento já está no final
		} while (trocou);
	}

	public static void imprimir(int[] v)
	{
		for (int i = 0; i < v.length; i++)
		{
			System.out.print(v[i] + " ");
		}
		
		System.out.println();
	}

	public static void main(String[] args)
	{
		int[] numeros = { 5, 1, 4, 2, 8 };

		System.out.println("Antes da ordenação:");
		imprimir(numeros);

		bubbleSort(numeros);

		System.out.println("Depois da ordenação:");
		imprimir(numeros);
	}
}

package Algoritmos.bubblesort.prof;

public class BubbleSortVersao2
{

    public static void imprimir(int[] v)
    {
        for (int i = 0; i < v.length; i++)
        {
            System.out.print(v[i] + " ");
        }
        System.out.println();
    }

    public static void main(String[] args) {
        int[] numeros = { 5, 1, 4, 2, 8 };

        System.out.println("Antes da ordenação:");
        imprimir(numeros);

        BubbleSorter sorter = new BubbleSorter();
        sorter.ordenar(numeros);

        System.out.println("Depois da ordenação:");
        imprimir(numeros);
    }
}


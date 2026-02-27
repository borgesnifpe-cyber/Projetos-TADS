package Algoritmos.bubblesort.prof;

public class BubbleSorter
{
    public void ordenar(int[] v)
    {
        int n = v.length;
        boolean trocou;

        do {
            trocou = false;
            for (int i = 0; i < n - 1; i++) {
                if (v[i] > v[i + 1]) {
                    int aux = v[i];
                    v[i] = v[i + 1];
                    v[i + 1] = aux;
                    trocou = true;
                }
            }
            n--;
        } while (trocou);
    }
}


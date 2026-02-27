package Algoritmos.bubblesort.prof;

import java.util.Arrays;

public abstract class AbstractBubbleSorter {

    public final void ordenar(int[] v) 
    {
        int n = v.length;
        boolean trocou;

        do {
            trocou = false;
            for (int i = 0; i < n - 1; i++) {
                if (precisaTrocar(v[i], v[i + 1])) {
                    int aux = v[i];
                    v[i] = v[i + 1];
                    v[i + 1] = aux;
                    trocou = true;
                }
            }
            n--;
        } while (trocou);
    }

    public final void ordenar(double[] v)
    {
        double n = v.length;
        boolean trocou;

        do {
            trocou = false;
            for (int i = 0; i < n - 1; i++) {
                if (precisaTrocar(v[i], v[i + 1])) {
                    double aux = v[i];
                    v[i] = v[i + 1];
                    v[i + 1] = aux;
                    trocou = true;
                }
            }
            n--;
        } while (trocou);
    }

    public final String ordenar(String v)
    {
        char[] a = v.toCharArray();
        Arrays.sort(a);
        String b = Arrays.toString(a).replace("[","").replace("]","").replace(", ","");
        return b;
    }

    protected abstract boolean precisaTrocar(int a, int b);
    protected abstract boolean precisaTrocar(double a,double b);
}


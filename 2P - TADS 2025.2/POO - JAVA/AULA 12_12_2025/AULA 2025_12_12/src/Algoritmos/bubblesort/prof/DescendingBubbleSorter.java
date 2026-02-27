package Algoritmos.bubblesort.prof;

public class DescendingBubbleSorter
   extends AbstractBubbleSorter
{

    @Override
    protected boolean precisaTrocar(int a, int b)
    {
        return a < b; // ordenação decrescente
    }
    protected boolean precisaTrocar(double a, double b)
    {
        return a < b; // ordenação decrescente
    }
}


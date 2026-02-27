package Algoritmos.bubblesort.prof;

public class AscendingBubbleSorter 
  extends AbstractBubbleSorter
{
    @Override
    protected boolean precisaTrocar(int a, int b)
    {
        return a > b; // ordenação crescente
    }

    protected boolean precisaTrocar(double a, double b)
    {
        return a > b;
    }
}
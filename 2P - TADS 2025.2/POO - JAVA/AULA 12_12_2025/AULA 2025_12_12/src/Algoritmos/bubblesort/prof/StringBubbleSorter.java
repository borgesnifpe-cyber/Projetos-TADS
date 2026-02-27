package Algoritmos.bubblesort.prof;

public class StringBubbleSorter extends AbstractBubbleSorter{
    protected boolean precisaTrocar(int a, int b) {
        return a > b;
    };
    protected boolean precisaTrocar(double a,double b) {
        return a < b;
    }
}

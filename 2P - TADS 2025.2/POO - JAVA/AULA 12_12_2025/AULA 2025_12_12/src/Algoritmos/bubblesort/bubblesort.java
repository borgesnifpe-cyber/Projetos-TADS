package Algoritmos.bubblesort;

public class bubblesort {
    void main(String[] args) {
        int[] numeros = {5,1,4,2,8,3,9,15,11,0,7};
        IO.println("Antes da ordenação: ");
        imprimir(numeros);
        bubbleSort(numeros);
        IO.println("Após a ordenação: ");
        imprimir(numeros);
    }

    void imprimir(int[] v) {
        for (int i=0;i<v.length;i++) {
            IO.print(" "+v[i]);
        }
        IO.println("");
    }

    void bubbleSort(int[] v) {
        int aux;
        for(int i = 0; i<v.length; i++){
            for(int j = 0; j< v.length-1; j++){
                if(v[j] > v[j + 1]){
                    aux = v[j];
                    v[j] = v[j+1];
                    v[j+1] = aux;
                }
            }
        }
    }
}
package Ferramentas;

import java.util.Scanner;

public class Calculadora {
    int a,b;

    public Calculadora() {

    }

    public static int somar(int a, int b){
        return a+b;
    }

    public static int subtrair(int a,int b){
        return a-b;
    }

    public static int multiplicar(int a,int b){
        return a*b;
    }

    public static double dividir (int a, int b) {
        if (b==0) {
           System.out.println("Divisor nulo, inserir valor positivo.");
        }
        return (double) a/ (double) b;
    }
}

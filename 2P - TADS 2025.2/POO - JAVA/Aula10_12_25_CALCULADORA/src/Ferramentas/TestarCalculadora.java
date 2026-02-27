package Ferramentas;

import java.util.Scanner;

public class TestarCalculadora {

    public static void main(String []args){

        Scanner input = new Scanner(System.in);
        System.out.println("Insira um valo para a: ");
        int a = input.nextInt();
        int b = input.nextInt();

        System.out.println("A soma de a e b é: "+Calculadora.somar(a,b));
        System.out.println("A subtração de a e b é: "+Calculadora.subtrair(a,b));
        System.out.println("A multiplicação de a e b é: "+Calculadora.multiplicar(a,b));
        System.out.println("A divisão de a e b é: "+Calculadora.dividir(a,b));
    }
}

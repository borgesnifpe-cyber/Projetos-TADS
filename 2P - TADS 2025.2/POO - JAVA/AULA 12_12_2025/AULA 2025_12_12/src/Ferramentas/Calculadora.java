package Ferramentas;
import java.util.Scanner;

public class Calculadora {

        static void main(String[] args){
            Calculadora calc = new Calculadora();
            calc.testadorCalculadora();
        }

        public Calculadora() {}

        public static int somar(int a, int b){return a+b;}

        public static int subtrair(int a,int b){return a-b;}

        public static int multiplicar(int a,int b){return a*b;}

        public static double dividir (int a, int b) {
            if (b==0) {
                IO.println("Divisor nulo, inserir valor positivo.");
            }
            return (double) a/ (double) b;
        }

        public void testadorCalculadora(){
            Scanner input = new Scanner(System.in);
            IO.println("Insira o primeiro valor: ");
            int a = input.nextInt();
            IO.println("Insira o segundo valor: ");
            int b = input.nextInt();
            seletorOperacao(a,b,input);
        }

        public void seletorOperacao(int a,int b,Scanner algumScanner) {
            int confirm;
            do {
                IO.println("Insira a opção de operação desejada:");
                IO.println("1- Somar; 2- Subtrair; 3- Multiplicar; 4-Dividir");
                int option = algumScanner.nextInt();
                switch (option) {
                    case 1:
                        IO.println("A soma de a e b é: " + Calculadora.somar(a, b));
                        break;
                    case 2:
                        IO.println("A subtração de a e b é: " + Calculadora.subtrair(a, b));
                        break;
                    case 3:
                        IO.println("A multiplicação de a e b é: " + Calculadora.multiplicar(a, b));
                        break;
                    case 4:
                        IO.println("A divisão de a e b é: " + Calculadora.dividir(a, b));
                        break;
                }
                IO.println("Deseja realizar outra operação? Digite 1 para Sim ou 2 para Não.");
                confirm = algumScanner.nextInt();
            } while (confirm == 1);
            IO.println("Calculadora encerrando!");
        }
}

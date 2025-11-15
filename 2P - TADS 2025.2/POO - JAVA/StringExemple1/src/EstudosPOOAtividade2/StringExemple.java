package EstudosPOOAtividade2;

import java.util.Scanner;

public class StringExemple {
    public static void main (String[] args) {
        //Instanciando objetos string de diferentes formas:
        String str1 = "Olá, Mundo!";
        String str2 = new String ("Java é muito divertido!");
        String str3 = new String (); //String vazia
        String str4 = new String ("Aprender java pelos fundamentos é excelente.");

        //Concatenando Strings
        String fraseCompleta = str1+""+str2;
        IO.println(fraseCompleta);

        //Usando métodos da classe String
        IO.println("Tamanho de str1:"+str1.length());
        IO.println("Caractere na posição 3 de str2:"+str2.charAt(3));
        IO.println("str1 em letras maiúsculas: "+str1.toUpperCase());
        IO.println("str2 em minúsculas: "+str2.toLowerCase());

        //comparando strings
        if (str1.equals(str2)) {
            IO.println("str1 e str2 têm conteúdos iguais");
        } else IO.println("str1 e str2 são diferentes.");

        Scanner sc = new Scanner(System.in);
        IO.println("Insira uma frase para contar os caracteres: ");
        String frase = sc.nextLine();
        int cont = 0;
        for (int i=0;i<frase.length();i++) {
            cont=cont+1;
        }
        String fraseSaida = String.format("Sua frase tem %d letras.",cont);
        IO.println(fraseSaida);

        StringBuilder fraseInvertida = new StringBuilder();
        int position = 0;
        for (int i=(frase.length()-1);i>=0;i--) {
             char letra = frase.charAt(i);
             fraseInvertida.insert(position,letra);
             position++;
        }
        IO.println("A frase invertida é: "+fraseInvertida);
    }
}

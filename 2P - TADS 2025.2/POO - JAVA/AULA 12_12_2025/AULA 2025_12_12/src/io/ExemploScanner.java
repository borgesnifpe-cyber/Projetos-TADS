package io;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.InputStream;
import java.util.Scanner;

public class ExemploScanner 
{

	public static void main(String[] args) 
			throws FileNotFoundException 
	{
		ExemploScanner testadorScanner;
		testadorScanner = new ExemploScanner();
		
		testadorScanner.testarLeitura();
	}
	
	/**
	 * Exemplo de método privado, com
	 * o javadoc.
	 * 
	 * @throws FileNotFoundException
	 */
	private void testarLeitura() 
			throws FileNotFoundException
	{
		Scanner leitor = new Scanner(System.in);
		InputStream entrada = new FileInputStream("text.txt");
		leitor = new Scanner(entrada);
		
		while (leitor.hasNext())
		{
			String texto = leitor.nextLine();
			System.out.println("Li o seguinte texto: " + texto);
		}
		
	}

}

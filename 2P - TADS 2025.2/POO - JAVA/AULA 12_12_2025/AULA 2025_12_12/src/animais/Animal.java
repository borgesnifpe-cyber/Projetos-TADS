package animais;

import java.util.Iterator;

// public class Animal
/**
 * A classe Animal representa um ancestral
 * comum de todos os animais.
 * 
 * Os mamíferos, aves e peixes 
 * herdam diretamente dela.
 * 
 * @author Paulo Abadie
 * @version 1.2
 */
public abstract class Animal
{
	private String nome = "João";
	
	public Animal()
	{
		// aqui o compilador vai chamar,
		// automaticamente, o construtor do pai.
		super();
		System.out.println("Executei o construtor de Animal");
		System.out.println("Este construtor só roda");
		System.out.println("depois que o construtor do pai termina.");
	}
	
//	public void mover()
//	{
//		System.out.println("Animal se moveu.");
//	}
	
	/**
	 * Faz o animal se mover, de alguma forma que
	 * é específica do animal.
	 * Após o mover, ele irá para uma 
	 * unidade de distância da posição original.
	 */
	public abstract void mover();
	
	/**
	 * Faz o animal realizar alguma ação que
	 * é típica da sua natureza.
	 */
	public void agir()
	{
		System.out.println("Animal agiu.");
	}
	
	/**
	 * Faz o animal fugir, dada uma certa
	 * distância.
	 * 
	 * @param distancia espaço a ser percorrido.
	 */
	public void fugir(int distancia)
	{
		for (int i = 0; i < distancia; i++)
		{
			mover();
		}
	}
	
	public String toString()
	{
		String texto = "Objeto da classe Animal";
		texto = texto + " Nome -> " + nome;
		return texto;
	}
}

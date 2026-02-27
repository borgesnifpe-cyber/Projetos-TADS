package animais;

import java.util.Iterator;

//public class Animal
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
	
	public void agir()
	{
		System.out.println("Animal agiu.");
	}
	
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

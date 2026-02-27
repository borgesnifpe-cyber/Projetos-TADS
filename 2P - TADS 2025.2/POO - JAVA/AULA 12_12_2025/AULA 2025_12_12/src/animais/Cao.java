package animais;

//public class Cao extends Animal
public class Cao extends Mamifero
{
	public Cao()
	{
		// aqui o compilador chama super();
		System.out.println("Executei o construtor de cão");
	}
	
	public void mover()
	{
		System.out.println("Cão andou.");
	}
	
	/**
	 * Exemplo de método que sobrescreve um
	 * código herdado do pai.
	 * 
	 * Aqui eu posso chamar métodos específicos
	 * desta classe.
	 * 
	 * Esta técnica permite grudar códigos
	 * particular em métodos gerais.
	 */
	public void agir()
	{
		System.out.println("Cão agiu.");
		mover();
		latir();
	}

	// coisas particulares que só o cão faz.
	public void latir()
	{
		System.out.println("Cão latiu.");
	}
	
	public String toString()
	{
		String texto = super.toString();
//		texto = texto + 
		texto = "Objeto da classe Cao.";
		//texto = texto + " Nome -> " + nome;
		return texto;
	}


}

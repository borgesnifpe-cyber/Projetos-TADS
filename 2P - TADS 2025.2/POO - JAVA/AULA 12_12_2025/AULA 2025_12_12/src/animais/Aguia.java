package animais;

//public class Aguia extends Animal
public class Aguia extends Ave
{
	String teste = "Testando depurador.";
	public void mover()
	{
		//System.out.println("Águia voou.");
		voar();
		pousar();
	}
	
	public void voar()
	{
		System.out.println("Águia voou.");
	}
	
	public void pousar()
	{
		System.out.println("Águia pousou.");
	}
	// coisas particulares que só a Águia faz.
	public void botarOvo()
	{
		System.out.println("Águia botou um ovo.");
	}


}

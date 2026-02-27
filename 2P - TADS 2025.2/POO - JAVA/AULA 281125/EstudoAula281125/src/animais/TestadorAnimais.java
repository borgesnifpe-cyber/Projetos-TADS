package animais;

public class TestadorAnimais
{

	public static void main(String[] args)
	{
		TestadorAnimais testador;
		testador = new TestadorAnimais();
		
		// dispara o teste dos objetos
		testador.testarAnimais();

	}

	private void testarAnimais()
	{
			Cao rex = new Cao();
			Aguia julia = new Aguia();
            Galinha rafinha = new Galinha();
			
//			rex.mover();
//			julia.mover();
			
//			testarCao(rex);
			//testarCao(julia);
			
//			testarAguia(rex);
//			testarAguia(julia);
			
			//testarAnimal(rex);
			//testarAnimal(julia);
			
			//  Aguia minhaAguia = new Aguia();
			
			// testarAnimal(minhaAguia);
			//testarMamifero(minhaAguia);
			// testarAve(minhaAguia);

            testarAve(rafinha);
	}

	public void testarCao(Cao algumCao)
	{
		System.out.println("Testando o cão.");
		//algumCao.mover();
		//testarAnimal(algumCao);
		testarMamifero(algumCao);
		
		algumCao.latir();
		System.out.println();
	}
	
	public void testarAguia(Aguia algumaAguia)
	{
		System.out.println("Testando a águia.");
		//algumaAguia.mover();
		testarAnimal(algumaAguia);
		
		algumaAguia.botarOvo();
		System.out.println("");
	}

    public void testarGalinha(Galinha algumaGalinha) {
        System.out.println("Testando a Galinha.");
        algumaGalinha.botarOvo();
        algumaGalinha.voar();
        algumaGalinha.fugir(10);
    }
	
	public void testarAve(Ave algumaAve)
	{
		System.out.println("Testando a ave.");
		
		// testa o miolo (parte herdada) do Animal,
		// mais métodos sobrescritos
		testarAnimal(algumaAve);
		
		// testa a parte específica do objeto.
		algumaAve.voar();
        algumaAve.agir();
        algumaAve.fugir(45);

        testarGalinha((Galinha) algumaAve);

	}
	
	public void testarMamifero(Mamifero algumMamifero)
	{
		System.out.println("Testando o mamífero.");
		
		// testa o miolo (parte herdada) do mamífero,
		// mais métodos sobrescritos
		testarAnimal(algumMamifero);
		
		// testa a parte específica do objeto.
		algumMamifero.mamar();
	}
	
	public void testarAnimal(Animal algumAnimal)
	{
		System.out.println("Testando o animal (não sei o tipo exato dele).");
		int valor;
		valor = 42;
		
		algumAnimal.mover();
		algumAnimal.agir();
		
		algumAnimal.fugir(3);
		System.out.println();
		// aqui não posso chamar DIRETAMENTE métodos particulares.
		//algumAnimal.
	}
	
}

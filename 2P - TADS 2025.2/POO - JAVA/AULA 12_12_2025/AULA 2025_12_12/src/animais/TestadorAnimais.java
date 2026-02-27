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

    /**
     * Método de teste geral do sistema
     */
	private void testarAnimais()
	{
			Cao rex = new Cao();
			Aguia julia = new Aguia();
			
//			rex.mover();
//			julia.mover();
			
//			testarCao(rex);
			//testarCao(julia);
			
//			testarAguia(rex);
//			testarAguia(julia);
			
			testarAnimal(rex);
			testarAnimal(julia);
			
			Aguia minhaAguia = new Aguia();
			
			testarAnimal(minhaAguia);
			//testarMamifero(minhaAguia);
			testarAve(minhaAguia);
	}

    /**
     * Método para testar um Cão e
     * também para testar a implementação
     * da herança da classe mamífero ou animal
     * @param algumCao
     */

	public void testarCao(Cao algumCao)
	{
		System.out.println("Testando o cão.");
		//algumCao.mover();
		//testarAnimal(algumCao);
		testarMamifero(algumCao);
		
		algumCao.latir();
		System.out.println();
	}

    /**
     * Método para testar uma Águia e
     * também para testar a implementação
     * da herança da classe Ave ou Animal
     * @param algumaAguia
     */
	public void testarAguia(Aguia algumaAguia)
	{
		System.out.println("Testando a águia.");
		//algumaAguia.mover();
		testarAnimal(algumaAguia);
		
		algumaAguia.botarOvo();
		System.out.println("");
	}

    /**
     * Método para testar uma Ave genérica e
     * também para testar a implementação
     * da herança da classe Animal com as sobreposições
     * plausíveis para a especificidade da classe Ave
     * @param algumaAve
     */
    public void testarAve(Ave algumaAve)
	{
		System.out.println("Testando a ave.");
		
		// testa o miolo (parte herdada) do Animal,
		// mais métodos sobrescritos
		testarAnimal(algumaAve);
		
		// testa a parte específica do objeto.
		algumaAve.voar();
	}

    /**
     * Método para testar um mamífero genérico e
     * também para testar a implementação
     * da herança da classe Animal
     * @param algumMamifero
     */
    public void testarMamifero(Mamifero algumMamifero)
	{
		System.out.println("Testando o mamífero.");
		
		// testa o miolo (parte herdada) do mamífero,
		// mais métodos sobrescritos
		testarAnimal(algumMamifero);
		
		// testa a parte específica do objeto.
		algumMamifero.mamar();
	}
    /**
     * Método para testar um Animal genérico
     * @param algumAnimal
     */
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

	public void testarVoador(Voador algumVoador) {
		algumVoador.voar();
	}
	
	
	
	
}

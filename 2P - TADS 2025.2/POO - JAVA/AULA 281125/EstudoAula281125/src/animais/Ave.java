package animais;

public abstract class Ave extends Animal
{
	public boolean podeVoar()
	{
		System.out.println("Ave pode voar.");
		return true;
	}
	
	/**
	 * O programador pode chamar o método voar(),
	 * somente se o método "podeVoar()" retornar
	 * true.
	 */
	public void voar()
	{
		if(podeVoar())
		{
			System.out.println("Ave voou.");
		}
		else
		{
			System.out.println("Esta ave não voa.");
		}
	}
    public void mover() {
        System.out.println("Ave moveu-se 300m");
    }

    public void agir() {
        System.out.println("Ave olha ao redor.");
    }
	

}

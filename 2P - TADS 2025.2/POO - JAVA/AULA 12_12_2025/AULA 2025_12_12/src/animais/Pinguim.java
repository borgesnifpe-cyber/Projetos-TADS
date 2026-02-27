package animais;

//public class Pinguim extends Animal
public class Pinguim extends Ave
{
    public void mover(){
        System.out.println("Pinguim se moveu 1m");
    }
	public boolean podeVoar()
	{
		System.out.println("Pinguim não pode voar.");
		
		return false;
	}

}

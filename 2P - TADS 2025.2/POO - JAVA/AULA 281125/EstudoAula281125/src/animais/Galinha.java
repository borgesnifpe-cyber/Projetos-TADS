package animais;

public class Galinha extends Ave
{
    public Galinha()
    {
        // aqui o compilador chama super();
        System.out.println("Executei o construtor da Galinha");
    }

    public boolean podeVoar() { return false; }
	public void botarOvo()
	{
		System.out.println("Galinha botou ovo.");
	}

    public void mover() {
        System.out.println("Galinha moveu-se 5m");
    }

    public void fugir (int distancia) {
        String ninguemSai = "A galinha está paralisada!";
        String formato = String.format("A galinha tentou fugir %d metros, mas não conseguiu. %s",distancia,ninguemSai);
        System.out.println(formato);
    }

    public void agir() {
        botarOvo();
    }

}

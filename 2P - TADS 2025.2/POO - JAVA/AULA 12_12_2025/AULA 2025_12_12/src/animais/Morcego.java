package animais;

public class Morcego extends Mamifero implements Voador{
    @Override
    public void voar() {
        IO.println("Morcego voou 300m");
    }

    @Override
    public boolean podeVoar() {
        return true;
    }

    public void sonar() {
        IO.println("Morcego está se localizando durante voo");
    }
}

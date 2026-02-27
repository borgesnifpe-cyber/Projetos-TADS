package BancoTech;

public class Conta {
    int idConta;
    double saldo;
    String senha;

    private int geradorId() {
        int idGerado = idConta++;
        return idGerado;
    }

    public Conta() {
        int idConta=1;
        double saldo=0;
        String senha="12345";
    }

    public void main (String[] args) {
        Conta novaConta = new Conta();
        for (int i=0;i<5;i++){
            novaConta.geradorId();
            IO.println("O ID atual é:"+novaConta.idConta);
        }
        IO.println("O último ID é:"+novaConta.idConta);
    }
}

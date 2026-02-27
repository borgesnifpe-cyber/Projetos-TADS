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
        String senha=12345;
    }

    public void main (String[] args) {
        Conta novaConta = new Conta();
        novaConta.geradorId();
    }


}

package Soparia;

public record Pedido(String nomePrato, double valor) {
    public String getValorFormatado(){
        String texto;
        return texto = String.format("R$ %.2f",valor);
    }
}

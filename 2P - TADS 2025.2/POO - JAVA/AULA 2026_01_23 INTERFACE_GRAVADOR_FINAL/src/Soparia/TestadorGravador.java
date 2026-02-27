package Soparia;

import java.util.ArrayList;

public class TestadorGravador {
    public static void main(String[] args) {

        gravadorNaTela meuGravador = new gravadorNaTela();
        ArrayList<Pedido> pedidosTeste = new ArrayList<>();
        int nPedidos = 6;
        for (int i = 1; i <= nPedidos; i++) {
            Pedido meuPedido = new Pedido("Prato "+i,i+5*1.5);
            pedidosTeste.add(meuPedido);
        }
        meuGravador.iniciarGravacao();
        meuGravador.GravarListaPedido(pedidosTeste);
        meuGravador.confirmarGravacao(pedidosTeste);
    }
}

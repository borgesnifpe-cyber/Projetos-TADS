package Soparia;

import java.util.ArrayList;

public interface Gravador {
    void iniciarGravacao();
    void confirmarGravacao();
    //void GravarListaPedido(Pedido[] pedido); alternativa correta, porém usa um array tradicional
    //void GravarListaPedido(Pedido pedido); está errado, pois a função indica uma lista, mas o parâmetro é apenas um ‘item’
    void GravarListaPedido(ArrayList<Pedido> listaPedido);
}

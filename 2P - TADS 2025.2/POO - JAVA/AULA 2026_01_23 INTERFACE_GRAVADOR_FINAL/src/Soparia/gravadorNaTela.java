package Soparia;

import java.time.LocalDateTime;
import java.util.ArrayList;

public class gravadorNaTela implements Gravador{

    public static void main (String[] args){
//        ArrayList<Pedido> pedidosTemp = new ArrayList<>();
//        Pedido meuPedido;
//        pedidosTemp.add(meuPedido);
//        int nPedidos=pedidosTemp.size(); //Local de inserção da fórmula de cálculo do número de itens da coleção de Pedidos
//        double total=0; //Local de inserção da fórmula de cálculo do valor total dos itens da coleção de Pedidos
//        for (int i = 0; i < pedidosTemp.size(); i++) {
//            double valorTemp = pedidosTemp[i].valor;
//            total = total + valorTemp;
//        }
    }

    public double calcValorTotal(ArrayList<Pedido> listaDePedidos) {
        double total=0;
        for (Pedido meuPedido : listaDePedidos) {
            double tempValor = meuPedido.valor();
            total +=tempValor;
        }
        return total;
    }

    @Override
    public void iniciarGravacao() {
        System.out.println("Lista de pedidos - Soparia TADS");
        String tempo = LocalDateTime.now().toString();
        System.out.println("Pedido às: "+tempo);
        System.out.println("===============================");
    }

    @Override
    public void GravarListaPedido(ArrayList<Pedido> listaPedido) {
        for (Pedido meuPedido : listaPedido) {
            System.out.println(meuPedido.nomePrato()+" - "+meuPedido.getValorFormatado());
        }
    }

    @Override
    public void confirmarGravacao() {
        System.out.println("===============================");
        int nPedidos =0;
        String nPedidos1 = String.format("Total de Itens: %"+nPedidos);
        System.out.println(nPedidos1);
        double total = calcValorTotal(null);
        String valorTotal = String.format("Valor Total: R$%.2f",total);
        System.out.println(valorTotal);
        System.out.println("===============================");
    }

    public void confirmarGravacao(ArrayList<Pedido> listaPedido) {
        System.out.println("===============================");
        int nPedidos = listaPedido.size();
        String nPedidos1 = String.format("Total de Itens:"+nPedidos);
        System.out.println(nPedidos1);
        double total = calcValorTotal(listaPedido);
        String valorTotal = String.format("Valor Total: R$%.2f",total);
        System.out.println(valorTotal);
        System.out.println("===============================");
    }
}

package banco.teste;

import banco.Conta;

public class TestadorSistema
{
	/**
	 * Exemplo de um teste simples do sistema.
	 *  
	 * @param args
	 */
	public static void main(String[] args)
	{
		TestadorSistema testador = new TestadorSistema();
		
		testador.testarCredito();
		testador.testarDebito();
	}

	private void testarCredito()
	{
		Conta novaConta = new Conta(42);
		
		novaConta.imprimirValorConta();
		novaConta.depositar(100);
		novaConta.imprimirValorConta();
	}

	private void testarDebito()
	{
		Conta novaConta = new Conta(42);
		
		novaConta.imprimirValorConta();
		
		
		novaConta.depositar(100);
		novaConta.imprimirValorConta();
		
		novaConta.debitar(50);
		novaConta.imprimirValorConta();
	}
}

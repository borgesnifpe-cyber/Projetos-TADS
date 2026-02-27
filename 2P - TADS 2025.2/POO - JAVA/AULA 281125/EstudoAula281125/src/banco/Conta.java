package banco;

/**
 * Esta classe representa uma conta no banco (financeiro).
 * Possui número e saldo. Tem operações para manipular
 * o saldo da conta.
 */
public class Conta
{
	private double saldo = 0;
	private int numeroConta;
	
	/**
	 * Cria um objeto Conta novo, dado o número da conta.
	 *  
	 * @param novoNumero o novo número de conta a ser utilizado.
	 */
	public Conta(int novoNumero)
	{
		saldo = 0;
		numeroConta = novoNumero;
	}
	
	//public void depositar(int valor)
	public void depositar(double valor)
	{
		saldo = saldo + valor;
		
		// PRINT DIDÁTICO: só serve para ajudar a explicar.
		// não devemos utilizá-lo no mercado.
		// Devemos isolar código de interface com o usuário
		// nas classes que têm essa responsabilidade.
		System.out.println("Terminei o depósito.");
	}

	/**
	 * Método para depuração: só deve ser usado
	 * no desenvolvimento. Não deve chegar em produção.
	 */
	public void imprimirValorConta()
	{
		System.out.print("Saldo da conta: ");
		System.out.println(saldo);
	}

	/**
	 * Realiza o débito do valor da conta.
	 * Sempre questionem os tipos.
	 * 
	 * @param valor
	 */
	//public void debitar(int valor)
	public void debitar(double valor)
	{
		saldo = saldo - valor;
	}
	
	

}

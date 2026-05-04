package Model;

public abstract class Usuário {

	private int id;

	private String nome;

	private int cpf;

	private boolean isActive;

	public boolean validarCpf() {
		return false;
	}

}

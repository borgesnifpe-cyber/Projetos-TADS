#include <stdio.h>
#include <stdlib.h>

//Estrutura de dados
struct personagem {
	char nomePers [20];
	char tipoArma [10];
	char elemento [10];
	char nomeDaBuild [20];
	int ataque;
	int hp;
	int defesa;
	float danoElemental;
	float chanceCrit;
	float danoCrit;
	float regDeEnergia;
	char obser[200];
};

int main() {
	//declaracao das variaveis
	int seletor;
	char conversao[100]; // buffer para entrada como string
	char sobraConversao;       // variável para verificar se há lixo após o número

	//cabecalho do projeto
	printf("Projeto de Linguagens de Programacao - Prof. Marco Antonio \n\n");
	printf("Alunos:\nNathan Borges\nAlisson Ramos\n\n");
	printf("Objetivo do sistema: Estabelecer valores de parametro medio de status\npara builds de personagens do jogo Wuthering Waves\n\n");

	//Titulo da aplicacao
	printf("***** Gestor de Guias de Builds - Wuthering Waves *****\n\n");

	do {
		printf("\nSelecione uma alternativa do sistema:\n");
		printf("1) Adicionar nova build\n");
		printf("2) Excluir build existente\n");
		printf("3) Atualizar build existente\n");
		printf("4) Consultar build\n");
		printf("5) Encerrar sistema\n\n");
		printf("Digite alternativa desejada: ");
		
		fgets(conversao, sizeof(conversao), stdin);

		// Verifica se só tem número inteiro e nada além disso
		if (sscanf(conversao, "%d %c", &seletor, &sobraConversao) != 1 || seletor < 1 || seletor > 5) {
			printf("\n******************************************\n");
			printf("Valor invalido, favor selecionar uma alternativa valida.\n");
			printf("******************************************\n");
		} else {
			break; // entrada válida
		}

	} while (1);

	//Menu de Escolha de Funcao
	switch (seletor) {
		case 1:
			printf("Escolha em desenvolvimento!\n");
			break;
		case 2:
			printf("Escolha em desenvolvimento!\n");
			break;
		case 3:
			printf("Escolha em desenvolvimento!\n");
			break;
		case 4:
			printf("Escolha em desenvolvimento!\n");
			break;
	}
	printf("\nPrograma encerrado. Volte sempre!\n");

	return 0;
}

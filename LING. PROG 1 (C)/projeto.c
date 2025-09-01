#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    int id;
    char nomePers[20];
    char tipoArma[20];
    char elemento[20];
    char nomeDaBuild[50];
    int ataque;
    int hp;
    int defesa;
    double danoElemental;
    double chanceCrit;
    double danoCrit;
    double regDeEnergia;
    char obser[100];
    int delete;
} personagem;

void remover_quebra_linha(char *str);
void cadastro(void);
void listar_builds(void);
void listar_builds_min(void);
void substituir_registro ();
void marcar_excluido (int id);
void menu(void);
void atualizar_builds(void);
void menu_excluir (void);

int main() {
    menu();
    return 0;
}

void menu(void) {
    int seletor;
    char entrada[100], lixo;

    printf("Projeto de Linguagens de Programacao - Prof. Marco Antonio\n\n");
    printf("Alunos:\nNathan Borges\nAlisson Ramos\n\n");
    printf("Objetivo do sistema: Estabelecer valores de parametro medio de status\npara builds de personagens do jogo Wuthering Waves\n\n");
    printf("***** Gestor de Guias de Builds - Wuthering Waves *****\n");

    while (1) {
        do {
            printf("\nSelecione uma alternativa do sistema:\n");
            printf("1) Adicionar nova build\n");
            printf("2) Excluir build existente\n");
            printf("3) Atualizar build existente\n");
            printf("4) Consultar builds salvas\n");
            printf("5) Encerrar sistema\n\n");
            printf("Digite alternativa desejada: ");

            fgets(entrada, sizeof(entrada), stdin);

            if (sscanf(entrada, "%d %c", &seletor, &lixo) != 1 || seletor < 1 || seletor > 5) {
                printf("\n******************************************\n");
                printf("Valor inválido, tente novamente.\n");
                printf("******************************************\n");
            } else {
                break;
            }
        } while (1);

        // ação conforme escolha do usuário
        switch (seletor) {
            case 1:
                cadastro();
                break;
            case 2:
                menu_excluir();
                   
                break;
            case 3:
                atualizar_builds();
                break;
            case 4:
                listar_builds();
                break;
            case 5:
                printf("Programa encerrado. Volte sempre!\n");
                return; // encerra o loop e o programa
        }
    }
}

void remover_quebra_linha(char *str) {
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == '\n') {
            str[i] = '\0';
            return;
        }
        i++;
    }
}

// Atualizei a função de cadastro retirando os limites do array, colocando apenas a função sizeof, pra evitar overflow //

void cadastro(void) {
    FILE *arquivo = fopen("texto.txt", "ab");
    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo.\n");
        return;
    }

    personagem p;
    fseek(arquivo, 0, SEEK_END);
    long tamanho = ftell(arquivo);
    p.id = (tamanho / sizeof(personagem)) + 1;

    printf("\nCadastro de dados. ID: %d\n", p.id);

    printf("Nome do Personagem: ");
    fgets(p.nomePers, sizeof(p.nomePers), stdin);
    remover_quebra_linha(p.nomePers);

    printf("Elemento: ");
    fgets(p.elemento, sizeof(p.elemento), stdin);
    remover_quebra_linha(p.elemento);

    printf("Tipo de Arma: ");
    fgets(p.tipoArma, sizeof(p.tipoArma), stdin);
    remover_quebra_linha(p.tipoArma);

    printf("Nome da Build: ");
    fgets(p.nomeDaBuild, sizeof(p.nomeDaBuild), stdin);
    remover_quebra_linha(p.nomeDaBuild);

    char temp[50];

    printf("Ataque: ");
    fgets(temp, sizeof(temp), stdin);
    p.ataque = atoi(temp);

    printf("HP: ");
    fgets(temp, sizeof(temp), stdin);
    p.hp = atoi(temp);

    printf("Defesa: ");
    fgets(temp, sizeof(temp), stdin);
    p.defesa = atoi(temp);

    printf("Dano Elemental: ");
    fgets(temp, sizeof(temp), stdin);
    p.danoElemental = atof(temp);

    printf("Chance Crítica: ");
    fgets(temp, sizeof(temp), stdin);
    p.chanceCrit = atof(temp);

    printf("Dano Crítico: ");
    fgets(temp, sizeof(temp), stdin);
    p.danoCrit = atof(temp);

    printf("Regeneração de Energia: ");
    fgets(temp, sizeof(temp), stdin);
    p.regDeEnergia = atof(temp);

    printf("Observações: ");
    fgets(p.obser, sizeof(p.obser), stdin);
    remover_quebra_linha(p.obser);
   
    p.delete = 0;

    fwrite(&p, sizeof(personagem), 1, arquivo);
    fclose(arquivo);

    printf("Cadastro finalizado com sucesso!\n");
}

void listar_builds(void) {
    FILE *arquivo = fopen("texto.txt", "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo ou nenhum dado cadastrado ainda.\n");
        return;
    }

    personagem p;
    int count = 0;

    printf("\n===== LISTA DE BUILDS CADASTRADAS =====\n");

    while (fread(&p, sizeof(personagem), 1, arquivo) == 1) {
        if (p.delete==0){
            printf("\nBuild #%d\n", ++count);
            printf("ID: %d\n", p.id);
            printf("Personagem: %s\n", p.nomePers);
            printf("Elemento: %s\n", p.elemento);
            printf("Tipo de Arma: %s\n", p.tipoArma);
            printf("Nome da Build: %s\n", p.nomeDaBuild);
            printf("Ataque: %d | HP: %d | Defesa: %d\n", p.ataque, p.hp, p.defesa);
            printf("Dano Elemental do Echo: %.2f%%\n", p.danoElemental);
            printf("Chance Crítica: %.2f%%\n", p.chanceCrit);
            printf("Dano Crítico: %.2f\n", p.danoCrit);
            printf("Regeneração de Energia: %.2f\n", p.regDeEnergia);
            printf("Observações: %s\n", p.obser);
            printf("---------------------------------------\n");
        }
    }

    if (count == 0) {
        printf("Nenhuma build encontrada.\n");
    }

    fclose(arquivo);
}

void listar_builds_min(void) {
    FILE *arquivo = fopen("texto.txt", "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo ou nenhum dado cadastrado ainda.\n");
        return;
    }

    personagem p;
    int count = 0;

    printf("\n===== LISTA DE BUILDS CADASTRADAS =====\n");

    while (fread(&p, sizeof(personagem), 1, arquivo) == 1) {
        if (p.delete==0){
            printf("\nBuild #%d\n", ++count);
            printf("ID: %d\n", p.id);
            printf("Personagem: %s\n", p.nomePers);
            printf("Nome da Build: %s\n", p.nomeDaBuild);
            printf("---------------------------------------\n");
        }
    }

    if (count == 0) {
        printf("Nenhuma build encontrada.\n");
    }

    fclose(arquivo);
}

void substituir_registro () {
    //leitura dos dados e criação de arquivo temporário
    personagem p;
    FILE *arquivo = fopen ("texto.txt", "rb");
        if (arquivo==NULL) {
            printf ("Erro ao abrir o arquivo ou nenhum dado cadastrado ainda.\n");
        }
    FILE *arquivo_destino = fopen ("temp.txt", "wb");
        if (arquivo_destino==NULL) {   //corrigi para arquivo_destino
            printf ("Erro ao criar o arquivo temporário.\n");
            fclose(arquivo);
        }
   
    int count = 0;
   
    while (fread(&p,sizeof(personagem),1,arquivo)) {
        if (p.delete==0) {
            fwrite(&p,sizeof(personagem),1,arquivo_destino);
            count++;
        }
    }
   
    fclose (arquivo);
    fclose (arquivo_destino);
   
    remove ("texto.txt");
    rename ("temp.txt","texto.txt");
   
    printf ("\n\nRegistro excluído com sucesso!\n\n");
}

void marcar_excluido (int id) {
    FILE *arquivo = fopen ("texto.txt","r+b");
    if (arquivo==NULL) {
        printf ("Erro ao abrir arquivo.\n");
        return;
    }
   
    personagem p;
    int found = 0;
   
    while (fread(&p,sizeof(personagem),1,arquivo)==1) {
        if (p.id==id && p.delete==0) {
            found=1;
            p.delete=1;
           
            fseek(arquivo,-sizeof(personagem), SEEK_CUR);
            fwrite(&p, sizeof(personagem),1, arquivo);
           
            printf("Registrado para exclusão\n");
        }
    }
   
    if (!found) {
        printf("Registro não encontrado ou já excluido\n");
    }
   
    fclose(arquivo);
}

void atualizar_builds() {
    FILE *fp;
    personagem p;
    int id_temp, encontrado = 0;

    fp = fopen("texto.txt", "rb+"); // abre para leitura e escrita
    if (fp == NULL) {
        printf("Erro ao abrir arquivo!\n");
        return;
    }

    printf("\n********* Atualização de Build *********\n");
    listar_builds_min();

    printf("Digite o ID da build que deseja atualizar: ");
    scanf("%d", &id_temp);
    getchar(); // consome o \n

    while (fread(&p, sizeof(personagem), 1, fp)) {
        if (p.id == id_temp && !p.delete) {
            encontrado = 1;
            printf("\nBuild encontrada:\n");
            printf("ID: %d | Nome: %s | Build: %s\n", p.id, p.nomePers, p.nomeDaBuild);

            printf("\nDigite os novos dados da build:\n");

            printf("Nome do Personagem: ");
            fgets(p.nomePers, sizeof(p.nomePers), stdin);
            remover_quebra_linha(p.nomePers);

            printf("Tipo de Arma: ");
            fgets(p.tipoArma, sizeof(p.tipoArma), stdin);
            remover_quebra_linha(p.tipoArma);

            printf("Elemento: ");
            fgets(p.elemento, sizeof(p.elemento), stdin);
            remover_quebra_linha(p.elemento);

            printf("Nome da Build: ");
            fgets(p.nomeDaBuild, sizeof(p.nomeDaBuild), stdin);
            remover_quebra_linha(p.nomeDaBuild);

            printf("Ataque: ");
            scanf("%d", &p.ataque);

            printf("HP: ");
            scanf("%d", &p.hp);

            printf("Defesa: ");
            scanf("%d", &p.defesa);

            printf("Dano Elemental: ");
            scanf("%lf", &p.danoElemental);

            printf("Chance de Critico: ");
            scanf("%lf", &p.chanceCrit);

            printf("Dano Crítico: ");
            scanf("%lf", &p.danoCrit);

            printf("Regeneração de Energia: ");
            scanf("%lf", &p.regDeEnergia);
            getchar(); // consome o \n

            printf("Observações: ");
            fgets(p.obser, sizeof(p.obser), stdin);
            remover_quebra_linha(p.obser);

            // Volta o ponteiro do arquivo para reescrever esta posição
            fseek(fp, -sizeof(personagem), SEEK_CUR);
            fwrite(&p, sizeof(personagem), 1, fp);

            printf("\n✅ Build atualizada com sucesso!\n");
            break;
        }
    }

    if (!encontrado) {
        printf("\n❌ Nenhuma build encontrada com esse ID.\n");
    }

    fclose(fp);
}

void menu_excluir () {
    int id_temp,confirm;
     printf ("\n");
                printf ("*********Exclusão de Build*********\n");
                printf ("Resumo dos builds ativas:\n");
                listar_builds_min();
                printf("\n");
                printf ("Selecione uma build para excluir pelo ID:");
                scanf("%d",&id_temp);
                printf("\nTem certeza que deseja excluir essa build? (Digite 1 para SIM/ 0 para NAO):");
                scanf("%d",&confirm);
                    if (confirm==1){
                        marcar_excluido(id_temp);
                        substituir_registro();
                        getchar();
                    } else {
                        printf ("\n\nExclusão cancelada!");
                    }
}

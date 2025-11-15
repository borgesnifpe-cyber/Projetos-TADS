#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

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
    bool deleted;
} personagem;

void remover_quebra_linha(char *str);
void cadastro(void);
void listar_builds(void);
void listar_builds_min(void);
void compactar_arquivo(void);
void marcar_excluido(int id);
void menu(void);
void atualizar_builds(void);
void menu_excluir(void);
int ler_int(const char *prompt);
double ler_double(const char *prompt);

int main() {
    menu();
    return 0;
}

void remover_quebra_linha(char *str) {
    char *pos = strchr(str, '\n');
    if (pos) *pos = '\0';
}

int ler_int(const char *prompt) {
    char buffer[100];
    long val;
    char *endptr;
    while (1) {
        printf("%s", prompt);
        if (!fgets(buffer, sizeof(buffer), stdin)) continue;
        val = strtol(buffer, &endptr, 10);
        if (endptr == buffer || *endptr != '\n') {
            printf("Entrada inválida. Digite um número inteiro.\n");
        } else {
            return (int)val;
        }
    }
}

double ler_double(const char *prompt) {
    char buffer[100];
    double val;
    char *endptr;
    while (1) {
        printf("%s", prompt);
        if (!fgets(buffer, sizeof(buffer), stdin)) continue;
        val = strtod(buffer, &endptr);
        if (endptr == buffer || *endptr != '\n') {
            printf("Entrada inválida. Digite um número.\n");
        } else {
            return val;
        }
    }
}

void cadastro(void) {
    FILE *arquivo = fopen("texto.dat", "ab");
    if (!arquivo) {
        printf("Erro ao abrir arquivo.\n");
        return;
    }

    personagem p = {0};

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

    p.ataque = ler_int("Ataque: ");
    p.hp = ler_int("HP: ");
    p.defesa = ler_int("Defesa: ");
    p.danoElemental = ler_double("Dano Elemental: ");
    p.chanceCrit = ler_double("Chance Critica: ");
    p.danoCrit = ler_double("Dano Critico: ");
    p.regDeEnergia = ler_double("Regeneracao de Energia: ");

    printf("Obs: ");
    fgets(p.obser, sizeof(p.obser), stdin);
    remover_quebra_linha(p.obser);
   
    p.deleted = false;

    if (fwrite(&p, sizeof(personagem), 1, arquivo) != 1) {
        printf("Erro ao escrever no arquivo.\n");
    }
    fclose(arquivo);
    printf("Cadastro finalizado com sucesso!\n");
}

void listar_builds(void) {
    FILE *arquivo = fopen("texto.dat", "rb");
    if (!arquivo) {
        printf("Nenhum dado cadastrado ainda.\n");
        return;
    }

    personagem p;
    int count = 0;

    printf("\n===== LISTA DE BUILDS CADASTRADAS =====\n");
    while (fread(&p, sizeof(personagem), 1, arquivo) == 1) {
        if (!p.deleted) {
            printf("\nBuild #%d\n", ++count);
            printf("ID: %d\n", p.id);
            printf("Personagem: %s\n", p.nomePers);
            printf("Elemento: %s\n", p.elemento);
            printf("Tipo de Arma: %s\n", p.tipoArma);
            printf("Nome da Build: %s\n", p.nomeDaBuild);
            printf("Ataque: %d | HP: %d | Defesa: %d\n", p.ataque, p.hp, p.defesa);
            printf("Dano Elemental: %.2f%%\n", p.danoElemental);
            printf("Chance Critica: %.2f%%\n", p.chanceCrit);
            printf("Dano Critico: %.2f%%\n", p.danoCrit);
            printf("Regeneracao de Energia: %.2f%%\n", p.regDeEnergia);
            printf("Obs: %s\n", p.obser);
            printf("---------------------------------------\n");
        }
    }

    if (count == 0) printf("Nenhuma build encontrada.\n");
    fclose(arquivo);
}

void listar_builds_min(void) {
    FILE *arquivo = fopen("texto.dat", "rb");
    if (!arquivo) {
        printf("Nenhum dado cadastrado ainda.\n");
        return;
    }

    personagem p;
    int count = 0;

    printf("\n===== LISTA DE BUILDS CADASTRADAS =====\n");
    while (fread(&p, sizeof(personagem), 1, arquivo) == 1) {
        if (!p.deleted) {
            printf("ID: %d | Personagem: %s | Build: %s\n", p.id, p.nomePers, p.nomeDaBuild);
            count++;
        }
    }

    if (count == 0) printf("Nenhuma build encontrada.\n");
    fclose(arquivo);
}

void compactar_arquivo(void) {
    FILE *origem = fopen("texto.dat", "rb");
    if (!origem) return;

    FILE *destino = fopen("temp.dat", "wb");
    if (!destino) {
        fclose(origem);
        return;
    }

    personagem p;
    while (fread(&p, sizeof(personagem), 1, origem) == 1) {
        if (!p.deleted) {
            fwrite(&p, sizeof(personagem), 1, destino);
        }
    }

    fclose(origem);
    fclose(destino);
    remove("texto.dat");
    rename("temp.dat", "texto.dat");
}

void marcar_excluido(int id) {
    FILE *arquivo = fopen("texto.dat", "r+b");
    if (!arquivo) {
        printf("Erro ao abrir arquivo.\n");
        return;
    }

    personagem p;
    int encontrado = 0;
    while (fread(&p, sizeof(personagem), 1, arquivo) == 1) {
        if (p.id == id && !p.deleted) {
            encontrado = 1;
            p.deleted = true;
            fseek(arquivo, -sizeof(personagem), SEEK_CUR);
            fwrite(&p, sizeof(personagem), 1, arquivo);
            break;
        }
    }
    fclose(arquivo);
    if (!encontrado) printf("Registro não encontrado.\n");
}

void atualizar_builds() {
    FILE *arquivo = fopen("texto.dat", "r+b");
    if (!arquivo) {
        printf("Erro ao abrir arquivo!\n");
        return;
    }

    printf("\n********* Atualização de Build *********\n");
    listar_builds_min();

    int id_temp = ler_int("\nDigite o ID da build que deseja atualizar: ");
    personagem p;
    int encontrado = 0;

    while (fread(&p, sizeof(personagem), 1, arquivo) == 1) {
        if (p.id == id_temp && !p.deleted) {
            encontrado = 1;
            printf("\nBuild encontrada. Digite os novos dados:\n");

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

            p.ataque = ler_int("Ataque: ");
            p.hp = ler_int("HP: ");
            p.defesa = ler_int("Defesa: ");
            p.danoElemental = ler_double("Dano Elemental: ");
            p.chanceCrit = ler_double("Chance Critica: ");
            p.danoCrit = ler_double("Dano Critico: ");
            p.regDeEnergia = ler_double("Regeneracao de Energia: ");

            printf("Obs: ");
            fgets(p.obser, sizeof(p.obser), stdin);
            remover_quebra_linha(p.obser);

            fseek(arquivo, -sizeof(personagem), SEEK_CUR);
            fwrite(&p, sizeof(personagem), 1, arquivo);
            printf("Build atualizada com sucesso!\n");
            break;
        }
    }

    if (!encontrado) printf("Nenhuma build encontrada com esse ID.\n");
    fclose(arquivo);
}

void menu_excluir(void) {
    printf("\n********* Exclusão de Build *********\n");
    listar_builds_min();
    int id_temp = ler_int("\nDigite o ID da build para excluir: ");
    int confirm = ler_int("Tem certeza? (1 = Sim / 0 = Não): ");
    if (confirm == 1) {
        marcar_excluido(id_temp);
        compactar_arquivo();
        printf("Build excluída com sucesso!\n");
    } else {
        printf("Exclusão cancelada.\n");
    }
}

void menu(void) {
    int seletor;
    printf("Sistema de Gestão de Builds - Wuthering Waves\n\n");
    while (1) {
        printf("\n1) Adicionar nova build\n");
        printf("2) Excluir build existente\n");
        printf("3) Atualizar build existente\n");
        printf("4) Consultar builds salvas\n");
        printf("5) Encerrar sistema\n");
        seletor = ler_int("Digite a opção desejada: ");

        switch (seletor) {
            case 1: cadastro(); break;
            case 2: menu_excluir(); break;
            case 3: atualizar_builds(); break;
            case 4: listar_builds(); break;
            case 5:
                printf("Programa encerrado.\n");
                return;
            default:
                printf("Opção inválida.\n");
        }
    }
}
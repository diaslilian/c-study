/*
  Author: Lilian Dias

  IMPORTANTE: O código foi desenvolvido na distribuição Linux, com o VSCODE, rodando com o terminal ZSH, com isso, alguns comandos podem ser diferentes de outros SOs.
  Exemplo de comandos: sleep(2), system("clear");
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define MAX_VACINAS 200

void menu();
void cadastroVacina();
void listaAplicacoes();
void consultaCpf();
void limpabuffer();

typedef struct
{
  char nome[50],
      cpf[16],
      vac[20],
      data[16];
  int numLote;

  int emUso, cod;
} Cadastro;

Cadastro vacinas[MAX_VACINAS];

int main()
{
  setlocale(LC_ALL, "Portuguese");

  menu();

  return 0;
}

void menu()
{
  int opcao;

  do
  {

    system("clear");
    printf("\n\n\n"
           " ------ \n"
           "| Menu |\n"
           "|-------------------------- \n"
           "| [1] Cadastrar Vacina     |\n"
           "| [2] Listar Aplicações    |\n"
           "| [3] Consultar por CPF    |\n"
           "|                          |\n"
           "| [4] Sair                 |\n"
           " --------------------------\n\n\n");

    printf("Selecione uma opcao: ");

    scanf("%d", &opcao);
    limpabuffer();

    switch (opcao)
    {
    case 1:
      cadastroVacina();
      break;

    case 2:
      listaAplicacoes();
      break;

    case 3:
      consultaCpf();
      break;

    case 4:
      system("clear");
      printf("\n\n\n");
      printf("----------------------\n");
      printf("| Fim da Execução... |\n");
      printf("----------------------\n\n");
      exit(0);
      break;

    default:
      printf("Valor inválido! Tente novamente...\n");
      sleep(2);
      main();
      break;
    }
  } while (opcao != 0);
}

void cadastroVacina()
{
  int op;
  char nome[50],
      cpf[16],
      vac[20],
      data[16];
  int numLote;

  do
  {
    system("clear");
    printf(" -------------- \n"
           "|   CADASTRO   |\n"
           " -------------- \n");

    printf("\nNome: ");
    fflush(stdout);
    fgets(nome, sizeof(nome), stdin);

    printf("\nCPF: ");
    fflush(stdout);
    fgets(cpf, sizeof(cpf), stdin);

    printf("\nVacina: ");
    fflush(stdout);
    fgets(vac, sizeof(vac), stdin);

    printf("\nData: ");
    fflush(stdout);
    fgets(data, sizeof(data), stdin);

    printf("\nNúmero do Lote: ");
    scanf("%d", &numLote);
    limpabuffer();

    for (int i = 0; i < MAX_VACINAS; i++)
    {
      if (vacinas[i].emUso == 0)
      {
        strcpy(vacinas[i].nome, nome);
        strcpy(vacinas[i].cpf, cpf);
        strcpy(vacinas[i].vac, vac);
        strcpy(vacinas[i].data, data);

        vacinas[i].numLote = numLote;

        vacinas[i].emUso = 1;

        break;
      }
    }

    printf("\n1 - Continuar cadastrando\n0 - Sair: ");
    scanf("%d", &op);
    limpabuffer();
  } while (op != 0);
}

void listaAplicacoes()
{

  int erro = 1;
  int op;

  do
  {
    system("clear");
    printf("\n");
    printf("--------------------\n");
    printf("| LISTA APLICAÇÕES |\n");
    printf("--------------------\n\n");
    printf("\n");

    for (int i = 0; i < MAX_VACINAS; i++)
    {

      if (vacinas[i].emUso == 1)
      {
        printf("\nCódigo: %d\n", i);
        printf("Nome: %s", vacinas[i].nome);
        printf("CPF: %s", vacinas[i].cpf);
        printf("Vacina: %s", vacinas[i].vac);
        printf("Data: %s", vacinas[i].data);
        printf("Número do Lote: %d", vacinas[i].numLote);
        printf("\n===================================\n");
      }

      erro = 0;
    }

    if (erro)
    {
      printf("Erro ao recuperar lista de aplicações...\n");
    }

    printf("\n\n\nDigite 0 para sair: ");
    scanf("%d", &op);
    limpabuffer();
  } while (op != 0);
}

void consultaCpf()
{
  int erro = 1;
  char cpf[16];
  int op;

  do
  {
    system("clear");
    printf("\n");
    printf("--------------------\n");
    printf("| CONSULTA POR CPF |\n");
    printf("--------------------\n\n");
    printf("\n\n");

    printf("\nDigite um CPF a ser pesquisado: ");
    fgets(cpf, sizeof(cpf), stdin);

    for (int i = 0; i < MAX_VACINAS; i++)
    {
      if (strstr(vacinas[i].cpf, cpf) != NULL)
      {
        printf("\n\nCódigo: %d\n", i);
        printf("Nome: %s", vacinas[i].nome);
        printf("CPF: %s", vacinas[i].cpf);
        printf("Vacina: %s", vacinas[i].vac);
        printf("Data: %s", vacinas[i].data);
        printf("Número do Lote: %d", vacinas[i].numLote);

        erro = 0;
      }
    }

    if (erro)
      printf("\n\nCPF não encontrado\n");
    else
      printf("\n\n\nPesquisa realizada com sucesso!\n");

    printf("\n\n\nDigite 0 para sair ou 1 para nova pesquisa: ");
    scanf("%d", &op);
    limpabuffer();
  } while (op != 0);
}

void limpabuffer()
{
  int c = 0;
  while ((c = getchar()) != '\n' && c != EOF)
  {
  }
  return;
}
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define true 1
int count = 0;
typedef struct produto
{
	char nome_produto[51];
	char pais_origem[51];
	int quantidade_itens;
	char codigo_simp[9];
} p;

void cadastra_produto(p *prod, char *nomeProduto, char *paisOrigem, int quantidadeItens);
void codigos(char *rCod, char *pais);
int main(void)
{

	p prod[1000];
	char codigo[9];
	while (true)
	{
		printf("+----------------------------------------------------+\n"
			   "| CONTROLE DE ESTOQUE ALI-IFB                        |\n"
			   "|                                                    |\n"
			   "|   1 - Cadastrar novo produto;                      |\n"
			   "|   2 - Atualizar informações de um produto          |\n"
			   "|   3 - Vender produto                               |\n"
			   "|   4 - Consultar informações de um produto          |\n"
			   "|   5 - Consultar quantidade de todos os produtos    |\n"
			   "|   6 - Finalizar produto                            |\n"
			   "+----------------------------------------------------+\n");

		int x;
		scanf("%d", &x);
		switch (x)
		{
		case 1:
		{
			// Nome produto:
			puts("Digite o nome do produto: ");
			getchar();
			scanf("%[^\n]s", prod[count].nome_produto);

			// País de origem:
			puts("Digite o nome do país de origem do produto: ");
			getchar();
			scanf("%[^\n]s", prod[count].pais_origem);

			// Quantidade de itens:
			puts("Digite a quantidade de produtos: ");
			scanf("%d", &prod[count].quantidade_itens);

			cadastra_produto(&prod[count], prod[count].nome_produto, prod[count].pais_origem, prod[count].quantidade_itens); //

			codigos(prod[count].codigo_simp, prod[count].pais_origem);

			printf("CÓDIGO DE BARRAS: %s\n", prod[count].codigo_simp);
			count++;
			break;
		}

		case 2:
		{
			int z, s, i;

			puts("digite o codigo do produto:");
			getchar();
			scanf("%[^\n]s", codigo);
			getchar();
			for (i = 0; i < count; i++)
			{
				if (strcmp(codigo, prod[i].codigo_simp) == 0)
				{
					s = 1;
					break;
				}
			}
			if (s != 1)
			{
				printf("código inválido!\n");
				break;
			}
			printf("Atualizar informações do produto:\n"
				   "  1 - Alterar Nome\n"
				   "  2 - Alterar pais de origem\n"
				   "  3 - Adicionar mais itens\n");
			scanf("%d", &z);
			switch (z)
			{
			case 1:
			{
				puts("Digite o novo nome:");
				char nome[51];
				getchar();
				scanf("%[^\n]s", nome);
				getchar();
				strcpy(prod[i].nome_produto, nome);
				break;
			}

			case 2:
			{
				puts("Digite o novo país: ");
				char pais[51];
				getchar();
				scanf("%[^\n]s", pais);
				getchar();
				strcpy(prod[i].nome_produto, pais);
				prod[i].codigo_simp[0] = toupper(pais[0]);
				prod[i].codigo_simp[1] = toupper(pais[1]);
				break;
			}

			case 3:
			{
				int quantidade;
				scanf("%d", &quantidade);
				prod[0].quantidade_itens += quantidade;
				break;
			}

			default:
				break;
			}
			break;
		}
		case 3:
		{
			int entrada;
			int i;
			puts("Digite o código do produto:");
			getchar();
			scanf("%[^\n]s", codigo);
			getchar();
			for (i = 0; i <= count; i++)
			{
				if (strcmp(codigo, prod[count].codigo_simp) != 0)
				{
					entrada = 1;
					puts("Código inválido!");
					break;
				}
			}
			if (entrada == 1)
			{
				while (true)
				{
					int qntVenda;
					puts("Quantidade de itens a ser vendido: ");
					scanf("%d", &qntVenda);

					if (qntVenda <= 0)
					{
						puts("valor inválido, Digite novamente");
					}
					else if (qntVenda >= prod[i].quantidade_itens)
					{
						puts("Não existem itens suficientes para este produto");
					}
					else
					{
						prod[i].quantidade_itens -= qntVenda;
					}
				}
			}
			break;
		}
		case 4:
		{
			puts("Digite o código do produto:");
			getchar();
			scanf("%s", codigo);
			getchar();
			int i;
			for (i = 0; i <= count; i++)
			{
				if (strcmp(codigo, prod[i].codigo_simp) == 0)
				{
					printf("código do produto: %s\n\n"
						   "Nome do Produto: %s\n"
						   "país de origem: %s\n"
						   "Quantidade de itens: %d\n"
						   "Código: %s\n",
						   prod[i].codigo_simp, prod[i].nome_produto, prod[i].pais_origem, prod[i].quantidade_itens, prod[i].codigo_simp);
				}
			}
			break;
		}
		case 5:
		{
			int i;
			for (i = 0; i < count; i++)
			{
				printf("%s\t%d\n", prod[i].codigo_simp, prod[i].quantidade_itens);
			}
			break;
		}
		default:
			return 0;
			break;
		}
	}
	return 0;
}

void codigos(char *rCod, char *pais)
{
	char y[4];
	int i, j = 0;
	sprintf(y, "%03i", count);
	for (i = 0; i < 2; i++)
	{
		rCod[i] = toupper(pais[i]);
	}
	rCod[i] = 'I';
	rCod[i + 1] = 'F';
	rCod[i + 2] = 'B';
	for (i = i + 3; i < 8; i++, j++)
	{
		rCod[i] = y[j];
	};
}

void cadastra_produto(p *prod, char *nomeProduto, char *paisOrigem, int quantidadeItens)
{
	strcpy(prod[count].nome_produto, nomeProduto);
	strcpy(prod[count].pais_origem, paisOrigem);
	prod[count].quantidade_itens = quantidadeItens;
}

#include "functions.h"

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
    prod[count].quantidade_itens = quantidadeItens; //1 vez buga 2 vez sai normal
}
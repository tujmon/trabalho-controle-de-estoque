#ifndef TRAB_H_INCLUDE
#define TRAB_H_INCLUDE

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int count;

typedef struct produto
{
    char nome_produto[51];
    char pais_origem[51];
    int quantidade_itens;
    char codigo_simp[9];
} p;

void codigos(char *rCod, char *pais);
void cadastra_produto(p *prod, char *nomeProduto, char *paisOrigem, int quantidadeItens);

#endif
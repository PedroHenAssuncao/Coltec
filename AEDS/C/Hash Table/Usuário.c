/**
* @file		Usuário.c
* @brief	Arquivo com funções destinadas a interação com o usuário.
* @author	Pedro Henrique Assunção
* @date		2020-11-05
*/

/* Inclusões */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "Erros.h"
#include "Hash.h"
#include "Tipos.h"

#pragma warning(disable : 4996)


DataType * NovosDados(void){

	DataType* novoDado = (DataType*)malloc(sizeof(DataType));

	if (novoDado == NULL) return NULL;

	setbuf(stdin, NULL);
	printf("\nDigite o nome do novo contato: ");
	fgets(novoDado->Nome, TAMANHO_MAXIMO_STRING, stdin);
	setbuf(stdin, NULL);
	printf("\n\nDigite o telefone do novo contato: ");
	(void)scanf("%d", &novoDado->Telefone);

	novoDado->Endereco = (DadosEndereco*)malloc(sizeof(DadosEndereco));

	if (novoDado->Endereco == NULL) return NULL;

	setbuf(stdin, NULL);
	printf("\nDigite a Rua da pessoa: ");
	fgets(novoDado->Endereco->Rua, TAMANHO_MAXIMO_STRING, stdin);
	setbuf(stdin, NULL);
	printf("\nDigite o Bairro da pessoa: ");
	fgets(novoDado->Endereco->Bairro, TAMANHO_MAXIMO_STRING, stdin);
	setbuf(stdin, NULL);
	printf("\nDigite a Cidade da pessoa: ");
	fgets(novoDado->Endereco->Cidade, TAMANHO_MAXIMO_STRING, stdin);
	setbuf(stdin, NULL);
	printf("\nDigite o número da casa da pessoa: ");
	(void)scanf("%d", &novoDado->Endereco->numero);
	setbuf(stdin, NULL);

	return novoDado;
}

char* NomeEscolhido(void) {

	char* nome = (char*)malloc(sizeof(char) * TAMANHO_MAXIMO_STRING);

	if (nome == NULL) return NULL;

	setbuf(stdin, NULL);
	printf("\nDigite o nome da pessoa desejada: ");
	fgets(nome, TAMANHO_MAXIMO_STRING, stdin);
	setbuf(stdin, NULL);

	return nome;
}

int EscolheColuna(HashTable * table) {

	int ColunaEscolhida;

	printf("\nEscolha uma coluna(Max: %d): ", table->nColunas);
	(void)scanf("%d", &ColunaEscolhida);

	return (ColunaEscolhida - 1);
}
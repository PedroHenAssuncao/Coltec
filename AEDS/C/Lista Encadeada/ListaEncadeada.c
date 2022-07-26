/**
* @file		ListaEncadeada.c
* @brief	Arquivo com as implementa��es de Lista.
* @author	Pedro Henrique Assun��o
* @date		2020-11-05
*/

/* Inclus�es */

#include <stdio.h>
#include <stdlib.h>
#include "Erros.h"
#include "Tipos.h"
#include "Lista.h"

// INICIO - manipula��o de Lista

/*
* Fun��o para cria��o/inicializa��o de uma nova lista
* @param Lista apontador para a lista que sera inicializada
* @return Endere�o da lista inicializada caso de certo, caso contr�rio retornar� NULL
*/
Lista * CriaLista(Lista* NovaLista){
	
	// Aloca espa�o para a nova lista
	NovaLista = (Lista*)malloc(sizeof(Lista));

	// Verifica se a aloca��o funcionou caso n�o tenha funcionado retornar� NULL
	if (NovaLista == NULL) return NULL;

	// Inicializa a nova lista caso a aloca��o tenha funcionado
	NovaLista->Nitens = 0;
	NovaLista->primeiro = NULL;

	// Retorna a nova lista inicializada caso tudo tenha funcionado :)
	return NovaLista;

}

/*
* Fun��o que insere item no inicio da Lista
* @param Lista apontador para a lista onde o item ser� inserido 
* @param TipoDado item que ser� inserido
* @return SUCESSO caso de certo, caso contr�rio retornar� o codigo do ERRO
*/
Erros_t InsereInicio(Lista* lista, TipoDado ItemInserir){
	
	// Verifica se os argumentos passados s�o v�lidos
	if (lista == NULL ) return ERRO_ARGUMENTO_INVALIDO;

	// Aloca espa�o na mem�ria para o novo item
	Item_Lista* novoItem = (Item_Lista*)malloc(sizeof(Item_Lista));

	// Verifica se a aloca��o funcionou
	if (novoItem == NULL) return ERRO_ALOCACAO_MEMORIA;

	// Insere o novo item como o primeiro item da lista
	novoItem->DadosItem = ItemInserir;
	novoItem->proximo = lista->primeiro;
	lista->primeiro = novoItem;
	// Incrementa o n�mero de itens
	lista->Nitens++;

	// Se chegou aqui tudo funcionou :)
	return SUCESSO;
}

/*
* Fun��o que insere de maneira ordenada na lista
* @param Lista apontador para a lista onde o item ser� inserido
* @param TipoDado item que ser� inserido
* @return SUCESSO caso tudo de certo, caso contr�rio retornar� o codigo do ERRO
*/
Erros_t InsereOrdenado(Lista* lista, TipoDado ItemInserir) {

	// Verifica se a lista � v�lida
	if (lista == NULL) return ERRO_ARGUMENTO_INVALIDO;

	// Aloca espa�o na mem�ria para o novo item
	Item_Lista* novoItem = (Item_Lista*)malloc(sizeof(Item_Lista));

	// Verifica se a aloca��o funcionou
	if (novoItem == NULL) return ERRO_ALOCACAO_MEMORIA;

	novoItem->DadosItem = ItemInserir;

	// Caso a lista esteja vazia o item ser� inserido na primeira posi��o
	if (ListaVazia(lista) == VERDADEIRO){

		// Insere o novo item como o primeiro item da lista
		novoItem->proximo = lista->primeiro;
		lista->primeiro = novoItem;
		// Incrementa o n�mero de itens
		lista->Nitens++;

		// Se chegou aqui tudo funcionou :)
		return SUCESSO;

	}

	// Variaveis para auxiliar a navega��o dentro da lista
	Item_Lista* anterior = NULL, * atual = lista->primeiro;

	// Percorre a lista
	while (atual->proximo != NULL){

		// Verifica se o item atual � maior ou igual ao item a ser inserido
		if (atual->DadosItem >= ItemInserir){

			// Caso o item atual seja maior verifica se o item atual � o primeiro
			if (anterior == NULL) {
				
				// Insere o novo item a primeira posi��o da lista e depois faz a linkagem
				lista->primeiro = novoItem;
				novoItem->proximo = atual;
			}

			// Caso o item atual n�o seja o primeiro
			else
			{
				// Faz a linkagem entre os itens da lista
				anterior->proximo = novoItem;
				novoItem->proximo = atual;
			}

			break;

		}
		
		// Percorre a lista
		anterior = atual;
		atual = atual->proximo;
	}

	// Incrementa o n�mero de itens
	lista->Nitens++;

	// Se chegou aqui tudo funcionou :)
	return SUCESSO;

}

/*
* Fun��o que procura um item especifico da lista
* @param Lista apontador para a lista que possui o item
* @param TipoDado item que ser� procurado
* @return SUCESSO caso tudo funcione, caso contr�rio retornar� o codigo de ERRO
*/
Erros_t ProcuraItem(Lista * lista, TipoDado itemProcurado){
	
	// Verifica se a lista � v�lida
	if (lista == NULL) return ERRO_ARGUMENTO_INVALIDO;

	// Verifica se a lista est� vazia
	if (ListaVazia(lista) == VERDADEIRO) return ERRO_LISTA_VAZIA;

	Item_Lista* atual = lista->primeiro;
	bool_t ItemEncontrado = FALSO;
	unsigned int posicao = 0;

	// Percorre a lista
	while (atual->proximo != NULL){

		posicao++;

		// Verifica se o item atual � o item procurado
		if (atual->DadosItem == itemProcurado) {

			// Atualiza o estado da vari�vel
			ItemEncontrado = VERDADEIRO;
			// Sai do looping
			break;
		}
		
		// Atualiza as variaveis utilizadas para percorrer a lista
		atual = atual->proximo;
	}

	// Verifica se o item foi encontrado
	if (ItemEncontrado == FALSO) {

		// Imprime mensagem de erro
		printf("\nO item: %.02f n�o est� na lista", itemProcurado);
		// Retorna o codigo de erro
		return ERRO_DADO_NAO_ENCONTRADO;
	}

	printf("O item: %.02f esta na Pos: %d", itemProcurado, posicao);

	// Se chegou aqui tudo funcionou :)
	return SUCESSO;
}

/*
* Fun��o que remove um item da lista
* @param Lista apontador para a lista que possui o item
* @param TipoDado item que ser� removido
* @return SUCESSO caso tudo funcione, caso contr�rio retornar� o codigo de ERRO
*/
Erros_t RemoveItem(Lista* lista, TipoDado ItemRemover){
	
	// Verifica se a lista � v�lida
	if (lista == NULL) return ERRO_ARGUMENTO_INVALIDO;

	// Verifica se a lista est� vazia
	if (ListaVazia(lista) == VERDADEIRO) return ERRO_LISTA_VAZIA;

	Item_Lista *anterior = NULL, * atual = lista->primeiro;
	bool_t ItemEncontrado = FALSO;

	// Percorre a lista
	while (atual != NULL){

		// Verifica se o item atual � o item a ser removido
		if (atual->DadosItem == ItemRemover) {

			// Atualiza o estado da v�riavel
			ItemEncontrado = VERDADEIRO;
			// Sai do looping
			break;

		}

		// Atualiza as vari�veis utilizadas para percorrer a lista
		anterior = atual;
		atual = atual->proximo;

	}

	// Verifica se o item foi encontrado
	if (ItemEncontrado == FALSO) {

		// Imprime mensagem de ERRO
		printf("\n\tEsse item n�o existe na lista\n");
		// Retorna codigo de ERRO
		return ERRO_DADO_NAO_ENCONTRADO;
	}

	// Verifica se o item a ser removido � o primeiro
	if (anterior == NULL) {

		// Substitui o primeiro item pelo pr�ximo
		lista->primeiro = atual->proximo;
		// Libera a mem�ria usado pelo item a ser removido
		free(atual);

		// Decrementa a quantidade de itens que a lista possui
		lista->Nitens--;

		// Se chegou aqui tudo funcionou :)
		return SUCESSO;

	}

	// Faz a linkagem entre o item anterior e o item que est� depois do item a ser removido
	anterior->proximo = atual->proximo;
	// Libera a mem�ria usada pelo item removido
	free(atual);

	// Decrementa a quantidade de itens da lista
	lista->Nitens--;

	// Se chegou aqui tudo funcionou :)
	return SUCESSO;
}

/*
* Fun��o que verifica se a lista est� vazia
* @param Lista apontador para a lista que ser� testada
* @return VERDADEIRO caso a lista esteja vazia e FALSO caso a lista n�o esteja vazia
*/
bool_t ListaVazia(Lista *  lista){
	
	// Verifica se a lista est� vazia, caso esteja retorna VERDADEIRO, caso contr�rio retorna FALSO
	return (lista->primeiro == NULL) ? VERDADEIRO : FALSO;
}

/*
* Fun��o destinada a impress�o dos itens da lista
* @param Lista apontador para a lista a ser impressa
* @return SUCESSO caso funcione, caso contr�rio retornar� o codigo de ERRO
*/
Erros_t ImprimeListaE(Lista* minhaLista) {

	// Verifica se a lista � v�lida
	if (minhaLista == NULL) return ERRO_ARGUMENTO_INVALIDO;

	// Verifica se a lista est� vazia
	if (ListaVazia(minhaLista) == VERDADEIRO) return ERRO_LISTA_VAZIA;

	int i = 0;
	Item_Lista* atual;
	Item_Lista* proximo = minhaLista->primeiro;

	printf("Lista com %d item(s)\n", minhaLista->Nitens);
	printf("Impressao da lista\n"\
		   "------------------\n");

	// Percorre a lista
	while (proximo != NULL){

		// Atualiza as vari�veis utilizadas para percorrer a lista
		atual = proximo;
		proximo = atual->proximo;

		printf("Pos: %d / Valor: %.02f\n", i + 1, atual->DadosItem);

		// incrementa o contador de posi��es
		i++;

	}
	printf("------------------\n");

	// Se chegou aqui tudo funcionou :)
	return SUCESSO;
}

/*
* Fun��o destinada a destrui��o da lista
* @param Lista apontador para a lista a ser destruida
* @return SUCESSO caso funcione, caso contr�rio retornar� o codigo de ERRO
*/
Erros_t DestroiLista(Lista* minhaLista){

	// Verifica se a lista � v�lida
	if (minhaLista == NULL) return ERRO_ARGUMENTO_INVALIDO;

	// Verifica se a lista est� vazia
	if (ListaVazia(minhaLista) == VERDADEIRO) return ERRO_LISTA_VAZIA;

	Item_Lista* atual;
	Item_Lista* proximo = minhaLista->primeiro;

	// Percorre a lista
	while (proximo != NULL) {

		// Atualiza as vari�veis utilizadas para percorrer a lista
		atual = proximo;
		proximo = atual->proximo;

		// Libera a mem�ria dos itens da lista
		free(atual);
	}

	// Inicaliza a lista
	minhaLista->primeiro = NULL;
	minhaLista->Nitens = 0;

	// Se chegou aqui tudo funcionou :)
	return SUCESSO;
}
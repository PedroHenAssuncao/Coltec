/**
* @file		ListaDuplamenteEncadeada.c
* @brief	Arquivo com as implementações de Lista Duplamente Encadeada.
* @author	Pedro Henrique Assunção
* @date		2020-11-05
*/


/* Inclusões */

#include <stdio.h>
#include <stdlib.h>
#include "Erros.h"
#include "ListaDuplamenteEncadeada.h"
#include "Tipos.h"

// INICIO - manipulação de lista duplamente encadeada

/*
* Função para criação/inicialização de uma nova lista
* @param Lista apontador para a lista que sera inicializada
* @return Endereço da lista inicializada caso de certo, caso contrário retornará NULL
*/
Lista* CriaLista(Lista* NovaLista) {

	// Aloca espaço para a nova lista
	NovaLista = (Lista*)malloc(sizeof(Lista));

	// Verifica se a alocação funcionou caso não tenha funcionado retornará NULL
	if (NovaLista == NULL) return NULL;

	// Inicializa a nova lista caso a alocação tenha funcionado
	NovaLista->Nitens = 0;
	NovaLista->primeiro = NovaLista->ultimo = NULL;

	// Retorna a nova lista inicializada caso tudo tenha funcionado :)
	return NovaLista;

}

/*
* Função que verifica se a lista está vazia
* @param Lista apontador para a lista que será testada
* @return VERDADEIRO caso a lista esteja vazia e FALSO caso a lista não esteja vazia
*/
bool_t ListaVazia(Lista* lista) {

	// Verifica se a lista está vazia, caso esteja retorna VERDADEIRO, caso contrário retorna FALSO
	return (lista->primeiro == NULL) ? VERDADEIRO : FALSO;
}

/*
* Função que insere item no inicio da Lista
* @param Lista apontador para a lista onde o item será inserido
* @param TipoDado item que será inserido
* @return SUCESSO caso de certo, caso contrário retornará o codigo do ERRO
*/
Erros_t InsereInicio(Lista* lista, TipoDado ItemInserir) {

	// Verifica se os argumentos passados são válidos
	if (lista == NULL) return ERRO_ARGUMENTO_INVALIDO;

	// Aloca espaço na memória para o novo item
	Item_Lista* novoItem = (Item_Lista*)malloc(sizeof(Item_Lista));

	// Verifica se a alocação funcionou
	if (novoItem == NULL) return ERRO_ALOCACAO_MEMORIA;

	novoItem->DadosItem = ItemInserir;
	novoItem->anterior = NULL;

	if (ListaVazia(lista) == VERDADEIRO) {

		novoItem->proximo = lista->primeiro;
		lista->primeiro = lista->ultimo = novoItem;

		lista->Nitens++;

		return SUCESSO;
	}

	// Insere o novo item como o primeiro item da lista
	novoItem->proximo = lista->primeiro;
	lista->primeiro->anterior = novoItem;
	lista->primeiro = novoItem;
	// Incrementa o número de itens
	lista->Nitens++;

	// Se chegou aqui tudo funcionou :)
	return SUCESSO;
}

/*
* Função que insere item no fim da Lista
* @param Lista apontador para a lista onde o item será inserido
* @param TipoDado item que será inserido
* @return SUCESSO caso de certo, caso contrário retornará o codigo do ERRO
*/
Erros_t InsereNoFim(Lista* lista, TipoDado ItemInserir) {

	// Verifica se os argumentos passados são válidos
	if (lista == NULL) return ERRO_ARGUMENTO_INVALIDO;

	// Aloca espaço na memória para o novo item
	Item_Lista* novoItem = (Item_Lista*)malloc(sizeof(Item_Lista));

	// Verifica se a alocação funcionou
	if (novoItem == NULL) return ERRO_ALOCACAO_MEMORIA;

	novoItem->DadosItem = ItemInserir;

	if (ListaVazia(lista) == VERDADEIRO) {

		novoItem->proximo = lista->primeiro;
		lista->primeiro = lista->ultimo = novoItem;

		lista->Nitens++;

		return SUCESSO;
	}

	novoItem->anterior = lista->ultimo;
	lista->ultimo->proximo = novoItem;
	lista->ultimo = novoItem;
	novoItem->proximo = NULL;

	lista->Nitens++;

	// Se chegou aqui tudo funcionou :)
	return SUCESSO;
}

/*
* Função que insere de maneira ordenada na lista
* @param Lista apontador para a lista onde o item será inserido
* @param TipoDado item que será inserido
* @return SUCESSO caso tudo de certo, caso contrário retornará o codigo do ERRO
*/
Erros_t InsereOrdenado(Lista* lista, TipoDado ItemInserir) {

	// Verifica se a lista é válida
	if (lista == NULL) return ERRO_ARGUMENTO_INVALIDO;

	// Aloca espaço na memória para o novo item
	Item_Lista* novoItem = (Item_Lista*)malloc(sizeof(Item_Lista));

	// Verifica se a alocação funcionou
	if (novoItem == NULL) return ERRO_ALOCACAO_MEMORIA;

	novoItem->DadosItem = ItemInserir;
	bool_t ItemInserido = FALSO;

	// Caso a lista esteja vazia o item será inserido na primeira posição
	if (ListaVazia(lista) == VERDADEIRO) {

		// Insere o novo item como o primeiro item da lista
		novoItem->proximo = lista->primeiro;
		novoItem->anterior = NULL;
		lista->primeiro->anterior = novoItem;
		lista->primeiro = novoItem;
		// Incrementa o número de itens
		lista->Nitens++;

		// Se chegou aqui tudo funcionou :)
		return SUCESSO;

	}

	// Variaveis para auxiliar a navegação dentro da lista
	Item_Lista* atual = lista->primeiro;

	// Percorre a lista
	while (atual->proximo != NULL) {

		// Verifica se o item atual é maior ou igual ao item a ser inserido
		if (atual->DadosItem >= ItemInserir) {

			// Caso o item atual seja maior verifica se o item atual é o primeiro
			if (atual->anterior == NULL) {

				// Insere o novo item a primeira posição da lista e depois faz a linkagem
				novoItem->proximo = lista->primeiro;
				novoItem->anterior = NULL;
				lista->primeiro->anterior = novoItem;
				lista->primeiro = novoItem;
				ItemInserido = VERDADEIRO;
			}

			// Caso o item atual não seja o primeiro
			else
			{
				// Faz a linkagem entre os itens da lista
				atual->anterior->proximo = novoItem;
				novoItem->anterior = atual->anterior;
				atual->anterior = novoItem;
				novoItem->proximo = atual;
				ItemInserido = VERDADEIRO;
			}

			break;

		}

		// Percorre a lista
		atual = atual->proximo;
	}

	// Verifica se o item é maior do que todos os itens da lista caso seja ele será inserido no final
	if (ItemInserido == FALSO) {

		novoItem->anterior = lista->ultimo;
		lista->ultimo->proximo = novoItem;
		lista->ultimo = novoItem;
		novoItem->proximo = NULL;

	}

	// Incrementa o número de itens
	lista->Nitens++;

	// Se chegou aqui tudo funcionou :)
	return SUCESSO;

}

/*
* Função que procura um item especifico da lista
* @param Lista apontador para a lista que possui o item
* @param TipoDado item que será procurado
* @return SUCESSO caso tudo funcione, caso contrário retornará o codigo de ERRO
*/
Erros_t ProcuraItem(Lista* lista, TipoDado itemProcurado) {

	// Verifica se a lista é válida
	if (lista == NULL) return ERRO_ARGUMENTO_INVALIDO;

	// Verifica se a lista está vazia
	if (ListaVazia(lista) == VERDADEIRO) return ERRO_LISTA_VAZIA;

	Item_Lista* atual = lista->primeiro;
	bool_t ItemEncontrado = FALSO;
	unsigned int posicao = 0;

	// Percorre a lista
	while (atual->proximo != NULL) {

		posicao++;

		// Verifica se o item atual é o item procurado
		if (atual->DadosItem == itemProcurado) {

			// Atualiza o estado da variável
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
		printf("\nO item: %.02f não está na lista", itemProcurado);
		// Retorna o codigo de erro
		return ERRO_DADO_NAO_ENCONTRADO;
	}

	printf("O item: %.02f esta na Pos: %d", itemProcurado, posicao);

	// Se chegou aqui tudo funcionou :)
	return SUCESSO;
}

/*
* Função que remove um item da lista
* @param Lista apontador para a lista que possui o item
* @param TipoDado item que será removido
* @return SUCESSO caso tudo funcione, caso contrário retornará o codigo de ERRO
*/
Erros_t RemoveItem(Lista* lista, TipoDado ItemRemover) {

	// Verifica se a lista é válida
	if (lista == NULL) return ERRO_ARGUMENTO_INVALIDO;

	// Verifica se a lista está vazia
	if (ListaVazia(lista) == VERDADEIRO) return ERRO_LISTA_VAZIA;

	Item_Lista* atual = lista->primeiro;
	bool_t ItemEncontrado = FALSO;

	// Percorre a lista
	while (atual != NULL) {

		// Verifica se o item atual é o item a ser removido
		if (atual->DadosItem == ItemRemover) {

			// Atualiza o estado da váriavel
			ItemEncontrado = VERDADEIRO;
			// Sai do looping
			break;

		}

		// Atualiza a variável utilizadas para percorrer a lista
		atual = atual->proximo;

	}

	// Verifica se o item foi encontrado
	if (ItemEncontrado == FALSO) {

		// Imprime mensagem de ERRO
		printf("\n\tEsse item não existe na lista\n");
		// Retorna codigo de ERRO
		return ERRO_DADO_NAO_ENCONTRADO;
	}

	// Verifica se o item a ser removido é o primeiro
	if (atual->anterior == NULL) {

		if (atual == lista->ultimo) {

			lista->primeiro = lista->ultimo = NULL;
			free(atual);
			lista->Nitens--;

			return SUCESSO;
		}
		// Substitui o primeiro item pelo próximo
		lista->primeiro = atual->proximo;
		lista->primeiro->anterior = NULL;
		// Libera a memória usado pelo item a ser removido
		free(atual);

		// Decrementa a quantidade de itens que a lista possui
		lista->Nitens--;

		// Se chegou aqui tudo funcionou :)
		return SUCESSO;

	}

	// Faz a linkagem entre o item anterior e o item que está depois do item a ser removido
	atual->anterior->proximo = atual->proximo;
	// Libera a memória usada pelo item removido
	free(atual);

	// Decrementa a quantidade de itens da lista
	lista->Nitens--;

	// Se chegou aqui tudo funcionou :)
	return SUCESSO;
}

/*
* Função destinada a impressão dos itens da lista
* @param Lista apontador para a lista a ser impressa
* @return SUCESSO caso funcione, caso contrário retornará o codigo de ERRO
*/
Erros_t ImprimeLista(Lista* minhaLista) {

	// Verifica se a lista é válida
	if (minhaLista == NULL) return ERRO_ARGUMENTO_INVALIDO;

	// Verifica se a lista está vazia
	if (ListaVazia(minhaLista) == VERDADEIRO) return ERRO_LISTA_VAZIA;

	int i = 0;
	Item_Lista* atual = minhaLista->primeiro;

	printf("Lista com %d item(s)\n", minhaLista->Nitens);
	printf("Impressao da lista\n"\
		"------------------\n");

	// Percorre a lista
	while (atual != NULL) {

		printf("Pos: %d / Valor: %.02f\n", i + 1, atual->DadosItem);

		// incrementa o contador de posições
		i++;

		// Atualiza a variável utilizada para percorrer a lista
		atual = atual->proximo;

	}
	printf("------------------\n");

	// Se chegou aqui tudo funcionou :)
	return SUCESSO;
}

/*
* Função destinada a destruição da lista
* @param Lista apontador para a lista a ser destruida
* @return SUCESSO caso funcione, caso contrário retornará o codigo de ERRO
*/
Erros_t DestroiLista(Lista* minhaLista) {

	// Verifica se a lista é válida
	if (minhaLista == NULL) return ERRO_ARGUMENTO_INVALIDO;

	// Verifica se a lista está vazia
	if (ListaVazia(minhaLista) == VERDADEIRO) return ERRO_LISTA_VAZIA;

	Item_Lista* atual;
	Item_Lista* proximo = minhaLista->primeiro;

	// Percorre a lista
	while (proximo != NULL) {

		// Atualiza as variáveis utilizadas para percorrer a lista
		atual = proximo;
		proximo = atual->proximo;

		// Libera a memória dos itens da lista
		free(atual);
	}

	// Inicaliza a lista
	minhaLista->primeiro = minhaLista->ultimo = NULL;
	minhaLista->Nitens = 0;

	// Se chegou aqui tudo funcionou :)
	return SUCESSO;
}

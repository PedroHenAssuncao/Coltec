/**
* @file Main.c
* @brief Arquivo com a fun��o main
* @author Pedro Henrique Assun��o
* @date 2020-11-05
*/

/* Inclus�es */

#include "Erros.h"
#include "Lista.h"
#include "BuscaBin�ria.h"
#include "Usu�rio.h"
#include "Hash.h"
#include "Tipos.h"


int main() {

	Lista* lista;
	HashTable* table;

	// Teste Hash table

	//table = CriaTabela();

	//InsereTabela(table, NovosDados());
	//InsereTabela(table, NovosDados());
	//InsereTabela(table, NovosDados());

	//ImprimeColuna(table, 6);
	//ImprimeColuna(table, 7);
	//ImprimeColuna(table, 8);

	//RemoveTabela(table, NomeEscolhido());

	//ImprimeColuna(table, 6);
	//ImprimeColuna(table, 7);
	//ImprimeColuna(table, 8);

	//LiberaTabela(table);

	// Teste Busca Bin�ria

	lista = CriaLista();

	InsereOrdenado(lista, NovosDados());
	ImprimirDadosLista(lista);
	InsereOrdenado(lista, NovosDados());
	ImprimirDadosLista(lista);
	InsereOrdenado(lista, NovosDados());

	ImprimirDadosLista(lista);

	ImprimirDadosPessoa(BuscaDadoItem(lista, NomeEscolhido()));

	DestroiLista(lista);
}
/**
* @file Main.c
* @brief Arquivo com a função main
* @author Pedro Henrique Assunção
* @date 2020-11-05
*/

/* Inclusões */

#include "Erros.h"
#include "Lista.h"
#include "BuscaBinária.h"
#include "Usuário.h"
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

	// Teste Busca Binária

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
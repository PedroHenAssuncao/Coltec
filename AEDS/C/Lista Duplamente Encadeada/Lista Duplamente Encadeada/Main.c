/**
* @file		Testes.c
* @brief	Arquivo com os testes.
* @author	Pedro Henrique Assunção
* @date		2020-11-05
*/

/* Inclusões */

#include <stdlib.h>
#include "ListaDuplamenteEncadeada.h"
#include "Erros.h"
#include "Tipos.h"

int main() {

	Lista* lista = NULL;

	lista = CriaLista(lista);

	InsereInicio(lista, 2);
	InsereNoFim(lista, 3);
	ImprimeLista(lista);
	InsereOrdenado(lista, 1);
	ImprimeLista(lista);
	InsereOrdenado(lista, 4);
	ImprimeLista(lista);
	InsereOrdenado(lista, 2.5);

	ImprimeLista(lista);

	RemoveItem(lista, 3);

	ImprimeLista(lista);

	DestroiLista(lista);

	return 0;
}
/**
* @file		Main.c 
* @brief	Arquivo com os testes de Grafo.
* @author	Pedro Henrique Assunção
* @date		2020-11-12
*/

/* Inclusões */

#include <stdlib.h>
#include "Grafo.h"
#include "Tipos.h"
#include "Erros.h"
#include "ListaE.h"


int main() {

	Grafo* Grafo;

	Grafo = CriaGrafo(eEhDigrafo);

	if (Grafo == NULL) Grafo = CriaGrafo(eEhDigrafo);

	InsereInicioVertice(Grafo, ObtemDados());
	InsereInicioVertice(Grafo, ObtemDados());
	InsereInicioVertice(Grafo, ObtemDados());

	InserirUmaAresta(Grafo, 1, 2);

	ImprimeGrafo(Grafo);

	DestroiGrafo(Grafo);

	return SUCESSO;
}
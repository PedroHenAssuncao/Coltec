/**
* @file
* @brief
* @author
* @date
*/

/* Inclusões */

#include <stdio.h>
#include <stdlib.h>
#include "Structs.h"
#include "Hash.h"
#include "Perfil.h"
#include "ListaE.h"
#include "Interações.h"
#include "Relações.h"

int main() {

	HashTable* table = NULL;
	TipoDado* UserAtivo = NULL;
	TipoDado* PerfilVisitado = NULL;

	table = CriaTabela();

	NovoPerfil(NovosDados(), table);
	NovoPerfil(NovosDados(), table);

	ImprimeTable(table);

	UserAtivo = AtivarPerfil(table, stringAlvo());

	ImprimeTable(table);

	InsereNovaPostagem(UserAtivo->postagens, NovaPostagem());

	ImprimePostagens(UserAtivo);

	RemoverPostagem(UserAtivo->postagens, ID_Alvo());

	ImprimePostagens(UserAtivo->postagens);
}

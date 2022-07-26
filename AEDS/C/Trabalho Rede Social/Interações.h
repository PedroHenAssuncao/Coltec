/**
* @file		Intera��es.h
* @brief	Arquivo com as defini��es das fun��es usadas para intera��o
* @atuhor	Pedro Henrique Assun��o
* @date		2020-11-12
*/

#pragma once
#ifndef __intera��es_h__
#define __intera��es_h__

/* Inclus�es */

#include "Structs.h"

/* Constantes */

/* Tipos */

/* Fun��es Exportadas*/

TipoDado* NovosDados(void);
char* stringAlvo(void);
Post_t* NovaPostagem(void);
unsigned int ID_Alvo(void);
unsigned int NumPostagens(void);
TipoDado* StalkerProfissional(TipoDado* PerfilVisitando);
#endif // !__intera��es_h__

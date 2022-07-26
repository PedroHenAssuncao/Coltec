/**
* @file		Interações.h
* @brief	Arquivo com as definições das funções usadas para interação
* @atuhor	Pedro Henrique Assunção
* @date		2020-11-12
*/

#pragma once
#ifndef __interações_h__
#define __interações_h__

/* Inclusões */

#include "Structs.h"

/* Constantes */

/* Tipos */

/* Funções Exportadas*/

TipoDado* NovosDados(void);
char* stringAlvo(void);
Post_t* NovaPostagem(void);
unsigned int ID_Alvo(void);
unsigned int NumPostagens(void);
TipoDado* StalkerProfissional(TipoDado* PerfilVisitando);
#endif // !__interações_h__

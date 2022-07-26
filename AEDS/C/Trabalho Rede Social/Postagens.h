/**
* @file		Postagens.h
* @brief	Arquivo com as fun��es exportadas de manipula��o de postagens.
* @author	Pedro Henrique Assun��o
* @date		2020-11-12
*/

#pragma once
#ifndef __postagens_h__
#define __postagens_h__

/* Inclus�es */

#include "Structs.h"

/* Constantes */


/* Tipos */



/* Fun��es Exportadas*/

unsigned int ObtemIDPost(void);
Item_Post_t* ObtemPostagem(TipoDado* PerfilVisitado, unsigned int ID);
Erros_t ImprimePostagensDetalhadas(TipoDado* Perfil, unsigned int ID);
#endif // !__postagens_h__


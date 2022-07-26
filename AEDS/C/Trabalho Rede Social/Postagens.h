/**
* @file		Postagens.h
* @brief	Arquivo com as funções exportadas de manipulação de postagens.
* @author	Pedro Henrique Assunção
* @date		2020-11-12
*/

#pragma once
#ifndef __postagens_h__
#define __postagens_h__

/* Inclusões */

#include "Structs.h"

/* Constantes */


/* Tipos */



/* Funções Exportadas*/

unsigned int ObtemIDPost(void);
Item_Post_t* ObtemPostagem(TipoDado* PerfilVisitado, unsigned int ID);
Erros_t ImprimePostagensDetalhadas(TipoDado* Perfil, unsigned int ID);
#endif // !__postagens_h__


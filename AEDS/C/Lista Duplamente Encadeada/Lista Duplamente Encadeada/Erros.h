/**
* @file Erros.h
* @brief Arquivo com defini��o geral de erros
* @author Pedro Henrique Assun��o
* @date 2020-11-05
*/

#pragma once
#ifndef __ERROS_h__
#define __ERROS_h__

/* Inclus�es */

/* Tipos */

typedef unsigned int Erros_t;

/* Constantes */

// N�mero de erros gerais
#define NUMERO_ERROS_GERAIS     (32)
// Offset de erros gerais
#define ERROS_GERAIS_OFFSET     (0)

// Caso a opera��o funcione corretamente
#define SUCESSO                   (ERROS_GERAIS_OFFSET + 0)
// Erro que indica falha na aloca��o de memoria
#define ERRO_ALOCACAO_MEMORIA     (ERROS_GERAIS_OFFSET + 1)
// Erro que indica argumentos inv�lidos
#define ERRO_ARGUMENTO_INVALIDO   (ERROS_GERAIS_OFFSET + 2)
// Erro que indica uma lista vazia
#define ERRO_LISTA_VAZIA          (ERROS_GERAIS_OFFSET + 3)
// Erro que indica que um dado n�o foi encontrado
#define ERRO_DADO_NAO_ENCONTRADO  (ERROS_GERAIS_OFFSET + 4)

/* Fun��es Exportadas*/

#endif // __ERROS_h__

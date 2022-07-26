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
#define SUCESSO                             (ERROS_GERAIS_OFFSET + 0)
// Erro que indica falha na aloca��o de memoria
#define ERRO_ALOCACAO_MEMORIA               (ERROS_GERAIS_OFFSET + 1)
// Erro que indica argumentos inv�lidos
#define ERRO_ARGUMENTO_INVALIDO             (ERROS_GERAIS_OFFSET + 2)
// Erro que indica uma lista vazia
#define ERRO_LISTA_VAZIA                    (ERROS_GERAIS_OFFSET + 3)
// Erro que indica que um dado n�o foi encontrado
#define ERRO_DADO_NAO_ENCONTRADO            (ERROS_GERAIS_OFFSET + 4)
// Erro que indica que uma table Hash est� vazia
#define ERRO_TABELA_VAZIA                   (ERROS_GERAIS_OFFSET + 5)
// Erro que indica que a lista de postagens est� vazia
#define LISTA_POSTAGENS_VAZIA	            (ERROS_GERAIS_OFFSET + 6)
// Erro que indica que o nome est� em uso
#define ERRO_NOME_EM_USO                    (ERROS_GERAIS_OFFSET + 7)
// Erro que indica que voc� est� tentando se adicionar como amigo
#define ERRO_NAO_EH_POSSIVEL_SE_ADICIONAR   (ERROS_GERAIS_OFFSET + 8)
// Erro que indica que voc�s j� s�o amigos
#define ERRO_VOCES_JA_SAO_AMIGOS            (ERROS_GERAIS_OFFSET + 9)

/* Fun��es Exportadas*/

#endif // __ERROS_h__

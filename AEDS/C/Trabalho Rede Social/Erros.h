/**
* @file Erros.h
* @brief Arquivo com definição geral de erros
* @author Pedro Henrique Assunção
* @date 2020-11-05
*/

#pragma once
#ifndef __ERROS_h__
#define __ERROS_h__

/* Inclusões */

/* Tipos */

typedef unsigned int Erros_t;

/* Constantes */

// Número de erros gerais
#define NUMERO_ERROS_GERAIS     (32)
// Offset de erros gerais
#define ERROS_GERAIS_OFFSET     (0)

// Caso a operação funcione corretamente
#define SUCESSO                             (ERROS_GERAIS_OFFSET + 0)
// Erro que indica falha na alocação de memoria
#define ERRO_ALOCACAO_MEMORIA               (ERROS_GERAIS_OFFSET + 1)
// Erro que indica argumentos inválidos
#define ERRO_ARGUMENTO_INVALIDO             (ERROS_GERAIS_OFFSET + 2)
// Erro que indica uma lista vazia
#define ERRO_LISTA_VAZIA                    (ERROS_GERAIS_OFFSET + 3)
// Erro que indica que um dado não foi encontrado
#define ERRO_DADO_NAO_ENCONTRADO            (ERROS_GERAIS_OFFSET + 4)
// Erro que indica que uma table Hash está vazia
#define ERRO_TABELA_VAZIA                   (ERROS_GERAIS_OFFSET + 5)
// Erro que indica que a lista de postagens está vazia
#define LISTA_POSTAGENS_VAZIA	            (ERROS_GERAIS_OFFSET + 6)
// Erro que indica que o nome está em uso
#define ERRO_NOME_EM_USO                    (ERROS_GERAIS_OFFSET + 7)
// Erro que indica que você está tentando se adicionar como amigo
#define ERRO_NAO_EH_POSSIVEL_SE_ADICIONAR   (ERROS_GERAIS_OFFSET + 8)
// Erro que indica que vocês já são amigos
#define ERRO_VOCES_JA_SAO_AMIGOS            (ERROS_GERAIS_OFFSET + 9)

/* Funções Exportadas*/

#endif // __ERROS_h__

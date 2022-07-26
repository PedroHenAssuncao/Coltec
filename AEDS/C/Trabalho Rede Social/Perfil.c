/**
* @file     Perfil.c
* @brief    Arquivo com as implementações das fumções de manipulação de perfis.
* @author   Pedro Henrique Assunção
* @date     2020-11-12
*/

/* Inclusões */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Erros.h"
#include "Structs.h"
#include "ListaE.h"
#include "Hash.h"

/*
Função para obter o Identificador Unico de triagem
@param Void
@return Retorna um Int ID incrementado que representa o ID do novo paciente
*/
unsigned int ObtemID(void) {

    static unsigned int ID = 0;
    return ID++;
}

Erros_t NovoPerfil(TipoDado * novoDado, HashTable * table) {

    if ((novoDado == NULL) || table == NULL) return ERRO_ARGUMENTO_INVALIDO;

    unsigned int ColunaNovoPerfil;
    unsigned int Erro;
    Item_lista* aux = NULL;
    bool_t NomeDisponivel = FALSO;

    ColunaNovoPerfil = IdentificaColuna(novoDado->Nome);

    if (ColunaNovoPerfil > table->nColunas) NomeDisponivel = VERDADEIRO;

    else {

        aux = table->DadosTabela[ColunaNovoPerfil - 1];

        while (aux != NULL){

            if (strcmp(aux->DadosItem->Nome, novoDado->Nome) == 0) NomeDisponivel = FALSO;

            aux = aux->Proximo;
        }

        if (aux == NULL) NomeDisponivel = VERDADEIRO;

    }

    if (NomeDisponivel == VERDADEIRO) {

        Erro = InsereTabela(table, novoDado);

        if (Erro == SUCESSO) {

            ColunaNovoPerfil = IdentificaColuna(novoDado->Nome);

            if (table->DadosTabela[ColunaNovoPerfil - 1]->DadosItem->Nome == novoDado->Nome) {

                table->DadosTabela[ColunaNovoPerfil - 1]->DadosItem->Seguindo = InicializaListaArestas(table->DadosTabela[ColunaNovoPerfil - 1]->DadosItem->Seguindo);

                if (table->DadosTabela[ColunaNovoPerfil - 1]->DadosItem->Seguindo == NULL) return ERRO_ALOCACAO_MEMORIA;

                table->DadosTabela[ColunaNovoPerfil - 1]->DadosItem->postagens = IniciaInicializaListaPost(table->DadosTabela[ColunaNovoPerfil - 1]->DadosItem->postagens);

                if (table->DadosTabela[ColunaNovoPerfil - 1]->DadosItem->postagens == NULL) return ERRO_ALOCACAO_MEMORIA;
            }

            else {

                Item_lista* aux = table->DadosTabela[ColunaNovoPerfil - 1];

                while (aux != NULL) {

                    if (strcmp(aux->DadosItem->Nome, novoDado->Nome) == 0) break;

                    aux = aux->Proximo;
                }

                if (aux == NULL) ERRO_DADO_NAO_ENCONTRADO;

                else {
                    aux->DadosItem->Seguindo = InicializaListaArestas(aux->DadosItem->Seguindo);

                    if (aux->DadosItem->Seguindo == NULL) return ERRO_ALOCACAO_MEMORIA;

                    aux->DadosItem->postagens = IniciaInicializaListaPost(aux->DadosItem->postagens);

                    if (aux->DadosItem->postagens == NULL) return ERRO_ALOCACAO_MEMORIA;
                }

            }
        }

        else return ERRO_ALOCACAO_MEMORIA;
    }

    else return ERRO_NOME_EM_USO;

    return SUCESSO;
}

Erros_t RemoverPerfil(char* QuemRemover, HashTable* table) {
    
    if (table == NULL) return ERRO_ARGUMENTO_INVALIDO;

    unsigned int ColunaDoItem = IdentificaColuna(QuemRemover);
    Item_lista* atual, *proximo;
    unsigned int i, count = 0;

    for ( i = 0; i < ColunaDoItem; i++){

        if (table->DadosTabela[i] == NULL) count++;
        
    }

    if (count == table->nColunas) return ERRO_TABELA_VAZIA;

    
    if (table->DadosTabela[ColunaDoItem - 1] == NULL) return ERRO_DADO_NAO_ENCONTRADO;

    if (table->DadosTabela[ColunaDoItem - 1]->Proximo != NULL) {

        proximo = table->DadosTabela[ColunaDoItem - 1];

        while (proximo != NULL){

            atual = proximo;
            proximo = atual->Proximo;
            if (strcmp(atual->DadosItem->Nome, QuemRemover) == 0) {

                RemoveTabela(table, QuemRemover);
            }
        }
    }

    else {

        if (strcmp(table->DadosTabela[ColunaDoItem - 1]->DadosItem->Nome, QuemRemover) == 0) {

            RemoveTabela(table, QuemRemover);
        }

        else return ERRO_DADO_NAO_ENCONTRADO;
    }

   

    return SUCESSO;
}

TipoDado* AtivarPerfil(HashTable * table, char * QuemAtivar) {

    Item_lista* aux;
    bool_t DadoEncontrado = FALSO;
    unsigned int Coluna;

    Coluna = IdentificaColuna(QuemAtivar);

    unsigned int i, count = 0;

    for (i = 0; i < Coluna; i++) {

        if (table->DadosTabela[i] == NULL) count++;

    }

    if (count == table->nColunas) return NULL;

    if (table->DadosTabela[Coluna - 1] == NULL) return NULL;

    else {
        aux = table->DadosTabela[Coluna - 1];
        while (aux != NULL) {

            if (strcmp(aux->DadosItem->Nome, QuemAtivar) == 0) {

                DadoEncontrado = VERDADEIRO;

                break;
            }

            aux = aux->Proximo;
        }

        if (DadoEncontrado == VERDADEIRO) return aux->DadosItem;

        else return NULL;
    }
}

/**
* @file     Postagens.c
* @brief    Arquivo com as implementa��es das fun��es de manipula��o de postagens
* @author   Pedro Henrique Assun��o
* @date     2020-11-12
*/

/* Inclus�es */

#include <stdio.h>
#include <stdlib.h>
#include "Erros.h"
#include "Tipos.h"
#include "Structs.h"
#include "ListaE.h"
#include "Hash.h"


/*
Fun��o para obter o Identificador Unico de triagem
@param Void
@return Retorna um Int ID incrementado que representa o ID do novo paciente
*/
unsigned int ObtemIDPost(void) {

    static unsigned int ID = 0;
    return ID++;
}

/**
* Fun��o que busca uma postagem pelo Id dela
* @param TipoDado apontador para o perfil onde est� a postagem
* @param Unsigned Int que armazena o ID da postagem a ser Buscada
* @return Endere�o da postagem buscada caso de certo, caso contr�rio retornar� NULL
*/
Item_Post_t* ObtemPostagem(TipoDado * PerfilVisitado, unsigned int ID) {

    Item_Post_t* aux = PerfilVisitado->postagens->Primeira;
    Erros_t DadoEncontrado = FALSO;

    while (aux != NULL){

        if (aux->DadosItem->ID == ID) {
            
            DadoEncontrado = VERDADEIRO;
            break;
        }

        aux = aux->proximo;
    }

    if (DadoEncontrado == VERDADEIRO) return aux;

    else return NULL;
}

/**
* Fun��o que imprime de maneira detalhada uma postagem
* @param TipoDado apontador para o perfil que contem a postagem a ser imprimida
* @param Unsigned Int que armazena o ID da postagem que ser� impressa
* @return SUCESSO caso de certo, caso contr�rio retornar� o codigo de erro
*/
Erros_t ImprimePostagensDetalhadas(TipoDado* Perfil, unsigned int ID) {

    if (Perfil == NULL) return ERRO_ARGUMENTO_INVALIDO;

    if (Perfil->postagens->nItens == 0) return LISTA_POSTAGENS_VAZIA;

    bool_t DadoEncontrado = FALSO;

    if (Perfil->postagens != NULL) {

        Item_Post_t* Imprime = Perfil->postagens->Primeira;

        printf("\n\n\tImprimindo uma postagem detalhada de %s\n\n", Perfil->Nome);
        while (Imprime != NULL) {

            if (Imprime->DadosItem->ID == ID) {

                DadoEncontrado = VERDADEIRO;
                break;
            }

            Imprime = Imprime->proximo;
        }

        if (DadoEncontrado == VERDADEIRO) {

            printf("\nID da postagem....: %d", Imprime->DadosItem->ID);
            printf("\n%.50s", Imprime->DadosItem->postagem);
            printf("\nNumero de curtidas: %d", Imprime->DadosItem->nCurtidas);

            printf("\n\tQuem curtiu: \n");

            ImprimeTable(Imprime->DadosItem->curtidas);

        }

        else return ERRO_DADO_NAO_ENCONTRADO;
    }

    else return LISTA_POSTAGENS_VAZIA;

    return SUCESSO;
}

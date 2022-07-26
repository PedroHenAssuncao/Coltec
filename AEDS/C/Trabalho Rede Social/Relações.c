/**
* @file     Rela��es.c
* @brief    Arquivo com as implementa��es de manipula��o de rela��es.
* @author   Pedro Henrique Assun��o
* @date     2020-11-12
*/

/* Inclus�es */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Tipos.h"
#include "Erros.h"
#include "Structs.h"
#include "ListaE.h"
#include "Hash.h"

/**
* Fun��o que une fun��es de inser��o e inicializa��o com o proposito de adicionar um novo amigo na lista
* @param TipoDado apontador para o perfil que ter� o amigo adiconado
* @param HashTable apontador para a tabela que contem os perfis
* @param char apontador para uma string que cont�m o nome do novo amigo
* @return SUCESSO caso tudo de certo, caso contr�rio retornar� o codigo de erro
*/
Erros_t AdicionarAmigo(TipoDado* PerfilAtivo, HashTable* table, char* NovoAmigo) {

    if (PerfilAtivo == NULL || table == NULL) return ERRO_ARGUMENTO_INVALIDO;

    unsigned int Coluna = IdentificaColuna(NovoAmigo);
    bool_t DadoEncontrado = FALSO;
    Item_lista* aux;
    Item_lista* auxiliar = PerfilAtivo->Seguindo->primeiro;

    if (table->DadosTabela[Coluna - 1] == NULL) return ERRO_DADO_NAO_ENCONTRADO;

    if (Coluna > table->nColunas) return ERRO_DADO_NAO_ENCONTRADO;

    if (strcmp(PerfilAtivo->Nome, NovoAmigo) == 0) return ERRO_NAO_EH_POSSIVEL_SE_ADICIONAR;

    else {

        aux = table->DadosTabela[Coluna - 1];

        while (aux != NULL) {

            if (strcmp(aux->DadosItem->Nome, NovoAmigo) == 0) { // Se digitar nome que n�o existe da seg fault aqui


                DadoEncontrado = VERDADEIRO;
                break;
            }

            aux = aux->Proximo;
        }

        if (PerfilAtivo->Seguindo->Seguidores != 0) {

            while (auxiliar != NULL) {

                if (aux == NULL) break;

                if (strcmp(auxiliar->DadosItem->Nome, aux->DadosItem->Nome) == 0) return ERRO_VOCES_JA_SAO_AMIGOS;

                auxiliar = auxiliar->Proximo;
            }
        }

        else if (DadoEncontrado == VERDADEIRO) {

            InsereInicioListaArestas(PerfilAtivo->Seguindo, aux);
        }

        else return ERRO_DADO_NAO_ENCONTRADO;
    }

    return SUCESSO;
}

/**
* Fun��o que une fun��es de remo��o e libera��o com o proposito de remover um amigo da lista de amigos
* @param TipoDado apontador para o perfil que ter� o amigo excluido
* @param HashTable apontador para a tabela contendo todos os perfis
* @param char apontador para a string que contem o nome do amigo que ser� removido
* @return SUCESSO caso tudo de certo, caso contr�rio retornar� o codigo de erro
*/
Erros_t RemoverAmigo(TipoDado* PerfilAtivo, HashTable* table, char* AmigoRemover) {

    if (PerfilAtivo == NULL || table == NULL) return ERRO_ARGUMENTO_INVALIDO;

    unsigned int Coluna = IdentificaColuna(AmigoRemover);
    bool_t DadoEncontrado = FALSO;
    Item_lista* aux;

    if (table->DadosTabela[Coluna - 1] == NULL) return ERRO_DADO_NAO_ENCONTRADO;

    else {

        aux = table->DadosTabela[Coluna - 1];

        while (aux != NULL) {

            if (strcmp(aux->DadosItem->Nome, AmigoRemover) == 0) {

                DadoEncontrado = VERDADEIRO;
                break;
            }

            aux = aux->Proximo;
        }

        if (DadoEncontrado == VERDADEIRO) {

            RemoveListaAresta(PerfilAtivo->Seguindo, aux->DadosItem);
        }

        else return ERRO_DADO_NAO_ENCONTRADO;
    }

    return SUCESSO;
}

/**
* Fun��o que imprime a lista de amigos
* @param TipoDado apontador para o perifl que ter� sua lista de amigos impressa
* @return SUCESSO caso tudo de certo, caso contr�rio retornar� o codigo de erro
*/
Erros_t ImprimeListaAmigos(TipoDado* PerfilAtivo) {

    if (PerfilAtivo == NULL) return ERRO_ARGUMENTO_INVALIDO;

    Item_lista* Imprime = PerfilAtivo->Seguindo->primeiro;

    if (PerfilAtivo->Seguindo->Seguidores == 0) return ERRO_LISTA_VAZIA;

    printf("\n\tImprimindo Lista de Amigos\n\n");
    while (Imprime != NULL) {

        printf("\nNome: %-30s   ID: %d\n", Imprime->DadosItem->Nome, Imprime->DadosItem->ID);
        printf("Email: %-30s\n", Imprime->DadosItem->Email);

        Imprime = Imprime->Proximo;
    }

    return SUCESSO;
}

/**
* Fun��o que busca um perfil na lista de amigos do perfil ativo no momento
* @param TipoDado apontador para o perfil cujo o amigo que ser� visitado pertence
* @param char apontador para a string que armazena o nome do amigo que ser� visitado
* @return Endere�o do amigo que ser� visitado caso de certo, caso contr�rio retornar� NULL
*/
TipoDado* VisitarPerfil(TipoDado * PerfilAtivo, char * QuemVisitar) {

    if (PerfilAtivo == NULL) return NULL;

    if (strcmp(PerfilAtivo->Nome, QuemVisitar) == 0) return NULL;

    bool_t DadoEncontrado = FALSO;
    Item_lista* aux = PerfilAtivo->Seguindo->primeiro;
    TipoDado* PerfilVisitar = NULL;

    while (aux != NULL){

        if (strcmp(aux->DadosItem->Nome, QuemVisitar) == 0) {

            DadoEncontrado = VERDADEIRO;
            break;
        }

        aux = aux->Proximo;
    }

    if (DadoEncontrado == VERDADEIRO) {

        PerfilVisitar = aux->DadosItem;
        return PerfilVisitar;
    }

    else return NULL;
}

/**
* Fun��o que imprime as N ultimas postagens do perfil escolhido e se o perfil ativo no momento curtiu ou n
* @param TipoDado apontador para o perfil que se deseja ver se curtiu ou n algumas das postagens
* @param TipoDado apontador para o perfil que ter� suas postagens impressas
* @param unsigned int que armazena o n�mero de postagens que ser�o impressas
* @return SUCESSO caso tudo de certo, caso contr�rio retornar� o codigo de erro
*/
Erros_t ImprimirNultimasPostagens(TipoDado * PerfilAtivo, TipoDado * PerfilVisitado, unsigned int Npostagens){
    
    if (PerfilVisitado == NULL || PerfilAtivo == NULL || Npostagens == 0) return ERRO_ARGUMENTO_INVALIDO;

    

    unsigned int i;
    unsigned int Coluna = IdentificaColuna(PerfilAtivo->Nome);
    bool_t DadoEncontrado = FALSO;

    Item_Post_t* Imprime = PerfilVisitado->postagens->Primeira;
    Item_lista* aux;

    printf("\n\tImprimindo postagens: \n");
    for ( i = 0; i < Npostagens; i++){

        if (Imprime == NULL) break;

        printf("\nID da postagem....: %d", Imprime->DadosItem->ID);
        printf("\n%s", Imprime->DadosItem->postagem);
        printf("\nNumero de curtidas: %d", Imprime->DadosItem->nCurtidas);

        if (Imprime->DadosItem->nCurtidas == 0 || Imprime->DadosItem->curtidas->nColunas < (Coluna - 1)) printf("\n\tVoc� n�o curtiu essa postagem\n");

        else if (Imprime->DadosItem->curtidas->DadosTabela[Coluna - 1] == NULL) printf("\n\tVoc� n�o curtiu essa postagem\n");

        else {

            if (Imprime->DadosItem->curtidas->DadosTabela[Coluna - 1]->Proximo != NULL) {

                aux = Imprime->DadosItem->curtidas->DadosTabela[Coluna - 1];

                while (aux != NULL){

                    if (strcmp(aux->DadosItem->Nome, PerfilAtivo->Nome) == 0) {

                        DadoEncontrado = VERDADEIRO;
                        break;
                    }

                    else aux = aux->Proximo;
                }

                if (DadoEncontrado == VERDADEIRO) printf("\n\tVoc� curtiu essa postagem\n\n");

                else  printf("\n\tVoc� n�o curtiu essa postagem\n");
            }

            else printf("\n\tVoc� curtiu essa postagem\n\n");
        }

        Imprime = Imprime->proximo;

    }

    return SUCESSO;
}
/**
* @file		BuscaBinária.c
* @brief	Arquivo com as implementações de BuscaBinária.
* @author	Pedro Henrique Assunção
* @date		2020-11-05
*/

/* Inclusões */

#include <stdio.h>
#include <stdlib.h>
#include "Hash.h"
#include "Erros.h"
#include "Tipos.h"
#include "Lista.h"

DataType ** CriaVetorDePonteiros(Lista * lista){
	
	if (lista == NULL) return NULL;

	DataType** Vetor = (DataType**)malloc(sizeof(DataType*) * lista->nItens);

	if (Vetor == NULL) return NULL;

	unsigned int i;
	Item_lista* DadosParaCopiar = lista->Primeiro;

	for ( i = 0; i < lista->nItens ; i++){

		Vetor[i] = DadosParaCopiar->DadosItem;
		DadosParaCopiar = DadosParaCopiar->Proximo;

	}
	
	return Vetor;
}

Erros_t InsereOrdenado(Lista* lista, DataType* dadosItem) {
 
    if (lista == NULL) return ERRO_ARGUMENTO_INVALIDO;

    unsigned int i;
    Item_lista* DadosLista = lista->Primeiro;
    Item_lista* NovoItem = (Item_lista*)malloc(sizeof(Item_lista));

    if (NovoItem == NULL) return ERRO_ALOCACAO_MEMORIA;

    bool_t ItemInserido = FALSO;
    int SomaCaracteres = IdentificaColuna(dadosItem->Nome);
    NovoItem->DadosItem = dadosItem;

    for (i = 0; i < lista->nItens; i++) {
        if (DadosLista != NULL) {
            if (SomaCaracteres <= IdentificaColuna(DadosLista->DadosItem->Nome)) {
                if (DadosLista->Proximo != NULL) {
                    if (DadosLista->Anterior != NULL) {
                        DadosLista->Anterior->Proximo = NovoItem;
                        NovoItem->Anterior = DadosLista->Anterior;
                    }
                    else {
                        NovoItem->Proximo = DadosLista;
                        DadosLista->Anterior = NovoItem;
                        lista->Primeiro = NovoItem;
                        NovoItem->Anterior = NULL;
                    }
                    DadosLista->Anterior = NovoItem;
                }
                else {
                    DadosLista->Proximo = NovoItem;
                    NovoItem->Anterior = DadosLista;
                    NovoItem->Proximo = NULL;
                }
                ItemInserido = VERDADEIRO;
            }
            break;
        }
        DadosLista = DadosLista->Proximo;
    }

    if (ItemInserido == FALSO && lista->nItens == 0) {
        NovoItem->Anterior = NULL;
        NovoItem->Proximo = NULL;
        lista->Primeiro = NovoItem;
        lista->Ultimo = NovoItem;
    }
    else if (ItemInserido == VERDADEIRO) {
        lista->Ultimo->Proximo = NovoItem;
        NovoItem->Anterior = lista->Ultimo;
        NovoItem->Proximo = NULL;
        lista->Ultimo = NovoItem;
    }
    lista->nItens++;

    return SUCESSO;
}

Erros_t ImprimirDadosLista(Lista* lista) {

    if (ListaVazia(lista) == VERDADEIRO) return ERRO_LISTA_VAZIA;

    Item_lista* aux = lista->Primeiro;
    
    printf("\n\t Imprimindo dados da lista \n");
    printf("%-25s %s\n", "Nome:", "Telefone:");
    
    while (aux != NULL) {

        printf("%-25s %d\n", aux->DadosItem->Nome, aux->DadosItem->Telefone);

        aux = aux->Proximo;
    }

    printf("\n");

    return SUCESSO;
}

Erros_t ImprimirDadosPessoa(DataType* dados) {

    if (dados == NULL) return ERRO_DADO_NAO_ENCONTRADO;

    printf("\nNome: %-25s   Telefone: %d\n", dados->Nome, dados->Telefone);
    printf("Rua: %-25s    Numero: %.4d\n", dados->Endereco->Rua, dados->Endereco->numero);
    printf("Bairro: %-25s Cidade: %-25s\n\n", dados->Endereco->Bairro, dados->Endereco->Cidade);

    return SUCESSO;
}

DataType* BuscaDadoItem(Lista* lista, char procurado[TAMANHO_MAXIMO_STRING]) {
    
    DataType** Vetor = CriaVetorDePonteiros(lista);

    if (Vetor == NULL) return NULL;

    int inicio, fim, meio;
    int SomaCharProcurado = IdentificaColuna(procurado);

    inicio = 0;
    fim = lista->nItens - 1;

    while (inicio <= fim) {
        meio = (inicio + fim) / 2;
        if (SomaCharProcurado < IdentificaColuna(Vetor[meio]->Nome)) {
            fim = meio - 1;
        }
        else if (SomaCharProcurado > IdentificaColuna(Vetor[meio]->Nome)) {
            inicio = meio + 1;
        }
        else if (SomaCharProcurado == IdentificaColuna(Vetor[meio]->Nome)) {
            return Vetor[meio];
        }
    }

    return NULL;
}
/**
* @file		Interação.c
* @brief	Arquivo com a implementação das funções de interação usuario software.
* @author	Pedro Henrique Assunção
* @date		2020-11-12
*/

/* Inclusões */

#include <stdio.h>
#include <stdlib.h>
#include "Structs.h"
#include "Perfil.h"
#include "Postagens.h"
#include "Relações.h"

// Desibilita o warning que diz que o strcpy e o scanf são inseguros
#pragma warning(disable: 4996)

/**
* Função que le do teclado as informações referentes a um novo perfil
* @param Void
* @return Endereço do novo dado caso de certo, caso contrário retornará NULL
*/
TipoDado* NovosDados(void) {

	TipoDado* novoDado = (TipoDado*)malloc(sizeof(TipoDado));

	if (novoDado == NULL) return NULL;

	setbuf(stdin, NULL);
	printf("\nDigite o seu nome de usuário: ");
	fgets(novoDado->Nome, TAMANHO_MAXIMO_STRING, stdin);
	setbuf(stdin, NULL);
	printf("\nDigite o seu Email: ");
	fgets(novoDado->Email, TAMANHO_MAXIMO_STRING, stdin);
	setbuf(stdin, NULL);

	novoDado->ID = ObtemID();

	return novoDado;
}

/**
* Função que le do teclado uma string que será usada posteriormente
* @param Void
* @return Endereço da nova string caso de certo, caso contrário retornará NULL
*/
char* stringAlvo(void) {

	char *NomeDesejado = (char*)malloc(sizeof(char)*TAMANHO_MAXIMO_STRING);

	if (NomeDesejado == NULL) return NULL;

	setbuf(stdin, NULL);
	printf("\nDigite o nome da pessoa: ");
	fgets(NomeDesejado, TAMANHO_MAXIMO_STRING, stdin);
	setbuf(stdin, NULL);

	return NomeDesejado;
}

/**
* Função que le do teclado informações referentes a uma nova postagem
* @param Void
* @return Endereço dos dados da nova postagem caso de certo, caso contrário retornará NULL
*/
Post_t* NovaPostagem(void) {

	Post_t* novoPost = (Post_t*)malloc(sizeof(Post_t));

	if (novoPost == NULL) return NULL;

	setbuf(stdin, NULL);
	printf("\nEscreva no que está pensando agora: ");
	fgets(novoPost->postagem, TAMANHO_MAXIMO_STRING, stdin);
	setbuf(stdin, NULL);

	novoPost->ID = ObtemIDPost();

	novoPost->nCurtidas = 0;

	novoPost->curtidas = (HashTable*)malloc(sizeof(HashTable));

	if (novoPost->curtidas == NULL) return NULL;

	novoPost->curtidas->nColunas = 0;
	novoPost->curtidas->DadosTabela = NULL;

	return novoPost;
}

/**
* Função que le do teclado um inteiro que corresponde ao ID
* @param Void
* @return Unsigned int que armazena o ID lido do teclado
*/
unsigned int ID_Alvo(void){
	
	unsigned int ID_desejado;

	printf("\nDigite o ID desejado: ");
	(void)scanf("%d", &ID_desejado);

	return ID_desejado;
}

/**
* Função que le do teclado um valor que corresponde ao número de postagens que serão imprimidas
* @param Void
* @return Unsigned int que armazena o número de postagens
*/
unsigned int NumPostagens(void) {

	unsigned int Npost;

	printf("\nDigite o número de postagens que deseja ver: ");
	(void)scanf("%d", &Npost);

	return Npost;
}

/**
* Função que identifica o novo perfil que será visitado
* @param TipoDado apontador para o perfil onde está contido a lista de amigos que
		 será usada para identificar o endereço do perfil que será visitado a seguir
* @return Endereço do perfil que será visitado caso de certo, caso contrário retornará NULL
*/
TipoDado * StalkerProfissional(TipoDado * PerfilVisitando) {

	Erros_t Erro;
	TipoDado* aux = NULL;
	TipoDado* PerfilVisitado = NULL;

	printf("\n\t+----------------------------------------------+");
	printf("\n\t| BEM VINDO A FUNÇÃO DE STALKER PROFISSIONAL   |");
	printf("\n\t| ESCOLHA UM PERFIL PARA STALKEAR              |");
	printf("\n\t+----------------------------------------------+\n\n");

	Erro = ImprimeListaAmigos(PerfilVisitando);

	if (Erro == ERRO_LISTA_VAZIA) {

		printf("\n\t+----------------------------------------------+");
		printf("\n\t| PARECE QUE VOCÊ NÃO TEM AMIGOS PARA STALKEAR |");
		printf("\n\t+----------------------------------------------+\n\n");
	}

	else if (Erro == SUCESSO) {

		aux = VisitarPerfil(PerfilVisitando, stringAlvo());

		if (aux == NULL) {

			printf("\n\t+------------------------------------------------+");
			printf("\n\t| OPS... PARECE QUE ALGUM ERRO RESOLVEU APARECER |");
			printf("\n\t+------------------------------------------------+\n\n");
		}

		else {

			printf("\n\t+-------------------------------------+");
			printf("\n\t| MODO STALKER ATIVADO COM SUCESSO!!! |");
			printf("\n\t+-------------------------------------+\n\n");

			PerfilVisitado = aux;

			return PerfilVisitado;
			
		}

	}

	return PerfilVisitado;
}
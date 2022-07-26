/**
* @file		Intera��o.c
* @brief	Arquivo com a implementa��o das fun��es de intera��o usuario software.
* @author	Pedro Henrique Assun��o
* @date		2020-11-12
*/

/* Inclus�es */

#include <stdio.h>
#include <stdlib.h>
#include "Structs.h"
#include "Perfil.h"
#include "Postagens.h"
#include "Rela��es.h"

// Desibilita o warning que diz que o strcpy e o scanf s�o inseguros
#pragma warning(disable: 4996)

/**
* Fun��o que le do teclado as informa��es referentes a um novo perfil
* @param Void
* @return Endere�o do novo dado caso de certo, caso contr�rio retornar� NULL
*/
TipoDado* NovosDados(void) {

	TipoDado* novoDado = (TipoDado*)malloc(sizeof(TipoDado));

	if (novoDado == NULL) return NULL;

	setbuf(stdin, NULL);
	printf("\nDigite o seu nome de usu�rio: ");
	fgets(novoDado->Nome, TAMANHO_MAXIMO_STRING, stdin);
	setbuf(stdin, NULL);
	printf("\nDigite o seu Email: ");
	fgets(novoDado->Email, TAMANHO_MAXIMO_STRING, stdin);
	setbuf(stdin, NULL);

	novoDado->ID = ObtemID();

	return novoDado;
}

/**
* Fun��o que le do teclado uma string que ser� usada posteriormente
* @param Void
* @return Endere�o da nova string caso de certo, caso contr�rio retornar� NULL
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
* Fun��o que le do teclado informa��es referentes a uma nova postagem
* @param Void
* @return Endere�o dos dados da nova postagem caso de certo, caso contr�rio retornar� NULL
*/
Post_t* NovaPostagem(void) {

	Post_t* novoPost = (Post_t*)malloc(sizeof(Post_t));

	if (novoPost == NULL) return NULL;

	setbuf(stdin, NULL);
	printf("\nEscreva no que est� pensando agora: ");
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
* Fun��o que le do teclado um inteiro que corresponde ao ID
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
* Fun��o que le do teclado um valor que corresponde ao n�mero de postagens que ser�o imprimidas
* @param Void
* @return Unsigned int que armazena o n�mero de postagens
*/
unsigned int NumPostagens(void) {

	unsigned int Npost;

	printf("\nDigite o n�mero de postagens que deseja ver: ");
	(void)scanf("%d", &Npost);

	return Npost;
}

/**
* Fun��o que identifica o novo perfil que ser� visitado
* @param TipoDado apontador para o perfil onde est� contido a lista de amigos que
		 ser� usada para identificar o endere�o do perfil que ser� visitado a seguir
* @return Endere�o do perfil que ser� visitado caso de certo, caso contr�rio retornar� NULL
*/
TipoDado * StalkerProfissional(TipoDado * PerfilVisitando) {

	Erros_t Erro;
	TipoDado* aux = NULL;
	TipoDado* PerfilVisitado = NULL;

	printf("\n\t+----------------------------------------------+");
	printf("\n\t| BEM VINDO A FUN��O DE STALKER PROFISSIONAL   |");
	printf("\n\t| ESCOLHA UM PERFIL PARA STALKEAR              |");
	printf("\n\t+----------------------------------------------+\n\n");

	Erro = ImprimeListaAmigos(PerfilVisitando);

	if (Erro == ERRO_LISTA_VAZIA) {

		printf("\n\t+----------------------------------------------+");
		printf("\n\t| PARECE QUE VOC� N�O TEM AMIGOS PARA STALKEAR |");
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
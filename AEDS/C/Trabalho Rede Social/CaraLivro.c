/**
* @file		CaraLivro.c
* @brief	Arquivo com a união dos modulos de controle
* @author	Pedro Henrirque Assunção
* @date		2020-11-16
*/

/* Inclusões */

#include <stdio.h>
#include <stdlib.h>
#include "Structs.h"
#include "Hash.h"
#include "Perfil.h"
#include "ListaE.h"
#include "Interações.h"
#include "Relações.h"
#include "Postagens.h"

// Desabilita o Erro que diz que o Scanf é inseguro
#pragma warning(disable: 4996)

/*  Constantes */

#define FECHAR_PROGRAMA (0)


int main() {

	unsigned int OpcaoEscolhida = 0;
	unsigned int IdPostagem;
	Erros_t Erro;
	HashTable* TabelaComPerfisCadastrados = NULL;
	TipoDado* PerfilAtivo = NULL;
	TipoDado* PerfilVisitado = NULL;
	TipoDado* aux = NULL;
	Item_Post_t* postaux = NULL;

	TabelaComPerfisCadastrados = CriaTabela();

	printf("\t+-----------------------------------+\n");
	printf("\t| BEM VINDO AO FACEBOOK DO PARAGUAI |\n");
	printf("\t+-----------------------------------+\n\n");


	do{

        printf("+-----------------------------+\n");
        printf("| Funcionalidades do software |\n");
        printf("+-----------------------------+\n");
        printf("[00] Encerrar.\n");
        printf("[01] Ativar um perfil.\n");
        printf("[02] Criar perfil.\n");
        printf("[03] Deletar perfil.\n");
        printf("[04] Imprimir todos os perfis.\n");
        printf("Escolha: ");
        (void)scanf("%d", &OpcaoEscolhida);

		switch (OpcaoEscolhida){
		case 0:

			printf("\n\n\t+-----------------------------------------+");
			printf("\n\t|   ATÉ LOGO, ESPERO VER VOCÊ NOVAMENTE   |");
			printf("\n\t+-----------------------------------------+\n\n");
			break;
		case 1:

			if (TabelaComPerfisCadastrados->nColunas == 0) {

				printf("\n\n\t+---------------------------------------------+");
				printf("\n\t| OPS... PARECE QUE NÃO HÁ PERFIS CADASTRADOS |");
				printf("\n\t| DESEJA CADASTRAR ALGUM?                     |");
				printf("\n\t| [01] SIM     [00] NÃO                       |");
				printf("\n\t+---------------------------------------------+");
				printf("\nEscolha: ");
				(void)scanf("%d", &OpcaoEscolhida);

				if (OpcaoEscolhida == 1) NovoPerfil(NovosDados(), TabelaComPerfisCadastrados);

				else OpcaoEscolhida = !FECHAR_PROGRAMA;

			}

			else {

				ImprimeTable(TabelaComPerfisCadastrados);

				printf("\n\t+--------------------------------------+");
				printf("\n\t| ESCOLHA UM DESSES PERFIS PARA ATIVAR |");
				printf("\n\t+--------------------------------------+\n\n");

				aux = AtivarPerfil(TabelaComPerfisCadastrados, stringAlvo());

				if (aux == NULL) {

					printf("\n\t+-------------------------------------------+");
					printf("\n\t| OPS... PARECE QUE NÃO EXISTE ESSE USUÁRIO |");
					printf("\n\t+-------------------------------------------+\n\n");
				}

				else {

					printf("\n\t+----------------------------------+");
					printf("\n\t| PERFIL ATIVADO COM SUCESSO!!! :) |");
					printf("\n\t+----------------------------------+\n\n");

					PerfilAtivo = aux;

					do{

						printf("+----------------------------------------------+\n");
						printf("| FUNCIONALIDADES DISPONIVEIS COM PERFIL ATIVO |\n");
						printf("+----------------------------------------------+\n");
						printf("[00] Voltar ao menu principal.\n");
						printf("[01] Exibir lista de amigos.\n");
						printf("[02] Adicionar um amigo.\n");
						printf("[03] Desfazer amizade.\n");
						printf("[04] Navegar no perfil de um amigo.\n");
						printf("[05] Exibir todas as suas postagens.\n");
						printf("[06] Exibir suas N ultimas postagens.\n");
						printf("[07] Fazer uma nova postagem.\n");
						printf("[08] Excluír uma postagem.\n");
						printf("[09] Deixar de curtir uma postagem.\n");
						printf("Escolha: ");
						(void)scanf("%d", &OpcaoEscolhida);

						switch (OpcaoEscolhida){

						case 0:

							printf("\n\t+----------------------------+");
							printf("\n\t| VOLTANDO AO MENU PRINCIPAL |");
							printf("\n\t+----------------------------+\n\n");

							break;

						case 1:

							Erro = ImprimeListaAmigos(PerfilAtivo);

							if (Erro == ERRO_ARGUMENTO_INVALIDO) {

								printf("\n\t+----------------------------------------------------------------------+");
								printf("\n\t| OPS... OCORREU ALGUM ERRO INTERNO                                    |");
								printf("\n\t| PARECE QUE NA CHAMADA DA FUNÇÃO FOI PASSADO ALGUM ARGUMENTO INVÁLIDO |");
								printf("\n\t+----------------------------------------------------------------------+\n\n");
							}

							else if (Erro == ERRO_LISTA_VAZIA) {

								printf("\n\t+-----------------------------------------+");
								printf("\n\t| OPS... PARECE QUE VOCÊ NÃO TEM AMIGOS   |");
								printf("\n\t| DESEJA ADICIONAR ALGUM?                 |");
								printf("\n\t| [01] SIM    [00] NÃO                    |");
								printf("\n\t+-----------------------------------------+");
								printf("\nEscolha: ");
								(void)scanf("%d", &OpcaoEscolhida);

								if (OpcaoEscolhida == 0) {

									printf("\n\t+------------------+");
									printf("\n\t| VOLTANDO AO MENU |");
									printf("\n\t+------------------+\n\n");

									OpcaoEscolhida = !FECHAR_PROGRAMA;
								}

								else if (OpcaoEscolhida == 1) {

									ImprimeTable(TabelaComPerfisCadastrados);

									Erro = AdicionarAmigo(PerfilAtivo, TabelaComPerfisCadastrados, stringAlvo());

									if (Erro == SUCESSO) {

										printf("\n\t+---------------------------------+");
										printf("\n\t| PARABÉNS VOCÊ TEM UM NOVO AMIGO |");
										printf("\n\t+---------------------------------+\n\n");
									}

									else if (Erro == ERRO_VOCES_JA_SAO_AMIGOS) {

										printf("\n\t+---------------------+");
										printf("\n\t| VOCES JÁ SÃO AMIGOS |");
										printf("\n\t+---------------------+\n\n");
									}

									else if (Erro == ERRO_ARGUMENTO_INVALIDO){
										
										printf("\n\t+----------------------------------------------------------------------+");
										printf("\n\t| OPS... OCORREU ALGUM ERRO INTERNO                                    |");
										printf("\n\t| PARECE QUE NA CHAMADA DA FUNÇÃO FOI PASSADO ALGUM ARGUMENTO INVÁLIDO |");
										printf("\n\t+----------------------------------------------------------------------+\n\n");
									}

									else if (Erro == ERRO_DADO_NAO_ENCONTRADO) {

										printf("\n\t+------------------------------------------+");
										printf("\n\t| OPS... PARECE QUE ESSA PESSOA NÃO ESTÁ   |");
										printf("\n\t| CADASTRADA NO FACEBOOK PARAGUAI          |");
										printf("\n\t+------------------------------------------+\n\n");
									}

									else if (Erro == ERRO_NAO_EH_POSSIVEL_SE_ADICIONAR) {

										printf("\n\t+------------------------------+");
										printf("\n\t| AMOR PRÓPRIO É MUITO BOM MAS |");
										printf("\n\t| NÃO É POSSÍVEL SE ADICIONAR  |");
										printf("\n\t+------------------------------+\n\n");
									}
								}

								else {

									printf("\n\t+--------------------+");
									printf("\n\t| OPÇÃO INVÁLIDA     |");
									printf("\n\t| VOLTANDO AO MENU   |");
									printf("\n\t+--------------------+\n\n");
								}
							}
							
							break;

						case 2:

							ImprimeTable(TabelaComPerfisCadastrados);

							Erro = AdicionarAmigo(PerfilAtivo, TabelaComPerfisCadastrados, stringAlvo());

							if (Erro == SUCESSO) {

								printf("\n\t+---------------------------------+");
								printf("\n\t| PARABÉNS VOCÊ TEM UM NOVO AMIGO |");
								printf("\n\t+---------------------------------+\n\n");
							}

							else if (Erro == ERRO_VOCES_JA_SAO_AMIGOS) {

								printf("\n\t+---------------------+");
								printf("\n\t| VOCES JÁ SÃO AMIGOS |");
								printf("\n\t+---------------------+\n\n");
							}

							else if (Erro == ERRO_ARGUMENTO_INVALIDO) {

								printf("\n\t+----------------------------------------------------------------------+");
								printf("\n\t| OPS... OCORREU ALGUM ERRO INTERNO                                    |");
								printf("\n\t| PARECE QUE NA CHAMADA DA FUNÇÃO FOI PASSADO ALGUM ARGUMENTO INVÁLIDO |");
								printf("\n\t+----------------------------------------------------------------------+\n\n");
							}

							else if (Erro == ERRO_DADO_NAO_ENCONTRADO) {

								printf("\n\t+------------------------------------------+");
								printf("\n\t| OPS... PARECE QUE ESSA PESSOA NÃO ESTÁ   |");
								printf("\n\t| CADASTRADA NO FACEBOOK PARAGUAI          |");
								printf("\n\t+------------------------------------------+\n\n");
							}

							else if (Erro == ERRO_NAO_EH_POSSIVEL_SE_ADICIONAR) {

								printf("\n\t+------------------------------+");
								printf("\n\t| AMOR PRÓPRIO É MUITO BOM MAS |");
								printf("\n\t| NÃO É POSSÍVEL SE ADICIONAR  |");
								printf("\n\t+------------------------------+\n\n");
							}

							break;

						case 3:

							printf("\n\t+-------------------------------------+");
							printf("\n\t| PERDER UM AMIGO É SEMPRE CHATO      |");
							printf("\n\t| ESPERO QUE NÃO TENHAM BRIGADO       |");
							printf("\n\t| ENFIM ESCOLHA UM AMIGO PARA REMOVER |");
							printf("\n\t+-------------------------------------+\n");

							Erro = ImprimeListaAmigos(PerfilAtivo);

							if (Erro == ERRO_LISTA_VAZIA) {

								printf("\n\t+---------------------------------------+");
								printf("\n\t| OPS... PARECE QUE VOCÊ NÃO TEM AMIGOS |");
								printf("\n\t+---------------------------------------+\n\n");
							}

							else if (Erro == SUCESSO) {

								Erro = RemoverAmigo(PerfilAtivo, TabelaComPerfisCadastrados, stringAlvo());

								if (Erro == ERRO_ARGUMENTO_INVALIDO) {

									printf("\n\t+----------------------------------------------------------------------+");
									printf("\n\t| OPS... OCORREU ALGUM ERRO INTERNO                                    |");
									printf("\n\t| PARECE QUE NA CHAMADA DA FUNÇÃO FOI PASSADO ALGUM ARGUMENTO INVÁLIDO |");
									printf("\n\t+----------------------------------------------------------------------+\n\n");
								}

								else if (Erro == ERRO_DADO_NAO_ENCONTRADO) {

									printf("\n\t+--------------------------------------+");
									printf("\n\t| OPS... PARECE QUE NÃO HÁ NINGUEM     |");
									printf("\n\t| COM ESSE NOME NA SUA LISTA DE AMIGOS |");
									printf("\n\t+--------------------------------------+\n\n");
								}

								else {

									printf("\n\t+---------------------------------------+");
									printf("\n\t| NÃO SEI QUEM FICA FELIZ COM ISSO MAS  |");
									printf("\n\t| AMIGO REMOVIDO COM SUCESSO :(         |");
									printf("\n\t+---------------------------------------+\n\n");
								}
							}
							break;

						case 4:

							printf("\n\t+---------------------------------+");
							printf("\n\t| BEM VINDO A FUNÇÃO DE STALKER   |");
							printf("\n\t| ESCOLHA UM PERFIL PARA STALKEAR |");
							printf("\n\t+---------------------------------+\n\n");
							
							Erro = ImprimeListaAmigos(PerfilAtivo);

							if (Erro == ERRO_LISTA_VAZIA) {

								printf("\n\t+----------------------------------------------+");
								printf("\n\t| PARECE QUE VOCÊ NÃO TEM AMIGOS PARA STALKEAR |");
								printf("\n\t+----------------------------------------------+\n\n");
							}

							else if (Erro == SUCESSO) {

								aux = VisitarPerfil(PerfilAtivo, stringAlvo());

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

									do{

										printf("+---------------------------------------------+\n");
										printf("| FUNCIONALIDADES DISPONIVEIS EM MODO STALKER |\n");
										printf("+---------------------------------------------+\n");
										printf("[00] Voltar ao menu de perfil aitvo.\n");
										printf("[01] Exibir lista de amigos.\n");
										printf("[02] Navegar entre perfis.\n");
										printf("[03] Exibir todas as postagens.\n");
										printf("[04] Exibir N ultimas postagens.\n");
										printf("[05] Deixar de curtir alguma postagem.\n");
										printf("Escolha: ");
										(void)scanf("%d", &OpcaoEscolhida);

										switch (OpcaoEscolhida){
										case 0:

											printf("\n\t+----------------------------+");
											printf("\n\t| VOLTANDO AO MENU DE PERFIS |");
											printf("\n\t+----------------------------+\n\n");

											break;

										case 1:

											Erro = ImprimeListaAmigos(PerfilVisitado);

											if (Erro == ERRO_ARGUMENTO_INVALIDO) {

												printf("\n\t+----------------------------------------------------------------------+");
												printf("\n\t| OPS... OCORREU ALGUM ERRO INTERNO                                    |");
												printf("\n\t| PARECE QUE NA CHAMADA DA FUNÇÃO FOI PASSADO ALGUM ARGUMENTO INVÁLIDO |");
												printf("\n\t+----------------------------------------------------------------------+\n\n");
											}

											else if (Erro == ERRO_LISTA_VAZIA){

												printf("\n\t+------------------------------------------+");
												printf("\n\t| PARECE QUE ESTE PERFIL NÃO POSSUI AMIGOS |");
												printf("\n\t+------------------------------------------+\n\n");
											}

											else {

												printf("\n\t+------------------------------------+");
												printf("\n\t| ESSES FORAM OS AMIGOS DO SEU AMIGO |");
												printf("\n\t+------------------------------------+\n\n");
											}
											break;

										case 2:

											PerfilVisitado = StalkerProfissional(PerfilVisitado);

											break;

										case 3:

											Erro = ImprimePostagens(PerfilVisitado);

											if (Erro == LISTA_POSTAGENS_VAZIA) {

												printf("\n\t+------------------------------------+");
												printf("\n\t| PARECE QUE NÃO HÁ NENHUMA POSTAGEM |");
												printf("\n\t+------------------------------------+\n\n");
											}

											if (Erro == ERRO_ARGUMENTO_INVALIDO) {

												printf("\n\t+----------------------------------------------------------------------+");
												printf("\n\t| OPS... OCORREU ALGUM ERRO INTERNO                                    |");
												printf("\n\t| PARECE QUE NA CHAMADA DA FUNÇÃO FOI PASSADO ALGUM ARGUMENTO INVÁLIDO |");
												printf("\n\t+----------------------------------------------------------------------+\n\n");
											}

											else if (Erro == SUCESSO) {

												printf("\n\t+-----------------------------------+");
												printf("\n\t| DESEJA CURTIR ALGUMA POSTAGEM?    |");
												printf("\n\t| [01] SIM   [00] NÃO               |");
												printf("\n\t+-----------------------------------+\n");
												printf("Escolha: ");
												(void)scanf("%d", &OpcaoEscolhida);

												if (OpcaoEscolhida == 1) {

													IdPostagem = ID_Alvo();

													postaux = ObtemPostagem(PerfilVisitado, IdPostagem);

													if (postaux == NULL) {

														printf("\n\t+-------------------------------------+");
														printf("\n\t| PARECE QUE ESSA POSTAGEM NÃO EXISTE |");
														printf("\n\t+-------------------------------------+\n\n");
													}

													else {

														InsereTabela(postaux->DadosItem->curtidas, PerfilAtivo);

														postaux->DadosItem->nCurtidas++;

														printf("\n\t+--------------------------------+");
														printf("\n\t| POSTAGEM CURTIDA COM SUCESSO!! |");
														printf("\n\t+--------------------------------+\n\n");
													}



												}

												printf("\n\t+----------------------------------------------------+");
												printf("\n\t| DESEJA IMPRIMIR DETALHADAMENTE ALGUMA POSTAGEM?    |");
												printf("\n\t| [01] SIM   [00] NÃO                                |");
												printf("\n\t+----------------------------------------------------+\n");
												printf("Escolha: ");
												(void)scanf("%d", &OpcaoEscolhida);

												if (OpcaoEscolhida == 1) {

													IdPostagem = ID_Alvo();

													Erro = ImprimePostagensDetalhadas(PerfilVisitado, IdPostagem);

													if (Erro == LISTA_POSTAGENS_VAZIA || Erro == ERRO_DADO_NAO_ENCONTRADO) {

														printf("\n\t+-------------------------+");
														printf("\n\t| POSTAGEM NÃO ENCONTRADA |");
														printf("\n\t+-------------------------+\n\n");
													}

												}


												else OpcaoEscolhida = !FECHAR_PROGRAMA;
											}
											
											break;

										case 4:

											Erro = ImprimirNultimasPostagens(PerfilAtivo, PerfilVisitado, NumPostagens());

											if (Erro == ERRO_ARGUMENTO_INVALIDO) {

												printf("\n\t+----------------------------------------------------------------------+");
												printf("\n\t| OPS... OCORREU ALGUM ERRO INTERNO                                    |");
												printf("\n\t| PARECE QUE NA CHAMADA DA FUNÇÃO FOI PASSADO ALGUM ARGUMENTO INVÁLIDO |");
												printf("\n\t+----------------------------------------------------------------------+\n\n");
											}

											else if (Erro == SUCESSO) {

												printf("\n\t+-----------------------------------+");
												printf("\n\t| DESEJA CURTIR ALGUMA POSTAGEM?    |");
												printf("\n\t| [01] SIM   [00] NÃO               |");
												printf("\n\t+-----------------------------------+\n");
												printf("Escolha: ");
												(void)scanf("%d", &OpcaoEscolhida);

												if (OpcaoEscolhida == 1) {

													IdPostagem = ID_Alvo();

													postaux = ObtemPostagem(PerfilVisitado, IdPostagem);

													if (postaux == NULL) {

														printf("\n\t+-------------------------------------+");
														printf("\n\t| PARECE QUE ESSA POSTAGEM NÃO EXISTE |");
														printf("\n\t+-------------------------------------+\n\n");
													}

													else {

														InsereTabela(postaux->DadosItem->curtidas, PerfilAtivo);

														postaux->DadosItem->nCurtidas++;

														printf("\n\t+--------------------------------+");
														printf("\n\t| POSTAGEM CURTIDA COM SUCESSO!! |");
														printf("\n\t+--------------------------------+\n\n");
													}


													
												}

												printf("\n\t+----------------------------------------------------+");
												printf("\n\t| DESEJA IMPRIMIR DETALHADAMENTE ALGUMA POSTAGEM?    |");
												printf("\n\t| [01] SIM   [00] NÃO                                |");
												printf("\n\t+----------------------------------------------------+\n");
												printf("Escolha: ");
												(void)scanf("%d", &OpcaoEscolhida);

												if (OpcaoEscolhida == 1){

													IdPostagem = ID_Alvo();

													Erro = ImprimePostagensDetalhadas(PerfilVisitado, IdPostagem);

													if (Erro == LISTA_POSTAGENS_VAZIA || Erro == ERRO_DADO_NAO_ENCONTRADO) {

														printf("\n\t+-------------------------+");
														printf("\n\t| POSTAGEM NÃO ENCONTRADA |");
														printf("\n\t+-------------------------+\n\n");
													}

												}


												else OpcaoEscolhida = !FECHAR_PROGRAMA;
											}

											break;

										case 5:

											Erro = ImprimePostagens(PerfilVisitado);

											if (Erro == LISTA_POSTAGENS_VAZIA) {

												printf("\n\t+------------------------------------+");
												printf("\n\t| PARECE QUE NÃO HÁ NENHUMA POSTAGEM |");
												printf("\n\t+------------------------------------+\n\n");
											}

											if (Erro == ERRO_ARGUMENTO_INVALIDO) {

												printf("\n\t+----------------------------------------------------------------------+");
												printf("\n\t| OPS... OCORREU ALGUM ERRO INTERNO                                    |");
												printf("\n\t| PARECE QUE NA CHAMADA DA FUNÇÃO FOI PASSADO ALGUM ARGUMENTO INVÁLIDO |");
												printf("\n\t+----------------------------------------------------------------------+\n\n");
											}

											else if (Erro == SUCESSO) {

												IdPostagem = ID_Alvo();

												postaux = ObtemPostagem(PerfilVisitado, IdPostagem);

												if (postaux == NULL) {

													printf("\n\t+-------------------------------------+");
													printf("\n\t| PARECE QUE ESSA POSTAGEM NÃO EXISTE |");
													printf("\n\t+-------------------------------------+\n\n");
												}

												else {

													Erro = RemoveTabelaCurtidas(postaux->DadosItem->curtidas, PerfilAtivo->Nome);

													if (Erro == ERRO_DADO_NAO_ENCONTRADO) {

														printf("\n\t+---------------------------------------------------------------+");
														printf("\n\t| PARECE QUE ESSA POSTAGEM NÃO FOI PREVIAMENTE CURTIDA POR VOCê |");
														printf("\n\t+---------------------------------------------------------------+\n\n");
													}

													else if (Erro == SUCESSO) {

														postaux->DadosItem->nCurtidas--;

														printf("\n\t+----------------------------------+");
														printf("\n\t| VOCÊ DEIXOU DE CURTIR A POSTAGEM |");
														printf("\n\t+----------------------------------+\n\n");
													}
												}
											}

											
											break;
										default:
											break;
										}

									} while (OpcaoEscolhida != FECHAR_PROGRAMA);

								}

							}

							else if (Erro == ERRO_ARGUMENTO_INVALIDO) {

								printf("\n\t+----------------------------------------------------------------------+");
								printf("\n\t| OPS... OCORREU ALGUM ERRO INTERNO                                    |");
								printf("\n\t| PARECE QUE NA CHAMADA DA FUNÇÃO FOI PASSADO ALGUM ARGUMENTO INVÁLIDO |");
								printf("\n\t+----------------------------------------------------------------------+\n\n");
							}

							OpcaoEscolhida = !FECHAR_PROGRAMA;

							break;

						case 5:

							Erro = ImprimePostagens(PerfilAtivo);

							if (Erro == LISTA_POSTAGENS_VAZIA) {

								printf("\n\t+------------------------------------------+");
								printf("\n\t| PARECE QUE VOCÊ NÃO FEZ NENHUMA POSTAGEM |");
								printf("\n\t+------------------------------------------+\n\n");
							}

							if (Erro == ERRO_ARGUMENTO_INVALIDO) {

								printf("\n\t+----------------------------------------------------------------------+");
								printf("\n\t| OPS... OCORREU ALGUM ERRO INTERNO                                    |");
								printf("\n\t| PARECE QUE NA CHAMADA DA FUNÇÃO FOI PASSADO ALGUM ARGUMENTO INVÁLIDO |");
								printf("\n\t+----------------------------------------------------------------------+\n\n");
							}

							else if(Erro == SUCESSO) {

								printf("\n\t+-----------------------------------+");
								printf("\n\t| DESEJA CURTIR ALGUMA POSTAGEM?    |");
								printf("\n\t| [01] SIM   [00] NÃO               |");
								printf("\n\t+-----------------------------------+\n");
								printf("Escolha: ");
								(void)scanf("%d", &OpcaoEscolhida);

								if (OpcaoEscolhida == 1) {

									IdPostagem = ID_Alvo();

									postaux = ObtemPostagem(PerfilAtivo, IdPostagem);

									if (postaux == NULL) {

										printf("\n\t+-------------------------------------+");
										printf("\n\t| PARECE QUE ESSA POSTAGEM NÃO EXISTE |");
										printf("\n\t+-------------------------------------+\n\n");
									}

									else {

										InsereTabela(postaux->DadosItem->curtidas, PerfilAtivo);

										postaux->DadosItem->nCurtidas++;

										printf("\n\t+--------------------------------+");
										printf("\n\t| POSTAGEM CURTIDA COM SUCESSO!! |");
										printf("\n\t+--------------------------------+\n\n");
									}



								}

								printf("\n\t+----------------------------------------------------+");
								printf("\n\t| DESEJA IMPRIMIR DETALHADAMENTE ALGUMA POSTAGEM?    |");
								printf("\n\t| [01] SIM   [00] NÃO                                |");
								printf("\n\t+----------------------------------------------------+\n");
								printf("Escolha: ");
								(void)scanf("%d", &OpcaoEscolhida);

								if (OpcaoEscolhida == 1) {

									IdPostagem = ID_Alvo();

									Erro = ImprimePostagensDetalhadas(PerfilAtivo, IdPostagem);

									if (Erro == LISTA_POSTAGENS_VAZIA || Erro == ERRO_DADO_NAO_ENCONTRADO) {

										printf("\n\t+-------------------------+");
										printf("\n\t| POSTAGEM NÃO ENCONTRADA |");
										printf("\n\t+-------------------------+\n\n");
									}

								}

								else OpcaoEscolhida = !FECHAR_PROGRAMA;
							}

							break;

						case 6:

							Erro = ImprimirNultimasPostagens(PerfilAtivo, PerfilAtivo, NumPostagens());

							if (Erro == ERRO_ARGUMENTO_INVALIDO) {

								printf("\n\t+----------------------------------------------------------------------+");
								printf("\n\t| OPS... OCORREU ALGUM ERRO INTERNO                                    |");
								printf("\n\t| PARECE QUE NA CHAMADA DA FUNÇÃO FOI PASSADO ALGUM ARGUMENTO INVÁLIDO |");
								printf("\n\t+----------------------------------------------------------------------+\n\n");
							}

							else if (Erro == SUCESSO) {
								
								printf("\n\t+-----------------------------------+");
								printf("\n\t| DESEJA CURTIR ALGUMA POSTAGEM?    |");
								printf("\n\t| [01] SIM   [00] NÃO               |");
								printf("\n\t+-----------------------------------+\n");
								printf("Escolha: ");
								(void)scanf("%d", &OpcaoEscolhida);

								if (OpcaoEscolhida == 1) {

									IdPostagem = ID_Alvo();

									postaux = ObtemPostagem(PerfilAtivo, IdPostagem);

									if (postaux == NULL) {

										printf("\n\t+-------------------------------------+");
										printf("\n\t| PARECE QUE ESSA POSTAGEM NÃO EXISTE |");
										printf("\n\t+-------------------------------------+\n\n");
									}

									else {

										InsereTabela(postaux->DadosItem->curtidas, PerfilAtivo);

										postaux->DadosItem->nCurtidas++;

										printf("\n\t+--------------------------------+");
										printf("\n\t| POSTAGEM CURTIDA COM SUCESSO!! |");
										printf("\n\t+--------------------------------+\n\n");
									}



								}

								printf("\n\t+----------------------------------------------------+");
								printf("\n\t| DESEJA IMPRIMIR DETALHADAMENTE ALGUMA POSTAGEM?    |");
								printf("\n\t| [01] SIM   [00] NÃO                                |");
								printf("\n\t+----------------------------------------------------+\n");
								printf("Escolha: ");
								(void)scanf("%d", &OpcaoEscolhida);

								if (OpcaoEscolhida == 1) {

									IdPostagem = ID_Alvo();

									Erro = ImprimePostagensDetalhadas(PerfilAtivo, IdPostagem);

									if (Erro == LISTA_POSTAGENS_VAZIA || Erro == ERRO_DADO_NAO_ENCONTRADO) {

										printf("\n\t+-------------------------+");
										printf("\n\t| POSTAGEM NÃO ENCONTRADA |");
										printf("\n\t+-------------------------+\n\n");
									}

								}

								else OpcaoEscolhida = !FECHAR_PROGRAMA;
							}
							break;

						case 7:

							Erro = InsereNovaPostagem(PerfilAtivo->postagens, NovaPostagem());

							if (Erro == ERRO_ALOCACAO_MEMORIA) {

								printf("\n\t+----------------------------------------------------------+");
								printf("\n\t| HOUVE ALGUM ERRO QUE IMPEDIU A CONCLUSÃO DE SUA POSTAGEM |");
								printf("\n\t+----------------------------------------------------------+\n\n");
							}

							else if (Erro == ERRO_ARGUMENTO_INVALIDO) {

								printf("\n\t+----------------------------------------------------------------------+");
								printf("\n\t| OPS... OCORREU ALGUM ERRO INTERNO                                    |");
								printf("\n\t| PARECE QUE NA CHAMADA DA FUNÇÃO FOI PASSADO ALGUM ARGUMENTO INVÁLIDO |");
								printf("\n\t+----------------------------------------------------------------------+\n\n");

							}

							else {

								printf("\n\t+--------------------------------------+");
								printf("\n\t| POSTAGEM EFETUADA COM SUCESSO!!! :)  |");
								printf("\n\t+--------------------------------------+\n\n");
							}

							break;

						case 8:

							Erro = ImprimePostagens(PerfilAtivo);

							if (Erro == LISTA_POSTAGENS_VAZIA) {

								printf("\n\t+------------------------------------------+");
								printf("\n\t| PARECE QUE VOCÊ NÃO FEZ NENHUMA POSTAGEM |");
								printf("\n\t+------------------------------------------+\n\n");
							}

							if (Erro == ERRO_ARGUMENTO_INVALIDO) {

								printf("\n\t+----------------------------------------------------------------------+");
								printf("\n\t| OPS... OCORREU ALGUM ERRO INTERNO                                    |");
								printf("\n\t| PARECE QUE NA CHAMADA DA FUNÇÃO FOI PASSADO ALGUM ARGUMENTO INVÁLIDO |");
								printf("\n\t+----------------------------------------------------------------------+\n\n");
							}

							else {

								Erro = RemoverPostagem(PerfilAtivo->postagens, ID_Alvo());

								if (Erro == ERRO_DADO_NAO_ENCONTRADO) {

									printf("\n\t+-------------------------------------+");
									printf("\n\t| NÃO EXISTE UMA POSTAGEM COM ESSE ID |");
									printf("\n\t+-------------------------------------+\n\n");
								}

								else if (Erro == ERRO_ARGUMENTO_INVALIDO) {

									printf("\n\t+----------------------------------------------------------------------+");
									printf("\n\t| OPS... OCORREU ALGUM ERRO INTERNO                                    |");
									printf("\n\t| PARECE QUE NA CHAMADA DA FUNÇÃO FOI PASSADO ALGUM ARGUMENTO INVÁLIDO |");
									printf("\n\t+----------------------------------------------------------------------+\n\n");
								}

								else {

									printf("\n\t+-------------------------------------+");
									printf("\n\t| POSTAGEM REMOVIDA COM SUCESSO!!! :) |");
									printf("\n\t+-------------------------------------+\n\n");
								}
							}

							break;

						case 9:

							Erro = ImprimePostagens(PerfilAtivo);

							if (Erro == LISTA_POSTAGENS_VAZIA) {

								printf("\n\t+------------------------------------+");
								printf("\n\t| PARECE QUE NÃO HÁ NENHUMA POSTAGEM |");
								printf("\n\t+------------------------------------+\n\n");
							}

							if (Erro == ERRO_ARGUMENTO_INVALIDO) {

								printf("\n\t+----------------------------------------------------------------------+");
								printf("\n\t| OPS... OCORREU ALGUM ERRO INTERNO                                    |");
								printf("\n\t| PARECE QUE NA CHAMADA DA FUNÇÃO FOI PASSADO ALGUM ARGUMENTO INVÁLIDO |");
								printf("\n\t+----------------------------------------------------------------------+\n\n");
							}

							else if (Erro == SUCESSO) {

								IdPostagem = ID_Alvo();

								postaux = ObtemPostagem(PerfilAtivo, IdPostagem);

								if (postaux == NULL) {

									printf("\n\t+-------------------------------------+");
									printf("\n\t| PARECE QUE ESSA POSTAGEM NÃO EXISTE |");
									printf("\n\t+-------------------------------------+\n\n");
								}

								else {

									Erro = RemoveTabelaCurtidas(postaux->DadosItem->curtidas, PerfilAtivo->Nome);

									if (Erro == ERRO_DADO_NAO_ENCONTRADO) {

										printf("\n\t+---------------------------------------------------------------+");
										printf("\n\t| PARECE QUE ESSA POSTAGEM NÃO FOI PREVIAMENTE CURTIDA POR VOCê |");
										printf("\n\t+---------------------------------------------------------------+\n\n");
									}

									else if (Erro == SUCESSO) {

										postaux->DadosItem->nCurtidas--;

										printf("\n\t+----------------------------------+");
										printf("\n\t| VOCÊ DEIXOU DE CURTIR A POSTAGEM |");
										printf("\n\t+----------------------------------+\n\n");
									}
								}
							}

							
							break;
						default:

							printf("\n\t+----------------+");
							printf("\n\t| OPÇÃO INVÁLIDA |");
							printf("\n\t+----------------+\n\n");

							break;
						}

					} while (OpcaoEscolhida != FECHAR_PROGRAMA);

					OpcaoEscolhida = !FECHAR_PROGRAMA;
				}
			}

			break;

		case 2:

			printf("\n\t+--------------------------------------------------------------+");
			printf("\n\t| SEJA BEM VINDO A NOSSA REDE SOCIAL!!!                        |");
			printf("\n\t| PARA REALIZAR O SEU CADASTRO IREMOS PRECISAR DE ALGUNS DADOS |");
			printf("\n\t+--------------------------------------------------------------+\n\n");
			
			Erro = NovoPerfil(NovosDados(), TabelaComPerfisCadastrados);

			if (Erro == SUCESSO) {

				printf("\n\t+-------------------------------------+");
				printf("\n\t| CADASTRO EFETUADO COM SUCESSO!!! :) |");
				printf("\n\t+-------------------------------------+\n\n");
			}

			while (Erro != SUCESSO){

				if (Erro == ERRO_NOME_EM_USO) {

					printf("\n\t+-------------------------------------------------+");
					printf("\n\t| DESCULPE MAS PARECE QUE ESSE NOME JÁ ETÁ EM USO |");
					printf("\n\t| TENTE ALGUM OUTRO NOME DE USUÁRIO.              |");
					printf("\n\t+-------------------------------------------------+\n\n");

					Erro = NovoPerfil(NovosDados(), TabelaComPerfisCadastrados);
				}

				if (Erro == ERRO_ARGUMENTO_INVALIDO) {

					printf("\n\t+----------------------------------------------------------------------+");
					printf("\n\t| OPS... PARECE QUE OCORREU ALGUM ERRO INTERNO                         |");
					printf("\n\t| PARECE QUE NA CHAMADA DA FUNÇÃO FOI PASSADO ALGUM ARGUMENTO INVÁLIDO |");
					printf("\n\t+----------------------------------------------------------------------+\n\n");

					Erro = SUCESSO;
				}
			}
			break;
		case 3:

			if (TabelaComPerfisCadastrados->nColunas == 0) {

				printf("\n\t+--------------------------------------------+");
				printf("\n\t| OPS.. PARECE QUE NÃO HÁ PERFIS CADASTRADOS |");
				printf("\n\t+--------------------------------------------+\n\n");

				break;
			}
			printf("\n\t+-------------------------------------------+");
			printf("\n\t| É SEMPRE TÃO DIFICIL DIZER ADEUS          |");
			printf("\n\t| MAS INFELIZMENTE ACONTECE                 |");
			printf("\n\t| ESCOLHA UM PERFIL PARA SER DELETADO       |");
			printf("\n\t+-------------------------------------------+\n\n");

			ImprimeTable(TabelaComPerfisCadastrados);

			Erro = RemoverPerfil(stringAlvo(), TabelaComPerfisCadastrados);

			if (Erro == SUCESSO) {

				printf("\n\t+-----------------------------------+");
				printf("\n\t| PERFIL DELETADO COM SUCESSO!!     |");
				printf("\n\t| EU VOU CHORAR.                    |");
				printf("\n\t+-----------------------------------+\n\n");
			}

			while (Erro != SUCESSO){

				if (Erro == ERRO_DADO_NAO_ENCONTRADO) {

					printf("\n\t+--------------------------------------------+");
					printf("\n\t| PARECE QUE NÃO EXISTE PERFIL COM ESSE NOME |");
					printf("\n\t| DESEJA TENTAR DE NOVO?                     |");
					printf("\n\t| [01] SIM      [00] NÃO                     |");
					printf("\n\t+--------------------------------------------+\n");
					printf("\nEscolha: ");

					(void)scanf("%d", &OpcaoEscolhida);

					if (OpcaoEscolhida == 0) {
						
						OpcaoEscolhida = !FECHAR_PROGRAMA;

						Erro = SUCESSO;

						break;
					}

					else {

						ImprimeTable(TabelaComPerfisCadastrados);

						Erro = RemoverPerfil(stringAlvo(), TabelaComPerfisCadastrados);
					}
				}

				if (Erro == ERRO_ARGUMENTO_INVALIDO){

					printf("\n\t+----------------------------------------------------------------------+");
					printf("\n\t| OPS... PARECE QUE OCORREU ALGUM ERRO INTERNO                         |");
					printf("\n\t| PARECE QUE NA CHAMADA DA FUNÇÃO FOI PASSADO ALGUM ARGUMENTO INVÁLIDO |");
					printf("\n\t+----------------------------------------------------------------------+\n\n");

					Erro = SUCESSO;
				}

				if (Erro == ERRO_TABELA_VAZIA) {

					printf("\n\t+--------------------------------------------+");
					printf("\n\t| OPS.. PARECE QUE NÃO HÁ PERFIS CADASTRADOS |");
					printf("\n\t+--------------------------------------------+\n\n");

					Erro = SUCESSO;
				}
			}
			break;
		case 4:

			printf("\n\t+-------------------------------------+");
			printf("\n\t| IMPRIMINDO LISTA DE PESSOAS FELIZES |");
			printf("\n\t| OPS... QUER DIZER USUÁRIOS          |");
			printf("\n\t+-------------------------------------+\n\n");

			Erro = ImprimeTable(TabelaComPerfisCadastrados);

			if (Erro == SUCESSO) {

				printf("\n\t+---------------------------------+");
				printf("\n\t| USUÁRIOS IMPRIMIDOS COM SUCESSO |");
				printf("\n\t+---------------------------------+\n\n");
			}

			while (Erro != SUCESSO){

				if (Erro == ERRO_ARGUMENTO_INVALIDO) {

					printf("\n\t+----------------------------------------------------------------------+");
					printf("\n\t| OPS... PARECE QUE OCORREU ALGUM ERRO INTERNO                         |");
					printf("\n\t| PARECE QUE NA CHAMADA DA FUNÇÃO FOI PASSADO ALGUM ARGUMENTO INVÁLIDO |");
					printf("\n\t+----------------------------------------------------------------------+\n\n");

					Erro = SUCESSO;
				}

				if (Erro == ERRO_TABELA_VAZIA) {

					printf("\n\t+----------------------------------------+");
					printf("\n\t| OPS... PARECE QUE NÃO HÁ USUÁRIO AINDA |");
					printf("\n\t+----------------------------------------+\n\n");

					Erro = SUCESSO;
				}
			}

			break;
		default:

			printf("\n\t+----------------+");
			printf("\n\t| OPÇÃO INVÁLIDA |");
			printf("\n\t+----------------+\n\n");

			break;
		}
	} while (OpcaoEscolhida != FECHAR_PROGRAMA);

	LiberaTabela(TabelaComPerfisCadastrados);

	return SUCESSO;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblioteca.h"
#include "artista.h"
#include "espetaculo.h"
#include "ingresso.h"
#include "usuario.h"
#include "relatorio.h"


void modulo_Relatorio(void) {
    char opcao;
    do {
        opcao = menu_Relatorio(); 
        switch(opcao) {
            case '1':  Ingressos_por_Espetaculo();
		    break;
            case '2':  Artistas_por_Espetaculo(); 
		    break;
            case '3':  Ingressos_por_Usuario(); 
		    break;
            } 
    } while (opcao != '0');
}


void Ingressos_por_Espetaculo(void) {

	// função ainda em desenvolvimento
	// exibe a tela apenas para testes

    char* idEspetaculo;

	idEspetaculo = tela_Ingressos_por_Espetaculo();
    relat_Ingressos_por_Espetaculo(idEspetaculo);
    free(idEspetaculo);
}




void listar_Artistas_por_Espetaculo(void) {

	// função ainda em desenvolvimento
	// exibe a tela apenas para testes

    char* idEspetaculo;

	idEspetaculo = tela_Ingressos_por_Espetaculo();
    relat_Ingressos_por_Espetaculo(idEspetaculo);
    free(idEspetaculo);
}


void Ingressos_por_Usuario(void) {
    
	// função ainda em desenvolvimento
	// exibe a tela apenas para testes

    char* idUsuario;

	idUsuario = tela_Ingressos_por_Usuario();
    relat_Ingressos_por_Usuario(idUsuario);
    free(idUsuario);
}


char menu_Relatorio(void) {
    char op;
    limpaTela();  
    printf("\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                       ///\n");
    printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
    printf("///           = = = = = = = =  Menu Relatório = = = = = = = =             ///\n");
    printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
    printf("///                                                                       ///\n");
    printf("///           1. Listar Ingressos por Espetaculo                          ///\n");
    printf("///           2. Listar Artistas por Espetaculo                           ///\n");
    printf("///           3. Listar Ingressos por Usuario                             ///\n");
    printf("///           0. Voltar ao menu anterior                                  ///\n");
    printf("///                                                                       ///\n");
    printf("///           Escolha a opção desejada: ");
    scanf(" %c", &op); 
    printf("///                                                                       ///\n");
    printf("///                                                                       ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    delay(1); 
    return op;
}



char* tela_Ingressos_por_Espetaculo (void) {
    char* idEspetaculo;
    idEspetaculo = (char*) malloc(4*sizeof(char));
    limpaTela();
	printf("\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("///                                                                       ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///           = = = = =  Ingressos por Espetaculo   = = = = =             ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///                                                                       ///\n");
	printf("///           Informe o id do Espetaculo: ");
	scanf("%[0-9]", idEspetaculo);
	getchar();
	printf("///                                                                       ///\n");
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("\n");
	delay(1);
	return idEspetaculo;
}


char* tela_Artista_por_Espetaculo(void) {
	char *idEspetaculo;
	idEspetaculo = (char*) malloc(12*sizeof(char));
	limpaTela();
	printf("\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("///                                                                       ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///           = = = = =  Artistas por Espetaculo  = = = = = =             ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///                                                                       ///\n");
	printf("///           Informe o id do Espetaculo: ");
	scanf("%[0-9]", idEspetaculo);
	getchar();
	printf("///                                                                       ///\n");
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("\n");
	delay(1);
	return idEspetaculo;
}


char* tela_Ingressos_por_Usuario(void) {
	char* idUsuario;
	idUsuario = (char*) malloc(7*sizeof(char));
	limpaTela();
	printf("\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("///                                                                       ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///           = = = = = =  Ingressos por Usuario  = = = = = =             ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///                                                                       ///\n");
	printf("///           Informe o id do Usuario: ");
	scanf("%[0-9]", idUsuario);
	getchar();
	printf("///                                                                       ///\n");
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("\n");
	delay(1);
	return idUsuario;
}



void relat_Ingressos_por_Espetaculo(char* idEspetaculo) {
    limpaTela();
	printf("\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("///                                                                       ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///           = = = = = = = ID do Espetaculo: %-3s  = = = = =             ///\n", idEspetaculo);
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///                                                                       ///\n");
    printf("///           ===============================================             ///\n");
	printf("///           ||  id  ||        Nome do Espetaculo       ||             ///\n");
    printf("///           ===============================================             ///\n");
    printf("///           || 12345678901 || Astrogildo de Araújo Alves ||             ///\n");
    printf("///           || 23456789012 || Benoclécio Barbosa Bastos  ||             ///\n");
    printf("///           || 34567890123 || Clecionilda Cardoso Castro ||             ///\n");
	printf("///                                                                       ///\n");
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("\n");
    printf("///           Tecle <ENTER> para continuar...                             ///");
    getchar();
}


void relat_Artista_por_Espetaculo(char* idEspetaculo) {
    
    limpaTela();
	printf("\n");
	
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("///                                                                       ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///           = = = = =  Espetaculo: %12s \n", idEspetaculo);
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///                                                                       ///\n");
    printf("///           ===============================================             ///\n");
	printf("///           ||  Artista  ||       Espetaculo       ||             ///\n");
    printf("///           ===============================================             ///\n");
    printf("///           ||     T09     || Francês Instrumental I     ||             ///\n");
    printf("///           ||     T16     || Inglês para Negócios  II   ||             ///\n");
    printf("///           ||     T42     || Inglês para Negócios III   ||             ///\n");
	printf("///                                                                       ///\n");
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("\n");
    printf("///           Tecle <ENTER> para continuar...                             ///");
    getchar();
    
}


void relat_Ingressos_por_Usuario(char* idUsuario) {
	char* idUsuario;
	nomeUsuario = getNomeUsuario(idUsuario);
    limpaTela();
	printf("\n");
	
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("///                                                                       ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///          = = = = =  Usuario: %12s \n", idEspetaculo);           
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///                                                                       ///\n");
    printf("///           ===============================================             ///\n");
	printf("///           ||  ID Ingresso  ||        Nome do Usuario       ||             ///\n");
    printf("///           ===============================================             ///\n");
    
	printf("///                                                                       ///\n");
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("\n");
    printf("///           Tecle <ENTER> para continuar...                             ///");
    getchar();
	free(nomeUsuario);
}




char* getNomeUsuario(char* idUsuario) {
	char *nomeUsuario;
	Usuario* usr;
	
	nomeUsuario = (char*) malloc(51*sizeof(char));
	usr = (Usuario*) malloc(sizeof(Usuario));
	usr = buscarProfessor(idUsuario);
    if (usr == NULL) {
    	strcpy(nomeUsuario, "");
    } else {
    	strcpy(nomeUsuario, usr->nome);
    }
    
	return nomeUsuario;
}

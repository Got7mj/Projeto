#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "artista.h"
#include "biblioteca.h"


typedef struct artista Artista;

/// Funções do Módulo  

void modulo_Artista(void) {
    char opcao;
    do {
        opcao = menu_Artista();
        switch(opcao) {
            case '1': 	cadastrar_Artista();
                        break;
            case '2': 	consultar_Artista();
                        break;
            case '3': 	alterar_Artista();
                        break;
            case '4': 	excluir_Artista();
                        break;
        } 		
    } while (opcao != '0');
}


char menu_Artista(void) {
    char op;
    limpaTela();
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///            = = = = = = = = =  Menu Artista = = = = = = = =              ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///                                                                         ///\n");
    printf("///            1. Cadastrar um novo artista                                 ///\n");
    printf("///            2. Consultar os dados de um artista                          ///\n");
    printf("///            3. Alterar o cadastro de um artista                          ///\n");
    printf("///            4. Excluir um artista do sistema                             ///\n");
    printf("///            0. Voltar ao menu anterior                                   ///\n");
    printf("///                                                                         ///\n");
    printf("///            Escolha a opção desejada:   ");
    scanf("%c", &op);
    getchar();
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");    
    delay(1);
    return op;
}


void tela_cadastrar_Artista(void) {
    char id[12];
    char nome[51];    
    char email[30];
    char celular[12];
    char cargo[30];
    limpaTela();
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///            = = = = = = = = Cadastrar Artista = = = = = = =              ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///                                                                         ///\n");
do {
    printf("///            ID (apenas números):    ");
    scanf("%[^\n]", id);
    getchar();
} while (!validarID(id));    
    printf("///            Nome completo:          ");
    scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", nome);
    getchar();
    printf("///            E-mail:                 ");
    scanf("%[A-Za-z0-9@._]", email);
    getchar();
do {
	    printf("///           Celular  (apenas números com DDD): ");
	    scanf("%[^\n]", celular);
	    getchar();
} while (!validarCelular(celular));
    printf("///            Cargo:                  ");
    scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", cargo);
    getchar();
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");    
    delay(1);
}


void tela_consultar_Artista(void) {
    char id[12];
     limpaTela();
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///            = = = = = = = = Consultar Artista = = = = = = =              ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///                                                                         ///\n");
    printf("///            Informe o ID (apenas números):    ");
    scanf("%[0-9]", id);
    getchar();
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");    
    delay(1);
}


void tela_alterar_Artista(void) {
    char id[12];
     limpaTela();
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///            = = = = = = = = Alterar Artista = = = = = = = =              ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///                                                                         ///\n");
    printf("///            Informe o ID (apenas números):    ");
    scanf("%[0-9]", id);
    getchar();
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    delay(1);
}


void tela_excluir_Artista(void) {
     char id[12];
     limpaTela();
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///            = = = = = = = = Excluir Artista = = = = = = = =              ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///                                                                         ///\n");
    printf("///            Informe o ID (apenas números):    ");
    scanf("%[0-9]", id);
    getchar();
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    delay(1);
}


void cadastrar_Artista(void) {
	// função ainda em desenvolvimento
	// exibe a tela apenas para testes
	tela_cadastrar_Artista();
}
void consultar_Artista(void) {
	// função ainda em desenvolvimento
	// exibe a tela apenas para testes
	tela_consultar_Artista();
}
void alterar_Artista(void) {
	// função ainda em desenvolvimento
	// exibe a tela apenas para testes
	tela_alterar_Artista();
}
void excluir_Artista(void) {
	// função ainda em desenvolvimento
	// exibe a tela apenas para testes
	tela_excluir_Artista();
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "usuario.h"
#include "biblioteca.h"


/// Funções do Módulo  

void modulo_usuario(void) {
    char opcao;
    do {
        opcao = menu_usuario();
        switch(opcao) {
            case '1': 	cadastrar_usuario();
                        break;
            case '2': 	consultar_usuario();
                        break;
            case '3': 	alterar_usuario();
                        break;
            case '4': 	excluir_usuario();
                        break;
        } 		
    } while (opcao != '0');
}


char menu_usuario(void) {
    char op;
    limpaTela();
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///            = = = = = = = = =  Menu usuario = = = = = = = =              ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///                                                                         ///\n");
    printf("///            1. Cadastrar usuario                                         ///\n");
    printf("///            2. Consultar os dados do usuario                             ///\n");
    printf("///            3. Alterar o cadastro do usuario                             ///\n");
    printf("///            4. Excluir usuario do sistema                                ///\n");
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


void tela_cadastrar_usuario(void) {
    char id[12];
    char nome[51];    
    char email[30];
    char celular[12];
    char nasc[11];
    limpaTela();
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///            = = = = = = = = Cadastrar Usuario = = = = = = =              ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///                                                                         ///\n");
do {
    printf("///            ID (apenas números):    ");
    scanf("%[^\n]", id);
    getchar();
} while (!validaId(id));    
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
} while (!validaCelular(celular));
    printf("///           Data de Nascimento (dd/mm/aaaa):  ");
	  scanf("%[0-9/]", nasc);
    getchar();
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");    
    delay(1);
}


void tela_consultar_usuario(void) {
    char id[12];
     limpaTela();
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///            = = = = = = = = Consultar Usuario = = = = = = =              ///\n");
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


void tela_alterar_usuario(void) {
    char id[12];
     limpaTela();
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///            = = = = = = = = Alterar Usuario = = = = = = = =              ///\n");
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


void tela_excluir_usuario(void) {
     char id[12];
     limpaTela();
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///            = = = = = = = = Excluir Usuario = = = = = = = =              ///\n");
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


void cadastrar_usuario(void) {
	// função ainda em desenvolvimento
	// exibe a tela apenas para testes
	tela_cadastrar_usuario();
}
void consultar_usuario(void) {
	// função ainda em desenvolvimento
	// exibe a tela apenas para testes
	tela_consultar_usuario();
}
void alterar_usuario(void) {
	// função ainda em desenvolvimento
	// exibe a tela apenas para testes
	tela_alterar_usuario();
}
void excluir_usuario(void) {
	// função ainda em desenvolvimento
	// exibe a tela apenas para testes
	tela_excluir_usuario();
}

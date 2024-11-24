#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "usuario.h"
#include "biblioteca.h"


/// Funções do Módulo  

typedef struct usuario Usuario;

void modulo_Usuario(void) {
    char opcao;
    do {
        opcao = menu_Usuario();
        switch(opcao) {
            case '1': 	cadastrar_Usuario();
                        break;
            case '2': 	consultar_Usuario();
                        break;
            case '3': 	alterar_Usuario();
                        break;
            case '4': 	excluir_Usuario();
                        break;
        } 		
    } while (opcao != '0');
}


char menu_Usuario(void) {
    char op;
    limpaTela();
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///            = = = = = = = = =  Menu Usuario = = = = = = = =              ///\n");
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


void tela_cadastrar_Usuario(void) {
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
} while (!validarID(id));
do {
    printf("///            Nome completo:          ");
    scanf("%[^\n]", nome);
    getchar();
} while (!validarNome(nome));
do {
    printf("///            E-mail:                 ");
    scanf("%[^\n]", email);
    getchar();
} while (!validarEmail(email));
do {
    printf("///           Celular  (apenas números com DDD): ");
    scanf("%[^\n]", celular);
    getchar();
} while (!validarCelular(celular));
do {
    printf("///           Data de Nascimento (dd/mm/aaaa):  ");
    scanf("%[^\n]", nasc);
    getchar();
} while (!validarNasc(nasc));	
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");    
    delay(1);
}


void tela_consultar_Usuario(void) {
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


void tela_alterar_Usuario(void) {
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


void tela_excluir_Usuario(void) {
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


void cadastrar_Usuario(void) {
	// função ainda em desenvolvimento
	// exibe a tela apenas para testes
	tela_cadastrar_Usuario();
}
void consultar_Usuario(void) {
	// função ainda em desenvolvimento
	// exibe a tela apenas para testes
	tela_consultar_Usuario();
}
void alterar_Usuario(void) {
	// função ainda em desenvolvimento
	// exibe a tela apenas para testes
	tela_alterar_Usuario();
}
void excluir_Usuario(void) {
	// função ainda em desenvolvimento
	// exibe a tela apenas para testes
	tela_excluir_Usuario();
}

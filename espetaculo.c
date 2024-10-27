#include <stdio.h>
#include <stdlib.h>
#include "espetaculo.h"
#include "biblioteca.h"


void modulo_espetaculo(void) {
    char opcao;
    do {
        opcao = menu_espetaculo();
        switch(opcao) {
            case '1': 	cadastrar_espetaculo();
                        break;
            case '2': 	consultar_espetaculo();
                        break;
            case '3': 	alterar_espetaculo();
                        break;
            case '4': 	excluir_espetaculo();
                        break;
        } 		
    } while (opcao != '0');
}


char menu_espetaculo(void) {
    char op;
    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///            = = = = = = = = Menu Espetáculo = = = = = = = =              ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///                                                                         ///\n");
    printf("///            1. Cadastrar um novo espetáculo                              ///\n");
    printf("///            2. Pesquisar os dados do espetáculo                          ///\n");
    printf("///            3. Atualizar espetáculo                                      ///\n");
    printf("///            4. Excluir espetáculo do sistema                             ///\n");
    printf("///            0. Voltar ao menu anterior                                   ///\n");
    printf("///                                                                         ///\n");
    printf("///            Escolha a opção desejada:          ");
    scanf("%c", &op);
    getchar();
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    delay(1);
    return op;
}


void tela_cadastrar_espetaculo(void) {
    char id[12];
    char data[12];
    char horario[9];
    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///            = = = = = = = Cadastrar Espetáculo = = = = = =               ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///                                                                         ///\n");
    printf("///            ID (apenas números):    ");
    scanf("%[0-9]", id);
    getchar();
    printf("///            Data (dd/mm/aaaa):      ");
    scanf("%[0-9/]", data);
    getchar();
    printf("///            Horário (hh/mm/ss):     ");
    scanf("%[0-9:]", horario);
    getchar();
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");    
    delay(1);
}


void tela_consultar_espetaculo(void) {
    char id[12];
    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///            = = = = = = = Consultar Espetáculo = = = = = = =             ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///                                                                         ///\n");
    printf("///            Informe o ID (apenas números):     ");
    scanf("%[0-9]", id);
    getchar();
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");    
    delay(1);
}


void tela_alterar_espetaculo(void) {
    char id[12];
    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///            = = = = = = = Consultar Espetáculo = = = = = = =             ///\n");
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


void tela_excluir_espetaculo(void) {
    char id[12];
    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///            = = = = = = = = Excluir Espetáculo = = = = = = =             ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///                                                                         ///\n");
    printf("///            Informe o ID (apenas números):     ");
    scanf("%[0-9]", id);
    getchar();
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");    
    delay(1);
}


void cadastrar_espetaculo(void) {
	// função ainda em desenvolvimento
	// exibe a tela apenas para testes
	tela_cadastrar_espetaculo();
}
void consultar_espetaculo(void) {
	// função ainda em desenvolvimento
	// exibe a tela apenas para testes
	tela_consultar_espetaculo();
}
void alterar_espetaculo(void) {
	// função ainda em desenvolvimento
	// exibe a tela apenas para testes
	tela_alterar_espetaculo();
}
void excluir_espetaculo(void) {
	// função ainda em desenvolvimento
	// exibe a tela apenas para testes
	tela_excluir_espetaculo();
}

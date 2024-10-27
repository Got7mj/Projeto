#include <stdio.h>
#include <stdlib.h>
#include "ingresso.h"
#include "biblioteca.h"


void modulo_ingresso(void) {
    char opcao;
    do {
        opcao = menu_ingresso();
        switch(opcao) {
            case '1': 	tela_comprar_ingresso();
                        break;
            case '2': 	tela_reembolsar_ingresso();
                        break;            
        } 		
    } while (opcao != '0');
}


char tela_menu_ingresso(void) {
    char op;
    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///            = = = = = = = = =  Menu Ingresso = = = = = = =               ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///                                                                         ///\n");
    printf("///            1. Comprar ingresso                                          ///\n");
    printf("///            2. Reembolsar ingresso                                       ///\n");
    printf("///            0. Voltar ao menu anterior                                   ///\n");
    printf("///                                                                         ///\n");
    printf("///            Escolha a opção desejada:                                    ///\n");
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t<<< ... Aguarde ... >>>\n");
    delay(1);
    return op;
}


void tela_comprar_ingresso(void) {
    char id[12];
    char preco[3];
    char quantidade[2];
    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///            = = = = = = = = Comprar ingresso = = = = = = =               ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///                                                                         ///\n");
    printf("///            ID (apenas números):    ");
    scanf("%[0-9]", id);
    getchar();
    printf("///            Preço (apenas números):    ");
    scanf("%[0-9]", preco);
    getchar();
    printf("///            Quantidade (apenas números):     ");
    scanf("%[0-9]", quantidade);
    getchar();
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t<<< ... Aguarde ... >>>\n");
    delay(1);
}


void tela_reembolsar_ingresso(void) {
    char id[12];
    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///            = = = = = = = = Reembolsar ingresso = = = = = =              ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///                                                                         ///\n");
    printf("///            Informe o ID (apenas números):   ");
    scanf("%[0-9]", id);
    getchar();
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t<<< ... Aguarde ... >>>\n");
    delay(1);
}


void comprar_ingresso(void) {
	// função ainda em desenvolvimento
	// exibe a tela apenas para testes
	tela_comprar_ingresso();
}


void reembolsar_ingresso(void) {
	// função ainda em desenvolvimento
	// exibe a tela apenas para testes
	tela_reembolsar_ingresso();
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h> 
#include "biblioteca.h"
#include "artista.h"
#include "espetaculo.h"
#include "ingresso.h"
#include "usuario.h"
#include "relatorio.h"



/// Assinatura das funções


char menu_principal(void);
void tela_equipe(void);
void tela_sobre(void);
void delay(int);


/// Programa principal
int main(void) {
    char opcao;
    do {
        opcao = menu_principal();
        switch(opcao) {
            case '1':   modulo_Artista();
                        break;
            case '2':   modulo_Espetaculo();
                        break;
            case '3':   modulo_Ingresso();
                        break;
            case '4':   modulo_Usuario();
		    	break;
            case '5':   modulo_Relatorio();
		        break;
	    case '6':   tela_sobre();
			break;
	    case '7':   tela_equipe();
                        break;
        } 	
    } while (opcao != '0');
    
    return 0;
}    


/// Funções

void tela_sobre(void) {
    system("clear||cls");
    printf("\n");    
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = Sistema de Gestão para um Circo = = =                  ///\n");
    printf("///                                                                         ///\n");
    printf("///  Um sistema desenvolvido para gerenciar as operações de um circo,       ///\n");
    printf("///  incluindo controle de artistas, bilheteria, agendamento de             ///\n");
    printf("///  apresentações.                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}


void tela_equipe(void) {
    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///              = = = Sistema de Gestão para um Circo = = =                ///\n");
    printf("///                                                                         ///\n");
    printf("///            Projeto desenvolvido por:                                    ///\n");
    printf("///                                                                         ///\n");
    printf("///            Mariana Araujo de Medeiros                                   ///\n");
    printf("///            Git: https://github.com/Got7mj/Projeto.git                   ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
} 


char menu_principal(void) {
    char op;
    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///             Universidade Federal do Rio Grande do Norte                 ///\n");
    printf("///                 Centro de Ensino Superior do Seridó                     ///\n");
    printf("///               Departamento de Computação e Tecnologia                   ///\n");
    printf("///                  Disciplina DCT1106 -- Programação                      ///\n");
    printf("///                  Sistema de Gestão para um Circo                        ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///              = = = Sistema de Gestão pra um Circo = = =                 ///\n");
    printf("///                                                                         ///\n");
    printf("///            1. Módulo Artista                                            ///\n");
    printf("///            2. Módulo Espetáculo                                         ///\n");
    printf("///            3. Módulo Ingresso                                           ///\n");
    printf("///            4. Módulo Usuario                                            ///\n");
    printf("///            5. Módulo Relatorio                                          ///\n");	
    printf("///            0. Sair                                                      ///\n");
    printf("///                                                                         ///\n");
    printf("///            Escolher a opção desejada: ");  
    scanf("%c", &op);
    getchar();
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t<<< ... Aguarde ... >>>\n");
    sleep(1);
    return op;
}

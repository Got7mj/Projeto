#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/// Assinatura das funções
void tela_sobre(void);
void tela_equipe(void);
char tela_principal(void);
void modulo_artista(void);
char tela_menu_artista(void);
void tela_cadastrar_artista(void);
void tela_consultar_artista(void);
void tela_alterar_artista(void);
void tela_excluir_artista(void);
void modulo_espetaculo(void);
char tela_menu_espetaculo(void);
void tela_cadastrar_espetaculo(void);
void tela_consultar_espetaculo(void);
void tela_alterar_espetaculo(void);
void tela_excluir_espetaculo(void);
void modulo_ingresso(void);
char tela_menu_ingresso(void);
void tela_comprar_ingresso(void);
void tela_reembolsar_ingresso(void);
void moduloRelatorio(void);
void delay(int);


/// Programa principal
int main(void) {
    char opcao;
    do {
        opcao = telaPrincipal();
        switch(opcao) {
            case '1':   modulo_artista();
                        break;
            case '2':   modulo_espetaculo();
                        break;
            case '3':   modulo_ingresso();
                        break;
            case '4':   // Módulo Relatórios
                        break;
            case '5':   telaSobre();
                        telaEquipe();
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


char tela_principal(void) {
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
    printf("///            4. Módulo Relatórios                                         ///\n");
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





void delay(int segundos) {
  int tempo = 500000 * segundos;
  clock_t inicio = clock();
  while (clock() < inicio + tempo) {
    // não faz nada, apenas gasta tempo
  }
}


/// Funções do Módulo Artista  

void modulo_artista(void) {
    char opcao;
    do {
        opcao = tela_menu_artista();
        switch(opcao) {
            case '1': 	tela_cadastrar_artista();
                        break;
            case '2': 	tela_consultar_artista();
                        break;
            case '3': 	tela_alterar_artista();
                        break;
            case '4': 	tela_excluir_artista();
                        break;
        } 		
    } while (opcao != '0');
}


char tela_menu_artista(void) {
    char op;
    system("clear||cls");
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
    printf("\t\t\t<<< ... Aguarde ... >>>\n");
    delay(1);
    return op;
}


void tela_cadastrar_artista(void) {
    char id[12];
    char nome[51];    
    char email[30];
    char celular[12];
    char cargo[30];
    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///            = = = = = = = = Cadastrar Artista = = = = = = =              ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///                                                                         ///\n");
    printf("///            ID (apenas números):    ");
    scanf("%[0-9]", id);
    getchar();
    printf("///            Nome completo:          ");
    scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", nome);
    getchar();
    printf("///            E-mail:                 ");
    scanf("%[A-Za-z0-9@._]", email);
    getchar();
    printf("///            Celular (apenas números):    ");
    scanf("%[0-9]", celular);
    getchar();
    printf("///            Cargo:                  ");
    scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", cargo);
    getchar();
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t<<< ... Aguarde ... >>>\n");
    delay(1);
}


void tela_consultar_artista(void) {
    char id[12];
    system("clear||cls");
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
    printf("\t\t\t<<< ... Aguarde ... >>>\n");
    delay(1);
}


void tela_alterar_artista(void) {
    char id[12];
    system("clear||cls");
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
    printf("\t\t\t<<< ... Aguarde ... >>>\n");
    delay(1);
}


void tela_excluir_artista(void) {
     char id[12];
    system("clear||cls");
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
    printf("\t\t\t<<< ... Aguarde ... >>>\n");
    delay(1);
}


/// Funções do Módulo espetaculo 

void modulo_espetaculo(void) {
    char opcao;
    do {
        opcao = tela_menu_espetaculo();
        switch(opcao) {
            case '1': 	tela_cadastrar_espetaculo();
                        break;
            case '2': 	tela_consultar_espetaculo();
                        break;
            case '3': 	tela_alterar_espetaculo();
                        break;
            case '4': 	tela_excluir_espetaculo();
                        break;
        } 		
    } while (opcao != '0');
}


char tela_menu_espetaculo(void) {
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
    printf("///            Escolha a opção desejada:                                    ///\n");
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t<<< ... Aguarde ... >>>\n");
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
    printf("\t\t\t<<< ... Aguarde ... >>>\n");
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
    printf("\t\t\t<<< ... Aguarde ... >>>\n");
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
    printf("\t\t\t<<< ... Aguarde ... >>>\n");
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
    printf("\t\t\t<<< ... Aguarde ... >>>\n");
    delay(1);
}


/// Funções do Módulo ingresso 

void modulo_ingresso(void) {
    char opcao;
    do {
        opcao = tela_menu_ingresso();
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


void moduloRelatorio(void) {
	// modulo em desenvolvimento

}

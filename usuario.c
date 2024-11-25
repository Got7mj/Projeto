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

Usuario* tela_Preencher_Usuario(void) {
	Usuario *usr;
	limpaTela();
	printf("\n");
	printf("///////////////////////////////////////////////////////////////////////////////\n");
	printf("///                                                                         ///\n");
	printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
	printf("///            = = = = = = = = Cadastrar Usuario = = = = = = =              ///\n");
	printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
	printf("///                                                                         ///\n");  
	usr = (Usuario*) malloc(sizeof(Usuario));
	do {
		printf("///            ID (apenas números):    ");
		scanf("%[^\n]", usr->id);
		getchar();
	} while (!validarID(usr->id));
	do {
		printf("///            Nome completo:          ");
		scanf("%[^\n]", usr->nome);
		getchar();
	} while (!validarNome(usr->nome));
	do {
		printf("///            E-mail:                 ");
		scanf("%[^\n]", usr->email);
		getchar();
	} while (!validarEmail(usr->email));
	do {
		printf("///           Celular  (apenas números com DDD): ");
		scanf("%[^\n]", usr->celular);
		getchar();
	} while (!validarCelular(usr->celular));
	do {
		printf("///           Data de Nascimento (dd/mm/aaaa):  ");
		scanf("%[^\n]", usr->nasc);
		getchar();
	} while (!validarNasc(usr->nasc));
	usr->status = True;
	printf("///                                                                       ///\n");
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("\n");
	delay(1);
  	return usr;
}


void tela_consultar_Usuario(void) {
    char* id;
    id = (char*) malloc(12*sizeof(char));
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
    return id;
}


void tela_alterar_Usuario(void) {
    char* id;
    id = (char*) malloc(12*sizeof(char));
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
    return id;
}


void tela_excluir_Usuario(void) {
    char* id;
    id = (char*) malloc(12*sizeof(char));
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
    return id;
}


void tela_Erro_Arquivo(void) {
    limpaTela();
    printf("\n");
    printf("////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                      ///\n");
    printf("///           = = = = = = Erro: Não foi possível acessar = = = = = =     ///\n");
    printf("/// 	  = = = = = = = = = o banco de dados = = = = = = = = = =     ///\n");
    printf("///           = = = O arquivo de usuários não foi encontrada = = = =     ///\n");
    printf("///           = = = = = = = Se o problema persistir, = = = = = = = =     ///\n");
    printf("/// 	  = = = = entre em contato com o administrador.= = = = =     ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = = = = =     ///\n");
    printf("///                                                                      ///\n");
    printf("///                                                                      ///\n");
    printf("////////////////////////////////////////////////////////////////////////////\n");
    printf("\n\nTecle ENTER para continuar!\n\n");
    getchar();
    exit(1);


void gravar_Usuario(Usuario *usr) {
	FILE* fp;
	fp = fopen("usuarios.dat", "ab");
	if (fp == NULL) {
		tela_Erro_Arquivo();
	}
	fwrite(usr, sizeof(Usuario), 1, fp);
	fclose(fp);
}


Usuario* buscar_Usuario(char* id) {
	FILE* fp;
	Usuario* usr;

	usr = (Usuario*) malloc(sizeof(Usuario));
	fp = fopen("usuarios.dat", "rb");
	if (fp == NULL) {
		tela_Erro_Arquivo();
	}
	while(fread(usr, sizeof(Usuario), 1, fp)) {
		if ((strcmp(usr->id, id) == 0) && (usr->status == True)) {
			fclose(fp);
			return usr;
		}
	}
	fclose(fp);
	return NULL;
}


void exibir_Usuario(Usuario* usr) {

	if (usr == NULL) {
		printf("\n= = = Usuario Inexistente = = =\n");
	} else {
		printf("\n= = = Usuario Cadastrado = = =\n");
		printf("Id do usuario: %s\n", usr->id);
		printf("Nome do usuario: %s\n", usr->nome);
		printf("Email do usuario: %s\n", usr->email);
		printf("Celular: %s\n", usr->celular);
		printf("Data de Nasc: %s\n", usr->nasc);		
		printf("Status: %d\n", usr->status);
	}
	printf("\n\nTecle ENTER para continuar!\n\n");
	getchar();
}


void regravar_Usuario(Usuario* usr) {
	int achou;
	FILE* fp;
	Usuario* usr_Lido;

	usr_Lido = (Usuario*) malloc(sizeof(Usuario));
	fp = fopen("usuarios.dat", "r+b");
	if (fp == NULL) {
		tela_Erro_Arquivo();
	}
	// while(!feof(fp)) {
	achou = False;
	while(fread(usr_Lido, sizeof(Usuario), 1, fp) && !achou) {
		//fread(usr_Lido, sizeof(Usuario), 1, fp);
		if (strcmp(usr_Lido->id, usr->id) == 0) {
			achou = True;
			fseek(fp, -1*sizeof(Usuario), SEEK_CUR);
        	fwrite(usr, sizeof(Usuario), 1, fp);
			//break;
		}
	}
	fclose(fp);
	free(usr_Lido);
}

void cadastrar_Usuario(void) {
	Usuario *usr;
	usr = tela_Preencher_Usuario();
	gravar_Usuario(usr);
	free(usr);
}

void consultar_Usuario(void) {
	Usuario *usr;
	char* id;
	usr = buscar_Usuario(id);
	exibir_Usuario(usr);
	free(usr); 
	free(id);
}

void alterar_Usuario(void) {
	Usuario *usr;
	char* id;
	usr = buscar_Usuario(id);
	if (usr == NULL) {
		printf("\n\nUsuario não encontrado!\n\n");
	} else {
		usr = tela_Preencher_Usuario();
		strcpy(usr->id, id);
		regravar_Usuario(usr);
		// Outra opção:
		// excluir_Usuario(id);
		// gravar_Usuario(usr);
		free(usr);
	}
	free(id);
}

void excluir_Usuario(void) {
	Usuario *usr;
	char* id;
	id = tela_Excluir_Usuario(id);
	usr = (Usuario*) malloc(sizeof(Usuario));
	usr = buscar_Usuario(id);
	if (usr == NULL) {
		printf("\n\nUsuario não encontrado!\n\n");
	} else {
		usr->status = False;
		regravar_Usuario(usr);
		free(usr);
	}
	free(id);
}

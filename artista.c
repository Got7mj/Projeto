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


Artista* tela_Preencher_Artista(void) {
    Artista *art;
    limpaTela();
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///            = = = = = = = = Cadastrar Artista = = = = = = =              ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///                                                                         ///\n");
	art = (Artista*) malloc(sizeof(Artista));
do {
    printf("///            ID (apenas números):    ");
    scanf("%[^\n]", art->id);
    getchar();
} while (!validarID(art->id)); 
do{	
    printf("///            Nome completo:          ");
    scanf("%[^\n]", art->nome);
    getchar();
} while(!validarNome(art->nome));
do{
    printf("///            E-mail:                 ");
    scanf(""%[^\n]", art->email);
    getchar();
} while(!validarEmail("%[^\n]", art->email));
do {
	printf("///           Celular  (apenas números com DDD): ");
	scanf("%[^\n]", art->celular);
	getchar();
} while (!validarCelular(art->celular));
do{
    printf("///            Cargo:                  ");
    scanf("%[^\n]", art->cargo);
    getchar();
} while(!validarCargo(art->cargo));
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");    
    delay(1);
    return art;
}


char* tela_consultar_Artista(void) {
    char* id;
    id = (char*) malloc(12*sizeof(char));
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
    return id;
}


char* tela_alterar_Artista(void) {
    char* id;
    id = (char*) malloc(12*sizeof(char));
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
    return id;
}


char* tela_excluir_Artista(void) {
     char* id;
    id = (char*) malloc(12*sizeof(char));
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



void gravar_Artista(Artista *art) {
	FILE* fp;
	fp = fopen("artistas.dat", "ab");
	if (fp == NULL) {
		tela_Erro_Arquivo();
	}
	fwrite(usr, sizeof(Artista), 1, fp);
	fclose(fp);
}


Artista* buscar_Artista(char* id) {
	FILE* fp;
	Artista* art;

	art = (Artista*) malloc(sizeof(Artista));
	fp = fopen("artistas.dat", "rb");
	if (fp == NULL) {
		tela_Erro_Arquivo();
	}
	while(fread(usr, sizeof(Artista), 1, fp)) {
		if ((strcmp(art->id, id) == 0) && (art->status == True)) {
			fclose(fp);
			return art;
		}
	}
	fclose(fp);
	return NULL;
}


void exibir_Artista(Artista* atr) {

	if (usr == NULL) {
		printf("\n= = = Artista Inexistente = = =\n");
	} else {
		printf("\n= = = Artista Cadastrado = = =\n");
		printf("Id: %s\n", atr->id);
		printf("Nome: %s\n", atr->nome);
		printf("Email: %s\n", atr->email);
		printf("Celular: %s\n", atr->celular);
		printf("Cargo: %s\n", atr->cargo);		
		printf("Status: %d\n", atr->status);
	}
	printf("\n\nTecle ENTER para continuar!\n\n");
	getchar();
}


void regravar_Artista(Artista* art) {
	int achou;
	FILE* fp;
	Usuario* atr_Lido;

	atr_Lido = (Artista*) malloc(sizeof(Artista));
	fp = fopen("artistas.dat", "r+b");
	if (fp == NULL) {
		tela_Erro_Arquivo();
	}
	// while(!feof(fp)) {
	achou = False;
	while(fread(atr_Lido, sizeof(Artista), 1, fp) && !achou) {
		//fread(atr_Lido, sizeof(Artista), 1, fp);
		if (strcmp(atr_Lido->id, atr->id) == 0) {
			achou = True;
			fseek(fp, -1*sizeof(Artista), SEEK_CUR);
        	fwrite(atr, sizeof(Artista), 1, fp);
			//break;
		}
	}
	fclose(fp);
	free(atr_Lido);
}


void cadastrar_Artista(void) {
	Artista *art;
	art = tela_Preencher_Artista();
	gravar_Artista(art);
	free(art);
}
void consultar_Artista(void) {
	Artista *art;
	char* id;
	usr = buscar_Artista(id);
	exibir_Artista(art);
	free(art); 
	free(id);
}
void alterar_Artista(void) {
	Artista *art;
	char* id;
	art = buscar_Artista(id);
	if (usr == NULL) {
		printf("\n\nArtista não encontrado!\n\n");
	} else {
		usr = tela_Preencher_Artista();
		strcpy(art->id, id);
		regravar_Artista(art);
		// Outra opção:
		// excluir_Artista(id);
		// gravar_Artista(art);
		free(art);
	}
	free(id);
}
void excluir_Artista(void) {
	Artista *art;
	char* id;
	id = tela_Excluir_Artista(id);
	art = (Artista*) malloc(sizeof(Artista));
	art = buscar_Artista(id);
	if (art == NULL) {
		printf("\n\nArtista não encontrado!\n\n");
	} else {
		art->status = False;
		regravar_Artista(art);
		free(art);
	}
	free(id);
}

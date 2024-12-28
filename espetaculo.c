#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "espetaculo.h"
#include "biblioteca.h"

typedef struct espetaculo Espetaculo;

void modulo_Espetaculo(void) {
    char opcao;
    do {
        opcao = menu_Espetaculo();
        switch(opcao) {
            case '1': 	cadastrar_Espetaculo();
                        break;
            case '2': 	consultar_Espetaculo();
                        break;
            case '3': 	alterar_Espetaculo();
                        break;
            case '4': 	excluir_Espetaculo();
                        break;
        } 		
    } while (opcao != '0');
}


void cadastrar_Espetaculo(void) {
	Espetaculo* est;
	est = tela_cadastrar_Espetaculo();
	gravar_Espetaculo(est);
	free(est);
}  

void consultar_Espetaculo(void) {
	Espetaculo* est;
	char* id = NULL;
	id = tela_consultar_Espetaculo();
	est = buscar_Espetaculo(id);
	exibir_Espetaculo(est);
	free(est); 
	free(id);
}

void alterar_Espetaculo(void) {
	Espetaculo* est;
	char* id = NULL;
	id = tela_alterar_Espetaculo();
	est = buscar_Espetaculo(id);
	if (est == NULL) {
		printf("\n\nEspetaculo não encontrado!\n\n");
	} else {
		est = tela_cadastrar_Espetaculo();
		strcpy(est->id, id);
		regravar_Espetaculo(est);		
		free(est);
	}
	free(id);
}

void excluir_Espetaculo(void) {
	Espetaculo* est;
	char* id;
	id = tela_excluir_Espetaculo();
	est = (Espetaculo*) malloc(sizeof(Espetaculo));
	est = buscar_Espetaculo(id);
	if (est == NULL) {
		printf("\n\nEspetaculo não encontrado!\n\n");
	} else {
		est->status = False;
		regravar_Espetaculo(est);
		free(est);
	}
	free(id);
}



char menu_Espetaculo(void) {
    char op;
    limpaTela();
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


Espetaculo* tela_cadastrar_Espetaculo(void) {
    Espetaculo *est;
    est = (Espetaculo*) malloc(sizeof(Espetaculo));
    limpaTela();
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///            = = = = = = = Cadastrar Espetáculo = = = = = =               ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///                                                                         ///\n");
do {
    printf("///            ID (apenas números):    ");
    scanf("%[^\n]", est->id);
    getchar();
} while(!validarID(est->id)); 
do {	
    printf("///            Data (dd/mm/aaaa):      ");
    scanf("%[^\n]", est->data);
    getchar();
} while(!validarData(est->data));
do {
    printf("///            Horário (hh/mm/ss):     ");
    scanf("%[^\n]", est->horario);
    getchar();
} while(!validarHorario(est->horario)); 
    est->status = True;
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");    
    delay(1);
    return est;
}


char* tela_consultar_Espetaculo(void) {
    char* id;
    id = (char*) malloc(12*sizeof(char));
    limpaTela();
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
    return id;
}


char* tela_alterar_Espetaculo(void) {
    char* id;
    id = (char*) malloc(12*sizeof(char));
    limpaTela();
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
    return id;
}


char* tela_excluir_Espetaculo(void) {
    char* id;
    id = (char*) malloc(12*sizeof(char));
    limpaTela();
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
    return id;
}


void tela_Erro_Arquivo_Espetaculo(void) {
    limpaTela();
    printf("\n");
    printf("////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                      ///\n");
    printf("///           = = = = = = Erro: Não foi possível acessar = = = = = =     ///\n");
    printf("/// 	  = = = = = = = = = o banco de dados = = = = = = = = = =     ///\n");
    printf("///           = = = = = = O arquivo não foi encontrada = = = = = = =     ///\n");
    printf("///           = = = = = = = Se o problema persistir, = = = = = = = =     ///\n");
    printf("/// 	  = = = = entre em contato com o administrador.= = = = =     ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = = = = =     ///\n");
    printf("///                                                                      ///\n");
    printf("///                                                                      ///\n");
    printf("////////////////////////////////////////////////////////////////////////////\n");
    printf("\n\nTecle ENTER para continuar!\n\n");
    getchar();
    exit(1);
}

void gravar_Espetaculo(Espetaculo* est) {
	FILE* fp;
	fp = fopen("espetaculos.dat", "ab");
	if (fp == NULL) {
		tela_Erro_Arquivo_Espetaculo();
	}
	fwrite(est, sizeof(Espetaculo), 1, fp);
	fclose(fp);
}

Espetaculo* buscar_Espetaculo(char* id) {
	FILE* fp;
	Espetaculo* est;
	est = (Espetaculo*) malloc(sizeof(Espetaculo));
	fp = fopen("espetaculos.dat", "rb");
	if (fp == NULL) {
		tela_Erro_Arquivo_Espetaculo();
	}
	while(fread(est, sizeof(Espetaculo), 1, fp)) {
		if ((strcmp(est->id, id) == 0) && (est->status == True)) {
			fclose(fp);
			return est;
		}
	}
	fclose(fp);
	return NULL;
}


void exibir_Espetaculo(Espetaculo* est) {
	if (est == NULL) {
		printf("\n= = = Espetaculo Inexistente = = =\n");
	} else {
		printf("\n= = = Espetaculo Cadastrado = = =\n");
		printf("Id: %s\n", est->id);
		printf("Data: %s\n", est->data);
		printf("Horario: %s\n", est->horario);		
		printf("Status: %d\n", est->status);
	}
	printf("\n\nTecle ENTER para continuar!\n\n");
	getchar();
}


void regravar_Espetaculo(Espetaculo* est) {
	int achou;
	FILE* fp;
	Espetaculo* est_Lido;
	est_Lido = (Espetaculo*) malloc(sizeof(Espetaculo));
	fp = fopen("espetaculos.dat", "r+b");
	if (fp == NULL) {
		tela_Erro_Arquivo_Espetaculo();
	}
		achou = False;
		while(fread(est_Lido, sizeof(Espetaculo), 1, fp) && !achou) {		
			if (strcmp(est_Lido->id, est->id) == 0) {
				achou = True;
				fseek(fp, -1*sizeof(Espetaculo), SEEK_CUR);
				fwrite(est, sizeof(Espetaculo), 1, fp);
			}
		}
		fclose(fp);
		free(est_Lido);
	}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ingresso.h"
#include "biblioteca.h"

typedef struct ingresso Ingresso;

void modulo_Ingresso(void) {
    char opcao;
    do {
        opcao = menu_Ingresso();
        switch(opcao) {
            case '1': 	comprar_Ingresso();
                        break;
            case '2': 	reembolsar_Ingresso();
                        break;            
        } 		
    } while (opcao != '0');
}


char tela_menu_Ingresso(void) {
    char op;
    limpaTela();
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
    printf("///            Escolha a opção desejada:      ");
    scanf("%c", &op);
    getchar();
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    delay(1);
    return op;
}


Ingresso* tela_Preencher_Ingresso(void) {
    Ingresso *igs;
    limpaTela();
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///            = = = = = = = = Comprar ingresso = = = = = = =               ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///                                                                         ///\n");
    igs = (Ingresso*) malloc(sizeof(Ingresso));
    
    // Validação do ID
    do {
        printf("///            ID (apenas números):    ");
        scanf("%11s", igs->id);  // Limitar para 11 caracteres para evitar estouro de buffer
        getchar();  // Limpar o caractere de nova linha que fica no buffer
    } while(!validarID(igs->id)); 
    
    // Validação do Preço
    do {
        printf("///            Preço (apenas números):    ");
        scanf("%11s", igs->preco);  // Limitar para 11 caracteres para evitar estouro de buffer
        getchar();
    } while(!validarPreco(igs->preco)); 
    
    // Validação da Quantidade
    do {    
        printf("///            Quantidade (apenas números):     ");
        scanf("%d", &igs->quantidade);  // Corrigido para passar o endereço de 'quantidade'
        getchar();
    } while (!validarQuantidade(igs->quantidade));
    
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    delay(1);
    return igs;
}



char* tela_reembolsar_Ingresso(void) {
    char* id;
    id = (char*) malloc(12 * sizeof(char));  // Garantir que a memória é suficiente para o ID
    limpaTela();
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///            = = = = = = = = Reembolsar ingresso = = = = = =              ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///                                                                         ///\n");
    printf("///            Informe o ID (apenas números):   ");
    scanf("%11s", id);  // Limitar para 11 caracteres para evitar estouro de buffer
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
    printf("///           = = = O arquivo de Ingresso não foi encontrada = = = =     ///\n");
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


void gravar_Ingresso(Ingresso *igs) {
    FILE* fp = fopen("ingressos.dat", "ab");
    if (fp == NULL) {
        tela_Erro_Arquivo();
    }
    fwrite(igs, sizeof(Ingresso), 1, fp);
    fclose(fp);
    // A memória de igs não deve ser liberada aqui, pois a função que chama 'gravar_Ingresso' deve liberar
}



Ingresso* buscar_Ingresso(char* id) {
    FILE* fp;
    Ingresso* igs = (Ingresso*) malloc(sizeof(Ingresso));  // Aloca memória corretamente
    if (igs == NULL) {
        // Tratar erro de alocação de memória
        tela_Erro_Arquivo();
    }

    fp = fopen("ingressos.dat", "rb");
    if (fp == NULL) {
        tela_Erro_Arquivo();
    }
    
    while(fread(igs, sizeof(Ingresso), 1, fp)) {
        if (strcmp(igs->id, id) == 0 && igs->status == True) {
            fclose(fp);
            return igs;
        }
    }
    fclose(fp);
    free(igs);  // Liberar memória se o ingresso não for encontrado
    return NULL;
}



void exibir_Ingresso(Ingresso* igs) {
    if (igs == NULL) {
        printf("\n= = = Ingresso Inexistente = = =\n");
    } else {
        printf("\n= = = Ingresso Cadastrado = = =\n");
        printf("Id: %s\n", igs->id);
        printf("Preço: %s\n", igs->preco);
        printf("Quantidade: %d\n", igs->quantidade);  // Corrigir para 'igs->quantidade' ser do tipo 'int'
        printf("Status: %d\n", igs->status);
    }
    printf("\n\nTecle ENTER para continuar!\n\n");
    getchar();
}



void regravar_Ingresso(Ingresso* igs) {
    FILE* fp = fopen("ingressos.dat", "r+b");
    if (fp == NULL) {
        tela_Erro_Arquivo();
    }
    Ingresso* igs_Lido = (Ingresso*) malloc(sizeof(Ingresso));
    int achou = False;

    while(fread(igs_Lido, sizeof(Ingresso), 1, fp)) {
        if (strcmp(igs_Lido->id, igs->id) == 0) {
            achou = True;
            fseek(fp, -1 * sizeof(Ingresso), SEEK_CUR);  // Vai para o início do ingresso encontrado
            fwrite(igs, sizeof(Ingresso), 1, fp);
            break;
        }
    }

    if (!achou) {
        printf("Ingresso não encontrado para atualização.\n");
    }

    fclose(fp);
    free(igs_Lido);  // Libera a memória alocada
}



void comprar_Ingresso(void) {
	Ingresso *igs;
	igs = tela_Preencher_Ingresso();
	gravar_Ingresso(igs);
	free(igs);
}


void reembolsar_Ingresso(void) {
    Ingresso *igs;
    char* id;
    id = tela_reembolsar_Ingresso();  // Agora o ID é obtido da tela
    igs = buscar_Ingresso(id);
    if (igs == NULL) {
        printf("\n\nIngresso não encontrado!\n\n");
    } else {
        igs = tela_Preencher_Ingresso();
        strcpy(igs->id, id);  // Preserva o ID original
        regravar_Ingresso(igs);
    }
    free(id);  // Libera a memória alocada para o ID
}


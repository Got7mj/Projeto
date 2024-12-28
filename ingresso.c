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
            case '1':  comprar_Ingresso();
                        break;
            case '2':  reembolsar_Ingresso();
                        break; 
            case '3':  Ingressos_Vendidos();
                        break;                       
        }        
    } while (opcao != '0');
}

float precoPorIngresso = 5.0; // Preço de cada ingresso alterado para R$ 5,00
int ingressosVendidos = 0;

void comprar_Ingresso(void) {
    int quantidade;
    float total;
    Ingresso* igs;
    igs = tela_comprar_Ingresso();
    gravar_Ingresso(igs);
    free(igs);
	printf("Digite a quantidade de ingressos que deseja comprar: ");
	if (scanf("%d", &quantidade) != 1 || quantidade <= 0) {
		printf("Quantidade inválida! Por favor, insira um número positivo.\n");
		while(getchar() != '\n');  
		return;
	}   

    ingressosVendidos += quantidade;
    total = quantidade * precoPorIngresso;
    printf("Total a pagar: R$ %.2f\n", total);
}

void reembolsar_Ingresso(void) {
    Ingresso *igs;
    char* id = NULL;
    int quantidade;
    float reembolso;
    id = tela_reembolsar_Ingresso(); 
	igs = buscar_Ingresso(id);
	if (igs == NULL) {     
		printf("\n\nIngresso não encontrado!\n\n");
	} else {
		exibir_Ingressos_Vendidos(igs);
		printf("Digite a quantidade de ingressos que deseja reembolsar: ");
		if (scanf("%d", &quantidade) != 1 || quantidade <= 0 || quantidade > igs->quantidade) {
			printf("Quantidade inválida! Você não pode reembolsar mais ingressos do que comprou.\n");
			while (getchar() != '\n'); 
			return;
		}

        // Calcula o valor do reembolso
        reembolso = quantidade * precoPorIngresso;
        
        // Atualiza a quantidade de ingressos vendidos
        ingressosVendidos -= quantidade;
        igs->quantidade -= quantidade;

        // Exibe o valor do reembolso
        printf("Reembolso de R$ %.2f realizado com sucesso!\n", reembolso);

        // Registra a alteração do ingresso após o reembolso
        regravar_Ingresso(igs);
    }
	free(id);
}


void Ingressos_Vendidos() {
    FILE* fp = fopen("ingressos.dat", "rb");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo de ingressos.\n");
        return;
    }
    Ingresso igs;
    int encontrado = 0;
    printf("\n= = = Ingressos Vendidos = = =\n");
    while (fread(&igs, sizeof(Ingresso), 1, fp)) {
        if (igs.status == 1) { // 1 para ativo/vendido
            printf("ID: %s\n", igs.id);
            printf("Preço: %.2f\n", igs.preco);
            printf("Quantidade: %d\n", igs.quantidade);
            printf("Status: %s\n", (igs.status == 1) ? "Ativo" : "Inativo");
            printf("----------------------------\n");
            encontrado = 1;
        }
    }
    if (!encontrado) {
        printf("Nenhum ingresso vendido encontrado.\n");
    }
    fclose(fp);
}


char menu_Ingresso(void) {
    char op;
    limpaTela();
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///            = = = = = = = = =  Menu Ingresso = = = = = = =               ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///                                                                         ///\n");
    printf("///            1. Comprar ingressos                                         ///\n");
    printf("///            2. Reembolsar ingressos                                      ///\n");
    printf("///            3. Exibir ingressos vendidos                                 ///\n");
    printf("///            0. Voltar ao menu anterior                                   ///\n");
    printf("///                                                                         ///\n");
    printf("///            Escolha a opção desejada:      ");
    scanf(" %c", &op);  // Corrigir o uso de scanf para capturar o char corretamente
    getchar();
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    return op;
}

Ingresso* tela_comprar_Ingresso(void) {
    Ingresso *igs;
    igs = (Ingresso*) malloc(sizeof(Ingresso));
    limpaTela();
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///            = = = = = = = = Comprar ingresso = = = = = = =               ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///                                                                         ///\n");
    do {
        printf("///            ID (apenas números):    ");
        scanf("%11s", igs->id);  
        getchar();  
    } while(!validarID(igs->id)); 
    do {
        printf("///            Preço (apenas números):    ");
        scanf("%f", &igs->preco);  // Alterado para tipo float
        getchar();
    } while(!validarPreco(igs->preco)); 
    do {    
        printf("///            Quantidade (apenas números):     ");
        scanf("%d", &igs->quantidade);  
        getchar();
    } while (!validarQuantidade(igs->quantidade));
    igs->status = True;
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    delay(1);
    return igs;
}

char* tela_reembolsar_Ingresso(void) {
    char* id;
    id = (char*) malloc(12 * sizeof(char));  
    limpaTela();
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///            = = = = = = = = Reembolsar ingresso = = = = = =              ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///                                                                         ///\n");
    printf("///            Informe o ID (apenas números):   ");
    scanf("%11s", id);  
    getchar();
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    delay(1);
    return id;
}

char* tela_Ingressos_Vendidos() {
    FILE* fp;
    Ingresso* igs = (Ingresso*) malloc(sizeof(Ingresso));
    limpaTela();
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///           Ingressos vendidos:                                           ///\n");
    printf("///                                                                         ///\n");
    fp = fopen("ingressos.dat", "rb");
    if (fp == NULL) {
        tela_Erro_Arquivo_Ingresso();
    }
    int totalIngressos = 0;
	while (fread(igs, sizeof(Ingresso), 1, fp)) {
		if (igs->status == True) {
			totalIngressos += igs->quantidade;
			printf("ID: %s | Preço: %.2f | Quantidade: %d | Status: %s\n", 
				igs->id, igs->preco, igs->quantidade, 
				(igs->status == True) ? "Ativo" : "Inativo");
		}
	}
	fclose(fp);
	printf("///                                                                        ///\n");
	printf("///      Total de ingressos vendidos: %d\n", totalIngressos);
	printf("///                                                                         ///\n");
	printf("///////////////////////////////////////////////////////////////////////////////\n");
	free(igs);
	getchar();  
}


void tela_Erro_Arquivo_Ingresso(void) {
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

void gravar_Ingresso(Ingresso *igs) {
    FILE* fp = fopen("ingressos.dat", "ab");
    if (fp == NULL) {
        tela_Erro_Arquivo_Ingresso();
    }
    fwrite(igs, sizeof(Ingresso), 1, fp);
    fclose(fp);    
}


Ingresso* buscar_Ingresso(char* id) {
    FILE* fp;
    Ingresso igs;  
    fp = fopen("ingressos.dat", "rb");
    if (fp == NULL) {
        tela_Erro_Arquivo_Ingresso();
        return NULL;
    }
    while(fread(&igs, sizeof(Ingresso), 1, fp)) {
        if (strcmp(igs.id, id) == 0 && igs.status == True) {
            fclose(fp);
            Ingresso* resultado = (Ingresso*) malloc(sizeof(Ingresso));
            *resultado = igs;  
            return resultado;
        }
    }
    fclose(fp);
    return NULL;
}


void exibir_Ingressos_Vendidos(Ingresso* igs) {
    if (igs == NULL) {
        printf("\n= = = Ingresso Inexistente = = =\n");
    } else {
        printf("\n= = = Ingresso Cadastrado = = =\n");
        printf("ID: %s\n", igs->id);
        printf("Preço: %.2f\n", igs->preco);  
        printf("Quantidade: %d\n", igs->quantidade);  
        printf("Status: %s\n", (igs->status == True) ? "Ativo" : "Inativo");
    }

    printf("\n\nTecle ENTER para continuar!\n\n");
    getchar();  
}



void regravar_Ingresso(Ingresso* igs) {
	FILE* fp = fopen("ingressos.dat", "r+b");
	if (fp == NULL) {
		tela_Erro_Arquivo_Ingresso();
	}
	Ingresso* igs_Lido = (Ingresso*) malloc(sizeof(Ingresso));
	int achou = False;
	while(fread(igs_Lido, sizeof(Ingresso), 1, fp)) {
		if (strcmp(igs_Lido->id, igs->id) == 0) {
			achou = True;
			fseek(fp, -1 * sizeof(Ingresso), SEEK_CUR);  
			fwrite(igs, sizeof(Ingresso), 1, fp);
			break;
		}
	}
	if (!achou) {
		printf("Ingresso não encontrado para atualização.\n");
	}
	fclose(fp);
	free(igs_Lido); 
}

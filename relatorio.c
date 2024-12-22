#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblioteca.h"
#include "artista.h"
#include "espetaculo.h"
#include "ingresso.h"
#include "usuario.h"
#include "relatorio.h"


void modulo_Relatorio(void) {
	char opcao;
	do {
        opcao = menu_Relatorio();
        switch(opcao) {
            case '1':  listrar_Artista();
                    break;
            case '2':  listrar_Espetaculo();
                    break;
            case '3':  listrar_Ingresso();
                    break;
            case '4':  listrar_Usuario();
                    break;
        } 
    } while (opcao != '0');
}

char menuRelatorio(void) {
	char op;
    limpaTela();
	printf("\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("///                                                                       ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///           = = = = = = = =  Menu Relatório = = = = = = = =             ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///                                                                       ///\n");
	printf("///           1. Listar Artistas                                          ///\n");
	printf("///           2. Listar Espetaculos                                       ///\n");
	printf("///           3. Listar Ingressos                                         ///\n");
	printf("///           4. Listar Usuarios                                          ///\n");
	printf("///           0. Voltar ao menu anterior                                  ///\n");
	printf("///                                                                       ///\n");
	printf("///           Escolha a opção desejada: ");
	scanf("%c", &op);
	getchar();
	printf("///                                                                       ///\n");
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("\n");
	delay(1);
	return op;
}

void listar_Artistas(void) {
    FILE *fp;
    Artista *art;
    fp = fopen("artistas.dat", "rb");
    if (fp == NULL) {
        printf("Erro ao abrir arquivo de artistas.\n");
        return;
    }
    art = (Artista*)malloc(sizeof(Artista)); 
    while(fread(art, sizeof(Artista), 1, fp)) {
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                        Lista de Artistas                              ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("ID: %d\n", artista.id);
    printf("Nome: %s\n", artista.nome);
    printf("Email: %s\n", artista.email);
    printf("Celular: %s\n", artista.celular);
    printf("Cargo: %s\n", artista.cargo);
    printf("-------------------------------------------------\n");
    printf("Pressione qualquer tecla para sair...");
    getchar();
    }
    fclose(fp);
    free(art);
    return 0;
}

void listar_Espetaculos(void) {
    FILE *fp;
    Espetaculo *est;
    fp = fopen("espetaculos.dat", "rb");
    if (fp == NULL) {
        printf("Erro ao abrir arquivo de espetáculos.\n");
        return;
    }
    est = (Espetaculo*) malloc(sizeof(Espetaculo));
    while(fread(est, sizeof(Espetaculo), 1, fp)) {
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                        Lista de Espetáculos                            ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("ID: %d\n",espetaculo.id); 
    printf("Data: %s\n", espetaculo.data);
    printf("Horario: %s\n", espetaculo.horario);
    printf("-------------------------------------------------\n");
    printf("Pressione qualquer tecla para sair...");
    getchar();
    }
    fclose(fp);
    free(est);
    return 0;
}

void listar_Ingressos(void) {
    FILE *fp;
    Ingresso *igs;
    fp = fopen("ingressos.dat", "rb");
    if (fp == NULL) {
        printf("Erro ao abrir arquivo de ingressos.\n");
        return;
    }
    igs->(Ingresso*) malloc(sizeof(Ingresso));
    while (fread(&igs, sizeof(Ingresso), 1, fp)) {
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                        Lista de Ingressos                             ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("id: %s\n", igs.id);
    printf("Quantidade: %d\n", *igs.quantidade);
    printf("Preço: %.2f\n", igs.preco);
    printf("-------------------------------------------------\n");
    printf("Pressione qualquer tecla para sair...");
    getchar();
    }
    fclose(fp);
    free(igs);
    return 0;
}

void listar_Usuarios(void) {
    FILE *fp;
    Usuario *usr;    
    fp = fopen("usuarios.dat", "rb");
    if (fp == NULL) {
        printf("Erro ao abrir arquivo de usuários.\n");
        return;
    }
    usr = (Usuario*) malloc(sizeof(Usuario));
    while(fread(usr, sizeof(Usuario), 1, fp)) {
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                        Lista de Usuários                               ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("id: %s\n", usuario.id);
    printf("Nome: %s\n", usuario.nome);
    printf("E-mail: %s\n", usuario.email);
    printf("Celular: %s\n", usuario.celular);
    printf("Nasc: %d\n", usuario.idade);
    printf("-------------------------------------------------\n");
    }

    fclose(fp);
}

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
            case '1':  listar_Artistas();
		    break;
            case '2':  listar_Espetaculos(); 
		    break;
            case '3':  listar_Ingressos(); 
		    break;
            case '4':  listar_Usuarios(); 
                break;
        } 
    } while (opcao != '0');
}


char menu_Relatorio(void) {
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
    printf("///           2. Listar Espetáculos                                       ///\n");
    printf("///           3. Listar Ingressos                                         ///\n");
    printf("///           4. Listar Usuarios                                          ///\n");
    printf("///           0. Voltar ao menu anterior                                  ///\n");
    printf("///                                                                       ///\n");
    printf("///           Escolha a opção desejada: ");
    scanf(" %c", &op); 
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
        printf("////////////////////////////////////////////////////////////////////////////\n");
        printf("///                        Lista de Artistas                              ///\n");
        printf("/////////////////////////////////////////////////////////////////////////////\n");
        printf("ID: %d\n", art->id);  
        printf("Nome: %s\n", art->nome); 
        printf("Email: %s\n", art->email);  
        printf("Celular: %s\n", art->celular);  
        printf("Cargo: %s\n", art->cargo);  
        printf("-------------------------------------------------\n");
    }
    fclose(fp);
    free(art);
}


void listar_Espetaculos(void) {
    FILE *fp;
    Espetaculo *est;
    fp = fopen("espetaculos.dat", "rb");
    if (fp == NULL) {
        printf("Erro ao abrir arquivo de espetáculos.\n");
        return;
    }
    est = (Espetaculo*)malloc(sizeof(Espetaculo));
    while(fread(est, sizeof(Espetaculo), 1, fp)) {
        printf("///////////////////////////////////////////////////////////////////////////////\n");
        printf("///                        Lista de Espetáculos                            ///\n");
        printf("///////////////////////////////////////////////////////////////////////////////\n");
        printf("ID: %d\n", est->id);  
        printf("Data: %s\n", est->data);  
        printf("Horario: %s\n", est->horario);  
        printf("-------------------------------------------------\n");
    }
    fclose(fp);
    free(est);
}


void listar_Ingressos(void) {
    FILE *fp;
    Ingresso *igs;
    fp = fopen("ingressos.dat", "rb");
    if (fp == NULL) {
        printf("Erro ao abrir arquivo de ingressos.\n");
        return;
    }
    igs = (Ingresso*)malloc(sizeof(Ingresso));  
    while(fread(igs, sizeof(Ingresso), 1, fp)) {
        printf("///////////////////////////////////////////////////////////////////////////////\n");
        printf("///                        Lista de Ingressos                             ///\n");
        printf("///////////////////////////////////////////////////////////////////////////////\n");
        printf("ID: %d\n", igs->id);  
        printf("Quantidade: %d\n", igs->quantidade);  
        printf("Preço: %.2f\n", igs->preco);  
        printf("-------------------------------------------------\n");
    }
    fclose(fp);
    free(igs);
}


void listar_Usuarios(void) {
    FILE *fp;
    Usuario *usr;
    fp = fopen("usuarios.dat", "rb");
    if (fp == NULL) {
        printf("Erro ao abrir arquivo de usuários.\n");
        return;
    }
    usr = (Usuario*)malloc(sizeof(Usuario));
    while(fread(usr, sizeof(Usuario), 1, fp)) {
        printf("///////////////////////////////////////////////////////////////////////////////\n");
        printf("///                        Lista de Usuários                               ///\n");
        printf("///////////////////////////////////////////////////////////////////////////////\n");
        printf("ID: %d\n", usr->id);  
        printf("Nome: %s\n", usr->nome);  
        printf("E-mail: %s\n", usr->email);  
        printf("Celular: %s\n", usr->celular);  
        printf("Nasc: %d\n", usr->idade);  
        printf("-------------------------------------------------\n");
    }
    fclose(fp);
    free(usr);
}

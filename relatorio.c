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
	    case '5':  listar_Artistas_Com_Filtro();
		    break;
            case '6':  listar_Espetaculos_Com_Filtro(); 
		    break;
            case '7':  listar_Ingressos_Com_Filtro(); 
		    break;
            case '8':  listar_Usuarios_Com_Filtro(); 
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
    printf("///           5. Listar Artistas com Filtro                               ///\n");
    printf("///           6. Listar Espetáculos com Filtro                            ///\n");
    printf("///           7. Listar Ingressos com Filtro                              ///\n");
    printf("///           8. Listar Usuarios com Filtro                               ///\n");
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
        printf("ID: %s\n", art->id);  
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
        printf("ID: %s\n", est->id);  
	printf("Nome: %s\n", est->nome);
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
        printf("ID: %s\n", igs->id);  
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
        printf("ID: %s\n", usr->id);  
        printf("Nome: %s\n", usr->nome);  
        printf("E-mail: %s\n", usr->email);  
        printf("Celular: %s\n", usr->celular);  
        printf("Nasc: %s\n", usr->nasc);  
        printf("-------------------------------------------------\n");
    }
    fclose(fp);
    free(usr);
}

void listar_Artistas_Com_Filtro(void) {
    char nome_filtro[50];
    FILE *fp;
    Artista *art;
    fp = fopen("artistas.dat", "rb");
    if (fp == NULL) {
        printf("Erro ao abrir arquivo de artistas.\n");
        return;
    }
    art = (Artista*)malloc(sizeof(Artista));
	printf("Digite o Nome do Artista: ");
	getchar(); 
	fgets(nome_filtro, 50, stdin);
	nome_filtro[strcspn(nome_filtro, "\n")] = '\0';  
	while (fread(art, sizeof(Artista), 1, fp)) {
		if (strstr(art->nome, nome_filtro)) {
			printf("ID: %s\n", art->id);
			printf("Nome: %s\n", art->nome);
			printf("Email: %s\n", art->email);
			printf("Celular: %s\n", art->celular);
			printf("Cargo: %s\n", art->cargo);
			printf("-------------------------------------------------\n");
		}
	}
	fclose(fp);
	free(art);
}


void listar_Espetaculos_Com_Filtro(void) {
    char id_filtro[50];	z
    FILE *fp;
    Espetaculo *est;
    fp = fopen("espetaculos.dat", "rb");
    if (fp == NULL) {
        printf("Erro ao abrir arquivo de espetáculos.\n");
        return;
    }
    est = (Espetaculo*)malloc(sizeof(Espetaculo));
	while (fread(est, sizeof(Espetaculo), 1, fp)) {
                if (strcmp(est->data, data_filtro) == 0) {
                    printf("ID: %s\n", est->id);
		    printf("Nome: %s\n", est->nome);
                    printf("Data: %s\n", est->data);
                    printf("Horario: %s\n", est->horario);
                    printf("-------------------------------------------------\n");
                }
            }
	fclose(fp);
	free(est);
}

void listar_Ingressos_Com_Filtro(void) {
    FILE *fp;
    Ingresso *igs;    
    fp = fopen("ingressos.dat", "rb");
    if (fp == NULL) {
        printf("Erro ao abrir arquivo de ingressos.\n");
        return;
    }
    while (fread(&igs, sizeof(Ingresso), 1, fp)) {
	   // if (igs->quantidade > 10) {  
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///             Lista de Ingressos (Com Filtro - Quantidade > 10)           ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("Id: %s\n", igs->id);
    printf("Quantidade: %d\n", igs->quantidade);
    printf("Preço: %.2f\n", igs->preco);
    printf("-------------------------------------------------\n");
	    }
    }
    fclose(fp);
}


void listar_Usuarios_Com_Filtro(void) {
    char nome_filtro[50];
    FILE *fp;
    Usuario *usr;
       
    fp = fopen("usuarios.dat", "rb");
    if (fp == NULL) {
        printf("Erro ao abrir arquivo de usuários.\n");
        return;
    }

    usr = (Usuario*)malloc(sizeof(Usuario));
	printf("Digite o Nome do Usuário: ");
	getchar();  
	fgets(nome_filtro, 50, stdin);
	nome_filtro[strcspn(nome_filtro, "\n")] = '\0';  
	while (fread(usr, sizeof(Usuario), 1, fp)) {
		if (strstr(usr->nome, nome_filtro)) {
			printf("ID: %s\n", usr->id);
			printf("Nome: %s\n", usr->nome);
			printf("E-mail: %s\n", usr->email);
			printf("Celular: %s\n", usr->celular);
			printf("Nasc: %s\n", usr->nasc);
			printf("-------------------------------------------------\n");
		}
	}	
	fclose(fp);
	free(usr);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblioteca.h"
#include "artista.h"
#include "espetaculo.h"
#include "ingresso.h"
#include "usuario.h"
#include "relatorio.h"

/// Assinatura das funções


void modulo_Relatorio(void);
void delay(int);

void modulo_Relatorio(void) {
	// modulo em desenvolvimento
}
char menu_Relatorio() {
    // Implementação da função
}

// Função para listar todos os ingressos
void listar_Ingressos(void) {
    FILE *fp;
    Ingresso igs;
    fp = fopen("ingressos.dat", "rb");
    if (fp == NULL) {
        printf("Erro ao abrir arquivo de ingressos.\n");
        return;
    }

    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                        Lista de Ingressos                             ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");

    while (fread(&igs, sizeof(Ingresso), 1, fp)) {
        printf("Tipo: %s\n", igs.tipo);
        printf("Quantidade: %d\n", *igs.quantidade);
        printf("Preço: %.2f\n", igs.preco);
        printf("-------------------------------------------------\n");
    }

    fclose(fp);
}

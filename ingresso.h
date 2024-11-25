#ifndef INGRESSO_H
#define INGRESSO_H

#include <stdbool.h>  // Para usar o tipo 'bool' que facilita a leitura do código

// Definição da estrutura do ingresso
typedef struct ingresso {
    char id[12];        // ID do ingresso (apenas números)
    char preco[12];     // Preço do ingresso (apenas números, usando 12 caracteres para permitir valores maiores)
    int quantidade;     // Quantidade disponível
    bool status;        // Status de ativo ou cancelado (true ou false)
} Ingresso;

// Funções de manipulação de ingressos
bool validarID(char* id);
bool validarPreco(char* preco);
bool validarQuantidade(int quantidade);
Ingresso* tela_Preencher_Ingresso(void);
char* tela_reembolsar_Ingresso(void);
void tela_Erro_Arquivo(void);
void gravar_Ingresso(Ingresso* igs);
Ingresso* buscar_Ingresso(char* id);
void exibir_Ingresso(Ingresso* igs);
void regravar_Ingresso(Ingresso* igs);
void comprar_Ingresso(void);
void reembolsar_Ingresso(void);

#endif // INGRESSO_H

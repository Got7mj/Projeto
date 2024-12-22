#define ATIVO "ativo"
#define REEMBOLSADO "reembolsado"

typedef struct ingresso Ingresso;

struct ingresso {
    char id[12];   
    int *quantidade;        
    float preco;  
char status;
};

void modulo_Ingresso(void);
char menu_Ingresso(void);
Ingresso* tela_comprar_Ingresso(void);
char* tela_reembolsar_Ingresso(void);
void tela_Erro_Arquivo_Ingresso(void);
void gravar_Ingresso(Ingresso *igs);
Ingresso* buscar_Ingresso(char*);
void exibir_Ingresso(Ingresso *igs); 

void comprar_Ingresso(void);
void reembolsar_Ingresso(void);

/// Assinatura das funções

typedef struct ingresso Ingresso;

struct ingresso {
    char id[12];        
    char preco[12];     
    int quantidade;     
int status;
};

void modulo_Ingresso(void);
char menu_Ingresso(void);
Ingresso* tela_Preencher_Ingresso(void);
char* tela_reembolsar_Ingresso(void);
void tela_Erro_Arquivo(void);
void gravar_Ingresso(Ingresso*);
Ingresso* buscar_Ingresso(char*);
void exibir_Ingresso(Ingresso*);
void regravar_Ingresso(Ingresso*);
void comprar_Ingresso(void);
void reembolsar_Ingresso(void);



typedef struct ingresso Ingresso;

struct ingresso {
    char id[12];    
    float preco;
    int quantidade;  // Quantidade como int
    int status; 
};

void modulo_Ingresso(void);
char menu_Ingresso(void);
Ingresso* tela_comprar_Ingresso(void); 
char* tela_reembolsar_Ingresso(void);
char* tela_reembolsar_Ingresso(void);
void tela_Erro_Arquivo_Ingresso(void);
void gravar_Ingresso(Ingresso*);
Ingresso* buscar_Ingresso(char*);
void exibir_Ingresso_Vendidos(Ingresso*); 
void comprar_Ingresso(void);
void reembolsar_Ingresso(void);
void exibirIngressosVendidos(void);
void regravar_Ingresso(Ingresso*);

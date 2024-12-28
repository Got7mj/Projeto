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
char* tela_Ingresso_Vendidos(void);
void tela_Erro_Arquivo_Ingresso(void);
void comprar_Ingresso(void);
void reembolsar_Ingresso(void);
void Ingressos_Vendidos(void);
void gravar_Ingresso(Ingresso*);
Ingresso* buscar_Ingresso(char*);
void exibir_Ingressos_Vendidos(Ingresso*); 
void regravar_Ingresso(Ingresso*);

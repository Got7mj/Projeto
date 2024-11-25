typedef struct espetaculo Espetaculo;

struct espetaculo {
char id[12];
char data[12];
char horario[9];
int status;
};

void modulo_Espetaculo(void);
char menu_Espetaculo(void);
Espetaculo* tela_Preencher_Espetaculo(void);
char* tela_consultar_Espetaculo(void);
char* tela_alterar_Espetaculo(void);
char* tela_excluir_Espetaculo(void);
void tela_Erro_Espetaculo(void);
void gravar_Espetaculo(Espetaculo*);
Espetaculo* buscar_Espetaculo(char*);
void exibir_Espetaculo(Espetaculo*);
void regravar_Espetaculo(Espetaculo*); 
void cadastrar_Espetaculo(void);
void consultar_Espetaculo(void);
void alterar_Espetaculo(void);
void excluir_Espetaculo(void);

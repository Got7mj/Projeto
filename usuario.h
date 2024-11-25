/// Assinatura das funções

typedef struct usuario Usuario;

struct usuario{
char id[12];
char nome[51];   
char email[30];
char celular[12];
char nasc[11];
int status;
};

void modulo_Usuario(void);
char menu_Usuario(void);
Usuario* tela_Preencher_Usuario(void);
char* tela_consultar_Usuario(void);
char* tela_alterar_Usuario(void);
char* tela_excluir_Usuario(void);
void tela_Erro_Arquivo(void);
void gravar_Usuario(Usuario*);
Usuario* buscar_Usuario(char*);
void exibir_Usuario(Usuario*);
void regravar_Usuario(Usuario*);
void cadastrar_Usuario(void);
void consultar_Usuario(void);
void alterar_Usuario(void);
void excluir_Usuario(void);

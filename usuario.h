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
void tela_cadastrar_Usuario(void);
void tela_consultar_Usuario(void);
void tela_alterar_Usuario(void);
void tela_excluir_Usuario(void);
void cadastrar_Usuario(void);
void consultar_Usuario(void);
void alterar_Usuario(void);
void excluir_Usuario(void);

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

void modulo_usuario(void);
char menu_usuario(void);
void tela_cadastrar_usuario(void);
void tela_consultar_usuario(void);
void tela_alterar_usuario(void);
void tela_excluir_usuario(void);
void cadastrar_usuario(void);
void consultar_usuario(void);
void alterar_usuario(void);
void excluir_usuario(void);

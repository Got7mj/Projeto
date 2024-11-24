typedef struct espetaculo Espetaculo;

struct espetaculo {
char id[12];
char data[12];
char horario[9];
int status;
};

void modulo_Espetaculo(void);
char menu_Espetaculo(void);
void tela_cadastrar_Espetaculo(void);
void tela_consultar_Espetaculo(void);
void tela_alterar_Espetaculo(void);
void tela_excluir_Espetaculo(void);
void cadastrar_Espetaculo(void);
void consultar_Espetaculo(void);
void alterar_Espetaculo(void);
void excluir_Espetaculo(void);

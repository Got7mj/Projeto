typedef struct espetaculo Espetaculo;

struct espetaculo {
char id[12];
char data[12];
char horario[9];
int status;
};

void modulo_espetaculo(void);
char menu_espetaculo(void);
void tela_cadastrar_espetaculo(void);
void tela_consultar_espetaculo(void);
void tela_alterar_espetaculo(void);
void tela_excluir_espetaculo(void);
void cadastrar_espetaculo(void);
void consultar_espetaculo(void);
void alterar_espetaculo(void);
void excluir_espetaculo(void);

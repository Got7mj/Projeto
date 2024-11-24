/// Assinatura das funções

typedef struct artista Artista;

struct artista {
char id[12];
char nome[51]; 
char email[30];
char celular[12];
char cargo[30];
int status;
};

void modulo_Artista(void);
char menu_Artista(void);
void tela_cadastrar_Artista(void);
void tela_consultar_Artista(void);
void tela_alterar_Artista(void);
void tela_excluir_Artista(void);
void cadastrar_Artista(void);
void consultar_Artista(void);
void alterar_Artista(void);
void excluir_Artista(void);

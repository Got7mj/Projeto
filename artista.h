/// Assinatura das funções

typedef struct artista Artista;

struct artista {
char id[12];
char nome[51]; 
char email[30];
char celular[12];
char cargo[20];
int status;
};

void modulo_Artista(void);
char menu_Artista(void);
Artista* tela_cadastrar_Artista(void);
char* tela_consultar_Artista(void);
char* tela_alterar_Artista(void);
char* tela_excluir_Artista(void);
void tela_Erro_Arquivo_Artista(void);
void gravar_Artista(Artista*);
Artista* buscar_Artista(char*);
void exibir_Artista(Artista*);
void regravar_Artista(Artista*);
void cadastrar_Artista(void);
void consultar_Artista(void);
void alterar_Artista(void);
void excluir_Artista(void);

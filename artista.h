/// Assinatura das funções

void modulo_artista(void);
char menu_artista(void);
void tela_cadastrar_artista(void);
void tela_consultar_artista(void);
void tela_alterar_artista(void);
void tela_excluir_artista(void);
void cadastrar_artista(void);
void consultar_artista(void);
void alterar_artista(void);
void excluir_artista(void);

///
/// Funções de validação - serão transferidas para o módulo biblioteca.c
///

int validaId(char []);
int validaNome(char []);
int validaEmail(char []);
int validaCelular(char []);
int validaCargo(char []);

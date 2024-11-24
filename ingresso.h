typedef struct ingresso Ingresso;

struct ingresso {
char id[12];
char preco[3];
char quantidade[2];
 int status;
};

void modulo_ingresso(void);
char menu_ingresso(void);
void tela_comprar_ingresso(void);
void tela_reembolsar_ingresso(void);
void comprar_ingresso(void);
void reembolsar_ingresso(void);

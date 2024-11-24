typedef struct ingresso Ingresso;

struct ingresso {
char id[12];
char preco[3];
char quantidade[2];
 int status;
};

void modulo_Ingresso(void);
char menu_Ingresso(void);
void tela_comprar_Ingresso(void);
void tela_reembolsar_Ingresso(void);
void comprar_Ingresso(void);
void reembolsar_Ingresso(void);

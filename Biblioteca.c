#include <time.h>
#include <stdlib.h>
#include <string.h>

///////////////////////////////////////////////////////////////////////////////
/// Faz uma pausa por n segundos, com n sendo passado como parâmetro
///
void delay(int segundos) {
  int tempo = 1000 * segundos;
  clock_t inicio = clock();
  while (clock() < inicio + tempo) {
    // não faz nada, apenas gasta tempo
  }
} /// Autor: https://github.com/rauan-meirelles


///////// Limpa a tela//////////////

void limpaTela(void) {
  if (system("clear") {  
	
  }
} /// Autor: https://github.com/rauan-meirelles


///////////////////////////////////////////////////////////////////////////////
/// Autor: https://github.com/rauan-meirelles

int Digito(char c) {
  if (c >= '0' && c <= '9') {
    return 1;
  } else {
    return 0;
  }
}


///////////////////////////////////////////////////////////////////////////////
/// Retorna 1 se o caractere recebido for uma letra alfabético 
/// (entre 'A' e 'Z' ou 'a' e 'z') ou retorna 0 caso contrário
///
int Letra(char c) {
  if (c >= 'A' && c <= 'Z') {
    return 1;
  } else if (c >= 'a' && c <= 'z') {
    return 1;
  } else {
    return 0;
  }
}


/////////////////// Validar Nome //////////////////////////////////
/// Retorna 1 se string recebido for exclusivamente alfabético ou
/// retorna 0 caso contrário
///
int validarNome(char* nome) {
  for (int i=0; nome[i]!='\0'; i++) {
    if (!Letra(nome[i])) {
      return 0;
    }
  }
	return 1;
}/// Autor: https://github.com/rauan-meirelles


/////////////////////////////////////////
//// função necessária para criar a função que valida email

int caracteresEmail(char c) {
	// Verifica se o caractere é uma letra, dígito ou um dos caracteres válidos
    if ((!letra(c)) && (!Digito(c)) && (c != '@') && (c != '.') && (c != '_') && (c != '-')) {
        return 0;// Caractere válido
    }
    else {
        return 1;// Caractere inválido
    }
}////// AUTOR: https://github.com/quirinof


/////////////////// VALIDA EMAIL ///////////////////////
int validarEmail(char* email) {
    int i;
    int a = 0, p = 0;
    // verifica se o primeiro caractere é uma letra ou dígito
    if(!letra(email[0]) && !Digito(email[0])) {
            return 0;
        }
    for (i = 0; email[i] != '\0'; i++) {
        // verifica se o email contém apenas os caracteres válidos
        if (!caracteres_email(email[i])) {
            return 0;
        }
        // verificando quantidade de '@' e '.' no email
        if (email[i] == '@') {
            a++;
        }
        if (email[i] == '.') {
            p++;
        }
    }
    // Valida se há exatamente um '@' e pelo menos um '.'
    if (a != 1 || p < 1) {
        return 0;
    } 
	// Email válido
    return 1;
}//// AUTOR: https://github.com/quirinof


/////////////////// Valida Celular ///////////////////////
int validarCelular(char* celular[]) {
    int tam;
    tam = strlen(celular);
    if (tam != 11) {
        return 0;
    }
    for (int i = 0; i < tam; i++) {
        if (!Digito(celular[i])) {
            return 0;
        }
    }
    return 1;
}/// Autor: https://github.com/rauan-meirelles


///////////// Valida Id ////////////////////////// 
 

int validarID(char* id[]) {
    int tam;

    tam = strlen(id);
    if (tam < 10 || tam > 11) {
        return 0;
    }
    for (int i = 0; i < tam; i++) {
        if (!Digito(id[i])) {
            return 0;
        }
    }
    return 1;
}

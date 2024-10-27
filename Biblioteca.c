#include <time.h>
#include <stdlib.h>

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



///////////////////////////////////////////////////////////////////////////////
/// Limpa a tela

void limpaTela(void) {
  if (system("clear") || system("cls")) {
	  
	// limpa a tela, funciona em Linux, Mac e Windows
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

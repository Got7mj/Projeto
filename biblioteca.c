#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


///////////////////////////////////////////////////////////////////////////////
/// Faz uma pausa por n segundos, com n sendo passado como parâmetro
///Autor: https://github.com/rauan-meirelles
void delay(int segundos) {
  int tempo = 1000 * segundos;
  clock_t inicio = clock();
  while (clock() < inicio + tempo) {
    // não faz nada, apenas gasta tempo
  }
}  


///////// Limpa a tela//////////////
// Autor: https://github.com/rauan-meirelles
void limpaTela(void) {
  if (system("clear")) {  	
  }
} 


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
int letra(char c) {
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
    if (!letra(nome[i])) {
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
        if (!caracteresEmail(email[i])) {
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
/// Autor: https://github.com/rauan-meirelles

void validarCelular(char **celular, int tamanho) {
    int tam;
    for (int i = 0; i < tamanho; i++) {
        tam = strlen(celular[i]);
        for (int j = 0; j < tam; j++) {
            if (!Digito(celular[i][j])) {
            }
        }
    }
}


//////////// Função para verificar se um ano é bissexto ///////////////////
/// Retorna 1 se ano for bissexto e retorna 0 caso contrário
///
int Bissexto(int ano) {
  if ((ano % 4 == 0) && (ano % 100 != 0)) {
    return 1;
  } else if (ano % 400 == 0) {
    return 1;
  } else {
    return 0;
  }
}/// Autor: https://github.com/rauan-meirelles


///////////////////////////////////////////////////////////////////////////////
/// Retorna 1 se dia, mes e ano correspondem a uma data válida, inclusive
/// em anos bissextos, ou retorna 0 caso contrário
///
int Data(int dd, int mm, int aa) {
  int maiorDia;
  if (aa < 0 || mm < 1 || mm > 12)
    return 0;
  if (mm == 2) {
    if (Bissexto(aa)) 
      maiorDia = 29;
    else
      maiorDia = 28;
  } else if (mm == 4 || mm == 6 || mm == 9 || mm == 11) {
    maiorDia = 30;
  } else
    maiorDia = 31;
  if (dd < 1 || dd > maiorDia)
    return 0;
  return 1;
}// Autor: https://github.com/rauan-meirelles


///////////////// Validar Data ///////////////////////////////////////
/// Retorna 1 se string recebido corresponder a uma data válida (apenas dígitos
/// e no formato: ddmmaaaa) ou retorna 0 caso contrário
///
int validarData(char* data) {
  int tam, dia, mes, ano;
  tam = strlen(data);
  if (tam != 8) {
    return 0;
  }
  for (int i = 0; i < tam; i++) {
    if (!Digito(data[i])) {
      return 0;
    }
  }
  dia = (data[0] - '0') * 10 + (data[1] - '0');
  mes = (data[2] - '0') * 10 + (data[3] - '0');
  ano = (data[4] - '0') * 1000 + (data[5] - '0') * 100 + 
        (data[6] - '0') * 10 + (data[7] - '0');
  if (!Data(dia, mes, ano)) {
    return 0;
  }
  return 1;
}// Autor: https://github.com/rauan-meirelles


/////// Função para validar uma data de nascimento////////
int validarNasc(char* dataNasc) {
    if (!validarData(dataNasc)) {
        return 0; // Data inválida
    }

    // Extraindo o ano da data
    int ano = (dataNasc[4] - '0') * 1000 + (dataNasc[5] - '0') * 100 +
              (dataNasc[6] - '0') * 10 + (dataNasc[7] - '0');

    // Obtém a data atual
    time_t t = time(NULL);
    struct tm *now = localtime(&t);
    int anoAtual = now->tm_year + 1900;

    // Verifica se a data de nascimento é válida (não pode ser futura)
    if (ano > anoAtual) {
        return 0; // Data de nascimento não pode ser futura
    }

    return 1; // Data de nascimento válida
}// Autor: https://github.com/rauan-meirelles


///////////// Valida Id ////////////////////////// 
 int validarID(char* id) {
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


///////////// Valida Cargo ////////////////////////// 
// Função para validar o nome de um cargo

int validarCargo(char* cargo) {
    // Verifica se o cargo não é nulo ou vazio
    if (cargo == NULL || strlen(cargo) == 0) {
        return 0; // Cargo inválido
    }
    // Verifica o comprimento máximo (por exemplo, 27 caracteres)
    if (strlen(cargo) > 27) {
        return 0; 
    }
    // Verifica se contém caracteres inválidos (exemplo: números ou caracteres especiais)
    for (int i = 0; cargo[i] != '\0'; i++) {
        if (!letra(cargo[i]) && cargo[i] != ' ') {
            return 0; // Caractere inválido encontrado
        }
    }
    return 1; // Cargo válido
}


//////// Função para validar horário no formato hh:mm///////

int validarHorario(char* horario) {
    int hh, mm;
    if (strlen(horario) != 5 || horario[2] != ':') {
        return 0; // Formato inválido
    }
    hh = (horario[0] - '0') * 10 + (horario[1] - '0');
    mm = (horario[3] - '0') * 10 + (horario[4] - '0');
    if (hh < 0 || hh > 23 || mm < 0 || mm > 59) {
        return 0; 
    }
    return 1; 
}


////// Função para validar preço/////////////
int validarPreco(float preco) {
    if (preco > 0) {
        return 1; // Preço válido
    }
    else {
    return 0;
  }
}


/////// Função para validar quantidade///////////
int validarQuantidade(int quantidade) {
    if (quantidade > 0) {
        return 1;  // Quantidade válida
    }else {
    return 0;
  }
}

#include <stdio.h>
#include <string.h>

#define QTD_PESSOAS 5
#define TAM_NOME 30
#define TAM_TEMP 256

struct Pessoa {
  char nome[TAM_NOME];
  int idade;
  double peso, altura;
};

void lerStr(char *str, int count);
void lerPessoa(struct Pessoa *pessoa);
void imprimirPessoa(struct Pessoa pessoa);
double calcularIMC(struct Pessoa pessoa);

// exercícios: implemente as seguintes funções e utilize-as no main
double calcularMediaAltura(struct Pessoa vp[], int tam);
int encontrarPessoaMaisPesada(struct Pessoa vp[], int tam);
double calcularMediaIdadeIMCnormal(struct Pessoa vp[], int tam);

double calcularMediaAltura(struct Pessoa vp[], int tam) {
    double soma = 0.0;
    for (int i = 0; i < tam; i++) {
        soma += vp[i].altura;
    }
    return tam > 0 ? soma / tam : 0.0;
}

int encontrarPessoaMaisPesada(struct Pessoa vp[], int tam) {
    if (tam == 0) return -1;
    int indice = 0;
    for (int i = 1; i < tam; i++) {
        if (vp[i].peso > vp[indice].peso) {
            indice = i;
        }
    }
    return indice;
}

double calcularMediaIdadeIMCnormal(struct Pessoa vp[], int tam) {
    int cont = 0, somaIdade = 0;
    double mediaIdades = 0.0 , imc;
    for (int i = 0; i < tam; i++) {
        imc = calcularIMC(vp[i]); // Apenas atribuição, sem redeclaração
        if (imc >= 18.5 && imc <= 24.9) {
            somaIdade += vp[i].idade;
            cont++;
        }
    }
    return cont > 0 ? (double)somaIdade / cont : 0.0;
}

int main() {
  struct Pessoa pessoas[QTD_PESSOAS];
  for (int i = 0; i < QTD_PESSOAS; i += 1) {
    printf("----- Digitação dos dados da Pessoa %d -----\n", i + 1);
    lerPessoa(&pessoas[i]);
  }

  printf("\n\n");

  for (int i = 0; i < QTD_PESSOAS; i += 1) {
    printf("Impressão dados da Pessoa %d: ", i + 1);
    imprimirPessoa(pessoas[i]);
  }

  // Uso das funções implementadas
  printf("\nMédia das alturas: %.2f m\n", calcularMediaAltura(pessoas, QTD_PESSOAS));
  int idxMaisPesada = encontrarPessoaMaisPesada(pessoas, QTD_PESSOAS);
  if (idxMaisPesada != -1) {
      printf("Pessoa mais pesada: %s (%.2f kg)\n", pessoas[idxMaisPesada].nome, pessoas[idxMaisPesada].peso);
  }
  printf("Média das idades (IMC normal): %.2f anos\n", calcularMediaIdadeIMCnormal(pessoas, QTD_PESSOAS));

  return 0;
}

void lerStr(char *str, int count) {
  fgets(str, count, stdin);
  int tam = strlen(str);
  if (tam > 0 && str[tam - 1] == '\n') {
    str[tam - 1] = '\0';
  }
}

void lerPessoa(struct Pessoa *pessoa) {
  char tempStr[TAM_TEMP];
  printf("Digite o nome: ");
  lerStr(pessoa->nome, TAM_NOME); // lerStr((*pessoa).nome, TAM_NOME);
  printf("Digite a idade: ");
  scanf("%d", &pessoa->idade); // scanf("%d", &(*pessoa).idade);
  printf("Digite o peso: ");
  scanf("%lf", &pessoa->peso); // scanf("%lf", &(*pessoa).peso);
  printf("Digite a altura: ");
  scanf("%lf", &pessoa->altura); // scanf("%lf", &(*pessoa).altura);
  lerStr(tempStr, TAM_TEMP); // realiza a leitura do '\n' do scanf anterior
}

void imprimirPessoa(struct Pessoa pessoa) {
  double imc = calcularIMC(pessoa);
  printf("(%s, %d anos, %.2f kg, %.2f m, IMC %.2f)\n",
    pessoa.nome,
    pessoa.idade,
    pessoa.peso,
    pessoa.altura,
    imc
  );
}

double calcularIMC(struct Pessoa pessoa) {
  return pessoa.peso / (pessoa.altura * pessoa.altura);
}
#include <stdio.h>

// Constantes que definem o número máximo de linhas e colunas da matriz
const int QTD_LINHAS = 100;
const int QTD_COLUNAS = 200;

// Declaração das funções utilizadas no programa
void preencherMatrizDigitacao(int m[][QTD_COLUNAS], int linhas, int colunas);
void imprimirMatriz(int m[][QTD_COLUNAS], int linhas, int colunas);
int digitarIntervalo(int min, int max);

int main()
{
  // Declaração da matriz com o tamanho máximo permitido
  int matriz[QTD_LINHAS][QTD_COLUNAS];
  int qtdLinhas, qtdColunas; // Variáveis para armazenar o número de linhas e colunas da matriz

  // Solicita ao usuário o número de linhas da matriz
  printf("Digite o numero de linhas\n");
  qtdLinhas = digitarIntervalo(1, QTD_LINHAS); // Garante que o número de linhas esteja no intervalo permitido

  // Solicita ao usuário o número de colunas da matriz
  printf("\nDigite o numero de colunas\n");
  qtdColunas = digitarIntervalo(1, QTD_COLUNAS); // Garante que o número de colunas esteja no intervalo permitido

  // Solicita ao usuário que preencha os valores da matriz
  printf("\nPreencha a matriz\n");
  preencherMatrizDigitacao(matriz, qtdLinhas, qtdColunas);

  // Imprime a matriz preenchida
  printf("\n\nImpressao\n");
  imprimirMatriz(matriz, qtdLinhas, qtdColunas);

  return 0; // Indica que o programa terminou com sucesso
}

// Função para preencher a matriz com valores digitados pelo usuário
void preencherMatrizDigitacao(int m[][QTD_COLUNAS], int linhas, int colunas) {
  // Percorre todas as linhas da matriz
  for (int i = 0; i < linhas; i += 1) {
    // Percorre todas as colunas da matriz
    for (int j = 0; j < colunas; j += 1) {
      // Solicita ao usuário o valor para a posição [i][j] da matriz
      printf("Digite o valor de m[%d][%d]: ", i + 1, j + 1);
      scanf("%d", &m[i][j]); // Lê o valor digitado e armazena na matriz
    }
  }
}

// Função para imprimir os valores da matriz
void imprimirMatriz(int m[][QTD_COLUNAS], int linhas, int colunas) {
  // Percorre todas as linhas da matriz
  for (int i = 0; i < linhas; i += 1) {
    // Percorre todas as colunas da matriz
    for (int j = 0; j < colunas; j += 1) {
      // Imprime o valor da posição [i][j] seguido de uma tabulação
      printf("%d\t", m[i][j]);
    }
    // Quebra de linha após imprimir todos os valores de uma linha
    printf("\n");
  }
}

// Função para garantir que o usuário digite um valor dentro de um intervalo
int digitarIntervalo(int min, int max) {
  int num; // Variável para armazenar o valor digitado pelo usuário
  do {
    // Solicita ao usuário um valor dentro do intervalo [min, max]
    printf("Digite um valor entre %d e %d: ", min, max);
    scanf("%d", &num); // Lê o valor digitado
  } while (num < min || num > max); // Repete enquanto o valor estiver fora do intervalo
  return num; // Retorna o valor válido digitado pelo usuário
}
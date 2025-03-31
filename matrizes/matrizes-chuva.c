#include <stdio.h>
#include <stdlib.h>
#include <float.h> // Para utilizar a constante DBL_MAX (maior valor representável por um double)

// Constantes que definem o número de anos e meses
const int QTD_ANOS = 5;
const int QTD_MESES = 12;

// Declaração das funções utilizadas no programa
void preencherMatriz(double chuvas[QTD_ANOS][QTD_MESES]);
void imprimirMatriz(double chuvas[QTD_ANOS][QTD_MESES]);
void imprimirMesMaisSeco(double chuvas[QTD_ANOS][QTD_MESES]);
void imprimirMediaPorMes(double chuvas[QTD_ANOS][QTD_MESES]);

int main() {
   // Declaração da matriz para armazenar os dados de chuvas
   double chuvas[QTD_ANOS][QTD_MESES];

   // Inicializa o gerador de números aleatórios com uma semente fixa
   srand(7);

   // Preenche a matriz com valores aleatórios de chuvas
   preencherMatriz(chuvas);

   // Imprime a matriz de chuvas
   imprimirMatriz(chuvas);

   // Determina e imprime o mês/ano mais seco
   imprimirMesMaisSeco(chuvas);

   // Calcula e imprime a média de chuvas por mês e o mês mais seco em média
   imprimirMediaPorMes(chuvas);

   return 0; // Indica que o programa terminou com sucesso
}

// Função para preencher a matriz com valores aleatórios de chuvas
void preencherMatriz(double chuvas[QTD_ANOS][QTD_MESES]) {
   for (int i = 0; i < QTD_ANOS; i += 1) {
     for (int j = 0; j < QTD_MESES; j += 1) {
       // Gera um valor aleatório entre 0.0 e 99.9 (em mm)
       chuvas[i][j] = (rand() % 1000) / 10.0;
     }
   }
}

// Função para imprimir a matriz de chuvas
void imprimirMatriz(double chuvas[QTD_ANOS][QTD_MESES]) {
   // Imprime o cabeçalho com os números dos meses
   printf("      ");
   for (int i = 0; i < QTD_MESES; i += 1) {
     printf(" %2d  ", i + 1);
   }
   printf("\n");

   // Imprime os valores de chuvas para cada ano
   for (int i = 0; i < QTD_ANOS; i += 1) {
     printf("%d: ", 2020 + i); // Imprime o ano correspondente (começando em 2020)
     for (int j = 0; j < QTD_MESES; j += 1) {
       printf("%4.1f ", chuvas[i][j]); // Imprime o valor de chuvas com uma casa decimal
     }
     printf("\n");
   }
}

// Função para determinar e imprimir o mês/ano mais seco
void imprimirMesMaisSeco(double chuvas[QTD_ANOS][QTD_MESES]) {
   int mes = 0, ano = 0; // Variáveis para armazenar o índice do mês/ano mais seco

   // Percorre a matriz para encontrar o menor valor de chuvas
   for (int i = 0; i < QTD_ANOS; i += 1) {
     for (int j = 0; j < QTD_MESES; j += 1) {
       if (chuvas[i][j] < chuvas[ano][mes]) {
         ano = i; // Atualiza o índice do ano mais seco
         mes = j; // Atualiza o índice do mês mais seco
       }
     }
   }

   // Imprime o mês/ano mais seco
   printf("O mes/ano mais seco foi %d/%d\n", mes + 1, 2020 + ano);
}

// Função para calcular e imprimir a média de chuvas por mês
void imprimirMediaPorMes(double chuvas[QTD_ANOS][QTD_MESES]) {
   double soma, media, mediaMesMaisSeco = DBL_MAX; // Variáveis para soma, média e menor média
   int indiceMesMaisSeco = 0; // Índice do mês com a menor média

   // Percorre cada mês
   for (int j = 0; j < QTD_MESES; j += 1) {
     soma = 0.0; // Inicializa a soma das chuvas do mês

     // Soma as chuvas de todos os anos para o mês atual
     for (int i = 0; i < QTD_ANOS; i += 1) {
       soma += chuvas[i][j];
     }

     // Calcula a média de chuvas para o mês
     media = soma / QTD_ANOS;

     // Imprime a média de chuvas do mês
     printf("A media de chuvas no mes %2d = %4.1f\n", j + 1, media);

     // Verifica se a média atual é a menor já encontrada
     if (media < mediaMesMaisSeco) {
       mediaMesMaisSeco = media; // Atualiza a menor média
       indiceMesMaisSeco = j; // Atualiza o índice do mês mais seco
     }
   }

   // Imprime o mês com a menor média de chuvas
   printf("Em media, o mes mais seco eh %d com %.1f\n", indiceMesMaisSeco + 1, mediaMesMaisSeco);
}
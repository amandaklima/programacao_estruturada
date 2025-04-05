#include <stdio.h>
 
const int M = 30; // Número máximo de linhas da matriz
const int N = 20; // Número máximo de colunas da matriz

// Função para criar um vetor contendo o maior elemento de cada coluna de uma matriz
void criarVetorMaiorColuna(int m[][N], int v[], int qtdLinhas, int qtdColunas) {
   int maior; // Variável para armazenar o maior valor de uma coluna
   for (int j = 0; j < qtdColunas; j += 1) { // Itera sobre cada coluna
     maior = m[0][j]; // Inicializa o maior valor com o elemento da primeira linha da coluna
     for (int i = 0; i < qtdLinhas; i += 1) { // Itera sobre cada linha da coluna
       if (m[i][j] > maior) { // Verifica se o elemento atual é maior que o maior encontrado até agora
         maior = m[i][j]; // Atualiza o maior valor
       }
     }
     v[j] = maior; // Armazena o maior valor da coluna no vetor
   }
}
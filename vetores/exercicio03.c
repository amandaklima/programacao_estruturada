#include <stdio.h>

// Definindo uma constante para a quantidade de alunos
const int QTD_ALUNOS = 5;

// Função para preencher o vetor de notas da turma
void preencherNotasTurma(double notas[QTD_ALUNOS]) {
  printf("Digitacao de todas as notas da turma\n");
  for (int i = 0; i < QTD_ALUNOS; i += 1) {
    printf("Digite a nota %d: ", i + 1);
    scanf("%lf", &notas[i]); // Lendo a nota de cada aluno
  }
}

// Função para calcular a média das notas da turma
double calcularMediaTurma(double notas[QTD_ALUNOS]) {
  double somatorio = 0;
  for (int i = 0; i < QTD_ALUNOS; i += 1) {
    somatorio += notas[i]; // Somando todas as notas
  }
  return somatorio / QTD_ALUNOS; // Calculando a média
}

// Função para imprimir todas as notas da turma
void imprimirNotasTurma(double notas[QTD_ALUNOS]) {
  printf("\nImpressao de todas as notas da turma\n");
  for (int i = 0; i < QTD_ALUNOS; i += 1) {
    printf("Nota %d: %.2f\n", i + 1, notas[i]); // Imprimindo cada nota
  }
}

// Função para imprimir as notas acima da média da turma
void imprimirNotasAcimaMedia(double notas[QTD_ALUNOS], double media) {
  printf("\nImpressao de todas as notas acima da media da turma\n");
  for (int i = 0; i < QTD_ALUNOS; i += 1) {
    if (notas[i] > media) {
      printf("Nota %d: %.2f\n", i + 1, notas[i]); // Imprimindo notas acima da média
    }
  }
}

int main() {
  double notas[QTD_ALUNOS]; // Declarando o vetor de notas
  double media;
  preencherNotasTurma(notas); // Preenchendo o vetor com as notas dos alunos
  media = calcularMediaTurma(notas); // Calculando a média das notas
  printf("\nMedia da turma: %.2f\n", media); // Imprimindo a média da turma
  imprimirNotasTurma(notas); // Imprimindo todas as notas da turma
  imprimirNotasAcimaMedia(notas, media); // Imprimindo as notas acima da média
  return 0;
}
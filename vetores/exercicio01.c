#include <stdio.h>

// Definindo uma constante para a quantidade de alunos
const int QTD_ALUNOS = 3;

int main() {
  double notas[QTD_ALUNOS]; // Declarando o vetor de notas
  printf("Digitacao de todas as notas da turma\n");
  
  // Preenchendo o vetor com as notas dos alunos
  for (int i = 0; i < QTD_ALUNOS; i += 1) {
    printf("Digite a nota %d: ", i + 1);
    scanf("%lf", &notas[i]); // Lendo a nota de cada aluno e armazenando no vetor
  }

  printf("\nImpressao de todas as notas da turma\n");
  
  // Imprimindo todas as notas armazenadas no vetor
  for (int i = 0; i < QTD_ALUNOS; i += 1) {
    printf("Nota %d: %.2f\n", i + 1, notas[i]); // Imprimindo cada nota com duas casas decimais
  }
  
  return 0;
}
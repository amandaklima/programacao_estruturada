#include <stdio.h>
#include <math.h>

// Constante que define o limite máximo para a verificação de números primos
const int MAX_NUM = 10000000;

// Função para verificar se um número é primo (método básico)
int ehPrimo(int num) {
  // O número 1 não é primo
  if (num == 1) {
    return 0;
  }
  // Verifica se o número é divisível por qualquer valor entre 2 e num/2
  for (int divisor = 2; divisor < num / 2; divisor += 1) {
    if (num % divisor == 0) {
      return 0; // Se for divisível, não é primo
    }
  }
  return 1; // Se não for divisível por nenhum número, é primo
}

// Função otimizada para verificar se um número é primo
int ehPrimoOtimizada(int num) {
    int k = 1, a = 0, b = 0; // Variáveis auxiliares para o cálculo
    long sr; // Variável para armazenar a raiz quadrada do número

    // Casos especiais para números pequenos
    switch(num) {
        case 1: return 0; // 1 não é primo
        case 2: return 1; // 2 é primo
        case 3: return 1; // 3 é primo
        case 4: return 0; // 4 não é primo
        case 5: return 1; // 5 é primo
        case 6: return 0; // 6 não é primo
        case 7: return 1; // 7 é primo
    }

    // Números pares maiores que 2 não são primos
    if (num % 2 == 0) return 0;

    // Números divisíveis por 3 não são primos
    if (num % 3 == 0) return 0;

    // Calcula a raiz quadrada do número para limitar as verificações
    sr = (int) sqrt(num);

    // Verifica divisores no formato 6k ± 1 (otimização para números primos)
    while (b < sr) {
        a = (6 * k) - 1; // Primeiro divisor no formato 6k - 1
        b = (6 * k) + 1; // Segundo divisor no formato 6k + 1

        // Se o número for divisível por qualquer um dos divisores, não é primo
        if (num % a == 0)
            return 0;
        if (num % b == 0)
            return 0;

        k += 1; // Incrementa o valor de k para testar os próximos divisores
    }

    return 1; // Se não for divisível por nenhum divisor, é primo
}

int main() {
  int qtdPrimos = 0; // Contador para armazenar a quantidade de números primos encontrados

  // Exibe uma mensagem inicial indicando o intervalo de verificação
  printf("Listagem dos numeros primos entre 1 e %d\n", MAX_NUM);

  // Loop para verificar todos os números entre 1 e MAX_NUM
  for (int num = 1; num <= MAX_NUM; num += 1) {
    // Verifica se o número é primo usando a função otimizada
    if (ehPrimoOtimizada(num)) {
      qtdPrimos += 1; // Incrementa o contador de números primos
      printf("%d ", num); // Imprime o número primo
    }
  }

  // Exibe a quantidade total de números primos encontrados
  printf("\n\nExistem %d primos entre 1 e %d\n\n", qtdPrimos, MAX_NUM);

  return 0; // Indica que o programa terminou com sucesso
}
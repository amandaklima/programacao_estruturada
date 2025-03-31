/*
 Neste problema você deverá ler 15 valores colocá-los em 2 vetores 
 conforme estes valores forem pares ou ímpares. Só que o tamanho de
 cada um dos dois vetores é de 5 posições. Então, cada vez que um dos
 dois vetores encher, você deverá imprimir todo o vetor e utilizá-lo
 novamente para os próximos números que forem lidos. Terminada a leitura,
 deve-se imprimir o conteúdo que restou em cada um dos dois vetores,
 imprimindo primeiro os valores do vetor impar. Cada vetor pode ser
 preenchido tantas vezes quantas for necessário.
 
 Entrada
 A entrada contém 15 números inteiros.
 
 Saída
 Imprima a saída conforme o exemplo abaixo.
 */

 #include <stdio.h>

 // Constantes para definir a quantidade de números a serem lidos e o tamanho dos vetores
 const int QTD_NUMEROS = 15;
 const int TAM_VETOR = 5;
 
 // Função para imprimir os elementos de um vetor
 void imprimir(int v[], int n, char *nomeVetor);
 
 int main() {
    // Declaração dos vetores para armazenar números pares e ímpares
    int par[TAM_VETOR], impar[TAM_VETOR];
    int num, qtdPares = 0, qtdImpares = 0; // Variáveis para armazenar o número lido e as quantidades de pares/ímpares
 
    // Loop para ler os 15 números
    for (int i = 0; i < QTD_NUMEROS; i += 1) {
      scanf("%d", &num); // Lê um número inteiro
 
      // Verifica se o número é par
      if (num % 2 == 0) {
        par[qtdPares] = num; // Adiciona o número ao vetor de pares
        qtdPares += 1; // Incrementa a quantidade de pares
 
        // Se o vetor de pares estiver cheio, imprime e reinicia o contador
        if (qtdPares == TAM_VETOR) {
          imprimir(par, qtdPares, "par");
          qtdPares = 0;
        }
      } else { // Caso contrário, o número é ímpar
        impar[qtdImpares] = num; // Adiciona o número ao vetor de ímpares
        qtdImpares += 1; // Incrementa a quantidade de ímpares
 
        // Se o vetor de ímpares estiver cheio, imprime e reinicia o contador
        if (qtdImpares == TAM_VETOR) {
          imprimir(impar, qtdImpares, "impar");
          qtdImpares = 0;
        }
      }
    }
 
    // Após o loop, imprime os elementos restantes nos vetores (se houver)
    imprimir(impar, qtdImpares, "impar");
    imprimir(par, qtdPares, "par");
 }
 
 // Função para imprimir os elementos de um vetor
 void imprimir(int v[], int n, char *nomeVetor) {
    // Percorre o vetor e imprime cada elemento no formato especificado
    for (int i = 0; i < n; i += 1) {
      printf("%s[%d] = %d\n", nomeVetor, i, v[i]);
    }
 }
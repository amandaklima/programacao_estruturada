#include <stdio.h>

const int TAM = 5; // Define o tamanho máximo do vetor original

// Declaração das funções utilizadas no programa
int inserirVetor(int v[], int n);
int imprimirVetor(int v[], int n);
int inserirOrdenado(int v[], int n, int x);
int criarVetorOrdenado(int vetOrig[], int vetOrd[], int tamVetOrig);
int buscaBinaria(int v[], int n, int x);

int main() {
   int vetOrig[TAM], vetOrd[100]; // vetOrig: vetor original, vetOrd: vetor ordenado
   int tamVetOrig = 0, tamVetOrd = 0; // tamVetOrig: tamanho atual do vetor original, tamVetOrd: tamanho do vetor ordenado
   int opcao, num, pos; // Variáveis auxiliares para o menu, número a ser inserido e posição encontrada

   do {
     // Exibe o menu de opções para o usuário
     printf("\nMENU\n\n");
     printf("1 - Inserir 1 valor no vetor\n");
     printf("2 - Criar vetor ordenado\n");
     printf("3 - Busca Binária\n");
     printf("Digite sua opcao (0 p/ finalizar): ");
     scanf("%d", &opcao); // Lê a opção escolhida pelo usuário

     switch (opcao) {
     case 1:
       // Insere um valor no vetor original
       tamVetOrig = inserirVetor(vetOrig, tamVetOrig);
       printf("vetOrig = ");
       imprimirVetor(vetOrig, tamVetOrig); // Imprime o vetor original atualizado
       break;
     case 2:
       // Cria o vetor ordenado a partir do vetor original
       tamVetOrd = criarVetorOrdenado(vetOrig, vetOrd, tamVetOrig);
       break;
     case 3:
       // Realiza a busca binária no vetor ordenado
       tamVetOrd = criarVetorOrdenado(vetOrig, vetOrd, tamVetOrig); // Garante que o vetor esteja ordenado
       printf("Digite um numero para realizar a busca: ");
       scanf("%d", &num); // Lê o número a ser buscado
       pos = buscaBinaria(vetOrd, tamVetOrd, num); // Realiza a busca binária
       if (pos != -1) {
         // Se o número foi encontrado, exibe a posição
         printf("Achou o valor %d na posicao %d\n", num, pos + 1);
       } else {
         // Caso contrário, informa que o número não foi encontrado
         printf("Nao achou o valor %d\n", num);
       }
       break;
     default:
       // Caso o usuário insira uma opção inválida
       if (opcao != 0) {
         printf("Opcao invalida!\n");
       }
       break;
     }
   } while (opcao != 0); // O programa continua até que o usuário escolha a opção 0 (sair)

   return 0; // Finaliza o programa
}

// Função para imprimir os elementos de um vetor
int imprimirVetor(int v[], int n) {
   for (int i = 0; i < n; i += 1) {
     printf("%d ", v[i]); // Imprime cada elemento do vetor
   }
   printf("\n");
}

// Função para inserir um valor no vetor original
int inserirVetor(int v[], int n) {
   if (n < TAM) { // Verifica se ainda há espaço no vetor
     printf("Digite um valor inteiro: ");
     scanf("%d", &v[n]); // Lê o valor a ser inserido
     return n + 1; // Retorna o novo tamanho do vetor
   } else {
     printf("Vetor cheio!\n"); // Mensagem de erro caso o vetor esteja cheio
     return n; // Retorna o tamanho atual do vetor
   }
}

// Função para inserir um valor no vetor de forma ordenada
int inserirOrdenado(int v[], int n, int x) {
   int pos = n; // Começa pela última posição do vetor
   if (pos < TAM) { // Verifica se há espaço no vetor
     // Move os elementos maiores que x para a direita
     while (pos > 0 && v[pos - 1] > x) {
       v[pos] = v[pos - 1];
       pos -= 1;
     }
     v[pos] = x; // Insere o valor na posição correta
     return n + 1; // Retorna o novo tamanho do vetor
   } else {
     printf("Vetor cheio!\n"); // Mensagem de erro caso o vetor esteja cheio
     return n; // Retorna o tamanho atual do vetor
   }
}

// Função para criar um vetor ordenado a partir do vetor original
int criarVetorOrdenado(int vetOrig[], int vetOrd[], int tamVetOrig) {
   int tamVetOrd = 0; // Inicializa o tamanho do vetor ordenado
   for (int i = 0; i < tamVetOrig; i += 1) {
     tamVetOrd = inserirOrdenado(vetOrd, tamVetOrd, vetOrig[i]); // Insere cada elemento de forma ordenada
   }
   printf("vetOrig = ");
   imprimirVetor(vetOrig, tamVetOrig); // Imprime o vetor original
   printf("vetOrd = ");
   imprimirVetor(vetOrd, tamVetOrd); // Imprime o vetor ordenado
   return tamVetOrd; // Retorna o tamanho do vetor ordenado
}

// Função para realizar a busca binária em um vetor ordenado
int buscaBinaria(int v[], int n, int x) {
   int inicio = 0, fim = n - 1, meio; // Define os limites inicial e final
   while (inicio <= fim) { // Continua enquanto houver elementos para buscar
     meio = (inicio + fim) / 2; // Calcula o índice do meio
     if (v[meio] == x) {
       return meio; // Retorna a posição se o valor for encontrado
     } else if (x < v[meio]) {
       fim = meio - 1; // Ajusta o limite final se o valor for menor
     } else {
       inicio = meio + 1; // Ajusta o limite inicial se o valor for maior
     }
   }
   return -1; // Retorna -1 se o valor não for encontrado
}
#include <stdio.h>
#include <stdlib.h>

#define MAX_TAMANHO 50

// Função para inserir elemento de forma ordenada
void inserirOrdenado(int vetor[], int *tamanho, int valor) {
    int i, j;
    
    // Se o vetor está cheio, não insere
    if (*tamanho >= MAX_TAMANHO) {
        printf("Vetor está cheio. Não é possível inserir mais elementos.\n");
        return;
    }
    
    // Se o vetor está vazio, insere no início
    if (*tamanho == 0) {
        vetor[0] = valor;
        (*tamanho)++;
        return;
    }
    
    // Encontra a posição para inserir mantendo a ordenação
    for (i = 0; i < *tamanho; i++) {
        if (valor <= vetor[i]) {
            // Desloca elementos para a direita
            for (j = *tamanho; j > i; j--) {
                vetor[j] = vetor[j-1];
            }
            vetor[i] = valor;
            (*tamanho)++;
            return;
        }
    }
    
    // Se o valor é maior que todos, insere no final
    vetor[*tamanho] = valor;
    (*tamanho)++;
}

// Função de busca binária
int buscaBinaria(int vetor[], int tamanho, int valor) {
    int inicio = 0, fim = tamanho - 1, meio;
    
    while (inicio <= fim) {
        meio = (inicio + fim) / 2;
        
        if (vetor[meio] == valor) {
            return meio;  // Elemento encontrado, retorna sua posição
        }
        
        if (valor < vetor[meio]) {
            fim = meio - 1;
        } else {
            inicio = meio + 1;
        }
    }
    
    return -1;  // Elemento não encontrado
}

// Função para remover elemento
void removerElemento(int vetor[], int *tamanho, int posicao) {
    int i;
    
    // Desloca elementos para preencher o espaço do elemento removido
    for (i = posicao; i < *tamanho - 1; i++) {
        vetor[i] = vetor[i+1];
    }
    
    // Reduz o tamanho do vetor
    (*tamanho)--;
}

// Função para imprimir o vetor
void imprimirVetor(int vetor[], int tamanho) {
    int i;
    
    printf("Vetor: ");
    for (i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

int main() {
    int vetor[MAX_TAMANHO];
    int tamanho_max, tamanho = 0, opcao, valor, posicao;
    
    // Solicitar tamanho do vetor
    do {
        printf("Digite o tamanho do vetor (entre 3 e 50 elementos): ");
        scanf("%d", &tamanho_max);
    } while (tamanho_max < 3 || tamanho_max > 50);
    
    // Preencher vetor de forma ordenada
    printf("Digite %d valores inteiros para preencher o vetor:\n", tamanho_max);
    
    while (tamanho < tamanho_max) {
        scanf("%d", &valor);
        inserirOrdenado(vetor, &tamanho, valor);
    }
    

    while (1) {
        printf("\nMenu:\n");
        printf("1. Imprimir vetor\n");
        printf("2. Consultar posição de um elemento\n");
        printf("3. Remover elemento\n");
        printf("4. Inserir elemento\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        
        if (opcao == 1) {
            imprimirVetor(vetor, tamanho);
        }
        else if (opcao == 2) {
            printf("Digite o valor a ser buscado: ");
            scanf("%d", &valor);
            posicao = buscaBinaria(vetor, tamanho, valor);
            
            if (posicao != -1) {
                printf("Elemento encontrado na posição %d\n", posicao);
            } else {
                printf("Elemento não encontrado\n");
            }
        }
        else if (opcao == 3) {
            printf("Digite o valor a ser removido: ");
            scanf("%d", &valor);
            posicao = buscaBinaria(vetor, tamanho, valor);
            
            if (posicao != -1) {
                removerElemento(vetor, &tamanho, posicao);
                printf("Elemento removido com sucesso\n");
            } else {
                printf("Elemento não encontrado\n");
            }
        }
        else if (opcao == 4) {
            if (tamanho >= MAX_TAMANHO) {
                printf("Vetor está cheio, não é possível inserir mais elementos.\n");
            } else {
                printf("Digite o valor a ser inserido: ");
                scanf("%d", &valor);
                inserirOrdenado(vetor, &tamanho, valor);
                printf("Elemento inserido com sucesso\n");
            }
        }
        else if (opcao == 0) {
            printf("Encerrando o programa\n");
            break;
        }
        else {
            printf("Opção inválida\n");
        }
    }
    
    return 0;
}
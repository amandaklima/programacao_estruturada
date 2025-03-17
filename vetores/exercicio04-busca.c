#include <stdio.h>
#include <stdlib.h>
#include <time.h>


const int QTD = 100;


// inserir o valor x de forma ordenada
//pos tem  o indice da próxima posição livre do vetor
    
    void inserirOrdenado(int v[QTD], int x, int pos) {
    int i = pos - 1;
    
    while (i >= 0 && v[i] > x) {
        v[i + 1] = v[i];
        i -= 1;
    }

    v[i + 1] = x;
}
// Função para preencher o vetor com valores aleatórios
void preencherVetorAleatorio(int v[QTD]) {
    for (int i = 0; i < QTD; i += 1) {
    // v[i] = rand() % 1000 + 1;
    inserirOrdenado (v, rand()% 1000 +1, i);
    }
  }
// Função para imprimir os valores do vetor
void imprimirVetor(int v[QTD]) {
    for (int i = 0; i < QTD; i += 1) {
        printf("%d ", v[i]); // Imprimindo cada valor do vetor
    }
    printf("\n");
}

// só funciona se o vetor estiver ordenado
int buscaMelhorada(int v[QTD], int x) {
    int i = 0;
    while (i < QTD && v[i] < x){
        i += 1;
    }

    if (i < QTD && v[i]== x){
        return i;
    }
    return -1; 
}

int main() {
    int numeros[QTD]; 
    int num, pos;
    // srand(time(NULL)); // Inicializando o gerador de números aleatórios com a hora atual
    srand(7); // Inicializando o gerador de números aleatórios com uma semente fixa para resultados reprodutíveis
    preencherVetorAleatorio(numeros); // Preenchendo o vetor com valores aleatórios
    imprimirVetor(numeros); // Imprimindo o vetor com os números aléatórios gerados

    printf("Digite um valor entre 1 e 1000: ");
    scanf("%d", &num); 
    
    while (num >= 1 && num <= 1000) { // Continuar enquanto o valor estiver no intervalo válido
        pos = buscar(numeros, num); // Buscando o valor no vetor
        if (pos != -1) {
            printf("O numero %d esta dentro do vetor na %da posicao!\n", num, pos + 1); 
        } else {
            printf("O numero %d nao esta dentro do vetor!\n", num); 
        }
        printf("Digite um valor entre 1 e 1000: ");
        scanf("%d", &num); 
    }
    return 0;
}
#include <stdio.h>

struct Produto {
    int codigo;
    char nome[50];
    double preco;
};

void selectionSortPreco(struct Produto p[], int n) {
    int i, j, min_idx;
    struct Produto temp;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (p[j].preco < p[min_idx].preco) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            temp = p[i];
            p[i] = p[min_idx];
            p[min_idx] = temp;
        }
    }
}

int main() {
    struct Produto produtos[] = {
        {1, "Produto A", 29.99},
        {2, "Produto B", 19.99},
        {3, "Produto C", 49.99},
        {4, "Produto D", 9.99},
        {5, "Produto E", 39.99}
    };

    int n = sizeof(produtos) / sizeof(produtos[0]);
    
    
    selectionSortPreco(produtos, n);
    
    
    printf("Produtos ordenados por preço:\n");
    for (int i = 0; i < n; i++) {
        printf("%d - %s: %.2f\n", produtos[i].codigo, produtos[i].nome, produtos[i].preco);
    }
    
    return 0;
}
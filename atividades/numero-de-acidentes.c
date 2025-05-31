#include <stdio.h>
#include <string.h>

#define TOTAL_ESTADOS 26

typedef struct {
    char nome[30];
    int veiculos;
    int acidentes;
} Estado;

// Nomes fixos dos 26 estados brasileiros
const char nomesEstados[TOTAL_ESTADOS][30] = {
    "Acre", "Alagoas", "Amapa", "Amazonas", "Bahia", "Ceara", "Distrito Federal",
    "Espirito Santo", "Goias", "Maranhao", "Mato Grosso", "Mato Grosso do Sul",
    "Minas Gerais", "Para", "Paraiba", "Parana", "Pernambuco", "Piaui",
    "Rio de Janeiro", "Rio Grande do Norte", "Rio Grande do Sul", "Rondonia",
    "Roraima", "Santa Catarina", "Sao Paulo", "Sergipe"
};

// (a) Coletar dados (exceto nome) do usuário
void coletarDados(Estado estados[]) {
    for (int i = 0; i < TOTAL_ESTADOS; i++) {
        strcpy(estados[i].nome, nomesEstados[i]);

        printf("\n[%d] Estado: %s\n", i + 1, estados[i].nome);
        printf("Informe o número de veículos em 2007: ");
        scanf("%d", &estados[i].veiculos);
        printf("Informe o número de acidentes em 2007: ");
        scanf("%d", &estados[i].acidentes);
    }
}

// (b) Encontrar maior e menor número de acidentes
void encontrarMaiorMenorAcidente(Estado estados[], int *indiceMaior, int *indiceMenor) {
    *indiceMaior = *indiceMenor = 0;
    for (int i = 1; i < TOTAL_ESTADOS; i++) {
        if (estados[i].acidentes > estados[*indiceMaior].acidentes) {
            *indiceMaior = i;
        }
        if (estados[i].acidentes < estados[*indiceMenor].acidentes) {
            *indiceMenor = i;
        }
    }
}

// (c) Percentual de veículos envolvidos em acidentes
float calcularPercentualAcidentes(Estado estados[], int i) {
    if (estados[i].veiculos == 0) return 0;
    return (100.0 * estados[i].acidentes) / estados[i].veiculos;
}

// (d) Média de acidentes no país
float calcularMediaAcidentes(Estado estados[]) {
    int total = 0;
    for (int i = 0; i < TOTAL_ESTADOS; i++) {
        total += estados[i].acidentes;
    }
    return (float)total / TOTAL_ESTADOS;
}

// (e) Exibir estados acima da média de acidentes
void estadosAcimaDaMedia(Estado estados[], float media) {
    for (int i = 0; i < TOTAL_ESTADOS; i++) {
        if (estados[i].acidentes > media) {
            printf("%s (%d acidentes)\n", estados[i].nome, estados[i].acidentes);
        }
    }
}

int main() {
    Estado estados[TOTAL_ESTADOS];
    int maior, menor;
    float media;

    // (a)
    coletarDados(estados);

    // (b)
    encontrarMaiorMenorAcidente(estados, &maior, &menor);
    printf("\n== Resultados ==\n");
    printf("Maior número de acidentes: %d (%s)\n", estados[maior].acidentes, estados[maior].nome);
    printf("Menor número de acidentes: %d (%s)\n", estados[menor].acidentes, estados[menor].nome);

    // (c)
    printf("\nPercentual de veículos envolvidos em acidentes por estado:\n");
    for (int i = 0; i < TOTAL_ESTADOS; i++) {
        float percentual = calcularPercentualAcidentes(estados, i);
        printf("%s: %.2f%%\n", estados[i].nome, percentual);
    }

    // (d)
    media = calcularMediaAcidentes(estados);
    printf("\nMédia de acidentes no país: %.2f\n", media);

    // (e)
    printf("\nEstados com número de acidentes acima da média:\n");
    estadosAcimaDaMedia(estados, media);

    return 0;
}

#include <stdio.h>

int main() {
    char sexo;
    int idade, totalMulheres = 0, mulheresMenos50kg = 0, homensMenos30 = 0;
    float peso, somaPesoHomensMenos30 = 0, pesoMaisPesada = 0;
    int idadeMaisPesada = 0;

    
    while (1) {
        
        printf("Digite o sexo (M/F) ou 'S' para sair o resultado: ");
        scanf(" %c", &sexo);
        if (sexo == 'S' || sexo == 's') {
            break;
        }

        
        printf("Digite a idade: ");
        scanf("%d", &idade);

        
        printf("Digite o peso: ");
        scanf("%f", &peso);

        // Verifica se a pessoa atual é a mais pesada até agora
        if (peso > pesoMaisPesada) {
            pesoMaisPesada = peso;
            idadeMaisPesada = idade;
        }

        // Processa os dados de acordo com o sexo
        if (sexo == 'M' || sexo == 'm') {
            // Se for homem e tiver menos de 30 anos, acumula o peso e conta
            if (idade < 30) {
                somaPesoHomensMenos30 += peso;
                homensMenos30++;
            }
        } else if (sexo == 'F' || sexo == 'f') {
            // Se for mulher, conta o total de mulheres
            totalMulheres++;
            // Se pesar menos de 50 kg, conta as mulheres com menos de 50 kg
            if (peso < 50) {
                mulheresMenos50kg++;
            }
        }
    }

    printf("A idade da pessoa mais pesada: %d\n", idadeMaisPesada);

    if (homensMenos30 > 0) {
        printf("A média de peso dos homens com menos de 30 anos: %.2f\n", somaPesoHomensMenos30 / homensMenos30);
    } else {
        printf("Não há homens com menos de 30 anos.\n");
    }

    
    if (totalMulheres > 0) {
        printf("O percentual de mulheres com menos de 50 kg: %.2f%%\n", (mulheresMenos50kg / (float)totalMulheres) * 100);
    } else {
        printf("Não há mulheres.\n");
    }

    return 0;
}

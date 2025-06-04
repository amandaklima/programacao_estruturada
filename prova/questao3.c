#include <stdio.h>
#include <string.h>

#define MAX_PACIENTES 100

struct Paciente {
    char nome[100];
    int idade;
    char sexo; 
};

void preencherPacientes(struct Paciente pacientes[], int n);
void imprimirPacientes(struct Paciente pacientes[], int n);
void ordenarPorNome(struct Paciente pacientes[], int n);
void contarSexo(struct Paciente pacientes[], int n);
void filtrarMaioresIdade(struct Paciente pacientes[], int n);

int main() {
    struct Paciente pacientes[MAX_PACIENTES];
    int n;

    printf("Digite o número de pacientes: ");
    scanf("%d", &n);
    getchar(); 

    if (n <= 0 || n > MAX_PACIENTES) {
        printf("Número inválido.\n");
        return 1;
    }

    preencherPacientes(pacientes, n);

    int opcao;
    do {
        printf("\n--- MENU ---\n");
        printf("1. Imprimir pacientes\n");
        printf("2. Ordenar por nome\n");
        printf("3. Contar por sexo\n");
        printf("4. Filtrar maiores de idade\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1:
                imprimirPacientes(pacientes, n);
                break;
            case 2:
                ordenarPorNome(pacientes, n);
                printf("Pacientes ordenados por nome.\n");
                break;
            case 3:
                contarSexo(pacientes, n);
                break;
            case 4:
                filtrarMaioresIdade(pacientes, n);
                break;
            case 0:
                printf("Encerrando...\n");
                break;
            default:
                printf("Opção inválida.\n");
        }
    } while (opcao != 0);

    return 0;
}

void preencherPacientes(struct Paciente pacientes[], int n) {
    for (int i = 0; i < n; i++) {
        printf("\nPaciente %d:\n", i + 1);

        printf("Nome: ");
        fgets(pacientes[i].nome, sizeof(pacientes[i].nome), stdin);
        strtok(pacientes[i].nome, "\n");

        printf("Idade: ");
        scanf("%d", &pacientes[i].idade);
        getchar();

        do {
            printf("Sexo (M/F): ");
            scanf(" %c", &pacientes[i].sexo);
            getchar();
        } while (pacientes[i].sexo != 'M' && pacientes[i].sexo != 'F');
    }
}

void imprimirPacientes(struct Paciente pacientes[], int n) {
    printf("\n--- Lista de Pacientes ---\n");
    for (int i = 0; i < n; i++) {
        printf("Nome: %s | Idade: %d | Sexo: %c\n",
               pacientes[i].nome, pacientes[i].idade, pacientes[i].sexo);
    }
}

void ordenarPorNome(struct Paciente pacientes[], int n) {
    struct Paciente temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(pacientes[j].nome, pacientes[j + 1].nome) > 0) {
                temp = pacientes[j];
                pacientes[j] = pacientes[j + 1];
                pacientes[j + 1] = temp;
            }
        }
    }
}

void contarSexo(struct Paciente pacientes[], int n) {
    int masc = 0, fem = 0;
    for (int i = 0; i < n; i++) {
        if (pacientes[i].sexo == 'M') masc++;
        else if (pacientes[i].sexo == 'F') fem++;
    }
    printf("\nTotal Masculino: %d\n", masc);
    printf("Total Feminino: %d\n", fem);
}

void filtrarMaioresIdade(struct Paciente pacientes[], int n) {
    printf("\n--- Pacientes Maiores de Idade (18+) ---\n");
    int encontrou = 0;
    for (int i = 0; i < n; i++) {
        if (pacientes[i].idade >= 18) {
            printf("Nome: %s | Idade: %d | Sexo: %c\n",
                   pacientes[i].nome, pacientes[i].idade, pacientes[i].sexo);
            encontrou = 1;
        }
    }
    if (!encontrou)
        printf("Nenhum paciente maior de idade encontrado.\n");
}

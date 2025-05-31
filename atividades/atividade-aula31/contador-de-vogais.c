#include <stdio.h>    
#include <string.h>
#include <ctype.h>    

int contarVogais(const char *frase) {

    int cont = 0;  


    for (int i = 0; frase[i] != '\0'; i++) {
        // Converte o caractere para minúsculo
        char c = tolower(frase[i]);

    
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            cont++;  
        }
    }

    return cont;  
}

// Função que transforma a primeira letra de cada palavra em maiúscula
void capitalizarPalavras(char *frase) {
    int i = 0;
    int novoInicio = 1; 

    // Percorre a frase até o final
    while (frase[i] != '\0') {
        if (frase[i] == ' ') {
            // Se o caractere for espaço, a próxima letra será o início de uma nova palavra
            novoInicio = 1;
        } else if (novoInicio && frase[i] >= 'a' && frase[i] <= 'z') {
    
            frase[i] = frase[i] - 32; // Converte para maiúsculo subtraindo 32 
            novoInicio = 0; 
        } else {
            novoInicio = 0; 
        }
        i++; // Passa para o próximo caractere
    }
}


int main() {
    char frase[201]; 

    
    printf("Digite uma frase (até 200 caracteres): ");
    fgets(frase, sizeof(frase), stdin); 
    // Remove a quebra de linha que o fgets pode armazenar
    frase[strcspn(frase, "\n")] = '\0';

    
    printf("\nFrase digitada: %s\n", frase);

    // Conta as vogais 
    int numVogais = contarVogais(frase);
    printf("Número de vogais: %d\n", numVogais);

    capitalizarPalavras(frase);
    printf("Frase com iniciais maiúsculas: %s\n", frase);

    return 0; 
}

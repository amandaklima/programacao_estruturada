
#include <stdio.h>
#define MAX_REPETCOES 5

// variaveis camel case variavelTipo tudo junto 
//constante #define VARIAVEL_TIPO maiusculo e _

int main() {
    int num1, num2;
    printf("Digite um número inteiro:");
    scanf("%d", &num1);

    printf("Digite um número inteiro maior que %d\n", num1);
    scanf("%d", &num2);

    // estrutura do while
    while (num2 <= num1 && quantidadeRepeticoes <=MAX_REPETCOES){
        quantidadeRepeticoes = quantidadeRepeticoes +1;
        
        printf("Valor digitado é invalido! %d\n", num1);
        printf("Digite um número inteiro maior que %d\n", num1);
        scanf("%d", &num2);
    }
    if ( quantidadeRepeticoes <=MAX_REPETCOES){
        printf("Existem %d valores no intervalo de \n", num1);

    return 0;
}

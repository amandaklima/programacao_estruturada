#include <stdio.h>
// main e printf são algumas das funçoes da biblioteca stdio 
int main () {
        printf("Olá mundo!\n");
        return 0;
}

// int, float, double, char e void são todos tipos de dados utilizados para declarar variáveis

int main () {
    int n1 = 5;
    double n2 = 5.0 / 2;
    double n3; 
    char letra = 'a';
    // Um caractere se usa apóstrofo 'a', string e texto com aspas "amanda"

    // Para exibir dados na tela, você usa o símbolo % seguido de um especificador de formato para controlar como os valores serão apresentados.
    // O % indica o tipo de dado a ser impresso, e o que vem após ele define o formato, como inteiros, floats, strings, etc.

    // O & você utiliza no scanf e não no printf, ele é pra indicar que você vai mexer num local de memória
    //%f pode ser usado para ler tanto float quanto double (por convenção e compatibilidade).
    //%lf é o especificador correto para ler um valor do tipo double.
    printf ("Digite um valor inteiro: ");
    scanf("%lf", &n3);
    
    //%.2f é usado para restringir e quantidade de casas decimais que aparecerá na tela
    printf("n1 = %d e n2 = %.2f e n3 = %.2f\n", n1, n2, n3);
    printf("letra = %c\n", letra);
    return 0;
}


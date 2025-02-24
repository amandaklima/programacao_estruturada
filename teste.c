// for com números que possuem exatamente 2 divisores = primos 
#include <stdio.h>

int main (){
    int num;
    printf("Digite um numero inteiro:\n");
    scanf("%d", &num);

    int divisor, qtdDivisores =0;
    for (divisor =1; divisor <= num; divisor +=1){
        if (num % divisor == 0){
          qtdDivisores +=1;

        }
    }
    if (qtdDivisores == 2) {
        printf ("%d nao eh um numero primo\n", num);
    }
    else
    {
        printf ("%d eh um numero primo\n", num);
    }
    
}
return 0;
}


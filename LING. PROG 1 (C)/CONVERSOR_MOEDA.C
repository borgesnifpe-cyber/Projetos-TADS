#include <stdio.h>
#include <stdlib.h>

int main()
{
    float Real,dolar;
    
    printf ("Insira o valor em real\n");
    scanf("%f",&Real);
    dolar=Real/5.65;
    printf ("%.2f reais equivalem a %.2f dolares", Real, dolar);

    return 0;
}
#include <stdio.h>
//#include <omp.h>

long long num_passos = 1000000000;
double passo;

int main()
{
    int  i;
    double x, pi, soma = 0.0f;

    passo = 1.0f/(double)num_passos;

    #pragma omp parallel for simd private(x) reduction(+:soma)
    for (i = 0; i < num_passos; i++)
    {
        x = (i + 0.5)*passo;
        soma = soma + 4.0f/(1.0f + x*x);
    }

    pi = soma*passo;

    printf("O valor de PI eh: %f\n", pi);

    return 0;
}
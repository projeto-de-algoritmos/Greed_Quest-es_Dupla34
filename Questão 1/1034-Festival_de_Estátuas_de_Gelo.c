#include <stdio.h>
// Macro que retorna o menor valor entre dois inteiros
#define min(a, b) (a < b ? a : b)

/*
    
Variáveis globais:

N = número de blocos
M = tamanho da mochila
blocos = vetor com os tamanhos dos blocos
mochila = vetor com a quantidade de blocos necessários para preencher a mochila

*/
int N, M, blocos[25], mochila[1000001];

// Função que calcula a quantidade de blocos necessários para preencher a mochila
int knapsack()
{
    for (int i = 1; i <= M; ++i)
    {
        mochila[i] = -1;
    }
    mochila[0] = 0;

    for (int i = 0; i < N; ++i)
    {
        int bloco = blocos[i];

        for (int j = bloco; j <= M; ++j)
        {
            if (mochila[j - bloco] != -1)
            {
                if (mochila[j] == -1)
                {
                    mochila[j] = mochila[j - bloco] + 1;
                }
                else
                {
                    mochila[j] = min(mochila[j], mochila[j - bloco] + 1);
                }
            }
        }
    }

    return mochila[M];
}

int main()
{
    // número de casos de teste
    int size;
    scanf("%d", &size);
    
    for (int k = 0; k < size; ++k)
    {
        scanf("%d %d", &N, &M);
        for (int i = 0; i < N; ++i)
        {
            scanf("%d", &blocos[i]);
        }

        printf("%d\n", knapsack());
    }

    return 0;
}
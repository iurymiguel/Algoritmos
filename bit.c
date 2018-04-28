#include <stdio.h>
#define TAM 7

typedef struct BIT
{
    int *parents;
    int *values;
} BIT;

void setBitParents(BIT *bit, int n)
{
    int i, index;
    (*bit).parents[0] = -1;

    for (i = 1; i < n; i++)
    {
        index = i;
        index -= index & (-index);
        (*bit).parents[i] = index;
    }
}

/*Atualiza a BIT. Nó 0 é a raiz, sempre com valor 0. Cada posição x do vetor
original será representada na posição x+1 da BIT.*/
void setBitValues(BIT *bit, int arr[], int n)
{
    int i, parent = (*bit).parents[n + 1], val = 0;

    /* soma a partir da posição do nó pai, até a posição
    correspondente ao nó no vetor original*/
    for (i = parent; i <= n; i++)
    {
        val += arr[i];
    }

    (*bit).values[n + 1] = val;
}

//Constrói e retorna uma BIT para um dado vetor arr de tamanho n.
BIT constructBITree(int arr[], int n)
{
    int i, parents[n + 1], values[n + 1];
    static BIT bit;

    bit.parents = parents;
    bit.values = values;

    setBitParents(&bit, n + 1);


    bit.values[0] = 0;

    for (i = 0; i < n; i++)
    {
        setBitValues(&bit, arr, i);
    }

    return bit;
}
//Retorna a soma dos elementos de arr[0..index].
int getSum(int index)
{
    return 0;
}

int main()
{

    int i, arr[TAM];

    arr[0] = 3;
    arr[1] = 2;
    arr[2] = -1;
    arr[3] = 6;
    arr[4] = 5;
    arr[5] = 4;
    arr[6] = -3;

    BIT bit = constructBITree(arr, TAM);

    int index = 1;
    index -= index & (-index);

    printf("%d\n", index);

    index = 4;
    index += index & (-index);

    printf("%d\n", index);

    index = 4;
    index = index & (-index);

    printf("%d\n", index);

    return 0;
}
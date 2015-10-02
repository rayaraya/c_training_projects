#include <stdio.h>
#include <stdlib.h>

int* Input (int* pNum, const int nLen);
void Qsort (int* pNum, int Start, int Stop);
void Output (int* pNum, const int nLen);
void Swap (int* a, int* b);

int main ()
{
    int N;

    printf ("Please input the number of elements in the array for sort: ");

    if ((scanf("%d", &N) != 1)|| N <= 0)
    {
        printf("Unfortunately, wrong input.");
        return 0;
    }


    int* pNum = (int*) calloc (N, sizeof (*pNum));

    Input (pNum, N);
    if (*pNum == 0) return 0;
    Qsort (pNum, 0, N-1);
    Output (pNum, N);

    free (pNum);
    pNum = NULL;

    return 0;
}

int* Input (int* pNum, const int nLen)
{
    int i, end = 0;

    printf ("Please input array elements: ");

    for (i = 0; i < nLen; i++)
    {
        if ((scanf ("%d", &pNum[i])) != 1)  end = 1;
    }

    if (end == 1)
    {
        printf("Unfortunately, wrong input.");
        return 0;
    }

    return pNum;
}

void Output (int* pNum, const int nLen)
{
    int i;

    for (i = 0; i < nLen; i++) printf ("%d ", pNum[i]);
}

void Swap(int* a, int* b)
{
    int c = *a;
    *a = *b;
    *b = c;
}

void Qsort (int* pNum, int Start, int Stop)
{

    if (Start != Stop)
    {

        int i = Start, j = Stop, Medm;

        Medm = pNum[(i + j) / 2 ];

        while (i <= j)
        {
            while (pNum[i] < Medm) i++;
            while (pNum[j] > Medm) j--;

            if (i <= j) Swap(&pNum[i++], &pNum[j--]);
        }

        if (Start < j)
            Qsort(pNum, Start, j);
        if (Stop > i)
            Qsort(pNum, i , Stop );
    }
}



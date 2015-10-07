#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include <string.h>

int* Input (int* pNum, const int nLen);
void Mergesort (int* pNum, const int nLen);
void Output (int* pNum, const int nLen);
void Swap(int* a, int* b);

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
    Mergesort (pNum, N);
    Output (pNum, N);

    free (pNum);
    pNum = NULL;

    return 0;
}

void Mergesort (int* pNum, const int nLen)
{
    if (nLen <= 1) {}
    else if (nLen == 2)
    {
        if(pNum[0] > pNum[1])
            Swap(&pNum[0], &pNum[1]);
    }
    else
    {
        Mergesort(&(pNum[(nLen / 2)]), nLen / 2 + nLen % 2);
        Mergesort(&(pNum[0]), nLen / 2);

        int* pS = (int*) calloc (nLen, sizeof(*pS));

        int i = 0, j = floor(nLen / 2), k = 0;

        for (k = 0; k < nLen; k++)
        {
            assert(i < floor(nLen / 2) || j < nLen);

            if (pNum[i] < pNum[j])
            {
                pS[k] = pNum[i];
                i++;

                if (i == floor(nLen / 2))
                {
                    for (k++; j < nLen; j++, k++)
                            pS[k] = pNum[j];
                    assert(k == nLen);
                }
            }
            else
            {
                pS[k] = pNum[j];
                j++;

                if (j == nLen)
                {
                    for (k++; i < floor(nLen / 2); i++, k++)
                        pS[k] = pNum[i];
                    assert(k == nLen);
                }
            }
        }
        memcpy(pNum, pS, nLen * sizeof(*pNum));
    }
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

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include <string.h>
#include <time.h>

#define QU 1000000

void Mergesort (int* pNum, const int nLen);
void Qsort (int* pNum, int Start, int Stop);
void Swap(int* a, int* b);
void Compare_in_file (time_t time_1, time_t time_2, time_t time_12, time_t time_22);
void Compare_in_console (time_t time_1, time_t time_2, time_t time_12, time_t time_22);
void Create_file_with_rand_numb ();

int main ()
{
    int N = 0, i = 0;


    void Create_file_with_rand_numb ();

    time_t time_1, time_2, time_12, time_22;

    FILE* file = fopen ("numbers.txt", "r");

    fscanf(file, "%d", &N);

    int* pNum = (int*) calloc (N, sizeof (*pNum));

    for (i = 0; i < N; i++)
    {
        fscanf(file, "%d", &pNum[i]);
    }
    int* pNum1 = (int*) calloc (N, sizeof (*pNum1));

    for (i = 0; i < N; i++)
    {
        pNum1[i] = pNum[i];
    }

    if (*pNum == 0) return 0;

    time (&time_1);
    Qsort (pNum, 0, N - 1);
    time (&time_2);

    time (&time_12);
    Mergesort (pNum1, N);
    time (&time_22);

    Compare_in_file (time_1, time_2, time_12, time_22);

    Compare_in_console (time_1, time_2, time_12, time_22);

    free (pNum);
    pNum = NULL;

    free (pNum1);
    pNum1 = NULL;

    return 0;
}

void Mergesort (int* pNum, const int nLen)
{
    if (nLen <= 1) {}
    else if (nLen == 2)
    {
        if(pNum[0] > pNum[1])
            Swap (&pNum[0], &pNum[1]);
    }
    else
    {
        Mergesort(&(pNum[(nLen / 2)]), nLen / 2 + nLen % 2);
        Mergesort(&(pNum[0]), nLen / 2);

        int* pS = (int*) calloc (nLen, sizeof(*pS));

        int i = 0, j = floor (nLen / 2), k = 0;

        for (k = 0; k < nLen; k++)
        {
            assert(i < floor (nLen / 2) || j < nLen);

            if (pNum[i] < pNum[j])
            {
                pS[k] = pNum[i];
                i++;

                if (i == floor (nLen / 2))
                {
                    for (k++; j < nLen; j++, k++)
                            pS[k] = pNum[j];
                    assert (k == nLen);
                }
            }
            else
            {
                pS[k] = pNum[j];
                j++;

                if (j == nLen)
                {
                    for (k++; i < floor (nLen / 2); i++, k++)
                        pS[k] = pNum[i];
                    assert (k == nLen);
                }
            }
        }
        memcpy (pNum, pS, nLen * sizeof(*pNum));
    }
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


void Swap(int* a, int* b)
{
    int c = *a;
    *a = *b;
    *b = c;
}

void Compare_in_file (time_t time_1, time_t time_2, time_t time_12, time_t time_22)
{
    unsigned long long c1 = time_2 - time_1;

    unsigned long long c2 = time_22 - time_12;

    FILE* fileout = fopen ("time.txt", "w");
    fprintf (fileout,"Qsort: %lld\nMergesort: %lld\n", c1, c2);

    if (c1 == c2) fprintf (fileout, "Both sort work in the same time");
    if (c1 < c2)
        fprintf (fileout, "Qsort faster");
    else
        fprintf (fileout, "Mergesort faster");
}

void Compare_in_console (time_t time_1, time_t time_2, time_t time_12, time_t time_22)
{
    unsigned long long c1 = time_2 - time_1;

    unsigned long long c2 = time_22 - time_12;

    printf ("Qsort: %lld\nMergesort: %lld\n", c1, c2);

    if (c1 == c2) printf ("Both sort work in the same time");
    if (c1 < c2)
        printf ("Qsort faster");
    else
        printf ("Mergesort faster");
}

void Create_file_with_rand_numb ()
{
    FILE* file = fopen("numbers.txt", "w");
    int i = 0;
    int nSV = time (NULL);

    srand (nSV);

    fprintf(file, "%d", QU);

    for (i = 0; i < QU; i++)
    {
        fprintf(file, "%d ", rand() % 100);
    }
}

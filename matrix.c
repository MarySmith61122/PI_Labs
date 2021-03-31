//Functions for 'matrix' library

#include "matrix.h"
#include <stdio.h>

//readfile - open .txt file and read input values (4x4 array)
//if file empty returns 1
//if reads incorrectly returns 2
//if reads successfully returns 0

int readfile(char* file, fmatrix inp)
{
    FILE* F = fopen(file, "r");
    if (F == NULL) return 1;
    float n;
    int i, j;
    for (i = 0; i < 4; i++)
        for (j = 0; j < 4; j++)
        {
            if (fscanf(F, "%f", &n) != 1) return 2;
            (*inp)[i][j] = n;
        }
    fclose(F);
    return 0;
}

//add - count the sum of elements in the given fragment

float add(fmatrix inp, int part)
{
    int i, j;
    int a1 = 0, a2 = 3;
    float s = 0;
    if ((part) == 4) a1 = 3;
    if ((part) == 3) a2 = 0;
    for (i = 0; i < 4; i++)
    {
        for (j = a1; j <= a2; j++) s = s + (*inp)[i][j];
        switch (part)
        {
        case 1: a2--; break;
        case 2: a1++; break;
        case 3: a2++; break;
        case 4: a1--; break;
        }
    }
    return s;
}

//min - find the minimum of elements in the given fragment

float min(fmatrix inp, int part)
{
    int i, j;
    int a1 = 0, a2 = 3;
    float min = 0;
    if ((part) == 4) a1 = 3;
    if ((part) == 3) a2 = 0;
    min = (*inp)[0][a1];
    for (i = 0; i < 4; i++)
    {
        for (j = a1; j <= a2; j++) if (min > (*inp)[i][j]) min = (*inp)[i][j];
        switch (part)
        {
        case 1: a2--; break;
        case 2: a1++; break;
        case 3: a2++; break;
        case 4: a1--; break;
        }
    }
    return min;
}

//max - find the maximum of elements in the given fragment

float max(fmatrix inp, int part)
{
    int i, j;
    int a1 = 0, a2 = 3;
    float max = 0;
    if ((part) == 4) a1 = 3;
    if ((part) == 3) a2 = 0;
    max = (*inp)[0][a1];
    for (i = 0; i < 4; i++)
    {
        for (j = a1; j <= a2; j++) if (max < (*inp)[i][j]) max = (*inp)[i][j];
        switch (part)
        {
        case 1: a2--; break;
        case 2: a1++; break;
        case 3: a2++; break;
        case 4: a1--; break;
        }
    }
    return max;
}



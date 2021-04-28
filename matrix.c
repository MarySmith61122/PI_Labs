/*!
    \file
    \brief Functions for 'matrix' library
*/

#include "matrix.h"
#include <stdio.h>

/**
    \brief function readfile
    \author Mary Smith
    \version 1.0
    \date November 2020
    \warning Function made for educating purposes only

    Function for opening .txt files and reading input values (4x4 array)
*/

int readfile(char* file, fmatrix inp)
{
    /**
        \param [in] file Input file name
        \param [in] inp Matrix variable
    */
    
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

/**
    \brief function add
    \author Mary Smith
    \version 1.0
    \date November 2020
    \warning Function made for educating purposes only

    Function for counting the sum of elements in the given fragment
*/

float add(fmatrix inp, int part)
{
    /**
        \param [in] inp Matrix variable
        \param [in] part Matrix part
        \param [out] s The sum of given part
    */
    
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

/**
    \brief function min
    \author Mary Smith
    \version 1.0
    \date November 2020
    \warning Function made for educating purposes only

    Function for finding the minimum of elements in the given fragment
*/

float min(fmatrix inp, int part)
{
    /**
        \param [in] inp Matrix variable
        \param [in] part Matrix part
        \param [out] min The minimum element of given part
    */
    
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

/**
    \brief function max
    \author Mary Smith
    \version 1.0
    \date November 2020
    \warning Function made for educating purposes only

    Function for finding the maximum of elements in the given fragment
*/

float max(fmatrix inp, int part)
{
    /**
        \param [in] inp Matrix variable
        \param [in] part Matrix part
        \param [out] max The maximum element of given part
    */

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

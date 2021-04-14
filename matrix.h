//Head file for 'matrix' library

#pragma once
#ifndef  h_matrix
#define h_matrix
typedef float mtrx[4][4];
typedef mtrx* fmatrix;
extern int readfile(char*, fmatrix);
extern float add(fmatrix, int);
extern float min(fmatrix, int);
extern float max(fmatrix, int);
extern void message();
#endif

#pragma once
#ifndef arr_H
#define arr_H

#include  <iostream>
#include  <ctime>
#include  <stdlib.h>

int acceptCorrectINum();
double acceptCorrectDNum();
void coutArr(int *arr, int size);
void coutArr(double *arr, int size);
void swapMaxMinEl(int *arr, int size);
void fillArrRand(int *arr, int size);
void sortIArr(int *arr, int size);
void delEvenElem(int *arr, int &size);
void delElemMult5(int *arr, int &size);
void shiftArr(int *arr, int size);

#endif // !arr_H
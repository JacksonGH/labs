#pragma once
#ifndef farr_H
#define farr_H

double acceptCorrectINum();
double acceptCorrectDNum();
void coutArr(int *arr, int size);
void coutArr(double *arr, int size);
void fillArrRand(int *arr, int size, int a, int b);
void sortIArr(int *arr, int size);
void delEvenElem(int *arr, int &size);

#endif // !farr_H
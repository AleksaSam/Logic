#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <time.h>
#include<queue>
#ifndef ALG_H
#define ALG_H
using namespace std;
int max_match(int** A, int n);
int menu();
int title();
int find_pair(int r, int* match, int n, int** A, int* p, int* used);
int graph();
void menu2(int** A, int n);
void menusave(int** A, int n, int* match, int* vis, int f);
int readMatr(int** A, int n, int count);
int saveres(int** A, int* match, int n, int* vis, int f);
#endif
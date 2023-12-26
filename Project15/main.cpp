#include "alg.h"
int saveres(int** A, int* match, int n, int* vis, int f) {
	for (int i = 0; i < n; i++) {
		vis[i] = 0;
	}
	FILE* res;
	res = fopen("result.txt", "w");
	if (res == NULL) {
		printf("Ошибка открытия файла\n");
		return 1;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			fprintf(res, "%d ", A[i][j]);
		}
		fprintf(res,"\n");
	}
	if (f > 0) {
		for (int i = 0; i < n; i++) {
			if (match[i] != -1 && vis[i] == 0) {
				fprintf(res, "(%d, %d) ", i, match[i]);
				int j = match[i];
				vis[i] = 1;
				vis[j] = 1;
			}
		}
		fprintf(res, "\n");
		printf("Результаты записаны в файл result.txt\n");
	}
	else if (f == 0) {
		fprintf(res,"Паросочетание не найдено\n");
		printf("Результаты записаны в файл result.txt\n");
	}
	fclose(res);
	return 0;
}
int readMatr(int** A, int n, int count) {
	int err = 0;
	FILE* matr;
	matr = fopen("mass.txt", "r");
	if (matr == NULL) {
		printf("Ошибка открытия файла\n");
		return 1;
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			err=fscanf(matr, "%d", &A[i][j]);
		}
	}
	fclose(matr);
	if (err == 0 || err==EOF) {
		printf("Ошибка чтения из файла\n");
		for (int i = 0; i < n; i++)
			free(A[i]);
		free(A);
		return 1;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", A[i][j]);
		}
		printf("\n");
	}
	return 0;
}

int graph() {
	int** A;
	int n;
	int err = 0, t=0, k, count = 0;;
	int s, m;
	float test = 0;
	FILE* matr;
	while (1) {
		printf("1. Заполнить матрицу случайно\n2. Задать собственную связь вершин\n3. Заполнить матрицу из файла\n");
		printf("Ваш выбор: \n");
		err = scanf("%f", &test);
		if (err == 0) {
			printf("Неверный выбор.\n");
			while (getchar() != '\n');
			Sleep(700);
			system("cls");
			continue;
		}
		s = (int)test;
		srand(time(NULL));
		switch (s) {
		case 1:
			system("cls");
			printf("Введите целое количество вершин графа больше нуля: ");
			err=scanf("%f", &test);
			if ((err == 0) || (test <= 0)) {
				printf("Ошибка\n");
				while (getchar() != '\n');
				Sleep(700);
				system("cls");
				break;
			}
			n = (int)test;
			A = (int**)malloc(sizeof(int*) * n);
			for (int i = 0; i < n; i++) {
				A[i] = (int*)malloc(sizeof(int) * n);
			}
			if (A == NULL) {
				printf("Ошибка выделения памяти\n");
				return 1;
			}
			for (int i = 0; i < n; i++)
				for (int j = i; j < n; j++) {
					A[i][j] = rand() % 2;
					A[j][i] = A[i][j];
					if (i == j) A[i][j] = 0;
				}
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					printf("%d ", A[i][j]);
				}
				printf("\n");
			}
			menu2(A, n);
			return 0;
		case 2:
			system("cls");
			printf("Введите целое количество вершин графа больше нуля: ");
			err = scanf("%f", &test);
			if ((err == 0) || (test <= 0)) {
				printf("Ошибка\n");
				while (getchar() != '\n');
				Sleep(700);
				system("cls");
				break;
			}
			n = (int)test;
			A = (int**)malloc(sizeof(int*) * n);
			for (int i = 0; i < n; i++) {
				A[i] = (int*)malloc(sizeof(int) * n);
			}
			if (A == NULL) {
				printf("Ошибка выделения памяти\n");
				return 1;
			}
			for (int i = 0; i < n; i++) {
				for (int j = i; j < n; j++) {
					if (i == j) A[i][j] = 0;
					if (i != j) {
						printf("Есть ли связь у вершин %d и %d(1-есть/0-нет): \n", i, j);
						err = scanf("%f", &test);
						if (err == 0 || test < 0 || test>1) {
							printf("Ошибка!\n");
							Sleep(700);
							system("cls");
							return graph();
						}
						m = (int)test;
						A[i][j] = m;
						A[j][i] = A[i][j];
					}

				}
			}
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					printf("%d ", A[i][j]);
				}
				printf("\n");
			}
			menu2(A, n);
			return 0;
		case 3:
			system("cls");
			matr = fopen("mass.txt", "r");
			if (matr == NULL) {
				printf("Ошибка открытия файла\n");
				break;
			}
			while (fscanf(matr, "%d", &k) != EOF) {
				count++;
			}
			fclose(matr);
			n = sqrt(count);
			A = (int**)malloc(sizeof(int*) * n);
			for (int i = 0; i < n; i++) {
				A[i] = (int*)malloc(sizeof(int) * n);
			}
			if (A == NULL) {
				printf("Ошибка выделения памяти\n");
				return 1;
			}
			t=readMatr(A, n, count);
			if (t == 1)
				break;
			menu2(A, n);
			return 0;
		default:
			printf("Неверный выбор\n");
			Sleep(700);
			system("cls");
			break;
		}
	}
	return 0;
}


int find_pair(int r, int* match, int n, int** A, int* p, int* used) {
	int v, to;
	/*for (int i = 0; i < n; i++)
		used[i] = 0;*/
	for (int i = 0; i < n; i++)
		p[i] = -1;
	used[r] = 1;
	queue <int> q;
	q.push(r);
	while (!q.empty()) {
		v = q.front();
		q.pop();
		for (int i = 0; i < n; i++) {
			if ((A[v][i] == 1) && (used[i] == 0)) {
				to = i;
				if (match[v] == to)
					continue;
				else if (p[to] == -1) {
					p[to] = v;
					if (match[to] == -1)
						return to;
					to = match[to];
					used[to] = 1;
					q.push(to);
				}
			}
		}
	}

	return -1;
}
int max_match(int** A, int n) {

	int** vis = (int**)malloc(sizeof(int*) * n);
	for (int i = 0; i < n; i++) {
		vis[i] = (int*)malloc(sizeof(int) * n);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			vis[i][j] = -1;
		}
	}
	int* p = (int*)malloc(sizeof(int) * n);
	int* match = (int*)malloc(sizeof(int) * n);
	int* used = (int*)malloc(sizeof(int) * n);
	for (int t = 0; t < n; ++t) {

		for (int j = 0; j < n; ++j) {
			for (int i = 0; i < n; i++)
				match[i] = -1;

			for (int i = 0; i < n; i++)
				used[i] = 0;

			if (A[t][j] == 1 && vis[t][j] == -1 && vis[j][t] == -1) {
				match[j] = t;
				match[t] = j;
			}
			else continue;
			for (int i = 0; i < n; ++i) {
				if (match[i] == -1) {
					int v = find_pair(i, match, n, A, p, used);
					while (v != -1) {
						int pv = p[v], ppv = match[pv];
						match[v] = pv, match[pv] = v;
						v = ppv;

					}

				}
			}

			for (int i = 0; i < n; i++) {
				if (match[i] != -1) {
					printf("(%d, %d) ", i, match[i]);
					int j = match[i];
					vis[i][j] = 1;
					vis[j][i] = 1;
					match[j] = -1;
				}
			}
			printf("\n");

		}
	}

	free(match);
	free(p);
	free(used);
	for (int i = 0; i < n; i++)
		free(vis[i]);
	free(vis);
	return 0;
}
//int max_match(int** A, int n) {
//	int f = 0;
//	int* vis = (int*)malloc(sizeof(int) * n);
//	for (int i = 0; i < n; i++) {
//			vis[i] = 0;
//	}
//	if (vis == NULL) {
//		printf("Ошибка выделения памяти\n");
//		return 1;
//	}
//	int* p = (int*)malloc(sizeof(int) * n);
//	if (p == NULL) {
//		printf("Ошибка выделения памяти\n");
//		return 1;
//	}
//	int* match = (int*)malloc(sizeof(int) * n);
//	if (match == NULL) {
//		printf("Ошибка выделения памяти\n");
//		return 1;
//	}
//	int* used = (int*)malloc(sizeof(int) * n);
//	if (used == NULL) {
//		printf("Ошибка выделения памяти\n");
//		return 1;
//	}
//			for (int i = 0; i < n; i++)
//				match[i] = -1;
//			for (int i = 0; i < n; ++i) {
//				if (match[i] == -1) {
//					int v = find_pair(i, match, n, A, p, used);
//					while (v != -1) {
//						int pv = p[v], ppv = match[pv];
//						match[v] = pv, match[pv] = v;
//						v = ppv;
//						f++;
//					}
//				}
//			}
//			if (f == 0) {
//				printf("Паросочетание не найдено\n");
//			}
//			else {
//				printf("Максимальное паросочетание:");
//				for (int i = 0; i < n; i++) {
//					if (match[i] != -1 && vis[i] == 0) {
//						printf("(%d, %d) ", i, match[i]);
//						int j = match[i];
//						vis[i] = 1;
//						vis[j] = 1;
//					}
//				}
//				printf("\n");
//			}
//			menusave(A, n, match, vis, f);
//
//	free(match);
//	free(p);
//	free(used);
//	free(vis);
//	for (int i = 0; i < n; i++)
//		free(A[i]);
//	free(A);
//	return 0;
//}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	title();
	Sleep(5000);
	system("cls");
	menu();
	return 0;
}


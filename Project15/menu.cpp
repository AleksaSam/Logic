#include "alg.h"
void menusave(int** A, int n, int* match, int* vis, int f) {
	int err = 0;
	float test = 0;
	while (1) {
		printf("Сохранить результаты в файл?\n1.Да\n2.Нет\nВаш выбор:\n");
		int c = 0;
		err = scanf("%f", &test);
		if (err == 0) {
			printf("Неверный выбор.\n");
			while (getchar() != '\n');
			/*continue;*/
			break;
		}
		c = (int)test;
		switch (c) {
		case 1:
			saveres(A, match, n, vis, f);
			system("pause");
			system("cls");
			return;
		case 2:
			system("pause");
			system("cls");
			return;
		default:
			printf("Неверный выбор\n");
			Sleep(700);
			system("cls");
			break;
		}
	}
}
void menu2(int** A, int n) {
	float test = 0;
	int s;
	int err = 0;
	while (1) {
		printf("1.Найти максимальное паросочетание\n");
		printf("2.Вернуться в главное меню\n");
		printf("Ваш выбор:\n");
		err = scanf("%f", &test);
		if (err == 0) {
			printf("Неверный выбор.\n");
			while (getchar() != '\n');
			Sleep(700);
			system("cls");
			/*continue;*/
			break;
		}
		s = (int)test;
		switch (s) {
		case 1:
			max_match(A, n);
			return;
		case 2:
			for (int i = 0; i < n; i++)
				free(A[i]);
			free(A);
			system("cls");
			return;
			break;
		default:
			printf("Неверный выбор.\n");
			Sleep(700);
			system("cls");
			break;
		}
	}
}
int menu() {
	float test = 0;
	int c = 0;
	int err = 0;
	while (1) {
		printf("   Главное меню\n");
		printf("Выберите операцию:\n");
		printf("1. Генерация графа\n");
		printf("2. Выход\n");
		err=scanf("%f", &test);
		if (err == 0) {
			printf("Неверный выбор.\n");
			while (getchar() != '\n');
			Sleep(700);
			system("cls");
			continue;
		}
		c = (int)test;
		switch (c) {
		case 1:
			system("cls");
			graph();
			break;
		case 2:
			exit(0);
			break;
		default:
			printf("Неверный выбор.\n");
			Sleep(700);
			system("cls");
			break;
		}
	}
	return 0;
}
int title() {
	printf("   Министерство науки и высшего образования Российской Федерации\n");
	printf("        Пензенский государственный университет\n");
	printf("           Кафедра «Вычислительная Техника»\n\n\n\n\n\n");
	printf("   \t\tКурсовой проект\n");
	printf("  По курсу «Логика и основы алгоритмизации в инженерных задачах»\n");
	printf("                   на тему\n");
	printf("  «Реализация алгоритма поиска максимальных паросочетаний»\n\n\n\n\n"); 
	printf("   Выполнила студентка группы 22ВВВ3:\n");
	printf("   Самофалова А.В.\n");
	return 0;
}
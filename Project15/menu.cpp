#include "alg.h"
void menusave(int** A, int n, int* match, int* vis, int f) {
	int err = 0;
	float test = 0;
	while (1) {
		printf("��������� ���������� � ����?\n1.��\n2.���\n��� �����:\n");
		int c = 0;
		err = scanf("%f", &test);
		if (err == 0) {
			printf("�������� �����.\n");
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
			printf("�������� �����\n");
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
		printf("1.����� ������������ �������������\n");
		printf("2.��������� � ������� ����\n");
		printf("��� �����:\n");
		err = scanf("%f", &test);
		if (err == 0) {
			printf("�������� �����.\n");
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
			printf("�������� �����.\n");
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
		printf("   ������� ����\n");
		printf("�������� ��������:\n");
		printf("1. ��������� �����\n");
		printf("2. �����\n");
		err=scanf("%f", &test);
		if (err == 0) {
			printf("�������� �����.\n");
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
			printf("�������� �����.\n");
			Sleep(700);
			system("cls");
			break;
		}
	}
	return 0;
}
int title() {
	printf("   ������������ ����� � ������� ����������� ���������� ���������\n");
	printf("        ���������� ��������������� �����������\n");
	printf("           ������� ��������������� �������\n\n\n\n\n\n");
	printf("   \t\t�������� ������\n");
	printf("  �� ����� ������� � ������ �������������� � ���������� ��������\n");
	printf("                   �� ����\n");
	printf("  ����������� ��������� ������ ������������ �������������\n\n\n\n\n"); 
	printf("   ��������� ��������� ������ 22���3:\n");
	printf("   ���������� �.�.\n");
	return 0;
}
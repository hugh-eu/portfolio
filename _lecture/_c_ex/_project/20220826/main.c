#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <windows.h>

//typedef struct node {
//	int number;
//	struct node *p_next; // �ٸ� struct node�� ����ų ������ type
//} NODE;

//void AddNumber(NODE** pp_head, NODE **pp_tail, int data) {
//	if (NULL != *pp_head) {
//		(*pp_tail)->p_next = (NODE*)malloc(sizeof(NODE));
//		*pp_tail = (*pp_tail)->p_next;
//	}
//	else {
//		*pp_head = (NODE*)malloc(sizeof(NODE));
//		*pp_tail = *pp_head;
//	}
//	(*pp_tail)->number = data;
//	(*pp_tail)->p_next = NULL;
//}

//int Sum(int a, int b) {
//	return a + b;
//}
//int Sub(int a, int b) {
//	return a - b;
//}
//int Mul(int a, int b) {
//	return a * b;
//}
//int Div(int a, int b) {
//	return a / b;
//}

//struct Student{
//	char name[11];
//	int korScore;
//	int engScore;
//	int matScore;
//	struct Student *p_next;
//};

//void addStudent(struct Student **pp_head, struct Student**pp_tail, int *p_count) {
//	if (*pp_head != NULL){
//		(*pp_tail)->p_next = (struct Student*)malloc(sizeof(struct Student));
//		*pp_tail = (*pp_tail)->p_next;
//	}
//	else {
//		*pp_head = (struct Student*)malloc(sizeof(struct Student));
//		*pp_tail = *pp_head;
//	}
//	printf("%d ��° �л� �̸� : ", *p_count);
//	scanf("%s", (*pp_tail)->name);
//	printf("���� ���� : ");
//	scanf("%d", (*pp_tail)->korScore);
//	printf("���� ���� : ");
//	scanf("%d", (*pp_tail)->engScore);
//	printf("���� ���� : ");
//	scanf("%d", (*pp_tail)->matScore);
//	(*pp_tail)->p_next = NULL;
//	*p_count += 1;
//}

//void checkScores() {
//
//}



void main() {

	//NODE *p_head = NULL;
	//p_head = (NODE*)malloc(sizeof(NODE));
	//p_head->number = 12;
	//p_head->p_next = NULL;

	//p_head->p_next = (NODE*)malloc(sizeof(NODE));
	//p_head->p_next->number = 15;
	//p_head->p_next->p_next = NULL;

	//NODE *p = p_head;  // ������ ��� Ž��
	//while (p->p_next != NULL) {
	//	p = p->p_next;
	//}
	//printf("%d", p->number);


	//NODE *p;
	//while (NULL != p_head) {
	//	p = p_head->p_next;
	//	free(p_head);
	//	p_head = p;
	//}

	//p_tail = NULL;

	//NODE *p_head = NULL, *p_tail = NULL, *p;
	//int sum = 0, temp;

	//while (1) {
	//	printf("���ڸ� �Է��ϼ��� (9999�� ������ ����) : ");
	//	scanf("%d", &temp);
	//	if (9999 == temp) break;
	//	AddNumber(&p_head, &p_tail, temp);
	//}
	//p = p_head;
	//while (NULL != p) {
	//	if (p != p_head) printf(" + ");
	//	printf(" %d", p->number);
	//	sum += p->number;
	//	p = p->p_next;
	//}
	//printf(" = %d\n", sum);
	//while (NULL != p_head) {
	//	p = p_head;
	//	p_head = p_head->p_next;
	//	free(p);
	//}
	//p_tail = p_head;


	// ǥ�� ����� ���� �а���, �ʿ��Ҷ����� ã�Ƽ�����
	//FILE *p_file = fopen("D:\\hugh_park\\_c_ex\\_project\\20220826\\fopen.txt", "wt");  // ���� ����, ���, r �б�, rb ���̳ʸ�, ���̳ʸ��� ��� ��������, rt �ؽ�Ʈ, w����, wb���̳ʸ�, wt�ؽ�Ʈ, a �ٿ�����, ab���̳ʸ�, at�ؽ�Ʈ, r+, w+, a+
	//if (NULL != p_file) {
	//	//fprintf(p_file, "Hello\n");
	//	short int data = 0x0412;
	//	fprintf(p_file, "%x", data);  //���̳ʸ� data�� ���ڿ� ���·�
	//	fclose(p_file);
	//}
	//FILE* p_file = fopen("D:\\hugh_park\\_c_ex\\_project\\20220826\\fopen.txt", "rt");
	//if (NULL != p_file) {
	//	int data_fscan;
	//	fscanf(p_file, "%d", &data_fscan);  // �ؽ�Ʈ �о�� ����
	//	fclose(p_file);
	//	printf("%d", data_fscan);
	//}

	// �Լ� ������
	//int (*p)(int, int);  // ������ ��ȣ �����ʱ�, int�ΰ��� �Ű������� ���� ������ ����
	//p = &Sum;  // ������ �ʱ�ȭ, &��������, Sum�� �Լ��� �����ּҸ� ����Ŵ
	//int result = (*p)(2, 3);
	//printf("%d", result);

	//typedef int (*OP_TYPE)(int, int);
	////int (*p[4])(int, int) = { &Sum, &Sub, &Mul, &Div };  // �Լ������͸� ����� ���������� �Լ��� ����
	//OP_TYPE p[4] = { &Sum, &Sub, &Mul, &Div };
	//char op_table[4] = { '+', '-', '*', '/' };
	//for (int i = 0; i < 4; i++) printf("%d %c %d = %d\n", 8, op_table[i], 2, (*p[i])(8, 2));

	/*int num, count = 1;
	struct Student *p_head = NULL, *p_tail = NULL;
	while (1) {
		printf("[Menu]\n");
		printf("1. ���� �Է�\n");
		printf("2. ���� Ȯ��\n");
		printf("3. ����\n");
		printf("---------------\n");
		printf("����(1~3) : ");
		scanf("%d", &num);
		if (num == 1) {
			addStudent(&p_head, &p_tail, &count);
		}
		else if (num == 2) {
			checkScores();
		}
		else if (num == 3) {
			break;
		}
	}*/


}
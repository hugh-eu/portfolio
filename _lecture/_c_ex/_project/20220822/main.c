#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// num1 10, num2 20, �����͸� �̿��� �����Լ�
//void swapFunc(int * const n1, int * const n2) {  // const�� ����Ͽ� �ּҺ��� ����
//	
//	int temp = *n1;
//	*n1 = *n2;
//	*n2 = temp;
//
//}

//int getData(void *p_data, char type) {
//	int result = 0;
//	if (type == 1) result = *(char *)p_data;
//	else if (type == 2) result = *(short *)p_data;
//	else if (type == 4) result = *(int *)p_data;
//	return result;
//}

void main() {

	/*int num;
	int *ptr;

	num = 10;
	ptr = &num;
	printf("%d\n", num);
	printf("%d\n", *ptr);
	printf("%p\n", &num);
	printf("%x\n", (int)ptr);*/

	// swapFunc
	//int num1 = 10, num2 = 20;
	//printf("num1 : %d, num2 : %d\n", num1, num2);
	//swapFunc(&num1, &num2);
	//printf("num1 : %d, num2 : %d\n", num1, num2);

	//int data = 0;
	//void *ptr = &data;  // ����� ũ�Ⱑ ���������� ����, ����� ũ�������� ��� �̷��, �����Ӱ� ĳ�����Ͽ� ���
	//*(char *)ptr = 0x12345678;  // ����ȯ�ؾ� ������ ����, �ƴҽ� ����
	//printf("%X", data);

	// getData
	/*int data = 0x12345678;
	printf("%X\n", getData(&data, 1));*/

	//int data = 0x12345678;
	//short* ptr = &data;
	//*ptr = 0x0412;  // ��Ʋ�����, �޸𸮿� �ڿ������� ����
	//*(ptr + 1) = 0x4848;
	//printf("%X", data);

	/*char a = 0x12, b = 0x34;
	short c = 0x5678;
	int t;
	void* ptr = &t;
	*(short*)ptr = c;
	*((char*)ptr + 2) = b;
	*((char*)ptr + 3) = a;
	printf("%X", t);*/

	//char a = getchar();
	//rewind(stdin);  // ���ۿ� �����ִ� �Է°� �����
	//char b = getchar();
	//rewind(stdin);
	//printf("a:%c b:%c", a, b);

	//char input_string[10];
	//gets(input_string);  // 9�� ������ 0
	//printf("%s\n", input_string);
	//printf("%d", (int)sizeof(input_string));


	// str -> int�� ��ȯ
	//int pos_num = 1, num = 0, i, count;
	//char num_string[9] = "12345678";
	//count = strlen(num_string);
	//for (i = 0; i < count - 1; i++) pos_num *= 10;
	//for (i = 0; i < count; i++) {
	//	num += (num_string[i] - '0') * pos_num;
	//	pos_num /= 10;
	//}
	//printf("%s %d", num_string, num);

	/*int num = 0, count = 0;
	char num_string[5] = "1234";
	while (num_string[count] != 0) {
		num = num * 10 + (num_string[count] - '0');
		count++;
	}
	printf("%s %d", num_string, num);*/

	// atoi, ���ڿ��� ������ ��ȯ
	/*int first_num, second_num;
	char first_string[16], second_string[16];
	printf("�Է� : ");
	gets(first_string);
	printf("�Է� : ");
	gets(second_string);
	first_num = atoi(first_string);
	second_num = atoi(second_string);
	printf("%s %d %s %d", first_string, first_num, second_string, second_num);*/

	//int data;
	//scanf("%d", &data);  // ����
	//char strs[10];
	//scanf("%s", strs);  // �迭�� ���ڿ�
	//printf("%d %s", data, strs);

	//float a, b, c;
	//scanf("%f %f %f", &a, &b, &c);
	//printf("%.2lf", (a + b + c) / 3);  // int�ϰ�� 3.0, or (float)

	/*char strs1[10], strs2[10];
	scanf("%s", strs1);
	scanf("%s", strs2);
	strcat(strs1, strs2);
	printf("%s", strs1);*/

	/*char name[10];
	char weight[10];
	char height[10];
	char bloodType[10];
	char heartRate[10];
	scanf("%s %s %s %s %s", name, weight, height, bloodType, heartRate);
	printf("�̸� :%s, ������ : %skg, Ű : %scm, ������ : %s��, �ɹڼ� : %sȸ", name, weight, height, bloodType, heartRate);*/

	/*char students[3][34];
	for (int i = 0; i < 3; i++) {
		printf("%d ��° �л� �̸� : ", i + 1);
		scanf("%s", &*students[i]);
		printf("���� ����  : ");
		scanf("%d", &*(unsigned int*)(students[i] + 10));
		printf("���� ���� : ");
		scanf("%d", &*(unsigned int*)(students[i] + 14));
		printf("���� ���� : ");
		scanf("%d", &*(unsigned int*)(students[i] + 18));
		*(unsigned int*)(students[i] + 22) = (unsigned int)(*(unsigned int*)(students[i] + 10) + *(unsigned int*)(students[i] + 14) + *(unsigned int*)(students[i] + 18));
		*(double*)(students[i] + 26) = *(unsigned int*)(students[i] + 22) / 3.0;
	}
	printf("-----------------------------------------------------\n");
	printf("�̸�\t����\t����\t����\t����\t���\t���\n");
	printf("-----------------------------------------------------\n");
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if ((int)students[i][22] >= (int)students[j][22]) {
				if (j == 2) {
					printf("%s\t%d\t%d\t%d\t%d\t%.2lf\t1��\n", students[i], *(unsigned int*)(students[i] + 10), *(unsigned int*)(students[i] + 14), *(unsigned int*)(students[i] + 18), *(unsigned int*)(students[i] + 22), *(double*)(students[i] + 26));
					break;
				}
			}
			else {
				if (j == 2) {
					printf("%s\t%d\t%d\t%d\t%d\t%.2lf\t2��\n", students[i], *(unsigned int*)(students[i] + 10), *(unsigned int*)(students[i] + 14), *(unsigned int*)(students[i] + 18), *(unsigned int*)(students[i] + 22), *(double*)(students[i] + 26));
					break;
				}
				else {
					printf("%s\t%d\t%d\t%d\t%d\t%.2lf\t3��\n", students[i], *(unsigned int*)(students[i] + 10), *(unsigned int*)(students[i] + 14), *(unsigned int*)(students[i] + 18), *(unsigned int*)(students[i] + 22), *(double*)(students[i] + 26));
					break;
				}
			}
		}
	}*/

	

}
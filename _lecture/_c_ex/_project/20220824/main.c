#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <malloc.h> // �����޸� ���, ���ص� �ǳ�
//#define ALPHABET_COUNT 26

void main() {

	//�迭�� ������
	/*int nums[5] = { 1,2,3,4,5 };
	printf("%d\n", nums[2]);
	printf("%d\n", *(nums + 2));*/

	//int data[2] = { 0x12345678, 0x12345678 };
	//data[0] = 0x22;
	//printf("%x\n", data[0]);
	//*(char*)(data + 1) = 0x22;  // �迭���� ����ȯ�� ��� �����ͷ� ����
	//printf("%x\n", data[1]);
	/**(short*)((char*)data + 4) = 0x7777;
	*(char*)((char*)data + 6) = 0x12;
	*(char*)((char*)data + 7) = 0x34;
	printf("%x\n", data[1]);*/

	//char data[5] = {1,2,3,4,5};
	//int i, sum = 0, select = 2;
	//for (i = 0; i < 10; i++) sum += data[select];
	//for (i = 0; i < 10; i++) sum += *(data + select);
	/*char* p = data + select;
	for (i = 0; i < 10; i++) sum += *p;
	printf("%d", sum);*/

	//char data[5] = {1,2,3,4,5};
	//int result = 0, i;
	//char* p = data;
	//for (i = 0; i < 5; i++) {
	//	result += *p++;
	//	//p++;
	//}
	//printf("%d", result);

	/*char data[3][5];
	char(*key)[5];
	key = data;*/
	//(*key)[1] = 3;
	//(*(key + 1))[2] = 4;
	//(*(key + 2))[4] = 5;
	//printf("%d", (*(key + 2))[4]);

	//short* p = (short*)malloc(100);  //�����޸� �Ҵ��� �⺻�̶� �����ϰ� ����, �޸� �Ҵ� ������ ��� NULL ��ȯ�ϱ⶧��
	//if (p != NULL) {
	//}
	//else {
	//}
	//// �Ǵ�
	//if (p == 0) return 0;  // ����������
	//free(p);  // p �ּҿ� �Ҵ�� �޸� ����

	/*char* p_name;
	p_name = (char*)malloc(32);
	int i = 0;
	while (p_name == NULL) {
		i++;
		if (i == 3) {
			printf("Memory allocation error!!");
			break;
		}
		p_name = (char*)malloc(32);
	}
	if (p_name != NULL) {
		printf("Your name : ");
		gets(p_name);
		printf("Hi~ %s\n", p_name);
		free(p_name);
	}*/

	/*int iCount, i = 0;
	char* str = (char*)malloc(ALPHABET_COUNT + 1);
	while (str == NULL) {
		i++;
		if (i == 3) {
			printf("Memory allocation error!!");
			break;
		}
		str = (char*)malloc(ALPHABET_COUNT + 1);
	}
	if (str != NULL) {
		for (iCount = 0; iCount < ALPHABET_COUNT; iCount++) {
			str[iCount] = 0x41 + iCount;
		}
		str[iCount] = 0;
		printf("%s\n", str);
		for (iCount = 0; iCount < ALPHABET_COUNT; iCount++) {
			str[iCount] = 0x5A - iCount;
		}
		str[iCount] = 0;
		printf("%s\n", str);
		free(str);
	}*/

	/*int *p_num_list, count = 0, sum = 0, limit = 0, i;
	printf("�ִ밳�� : ");
	scanf("%d", &limit);
	p_num_list = (int*)malloc(sizeof(int) * limit);
	while (count < limit) {
		printf("�����Է�(9999����) : ");
		scanf("%d", p_num_list + count);
		if (*(p_num_list + count) == 9999) break;
		count++;
	}
	for (i = 0; i < count; i++) {
		if (i > 0) printf(" + ");
		printf("%d", *(p_num_list + i));
		sum += *(p_num_list + i);
	}
	printf(" = %d", sum);
	free(p_num_list);*/

	//421p 3����
	//char ***p = (char***)malloc(sizeof(char**) * 2);
	//for (int i = 0; i < 2; i++) {
	//	*(p + i) = (char**)malloc(sizeof(char*) * 3);
	//}
	//for (int i = 0; i < 2; i++) {
	//	for (int j = 0; j < 3; i++) {
	//		*(*(p + i) + j) = (char*)malloc(sizeof(char) * 4);
	//	}
	//}
	//free(**p);
	//free(*p);
	//free(p);  // �������Ѽ� �����ؾ��� ������ �������ϼ��� �ʰ�



}
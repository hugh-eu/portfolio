#include <stdio.h>
#include <stdlib.h>
#include <time.h>  // ���� seed���� ����ð��� �ο��Ͽ� seed �����ϱ� ����
//#define ABLE_HEIGHT 120
//#include <stdbool.h>  // ��Ÿ�� ���̺귯��

void main(void) {

	/*short data = 5;
	printf("data is %d", data);*/

	/*char month = 12, day = 3;
	printf("�ʴ� ������ ������?\n");
	printf("���� ������ %d�� %d���Դϴ�.", month, day);*/

	//char my_char = 65;
	//printf("my_char is %d\n", my_char);  // ����
	//printf("my_char is %c", my_char);  // ����	
	
	//float my_float = 3.14f; //float�� ��Ÿ���� �ڿ� f �߰�, f�� �Ⱥ��̴� ��� double
	//double my_double = 3.14;
	//printf("my_float is %f\n", my_float);  // �÷�Ʈ, �Ҽ������� 6�ڸ�
	//printf("my_double is %f\n", my_double);  // ���� ���� %f �Ҽ������� 14�ڸ�

	//int data1 = -1;  // signed �� ��������
	//unsigned int data2 = 4294967295;
	//printf("%d, %u, %d, %u", data1, data1, data2, data2);  // �����ִ밪 -1�� �޸� ������ unsigned �ִ밪�� �޸𸮱����� ����,

	//int data = 7;
	//printf("[%d] [%5d] [%05d] [%-5d]", data, data, data, data);  // ���ĭ��, 0���� ä���, ��������

	//double data = 3.141592;
	//printf("[%f] [%.4f] [%8.4f] [%-8.4f]", data, data, data, data);  // �Ǽ�, 4�ڸ�����, 8ĭ 4�ڸ�����

	//printf("Hello~ Tipssoft.com\n");
	//printf("Hello~ Tipssoft.com\rHi~~~~");  // r�� ����Ѱ�� ĳ���� �Ǿ����� �̵��Ѵ��� ���� ���ڿ��� ���� ���ڿ� ���
	//_getch();  // ��°�� Ȯ������ input���

	/*printf("1234567\b");
	_getch();*/


	// 0 false, 0�� �ƴϸ� true
	/*if (1) {
		
	}
	if (true) {  // stdbool.h, 1����Ʈ

	}*/

	/*int i = 5, sum;
	sum = ++i;  // i�� ���� ����, �Ŀ� ����
	printf("%d %d", sum, i);*/
	

	//int i = 5, sum;
	//sum = i++;  // i�� ���� ����, �Ŀ� ����
	//printf("%d %d", sum, i);

	//int num = 5;
	//++num;  // �����ϴ� ���� �ƴϱ� ������ �������
	//printf("%d", num);

	// if ~ else ��
	/*int num = 10;
	if (num >= 20) {
		printf("%d�� 20���� ũ��!", num);
	}
	else {
		printf("%d�� 20���� �۰ų� ����!", num);
	}*/

	// if ~ else if ��
	//int my_score = 75;

	//if (my_score >= 90) printf("A");  // �����ΰ�� �߰�ȣ ���� ����
	//else if (my_score >= 80) {
	//	printf("B");
	//}
	//else if (my_score >= 70) {
	//	printf("C");
	//}
	//else if (my_score >= 60) {
	//	printf("D");
	//}
	//else {
	//	printf("F");
	//}

	//int data = 3;
	//if (data > 3);  // �Ǽ�, �����ݷ����� ���ǹ��� ���±� ������ ���ϴ� data�� 3�� �ƴ϶� 4�� ����
	//	data++;
	//	printf("%d", data);

	// ����� ������ 120�̻��̸� ž�°���, �̸��̸� ž�ºҰ�
	//int child_height;

	//printf("������ Ű�� �Է��ϼ��� : ");
	//scanf_s("%d", &child_height);  // scanf_s(����) ����Ű �Է�, & child_height ������ ����Ű�� �޸��ּ�

	//if (child_height >= ABLE_HEIGHT) {
	//	printf("ž�� ����");
	//}
	//else {
	//	printf("ž�� �Ұ�");
	//}

	/*int value = 1000;
	double point = (value >= 10000) ? value * 0.1 : value * 0.05;
	printf("point = %f", point);*/

	// switch ~ default == if~ else if ~ else
	//int num = 2;
	////char num = 'A'; // ���ڵ� ����
	//switch (num){
	////switch (++num){  // ���� ����
	//case 2:  // ���̽� ���� ���� ����
	//case 1:  // ���̽� ��ø ����
	//	printf("hello");
	//	break;
	//case 3:
	//	printf("num is 3");
	//	break;
	//case 4:
	//	printf("num is 4");
	//	break;
	//default:
	//	printf("default");
	//	break;
	//}

	// �ݺ���
	// for, while, do ~ while: ������ 1ȸ ���� �� ���ǿ� ���� �ݺ�(do�� ���౸��, while�� ���Ǹ�)

	/*for (int num = 1; num < 6; num++) {  // for �ȿ��� ����Ǿ� for �ȿ����� ���, ����(�ۿ��� �ʱ�ȭ), ��, �ܰ� ��������, ���ο� �ڵ�
		printf("num = %d\n", num);
	}*/

	//����ڰ� �Է��� ���ڸ� �̿��� �ش� ������ ���

	//int i, j;  // for �ۿ��� ����Ǿ� �ۿ����� ��밡��
	//printf("�������� ����� ���� �Է� : ");
	//scanf_s("%d", &j);
	//for (i = 1; i < 10; i++) {
	//	printf("%d X %d = %d\n", j, i, j * i);
	//}

	/*int i, j;
	for (i = 1; i < 10; i++) {
		for (j = 2; j < 10; j++) {
			printf("%d X %d = %d\t", j, i, j * i);
		}
		printf("\n");
	}*/

	/*int i, j;
	for (i = 9; i > 0; i--) {
		for (j = 9; j > 1; j--) {
			printf("%d X %d = %d\t", j, i, j * i);
		}
		printf("\n");
	}*/

	/*for (int i = 1; i < 6; i++) {
		for (int j = 1; j < 6 - i; j++) {
			printf(" ");
		}
		for (int j = 1; j <= i; j++) {
			printf("*");
		}
		printf("\n");
	}*/

	// ������ �̿��� ����������
	//int rand_num, usr_num;
	//srand(time(NULL));  // ������ �õ� �ð����� �ʱ�ȭ
	//while (1) {
	//	printf("���������� ����\n");
	//	printf("1. ����  2. ����  3. ��  0. ����\n");
	//	scanf_s("%d", &usr_num);
	//	rand_num = (rand() % 3) + 1;
	//	if (rand_num == usr_num) {
	//		printf("�����ϴ�.\n");
	//	}
	//	else if (usr_num == 1) {
	//		if (rand_num == 2) {
	//			printf("���� : ����, ��ǻ�� : ����, �����ϴ�.\n");
	//		}
	//		else {
	//			printf("���� : ����, ��ǻ�� : ��, �̰���ϴ�.\n");
	//		}
	//	}
	//	else if (usr_num == 2) {
	//		if (rand_num == 1) {
	//			printf("���� : ����, ��ǻ�� : ����, �̰���ϴ�.\n");
	//		}
	//		else {
	//			printf("���� : ����, ��ǻ�� : ��, �����ϴ�.\n");
	//		}
	//	}
	//	else if (usr_num == 3) {
	//		if (rand_num == 1) {
	//			printf("���� : ��, ��ǻ�� : ����, �����ϴ�.\n");
	//		}
	//		else {
	//			printf("���� : ��, ��ǻ�� : ����, �̰���ϴ�.\n");
	//		}
	//	}
	//	else if (usr_num == 0) {
	//		break;
	//	}
	//	printf("\n");
	//}


	/*int num = 10;
	while (num < 15) {
		printf("num is %d\n", num);
		num++;
	}*/

	/*int num = 10;
	do {
		printf("����");
	} while (num < 0);*/

	/*int sum = 0, num = 1;
	do {
		printf("num(%d) + sum(%d) = ", num, sum);
		sum += num;
		printf("%d\n", sum);
		num++;
	} while (num <= 5);
	printf("\nResult : num = %d sum = %d\n", num, sum);*/

}
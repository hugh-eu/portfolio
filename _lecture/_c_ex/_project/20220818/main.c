#include <stdio.h>
//#define A 20
//#include <string.h>


//void tempFunc(int *n1, int *n2) {
//	*n1 = 100;
//	*n2 = 200;
//
//	printf("n1 -> %d, n2 -> %d\n", *n1, *n2);
//}

//unsigned char ModifyBit(unsigned char dest_data, unsigned char bit_num, char value) {
//	unsigned char mask;
//	if (bit_num < 8) {
//		mask = 0x01 << bit_num;
//		if (value == 1) dest_data |= mask;
//		else dest_data &= ~mask;
//	}
//	return dest_data;
//}

void main() {

	// ModifyBit
	/*unsigned char lamp_state = 0x7f;
	printf("%X->", lamp_state);
	lamp_state = ModifyBit(lamp_state, 3, 0);
	printf("%X->", lamp_state);
	lamp_state = ModifyBit(lamp_state, 3, 1);
	printf("%X\n", lamp_state);*/


	// �迭
	//short student[20];  // �迭 ����
	//short student[A]; // ����� �ε����� ���� �����δ� �ȵ�
	//student[1] = 10;  // �ʱ�ȭ
	//short student[20] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};  // ����� �ʱ�ȭ
	//short student[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};  // ����� �ʱ�ȭ
	//short student[20] = {0,};  // ����� �ʱ�ȭ, ��� 0
	//printf("%d", student[1]);
	//short student[20] = {10,};  // ����� �ʱ�ȭ, �ε��� 0�� 10, �ε���1���� 0
	//printf("%d", student[1]);
	/*for (int i = 0; i < 20; i++) {
		student[i] = 0;
	}*/
	/*for (int i = 0; i < sizeof(student) / sizeof(short); i++) {
		student[i] = 0;
	}*/
	//int index = 1;
	//student[index] = 10;
	/*printf("%d", student[19]);*/

	/*char data[5] = { 1, 2, 3, 4, 5 };
	int result = 0, i;
	for (i = 0; i < 5; i++) {
		result = result + data[i];
	}
	printf("data �迭�� �� ����� ���� %d�Դϴ�\n", result);*/

	//char data[6] = "happy";  // ���ڿ� �������ε����� 0�����Ͽ� ���ڿ� ǥ��,
	//char data[] = "happy";  // ������� ���ڿ� ���� �˾ƺ��� ����Ƿ� ����θ� �˾Ƽ� 
	//char data[] = "�ȳ��ϼ���";
	//printf("%d", data[5]);
	//printf("%d", (int)sizeof(data));

	// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//char data[10] = { 'a', 'b', 'c', 0,};
	////int data_length = strlen(data);
	////printf("%d", data_length);
	//char data_copy[16];
	//strcpy(data_copy, data);
	//printf("%s", data_copy);
	//strcat(data, "!!!!");
	//printf("%s", data);

	//char data[5][4] = {{1, 2, 3}, {4, 5, 6}};  // 2�����迭 ���� �� �ʱ�ȭ


	// 287p ��������
	//short data[9] = { 4, 6, 9, 8, 7, 2, 5, 1, 3 };

	// 2��
	//int result = 0;
	//for (int i = 0; i < sizeof(data) / sizeof(short); i = i + 2) {
	//	if (i % 2 == 0) result += data[i];
	//}
	//printf("%d", result);

	// 3��
	/*int max_num = 0;
	for (int i = 0; i < sizeof(data) / sizeof(short); i++) {
		if (data[i] > max_num) max_num = data[i];
	}
	printf("%d", max_num);*/

	// 4�� !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	/*char data[12] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	data[5] = 1;
	data[11] = 2;
	char datas[3][4] = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
	for (int i = 0; i < sizeof(data) / sizeof(char); i++) {
		int idx = i / 3;
		int col = i % 4;
		datas[idx][col] = data[i];
	}*/

	// 5��
	/*int data[7] = { 6, 3, 9, 7, 2, 4, 1 };
	for (int i = 0; i < (sizeof(data) / sizeof(int)) - 1; i++) {
		for (int j = 0; j < (sizeof(data) / sizeof(int)) - (i + 1);j++) {
			if (data[j] > data[j + 1]) {
				int temp = data[j];
				data[j] = data[j + 1];
				data[j + 1] = temp;
			}
		}
	}
	for (int i = 0; i < sizeof(data) / sizeof(int); i++) printf("%d", data[i]);*/

	// ������
	//short num;
	//short *ptr;  // ������ ���� ����, short�� �ּҸ� ����ų ������ Ÿ���� �����ٻ�, ������ 4byte

	//num = 10;
	//ptr = &num;  // ptr�� num�� �ּ� �ʱ�ȭ �Ҵ�
	//printf("%d\n", num);
	//printf("%x\n", (short)ptr);
	//printf("%d\n", *ptr);
	
	// tempFunc
	/*int num1 = 10;
	int num2 = 20;
	tempFunc(&num1, &num2);
	printf("num1 -> %d, num2 -> %d\n", num1, num2);*/

}
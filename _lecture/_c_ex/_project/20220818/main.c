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


	// 배열
	//short student[20];  // 배열 선언
	//short student[A]; // 선언시 인덱스의 길이 변수로는 안됨
	//student[1] = 10;  // 초기화
	//short student[20] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};  // 선언과 초기화
	//short student[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};  // 선언과 초기화
	//short student[20] = {0,};  // 선언과 초기화, 모두 0
	//printf("%d", student[1]);
	//short student[20] = {10,};  // 선언과 초기화, 인덱스 0만 10, 인덱스1부터 0
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
	printf("data 배열의 각 요소의 합은 %d입니다\n", result);*/

	//char data[6] = "happy";  // 문자열 마지막인덱스에 0저장하여 문자열 표현,
	//char data[] = "happy";  // 길어지면 문자열 길이 알아보기 힘드므로 비워두면 알아서 
	//char data[] = "안녕하세요";
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

	//char data[5][4] = {{1, 2, 3}, {4, 5, 6}};  // 2차원배열 선언 및 초기화


	// 287p 연습문제
	//short data[9] = { 4, 6, 9, 8, 7, 2, 5, 1, 3 };

	// 2번
	//int result = 0;
	//for (int i = 0; i < sizeof(data) / sizeof(short); i = i + 2) {
	//	if (i % 2 == 0) result += data[i];
	//}
	//printf("%d", result);

	// 3번
	/*int max_num = 0;
	for (int i = 0; i < sizeof(data) / sizeof(short); i++) {
		if (data[i] > max_num) max_num = data[i];
	}
	printf("%d", max_num);*/

	// 4번 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	/*char data[12] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	data[5] = 1;
	data[11] = 2;
	char datas[3][4] = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
	for (int i = 0; i < sizeof(data) / sizeof(char); i++) {
		int idx = i / 3;
		int col = i % 4;
		datas[idx][col] = data[i];
	}*/

	// 5번
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

	// 포인터
	//short num;
	//short *ptr;  // 포인터 변수 선언, short는 주소를 가리킬 변수의 타입을 적어줄뿐, 실제로 4byte

	//num = 10;
	//ptr = &num;  // ptr에 num의 주소 초기화 할당
	//printf("%d\n", num);
	//printf("%x\n", (short)ptr);
	//printf("%d\n", *ptr);
	
	// tempFunc
	/*int num1 = 10;
	int num2 = 20;
	tempFunc(&num1, &num2);
	printf("num1 -> %d, num2 -> %d\n", num1, num2);*/

}
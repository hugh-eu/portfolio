#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// num1 10, num2 20, 포인터를 이용한 스왑함수
//void swapFunc(int * const n1, int * const n2) {  // const를 사용하여 주소변경 막기
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
	//void *ptr = &data;  // 대상의 크기가 정해져있지 않음, 대상의 크기지정을 잠시 미루기, 자유롭게 캐스팅하여 사용
	//*(char *)ptr = 0x12345678;  // 형변환해야 값변경 가능, 아닐시 오류
	//printf("%X", data);

	// getData
	/*int data = 0x12345678;
	printf("%X\n", getData(&data, 1));*/

	//int data = 0x12345678;
	//short* ptr = &data;
	//*ptr = 0x0412;  // 리틀엔디언, 메모리에 뒤에값부터 저장
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
	//rewind(stdin);  // 버퍼에 남아있는 입력값 지우기
	//char b = getchar();
	//rewind(stdin);
	//printf("a:%c b:%c", a, b);

	//char input_string[10];
	//gets(input_string);  // 9자 마지막 0
	//printf("%s\n", input_string);
	//printf("%d", (int)sizeof(input_string));


	// str -> int로 변환
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

	// atoi, 문자열을 정수로 변환
	/*int first_num, second_num;
	char first_string[16], second_string[16];
	printf("입력 : ");
	gets(first_string);
	printf("입력 : ");
	gets(second_string);
	first_num = atoi(first_string);
	second_num = atoi(second_string);
	printf("%s %d %s %d", first_string, first_num, second_string, second_num);*/

	//int data;
	//scanf("%d", &data);  // 정수
	//char strs[10];
	//scanf("%s", strs);  // 배열에 문자열
	//printf("%d %s", data, strs);

	//float a, b, c;
	//scanf("%f %f %f", &a, &b, &c);
	//printf("%.2lf", (a + b + c) / 3);  // int일경우 3.0, or (float)

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
	printf("이름 :%s, 몸무게 : %skg, 키 : %scm, 혈액형 : %s형, 심박수 : %s회", name, weight, height, bloodType, heartRate);*/

	/*char students[3][34];
	for (int i = 0; i < 3; i++) {
		printf("%d 번째 학생 이름 : ", i + 1);
		scanf("%s", &*students[i]);
		printf("국어 점수  : ");
		scanf("%d", &*(unsigned int*)(students[i] + 10));
		printf("영어 점수 : ");
		scanf("%d", &*(unsigned int*)(students[i] + 14));
		printf("수학 점수 : ");
		scanf("%d", &*(unsigned int*)(students[i] + 18));
		*(unsigned int*)(students[i] + 22) = (unsigned int)(*(unsigned int*)(students[i] + 10) + *(unsigned int*)(students[i] + 14) + *(unsigned int*)(students[i] + 18));
		*(double*)(students[i] + 26) = *(unsigned int*)(students[i] + 22) / 3.0;
	}
	printf("-----------------------------------------------------\n");
	printf("이름\t국어\t영어\t수학\t총점\t평균\t등수\n");
	printf("-----------------------------------------------------\n");
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if ((int)students[i][22] >= (int)students[j][22]) {
				if (j == 2) {
					printf("%s\t%d\t%d\t%d\t%d\t%.2lf\t1등\n", students[i], *(unsigned int*)(students[i] + 10), *(unsigned int*)(students[i] + 14), *(unsigned int*)(students[i] + 18), *(unsigned int*)(students[i] + 22), *(double*)(students[i] + 26));
					break;
				}
			}
			else {
				if (j == 2) {
					printf("%s\t%d\t%d\t%d\t%d\t%.2lf\t2등\n", students[i], *(unsigned int*)(students[i] + 10), *(unsigned int*)(students[i] + 14), *(unsigned int*)(students[i] + 18), *(unsigned int*)(students[i] + 22), *(double*)(students[i] + 26));
					break;
				}
				else {
					printf("%s\t%d\t%d\t%d\t%d\t%.2lf\t3등\n", students[i], *(unsigned int*)(students[i] + 10), *(unsigned int*)(students[i] + 14), *(unsigned int*)(students[i] + 18), *(unsigned int*)(students[i] + 22), *(double*)(students[i] + 26));
					break;
				}
			}
		}
	}*/

	

}
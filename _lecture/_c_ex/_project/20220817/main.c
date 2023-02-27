#include <stdio.h>
#include <stdlib.h>
#include <time.h>  // 난수 seed값에 현재시간을 부여하여 seed 변경하기 위해
//#define ABLE_HEIGHT 120
//#include <stdbool.h>  // 불타입 라이브러리

void main(void) {

	/*short data = 5;
	printf("data is %d", data);*/

	/*char month = 12, day = 3;
	printf("너는 생일이 언제니?\n");
	printf("나의 생일은 %d월 %d일입니다.", month, day);*/

	//char my_char = 65;
	//printf("my_char is %d\n", my_char);  // 정수
	//printf("my_char is %c", my_char);  // 문자	
	
	//float my_float = 3.14f; //float를 나타내는 뒤에 f 추가, f를 안붙이는 경우 double
	//double my_double = 3.14;
	//printf("my_float is %f\n", my_float);  // 플로트, 소수점이하 6자리
	//printf("my_double is %f\n", my_double);  // 더블도 같은 %f 소수점이하 14자리

	//int data1 = -1;  // signed 는 생략가능
	//unsigned int data2 = 4294967295;
	//printf("%d, %u, %d, %u", data1, data1, data2, data2);  // 음수최대값 -1의 메모리 구조가 unsigned 최대값과 메모리구조가 같음,

	//int data = 7;
	//printf("[%d] [%5d] [%05d] [%-5d]", data, data, data, data);  // 출력칸수, 0으로 채우기, 왼쪽정렬

	//double data = 3.141592;
	//printf("[%f] [%.4f] [%8.4f] [%-8.4f]", data, data, data, data);  // 실수, 4자리까지, 8칸 4자리까지

	//printf("Hello~ Tipssoft.com\n");
	//printf("Hello~ Tipssoft.com\rHi~~~~");  // r을 사용한경우 캐럿이 맨앞으로 이동한다음 뒤의 문자열이 기존 문자열 덮어씀
	//_getch();  // 출력결과 확인위해 input대기

	/*printf("1234567\b");
	_getch();*/


	// 0 false, 0이 아니면 true
	/*if (1) {
		
	}
	if (true) {  // stdbool.h, 1바이트

	}*/

	/*int i = 5, sum;
	sum = ++i;  // i를 먼저 증가, 후에 대입
	printf("%d %d", sum, i);*/
	

	//int i = 5, sum;
	//sum = i++;  // i를 먼저 대입, 후에 증가
	//printf("%d %d", sum, i);

	//int num = 5;
	//++num;  // 대입하는 것이 아니기 때문에 관계없음
	//printf("%d", num);

	// if ~ else 문
	/*int num = 10;
	if (num >= 20) {
		printf("%d는 20보다 크다!", num);
	}
	else {
		printf("%d는 20보다 작거나 같다!", num);
	}*/

	// if ~ else if 문
	//int my_score = 75;

	//if (my_score >= 90) printf("A");  // 한줄인경우 중괄호 없이 가능
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
	//if (data > 3);  // 실수, 세미콜론으로 조건문을 끝냈기 때문에 원하던 data값 3이 아니라 4로 증가
	//	data++;
	//	printf("%d", data);

	// 어린이의 신장이 120이상이면 탑승가능, 미만이면 탑승불가
	//int child_height;

	//printf("아이의 키를 입력하세요 : ");
	//scanf_s("%d", &child_height);  // scanf_s(보안) 아이키 입력, & child_height 변수가 가리키는 메모리주소

	//if (child_height >= ABLE_HEIGHT) {
	//	printf("탑승 가능");
	//}
	//else {
	//	printf("탑승 불가");
	//}

	/*int value = 1000;
	double point = (value >= 10000) ? value * 0.1 : value * 0.05;
	printf("point = %f", point);*/

	// switch ~ default == if~ else if ~ else
	//int num = 2;
	////char num = 'A'; // 문자도 가능
	//switch (num){
	////switch (++num){  // 조건 가능
	//case 2:  // 케이스 순서 변경 가능
	//case 1:  // 케이스 중첩 가능
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

	// 반복문
	// for, while, do ~ while: 무조건 1회 실행 후 조건에 의한 반복(do에 실행구문, while은 조건만)

	/*for (int num = 1; num < 6; num++) {  // for 안에서 선언되어 for 안에서만 사용, 시작(밖에서 초기화), 끝, 단계 생략가능, 내부에 코드
		printf("num = %d\n", num);
	}*/

	//사용자가 입력한 숫자를 이용해 해당 구구단 출력

	//int i, j;  // for 밖에서 선언되어 밖에서도 사용가능
	//printf("구구단을 출력할 단을 입력 : ");
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

	// 난수를 이용해 가위바위보
	//int rand_num, usr_num;
	//srand(time(NULL));  // 난수의 시드 시간으로 초기화
	//while (1) {
	//	printf("가위바위보 게임\n");
	//	printf("1. 가위  2. 바위  3. 보  0. 종료\n");
	//	scanf_s("%d", &usr_num);
	//	rand_num = (rand() % 3) + 1;
	//	if (rand_num == usr_num) {
	//		printf("비겼습니다.\n");
	//	}
	//	else if (usr_num == 1) {
	//		if (rand_num == 2) {
	//			printf("유저 : 가위, 컴퓨터 : 바위, 졌습니다.\n");
	//		}
	//		else {
	//			printf("유저 : 가위, 컴퓨터 : 보, 이겼습니다.\n");
	//		}
	//	}
	//	else if (usr_num == 2) {
	//		if (rand_num == 1) {
	//			printf("유저 : 바위, 컴퓨터 : 가위, 이겼습니다.\n");
	//		}
	//		else {
	//			printf("유저 : 바위, 컴퓨터 : 보, 졌습니다.\n");
	//		}
	//	}
	//	else if (usr_num == 3) {
	//		if (rand_num == 1) {
	//			printf("유저 : 보, 컴퓨터 : 가위, 졌습니다.\n");
	//		}
	//		else {
	//			printf("유저 : 보, 컴퓨터 : 바위, 이겼습니다.\n");
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
		printf("만세");
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
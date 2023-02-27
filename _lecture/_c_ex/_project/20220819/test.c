/*#include <stdio.h>

void main() {

	unsigned int kor_score = 0, eng_score = 0, math_score = 0;
	printf("국어 점수 : ");
	scanf_s("%d", &kor_score);
	printf("영어 점수 : ");
	scanf_s("%d", &eng_score);
	printf("수학 점수 : ");
	scanf_s("%d", &math_score);
	unsigned int total_score = kor_score + eng_score + math_score;
	float average_score = total_score / 3.0;
	printf("1. 국어 점수 : %d\n2. 영어 점수 : %d\n3. 수학 점수 : %d\n총 점 : %6d\n평균 점수 : %7.2f", kor_score, eng_score, math_score, total_score, average_score);

}*/

//#include <stdio.h>
//
//void main() {
//
//	char op;
//	char str[12];
//	printf("1. 문자 입력 : ");
//	op = getchar();
//	printf("2. 문자열 입력 : ");
//	scanf_s("%s", str, 12);
//	printf("문자 출력 : %c\n", op);
//	printf("문자열 출력 : |%-12s|", str);
//
//}

//#include <stdio.h>
//
//void main() {
//	int num1, num2, triple;
//	float division;
//	printf("정수값 2개 입력 : ");
//	scanf_s("%d %d", &num1, &num2);
//	triple = num1 * num1 * num1;
//	division = (float)num1 / num2;
//	printf("세제곱 연산 결과 : %d * %d * %d = %08d\n", num1, num1, num1, triple);
//	printf("나눗셈 연산 결과 : %d / %d = %08.3f", num1, num2, division);
//}

//#include <stdio.h>
//
//void main() {
//	char a;
//	printf("알파벳 입력 : ");
//	a = getchar();
//	printf("입력한 알파벳 : %c\n", a);
//	printf("알파벳 아스키코드값 : %d\n", a);
//	printf("입력한 알파벳 + 8 : %c\n", a + 8);
//	printf("프로그램을 종료합니다.");
//}

//#include <stdio.h>
//#define ONE_INCH_TO_CM 2.54
//
//void main() {
//	float inch;
//	printf("- 인치를 센티미터로 환산하는 프로그램\n인치 입력(소수 둘째 자리) : ");
//	scanf_s("%f", &inch);
//	float inch_to_cm = inch * ONE_INCH_TO_CM;
//	printf("%.2f인치는 %.2fcm입니다.", inch, inch_to_cm);
//}

//#include <stdio.h>
//#define ONE_MILE_TO_KM 1.61
//
//void main() {
//	float mile;
//	printf("- 마일를 킬로미터로 환산하는 프로그램\n마일 입력(소수 둘째 자리) : ");
//	scanf_s("%f", &mile);
//	float mile_to_km = mile * ONE_MILE_TO_KM;
//	printf("%.2f마일은 %.2fkm입니다.", mile, mile_to_km);
//}

//#include <stdio.h>
//#define _CRT_SECURE_NO_WARNINGS  // scanf 보안경고 무시
//#pragma warning(disable:4996)  // scanf 반환값오류 무시
//
//void main(){
//	char a[100];
//	printf("- 배열을 사용하여 문자열을 출력하는 프로그램\n문자열 입력 : ");
//	scanf("%s", a);
//	printf("문자열 출력 : \"%s\"", a);
//}

//#include <stdio.h>
//
//void main() {
//	int a = 8, b = 9, c = 0;
//	c = a++ + b++;
//	c = --a + --b;
//	c = ++a - b--;
//	printf("%d %d %d", a, b, c);
//}

//#include <stdio.h>
//
//void main() {
//	char a;
//	printf("문자를 입력하시오 : ");
//	scanf_s("%c", &a, 1);
//	if (65 <= a && a <= 90) printf("입력한 %c는(은) \"알파벳 대문자\"입니다", a);
//	else if (97 <= a && a <= 122) printf("입력한 %c는(은) \"알파벳 소문자\"입니다", a);
//	else if (48 <= a && a <= 57) printf("입력한 %c는(은) \"숫자\"입니다", a);
//	else printf("입력한 %c는(은) \"기타 문자\"입니다\n프로그램을 다시 시작하세요.", a);
//}

//#include <stdio.h>
//
//void main() {
//	int a, b;
//	int *c;
//	printf("정수 입력 : ");
//	scanf_s("%d", &a, 4);
//	if (a < 0 || a > 100) printf("입력한 점수 %d는(은) 허용 구간이 아닙니다.\n프로그램을 다시 실행하세요.", a);
//	else {
//		switch (a / 5) {
//		case 19:
//			printf("입력한 점수 : %d\n등급 : A+ 학점", a);
//			break;
//		case 18:
//			printf("입력한 점수 : %d\n등급 : A0 학점", a);
//			break;
//		case 17:
//			printf("입력한 점수 : %d\n등급 : B+ 학점", a);
//			break;
//		case 16:
//			printf("입력한 점수 : %d\n등급 : B0 학점", a);
//			break;
//		case 15:
//			printf("입력한 점수 : %d\n등급 : C+ 학점", a);
//			break;
//		case 14:
//			printf("입력한 점수 : %d\n등급 : C0 학점", a);
//			break;
//		case 13:
//			printf("입력한 점수 : %d\n등급 : D+ 학점", a);
//			break;
//		case 12:
//			printf("입력한 점수 : %d\n등급 : D0 학점", a);
//			break;
//		default:
//			printf("입력한 점수 : %d\n등급 : F 학점", a);
//			break;
//		}
//	}
//}

//#include <stdio.h>
//#define _CRT_SECURE_NO_WARNINGS  // scanf 보안경고 무시
//#pragma warning(disable:4996)  // scanf 반환값오류 무시
//
//void main() {
//	char a;
//	printf("계절을 선택할 알파벳 입력 : ");
//	scanf("%c", &a);
//	switch (a) {
//	case 'A':
//	case 'a':
//		printf("계절 : 봄\n수행 : 꽃을 가꾼다");
//		break;
//	case 'S':
//	case 's':
//		printf("계절 : 여름\n수행 : 수영을 한다");
//		break;
//	case 'D':
//	case 'd':
//		printf("계절 : 가을\n수행 : 추수를 한다");
//		break;
//	case 'F':
//	case 'f':
//		printf("계절 : 겨울\n수행 : 스키를 탄다");
//		break;
//	default:
//		printf("허용되지 않는 알파벳입니다.\n대소문자 구별없이 A, S, D, F만 허용합니다.\n프로그램을 다시 시작하세요.");
//		break;
//	}
//}

//#include <stdio.h>
//
//void main() {
//	int a, b = 0, c;
//	printf("정수값 입력 : ");
//	scanf_s("%d", &a);
//	while (a < 0) {
//		printf("음의 정수값은 허용하지 않습니다.\n양의 정수값을 다시 입력하세요.\n정수값 입력 : ");
//		scanf_s("%d", &a);
//	}
//	for (int i = 1; i < a + 1; i++) {
//		if(i % 2 == 1) b += i;
//	}
//	printf("1부터 %d까지 홀수의 누적 합계는 %d", a, b);
//}

//#include <stdio.h>
//
//void main() {
//	int a, b = 0, c;
//	printf("정수값 입력 : ");
//	scanf_s("%d", &a);
//	while (a < 0) {
//		printf("음의 정수값은 허용하지 않습니다.\n양의 정수값을 다시 입력하세요.\n정수값 입력 : ");
//		scanf_s("%d", &a);
//	}
//	for (int i = 1; i < a + 1; i++) {
//		if (i % 2 == 0) b += i;
//	}
//	printf("1부터 %d까지 짝수의 누적 합계는 %d", a, b);
//}
/*#include <stdio.h>

void main() {

	unsigned int kor_score = 0, eng_score = 0, math_score = 0;
	printf("���� ���� : ");
	scanf_s("%d", &kor_score);
	printf("���� ���� : ");
	scanf_s("%d", &eng_score);
	printf("���� ���� : ");
	scanf_s("%d", &math_score);
	unsigned int total_score = kor_score + eng_score + math_score;
	float average_score = total_score / 3.0;
	printf("1. ���� ���� : %d\n2. ���� ���� : %d\n3. ���� ���� : %d\n�� �� : %6d\n��� ���� : %7.2f", kor_score, eng_score, math_score, total_score, average_score);

}*/

//#include <stdio.h>
//
//void main() {
//
//	char op;
//	char str[12];
//	printf("1. ���� �Է� : ");
//	op = getchar();
//	printf("2. ���ڿ� �Է� : ");
//	scanf_s("%s", str, 12);
//	printf("���� ��� : %c\n", op);
//	printf("���ڿ� ��� : |%-12s|", str);
//
//}

//#include <stdio.h>
//
//void main() {
//	int num1, num2, triple;
//	float division;
//	printf("������ 2�� �Է� : ");
//	scanf_s("%d %d", &num1, &num2);
//	triple = num1 * num1 * num1;
//	division = (float)num1 / num2;
//	printf("������ ���� ��� : %d * %d * %d = %08d\n", num1, num1, num1, triple);
//	printf("������ ���� ��� : %d / %d = %08.3f", num1, num2, division);
//}

//#include <stdio.h>
//
//void main() {
//	char a;
//	printf("���ĺ� �Է� : ");
//	a = getchar();
//	printf("�Է��� ���ĺ� : %c\n", a);
//	printf("���ĺ� �ƽ�Ű�ڵ尪 : %d\n", a);
//	printf("�Է��� ���ĺ� + 8 : %c\n", a + 8);
//	printf("���α׷��� �����մϴ�.");
//}

//#include <stdio.h>
//#define ONE_INCH_TO_CM 2.54
//
//void main() {
//	float inch;
//	printf("- ��ġ�� ��Ƽ���ͷ� ȯ���ϴ� ���α׷�\n��ġ �Է�(�Ҽ� ��° �ڸ�) : ");
//	scanf_s("%f", &inch);
//	float inch_to_cm = inch * ONE_INCH_TO_CM;
//	printf("%.2f��ġ�� %.2fcm�Դϴ�.", inch, inch_to_cm);
//}

//#include <stdio.h>
//#define ONE_MILE_TO_KM 1.61
//
//void main() {
//	float mile;
//	printf("- ���ϸ� ų�ι��ͷ� ȯ���ϴ� ���α׷�\n���� �Է�(�Ҽ� ��° �ڸ�) : ");
//	scanf_s("%f", &mile);
//	float mile_to_km = mile * ONE_MILE_TO_KM;
//	printf("%.2f������ %.2fkm�Դϴ�.", mile, mile_to_km);
//}

//#include <stdio.h>
//#define _CRT_SECURE_NO_WARNINGS  // scanf ���Ȱ�� ����
//#pragma warning(disable:4996)  // scanf ��ȯ������ ����
//
//void main(){
//	char a[100];
//	printf("- �迭�� ����Ͽ� ���ڿ��� ����ϴ� ���α׷�\n���ڿ� �Է� : ");
//	scanf("%s", a);
//	printf("���ڿ� ��� : \"%s\"", a);
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
//	printf("���ڸ� �Է��Ͻÿ� : ");
//	scanf_s("%c", &a, 1);
//	if (65 <= a && a <= 90) printf("�Է��� %c��(��) \"���ĺ� �빮��\"�Դϴ�", a);
//	else if (97 <= a && a <= 122) printf("�Է��� %c��(��) \"���ĺ� �ҹ���\"�Դϴ�", a);
//	else if (48 <= a && a <= 57) printf("�Է��� %c��(��) \"����\"�Դϴ�", a);
//	else printf("�Է��� %c��(��) \"��Ÿ ����\"�Դϴ�\n���α׷��� �ٽ� �����ϼ���.", a);
//}

//#include <stdio.h>
//
//void main() {
//	int a, b;
//	int *c;
//	printf("���� �Է� : ");
//	scanf_s("%d", &a, 4);
//	if (a < 0 || a > 100) printf("�Է��� ���� %d��(��) ��� ������ �ƴմϴ�.\n���α׷��� �ٽ� �����ϼ���.", a);
//	else {
//		switch (a / 5) {
//		case 19:
//			printf("�Է��� ���� : %d\n��� : A+ ����", a);
//			break;
//		case 18:
//			printf("�Է��� ���� : %d\n��� : A0 ����", a);
//			break;
//		case 17:
//			printf("�Է��� ���� : %d\n��� : B+ ����", a);
//			break;
//		case 16:
//			printf("�Է��� ���� : %d\n��� : B0 ����", a);
//			break;
//		case 15:
//			printf("�Է��� ���� : %d\n��� : C+ ����", a);
//			break;
//		case 14:
//			printf("�Է��� ���� : %d\n��� : C0 ����", a);
//			break;
//		case 13:
//			printf("�Է��� ���� : %d\n��� : D+ ����", a);
//			break;
//		case 12:
//			printf("�Է��� ���� : %d\n��� : D0 ����", a);
//			break;
//		default:
//			printf("�Է��� ���� : %d\n��� : F ����", a);
//			break;
//		}
//	}
//}

//#include <stdio.h>
//#define _CRT_SECURE_NO_WARNINGS  // scanf ���Ȱ�� ����
//#pragma warning(disable:4996)  // scanf ��ȯ������ ����
//
//void main() {
//	char a;
//	printf("������ ������ ���ĺ� �Է� : ");
//	scanf("%c", &a);
//	switch (a) {
//	case 'A':
//	case 'a':
//		printf("���� : ��\n���� : ���� ���۴�");
//		break;
//	case 'S':
//	case 's':
//		printf("���� : ����\n���� : ������ �Ѵ�");
//		break;
//	case 'D':
//	case 'd':
//		printf("���� : ����\n���� : �߼��� �Ѵ�");
//		break;
//	case 'F':
//	case 'f':
//		printf("���� : �ܿ�\n���� : ��Ű�� ź��");
//		break;
//	default:
//		printf("������ �ʴ� ���ĺ��Դϴ�.\n��ҹ��� �������� A, S, D, F�� ����մϴ�.\n���α׷��� �ٽ� �����ϼ���.");
//		break;
//	}
//}

//#include <stdio.h>
//
//void main() {
//	int a, b = 0, c;
//	printf("������ �Է� : ");
//	scanf_s("%d", &a);
//	while (a < 0) {
//		printf("���� �������� ������� �ʽ��ϴ�.\n���� �������� �ٽ� �Է��ϼ���.\n������ �Է� : ");
//		scanf_s("%d", &a);
//	}
//	for (int i = 1; i < a + 1; i++) {
//		if(i % 2 == 1) b += i;
//	}
//	printf("1���� %d���� Ȧ���� ���� �հ�� %d", a, b);
//}

//#include <stdio.h>
//
//void main() {
//	int a, b = 0, c;
//	printf("������ �Է� : ");
//	scanf_s("%d", &a);
//	while (a < 0) {
//		printf("���� �������� ������� �ʽ��ϴ�.\n���� �������� �ٽ� �Է��ϼ���.\n������ �Է� : ");
//		scanf_s("%d", &a);
//	}
//	for (int i = 1; i < a + 1; i++) {
//		if (i % 2 == 0) b += i;
//	}
//	printf("1���� %d���� ¦���� ���� �հ�� %d", a, b);
//}
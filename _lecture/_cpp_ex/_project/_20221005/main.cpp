#define _CRT_NO_SECURE_WARNINGS
#include <iostream>
#include <string>
#include <windows.h>
#include <tuple>

using namespace std;

bool checkWin(char arrs[3][3], char c);

tuple<int, int> checkComTurn(char arrs[3][3]);

void printBoard(char arrs[3][3]);

void swap(int *n1, int *n2);
void swap2(int &n1, int &n2);

int multi_calculator(int n1, int n2);

double multi_calculator(double d1, double d2);

void my_print(int i);
void my_print(double d);
void my_print(string s);

int my_absolute(int i);
double my_absolute(double d);

inline void factorial_func(int n);

void display(char c = 'c', int n = 3);  // 디폴트는 함수원형에만 사용, 구현부에는 정의하지 않음, 디폴트값은 맨뒤로

int doSum(int a, int b, int c = 0, int d = 0, int e = 0);

int main() {

	//int scores[10];
	//for (int i = 0; i < sizeof(scores)/sizeof(int); i++) {
	//	scores[i] = 10 * i;
	//}
	//for (int score : scores) {
	//	cout << score << endl;
	//}

	//const int ARRAY_SIZE = 10;
	//int scores2[ARRAY_SIZE];  // 변수로 배열선언 불가, 상수로

	//int scores3[5] = { 0, 1, 2, 3, 4 };
	//int scores3{ 0, 1, 2, 3, 4 };
	
	//int *scores4 = new int[5];
	//cout << scores4 << endl;
	//cout << &scores4[1] << endl;
	//for (int i = 0; i < 5; i++) {
	//	scores4[i] = i + 2;
	//}
	//for (int i = 0; i < 5; i++) {
	//	cout << scores4[i] << endl;
	//}

	//int scores5[]{ 10, 20, 30, 40, 50 };
	//for (auto &score : scores5) {  // call by ref, 변수에 값을 대입하지않고 바로 주소로 찾아가기 떄문에 빠름
	//	cout << "score : " << score << endl;
	//}

	// 100이하 난수, 길이 10인 배열, 가장 큰 정수 작은정수를 찾아 인덱스출력

	//srand((unsigned int)time(NULL));
	//int arrs[10];
	//for (int i = 0; i < 10; i++) {
	//	arrs[i] = (rand() % 100) + 1;
	//}
	//cout << "arrs[10] = {";
	//for (int i = 0; i < 10; i++) {
	//	cout << arrs[i];
	//	if (i < 9) {
	//		cout << ", ";
	//	}
	//	else {
	//		cout << "}" << endl;
	//	}
	//}
	//int max_int, min_int, max_idx, min_idx;
	//for (int i = 0; i < 10; i++) {
	//	if (i == 0) {
	//		max_int = arrs[i];
	//		min_int = arrs[i];
	//		max_idx = i;
	//		min_idx = i;
	//	}
	//	else {
	//		if (max_int < arrs[i]) {
	//			max_int = arrs[i];
	//			max_idx = i;
	//		}
	//		if (arrs[i] < min_int) {
	//			min_int = arrs[i];
	//			min_idx = i;
	//		}
	//	}
	//}
	//printf("최대값 : %d, 인덱스 : %d\n최소값 : %d, 인덱스 : %d", max_int, max_idx, min_int, min_idx);

	// 100이하 난수, 길이 10인 배열, 오름, 내림 정렬
	//srand((unsigned int)time(NULL));
	//int arrs[10];
	//for (int i = 0; i < 10; i++) {
	//	arrs[i] = (rand() % 100) + 1;
	//}
	//cout << " arrs[10] = {";
	//for (int i = 0; i < 10; i++) {
	//	cout << arrs[i];
	//	if (i < 9) {
	//		cout << ", ";
	//	}
	//	else {
	//		cout << "}" << endl;
	//	}
	//}

	//for (int i = 0; i < 9; i++) {
	//	for (int j = 0; j < 9; j++) {
	//		if (arrs[j + 1] < arrs[j]) {
	//			int temp = arrs[j + 1];
	//			arrs[j + 1] = arrs[j];
	//			arrs[j] = temp;
	//		}
	//	}
	//}
	//cout << "오름차순 : {";
	//for (int i = 0; i < 10; i++) {
	//	cout << arrs[i];
	//	if (i < 9) {
	//		cout << ", ";
	//	}
	//	else {
	//		cout << "}" << endl;
	//	}
	//}
	//for (int i = 0; i < 9; i++) {
	//	for (int j = 0; j < 9; j++) {
	//		if (arrs[8 - j] < arrs[9 - j]) {
	//			int temp = arrs[8 - j];
	//			arrs[8 - j] = arrs[9 - j];
	//			arrs[9 - j] = temp;
	//		}
	//	}
	//}
	//cout << "내림차순 : {";
	//for (int i = 0; i < 10; i++) {
	//	cout << arrs[i];
	//	if (i < 9) {
	//		cout << ", ";
	//	}
	//	else {
	//		cout << "}" << endl;
	//	}
	//}

	//int nums[3][5];
	//for (int i = 0; i < 3; i++) {
	//	for (int j = 0; j < 5; j++) {
	//		nums[i][j] = (j + 1) * pow(10, (i + 1));
	//	}
	//}
	//for (int i = 0; i < sizeof(nums)/sizeof(nums[i]); i++) {
	//	for (int j = 0; j < sizeof(nums[i]) / sizeof(int); j++) {
	//		printf("nums[%d][%d] = %d\n", i, j, nums[i][j]);
	//	}
	//}

	//int nums[3][5] = { {1, 2, 3,4, 5}, {1, 3, 2, 4, 5}, {1, 2, 3, 4, 5} };
	

	// 구구단 결과값 저장 2차원배열
	//int nums[8][9];
	//for (int i = 0; i < 8; i++) {
	//	for (int j = 0; j < 9; j++) {
	//		nums[i][j] = (i + 2) * (j + 1);
	//	}
	//}
	//for (int i = 0; i < sizeof(nums[0]) / sizeof(nums[0][0]); i++) {
	//	for (int j = 0; j < sizeof(nums) / sizeof(nums[0]); j++) {
	//		printf("%d X %d = %d\t", j + 2, i + 1, nums[j][i]);
	//	}
	//	cout << endl;
	//}
	
	// 틱택토 게임
	//char boards[3][3];
	//int selNum, row, column;
	//while (true) {
	//	cout << "1. 틱택토게임  2. 종료 ";
	//	cin >> selNum;
	//	if (selNum == 1) {
	//		for (int i = 0; i < 3; i++) {
	//			for (int j = 0; j < 3; j++) {
	//				boards[i][j] = ' ';
	//			}
	//		}
	//		printBoard(boards);
	//		while (true) {
	//			bool chk = true;
	//			while (chk) {
	//				cout << "행 : ";
	//				cin >> row;
	//				cout << "열 : ";
	//				cin >> column;
	//				if (boards[row - 1][column - 1] == ' ') {
	//					boards[row - 1][column - 1] = 'o';
	//					printBoard(boards);
	//					chk = false;
	//				}
	//				else {
	//					cout << "이미 선택된 자리입니다." << endl;
	//				}
	//			}
	//			bool chkWin = false;
	//			chkWin = checkWin(boards, 'o');
	//			if (chkWin) break;
	//			cout << "컴퓨터 선택중...." << endl;
	//			Sleep(1000);
	//			tuple<int, int> comTuple = checkComTurn(boards);
	//			if (get<0>(comTuple) == -1) {
	//				bool chkCom = true;
	//				srand((unsigned int)time(NULL));
	//				while (chkCom) {
	//					int comNum = rand() % 9 + 1;
	//					int comRow = comNum / 3, comCol = comNum % 3;
	//					if (boards[comRow][comCol] == ' ') {
	//						boards[comRow][comCol] = 'x';
	//						printBoard(boards);
	//						chkCom = false;
	//					}
	//				}
	//			}
	//			else {
	//				boards[get<0>(comTuple)][get<1>(comTuple)] = 'x';
	//				printBoard(boards);
	//			}
	//			bool chkLose = false;
	//			chkLose = checkWin(boards, 'x');
	//			if (chkLose) break;
	//		}
	//	}
	//	else {
	//		break;
	//	}
	//}

	// call by reference
	//int num1 = 10, num2 = 20;
	//cout << "before : num1 = " << num1 << " num2 = " << num2 << endl;
	//swap(&num1, &num2);
	//cout << "after : num1 = " << num1 << " num2 = " << num2 << endl;
	//swap2(num1, num2);
	//cout << "swap& : num1 = " << num1 << " num2 = " << num2 << endl;

	// 중복함수
	// 같은 함수명, 파라미터 개수 또는 타입이 다르게.
	//cout << "multi_calculator(10, 20) : " << multi_calculator(10, 20) << endl;
	//cout << "multi_calculator(3.14, 2.14) : " << multi_calculator(3.14, 2.14) << endl;
	
	// 정수 실수 문자열 출력 my_print() 중복함수, 입력값출력
	//int inputInt;
	//double inputDouble;
	//string inputString;
	//cout << "정수 : ";
	//cin >> inputInt;
	//cout << "실수 : ";
	//cin >> inputDouble;
	//cin.ignore();
	//cout << "문자열 : ";
	//getline(cin, inputString);
	//my_print(inputInt);
	//my_print(inputDouble);
	//my_print(inputString);
	
	// 정수 실수에 대한 절대값 my_absolute() 중복함수, 입력값에대한 절대값 출력
	//int inputInt;
	//double inputDouble;
	//cout << "정수 : ";
	//cin >> inputInt;
	//cout << "실수 : ";
	//cin >> inputDouble;
	//int absInt = my_absolute(inputInt);
	//double absDouble = my_absolute(inputDouble);
	//cout << "정수 절대값 : " << absInt << endl;
	//cout << "실수 절대값 : " << absDouble << endl;
	
	// 인라인 함수, 성능 향상, 
	//factorial_func(5);

	// 디폴트 매개변수 값, 매개변수는 원형부에만 구현부에는 뺌
	//display('a', 5);
	//display('b');
	//display();

	// 정수 2또는 3, 4, 5개의 의 합 출력
	//int nums[5];
	//int selNum, inputNum, chk, sum = 0;
	//for (int i = 0; i < sizeof(nums) / sizeof(int); i++) {
	//	cout << "1. 정수 입력  2. 종료 ";
	//	cin >> selNum;
	//	if (selNum == 1) {
	//		cout << "정수 : ";
	//		cin >> inputNum;
	//		nums[i] = inputNum;
	//		chk = i + 1;
	//	}
	//	else if (selNum == 2) {
	//		break;
	//	}
	//}
	//if (chk == 5) {
	//	sum = doSum(nums[0], nums[1], nums[2], nums[3], nums[4]);
	//}
	//else if (chk == 4) {
	//	sum = doSum(nums[0], nums[1], nums[2], nums[3]);
	//}
	//else if (chk == 3) {
	//	sum = doSum(nums[0], nums[1], nums[2]);
	//}
	//else if (chk == 2) {
	//	sum = doSum(nums[0], nums[1]);
	//}
	//cout << "sum = " << sum << endl;




	return 0;
}



int doSum(int a, int b, int c, int d, int e) {
	return a + b + c + d + e;
}



void display(char c, int n) {
	for (int i = 0; i < n; i++) {
		cout << c << endl;
	}
	cout << endl;
}



inline void factorial_func(int n) {
	int result = 1;
	for (int i = 1; i < n + 1; i++) {
		result *= i;
	}
	cout << n << "! = " << result << endl;
}



void my_print(int i) {
	cout << "정수 : " << i << endl;
}
void my_print(double b) {
	cout << "실수 : " << b << endl;
}
void my_print(string s) {
	cout << "문자열 : " << s << endl;
}


int my_absolute(int i) {
	if (i < 0) {
		return i * (-1);
	}
	else return i;
}
double my_absolute(double d) {
	if (d < 0) {
		return d * (-1);
	}
	else return d;
}


int multi_calculator(int n1, int n2) {
	return n1 * n2;
}
double multi_calculator(double d1, double d2) {
	return d1 * d2;
}


void swap(int *n1, int *n2) {
	int tempN1 = *n1;
	*n1 = *n2;
	*n2 = tempN1;
}
void swap2(int &n1, int &n2) {
	int tempN1 = n1;
	n1 = n2;
	n2 = tempN1;
}


bool checkWin(char arrs[3][3], char c) {
	int chkEmp = 0;
	for (int i = 0; i < 3; i++) {
		int chkRow = 0;
		for (int j = 0; j < 3; j++) {
			if (arrs[i][j] == c) {
				chkRow++;
			}
			else if (arrs[i][j] == ' ') {
				chkEmp++;
			}
		}
		if (chkRow == 3) {
			if (c == 'o') {
				cout << "승리!!\n" << endl;
			}
			else {
				cout << "패배!!\n" << endl;
			}
			return true;
		}
	}
	if (chkEmp == 0) {
		cout << "비겼습니다." << endl;
		return true;
	}
	for (int i = 0; i < 3; i++) {
		int chkCol = 0;
		for (int j = 0; j < 3; j++) {
			if (arrs[j][i] == c) {
				chkCol++;
			}
		}
		if (chkCol == 3) {
			if (c == 'o') {
				cout << "승리!!\n" << endl;
			}
			else {
				cout << "패배!!\n" << endl;
			}
			return true;
		}
	}
	if ((arrs[0][0] == c && arrs[1][1] == c && arrs[2][2] == c) || (arrs[0][2] == c && arrs[1][1] == c && arrs[2][0] == c)) {
		if (c == 'o') {
			cout << "승리!!\n" << endl;
		}
		else {
			cout << "패배!!\n" << endl;
		}
		return true;
	}
	return false;
}

tuple<int, int> checkComTurn(char arrs[3][3]) {
	for (int i = 0; i < 3; i++) {
		int chkRowC = 0;
		for (int j = 0; j < 3; j++) {
			if (arrs[i][j] == 'x') {
				chkRowC++;
			}
		}
		if (chkRowC == 2) {
			for (int j = 0; j < 3; j++) {
				if (arrs[i][j] == ' ') {
					return make_tuple(i, j);
				}
			}
		}
	}
	for (int i = 0; i < 3; i++) {
		int chkColC = 0;
		for (int j = 0; j < 3; j++) {
			if (arrs[j][i] == 'x') {
				chkColC++;
			}
		}
		if (chkColC == 2) {
			for (int j = 0; j < 3; j++) {
				if (arrs[j][i] == ' ') {
					return make_tuple(j, i);
				}
			}
		}
	}
	int chkCroC = 0;
	for (int i = 0; i < 3; i++) {
		if (arrs[i][i] == 'x') {
			chkCroC++;
		}
	}
	if (chkCroC == 2) {
		for (int i = 0; i < 3; i++) {
			if (arrs[i][i] == ' ') {
				return make_tuple(i, i);
			}
		}
	}
	chkCroC = 0;
	for (int i = 0; i < 3; i++) {
		if (arrs[i][2 - i] == 'x') {
			chkCroC++;
		}
	}
	if (chkCroC == 2) {
		for (int i = 0; i < 3; i++) {
			if (arrs[i][2 - i] == ' ') {
				return make_tuple(i, 2 - i);
			}
		}
	}
	for (int i = 0; i < 3; i++) {
		int chkRowU = 0;
		for (int j = 0; j < 3; j++) {
			if (arrs[i][j] == 'o') {
				chkRowU++;
			}
		}
		if (chkRowU == 2) {
			for (int j = 0; j < 3; j++) {
				if (arrs[i][j] == ' ') {
					return make_tuple(i, j);
				}
			}
		}
	}
	for (int i = 0; i < 3; i++) {
		int chkColU = 0;
		for (int j = 0; j < 3; j++) {
			if (arrs[j][i] == 'o') {
				chkColU++;
			}
		}
		if (chkColU == 2) {
			for (int j = 0; j < 3; j++) {
				if (arrs[j][i] == ' ') {
					return make_tuple(j, i);
				}
			}
		}
	}
	int chkCroU = 0;
	for (int i = 0; i < 3; i++) {
		if (arrs[i][i] == 'o') {
			chkCroU++;
		}
	}
	if (chkCroU == 2) {
		for (int i = 0; i < 3; i++) {
			if (arrs[i][i] == ' ') {
				return make_tuple(i, i);
			}
		}
	}
	chkCroU = 0;
	for (int i = 0; i < 3; i++) {
		if (arrs[i][2 - i] == 'o') {
			chkCroU++;
		}
	}
	if (chkCroU == 2) {
		for (int i = 0; i < 3; i++) {
			if (arrs[i][2 - i] == ' ') {
				return make_tuple(i, 2 - i);
			}
		}
	}
	return make_tuple(-1, -1);
}

void printBoard(char arrs[3][3]) {
	printf("\n%c|%c|%c\n-----\n%c|%c|%c\n-----\n%c|%c|%c\n\n",
		arrs[0][0], arrs[0][1], arrs[0][2],
		arrs[1][0], arrs[1][1], arrs[1][2],
		arrs[2][0], arrs[2][1], arrs[2][2]);
}
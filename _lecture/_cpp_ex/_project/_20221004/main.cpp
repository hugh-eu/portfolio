#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cmath>
#include <ctime>
#include <chrono>
#include <vector>
#include <algorithm>

using namespace std;  // std ���̺귯�� ����Ͽ� cout, endl ���


auto add(int n1, int n2) {
	int result = n1 + n2;
	return result;
}

bool isPass(int n1, int n2, int n3) {
	if ((n1 + n2 + n3) / 3.0 >= 80) {
		return true;
	}
	else {
		return false;
	}

}


int main() {

	//std::cout << "Hello World\n" << "hi" << endl;  // consolout, using namespace ��� std::�Ͽ� ��ġ �����Ͽ� ��밡��

	//int num1 = 0;
	//cout << "num : " << num1 << endl;
	//num1 = 100;
	//cout << "num : " << num1 << endl;
	//int num2{ 200 };  // int num2 = 200;
	//cout << "num2 : " << num2 << endl;
	//int num3 = { 300 };  // int num3 = 300;
	//cout << "num3 : " << num3 << endl;
	//printf("num3 : %d\n", num3);

	//float f1 = 3.14;
	//cout << "f1 : " << f1 << endl;
	//double d1 = 3.141592;
	//cout << "d1 : " << d1 << endl;

	//char c1 = 'a';
	//cout << "c1 : " << c1 << endl;

	//string str1 = "Hello cpp";
	//cout << "str1 : " << str1 << endl;
	//string str2 = "Good morning";
	//string str3 = " ";
	//string str4 = "Hugh";

	//string str5 = str2 + str3 + str4;
	//cout << "str5 : " << str5 << endl;

	//bool flag1 = true;
	//cout << "flag1 : " << flag1 << endl;  // 1
	//flag1 = false;
	//cout << "flag1 : " << flag1 << endl;  // 0

	//string str6 = "hello";
	//string str7 = "hello";
	//bool result = str6 == str7;
	//cout << "result : " << result << endl;

	//string str8 = "man ";
	//string str9 = str8 + to_string(5) + "��";  // to_string str ��ȯ �Լ�
	//cout << "str9 : " << str9 << endl;

	//const double TAX_RATE = 0.25;  // ��� ����, ������� ���� �빮�ڷ�, ��ܿ� ���
	//int income = 10000;
	//income = income * (1 - TAX_RATE);
	//cout << "������ : " << income << endl;

	// ������ �̸� ���� ���� ������ �߻���� ������ ��� ���
	//string name;
	//int age, height, weight;

	//cout << "�̸� : ";
	//cin >> name;
	//cout << "���� : ";
	//cin >> age;
	//cout << "���� : ";
	//cin >> height;
	//cout << "������ : ";
	//cin >> weight;
	//cout << "�̸� : " << name << "\n���� : " << age << "\n���� : " << height << "\n������ : " << weight << endl;

	// bmi���� ���
	//int height, weight;
	//float bmi;
	//cout << "���� : ";
	//cin >> height;
	//cout << "������ : ";
	//cin >> weight;
	//bmi = weight / pow((height / 100.0), 2);
	//cout << "BMI : " << bmi << endl;

	//int num4 = 123;
	//cout << "num4 : " << num4 << endl;
	//auto num5 = 123;  // auto �ڷ��� �ڵ����� �Ǵ�
	//cout << "num5 : " << num5 << endl;
	//cout << "sizeof(num5) : " << sizeof(num5) << endl;
	//auto num6 = 123.0;
	//cout << "num6 : " << num6 << endl;
	//cout << "sizeof(num6) : " << sizeof(num6) << endl;

	//double d2 = 42.41243781248923;
	//cout << "d2 : " << d2 << endl;  // �Ҽ��� �߷�����
	//cout.precision(10);  // ������ ����
	//cout << "d2, precision : " << d2 << endl;
	//cout << fixed;  // �Ҽ��� �Ʒ� ��¹��� �����ϱ� ����
	//cout.precision(10);  // ������ ����
	//cout << "d2, fixed, precision : " << d2 << endl;

	// �Լ�
	//cout << "add(10, 20) : " << add(10, 20) << endl;
	//cout << "sizeof(add(10, 20)) : " << sizeof(add(10, 20)) << endl;

	// ���
	//int n1 = 10;
	//int n2 = 20;
	//cout << n1 << endl;
	//cout << n2 << endl;
	//string str1 = "Hello";
	//string str2 = "Hi";
	//cout << str1 << endl;
	//cout << str2 << endl;
	//printf("str1 : %s\n", str1.c_str());
	//printf("str2 : %s\n", str2.c_str());

	// �Է�
	//int n3 = 100;
	//cout << "n3 : " << n3 << endl;
	//cin >> n3;
	//cout << "n3 : " << n3 << endl;
	//cin.ignore();  // ���� ����

	//double d1;
	//cin >> d1;
	//cout << "d1 : " << d1 << endl;

	//string nameStr;
	//cout << "�̸� : ";
	//cin >> nameStr;
	//cout << "�̸� : " << nameStr << endl;

	// �̸�, ����, ����, ������, �߻����� �Է� ���
	//string name, mail;
	//float height, weight, sizef;
	//cout << "�̸� : ";
	//cin >> name;
	//cout << "���� : ";
	//cin >> mail;
	//cout << "���� : ";
	//cin >> height;
	//cout << "������ : ";
	//cin >> weight;
	//cout << "�߻����� : ";
	//cin >> sizef;
	//
	//cout << "\n�̸� : " << name << endl;
	//cout << "���� : " << mail << endl;
	//cout << fixed;
	//cout.precision(1);
	//cout << "���� : " << height << endl;
	//cout << "������ : " << weight << endl;
	//cout << "�߻����� : " << sizef << endl;

	//int n1 = 10, n2 = 20;
	//cout << "n1 + n2 = " << n1 + n2 << endl;
	//cout << "n1 - n2 = " << n1 - n2 << endl;
	//cout << "n1 * n2 = " << n1 * n2 << endl;
	//cout << "n1 / (float)n2 = " << n1 / (float)n2 << endl;
	//cout << "n1 % n2 = " << n1 % n2 << endl;

	//int n1 = 10;
	//n1++;
	//cout << "n1 : " << n1 << endl;
	//n1--; n1--;
	//cout << "n1 : " << n1 << endl;

	// 10000������ 1100 �� �Ŷ�� �, �ܵ�
	//cout << "�Ŷ�� " << 10000 / 1100 << "��, �ܵ� " << 10000 % 1100 << "��" << endl;
	//
	//// cm �� inch�� ��ȯ, 2.5
	//float inputCm;
	//cout << "cm : ";
	//cin >> inputCm;
	//cout << fixed;
	//cout.precision(2);
	//cout << inputCm << "cm�� " << inputCm / 2.5 << "inch" << endl;

	//// 2050���� �ڽ��� ����
	//int age;
	//cout << "���� ���� : ";
	//cin >> age;
	//cout << "2050���� ���� : " << age + (2050 - 2022) << endl;

	//// ���μ��� �Է� �ﰢ�� �簢�� ����
	//float width, length;
	//cout << "���� : ";
	//cin >> width;
	//cout << "���� : ";
	//cin >> length;
	//cout << fixed;
	//cout.precision(2);
	//cout << "�ﰢ���� ���� : " << width * length / 2 << "\n�簢���� ���� : " << width * length << endl;

	// ��, ��, �� ȯ��
	//int _hour, _min, _sec;
	//cout << "�ð� : ";
	//cin >> _hour;
	//cout << "�� : ";
	//cin >> _min;
	//cout << "�� : ";
	//cin >> _sec;
	//printf("%d�ð� %d�� %d�� : %d��", _hour, _min, _sec, _hour * 3600 + _min * 60 + _sec);

	//// ������ �Է�, ���� ���, �Ҽ�2�ڸ�
	//float korscr, engscr, mathscr;
	//cout << "�������� : ";
	//cin >> korscr;
	//cout << "�������� : ";
	//cin >> engscr;
	//cout << "�������� : ";
	//cin >> mathscr;
	//cout << fixed;
	//cout.precision(2);
	//cout << "���� : " << korscr + engscr + mathscr << " ��� : " << (korscr + engscr + mathscr) / 3 << endl;

	//// ���� �ý��� ��¥ �ð� ���
	//time_t t = time(NULL);
	//struct tm *ptm = localtime(&t);
	//char now[20];
	//strftime(now, 20, "%Y-%m-%d %H:%M:%S", ptm);
	//cout << "���� �ð� : " << now << endl;

	//int num1 = 100, num2 = 200;
	//cout << "num1 == num2 : " << (num1 == num2) << endl;
	//cout << "num1 != num2 : " << (num1 != num2) << endl;
	//cout << "num1 > num2 : " << (num1 > num2) << endl;
	//cout << "num1 < num2 : " << (num1 < num2) << endl;
	//cout << "num1 >= num2 : " << (num1 >= num2) << endl;
	//cout << "num1 <= num2 : " << (num1 <= num2) << endl;

	//cout << "true && false : " << (true && false) << endl;
	//cout << "true || false : " << (true && false) << endl;
	//cout << "!true : " << (!true) << endl;

	// �ֻ�������
	//srand(time(NULL));  // ���ο� �õ�
	//char _enter[5];
	//int com_rand_num = rand() % 6 + 1;
	//cout << "�ֻ����� �������� ����Ű�� ��������.";
	//cin.getline(_enter, 5);
	//srand(time(NULL));
	//int my_rand_num = rand() % 6 + 1;
	//if (com_rand_num < my_rand_num) {
	//	printf("��ǻ�� : %d  �� : %d, �̰���ϴ�!!", com_rand_num, my_rand_num);
	//} else if (com_rand_num > my_rand_num) {
	//	printf("��ǻ�� : %d  �� : %d, �����ϴ�!!", com_rand_num, my_rand_num);
	//} else {
	//	printf("��ǻ�� : %d  �� : %d, �����ϴ�!!", com_rand_num, my_rand_num);
	//}

	//int num1{ 100 }, num2{ 200 };
	//if (num1 > num2) {
	//	cout << "num1�� num2���� ũ��." << endl;
	//}
	//else if (num1 < num2) {
	//	cout << "num1�� num2���� �۴�." << endl;
	//}
	//else {
	//	cout << "num1�� num2�� ����." << endl;
	//}

	//int inputNum;
	//cin >> inputNum;
	//switch (inputNum) {
	//case 1:
	//	cout << "Hi" << endl;
	//	break;
	//case 2:
	//	cout << "Hello" << endl;
	//	break;
	//default:
	//	cout << "Bye" << endl;
	//	break;
	//}

	//bool result = isPass(60, 100, 90);

	//if (result) {
	//	cout << "�հ�" << endl;
	//}
	//else {
	//	cout << "���հ�" << endl;
	//}

	// ����з�, ���� �Է�, 100g ���� ��, 200���� ��, �׿� ��
	//double weightApple;
	//cout << "�������(g) : ";
	//cin >> weightApple;
	//if (weightApple > 200) {
	//	cout << "��" << endl;
	//}
	//else if (100 < weightApple && weightApple <= 200) {
	//	cout << "��" << endl;
	//}
	//else {
	//	cout << "��" << endl;
	//}

	// ���� 5�� �Է� ���� ū�� ������ ���
	//int inputNums[5];
	//for (int i = 0; i < 5; i++) {
	//	cout << i + 1 << "��° ���� �Է� : ";
	//	cin >> inputNums[i];
	//	cin.ignore();
	//}
	//cout << "�ִ밪 : " << *max_element(inputNums, inputNums + 5) << endl;
	//cout << "�ּҰ� : " << *min_element(inputNums, inputNums + 5) << endl;


	// ��ǻ�Ͱ� ���ĺ� �Է��ϸ� ����ڰ� ����, 10����ȸ �����Ͻ� ���ĺ� ��ġ �˷��ֱ�
	//string alphabet[] = { "A", "B", "C", "D", "E", "F", "G", "H", "I", "J",
	//			"K", "L", "M", "N", "O", "P", "Q", "R", "S", "T",
	//			"U", "V", "W", "X", "Y", "Z" };
	//srand(time(NULL));
	//int com_rand_num = rand() % 26;
	//string com_str = alphabet[com_rand_num], my_str;
	//int i = 0;
	//while (true) {
	//	i++;
	//	cout << "���ĺ� �ϳ��� �Է��ϼ��� : ";
	//	cin >> my_str;
	//	my_str[0] = toupper(my_str[0]);
	//	if (com_str == my_str) {
	//		cout << "�����Դϴ�." << endl;
	//		break;
	//	}
	//	else {
	//		cout << "Ʋ�Ƚ��ϴ�. ";
	//		if (i == 10) {
	//			cout << "��ȸ�� ��� ����Ͽ����ϴ�.\n������ " << com_str << "�Դϴ�." << endl;
	//			break;
	//		}
	//		else {
	//			if (com_str < my_str) {
	//				cout << "�Է��� �ͺ��� ������ ���ĺ��Դϴ�." << endl;
	//			}
	//			else {
	//				cout << "�Է��� �ͺ��� ������ ���ĺ��Դϴ�." << endl;

	//			}
	//		}
	//	}
	//}

	// ���� ���� �Է�, ������ >=90 a, 80 b, 70 c, 60 d, f
	//double testScore;
	//cout << "���� ���� : ";
	//cin >> testScore;
	//int chkGrade = (int)(testScore / 10);
	//switch (chkGrade) {
	//case 10:
	//	cout << "A+++++" << endl;
	//	break;
	//case 9:
	//	cout << "A" << endl;
	//	break;
	//case 8:
	//	cout << "B" << endl;
	//	break;
	//case 7:
	//	cout << "C" << endl;
	//	break;
	//case 6:
	//	cout << "D" << endl;
	//	break;
	//default:
	//	cout << "F" << endl;
	//	break;
	//}

	//for (int i = 0; i < 5; i++) {
	//	cout << i << endl;
	//}

	//for (int num : inputNums) {
	//	cout << num << endl;
	//}

	//int i = 0;
	//while (i < 5) {
	//	cout << i << endl;
	//	i++;
	//}

	//string word;
	//do {
	//	cout << "�ϰ������ : ";
	//	getline(cin, word);  // cin���δ� ���� �����ϱ⶧���� getline(�Է�, ����) ���
	//	cout << "word : " << word << endl;
	//} while (word != "end");

	// ����ڰ� ���ϴ� ������
	//int inputNum;
	//cout << "���ϴ� �� : ";
	//cin >> inputNum;
	//for (int i = 1; i < 10; i++) {
	//	cout << inputNum <<  " X " << i << " == " << inputNum * i << endl;
	//}

	// ������ ��ü
	//for (int i = 1; i < 10; i++) {
	//	for (int j = 2; j < 10; j++) {
	//		printf("%d X %d = %d\t", j, i, i * j);
	//	}
	//	cout << endl;
	//}


	// 1���� ����� �Է� ���������� ��, ��
	//unsigned long long inputNum, sum=0, mul=1;
	//cout << "���� �Է� : ";
	//cin >> inputNum;
	//for (int i = 1; i < inputNum + 1; i++) {
	//	sum += i;
	//	mul *= i;
	//}
	//cout << "�� : " << sum << ", �� : " << mul << endl;

	/*for (int i = 0; i < 10; i++) {
		if (i % 2 == 0) {
			continue;
		}
		cout << i << endl;
		if (i == 5) break;
	}*/

	// 1000, 3�ǹ�� ����
	//int cnt = 0;
	//for (int i = 1; i < 1001; i++) {
	//	if (i % 3 == 0) cnt++;
	//}
	//cout << "1000������ 3�� ��� ���� : " << cnt << endl;

	// 1 99 3 6 9
	//for (int i = 1; i < 100; i++) {
	//	string strI = to_string(i);
	//	cout << i << " : ";
	//	for (int j = 0; j < strI.length(); j++) {
	//		if (strI[j] == '3' or strI[j] == '6' or strI[j] == '9') {
	//			cout << "¦!";
	//		}
	//	}
	//	cout << endl;
	//}

	// �����Է� ���� ���� ����, �ݺ�
	//string inputStr;
	//int vowels, selectedNum, etc;
	//while (true) {
	//	cout << "1. ������ �ڸ��� ���� �Ǻ�  2. ���� ";
	//	cin >> selectedNum;
	//	if (selectedNum == 1) {
	//		cin.ignore();
	//		vowels = 0;
	//		etc = 0;
	//		cout << "������ �Է� : ";
	//		getline(cin, inputStr);
	//		for (int i = 0; i < inputStr.length(); i++) {
	//			if (inputStr[i] == ' ' or inputStr[i] == '\n') {
	//				etc++;
	//			}
	//			else if (inputStr[i] == 'a' or inputStr[i] == 'e' or inputStr[i] == 'i' or inputStr[i] == 'o' or inputStr[i] == 'u') {
	//				vowels++;
	//			}
	//		}
	//		cout << "���� : " << inputStr.length() - vowels - etc << "��, ���� : " << vowels << "��" << endl;
	//	}
	//	else {
	//		break;
	//	}
	//}


	// 1 100 ���� ���߰� ���� ����.
	//srand((unsigned int)time(NULL));
	//int randInt = (rand() % 100) + 1, inputInt;
	//int i = 0;
	//while (true) {
	//	i++;
	//	cout << "������ ���� ���߱� : ";
	//	cin >> inputInt;
	//	if (randInt == inputInt) {
	//		cout << "�����Դϴ�." << endl;
	//		break;
	//	}
	//	else {
	//		cout << "Ʋ�Ƚ��ϴ�." << endl;
	//		if (i == 10) {
	//			cout << "������ȸ �ʰ�, ������ " << randInt << "�Դϴ�." << endl;
	//			break;
	//		}
	//		else {
	//			if (randInt < inputInt) {
	//				cout << "�Է��� ������ ���� �� �Դϴ�." << endl;
	//			}
	//			else {
	//				cout << "�Է��� ������ ���� �� �Դϴ�." << endl;
	//			}
	//		}
	//	}
	//}

	// 1 1000 ���E�� �ڵ� ����
	//int inputNum, num1, num2, answer;
	//bool flag = true;
	//while (flag) {
	//	cout << "1. ��������  2. �E������  3. ���� ";
	//	cin >> inputNum;
	//	srand((unsigned int)time(NULL));
	//	num1 = (rand() % 1000) + 1, num2 = (rand() % 1000) + 1;
	//	switch (inputNum)
	//	{
	//	case 1:
	//		cout << num1 << " + " << num2 << " = ";
	//		cin >> answer;
	//		if (answer == num1 + num2) {
	//			cout << "�����Դϴ�." << endl;
	//		}
	//		else {
	//			cout << "�����Դϴ�.\n" << "���� : " << num1 + num2 << endl;
	//		}
	//		break;
	//	case 2:
	//		cout << num1 << " - " << num2 << " = ";
	//		cin >> answer;
	//		if (answer == num1 - num2) {
	//			cout << "�����Դϴ�." << endl;
	//		}
	//		else {
	//			cout << "�����Դϴ�.\n" << "���� : " << num1 - num2 << endl;
	//		}
	//		break;
	//	case 3:
	//		flag = false;
	//		break;
	//	}
	//}


	return 0;

}

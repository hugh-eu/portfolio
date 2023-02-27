#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <windows.h>
#define MAX_COUNT 5

//void GetMyData(int** q) {
//	*q = (int*)malloc(8);
//}

//typedef char NAME_TYPE[14];

//typedef struct {
//	char name[14];
//	unsigned short int age;
//	float height;
//	float weight;
//} Person;

//typedef struct People {
//	char name[14];
//	unsigned short int age;
//	float height;
//	float weight;
//} Person;


//int AddFriend(NAME_TYPE* p_name, unsigned short int* p_age, float* p_height, float* p_weight, int count) {
//	if (count < MAX_COUNT) {
//		printf("\n새로운 친구 정보를 입력하세요\n");
//		printf("1. 이름 : ");
//		scanf("%s", *(p_name + count));
//		printf("2. 나이 : ");
//		scanf("%hu", p_age + count);
//		printf("3. 키 : ");
//		scanf("%f", p_height + count);
//		printf("4. 몸무게 : ");
//		scanf("%f", p_weight + count);
//		printf("입력을 완료했습니다. \n\n");
//		return 1;
//	}
//	else {
//		printf("최대 인원을 초과하여 입력을 할 수 없습니다. \n");
//		printf("최대 %d명까지만 관리 가능합니다. \n\n", MAX_COUNT);
//	}
//	return 0;
//}

//int AddFriend(Person *p_friend, int count) {
//	if (count < MAX_COUNT) {
//		p_friend += count;
//		printf("\n새로운 친구 정보를 입력하세요\n");
//		printf("1. 이름 : ");
//		scanf("%s", p_friend->name);
//		printf("2. 나이 : ");
//		scanf("%hu", &p_friend->age);
//		printf("3. 키 : ");
//		scanf("%f", &p_friend->height);
//		printf("4. 몸무게 : ");
//		scanf("%f", &p_friend->weight);
//		printf("입력을 완료했습니다. \n\n");
//		return 1;
//	}
//	else {
//		printf("최대 인원을 초과하여 입력을 할 수 없습니다. \n");
//		printf("최대 %d명까지만 관리 가능합니다. \n\n", MAX_COUNT);
//	}
//	return 0;
//}

//void ShowFriendList(NAME_TYPE* p_name, unsigned short int* p_age, float* p_height, float* p_weight, int count) {
//	int i;
//	if (count > 0) {
//		printf("\n등록된 친구 목록\n");
//		printf("===========================================================\n");
//		for (i = 0; i < count; i++) {
//			printf("%-14s, %3d, %6.2f, %6.2f\n", *(p_name + i), *(p_age + i), *(p_height + i), *(p_weight + i));
//		}
//		printf("===========================================================\n\n");
//	}
//	else {
//		printf("\n등록된 친구가 없습니다. ㅠㅠ\n\n");
//	}
//}

//void ShowFriendList(Person *p_friend, int count) {
//	int i;
//	if (count > 0) {
//		printf("\n등록된 친구 목록\n");
//		printf("===========================================================\n");
//		for (i = 0; i < count; i++) {
//			printf("%-14s, %3d, %6.2f, %6.2f\n", p_friend->name, p_friend->age, p_friend->height, p_friend->weight);
//			p_friend++;
//		}
//		printf("===========================================================\n\n");
//	}
//	else {
//		printf("\n등록된 친구가 없습니다. ㅠㅠ\n\n");
//	}
//}



void main() {

	//getmydata
	/*int *p;
	GetMyData(&p);
	*p = 5;
	free(p);*/

	/*short** pp;
	int n;
	scanf("%d", &n);
	pp = (short**)malloc(sizeof(short*) * n);*/

	/*unsigned char** pp;
	int n;
	pp = (unsigned char**)malloc(sizeof(unsigned char*) * 3);
	for (int i = 0; i < 3; i++) {
		printf("%d0대 인원수 : ", i + 2);
		scanf("%d", &n);
		*(pp + i) = (unsigned char*)malloc(sizeof(unsigned char) * n);
	}*/

	/*unsigned char *p_limit_table;
	unsigned char **p;
	int age, age_step, member, temp, sum;
	printf("20대부터 시작해서 연령층이 몇 개인가요 : ");
	scanf("%d", &age_step);
	p_limit_table = (unsigned char*)malloc(age_step);
	p = (unsigned char**)malloc(sizeof(unsigned char*) * age_step);
	for (age = 0; age < age_step; age++) {
		printf("\n%d0대 연령의 윗몸 일으키기 횟수\n", age + 2);
		printf("이 연령대는 몇 명입니까? : ");
		scanf("%d", &temp);
		*(p_limit_table + age) = (unsigned char)temp;
		*(p + age) = (unsigned char*)malloc(*(p_limit_table + age));
		for (member = 0; member < *(p_limit_table + age); member++){
			printf("%dth : ", member + 1);
			scanf("%d", &temp);
			*(*(p + age) + member) = (unsigned char)temp;
		}
	}
	printf("\n\n연령별 평균 윗몸 일으키기 횟수\n");
	for (age = 0; age < age_step; age++) {
		sum = 0;
		printf("%d대 : ", age + 2);
		for (member = 0; member < *(p_limit_table + age); member++) {
			sum += *(*(p + age) + member);
		}
		printf("%5.2f\n", (double)sum / *(p_limit_table + age));
		free(*(p + age));
	}
	free(p);
	free(p_limit_table);*/

	//typedef unsigned short int US;  // typedef, 자료형 단순하게 재정의, unsigned short int 를 US로 새로 정의
	//US temp;  // unsigned short int temp;
	//typedef int MY_DATA[5];
	//MY_DATA *p; // int (*p)[5];

	// 구조체, struct
	//struct People {  // 22바이트
	//	char name[12];
	//	unsigned short int age;
	//	float height;
	//	float weight;
	//};
	////struct People data;  // 22
	////struct People friend_list[64];  // 22x64
	////struct People *p;  // 4
	//typedef struct People Person;
	//Person data;
	//Person friend_list[64];
	//Person *p;
	/*typedef struct {
		char name[12];
		unsigned short int age;
		float height;
		float weight;
	} Person;*/  // 구조체 메인밖으로

	// struct
	//Person data = {"홍길동", 51, 185.6, 86.2};  // 바로 초기화 가능
	/*data.age = 21;
	data.height = 178.3;
	scanf("%s", &data.name);*/
	/*printf("%s", data.name);*/
	//Person* p;
	//p = &data;
	//(*p).age = 23;
	//p->age = 23;  // 화살표연산자

	//NAME_TYPE name[MAX_COUNT];
	//unsigned short int age[MAX_COUNT];
	//float height[MAX_COUNT];
	//float weight[MAX_COUNT];
	//int count = 0, num;
	//while (1) {
	//	printf("     [ 메 뉴 ]\n");
	//	printf("===================\n");
	//	printf("1. 친구 추가\n");
	//	printf("2. 친구 목록 보기\n");
	//	printf("3. 종료\n");
	//	printf("===================\n");
	//	printf("번호 선택 : ");
	//	scanf("%d", &num);

	//	if (num == 1) {
	//		if (1 == AddFriend(name, age, height, weight, count)) count++;
	//	}
	//	else if (num == 2) {
	//		ShowFriendList(name, age, height, weight, count);
	//	}
	//	else if (num == 3) {
	//		break;
	//	}
	//	else {
	//		printf("1~3 번호만 선택할 수 있습니다!!\n\n");
	//	}
	//}

	/*Person friends[MAX_COUNT];
	int count = 0, num;

	while (1) {
		printf("     [ 메 뉴 ]\n");
		printf("===================\n");
		printf("1. 친구 추가\n");
		printf("2. 친구 목록 보기\n");
		printf("3. 종료\n");
		printf("===================\n");
		printf("번호 선택 : ");
		scanf("%d", &num);

		if (num == 1) {
			if (1 == AddFriend(friends, count)) count++;
		}
		else if (num == 2) {
			ShowFriendList(friends, count);
		}
		else if (num == 3) {
			break;
		}
		else {
			printf("1~3 번호만 선택할 수 있습니다!!\n\n");
		}
	}*/
	

}
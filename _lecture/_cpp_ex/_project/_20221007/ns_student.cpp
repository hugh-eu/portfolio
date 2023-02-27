#include "ns_student.h"

using namespace student;

void StudentView::doView() {

	int  s_no, s_age, s_grade;
	string s_name, s_major, selectedNum;
	bool flag = true, chk_no;
	while (flag) {
		cout << "1. ���  2. ��ȸ  3. ����  4. ����  0. ���� ";
		cin >> selectedNum;
		while (selectedNum != "1" && selectedNum != "2" && selectedNum != "3" && selectedNum != "4" && selectedNum != "0") {
			cout << "!! ���ϴ� ����� ��Ȯ�� ���ڷ� �Է��ϼ���." << endl;
			cout << "1. ���  2. ��ȸ  3. ����  4. ����  0. ���� ";
			cin >> selectedNum;
		}
		if (selectedNum == "1") {
			StudentVo studentVo;
			cout << "\n  �̸� : ";
			cin >> s_name;
			cout << "  ���� : ";
			cin >> s_age;
			cout << "  �г� : ";
			cin >> s_grade;
			cout << "  ���� : ";
			cin >> s_major;
			cout << endl;
			studentVo.setS_name(s_name);
			studentVo.setS_age(s_age);
			studentVo.setS_grade(s_grade);
			studentVo.setS_major(s_major);
			studentController.insertStudentInfo(studentVo);
		}
		else if (selectedNum == "2") {
			cout << "  1) Ư���л� ���� ��ȸ  2) ��ü�л� ���� ��ȸ ";
			cin >> selectedNum;
			while (selectedNum != "1" && selectedNum != "2") {
				cout << "  !! ���ϴ� ����� ��Ȯ�� ���ڷ� �Է��ϼ���." << endl;
				cout << "  1) Ư���л� ���� ��ȸ  2) ��ü�л� ���� ��ȸ ";
				cin >> selectedNum;
			}
			if (selectedNum == "1") {
				cout << "\n    ��ȸ�� �л� �̸� : ";
				cin >> s_name;
				vector<StudentVo>studentVos = studentController.searchStudentInfo(s_name);
				if (0 < studentVos.size()) {
					for (auto iter = studentVos.begin(); iter != studentVos.end(); iter++) {
						cout << "\n �� s_no : " << iter->getS_no() << endl;
						cout << "    s_name : " << iter->getS_name() << endl;
						cout << "    s_age : " << iter->getS_age() << endl;
						cout << "    s_grade : " << iter->getS_grade() << endl;
						cout << "    s_major : " << iter->getS_major() << " ��\n" << endl;
					}
				}
				else {
					cout << "    !! �ش��ϴ� �л��� �����ϴ�.\n" << endl;
				}
			}
			else if (selectedNum == "2") {
				vector<StudentVo> studentVos = studentController.searchStudentsInfo();
				for (auto iter = studentVos.begin(); iter != studentVos.end(); iter++) {
					cout << "\n �� s_no : " << iter->getS_no() << endl;
					cout << "    s_name : " << iter->getS_name() << endl;
					cout << "    s_age : " << iter->getS_age() << endl;
					cout << "    s_grade : " << iter->getS_grade() << endl;
					cout << "    s_major : " << iter->getS_major() << " ��\n" << endl;
				}
			}

		}
		else if (selectedNum == "3") {
			cout << "  1) Ư���л� ���� ����  2) ��ü�л� �г�, ���� ���� ";
			cin >> selectedNum;
			while (selectedNum != "1" && selectedNum != "2") {
				cout << "  !! ���ϴ� ����� ��Ȯ�� ���ڷ� �Է��ϼ���." << endl;
				cout << "  1) Ư���л� ���� ����  2) ��ü�л� �г�, ���� ���� ";
				cin >> selectedNum;
			}
			if (selectedNum == "1") {
				cout << "\n    ������ �л� �̸� : ";
				cin >> s_name;
				vector<StudentVo> studentVos = studentController.searchStudentsInfoForModify(s_name);
				if (0 < studentVos.size()) {
					for (auto iter = studentVos.begin(); iter != studentVos.end(); iter++) {
						cout << "\n �� s_no : " << iter->getS_no() << endl;
						cout << "    s_name : " << iter->getS_name() << endl;
						cout << "    s_age : " << iter->getS_age() << endl;
						cout << "    s_grade : " << iter->getS_grade() << endl;
						cout << "    s_major : " << iter->getS_major() << " ��\n" << endl;
					}
					StudentVo studentVo;
					chk_no = true;
					while (chk_no) {
						cout << "    ������ �л� �й� : ";
						cin >> s_no;
						for (auto iter = studentVos.begin(); iter != studentVos.end(); iter++) {
							if (s_no == iter->getS_no()) {
								chk_no = false;
								break;
							}
						}
						if (chk_no == true) {
							cout << "    !! �й� ��ü�� ��Ȯ�ϰ� �Է��ϼ���." << endl;
						}
					}
					studentVo.setS_no(s_no);
					cout << "    ���� ���� : ";
					cin >> s_age;
					studentVo.setS_age(s_age);
					cout << "    �г� ���� : ";
					cin >> s_grade;
					studentVo.setS_grade(s_grade);
					cout << "    ���� ���� : ";
					cin >> s_major;
					studentVo.setS_major(s_major);
					cout << endl;
					studentController.modifyStudentInfo(studentVo);
				}
				else {
					cout << "    !! �ش��ϴ� �л��� �����ϴ�.\n" << endl;
				}
			}
			else if (selectedNum == "2") {
				studentController.modifyStudentsInfo();
			}

		}
		else if (selectedNum == "4") {
			cout << "  1) Ư���л� ���� ����  2) ��ü�л� ���� ���� ";
			cin >> selectedNum;
			while (selectedNum != "1" && selectedNum != "2") {
				cout << "  !! ���ϴ� ����� ��Ȯ�� ���ڷ� �Է��ϼ���." << endl;
				cout << "  1) Ư���л� ���� ����  2) ��ü�л� ���� ���� ";
				cin >> selectedNum;
			}
			if (selectedNum == "1") {
				cout << "\n    �̸� : ";
				cin >> s_name;
				vector<StudentVo> studentVos = studentController.searchStudentsInfoForDelete(s_name);
				if (0 < studentVos.size()) {
					for (auto iter = studentVos.begin(); iter != studentVos.end(); iter++) {
						cout << "\n �� s_no : " << iter->getS_no() << endl;
						cout << "    s_name : " << iter->getS_name() << endl;
						cout << "    s_age : " << iter->getS_age() << endl;
						cout << "    s_grade : " << iter->getS_grade() << endl;
						cout << "    s_major : " << iter->getS_major() << " ��\n" << endl;
					}
					chk_no = true;
					while (chk_no) {
						cout << "    ������ �л� �й� : ";
						cin >> s_no;
						for (auto iter = studentVos.begin(); iter != studentVos.end(); iter++) {
							if (s_no == iter->getS_no()) {
								chk_no = false;
								break;
							}
						}
						if (chk_no == true) {
							cout << "    !! �й� ��ü�� ��Ȯ�ϰ� �Է��ϼ���." << endl;
						}
					}
					cout << endl;
					studentController.deleteStudentInfo(s_no);
				}
				else {
					cout << "    !! �ش��ϴ� �л��� �����ϴ�.\n" << endl;
				}
			}
			else if (selectedNum == "2") {
				studentController.deleteStudentsInfo();
			}
		}
		else if (selectedNum == "0") {
			flag = false;
		}
	}

}

void StudentController::insertStudentInfo(StudentVo studentVo) {

	studentService.insertStudentInfo(studentVo);

}

vector<StudentVo> StudentController::searchStudentInfo(string s_name) {

	return studentService.searchStudentInfo(s_name);

}

vector<StudentVo> StudentController::searchStudentsInfo() {

	return studentService.searchStudentsInfo();

}

vector<StudentVo> StudentController::searchStudentsInfoForModify(string s_name) {

	return studentService.searchStudentsInfoForModify(s_name);

}

void StudentController::modifyStudentInfo(StudentVo studentVo) {

	studentService.modifyStudentInfo(studentVo);

}

void StudentController::modifyStudentsInfo() {

	studentService.modifyStudentsInfo();

}

vector<StudentVo> StudentController::searchStudentsInfoForDelete(string s_name) {

	return studentService.searchStudentsInfoForDelete(s_name);

}

void StudentController::deleteStudentInfo(int s_no) {

	studentService.deleteStudentInfo(s_no);

}

void StudentController::deleteStudentsInfo() {

	studentService.deleteStudentsInfo();

}

void StudentService::insertStudentInfo(StudentVo studentVo) {

	studentDao.insertStudentInfo(studentVo);

}

vector<StudentVo> StudentService::searchStudentInfo(string s_name) {

	return studentDao.searchStudentInfo(s_name);

}

vector<StudentVo> StudentService::searchStudentsInfo() {

	return studentDao.searchStudentsInfo();

}

vector<StudentVo> StudentService::searchStudentsInfoForModify(string s_name) {

	return studentDao.searchStudentsInfoForModify(s_name);

}

void StudentService::modifyStudentInfo(StudentVo studentVo) {

	studentDao.modifyStudentInfo(studentVo);

}

void StudentService::modifyStudentsInfo() {

	studentDao.modifyStudentsInfo();

}

vector<StudentVo> StudentService::searchStudentsInfoForDelete(string s_name) {

	return studentDao.searchStudentsInfoForDelete(s_name);

}

void StudentService::deleteStudentInfo(int s_no) {

	studentDao.deleteStudentInfo(s_no);

}

void StudentService::deleteStudentsInfo() {

	studentDao.deleteStudentsInfo();

}

void StudentDao::insertStudentInfo(StudentVo studentVo) {

	MYSQL* connection = nullptr;  // handler
	MYSQL mysql;  // mysql ����ü

	// mysql ����ü �ʱ�ȭ, �ʼ�
	MYSQL* ms = mysql_init(&mysql);

	// DB����
	connection = mysql_real_connect(&mysql, host, user, pw, db, 3306, (const char*)NULL, 0);
	// connection, ms�� mysql ����ü�� ����Ű�� ������
	if (connection == NULL) {
		printf("db connection fail.\n");
		printf("%d ERROR : %s\n", mysql_errno(&mysql), mysql_error(&mysql));  // ���� ��ȣ, ����
	}
	mysql_query(connection, "set NAMES euckr");  // �ѱ�
	char sql[1000];
	sprintf(sql, "INSERT INTO tbl_students (s_name, s_age, s_grade, s_major) VALUES ('%s', %d, %d, '%s')", studentVo.getS_name().c_str(), studentVo.getS_age(), studentVo.getS_grade(), studentVo.getS_major().c_str());
	mysql_query(connection, sql);
	mysql_close(connection);

}

vector<StudentVo> StudentDao::searchStudentInfo(string s_name) {

	MYSQL* connection = nullptr;  // �ڵ鷯
	MYSQL mysql;  // mysql ����ü
	MYSQL_RES* sql_rs;  // result set
	MYSQL_ROW sql_row;  // �� �ϳ�
	MYSQL* ms = mysql_init(&mysql);  // sql ����ü �ʱ�ȭ
	connection = mysql_real_connect(&mysql, host, user, pw, db, 3306, (const char*)NULL, 0);  // db����
	if (connection == NULL) {
		printf("db connection fail.\n");
		printf("%d ERROR : %s\n", mysql_errno(&mysql), mysql_error(&mysql));  // ���� ��ȣ, ����
	}
	mysql_query(connection, "set NAMES euckr");  // �ѱ�
	char sql[1000];
	sprintf(sql, "SELECT * FROM tbl_students WHERE s_name = '%s'", s_name.c_str());
	mysql_query(connection, sql);
	sql_rs = mysql_store_result(connection);
	vector<StudentVo> studentVos;
	while ((sql_row = mysql_fetch_row(sql_rs)) != nullptr) {
		StudentVo studentVo;
		studentVo.setS_no(atoi(sql_row[0]));
		studentVo.setS_name(sql_row[1]);
		studentVo.setS_age(atoi(sql_row[2]));
		studentVo.setS_grade(atoi(sql_row[3]));
		studentVo.setS_major(sql_row[4]);
		studentVos.push_back(studentVo);
	}
	mysql_free_result(sql_rs);
	mysql_close(connection);

	return studentVos;

}

vector<StudentVo> StudentDao::searchStudentsInfo() {

	MYSQL* connection = nullptr;  // �ڵ鷯
	MYSQL mysql;  // mysql ����ü
	MYSQL_RES* sql_rs;  // result set
	MYSQL_ROW sql_row;  // �� �ϳ�
	MYSQL* ms = mysql_init(&mysql);  // sql ����ü �ʱ�ȭ
	connection = mysql_real_connect(&mysql, host, user, pw, db, 3306, (const char*)NULL, 0);  // db����
	if (connection == NULL) {
		printf("db connection fail.\n");
		printf("%d ERROR : %s\n", mysql_errno(&mysql), mysql_error(&mysql));  // ���� ��ȣ, ����
	}
	mysql_query(connection, "set NAMES euckr");  // �ѱ�
	char sql[1000];
	sprintf(sql, "SELECT * FROM tbl_students");
	mysql_query(connection, sql);
	sql_rs = mysql_store_result(connection);
	vector<StudentVo> studentVos;
	while ((sql_row = mysql_fetch_row(sql_rs)) != nullptr) {
		StudentVo studentVo;
		studentVo.setS_no(atoi(sql_row[0]));
		studentVo.setS_name(sql_row[1]);
		studentVo.setS_age(atoi(sql_row[2]));
		studentVo.setS_grade(atoi(sql_row[3]));
		studentVo.setS_major(sql_row[4]);
		studentVos.push_back(studentVo);
	}
	mysql_free_result(sql_rs);
	mysql_close(connection);

	return studentVos;

}

vector<StudentVo> StudentDao::searchStudentsInfoForModify(string s_name) {

	MYSQL* connection = nullptr;  // �ڵ鷯
	MYSQL mysql;  // mysql ����ü
	MYSQL_RES* sql_rs;  // result set
	MYSQL_ROW sql_row;  // �� �ϳ�
	MYSQL* ms = mysql_init(&mysql);  // sql ����ü �ʱ�ȭ
	connection = mysql_real_connect(&mysql, host, user, pw, db, 3306, (const char*)NULL, 0);  // db����
	if (connection == NULL) {
		printf("db connection fail.\n");
		printf("%d ERROR : %s\n", mysql_errno(&mysql), mysql_error(&mysql));  // ���� ��ȣ, ����
	}
	mysql_query(connection, "set NAMES euckr");  // �ѱ�
	char sql[1000];
	sprintf(sql, "SELECT * FROM tbl_students WHERE s_name = '%s'", s_name.c_str());
	mysql_query(connection, sql);
	sql_rs = mysql_store_result(connection);
	vector<StudentVo> studentVos;
	while ((sql_row = mysql_fetch_row(sql_rs)) != nullptr) {
		StudentVo studentVo;
		studentVo.setS_no(atoi(sql_row[0]));
		studentVo.setS_name(sql_row[1]);
		studentVo.setS_age(atoi(sql_row[2]));
		studentVo.setS_grade(atoi(sql_row[3]));
		studentVo.setS_major(sql_row[4]);
		studentVos.push_back(studentVo);
	}
	mysql_free_result(sql_rs);
	mysql_close(connection);

	return studentVos;

}

void StudentDao::modifyStudentInfo(StudentVo studentVo) {

	MYSQL* connection = nullptr;  // �ڵ鷯
	MYSQL mysql;  // mysql ����ü
	MYSQL* ms = mysql_init(&mysql);  // sql ����ü �ʱ�ȭ
	connection = mysql_real_connect(&mysql, host, user, pw, db, 3306, (const char*)NULL, 0);  // db����
	if (connection == NULL) {
		printf("db connection fail.\n");
		printf("%d ERROR : %s\n", mysql_errno(&mysql), mysql_error(&mysql));  // ���� ��ȣ, ����
	}
	mysql_query(connection, "set NAMES euckr");  // �ѱ�
	char sql[1000];
	sprintf(sql, "UPDATE tbl_students SET s_age = %d, s_grade = %d, s_major = '%s' WHERE s_no = %d", studentVo.getS_age(), studentVo.getS_grade(), studentVo.getS_major().c_str(), studentVo.getS_no());
	mysql_query(connection, sql);
	mysql_close(connection);

}

void StudentDao::modifyStudentsInfo() {

	MYSQL* connection = nullptr;  // �ڵ鷯
	MYSQL mysql;  // mysql ����ü
	MYSQL_RES* sql_rs;  // result set
	MYSQL_ROW sql_row;  // �� �ϳ�
	MYSQL* ms = mysql_init(&mysql);  // sql ����ü �ʱ�ȭ
	connection = mysql_real_connect(&mysql, host, user, pw, db, 3306, (const char*)NULL, 0);  // db����
	if (connection == NULL) {
		printf("db connection fail.\n");
		printf("%d ERROR : %s\n", mysql_errno(&mysql), mysql_error(&mysql));  // ���� ��ȣ, ����
	}
	mysql_query(connection, "set NAMES euckr");  // �ѱ�
	char sql[1000];
	sprintf(sql, "SELECT * FROM tbl_students");
	mysql_query(connection, sql);
	sql_rs = mysql_store_result(connection);
	while ((sql_row = mysql_fetch_row(sql_rs)) != nullptr) {
		sprintf(sql, "UPDATE tbl_students SET s_age = %d, s_grade = %d WHERE s_no = %d", atoi(sql_row[2]) + 1, atoi(sql_row[3]) + 1, atoi(sql_row[0]));
		mysql_query(connection, sql);
	}
	mysql_free_result(sql_rs);
	mysql_close(connection);

}

vector<StudentVo> StudentDao::searchStudentsInfoForDelete(string s_name) {

	MYSQL* connection = nullptr;  // �ڵ鷯
	MYSQL mysql;  // mysql ����ü
	MYSQL_RES* sql_rs;  // result set
	MYSQL_ROW sql_row;  // �� �ϳ�
	MYSQL* ms = mysql_init(&mysql);  // sql ����ü �ʱ�ȭ
	connection = mysql_real_connect(&mysql, host, user, pw, db, 3306, (const char*)NULL, 0);  // db����
	if (connection == NULL) {
		printf("db connection fail.\n");
		printf("%d ERROR : %s\n", mysql_errno(&mysql), mysql_error(&mysql));  // ���� ��ȣ, ����
	}
	mysql_query(connection, "set NAMES euckr");  // �ѱ�
	char sql[1000];
	sprintf(sql, "SELECT * FROM tbl_students WHERE s_name = '%s'", s_name.c_str());
	mysql_query(connection, sql);
	sql_rs = mysql_store_result(connection);
	vector<StudentVo> studentVos;
	while ((sql_row = mysql_fetch_row(sql_rs)) != nullptr) {
		StudentVo studentVo;
		studentVo.setS_no(atoi(sql_row[0]));
		studentVo.setS_name(sql_row[1]);
		studentVo.setS_age(atoi(sql_row[2]));
		studentVo.setS_grade(atoi(sql_row[3]));
		studentVo.setS_major(sql_row[4]);
		studentVos.push_back(studentVo);
	}
	mysql_free_result(sql_rs);
	mysql_close(connection);

	return studentVos;

}

void StudentDao::deleteStudentInfo(int s_no) {

	MYSQL* connection = nullptr;  // �ڵ鷯
	MYSQL mysql;  // mysql ����ü
	MYSQL* ms = mysql_init(&mysql);  // sql ����ü �ʱ�ȭ
	connection = mysql_real_connect(&mysql, host, user, pw, db, 3306, (const char*)NULL, 0);  // db����
	if (connection == NULL) {
		printf("db connection fail.\n");
		printf("%d ERROR : %s\n", mysql_errno(&mysql), mysql_error(&mysql));  // ���� ��ȣ, ����
	}
	mysql_query(connection, "set NAMES euckr");  // �ѱ�
	char sql[1000];
	sprintf(sql, "DELETE FROM tbl_students WHERE s_no = %d", s_no);
	mysql_query(connection, sql);
	mysql_close(connection);

}

void StudentDao::deleteStudentsInfo() {

	MYSQL* connection = nullptr;  // �ڵ鷯
	MYSQL mysql;  // mysql ����ü
	MYSQL* ms = mysql_init(&mysql);  // sql ����ü �ʱ�ȭ
	connection = mysql_real_connect(&mysql, host, user, pw, db, 3306, (const char*)NULL, 0);  // db����
	if (connection == NULL) {
		printf("db connection fail.\n");
		printf("%d ERROR : %s\n", mysql_errno(&mysql), mysql_error(&mysql));  // ���� ��ȣ, ����
	}
	mysql_query(connection, "set NAMES euckr");  // �ѱ�
	char sql[1000];
	sprintf(sql, "DELETE FROM tbl_students");
	mysql_query(connection, sql);
	mysql_close(connection);

}

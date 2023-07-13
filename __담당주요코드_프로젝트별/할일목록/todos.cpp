#include "todos.h"

using namespace todos;


void TodosView::doView() {
	int m_no, t_no, result;
	string selNum, m_id, m_pw, temp_pw, txt, garbage;
	vector<TodosVo> todosVos;
	while (true) {
		system("cls");
		cout << "  「To Do List」" << endl;
		cout << "1. 로그인  2. 회원가입  0. 종료  ";
		cin >> selNum;
		cout << endl;
		if (selNum == "1") {
			cout << "    ID : ";
			cin >> m_id;
			cout << "    PW : ";
			cin >> m_pw;
			cout << endl;
			TodosVo todosVo;
			todosVo.setM_id(m_id);
			todosVo.setM_pw(m_pw);
			todosVos = todosController.checkIdPw(todosVo);
			if (todosVos.size() == 0) {
				cout << "    !! 입력하신 아이디, 비밀번호와 일치하는 가입내역이 없습니다." << endl;
				cout << endl;
				cout << "Press enter to continue.  ";
				cin.ignore();
				getline(cin, garbage);
				cout << endl;
			}
			else {
				m_no = todosVos.begin()->getM_no();
				while (true) {
					system("cls");
					todosVos = todosController.getTodos(m_no);
					cout << "  「To Do List」  - " << m_id << "님" << endl;
					if (todosVos.size() == 0) {
						cout << "내역 없음." << endl;
						cout << endl;
					}
					else {
						for (int i = 0; i < todosVos.size(); i++) {
							printf("[%s] #%02d %s\n", todosVos[i].getT_clear().c_str(), i + 1, todosVos[i].getT_txt().c_str());
						}
						cout << endl;
					}
					cout << "1. 리스트 추가  2. 완료한 일 체크  3. 완료 내역 삭제  4. 삭제 내역 보기  0. 로그아웃  ";
					cin >> selNum;
					cout << endl;
					if (selNum == "1") {
						cout << "    내용 : ";
						cin.ignore();
						getline(cin, txt);
						cout << endl;
						TodosVo todosVo;
						todosVo.setT_txt(txt);
						todosVo.setT_clear("_");
						todosVo.setM_no(m_no);
						todosController.addTodos(todosVo);
					}
					else if (selNum == "2") {
						if (todosVos.size() > 0) {
							cout << "    번호 : ";
							cin >> selNum;
							cout << endl;
							t_no = todosVos[stoi(selNum) - 1].getT_no();
							todosController.checkList(t_no);
						}
					}
					else if (selNum == "3") {
						todosController.delClearList();
					}
					else if (selNum == "4") {
						todosVos = todosController.getDelList(m_no);
						if (todosVos.size() == 0) {
							cout << "삭제 내역 없음." << endl;
							cout << endl;
						}
						else {
							for (int i = 0; i < todosVos.size(); i++) {
								printf("%s, %s에 완료함.\n", todosVos[i].getT_txt().c_str(), todosVos[i].getT_clear_date().c_str());
							}
							cout << endl;
						}
						cout << "Press enter to continue.  ";
						cin.ignore();
						getline(cin, garbage);
						cout << endl;
					}
					else if (selNum == "0") {
						break;
					}
				}
			}
		}
		else if (selNum == "2") {
			cout << "    ID : ";
			cin >> m_id;
			result = todosController.checkId(m_id);
			while (result > 0) {
				cout << "    !! 중복되는 ID가 있습니다." << endl;
				cout << endl;
				cout << "    ID : ";
				cin >> m_id;
				result = todosController.checkId(m_id);
			}
			cout << "    PW : ";
			cin >> m_pw;
			cout << "    비밀번호 확인" << endl;
			cout << "    PW : ";
			cin >> temp_pw;
			while (m_pw != temp_pw) {
				cout << "    !! 비밀번호가 일치하지 않습니다." << endl;
				cout << endl;
				cout << "    PW : ";
				cin >> m_pw;
				cout << "    비밀번호 확인" << endl;
				cout << "    PW : ";
				cin >> temp_pw;
			}
			cout << endl;
			TodosVo todosVo;
			todosVo.setM_id(m_id);
			todosVo.setM_pw(m_pw);
			todosController.insertMember(todosVo);
		}
		else if (selNum == "0") {
			break;
		}
	}
}

int TodosController::checkId(string m_id) {
	return todosService.checkId(m_id);
}

void TodosController::insertMember(TodosVo todosVo) {
	todosService.insertMember(todosVo);
}

vector<TodosVo> TodosController::checkIdPw(TodosVo todosVo) {
	return todosService.checkIdPw(todosVo);
}

vector<TodosVo> TodosController::getTodos(int m_no) {
	return todosService.getTodos(m_no);
}

void TodosController::addTodos(TodosVo todosVo) {
	todosService.addTodos(todosVo);
}

void TodosController::checkList(int t_no) {
	todosService.checkList(t_no);
}

void TodosController::delClearList() {
	todosService.delClearList();
}

vector<TodosVo> TodosController::getDelList(int m_no) {
	return todosService.getDelList(m_no);
}

int TodosService::checkId(string m_id) {
	return todosDao.checkId(m_id);
}

void TodosService::insertMember(TodosVo todosVo) {
	todosDao.insertMember(todosVo);
}

vector<TodosVo> TodosService::checkIdPw(TodosVo todosVo) {
	return todosDao.checkIdPw(todosVo);
}

vector<TodosVo> TodosService::getTodos(int m_no) {
	return todosDao.getTodos(m_no);
}

void TodosService::addTodos(TodosVo todosVo) {
	todosDao.addTodos(todosVo);
}

void TodosService::checkList(int t_no) {
	todosDao.checkList(t_no);
}

void TodosService::delClearList() {
	todosDao.delClearList();
}

vector<TodosVo>  TodosService::getDelList(int m_no) {
	return todosDao.getDelList(m_no);
}

int TodosDao::checkId(string m_id) {

	MYSQL mysql;
	MYSQL* connection = nullptr;
	MYSQL_RES* sql_rs;
	MYSQL* ms = mysql_init(&mysql);
	connection = mysql_real_connect(&mysql, host, user, pw, db, 3306, (const char*)NULL, 0);
	if (connection == NULL) {
		printf("db connection fail.\n");
		printf("%d ERROR : %s\n", mysql_errno(&mysql), mysql_error(&mysql));
	}
	mysql_query(connection, "set NAMES euckr");
	char sql[1000];
	sprintf(sql, "SELECT * FROM tbl_members WHERE m_id = '%s'", m_id.c_str());
	mysql_query(connection, sql);
	sql_rs = mysql_store_result(connection);
	if (mysql_fetch_row(sql_rs) == nullptr) {
		mysql_free_result(sql_rs);
		mysql_close(connection);

		return 0;
	}
	else {
		mysql_free_result(sql_rs);
		mysql_close(connection);

		return 1;
	}

}

void TodosDao::insertMember(TodosVo todosVo) {

	MYSQL mysql;
	MYSQL* connection = nullptr;
	MYSQL* ms = mysql_init(&mysql);
	connection = mysql_real_connect(&mysql, host, user, pw, db, 3306, (const char*)NULL, 0);
	if (connection == NULL) {
		printf("db connection fail.\n");
		printf("%d ERROR : %s\n", mysql_errno(&mysql), mysql_error(&mysql));
	}
	mysql_query(connection, "set NAMES euckr");
	char sql[1000];
	sprintf(sql, "INSERT INTO tbl_members (m_id, m_pw) VALUES ('%s', '%s')", todosVo.getM_id().c_str(), todosVo.getM_pw().c_str());
	mysql_query(connection, sql);
	mysql_close(connection);

}

vector<TodosVo> TodosDao::checkIdPw(TodosVo todosVo) {

	MYSQL mysql;
	MYSQL* connection = nullptr;
	MYSQL_RES* sql_rs;
	MYSQL_ROW sql_row;
	MYSQL* ms = mysql_init(&mysql);
	connection = mysql_real_connect(&mysql, host, user, pw, db, 3306, (const char*)NULL, 0);
	if (connection == NULL) {
		printf("db connection fail.\n");
		printf("%d ERROR : %s\n", mysql_errno(&mysql), mysql_error(&mysql));
	}
	mysql_query(connection, "set NAMES euckr");
	char sql[1000];
	sprintf(sql, "SELECT * FROM tbl_members WHERE m_id = '%s' AND m_pw = '%s'", todosVo.getM_id().c_str(), todosVo.getM_pw().c_str());
	mysql_query(connection, sql);
	sql_rs = mysql_store_result(connection);
	vector<TodosVo> todosVos;
	while ((sql_row = mysql_fetch_row(sql_rs)) != nullptr) {
		TodosVo todosVo;
		todosVo.setM_no(atoi(sql_row[0]));
		todosVo.setM_id(sql_row[1]);
		todosVo.setM_pw(sql_row[2]);
		todosVos.push_back(todosVo);
	}
	mysql_free_result(sql_rs);
	mysql_close(connection);

	return todosVos;

}

vector<TodosVo> TodosDao::getTodos(int m_no) {
	MYSQL mysql;
	MYSQL* connection = nullptr;
	MYSQL_RES* sql_rs;
	MYSQL_ROW sql_row;
	MYSQL* ms = mysql_init(&mysql);
	connection = mysql_real_connect(&mysql, host, user, pw, db, 3306, (const char*)NULL, 0);
	if (connection == NULL) {
		printf("db connection fail.\n");
		printf("%d ERROR : %s\n", mysql_errno(&mysql), mysql_error(&mysql));
	}
	mysql_query(connection, "set NAMES euckr");
	char sql[1000];
	sprintf(sql, "SELECT * FROM tbl_members m INNER JOIN tbl_todos t ON m.m_no = t.m_no WHERE m.m_no = %d", m_no);
	mysql_query(connection, sql);
	sql_rs = mysql_store_result(connection);
	vector<TodosVo> todosVos;
	while ((sql_row = mysql_fetch_row(sql_rs)) != nullptr) {
		TodosVo todosVo;
		todosVo.setM_no(atoi(sql_row[0]));
		todosVo.setM_id(sql_row[1]);
		todosVo.setM_pw(sql_row[2]);
		todosVo.setT_no(atoi(sql_row[3]));
		todosVo.setT_txt(sql_row[4]);
		todosVo.setT_clear(sql_row[5]);
		todosVos.push_back(todosVo);
	}
	mysql_free_result(sql_rs);
	mysql_close(connection);

	return todosVos;

}

void TodosDao::addTodos(TodosVo todosVo) {

	MYSQL mysql;
	MYSQL* connection = nullptr;
	MYSQL* ms = mysql_init(&mysql);
	connection = mysql_real_connect(&mysql, host, user, pw, db, 3306, (const char*)NULL, 0);
	if (connection == NULL) {
		printf("db connection fail.\n");
		printf("%d ERROR : %s\n", mysql_errno(&mysql), mysql_error(&mysql));
	}
	mysql_query(connection, "set NAMES euckr");
	char sql[1000];
	sprintf(sql, "INSERT INTO tbl_todos (t_txt, t_clear, m_no) VALUES ('%s', '%s', %d)", todosVo.getT_txt().c_str(), todosVo.getT_clear().c_str(), todosVo.getM_no());
	mysql_query(connection, sql);
	mysql_close(connection);

}

void TodosDao::checkList(int t_no) {

	MYSQL mysql;
	MYSQL* connection = nullptr;
	MYSQL* ms = mysql_init(&mysql);
	connection = mysql_real_connect(&mysql, host, user, pw, db, 3306, (const char*)NULL, 0);
	if (connection == NULL) {
		printf("db connection fail.\n");
		printf("%d ERROR : %s\n", mysql_errno(&mysql), mysql_error(&mysql));
	}
	mysql_query(connection, "set NAMES euckr");
	char sql[1000];
	sprintf(sql, "UPDATE tbl_todos SET t_clear = 'V', t_clear_date = NOW() WHERE t_no = %d", t_no);
	mysql_query(connection, sql);
	mysql_close(connection);

}

void TodosDao::delClearList() {

	MYSQL mysql;
	MYSQL* connection = nullptr;
	MYSQL* ms = mysql_init(&mysql);
	connection = mysql_real_connect(&mysql, host, user, pw, db, 3306, (const char*)NULL, 0);
	if (connection == NULL) {
		printf("db connection fail.\n");
		printf("%d ERROR : %s\n", mysql_errno(&mysql), mysql_error(&mysql));
	}
	mysql_query(connection, "set NAMES euckr");
	char sql[1000];
	sprintf(sql, "DELETE FROM tbl_todos WHERE t_clear = 'V'");
	mysql_query(connection, sql);
	mysql_close(connection);

}

vector<TodosVo> TodosDao::getDelList(int m_no) {

	MYSQL mysql;
	MYSQL* connection = nullptr;
	MYSQL_RES* sql_rs;
	MYSQL_ROW sql_row;
	MYSQL* ms = mysql_init(&mysql);
	connection = mysql_real_connect(&mysql, host, user, pw, db, 3306, (const char*)NULL, 0);
	if (connection == NULL) {
		printf("db connection fail.\n");
		printf("%d ERROR : %s\n", mysql_errno(&mysql), mysql_error(&mysql));
	}
	mysql_query(connection, "set NAMES euckr");
	char sql[1000];
	sprintf(sql, "SELECT * FROM complete_todos WHERE m_no = %d", m_no);
	mysql_query(connection, sql);
	sql_rs = mysql_store_result(connection);
	vector<TodosVo> todosVos;
	while ((sql_row = mysql_fetch_row(sql_rs)) != nullptr) {
		TodosVo todosVo;
		todosVo.setM_no(atoi(sql_row[0]));
		todosVo.setT_txt(sql_row[1]);
		todosVo.setT_clear_date(sql_row[2]);
		todosVos.push_back(todosVo);
	}
	mysql_free_result(sql_rs);
	mysql_close(connection);

	return todosVos;

}
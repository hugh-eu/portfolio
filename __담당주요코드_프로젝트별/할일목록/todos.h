#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <mysql.h>
#include <windows.h>

using namespace std;


namespace todos {

	class TodosVo {
	private:

		int m_no;
		string m_id;
		string m_pw;

		int t_no;
		string t_txt;
		string t_clear;
		string t_clear_date;

	public:

		void setM_no(int m_no) { this->m_no = m_no; }
		int getM_no() { return this->m_no; }

		void setM_id(string m_id) { this->m_id = m_id; }
		string getM_id() { return this->m_id; }

		void setM_pw(string m_pw) { this->m_pw = m_pw; }
		string getM_pw() { return this->m_pw; }

		void setT_no(int t_no) { this->t_no = t_no; }
		int getT_no() { return this->t_no; }

		void setT_txt(string t_txt) { this->t_txt = t_txt; }
		string getT_txt() { return this->t_txt; }

		void setT_clear(string t_clear) { this->t_clear = t_clear; }
		string getT_clear() { return this->t_clear; }

		void setT_clear_date(string t_clear_date) { this->t_clear_date = t_clear_date; }
		string getT_clear_date() { return this->t_clear_date; }

	};

	class TodosDao {
	private:

		const char* host = "192.168.35.57";
		const char* user = "hugh";
		const char* pw = "1234";
		const char* db = "db_todos";

	public:

		int checkId(string m_id);

		void insertMember(TodosVo todosVo);

		vector<TodosVo> checkIdPw(TodosVo todosVo);

		vector<TodosVo> getTodos(int m_no);

		void addTodos(TodosVo todosVo);

		void checkList(int t_no);

		void delClearList();

		vector<TodosVo> getDelList(int m_no);

	};

	class TodosService {
	private:

		TodosDao todosDao;

	public:

		int checkId(string m_id);

		void insertMember(TodosVo todosVo);

		vector<TodosVo> checkIdPw(TodosVo todosVo);

		vector<TodosVo> getTodos(int m_no);

		void addTodos(TodosVo todosVo);

		void checkList(int t_no);

		void delClearList();

		vector<TodosVo> getDelList(int m_no);

	};

	class TodosController {
	private:

		TodosService todosService;

	public:

		int checkId(string m_id);

		void insertMember(TodosVo todosVo);

		vector<TodosVo> checkIdPw(TodosVo todosVo);

		vector<TodosVo> getTodos(int m_no);

		void addTodos(TodosVo todosVo);

		void checkList(int t_no);

		void delClearList();

		vector<TodosVo> getDelList(int m_no);

	};

	class TodosView {
	private:

		TodosController todosController;

	public:

		void doView();

	};

}

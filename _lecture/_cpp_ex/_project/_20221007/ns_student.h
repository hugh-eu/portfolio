#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <mysql.h>  // 포함디렉터리 include, 라이브러리디렉터리 lib 폴더 위치 설정, libmysql.lib 링커>입력>추가종속성설정 및 복사하기

using namespace std;


namespace student {

	class StudentVo {
	private:

		int s_no;
		string s_name;
		int s_age;
		int s_grade;
		string s_major;

	public:

		int getS_no() {
			return this->s_no;
		}
		void setS_no(int s_no) {
			this->s_no = s_no;
		}
		string getS_name() {
			return this->s_name;
		}
		void setS_name(string s_name) {
			this->s_name = s_name;
		}
		int getS_age() {
			return this->s_age;
		}
		void setS_age(int s_age) {
			this->s_age = s_age;
		}
		int getS_grade() {
			return this->s_grade;
		}
		void setS_grade(int s_grade) {
			this->s_grade = s_grade;
		}
		string getS_major() {
			return this->s_major;
		}
		void setS_major(string s_major) {
			this->s_major = s_major;
		}

	};

	class StudentDao {
	private:

		const char* host = "192.168.61.128";
		const char* user = "hugh";
		const char* pw = "1234";
		const char* db = "db_students";

	public:

		StudentDao() {

		}

		void insertStudentInfo(StudentVo studentVo);

		vector<StudentVo> searchStudentInfo(string s_name);

		vector<StudentVo> searchStudentsInfo();

		vector<StudentVo> searchStudentsInfoForModify(string s_name);

		void modifyStudentInfo(StudentVo studentVo);

		void modifyStudentsInfo();

		vector<StudentVo> searchStudentsInfoForDelete(string s_name);

		void deleteStudentInfo(int s_no);

		void deleteStudentsInfo();

	};

	class StudentService {
	private:

		StudentDao studentDao;

	public:

		StudentService() {

		}

		void insertStudentInfo(StudentVo studentVo);

		vector<StudentVo> searchStudentInfo(string s_name);

		vector<StudentVo> searchStudentsInfo();

		vector<StudentVo> searchStudentsInfoForModify(string s_name);

		void modifyStudentInfo(StudentVo studentVo);

		void modifyStudentsInfo();

		vector<StudentVo> searchStudentsInfoForDelete(string s_name);

		void deleteStudentInfo(int s_no);

		void deleteStudentsInfo();

	};

	class StudentController {
	private:

		StudentService studentService;

	public:

		StudentController() {

		}

		void insertStudentInfo(StudentVo studentVo);

		vector<StudentVo> searchStudentInfo(string s_name);

		vector<StudentVo> searchStudentsInfo();

		vector<StudentVo> searchStudentsInfoForModify(string searchName);

		void modifyStudentInfo(StudentVo studentVo);

		void modifyStudentsInfo();

		vector<StudentVo> searchStudentsInfoForDelete(string searchName);

		void deleteStudentInfo(int s_no);

		void deleteStudentsInfo();

	};

	class StudentView {
	private:

		StudentController studentController;

	public:

		StudentView() {

		}

		void doView();

	};

}
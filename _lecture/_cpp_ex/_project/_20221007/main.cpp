#include "ns_student.h"

using namespace student;


int main() {

	//cout << "mysql_get_client_info() :" << mysql_get_client_info() << endl;  // mysql 설정 확인

	StudentView studentView;
	studentView.doView();

	return 0;
}

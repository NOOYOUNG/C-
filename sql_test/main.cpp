#include <iostream>
#include <mysql.h>
#include <string>
using namespace std;


int main() {
	MYSQL mysql;
	MYSQL* CnQuery;

	MYSQL_RES* result;
	//MYSQL_RES* mysql_store_result(MYSQL* mysql); mysql_query로 실행한 쿼리 Result Set 저장
	MYSQL_ROW row;
	//MYSQL_ROW mysql_fetch_row(MYSQL_RES* result); Result Set에서 하나의 row를 배열로 가져옴

	mysql_init(&mysql); // mysql 구조체 초기화
	
	if (!mysql_real_connect(&mysql, "localhost", "", "", "example", 3306, NULL, 0)) { //연결 실패시
		cerr << "Failed connect Mysql"<<endl;
		return 0;
	}

	//insert문
	mysql_set_character_set(&mysql, "utf8mb4"); // 한글 인식
	
	string name = u8"김강아지";
	int age = 5;

	string insert_query
		= "INSERT INTO test (name, age) VALUES ('" + name + "', " + to_string(age) + ")";

	if (mysql_query(&mysql, insert_query.c_str())) {
		cerr << "Query execution Error" << mysql_error(&mysql) << endl;
		return 0;
	}

	cout << "Add Date Success" << endl;
	mysql_close(&mysql); // mysql 서버와 disconnect


	
	/* //select문
	mysql_query(&mysql, "set session character_set_connection=euckr;");
	mysql_query(&mysql, "set session character_set_results=euckr;");
	mysql_query(&mysql, "set session character_set_client=euckr;");
	string select_query = "SELECT * FROM test";


	if (mysql_query(&mysql, select_query.c_str())) {
		cerr << "Query execution Error" << mysql_error(&mysql) << endl;
		return 0;
	}

	result = mysql_store_result(&mysql);
	if (!result) {
		cerr << "Failed retrieve result" << mysql_error(&mysql) << endl;
		return 0;
	}

	int num_fields = mysql_num_fields(result); // 전체 열의 개수 가져옴
	while ((row = mysql_fetch_row(result))) {
		for (int i = 0; i < num_fields; i++) {
			cout << (row[i] ? row[i] : "NULL") << " ";
		}
		cout << endl;
	}

	mysql_free_result(result); // Result Set 제거
	mysql_close(&mysql);
	*/


	/* //delete문
	string delete_query = "DELETE FROM test WHERE age=20";

	if (mysql_query(&mysql, delete_query.c_str())) {
		cerr << "Query execution Error" << mysql_error(&mysql) << endl;
		return 0;
	}

	cout << "삭제 성공" << endl;
	
	unsigned long affectedRow = mysql_affected_rows(&mysql); // 삭제된 행의 개수
	cout << "삭제된 행은 " << affectedRow << "개" << endl;

	mysql_close(&mysql);
	*/


	return 0;
}

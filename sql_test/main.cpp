#include <iostream>
#include <mysql.h>
#include <string>
using namespace std;


int main() {
	MYSQL mysql;
	MYSQL* CnQuery;

	MYSQL_RES* result;
	//MYSQL_RES* mysql_store_result(MYSQL* mysql); mysql_query�� ������ ���� Result Set ����
	MYSQL_ROW row;
	//MYSQL_ROW mysql_fetch_row(MYSQL_RES* result); Result Set���� �ϳ��� row�� �迭�� ������

	mysql_init(&mysql); // mysql ����ü �ʱ�ȭ
	
	if (!mysql_real_connect(&mysql, "localhost", "root", "root", "example", 3306, NULL, 0)) { //���� ���н�
		cerr << "Failed connect Mysql"<<endl;
		return 0;
	}

	//insert��
	mysql_set_character_set(&mysql, "utf8mb4"); // �ѱ� �ν�
	
	string name = u8"�谭����";
	int age = 5;

	string insert_query
		= "INSERT INTO test (name, age) VALUES ('" + name + "', " + to_string(age) + ")";

	if (mysql_query(&mysql, insert_query.c_str())) {
		cerr << "Query execution Error" << mysql_error(&mysql) << endl;
		return 0;
	}

	cout << "Add Date Success" << endl;
	mysql_close(&mysql); // mysql ������ disconnect


	
	/* //select��
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

	int num_fields = mysql_num_fields(result); // ��ü ���� ���� ������
	while ((row = mysql_fetch_row(result))) {
		for (int i = 0; i < num_fields; i++) {
			cout << (row[i] ? row[i] : "NULL") << " ";
		}
		cout << endl;
	}

	mysql_free_result(result); // Result Set ����
	mysql_close(&mysql);
	*/


	/* //delete��
	string delete_query = "DELETE FROM test WHERE age=20";

	if (mysql_query(&mysql, delete_query.c_str())) {
		cerr << "Query execution Error" << mysql_error(&mysql) << endl;
		return 0;
	}

	cout << "���� ����" << endl;
	
	unsigned long affectedRow = mysql_affected_rows(&mysql); // ������ ���� ����
	cout << "������ ���� " << affectedRow << "��" << endl;

	mysql_close(&mysql);
	*/


	return 0;
}
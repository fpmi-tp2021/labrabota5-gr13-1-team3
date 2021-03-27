#include <sqlite3.h>

const char* adminCommands[] = {
	"���������� �� ���� ��������� � �������� � ���������� ��������� \n\
		� ���������� ��������� ������ ���� �� �������� �������.",

	"���������� �� ���������� �������� � �������� � ���������� � \n\
		��������� ���������, ��������� �� ��������� ������.",

	"���������� �� ��������, ���������� ������������ ���������� ���.",

	"���������� �� �������� ����������� ����������� � �������� � \n\
		���������� ��������� ��������� � ��� ��������������;",

	"���������� �� ������� ������ � �������� � ���������� \n\
		��������� ��������� � ��� �������� � ����� ���������� �����.",

	"��������� �������� ���������� � ������� ��������� � �������, \n\
		���� ��������� ���������� ��������� ��������� �������� \n\
		��������� ���������� �����������.",

	"�� ��������� ������ ���������� ���������� ����������� � ��������� \n\
		��������� �� ������� ����.� �������� ��������� �������� ��������� \n\
		���� ������� � �������� ���� �������.���������� ������� � ����������� \n\
		�������.",

	"�� ��������� ���� �������� ������� ���������� � ����������� \n\
		��� ������� �� ��������� ������.",

	"Insert",
	"Update",
	"Delete",
};
const char* userCommands[] = {
	"���������� �� �������� ����������� ����������� � �������� � \n\
		���������� ��������� ��������� � ��� ��������������;",

	"���������� �� ��������, ���������� ������������ ���������� ���.",

	"�� ��������� ���� �������� ������� ���������� � ����������� \n\
		��� ������� �� ��������� ������."
};
#define ADMIN_FUN_COUNT 11
#define USER_FUN_COUNT 3
#define EXIT_CHOISE 0

void printCommands(const char* comand[], int size);
int Authorization();

void CountOfSoldAndRemainingCD_Ordered(sqlite3 *db);
void CountAndCostCD_ByDate(sqlite3 *db);
void AllCd_ByMaxSold(sqlite3 *db);
void CountAndName_ByMostPopularSigner(sqlite3 *db);
void SalaryAndSoldCount_ByAuthor(sqlite3 *db);
void Restrictions(sqlite3 *db);
void InfoCD_ByDate(sqlite3 *db);
void Info_ByDate(sqlite3 *db);
void Insert(sqlite3 *db);
void UpDate(sqlite3 *db);
void Delete(sqlite3 *db);

const void (*Admin_functions[ADMIN_FUN_COUNT])(sqlite3 *db) = {
	CountOfSoldAndRemainingCD_Ordered,
	CountAndCostCD_ByDate,
	AllCd_ByMaxSold,
	CountAndName_ByMostPopularSigner,
	SalaryAndSoldCount_ByAuthor,
	Restrictions,
	InfoCD_ByDate,
	Info_ByDate,
	Insert,
	UpDate,
	Delete,
};
const void (*User_functions[USER_FUN_COUNT])(sqlite3* db) = {
	CountAndName_ByMostPopularSigner,
	AllCd_ByMaxSold,
	Info_ByDate,
};
const void (**Function[2])(sqlite3* db) = {
		User_functions,
		Admin_functions
};

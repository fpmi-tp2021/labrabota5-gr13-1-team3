#include <string.h>
#include <stdio.h>
#include <sqlite3.h>

const char* adminPassword = "123456";

void printCommands(const char* comand[], int size) {
	for (int i = 0; i < size; i++)
		printf("%d - \t\t%s\n\n", i + 1, comand[i]);
	printf("0 - �����\n");
}

int Authorization() {
	char userName[50], password[50];

	printf("Enter your name: ");
	scanf("%s", userName);
	printf("Enter password: ");
	scanf("%s", password);
	int isAdmin = !strcmp(password, adminPassword);
	char* rights = isAdmin ? "admin" : "user";
	printf("Hello \'%s\' (rights - %s )\nWellcome to database Music-Salon!\n", userName, rights);
	return isAdmin;
}

void CountOfSoldAndRemainingCD_Ordered(sqlite3 *db) {
	// TO DO...
}
void CountAndCostCD_ByDate(sqlite3 *db){
	// TO DO...
}
void AllCd_ByMaxSold(sqlite3 *db){
	// TO DO...
}
void CountAndName_ByMostPopularSigner(sqlite3 *db){
	// TO DO...
}
void SalaryAndSoldCount_ByAuthor(sqlite3 *db){
	// TO DO...
}
void Insert(sqlite3 *db){
	// TO DO...
}
void UpDate(sqlite3 *db){
	// TO DO...
}
void Delete(sqlite3 *db){
	// TO DO...
}
void Restrictions(sqlite3 *db){
	// TO DO...
}
void InfoCD_ByDate(sqlite3 *db){
	// TO DO...
}
void Info_ByDate(sqlite3 *db){
	// TO DO...
}

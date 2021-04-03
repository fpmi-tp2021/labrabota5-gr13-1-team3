#include <string.h>
#include <stdio.h>
#include <sqlite3.h>

const char* adminPassword = "123456";

void printCommands(const char* comand[], int size) {
	for (int i = 0; i < size; i++)
		printf("%d - \t\t%s\n\n", i + 1, comand[i]);
	printf("0 - Выход\n");
}

int Authorization() {
	char userName[51], password[51];

	printf("Enter your name: ");
	scanf("%s", &userName);
	userName[50] = '\0';
	printf("Enter password: ");
	scanf("%s", &password);
	password[50] = '\0';
	int isAdmin = !strcmp(password, adminPassword);
	char* rights = isAdmin ? "admin" : "user";
	printf("Hello \'%s\' (rights - %s )\nWellcome to database Music-Salon!\n", userName, rights);
	return isAdmin;
}

static int callback(void* tmp, int argc, char** argv, char** colName) {
	for (int i = 0; i < argc; i++)
		printf(" %s = %s\n", colName[i], argv[i] ? argv[i] : "NULL");
	printf("\n");
	return 0;
}

void CountOfSoldAndRemainingCD_Ordered(sqlite3 *db) {
	char requestBuffer[255];
	char* errorMsg = 0;

	sprintf(requestBuffer, "DELETE FROM producer_info WHERE id=1;");
	if (sqlite3_exec(db, requestBuffer, callback, 0, &errorMsg))
		printf("%s", errorMsg);
}
void CountAndCostCD_ByDate(sqlite3 *db){
	char requestBuffer[255];
	char* errorMsg = 0;
	int id;
	char* first, * last;
	printf("Enter id: ");
	scanf("%d", &id);
	printf("Enter first date: ");
	scanf("%s", first);
	printf("Enter last date: ");
	scanf("%s", last);

	sprintf(requestBuffer,
		"SELECT Compact_Sale_Info.count, Compact_Disk_info.price "
		"FROM Compact_Sale_Info "
		"JOIN Compact_Disk_info "
		"USING(id) "
		"WHERE Compact_Sale_Info.dateOfOperation "
		"BETWEEN '%s' and '%s' and Compact_Disk_info.id = %d;"
		, first, last, id);
	if (sqlite3_exec(db, requestBuffer, callback, 0, &errorMsg))
		printf("%s", errorMsg);
}
void AllCd_ByMaxSold(sqlite3 *db){
	char requestBuffer[255];
	char* errorMsg = 0;
	sprintf(requestBuffer, 
		"SELECT d.ID, d.dateOfCreate, d.price, i.author, i.signer, i.name"
		"FROM Compact_Disk_info d"
		"JOIN producer_info i"
		"ON d.ID = i.Compact_Disk_info_ID"
		"JOIN Compact_Sale_Info s"
		"ON d.ID = s.Compact_Disk_info_ID"
		"WHERE s.count = (SELECT MAX(count) from Compact_Sale_Info)"
	);

	if (sqlite3_exec(db, requestBuffer, callback, 0, &errorMsg))
		printf("%s", errorMsg);
}
void CountAndName_ByMostPopularSigner(sqlite3 *db){
	char requestBuffer[255];
	char* errorMsg = 0;
	sprintf(requestBuffer,
		"SELECT p.name, p.signer, s.count"
		"FROM producer_info p"
		"JOIN Compact_Sale_Info s"
		"ON p.Compact_Disk_info_ID = s.ID"
		"WHERE s.count = (SELECT max(count) FROM Compact_Sale_Info)"
	);
	if (sqlite3_exec(db, requestBuffer, callback, 0, &errorMsg))
		printf("%s", errorMsg);
}
void SalaryAndSoldCount_ByAuthor(sqlite3 *db){
	char requestBuffer[255];
	char* errorMsg = 0;
	sprintf(requestBuffer,
		"SELECT p.signer, p.name, sum(d.price * s.count) maxsum"
		"FROM producer_info p"
		"JOIN Compact_Sale_Info s"
		"ON p.Compact_Disk_info_ID = s.ID"
		"JOIN Compact_Disk_info d"
		"ON p.Compact_Disk_info_ID = d.ID"
		"GROUP by p.signer"
	);
	if (sqlite3_exec(db, requestBuffer, callback, 0, &errorMsg))
		printf("%s", errorMsg);
}
void Insert(sqlite3 *db){
	char requestBuffer[255];
	char* errorMsg = 0;
	char* author, * signer, * name;
	int Compact_Disk_info_ID;

	printf("Enter autor: ");
	scanf("%s", author);
	printf("Enter signer: ");
	scanf("%s", signer);
	printf("Enter name: ");
	scanf("%s", name);
	printf("Enter Compact_Disk_info_ID: ");
	scanf("%d", Compact_Disk_info_ID);

	sprintf(requestBuffer, "INSERT INTO producer_info (author, signer, name, Compact_Disk_info_ID)"
		"VALUES ('%s', '%s', %s, '%d');", author, signer, name, Compact_Disk_info_ID);
	
	if (sqlite3_exec(db, requestBuffer, callback, 0, &errorMsg))
		printf("%s", errorMsg);
}
void UpDate(sqlite3 *db){
	char requestBuffer[255];
	char* errorMsg = 0;
	int id;
	char* name;
	printf("Enter id to delete");
	scanf("%d", &id);
	printf("Enter name to delete");
	scanf("%s", name);

	sprintf(requestBuffer, "UPDATE producer_info SET name='%s' WHERE id=%d;", name, id);
	if (sqlite3_exec(db, requestBuffer, callback, 0, &errorMsg))
		printf("%s", errorMsg);
}
void Delete(sqlite3 *db){
	char requestBuffer[255];
	char* errorMsg = 0;
	int id;
	printf("Enter id to delete");
	scanf("%d", &id);

	sprintf(requestBuffer, "DELETE FROM producer_info WHERE id=%d;", id);
	if (sqlite3_exec(db, requestBuffer, callback, 0, &errorMsg))
		printf("%s", errorMsg);
}
void Restrictions(sqlite3 *db){
	// TO DO...
}
void InfoCD_ByDate(sqlite3 *db){
	// TO DO...
}
void Info_ByDate(sqlite3 *db){
	char requestBuffer[255];
	char* errorMsg = 0;
	int id;
	printf("Enter id: ");
	scanf("%d", &id);

	sprintf(requestBuffer, "SELECT id, count, dateOfOperation FROM Compact_Sale_Info WHERE id = %d;", id);
	if (sqlite3_exec(db, requestBuffer, callback, 0, &errorMsg))
		printf("%s", errorMsg);
}

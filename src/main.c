#include <string.h>
#include <stdio.h>
#include <locale.h>
#include "../include/MusicManager.h"
#include <sqlite3.h>

int main() {
	setlocale(LC_ALL, "rus");
	sqlite3 * db = NULL;
	int isAdmin = Authorization();

	do {
		int choise;
		printf("\nChoose Command\n");
		isAdmin ? printCommands(adminCommands, ADMIN_FUN_COUNT) : printCommands(userCommands, USER_FUN_COUNT);

		scanf("%d", &choise);

		if (choise == EXIT_CHOISE) 
			break;
		if (!isAdmin && choise > USER_FUN_COUNT) {
			printf("Invalid Comand");
			continue;
		}

		Function[isAdmin][choise - 1](db);		
	} while (1);

	printf("Exit...\n");
	return 1;
}

#include <stdio.h>
#include <sqlite3.h>

int main(){
	char* userName;
	char* password;
	printf("Enter your name: ");
	scanf("%s", &userName);
	printf("Enter password: ");
	scanf("%s", &password);
	printf("Hello %s \n Wellcome to database Music-Salon!", userName);

	do{
		int choise;
	
		printf("Choose Command\n");
		printf("... 0 - exit");
		scanf("%d", &choise);
		switch(choise){
			case 1:{
			       
			       }
			case 2:{
			       }
			default: break;
		}

	}while(1);
	
	printf("Exit...\n");
	return 1;
}

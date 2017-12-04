#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
	char name[100] = "";
	char lastname[100] ="";

	printf("Enter your name: ");
	scanf("%s", name);

	printf("My name is %s \n", name);
	printf("And my last name is %s \n", lastname);

	if(strcmp(lastname,"")) abort();

	return 0;
}
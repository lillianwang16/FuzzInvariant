#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
	char name[10] = "";
	char lastname[100] ="";

	sscanf(argv[1], "%s", name);

	printf("My name is %s \n", name);
	printf("And my last name is %s \n", lastname);

	if(strcmp(lastname,"")) abort();

	return 0;
}

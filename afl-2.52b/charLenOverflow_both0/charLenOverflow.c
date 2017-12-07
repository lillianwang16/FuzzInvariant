#include <stdio.h>
#include <stdlib.h>
#include <errno.h>   // for errno
#include <limits.h>  // for INT_MAX
#include <math.h>

int main(int argc, char * argv [])
{

	if (argc <= 1) return 0;
        
        char firstName[100] = "";
        char lastName[100] = "";
        FILE *input = NULL;
        input = fopen(argv[1], "r");
        fscanf(input, "%s", &firstName);
        fclose(input);
        printf("Read");
        if (strcmp(lastName,"")) abort();
        printf("Success");
        return 0;
}

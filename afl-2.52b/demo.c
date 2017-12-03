#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int main(int argc, char** argv) {

    char *endptr;
    long int x = strtol(argv[0], &endptr, 10);
    if (x < 20) {
        printf(" < 20");
    }
    else if (x >= 20) {
        printf(" >= 20");
    }
    
    else if (x > 100) {
        abort();
    }

    return 0;

}



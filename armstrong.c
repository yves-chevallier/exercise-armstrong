#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool is_armstrong(int number) {
    return false;
}

void help(void) {
    printf("Usage: armstrong [options] [number]\n\n");
    printf("Check whether or not a number is an Armstrong number.\n");
    printf("Returns 0 for yes and 1 for no.\n\n");
    printf("  --version       display version and quit\n");
    printf("  --verbose, -v   display result on stdout\n");
}

int main(int argc, char *argv[]) {

    bool result = is_armstrong(153);

    return !result;
}

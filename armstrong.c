#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool is_armstrong(int number) {
    int candidate = number;
    int digits = log10(number) + 1;

    int sum = 0;
    while (number != 0) {
        sum += pow(number % 10, digits);
        number /= 10;
    }

    return sum == candidate;
}

void version(void) {
    printf("Version 1.0.0 2019(c)\nYves Chevallier <yves.chevallier@heig-vd.ch>\n");
}

void help(void) {
    printf("Usage: armstrong [options] [number]\n\n");
    printf("Check whether or not a number is an Armstrong number.\n");
    printf("Returns 0 for yes and 1 for no.\n\n");
    printf("  --version       display version and quit\n");
    printf("  --verbose, -v   display result on stdout\n");
}

int main(int argc, char *argv[]) {
    if (argc <= 1) {
        return 2;
    }

    bool verbose = false;
    int candidate = 0;
    int options = 0;

    for (size_t i = 1; i < argc; i++) {
        if (argv[i][0] == '-') {
            options++;
        }

        if (!strcmp(argv[i], "--version")) {
            version();
            exit(EXIT_SUCCESS);
        }
        else if (!strcmp(argv[i], "--verbose") || !strcmp(argv[i], "-v")) {
            verbose = true;
        }
        else if (!strcmp(argv[i], "--help")) {
            help();
            exit(EXIT_SUCCESS);
        }
        else {
            candidate = atoi(argv[i]);
        }
    }

    if (argc - options <= 1) {
        if (!scanf("%d", &candidate)) {
            return 3;
        }
    }

    bool result = is_armstrong(candidate);

    if (verbose) {
        printf("Le nombre %d %s un nombre d'Armstrong\n",
            candidate,
            result ? "\033[1;92mest\033[0m" : "\033[1;31mn'est pas\033[0m");
    }

    return !result;
}

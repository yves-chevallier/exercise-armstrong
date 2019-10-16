
bool is_armstrong(int number) {

}

void help(void) {
    printf("Usage: armstrong [options] [number]\n\n");
    printf("Check whether or not a number is an Armstrong number.\n");
    printf("Returns 0 for yes and 1 for no.\n\n");
    printf("  --version       display version and quit\n");
    printf("  --verbose, -v   display result on stdout\n");
}

int main(int argc, char *argv[]) {
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

    bool result = is_armstrong(candidate);

    return !result;
}

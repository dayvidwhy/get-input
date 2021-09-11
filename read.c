#include <stdio.h>
#include <stdlib.h>
#include "get_input.h"

/* errors */
enum Errors {
    NORMAL = 0,
    USAGE = 1,
    FILE_ERROR = 2
};

/* post error to stderr */
int post_status(enum Errors error) {
    const char* message = 0;
    switch(error) {
        case NORMAL:
            message = "Program ended.";
            break;
        case USAGE:
            message = "Usage: ./read.out file.";
            break;
        case FILE_ERROR:
            message = "File could not be read.";
            break;
        default:
            message = "Unknown error";
    }
    fprintf(stderr, "%s\n", message);
    fflush(stderr);
    exit(error);
}

/* start reading a file */
int main(int argc, char** argv) {
    if (argc != 2) {
        post_status(USAGE);
    }
    FILE* file;
    if (!(file = fopen(argv[1], "r"))) {
        post_status(FILE_ERROR);
    }

    char* line = get_line(file);
    fprintf(stdout, "Line was: %s\n", line);
    fflush(stdout);
    post_status(NORMAL);
}

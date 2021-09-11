#include <stdio.h>
#include <stdlib.h>
#include "get_input.h"

/* errors */
enum Errors {
    NORMAL = 0,
    USAGE = 1,
    FILE_ERROR = 2
};

/* pass a message to stderr */
void warn(const char* message) {
    fprintf(stderr, "%s\n", message);
    fflush(stderr);
}

/* pass a string to stdout */
void print(char* message) {
    fprintf(stdout, "%s\n", message);
    fflush(stdout);
}

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
    warn(message);
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
    print("Line was:");
    print(line);

    post_status(NORMAL);
}

#include <stdio.h>
#include <stdlib.h>
#include "get_input.h"

int main(int argc, char** argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: ./read.out file.\n");
        fflush(stderr);
        exit(1);
    }
    FILE* file;
    if (!(file = fopen(argv[1], "r"))) {
        fprintf(stderr, "File could not be read.\n");
        fflush(stderr);
        exit(1);
    }

    char* line = get_line(file);
    fprintf(stderr, "Line was: %s\n", line);
    fflush(stderr);
    exit(0);
}

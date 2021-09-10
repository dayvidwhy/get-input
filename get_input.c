#include <stdio.h>
#include <stdlib.h>

#define MEMORY_MULTIPLIER 2
#define NEWLINE_CHARACTER 10

/* Retrieve a series of characters up until a new line or EOF from file. */
char* get_line(FILE* file) {
    int cursor = 0;
    int memSize = 2;
    int select;

    /* initial malloc */
    char* line = (char *) malloc(sizeof(char) * memSize);

    /* start reading */
    while (1) {
        select = fgetc(file);
        if (select == EOF || select == NEWLINE_CHARACTER) {
            break;
        }
        if (cursor == memSize) {
            /* Increase in multiples */
            memSize = memSize * MEMORY_MULTIPLIER;
            line = (char *) realloc(line, sizeof(char) * memSize);
        }
        line[cursor] = (char) select;
        cursor++;
    }
    line[cursor] = '\0';
    return line;
}

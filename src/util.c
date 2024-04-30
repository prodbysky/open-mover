#include <stdlib.h>
#include <stdio.h>

#include <glad/glad.h>

#include "types.h"
#include "util.h"

char* read_entire_file(const char* fileName) {
    FILE* file = fopen(fileName, "r");
    if (file == NULL) {
        printf("Failed to open file: %s", fileName);
        return NULL;
    }
    fseek(file, 0, SEEK_END);
    i32 size = ftell(file);
    fseek(file, 0, SEEK_SET);
    
    char* string = malloc(size + 1);
    fread(string, size, 1, file);
    fclose(file);
    string[size] = 0;
    
    return string;
}

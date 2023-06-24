#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 1024

bool isSubsetValid(int* subset, int size) {
    if (size <= 1) {
        return false;
    }

    int i, j;
    for (i = 0; i < size - 1; i++) {
        for (j = i + 1; j < size; j++) {
            if (subset[i] == subset[j]) {
                return false;
            }
        }
    }

    int x;
    for (x = 2; x <= subset[0]; x++) {
        bool dividesAll = true;
        for (i = 0; i < size; i++) {
            if (subset[i] % x != 0) {
                dividesAll = false;
                break;
            }
        }
        if (dividesAll) {
            return false;
        }
    }

    return true;
}

char* solve(int a_count, int* a) {
    int i, j;
    for (i = 0; i < a_count; i++) {
        int* subset = malloc((i + 1) * sizeof(int));

        for (j = 0; j <= i; j++) {
            subset[j] = a[j];
        }

        if (isSubsetValid(subset, i + 1)) {
            free(subset);
            return "YES";
        }

        free(subset);
    }

    return "NO";
}

int main() {
    FILE* input_file = fopen("input4.txt", "r");
    FILE* output_file = fopen("output4.txt", "w");

    if (!input_file) {
        printf("Error al abrir el archivo de entrada.\n");
        return 1;
    }

    if (!output_file) {
        printf("Error al abrir el archivo de salida.\n");
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    fgets(line, MAX_LINE_LENGTH, input_file);
    int t = atoi(line);

    int t_itr, i;
    for (t_itr = 0; t_itr < t; t_itr++) {
        fgets(line, MAX_LINE_LENGTH, input_file);
        int a_count = atoi(line);

        fgets(line, MAX_LINE_LENGTH, input_file);
        char* token = strtok(line, " ");

        int* a = malloc(a_count * sizeof(int));

        for (i = 0; i < a_count; i++) {
            a[i] = atoi(token);
            token = strtok(NULL, " ");
        }

        char* result = solve(a_count, a);

        fprintf(output_file, "%s\n", result);

        free(a);
    }

    fclose(input_file);
    fclose(output_file);

    return 0;
}


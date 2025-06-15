#include <stdio.h>
#include "Save_To_CSV.h"


void save_times_all_algorithms(const char* filename, int N, float times[], int collisions[], int alg_count) {
    FILE* file = fopen(filename, "a");
    if (!file){ 
        perror("Failed to open file");  
        return;
    }
    fprintf(file, "%d", N);
    for (int i = 0; i < alg_count; i++) {
        fprintf(file, ",%.6f", times[i]);
        fprintf(file, ",%d", collisions[i]);
    }
    fprintf(file, "\n");
    fclose(file);
}
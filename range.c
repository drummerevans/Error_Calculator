#include <stdio.h>

int main() {
    FILE *file_ptr, *soln_ptr;
    int i, j;
    float max, min, arr[100]; // adjust arr size depending on amount of data

    file_ptr = fopen("dummydat.txt", "r"); // enter in text file here for reading from
    soln_ptr = fopen("solution.txt", "w"); // enter in text file here for writing to

    if(file_ptr != NULL) {
        for(i = 0; !feof(file_ptr); i++) {
            fscanf(file_ptr, "%f ", &arr[i]);
        }
        for(j = 0; j < i; j++) {
            fprintf(stdout, "Element[%d] contains: %f\n", j, arr[j]);
        }
        for(j = 0; j < i; j++) {
            fprintf(soln_ptr, "%f ", arr[j]);
        }

        max = arr[0];
        for(j = 0; j < i; j++) {
            if(max < arr[j]) {
                max = arr[j];
            }
        }

        min = arr[0];
        for(j = 0; j < i; j++) {
            if(min > arr[j]) {
                min = arr[j];
            }
        }
        fprintf(soln_ptr, "\nThe max value is: %f\t The min value is: %f\t", max, min);
        fprintf(soln_ptr, "\nThe range of the data is: %f\n", max - min);
        fprintf(stdout, "\nThe max value is: %f\t The min value is: %f\t", max, min);
        fprintf(stdout, "\nThe range of the data is: %f\n", max - min);

        fclose(file_ptr);
        fclose(soln_ptr);
        return 0;
    }
    else {
        fprintf(stdout, "Unable to open a file\n");
        return 1;
    }
}

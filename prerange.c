#include <stdio.h>

int main() {
    FILE *file_ptr;
    int i;
    char array[21];

    file_ptr = fopen("dummydat.txt", "w");

    if(file_ptr != NULL) {
        printf("Enter in 10 numbers, separated by spaces, into the text file: ");
        
        fgets(array, sizeof(array), stdin);
        fputs(array, file_ptr);

        fclose(file_ptr);

        return 0;
    }
    else {
        printf("Text file not created\n");
        return 1;
    }
}
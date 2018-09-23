#include <stdio.h>

int main() {
    FILE *file_ptr;
    int i;
    char text[31];

    file_ptr = fopen("data.txt", "w");

    if(file_ptr != NULL) {
        printf("Text file \"data.txt\" successfully created\n");
        
        printf("Enter the numbers 1 - 10, separated by spaces: ");
        fgets(text, sizeof(text), stdin);
        fputs(text, file_ptr);

        fprintf(stdout, "To clarify, the numbers entered were: \n%s\n", text);
        fclose(file_ptr);
        return 0;
    }
    else {
        printf("An error has occurred!\n");
        return 1;
    }
}
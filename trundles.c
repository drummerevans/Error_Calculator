#include <stdio.h>

int main() {
    FILE *fptr;
    int i, col_x[20], col_y[20], cols;

    fptr = fopen("trundles.dat", "w");

    if(fptr != NULL) {
        printf("A data file has been created\n");
        
        printf("How many elements would you like to put in to both columns? ");
        scanf("%d", &cols);
        printf("Enter in two numbers, separated by a space (in each column) and press enter to continue: ");

        for(i = 0; i < cols; i++) {
            fscanf(stdin, "%d %d", &col_x[i], &col_y[i]);
        }
        
        for(i = 0; i < cols; i++) {
            fprintf(fptr, "%d %d\n", col_x[i], col_y[i]);
        }
    }
    else {
        printf("Data file not created\n");
        return 1;
    }
}
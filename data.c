#include <stdio.h>
#include <math.h>

float std_dev(int x, float y);
float uncertainty(int m, float n);

int main() {
    FILE *data_ptr;
    FILE *result_ptr;
    int i, j;
    float nums[150], result, sum;

    data_ptr = fopen("data.txt", "r"); // put in text file to read results to
    result_ptr = fopen("result", "w"); // put in text file to write to

    if((data_ptr != NULL) && (result_ptr != NULL)) {
        for(i = 0; !feof(data_ptr); i++) {
            fscanf(data_ptr, "%f ", &nums[i]); // scanning text numbers from file to elements in the array nums
        }
        
        fprintf(stdout, "\nThere are %d numbers found\n", i);
    
        for(j = 0; j < i; j++) {
            result += nums[j];
        }
        float mean = result / i;
        fprintf(stdout, "The mean value of the numbers is: %f\n\n", mean);
        
        for(j = 0; j < i; j++) {
            fprintf(stdout, "Element[%d] contains number %f\n", j, nums[j]);
            sum += (nums[j] - mean) * (nums[j] - mean);
            printf("%dst calc gives: %f\n", j, sum);
        }
        fprintf(stdout, "\nThe sum of the difference of squares is: %f\n", sum);
        
        // printf("There are a total of %d numbers\n", i);
        float sigma = std_dev(i, sum);
        fprintf(stdout, "The standard deviation of the numbers is: %f\n", sigma);

        float error = uncertainty(i, sigma);
        fprintf(stdout, "The uncertainty in the mean of the numbers is: %f\n", error);
        
        for(j = 0; j < i; j++) {
            fprintf(result_ptr, "%d ", nums[j]); // adjust whether to read in ints of floats
        }
        
        fprintf(result_ptr, "\nThe mean value of these numbers is: %f", mean);
        fprintf(result_ptr, "\nThe std dev of these numbers is: %f", sigma);
        fprintf(result_ptr, "\nThe uncertainty (in the mean) of these numbers is: %f", error);
        
        fclose(data_ptr);
        fclose(result_ptr);
        return 0;
    }
    else {
        fprintf(stdout, "Unable to open file\n");
        return 1;
    } 
}

float std_dev(int x, float y) {
    float value;
    
    value = y / (x - 1);

    return sqrt(value);
}

float uncertainty(int m, float n) {
    float calculation;

    calculation = n / (sqrt(m));

    return calculation;
}


  
    
        



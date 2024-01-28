#include <stdio.h>
//Used AI to determine length of integer array in C
int main(int argc,char** argv) {
    int array[] = {1,2,3,4,5};
    int sum = 0;
    int length = sizeof(numbers) / sizeof(int);

    for (int i = 0; i<length; i++) {
        sum += array[i];
    }

    printf("Sum: %d",sum);
    printf("Average: %s",sum/length);
    return 0;
}
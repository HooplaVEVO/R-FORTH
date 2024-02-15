#include <stdio.h>

int main(int argc, char** argv) {
    float num1;
    float num2;
    printf("Enter a number: \n");
    scanf("%f", &num1);
    printf("Enter another number: \n");
    scanf("%f", &num2);

    printf("Sum: %f\n",num1+num2);
    printf("Difference: %f\n",num1-num2);
    printf("Product: %f\n",num1*num2);
    printf("Quotient: %f\n",num1/num2);
    return 0;
}
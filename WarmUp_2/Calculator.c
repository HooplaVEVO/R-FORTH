#include <stdio.h>
#include <stdin.h>

int main(int argc, char** argv) {
    float num1;
    float num2;
    printf("Enter a number: \n");
    scanf("%d", &num1);
    printf("Enter another number: \n");
    scanf("%d", &num2);

    printf("Sum: "+(num1+num2)+"\n");
    printf("Difference: "+(num1-num2)+"\n");
    printf("Product: "+(num1*num2)+"\n");
    printf("Quotient: "+(num1/num2)+"\n");
    return 0;
}
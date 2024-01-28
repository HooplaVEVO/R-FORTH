#include <stdio.h>

int main(int argc,char** argv) {
    int number = 5;
    int result = factorial(number);
    printf("Result: %d",result);
    return 0;
}

int factorial(int n) {
    if (n == 0){
        return 1;
    }
    return n*factorial(n-1);
}
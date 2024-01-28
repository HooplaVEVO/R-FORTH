#include <stdio.h>
//Had to use AI to determine length of char array

int main(int argc,char** argv) {
    char str[] = "Hello";
    char result[] = str;
    int length = 0;
    while(str[length!='/0']) {
        length++;
    }
    for (int i=0; i<(length); i++) {
        result[i] = str[length-i];
    }
    printf("%s\n",result);
    return 0;
}
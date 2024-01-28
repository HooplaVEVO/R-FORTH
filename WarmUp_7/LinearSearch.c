#include <stdio.h>

int main(int argc, char** argv) {
    int[] array = {1, 4, 7, 9, 12};
    int target = 9;
    int index = LinearSearch(array,target);
    if (index == -1){
        printf("Target integer %d not found",target);
    }
    else {
        printf("Target integer %d found at index %s",target,index);
    }
}

int LinearSearch(int[] array,int target) {
    int length = sizeof(array)/sizeof(array[0]);
    for (int i=0; i<length; i++) {
        if (array[i] == target){
            return i;
        }
    }
    return -1;
}
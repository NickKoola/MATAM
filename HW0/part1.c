#include <stdbool.h>
#include <stdio.h>
#include <malloc.h>

bool isPowerOfTwo(int num) {
    int power = 0;
    if(num == 0) 
        return false;
    while (num != 1) {
        if(num % 2 != 0)    
            return 0;
        num = num/2;
        power++;
    }
    return 1;
}
int getPowerOfTwo(int num) {
    int power = 0;
    while (num != 1) {
        num = num/2;
        power++;
    }
    return power;
}
int main() {
    printf("Enter size of input:\n");
    int size;
    scanf("%d",&size);
    if(size <= 0) {
        printf("Invalid size\n");
        return 0;
    }
    int* array = (int*)malloc(size * sizeof(int));
    if(array == NULL) {
        printf("failed malloc");
        free(array);
        return 0;
    }

    printf("Enter numbers:\n");
    for(int i = 0; i < size; ++i) {
        if(scanf("%d",&array[i]) == 0){ // if illegal input
            printf("Invalid number\n");
            free(array);
            return 0;
        }
    }

    int expoSum = 0;
    for(int i = 0; i < size; ++i) {
        if (isPowerOfTwo(array[i])) {
            int power = getPowerOfTwo(array[i]);
            expoSum += power;
            printf("The number %d is a power of 2: %d = 2^%d\n",array[i],array[i],power);
        }
    }
    printf("Total exponent sum is %d\n",expoSum);
    free(array);

}
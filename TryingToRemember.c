#include <stdio.h>

void findIndexMax(int array[], int n, int *maxIndex){
    if (n <= 0) {
        *maxIndex = -1;
        return;
    }
    *maxIndex = 0;
    int maxNum = array[0];
    for (int i = 1; i < n; i++){
        if (array[i] > maxNum) {
            maxNum = array[i];
            *maxIndex = i;
        }
    }
}


int main(){
    int array1[] = {12, 6, 3, 34, 67, 8, 42, 3, 5, 6, 7, 4, 2, 2, 3, 45, 56, 67, 7, 432, 4, 6, 76};
    int n = sizeof(array1) / sizeof(array1[0]);

    int result = 0;
    findIndexMax(array1, n, &result);
    printf("%d", result);
}
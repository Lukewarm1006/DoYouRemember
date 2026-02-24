#include <stdio.h>
#include <stdlib.h>

int* createArray(int n){
    int* p = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++){
        p[i] = i+1;
    }

    return p;
}

int main(){
    int n = 47;
    int* array = createArray(n);

    for (int i = 0; i < n; i++){
        printf("%d ", array[i]);
    }

    free(array);
}
#include <stdio.h>
#include <stdlib.h>

void merge(int list[], int size, int start);
void printl(int list[], int size);

int main(){
    int unsorted[] = {9, 15, 45, 32, 70, 1, 45, 21, 15};
    int size = sizeof(unsorted)/sizeof(int);
    merge(unsorted, size, 0);
    printl(unsorted, size);
}

void merge(int list[], int size, int start){
    if (size < 2){
        return;
    }
    merge(list, size/2, start);
    merge(list, size - size/2, start + size/2);
    int* fh = (int*)malloc(size/2*sizeof(int));
    int* sh = (int*)malloc((size - size/2)*sizeof(int));
    for (int i = 0; i < size/2; i++){
        fh[i] = list[start + i];
    }
    for (int i = 0; i < size - size/2; i++){
        sh[i] = list[start + size/2 + i];
    }
    for (int i = 0, j = 0; i < size; i++){
        if (j >= size - size/2 || (fh[i-j] <= sh[j] && i-j < size/2)){
            list[start + i] = fh[i-j];
        }
        else {
            list[start + i] = sh[j];
            j++;
        }
    }
    free(fh);
    free(sh);
    return;
}

void printl(int list[], int size){
    for (int i = 0; i < size; i++){
        printf("%d\t", list[i]);
    }
    printf("\n");
}

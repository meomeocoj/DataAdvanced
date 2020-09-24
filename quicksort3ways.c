#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define NUMBER 100000000

void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int partition_2w(int arr[], long int low, long int high){
    int pivot = arr[high];
    int i = low - 1;
    for(long int j = low; j < high; j++){
        if(arr[j] < pivot){
            ++i;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort_2w(int arr[], long int low, long int high){
    if(low < high){
        int pi = partition_2w(arr, low, high);
        quickSort_2w(arr, low, pi - 1);
        quickSort_2w(arr, pi + 1, high);
    }
}

// void printArray(int arr[], long int n){
//     for(long int i = 0; i < n; i++){
//         printf("%ld ", arr[i]);
//     }
// }
void exch(int a[], int i, int j){
    int tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}
void sort(int a[], int l, int r) {
    if (r <= l) return;
    int i = l-1, j = r;
    int p = l-1, q = r;
    while(1){
        while (a[++i] < a[r]);
        while (a[r] < a[--j]) if (j == l) break;
        if (i >= j) break;
        exch(a, i, j);
        if (a[i]==a[r]) exch(a, ++p, i);
        if (a[j]==a[r]) exch(a, --q, j);

        }
    exch(a, i, r);
    j = i - 1;
    i = i + 1;
    for (int k = l ; k <= p; k++) exch(a, k, j--);
    for (int k = r-1; k >= q; k--) exch(a, k, i++);
    sort(a, l, j);
    sort(a, i, r);
}
int cmpInt(const void *a, const void *b){
    return (*(int*)a) - *((int *)b);
}
int main(){
    srand((int)time(0));
    clock_t start, end;
    int *arr1 = (int*)malloc(NUMBER*sizeof(int));
    int *arr2 = (int*)malloc(NUMBER*sizeof(int));
    for(long int i = 0; i < NUMBER; ++i){
        arr1[i] = 1 + rand() % 10;
    }
    memcpy(arr2,arr1,NUMBER);
    start = clock();
    sort(arr1, 0, NUMBER);
    end = clock();
    // printArray(arr1, NUMBER);
    printf("\n");
    printf("Soring time of 3 ways QS:  %.2f seconds\n", (double)(end-start)/CLOCKS_PER_SEC);
    time_t start2, end2;
    start2 = clock();
    qsort(arr2,NUMBER,sizeof(int),cmpInt);
    end2 = clock();
    printf("\n");
    printf("Soring time of qsort:  %.2f seconds\n", (double)(end2-start2)/CLOCKS_PER_SEC);
}

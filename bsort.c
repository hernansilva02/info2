#include <stdio.h>

int length(int arr[], int size);

int main(void) {
    int arr[] = {5, 7, 2, 3, 4, 1, 6, 23, 123, 21, 10, 1002, 840, 12, 1233, 8, 9};
    int size = sizeof(arr);

    for (int i = 0; i < length(arr, size); i++) {
         for (int j = 0; j < length(arr, size) - i - 1; j++) {
             if (arr[j] > arr[j+1]) {
                int swp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = swp;
            }
        }
    }
    for (int i = 0; i < length(arr, size); i++) {
        printf("%d", arr[i]);
            printf(" ");
    }
    printf("\n");
}

int length(int arr[], int size) {
    int len = (size / sizeof(arr[0]));
    return len;
}

#include <stdio.h>

int main() {
    int arr[] = {23, 3, 45, 12, 67, 54, 6, 4};
    int size = sizeof(arr)/sizeof(arr[0]);
    int i;
    size = size - 1;
    for(i=0; i<size; i++)
        printf("%d", arr[i]);
    return 0;
}

// Time complexity: O(1)
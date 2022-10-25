// DELETING AT THE BEGINNING (ARRAY)

#include <stdio.h>
#include <stdlib.h>

int del_first(int arr[], int n)
{
    int i;
    if(n == 0)
    {
        printf("Array is empty.");
        return n;
    }
    for(i=0; i<n-1; i++)
        arr[i] = arr[i+1];
    return n-1;
}

int main() {
    int arr[8];
    int n, i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    for(i=0; i<n; i++)
        scanf("%d", &arr[i]);
    
    n = del_first(arr, n);
    for(i=0; i<n; i++)
        printf("%d", arr[i]);
    return 0;
}
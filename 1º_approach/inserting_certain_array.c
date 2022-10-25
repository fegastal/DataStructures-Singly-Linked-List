#include <stdio.h>

void add_at_pos(int arr[], int arr2[], int n, int data, int pos)
{
    int i;
    int index = pos-1;
    for(i=0; i<=index-1; i++)
        arr2[i] = arr[i];

    arr2[index] = data;
    int j;
    for(i=5; j=4; i<11; j<10; i++; j++)
        arr2[i] = arr[j];
}

int main()
{
    int arr[] = {2, 34, 21, 6, 7, 8, 90, 67, 23, 39};
    int pos = 5, data = 78, i;
    int size = sizeof(arr)/sizeof(arr[0]);
    int arr2[size+1];
    add_at_pos(arr, arr2, size, data, pos);
    for(i=0; i<size+1; i++)
        printf("%d", arr2[i]);
}

// Output: 2 34 21 6 78 7 8 90 67 23 39
// Time Complexity: 0(n)

// REMEMBER!
// We can't return an array from a function because an array
// created in the function is local to that function;

// This is the reason why arr2[] has been passed as a parameter
// to a funciton.

// Passing arr2(name of the array) is equivalent to passing
// the address of the first block of arr2. So the changes made in called
// function will be reflected in the caller function.
#include <stdio.h>
#include <stdlib.h>
#define ARR_SIZE 10

void swap(int* a, int* b)
{
    if (a == b)
        return;
    int c = *a;
    *a = *b;
    *b = c;
}

void q_sort(int arr[], int high, int low)
{
    if (high <= low)
        return;
    int p = high;
    int prevhigh = low;
    int idx = low;
    while (idx < high)
    {
        if (arr[idx] < arr[p])
        {
            swap(&arr[prevhigh], &arr[idx]);
            prevhigh++;
        }
        idx++;
    }
    swap(&arr[p], &arr[prevhigh]);
    q_sort(arr, prevhigh - 1, low);
    q_sort(arr, high, prevhigh + 1);

}    

int main()
{
    int arr[ARR_SIZE];
    int i;

    for (i = 0; i < ARR_SIZE; i++)
        arr[i] = rand()%100;
    for (i = 0; i < ARR_SIZE; i++)
        printf("%d ", arr[i]);
    printf("\n");
    q_sort(arr, ARR_SIZE - 1, 0);
    for (i = 0; i < ARR_SIZE; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}    

#include <stdio.h>

void merge(int arr[], int low, int mid, int high)
{
    int temp1[high-low];
    int temp2[high-low];
    int i = 0;
    int j = 0;
    int count = low;
    
    for (i = low; i <= mid; i++) 
        temp1[i] = arr[i];
    for (i = mid + 1; i <= high; i++)
        temp2[i] = arr[i];

    i = low; j = mid + 1;

    while (i <= mid && j <= high)
    {
        if (temp1[i] <= temp2[j])
            arr[count] = temp1[i++];
        else
            arr[count] = temp2[j++];
        count++;
    }
    while (i <= mid) arr[count++] = temp1[i++];
    while (j <= high) arr[count++] = temp2[j++];
}    

void mergesort(int arr[], int low, int high)
{
    int mid = (low + high)/2;
    if(low < high)
    {
        mergesort(arr, low, mid);
        mergesort(arr, mid+1, high);
        merge(arr, low, mid, high);
    }
}

int main()
{
    int arr[] = {2,5,3,9,10,1,-2,5,4};
    mergesort(arr, 0, 8);
    int i;
    for (i = 0; i < 9; i++)
        printf ("%d ", arr[i]);
    return 0;
}

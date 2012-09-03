//
// Program to print out the elements of a matrix in spiral order
//

#include<stdio.h>
#define ROWS 4
#define COLS 5

void print_spiral(int arr[][COLS])
{
    int r_start = 0;
    int r_stop = ROWS - 1;
    int c_start = 0;
    int c_stop = COLS - 1;
    int i;
    while (r_start <= r_stop && c_start <= c_stop)
    {
        for (i = c_start; i <= c_stop; i++)
            printf("%d ", arr[r_start][i]);
        for (i = r_start + 1; i <= r_stop; i++)
            printf("%d ", arr[i][c_stop]);
        // Traverse R->L and upwards only if this isnt the innermost
        // matrix
        if (r_start < r_stop)
            for (i = c_stop - 1; i >= c_start; i--)
                printf("%d ", arr[r_stop][i]);
        if (c_start < c_stop)
            for (i = r_stop - 1; i >= r_start + 1; i--)
                printf("%d ", arr[i][c_start]);
        c_start++;
        c_stop--;
        r_start++;
        r_stop--;
    }
}

int main()
{
    int arr[ROWS][COLS] = {{1, 2, 3, 4, 5},
                           {4, 5, 6, 7, 8},
                           {7, 8, 9, 9, 10},
                           {10, 11, 12, 13, 15}};
    print_spiral(arr);
    return 0;
}    

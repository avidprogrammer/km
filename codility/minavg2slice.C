#include <stdio.h>

int solution(int A[], int N) {

    float new_avg, curr_avg = (A[0] + A[1])/2.0;
    int start_pos = 0;
    int idx;
    
    for (idx = 1; idx < (N-1); idx++)
    {
        // Sequence of prev + curr + next 
        new_avg = (A[idx-1] + A[idx] + A[idx+1])/3.0;
        printf("1.new_avg %f avg %f idx %d\n", new_avg, curr_avg, idx);
        if (new_avg < curr_avg)
        {
            curr_avg = new_avg;
            start_pos = idx - 1;
        }

        // sequence of curr + next
        new_avg = (A[idx] + A[idx+1])/2.0;
        printf("2.new_avg %f avg %f idx %d start_pos %d\n", new_avg, curr_avg, idx, start_pos);
        if (new_avg < curr_avg)
        {
            start_pos = idx;
            curr_avg = new_avg;
        }
    }
    printf("avg %f", curr_avg);
    printf("\nstart_pos %d", start_pos);
    return start_pos;
}

int main() {

  int arr1[] = {10, 10, -1, 2, 4, -1, 2, -1}; //expected 5
  int arr2[] = {-3, -5, -8, -4, -10 }; //expected 2
  int arr3[] = {-3, -3, 10, -10, 10, -10, 10, -10, 10, -3, -3, 100, -11};// expected 3
  solution(arr3, 13);
  return 0;
}

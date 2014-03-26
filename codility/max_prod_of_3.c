#include<stdio.h>
#include<malloc.h>

void swap(int* a, int*b)
{
    int t;
    t = *a;
    *a = *b;
    *b = t;
}
int partition(int A[], int lo, int hi)
{
    int p = lo, i;
    int low_wall = lo;

    for(i=lo+1; i < hi; i++)
    {
        if (A[p] > A[i])
        {
            low_wall++;
            swap(&A[low_wall], &A[i]);
        }

    }
    swap(&A[low_wall], &A[p]);
    return (low_wall);

}
void q_sort(int A[], int lo, int hi)
{
    int p;
    if (lo >= hi)
        return;
    p = partition(A, lo, hi);
    q_sort(A, lo, p);
    q_sort(A, p+1, hi);
}

void merge(int A[], int lo, int mid, int hi)
{
    int* temp = malloc(sizeof(int) * (hi - lo + 1));
    int i = lo, j = mid+1, cnt = 0;
    while ( (i <= mid) && (j < hi))
    {
        if (A[i] <= A[j]) temp[cnt++] = A[i++];
        else temp[cnt++] = A[j++];
    }
    while (i <= mid)
        temp[cnt++] = A[i++];
    while (j < hi)
        temp[cnt++] = A[j++];

   cnt--;
   while(cnt>=0)
   {
       A[lo+cnt] = temp[cnt];
       cnt--;
   }

    free(temp);
}

void m_sort(int A[], int lo, int hi)
{
    int mid = (lo + hi) /2;
    if (lo >= hi)
        return;
    m_sort(A, lo, mid);
    m_sort(A, mid+1, hi);
    merge(A, lo, mid, hi);
}


void sort(int A[], int N)
{
    //q_sort(A, 0, N);
    m_sort(A, 0, N);
}

void print_arr(int A[], int N)
{
    int i;
    for (i = 0; i < N; i++)
        printf("%d ",A[i]);
    printf("\n");
}

int solution(int A[], int N)
{
    sort(A, N);
    print_arr(A, N);

    long long low = A[0] * A[1] * A[N-1];
    long long high = A[N-1] * A[N-2] * A[N-3];
    return ((low > high) ? low : high);
    return 0;
}

int main(int argc, char* argv[])
{
  int N = 5;
  int A[5] = {-3, 0 , 33, -4, 1};
  solution(A, N);
  return 0;
}  

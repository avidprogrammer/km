long max(long a, long b)
{
    if (a > b)
        return a;
    return b;
}

int solution(int A[], int N) {
    long maxsofar = A[0];
    long maxendhere = A[0];
    int i;
    
    for (i=1; i<N; i++)
    {
        maxendhere = max(A[i], maxendhere + A[i]);
        maxsofar = max(maxsofar, maxendhere);
    }
    return maxsofar;
}


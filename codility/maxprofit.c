int min(int a, int b)
{
    if (a < b)
        return a;
    return b;
}

int max(int a, int b)
{
    if (a > b)
        return a;
    return b;
}

int solution(int A[], int N) {
    int minsofar, maxsofar;
    int i, profit = 0;
    
    if (N)
    {
        minsofar = A[0];
        maxsofar = A[0];
    }
    
    for(i=1; i < N; i++)
    {
        minsofar = min(A[i], minsofar);
        maxsofar = max(A[i], minsofar);
        if ((maxsofar - minsofar) > profit)
            profit = maxsofar - minsofar;
    }
    
    return (profit > 0) ? profit : 0;
}


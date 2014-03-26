long mod (long num)
{
    if (num < 0)
        return num * -1;
    return num;
}    

int solution(int A[], int N) {
    long rsum = 0, lsum=0;
    int diff, mindiff = pow(2, ((sizeof(int) * 8) - 1)) - 1;
    int i;
    
    if (N < 2)
        return -1;
    
    for (i = 0; i < N; i++)
    {
        rsum += A[i];
    }
    
    for (i = 1; i < N; i++)
    {
        lsum += A[i-1];
        rsum -= A[i-1];
        diff = mod(lsum - rsum);
        if (diff < mindiff)
        {
            mindiff = diff;
        }
    }
    
    return mindiff;
}


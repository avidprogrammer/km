int solution(int N) {
    int dividend, divisor;
    int min_peri = N + 1;
    int i = 2;
    
    while ((i*i) <= N)
    {
        dividend = N%i;
        divisor = N/i;
        if (!dividend && min_peri > (divisor + i))
        {
            min_peri = divisor + i;
        }
        i++;
    }
    return 2*min_peri;
}


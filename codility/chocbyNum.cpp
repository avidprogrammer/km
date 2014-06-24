// you can use includes, for example:
#include <algorithm>

int gcd(int a, int b)
{
    if (a > b)
        swap(a, b);
    while (b%a != 0)
    {
        a = a%b;
        swap(a,b);
    }
    return a;
}


int solution(int N, int M) {
    int g = gcd(N, M);
    return N/g;
}


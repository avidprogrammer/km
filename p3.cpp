#include <algorithm>
#include <vector>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string.h>

using namespace std;
typedef unsigned long long ull;

ull largest_prime(ull N)
{
    ull div = 2, last_div = 1, last_n = N;
    ull srt = sqrt(N);
    ull n = N;
    while(n >1 && div<=srt)
    {
        if (n%div !=0)
            div++;
        else
        {
            last_div = div;
            last_n = n;
            n = n/div;
        }
    }
    return (last_n == last_div)? last_n : last_n/last_div;
}    

int main()
{
    ull i, T, N;
    
    cin >> T;
    for (i=0; i<T; i++)
    {
        cin >> N;
        cout << largest_prime(N) <<endl;
    }
    
    return 0;
}    


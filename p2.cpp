#include <algorithm>
#include <iostream>
#include <stdio.h>

typedef unsigned long long ull;
const ull MAX = 40000000000000000LL;
using namespace std;

int main()
{
    int i, T, idx, tot;
    ull N;
    ull a = 1, b = 2;
    ull fibo[27], sumfibo[27];
    ull* f_ptr = NULL;
    
    fibo[0] = 2;
    fibo[26] = MAX + 1;
    sumfibo[0] = 2;
    idx = 1;
    
    // Store Even Fibonacci numbers and compute prefix sum
    while(b < MAX)
    {
        a += b;
        swap(a, b);
        if (b%2 == 0)
        {
            fibo[idx] = b;
            sumfibo[idx] = sumfibo[idx-1] + b;
            idx++;
        }
    }
    
    tot = idx - 1;
    cin >> T;
    for (i=0; i<T; i++)
    {
        cin >> N;
        f_ptr = upper_bound(fibo, &fibo[tot], N);
        idx = ((ull)f_ptr - (ull)fibo)/sizeof(ull);
        cout << sumfibo[idx-1] << endl;
    }
    
    return 0;
}  


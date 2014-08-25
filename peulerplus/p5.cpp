#include <algorithm>
#include <vector>
#include <set>
#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

typedef unsigned long long ull;
typedef unsigned int ui;

ui primes[13] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41};

int main()
{
    ui N, T, i, j, k;
    ull prod, pprod;
    cin >> T;
    
    for(i=0; i<T; i++)
    {
        cin >> N;
        prod = 1;
        j = 0;
        while(primes[j] <= N)
        {
            pprod = primes[j];
            while(pprod*primes[j] <= N)
                pprod *= primes[j];
            prod *= pprod;
            j++;
        }
        cout << prod << endl;
    }
    return 0;
}    


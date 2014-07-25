#include <algorithm>
#include <iostream>
#include <math.h>

using namespace std;
typedef unsigned long long ull;

int main()
{
    ull T, N, i;
    cin >> T;
    
    for(i=0; i<T; i++)
    {
        cin >> N;
        ull sum = (N*(N+1))/2;
        ull sum_sq = sum * (2*N + 1)/3;
        cout << pow(sum, 2) - sum_sq << endl;
    }
    
    return 0;
}


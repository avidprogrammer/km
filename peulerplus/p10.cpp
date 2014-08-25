#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

typedef unsigned long long ull;
const ull MAX = 1000000;

int not_prime[MAX+1];
vector <ull> primes;
ull sum_primes[MAX+1] = {0, 0, 2};

int main() {
    ull i, j, N, T;
    ull s= 0;
    memset(not_prime, 0, sizeof(not_prime));
    for (i=2; i<MAX; i++)
    {
        if (not_prime[i])
            continue;
        primes.push_back(i);
        for(j=2; i*j < MAX; j++)
            not_prime[i*j] = 1;
    }

    for (i=1; i< primes.size(); i++) {
        for (j=primes[i-1] + 1; j< primes[i]; j++)
            sum_primes[j] = sum_primes[j-1];
        sum_primes[j] = sum_primes[j-1] + primes[i];
    }
    
    cin >> T;
    for (i=0; i<T; i++) {
        cin >> N;
        cout << sum_primes[N] << endl;            
    }
    
    return 0;
}


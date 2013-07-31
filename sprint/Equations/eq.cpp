#include <iostream>
#include <vector>
#include <math.h>
#include <string.h> // memset
#include <stdlib.h>
#include <stdio.h>

#define MOD  1000007

using namespace std;

// Sieve of Erathostenes
static vector<long long>* generate_primes(long long limit)
{
    vector<long long> *primes = new vector<long long>;
    long long arr[1000000] = {0};

    for(long long i = 2; i <= limit; i++)
    {
        if (!arr[i])
        {
            primes->push_back(i);
            for(long long j = 2; i*j <= limit; j++)
                arr[j*i] = 1;
        }
    }
    return primes;
}


// Prime factorization of N! - Legendre's Theorem
static long long n_factorial_prime_fac(long long prime, long long N)
{
    long long factors = 0;
    long long exp = 1;
    long long cur_fac = pow(prime, exp);
    while (cur_fac <= N)
    {
       factors += N/cur_fac;
       exp++;
       cur_fac = pow(prime, exp);
    }
    return factors;
}


// Number of factors
static long long total_factors(vector<long long>* primes, long long N)
{
    long long total = 1;
    vector<long long> :: iterator it = primes->begin();

    while(it != primes->end())
    {
        long long fac = n_factorial_prime_fac(*it, N);
        if (fac)
        {
            total = (total * (2*fac + 1)) % MOD; 
        }
        it++;
    }
    return total; 
}

int main(int argv, char* argc[])
{
    vector<long long> *primes;
    vector<long long>::iterator it;
    long long N, res;

    cin >> N;
    primes = generate_primes(N);
    res = total_factors(primes, N);
    printf("%lld", res); 
    return 0;
}


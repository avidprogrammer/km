#include <algorithm>
#include <iostream>
#include <string.h>
#include <vector>

using namespace std;
typedef unsigned long long ull;

ull const MAX = 1000000;
vector <ull> primes;

bool is_prime[MAX+1];

int main() {
  ull T, N, i, j;
  
  memset(is_prime, 1, sizeof(is_prime));

  for(i=2; i<MAX+1; i++)
  {
    if(is_prime[i])
      primes.push_back(i);
    else
      continue;
    for(j=i*2; j<MAX+1; j=j+i)
    {
      is_prime[j] = 0;
    }
  }
  
  cin >> T;
  for(i=0; i<T; i++)
  { 
    cin >> N;
    cout << primes[N-1]<<endl;
  }
    
  return 0;
}


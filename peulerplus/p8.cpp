#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;
typedef unsigned long long ull;
char bignum[1001] = "";

ull N, T, K;

ull get_num(char num_str)
{
  return num_str - '0';
}

ull get_prod(ull* idx)
{
  ull prod = 1;
  ull cnt = 0;
  ull indx = *idx;
  ull num = 0;

  while(cnt < K && indx < N)
  {
    num = get_num(bignum[indx]);
    prod *= num;
    cnt++;
    if (num == 0)
    {
      prod = 1;
      cnt = 0;
    }
    indx++;
  }

  *idx = indx;
  return (cnt == K) ? prod : 0;
}  

int main()
{
  ull i, prod, max_prod, idx;

  cin >> T;
  for(idx=0; idx<T; idx++)
  {
    i = 0;
    cin >> N >> K;
    cin >> bignum;
    prod = get_prod(&i);
    max_prod = prod;
  
    for(;i<N; i++)
    {
        if (bignum[i] == '0')
        {
            prod = get_prod(&i);
            i--;
        }
        else
            prod = prod/(get_num(bignum[i-K])) * get_num(bignum[i]);
        if (prod > max_prod)
            max_prod = prod;
    }
    cout << max_prod << endl;
  }
  return 0;
}  


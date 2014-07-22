#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <set>
#include <vector>

using namespace std;

typedef unsigned long long ull;
set <ull> palins;
set <ull> :: iterator si;

int is_palin(ull prod)
{
  ull n = prod;
  int arr[6] = {0, 0, 0, 0, 0, 0};
  int idx = 5;
  while (n > 0)
  {
    arr[idx--] = n%10;
    n = n/10;
  }


  return (arr[5] == arr[0] &&
          arr[4] == arr[1] &&
          arr[3] == arr[2]);
}  

int main()
{
  ull prod, i, j, T, N;

  for(i=999; i>99; i--)
  for(j=i; j>99; j--)
  {
    prod = i*j;
    if (is_palin(prod))
    {
      palins.insert(prod);
    }
  }

  cin >> T;
  for(i=0; i < T; i++)
  {
    cin >> N;
    si = palins.upper_bound(N);
    si--;
    cout << *si << endl;
  }

  return 0;
}  

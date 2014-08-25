#include <iostream>
#include <math.h>
#include <set>

using namespace std;
typedef unsigned long long ull;

unsigned numFactors(unsigned num) {
  unsigned sqrtNum = (unsigned) sqrt(num);
  set <unsigned> factors;
  unsigned i;

  if (num % 2 == 0)
    num /= 2;
  factors.insert(1);
  factors.insert(num); 
  for (i = 2; i <= sqrtNum; i++) {
    if (num % i == 0) {
      factors.insert(i);
      factors.insert(num/i);
    }
  }
  return factors.size();
}

int main() {
  ull sumIdx, i;
  unsigned N, T;

  cin >> T;
  for (i = 0; i < T; i++)
  {
    sumIdx = 2;
    cin >> N;
    while (1) {
      if ((numFactors(sumIdx) * numFactors(sumIdx + 1)) > N) {
        cout << ((sumIdx + 1) * sumIdx)/2 << endl;
        break;
      }
      sumIdx++;
    }
  }
    
 return 0;
}

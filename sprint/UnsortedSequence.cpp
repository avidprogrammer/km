#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class UnsortedSequence
{
  public: vector <int> getUnsorted(vector <int> s)
  {
    int i = s.size() - 1;
    sort(s.begin(), s.end());
    while(i && (s[i] == s[i-1]))
      i--;
    if (i == 0)
      return vector <int> ();
    swap(s[i], s[i-1]);
    return s;
  }
};

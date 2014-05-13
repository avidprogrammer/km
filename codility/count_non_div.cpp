#include <map>
#include <vector>
#include <set>
#include <string.h>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> &A) {
    int max = *max_element(A.begin(), A.end());
    int sieve[max+1];

    vector <int> res;
    vector <int> :: iterator vi;

    map<int, int> div_rep; // Occurences of a divisor

    set <int> divisors; // Unique divisors
    set<int> :: iterator d_itr;

    int sz = A.size();
    int i;
    
    memset(sieve, 0, sizeof(sieve));
    // Initialize divisors, divisor occurence
    for (i=0; i < sz; i++)
    {
        divisors.insert(A[i]);
        if (div_rep.find(A[i]) == div_rep.end())
            div_rep.insert(pair<int, int>(A[i], 0));
        div_rep[A[i]]++;
    }
   
    // For each divisor, sieve to tag its multiples
    for(d_itr=divisors.begin(); d_itr != divisors.end(); d_itr++)
    {
        int div = *d_itr;
        for (i=div; i <= max; i=i+div)
        {
            sieve[i] += (div_rep[div]);
        }
            
    }
    
    for (vi=A.begin(); vi != A.end(); vi++)
        res.push_back(sz - sieve[*vi]);
    
    return res;
}

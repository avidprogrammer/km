#include <algorithm>
#include <vector>
#include <set>
#include <iostream>
#include <string.h>

#define MAX 50000
vector<int> primes;
set<int> semi_primes;
int sp_cnt[MAX];

void get_primes(vector<int> &primes)
{
    bool not_prime[MAX];
    memset(not_prime, 0, sizeof(not_prime));
    
    for(int i=2; i<MAX; i++)
    {
        if (not_prime[i])
          continue;
        primes.push_back(i);
        for(int j=2; j*i<MAX; j++)
        {
            not_prime[j*i] = 1;
        }
    }
}

void get_semi_primes(set<int> &sp)
{
    vector<int> :: iterator si1 , si2;
    for(si1 = primes.begin(); si1 != primes.end(); si1++)
    {
        for(si2=si1; ((unsigned long)(*si1 * *si2) <= MAX); si2++)
        {
            sp.insert(*si1 * *si2);
        }

    }
}

vector<int> solution(int N, vector<int> &P, vector<int> &Q) {
    vector <int> soln;
    get_primes(primes);
    int idx;
    
    get_semi_primes(semi_primes);
    memset(sp_cnt, 0, sizeof(sp_cnt));
    sp_cnt[0] = 0;
    set<int>:: iterator si = semi_primes.begin();
    
    for(idx = 1; idx <= MAX; idx++)
    {
        sp_cnt[idx] = sp_cnt[idx-1];
        if (si != semi_primes.end() && *si <= idx) 
        {    si++;
             sp_cnt[idx]++;
        }
    }

    for(idx = 0; idx < P.size(); idx++)
        soln.push_back(sp_cnt[Q[idx]] - sp_cnt[P[idx] - 1]);

    return soln;
}


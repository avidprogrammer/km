#include <algorithm>
#include <vector>
using namespace std;

int get_gcd(int x, int y)
{
    if (x<y)
      swap(x, y);
      
    while(x%y != 0)
    {
        x = x%y;
        swap(x, y);
    }
    
    return y;
}

int has_common_divisors(int a, int b)
{
    int gcd = get_gcd(a, b);
    int g_a = gcd, g_b = gcd;

    while(a != 1 && g_a != 1)
    {
        g_a = get_gcd(g_a, a);
        a = a/g_a;
        //cout << "a : " << a << " g_a" << g_a << endl;
    }
    
    while(b != 1 && g_b != 1)
    {
        g_b = get_gcd(g_b, b);
        b = b/g_b;
        //cout << "b : " << b << " g_b" << g_b << endl;        
    }
    
    return ((a == 1) && (b == 1));
}

int solution(vector<int> &A, vector<int> &B) {
    unsigned idx;
    unsigned res = 0;
    
    for(idx=0; idx<A.size(); idx++)
    {
        if (has_common_divisors(A[idx], B[idx]))
            res++;
    }
    
    return res;
}


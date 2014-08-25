#include <iostream>
#include <vector>
typedef unsigned long long ull;

using namespace std;

int main()
{
    ull i, t, n, sum = 0;
    ull p3, p5, p15, s5, s3, s15;
    
    cin >> t;
    for (i=0; i<t; i++)
    {
        cin >> n;
        p3 = n/3;
        p5 = n/5;
        p15 = n/15;
        if (n%3 == 0)
            p3 -= 1;
        if (n%5 == 0)
            p5 -= 1;
        if(n%15 == 0)
            p15 -= 1;
        s5 = ((p5*5 + 5) * p5)/2;
        s3 = ((p3*3 + 3) * p3)/2;
        s15 = ((p15*15 + 15) * p15)/2;
        cout << s5 + s3 -s15 << endl;
    }
    return 0;
}  


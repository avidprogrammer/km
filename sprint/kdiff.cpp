#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main (int argc, char* argv[])
{
    long N, Q;
    long i, j, count = 0;
    vector <long> nums;
    vector <long>:: iterator it1, it2, itl, ith;

    cin >> N >> Q;
    it1 = nums.begin();
    long temp;
    for (i = 0; i < N; i++)
    {
        cin >> temp;
        nums.push_back(temp);
    }
    // * Sort the input numbers
    // * Once sorted for every element, 
    //    find the upper and lower bound of the numbers that have
    //    atleast K difference. 
    // * Iterate in the subsequence to find count of  numbers with K difference
    sort(nums.begin(), nums.end());
    for (it1 = nums.begin(); it1 != nums.end(); it1++)
    {
        itl = lower_bound(it1, nums.end(), *it1 - Q-1);
        ith = lower_bound(it1, nums.end(), *it1 + Q+1);
        cout << *itl << *ith << endl;
        for (it2 = itl; *it2 < *ith; it2++)
        {
            long long val = *it1 - *it2;
            if (val == Q || val == -Q)
                count++;
        }
    }
    cout << count;
    return 0;
}

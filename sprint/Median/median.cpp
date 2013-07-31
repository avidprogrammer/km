#include<iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <math.h>

using namespace std;

void add_to_seq (int ele, vector <int> &seq)
{
    int size = seq.size();
    vector <int>::iterator it;

    if (size == 0)
    { // First element
        seq.push_back(ele);
        return;
    }
   
    it = lower_bound(seq.begin(), seq.end(), ele);
    seq.insert (it, ele);
}

int remove_from_seq (int ele, vector <int> &seq)
{
    int size = seq.size();
    vector <int>::iterator it = seq.begin();

    // Empty list
    if (size == 0)
        return -1;
    
    it = find(seq.begin(), seq.end(), ele);
    if (it != seq.end())
    {
        seq.erase(it);
        if (size == 1)
            return -1;
    }
    else
        return -1;
    
    return 0;
}

double calc_median (vector <int> &seq)
{
    int size = seq.size();
   
    if (size == 1)
        return seq[0];
    else if (size%2 != 0)
        return seq[size/2];
    else   
        return ((long long)seq[size/2 - 1] + (long long)seq[size/2])/2.0;
}

int modify_seq (const string operation, int ele, vector <int> &seq)
{
    if (!operation.compare("a"))
        add_to_seq(ele, seq);
    else if (!operation.compare("r"))
        return remove_from_seq(ele, seq);
    else
        return -1;
    return 0;
}

int main(){
    int N;
    cin >> N;
    vector<int> seq;
        
    string s[N];	
    int x[N];

    for(int i = 0; i < N; i++)
    {
        cin >> s[i] >> x[i];
        int result = modify_seq(s[i], x[i], seq);
        if (result != -1)
        {
            double median = calc_median (seq);
            if (fmod(median, 1) != 0)
                printf("%0.01lf\n", median);
            else
                printf("%0.0lf\n", median);
        }
        else 
            cout << "Wrong!\n";
    }

    return 0;
}

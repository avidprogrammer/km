#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

class GUMIAndSongsDiv1 
{
  public:
  int maxSongs(vector<int> duration, vector<int> tone, int T)
  {
    int N = tone.size();
    int i, j, k, max_songs = 0;

    for (i=0; i<N; i++)
    {
      for (j=0; j<N;j++)
      {
        int t = T - (tone[i] - tone[j]);
        int num_songs = 0;
        multiset<int> dur;
        for (k=0; k<N; k++)
        {
          if (tone[k] <= tone[i] && tone[k] >= tone[j])
            dur.insert(duration[k]);
        }  
        for(int k : dur)
        {
          cout << k << " " << t << endl;
          if (k <= t)
          {
            t -= k;
            num_songs++;
          }
        }        
        max_songs = max(max_songs, num_songs);
      }
    }
    return max_songs;
  }
};

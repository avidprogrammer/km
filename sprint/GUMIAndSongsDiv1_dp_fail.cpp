#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int length = 1;
const int t_rem = 0;

typedef struct {
  int tone;
  int dur;
}Song;

bool SongComp(Song s1, Song s2)
{
  return (s1.tone < s2.tone);
}

class GUMIAndSongsDiv1
{
  public:
  int maxSongs(vector<int> duration, vector <int> tone, int T)
  {
    int maxsongs = 0, i, j;
    unsigned long N = tone.size();
    long dp[N][2];
    vector <Song> songs;
    
    for (i=0; i < N; i++)
    {
      Song s = {.tone = tone[i], .dur = duration[i]};
      songs.push_back(s);
    }
    
    sort(songs.begin(), songs.end(), SongComp);
      
    for (i=0; i<N; i++)
    {
        dp[i][length] = 1;
        dp[i][t_rem] = T - songs[i].dur;

      for (j=0; j<i; j++)
      {
        int tot_time = songs[i].tone - songs[j].tone + songs[i].dur;
        if (dp[j][t_rem] >= tot_time &&
            dp[j][length] >= dp[i][length])
        {
            dp[i][length] = dp[j][length] + 1;
            dp[i][t_rem] = dp[j][t_rem] - tot_time;
        }
      }
    }

    for (i=0; i<N; i++)
    {
      if(dp[i][length] > maxsongs)
        maxsongs = dp[i][length];
    }
    return maxsongs;
  }
};

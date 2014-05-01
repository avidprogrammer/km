#include<math.h>

int get_peaks(int A[], int N, int peaks[])
{
    int num_peaks = 0;
    int i;
    
    for (i=1; i<(N-1); i++)
    {
        if ((A[i] > A[i-1]) && (A[i] > A[i+1]))
            peaks[num_peaks++] = i;
    }

    return num_peaks;
}

int check_flag_pos(int peaks[], int tot_peaks, int num_flags)
{
    int min_d = num_flags;
    int st_pos = peaks[0];
    int cur_peak_idx = 0;
    int cur_peak;
    while((cur_peak_idx < tot_peaks) && num_flags)
    {
      num_flags--;
      cur_peak = peaks[cur_peak_idx];
      while(cur_peak < (st_pos + min_d))
      {
          cur_peak_idx++;
          cur_peak = peaks[cur_peak_idx];
      }
      st_pos = cur_peak;
    }
    
    return (num_flags == 0);
}

int solution(int A[], int N) {
    int peaks[N/2+1];
    int num_flags = 0, tot_peaks = 0;

    tot_peaks = get_peaks(A, N, peaks);
    num_flags = (tot_peaks > sqrt(N)) ? sqrt(N)+1 : tot_peaks;
    while(num_flags)
    {
        if(check_flag_pos(peaks, tot_peaks, num_flags))
            break;
        num_flags--;
    }
    
    return num_flags;
}


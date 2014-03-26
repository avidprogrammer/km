int solution(int X, int A[], int N)
{
  unsigned long i;
  unsigned long *marker = malloc(sizeof(unsigned long) * (X+1));
  unsigned long sum = 0;
  unsigned long exp_sum = (X) * (X+1)/2;

  memset(marker, 0, sizeof(unsigned long) * (X+1));
  
  for (i = 0; i < N; i++)
  {
    if (A[i] <= X && !marker[A[i]])
    {
      marker[A[i]]++; // Keep track of position where leaves have fallen
      sum += A[i];
      if (sum == exp_sum)
      return i;
    }
  }
  return -1;
}

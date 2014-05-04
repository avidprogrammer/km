#include <stdio.h>
#include <limits.h>
#include <malloc.h>
#include <string.h>

int main()
{
  int i, j, V, N, val;
  int *Sum, *Val;
  
  scanf("%d",&N);
  scanf("%d",&V);

  Sum = malloc(sizeof(int) * N);
  for(i=0; i<N; i++)
    Sum[i] = INT_MAX;

  Val = malloc(sizeof(int) * V);
  for (i=0; i<V; i++)
    scanf("%d",&Val[i]);

  Sum[0] = 0;
  for (i=1; i<N; i++)
    for (j=0; j<V; j++)
    {
      val = Val[j]; 
      if (val <= i && ((Sum[i-val]+1) < Sum[i]))
        Sum[i] = Sum[i-val]+1;
    }

  for (i=0; i<N; i++)
    printf("%d %d\n",i, Sum[i]);
  return 0;
}

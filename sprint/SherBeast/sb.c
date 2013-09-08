#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define SEED_SZ 100000

int debug= 0;

void pr_seed(unsigned short seed[], unsigned long sz)
{
    int i;
    for (i = sz - 1; i >= 0 ; i--)
        printf("%d", seed[i]);
    printf("\n");        
}

void debug_pr_seed(unsigned short seed[], unsigned long sz)
{
    if (debug)
        pr_seed(seed, sz);
}

int generate_next(short unsigned seed[], unsigned long sz)
{
    int res_idx = 1;
    int i, ret = 0;

    if (seed[0] == 5)
    {
        seed[0] = 3;
    }
    else
    {
        while (res_idx < sz && (seed[res_idx] == 3))
            res_idx++;
        seed[res_idx] = 3;
       
       // reset lower indexes
       for (i = 0; i < res_idx; i++)
           seed[i] = 5;
        
       if (res_idx == sz)
           ret = -1;
    }
    return ret;
}

bool is_valid(unsigned short seed[], unsigned long sz)
{
    unsigned long i;
    unsigned long cnt_3 = 0, cnt_5 = 0;
    for (i = 0; i < sz; i++)
    {
        if (seed[i] == 3)
            cnt_3++;
        else
            cnt_5++;
    }

    return !((cnt_3 % 5) || (cnt_5 % 3));
}

void highest_decent_number(void)
{
    unsigned short seed[SEED_SZ] =  {0};
    unsigned long N = 0;
    int i;
    int ret = 0;

    scanf("%lu", &N);

    // initialize seed
    for (i = 0; i < N; i++)
    {
        seed[i] = 5;
    }
    
    while (ret != -1)
    {
        if (is_valid(seed, N))
        {
            pr_seed(seed, N);
            return;
        }
        debug_pr_seed(seed, N);
        ret = generate_next(seed, N);
    }
    printf("%d\n", -1);
}

int main() {

    short T = 0, i;

    scanf("%hd", &T);

    for (i = 0; i < T; i++)
    {
        highest_decent_number();
    }
    return 0;
}


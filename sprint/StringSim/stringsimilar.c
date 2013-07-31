#include <stdio.h>
#include <string.h>

int parse_string(char* str)
{
    int len = strlen(str);
    int sum = len;
    int i, j, isum = 0;
    for (i = 1; i < len; i++)
    {
        isum = 0;
        for (j = 0; j < len; j++)
        {
            if (str[j] != str[i + j])
                break;
            isum++;
        }
        sum += isum;
    }
    return sum;
}

int main(int argc, char* argv[])
{
    int i, N;
    char str[100001];
    
    scanf("%d", &N);
    for (i = 0; i < N; i++)
    {
        int sum = 0;
        scanf("%s", str);
        //printf("*** %s %p***\n", str, &sum);
        sum += parse_string(str); 
        printf("%d\n", sum);
    }

    return 0;
}

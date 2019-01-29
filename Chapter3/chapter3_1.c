#include <stdio.h>
#include <time.h>

#define VLEN 10000
#define TICK(X) clock_t X = clock()
#define TOCK(X) printf("%s: %g sec\n", (#X), (double)(clock() - (X)) / CLOCKS_PER_SEC)

int binsearch(int x, int v[], int n);
int binsearch_fast(int x, int v[], int n);

int main(void)
{
    int v[VLEN];
    int x = 999;

    for(int i = 0; i < VLEN; ++i)
    {
        v[i] = i;
    }

    TICK(TIME_A);
    printf("%d\n", binsearch(x, v, VLEN));
    TOCK(TIME_A);

    TICK(TIME_B);
    printf("%d\n", binsearch_fast(x, v, VLEN));
    TOCK(TIME_B);

    return 0;
}

int binsearch(int x, int v[], int n)
{
    int low, mid, high;
    
    low = 0;
    
    high = n - 1;
    while(low <= high)
    {
        mid = (low + high) / 2;
        if(x < v[mid])
        {
            high = mid - 1;
        }
        else if(x > v[mid])
        {
            low = mid + 1;
        }
        else
            return mid;
    }
    return -1;
}

int binsearch_fast(int x, int v[], int n)
{
    int low, mid, high;
    
    low = 0;
    high = n - 1;

    if(x == v[low])
    {
        return low;
    }
    else if(x == v[high])
    {
        return high;
    }

    while(low < high)
    {
        mid = (low + high) / 2;
        if(x < v[mid])
        {
            high = mid;
        }
        else
        {
            low = mid + 1;
        }
    }

    if(low == high)
    {
        return low - 1;
    }

    return -1;
}
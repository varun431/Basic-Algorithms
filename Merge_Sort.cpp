#include <bits/stdc++.h>
using namespace std;

int SIZE;

void mergesort(int *a, int lbeg,int lend, int rbeg, int rend)
{
    int pa = lbeg, pb = rbeg, pt = lbeg, temp[SIZE];
    while(pa <= lend && pb <= rend)
    {
        if(a[pa] < a[pb])
        {
            temp[pt++] = a[pa++];
        }
        else
        {
            temp[pt++] = a[pb++];
        }
    }
    if(pa > lend)
    {
        while(pb <= rend)
        {
            temp[pt++] = a[pb++];
        }
    }
    else
    {
        while(pa <= lend)
        {
            temp[pt++] = a[pa++];
        }
    }
    for(pt = lbeg; pt <= rend; pt++)
    {
        a[pt] = temp[pt];
    }
}

void merge(int *a, int beg, int end)
{
    if(beg < end)
    {
        int mid = (beg + end)/2;
        merge(a, beg, mid);
        merge(a, mid+1, end);
        mergesort(a, beg, mid, mid+1, end);
    }
}

int main()
{
    SIZE = 6;
    int *a = new int[SIZE];
    a[0] = 5098, a[1] = 48798, a[2] = 3766, a[3] = 17687, a[4] = 276, a[5] = 6876767;
    merge(a,0,SIZE-1);
    for(int i=0; i<SIZE; i++)
    {
        printf("%d\t",a[i]);
    }
}

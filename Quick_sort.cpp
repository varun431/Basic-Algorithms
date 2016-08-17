#include <bits/stdc++.h>
#define LL long long
using namespace std;

void quicksort(LL* a, LL first, LL last)
{
    LL temp,pivot,i,j;
    if(first<last)
    {
        pivot = last;
        i = first, j = first;
        while(i<last)
        {
            if(a[i] < a[pivot])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
                j++;
            }
            i++;
        }
        temp = a[j];
        a[j] = a[pivot];
        a[pivot] = temp;
        quicksort(a,first,j-1);
        quicksort(a,j+1,last);
    }
}

int main()
{
    LL size,i;
    scanf("%lli",&size);
    LL* a = new LL[size];
    for(i=0; i<size; i++)
    {
        scanf("%lli",&a[i]);
    }
    quicksort(a,0,size-1);
    for(i=0; i<size; i++)
    {
        printf("%lli ",a[i]);
    }
}

#include <bits/stdc++.h>
#define max 100000000
using namespace std;
#define gP(n) (mark[n>>6]&(1<<((n>>1)&31)))
#define rP(n) (mark[n>>6]&=~(1<<((n>>1)&31)))
long int mark[max/64];
vector<long int> prime;

void opt_sieve()
{
    memset(mark, -1,sizeof(mark));
    prime.push_back(2);
    long int i,j,sqt = sqrt(max)+1;
    for(i=3;i<sqt;i+=2)
        if(gP(i))
        {
            long int i2 = i<<1;
            for(j=i*i;j<max;j+=i2)
                rP(j);
        }
    for(i=3;i<max;i+=2)
        if(gP(i))
            prime.push_back(i);
}

bool checkPrime (int x) {return (x&1)&&gP(x); }

int main()
{
    opt_sieve();
    for(int i=0;i<prime.size();i++)
        printf("%li\n",prime[i]);
}

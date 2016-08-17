#include <bits/stdc++.h>
#define max 1000007
#define pb push_back
#define sf scanf
#define pf printf
#define ll long long
using namespace std;

const int L1D_CACHE_SIZE = 32768;
vector<int> p;
int endind;

void segmented_sieve(int limit)
{
  p.pb(2);
  int segment_size = L1D_CACHE_SIZE;
  int sqrt = (int)std::sqrt((double) limit);
  int count = (limit < 2) ? 0 : 1;
  int s = 2;
  int n = 3;
  vector<char> sieve(segment_size);
  vector<char> is_prime(sqrt + 1, 1);
  for (int i = 2; i * i <= sqrt; i++)
    if (is_prime[i])
      for (int j = i * i; j <= sqrt; j += i)
        is_prime[j] = 0;
  vector<int> primes;
  vector<int> next;
  for (int low = 0; low <= limit; low += segment_size)
  {
    fill(sieve.begin(), sieve.end(), 1);
    int high = min(low + segment_size - 1, limit);
    for (; s * s <= high; s++)
    {
      if (is_prime[s])
      {
        primes.push_back((int) s);
          next.push_back((int)(s * s - low));
      }
    }
    for (size_t i = 1; i < primes.size(); i++)
    {
      int j = next[i];
      for (int k = primes[i] * 2; j < segment_size; j += k)
        sieve[j] = 0;
      next[i] = j - segment_size;
    }
    for (; n <= high; n += 2)
      if (sieve[n - low])
      {
        p.push_back(n);
        count++;
      }
  }
  endind = count;
}

inline ll read()
{
    ll input=0;
    char c = getchar();
    for(; c>='0' && c<='9'; c=getchar())
    {
        input = (input<<3) + (input<<1) + (c&15);
    }
    return input;
}

inline void write(ll n)
{
    char out[32],i=0;
    if(n==0)
        putchar('0');
    while(n!=0)
    {
        out[i++] = n%10 + '0';
        n /= 10;
    }
    while(i!=0)
    {
        putchar(out[--i]);
    }
    putchar('\n');
}

long long mul(long long a,long long b,long long c);
long long mod(long long a,long long b,long long c){
    long long x=1,y=a;
    while(b > 0){
        if(b%2 == 1){
            x=mul(x,y,c);
        }
        y = mul(y,y,c);
        b /= 2;
    }
    return x%c;
}

long long mul(long long a,long long b,long long c){
    long long x = 0,y=a%c;
    while(b > 0){
        if(b%2 == 1){
            x = (x+y)%c;
        }
        y = (y*2)%c;
        b /= 2;
    }
    return x%c;
}

int Miller(long long p,long long it = 20){
    if(p<2){
        return 0;
    }
    if(p!=2 && p%2==0){
        return 0;
    }
    long long s=p-1;
    while(s%2==0){
        s/=2;
    }
    long long i;
    for(i=0;i<it;i++){
        long long a=rand()%(p-1)+1,tt=s;
        long long md=mod(a,tt,p);
        while(tt!=p-1 && md!=1 && md!=p-1){
            md=mul(md,md,p);
            tt *= 2;
        }
        if(md!=p-1 && tt%2==0){
            return 0;
        }
    }
    return 1;
}

int main()
{
    segmented_sieve(max);
    int t;
    t = read();
    while(t--)
    {
        ll n, ans=1, i=0;
        n = read();
        while(i < endind)
        {
            if(p[i]*p[i]*p[i] > n)
                break;
            int count = 1;
            while(n%p[i])
            {
                n = n/p[i];
                count++;
            }
            ans = ans*count;
            i++;
        }
        int temp = sqrt(n);
        ll temp2 = temp*temp;
        if(Miller(n))
            ans *= 2;
        else if(temp2 == n && Miller(temp))
            ans *= 3;
        else if(n != 1)
            ans *= 4;
        write(ans);
    }
}

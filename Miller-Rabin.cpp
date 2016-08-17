#include<bits/stdc++.h>
using namespace std;

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

int Miller(long long p,long long it){
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
    int t;
    cin>>t;
    while(t--) {
        long long test , n;
        scanf("%lld" , &n);
        int fl = Miller(n , 20);
        if(fl)
                printf("YES number is Prime\n");
        else
                printf("NO Number is not Prime\n");
    }
	return 0;
}

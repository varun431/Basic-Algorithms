#include <bits/stdc++.h>
#define LL unsigned long long
using namespace std;

inline LL add(LL x, LL y)
{
    // Iterate till there is no carry
    while (y != 0)
    {
        // carry now contains common set bits of x and y
        LL carry = x & y;

        // Sum of bits of x and y where at least one of the bits is not set
        x = x ^ y;

        // Carry is shifted by one so that adding it to x gives the required sum
        y = carry << 1;
    }
    return x;
}

inline LL mul(LL a, LL b)
{
   LL result;
   result=0;
   while(b != 0)               // Iterate the loop till b==0
   {
        if (b&01)                // Bitwise &  of the value of b with 01
        {
          result = add(result,a);     // Add a to result if b is odd .
        }
        a<<=1;                   // Left shifting the value contained in 'a' by 1
                                // multiplies a by 2 for each loop
        b>>=1;                   // Right shifting the value contained in 'b' by 1.
   }
   return result;
}

int main()
{
    LL a=123456789,b=1234567;
    cout<<mul(a,b);
}

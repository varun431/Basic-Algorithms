#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>
using namespace std;

int main ()
{
	//Create the various different variables required
	int limit = 100000000;
	int root = ceil(sqrt(limit));
	//cout<<"Hi\n";
	bool *sieve = new bool[limit];
	//cout<<"Hi\n";
	//int *primes = new int[(limit/2)+1];
	vector<int> primes;
	vector<int>::iterator it;
	//cout<<"Hi\n";
	int insert = 2;
	primes.push_back(2);
	primes.push_back(3);
	//cout<<"Hi\n  ";
	for (int z = 0; z < limit; z++) sieve[z] = false; //Not all compilers have false as the default boolean value
	for (int x = 1; x <= root; x++)
	{
		for (int y = 1; y <= root; y++)
		{
			//Main part of Sieve of Atkin
			int n = (4*x*x)+(y*y);
			if (n <= limit && (n % 12 == 1 || n % 12 == 5)) sieve[n] ^= true;
			n = (3*x*x)+(y*y);
			if (n <= limit && n % 12 == 7) sieve[n] ^= true;
			n = (3*x*x)-(y*y);
			if (x > y && n <= limit && n % 12 == 11) sieve[n] ^= true;
		}
	}
	//Mark all multiples of squares as non-prime
	for (int r = 5; r <= root; r++) if (sieve[r]) for (int i = r*r; i < limit; i += r*r) sieve[i] = false;
	//Add into prime array
	for (int a = 5; a < limit; a++)
	{
		if (sieve[a])
		{
			primes.push_back(a);
		}
	}
	//The following code just writes the array to a file
	int i,k,j,count=0;
    //vector<long int>::iterator it;
    for(it=primes.begin();it!=primes.end();++it)
    {
        count++;
        //printf("%li\n",prime.back());
        if(count%100==1)
        {
            printf("%d\n",*it);
        }
    }
}

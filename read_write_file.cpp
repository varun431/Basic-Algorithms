#include <bits/stdc++.h>
using namespace std;

int main()
{
    ifstream f1("test1.txt"),f2("test2.txt");
    ofstream f3("test3.txt");
    string read1, read2;
    for(int i=1;i<=10000;i++)
    {
        getline(f1, read1);
        getline(f2, read2);
        if(read1.compare(read2) != 0)
            f3<<i<<"\n";
    }
    f1.close();
    f2.close();
    f3.close();
}

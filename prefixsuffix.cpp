#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--) {
        string str;
        cin>>str;
        int size=str.size();
        int k,l,m,flag=1;
        if(size&1) {
            k=size/2 +1;
        }
        else {
            k=size/2;
        }
        while(k<size) {
            l=0,m=k;
            while(m<size) {
                if(str[l]==str[m])
                {
                    m++;l++;
                }
                else break;
            }
            if(m==size) {
                flag=0;
                cout<<l<<endl;
                break;
            }
            k++;
        }
        if(flag)
            cout<<"0\n";
    }
}

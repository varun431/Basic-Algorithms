#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--) {
        string s1,s2;
        cin>>s1>>s2;
        int len1,len2,ans=0;
        len1=s1.size();
        len2=s2.size();
        int lcs[len1+1][len2+1];
        for(int i=0; i<=len1; i++) {
            for(int j=0; j<=len2; j++) {
                if(i == 0 || j == 0)
                    lcs[i][j] = 0;
                else {
                    if(s1[i-1] == s2[j-1]) {
                        lcs[i][j] = lcs[i-1][j-1]+1;
                        ans = (ans, lcs[i][j]);
                    }
                    else {
                        lcs[i][j] = 0;
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
}

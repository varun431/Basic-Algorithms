#include <bits/stdc++.h>
using namespace std;

int main() {
   int n, r,cnt=0;
   cin >> n;
   cin >> r;

   vector<bool> v(n);
   fill(v.begin()+n-r, v.end(), true);

   do {
       for (int i = 0; i < n; ++i) {
           if (v[i]) {
               cout << (i+1) << " ";
           }
       }
       cnt++;
       cout << "\n";
   } while (next_permutation(v.begin(), v.end()));
   cout<<cnt<<endl;
}

#include <assert.h>
#include <bits/stdc++.h>
using namespace std;
int answer[32];

void toBase(int n, int b, int* answer) {
    assert(b > 1);
    int q = n;
    int k = 0;
    while (q != 0) {
        answer[k] = q % b;
        q /= b;
        cout<<answer[k]<<"\t";
        ++k;
    }
}

int main() {
    int answer[32];
    int n = 100;
    int b = 3;
    toBase(n, b, answer);
    return 0;
}

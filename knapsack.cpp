#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n,t;
    int k;
    int a[2000];
    int minRem[2001];
    cin >> t;
    while(t--){
        cin >> n >> k;
        // take input
        for(int i=0; i<n; i++) cin >> a[i];
        // initialize min remainder for a given i to i
        // i.e. we dont have a number to get even 0
        // minRem[0] = 0
        for(int i=0; i<=k; i++) minRem[i] = i;
        // Now using dynamic programming
        // we go from 1 to k
        for(int i=1; i<=k; i++){
            for(int j=0; j<n; j++){
                if(a[j]>i) continue;
                if(minRem[i] > minRem[i%a[j]])
                       minRem[i] = minRem[i%a[j]];
            }
        }
        cout << k - minRem[k] << endl;
    }
    return 0;
}
// Example
/*
1
4 37
3 2 4 10
first we will get 0 for multiples of 2, 3, 4. So
minRem[2] = minRem[3] = minRem[4] = 0
but >> when we have i=7 and we a[j] = 4,
    >> minRem[7] = minRem[7%a[j]] = minRem[3] = 0;
    >> so basically we can form 7
and when we have 
  >> when we have i=37 and we a[j] = 10
  >> minRem[37] = minRem[37%a[j]] = minRem[7] = 0;
  >> so basically we can form 37

*/

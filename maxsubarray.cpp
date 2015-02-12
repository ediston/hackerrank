#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int a[100000];
    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        // take input
        for(int i=0; i<n; i++) {
            cin >> a[i];
        }
        long long  maxncs = 0;;
        long long  bestSum = 0;
        long long currentSum = 0;
        int currentInd = 0;
        int bestIndexStart = 0;
        int bestIndexEnd = 0;
        for(int i=0; i<n; i++){
            // if this number is positive just add to the sum
            if(a[i]>0) maxncs += a[i];
            // check if sum is currently 0 and new sum could be bigger than 0
            if(currentSum == 0 && currentSum + a[i] > 0){
                // then add this sum and save this index as currendsum was 0 till now
                // this index could be future bestindexbegin if currentsum will be greater than 
                // best sum
                currentSum = currentSum + a[i];
                currentInd = i;
            }else if(currentSum + a[i] > 0){
                // if currentsum is already >0 and then just add the new number
                currentSum = currentSum + a[i];
            }else{
                // else if sum is <0 .. then we dont want to include this number
                // next possible best index will be from next index i.e. i+1
                currentSum = 0;
            }
            // at every step keep checking for the best sum
            // update the bestsum start and end index.
            if(currentSum > bestSum){
                    bestSum = currentSum;
                    bestIndexStart = currentInd;
                    bestIndexEnd = i;
            }
        }
        // Incase there is not even a single positive number
        // then take the least negative or the biggest number 
        // example in (-13, -2, -3, -6) -2 is the biggest or the least negative number
        if(maxncs==0){
            maxncs = -10001;
            for(int i=0; i<n; i++){
                if(maxncs<a[i])
                    maxncs = a[i];
            }
            bestSum = maxncs;
        }
        // show output
        cout << bestSum << " " << maxncs << endl;
    }
    return 0;
}

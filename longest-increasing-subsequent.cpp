 
//https://www.hackerrank.com/challenges/longest-increasing-subsequent
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<long > lis;
long n;

long getMin(){
    return lis[0];
}

long getMax(){
    if(n==0) return -1;
    return lis[n-1];
}

void replace(long x){
    long lo = 0;
    long hi = n-1;
    long mid;
    while(lo<hi){
        mid = (lo+hi)/2;
        if(lis[mid]>x){
            hi = mid;
        }else{
            lo = mid+1;
        }
    }
    if(lo>1 && lis[lo-1]==x) return;
    lis[lo] = x;
}

int main() {
    long m;
    long a;
    cin >> m;
    n = 0;
    for(long i=0; i<m;i++){
        cin >> a;
        if(a>getMax()) {
            lis.push_back(a);
        }else{
           if(a<=getMin()) lis[0] = a;
           else replace(a);
        }
        n =  lis.size();
    }
    cout << lis.size() << endl;
    return 0;
}

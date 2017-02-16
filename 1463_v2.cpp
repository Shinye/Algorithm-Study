//
//  main.cpp
//  Algorithm_time
//
//  Created by Shinye Song on 2016. 10. 4..
//  Copyright © 2016년 Shinye Song. All rights reserved.


#include <iostream>
using namespace std;

int dp[1000001];

int go(int n){
    if(n==1) { return 0; }
    if(dp[n]>0) { return dp[n]; }
    
    dp[n] = go(n-1)+1;
    
    if(n%3 == 0) {
        int temp = go(n/3)+1;
        if(temp<dp[n]) {
            dp[n] = temp;
        }
    }
    
    if(n%2 == 0){
        int temp = go(n/2)+1;
        if (temp<dp[n]){
            dp[n] = temp;
        }
    }
    return dp[n];
}

int main(){
    int n;
    cin >> n;
    cout << go(n) << '\n';
    return 0;
}

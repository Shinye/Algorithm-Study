#include <iostream>
using namespace std;


int dp[1000001];


int main(){
    int n;int i;
    cin>>n;
    
    dp[0] = 1;
    dp[1] = 1;
    for(i = 2; i<=n; i++ ){
        dp[i] = dp[i-1]+dp[i-2];
        dp[i] %= 10007;
    }
    cout<<dp[n]<<endl;
}

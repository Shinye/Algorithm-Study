/*
 문자열의 모든 순열의 개수를 출력하는 알고리즘을 설계하라. 모든 문자는 문자열 내에서 고유하다고 가정할 것.
 입력 문자열로 abcdefg가 주어졌다고 해보자.
 
 Case “a” —-> {“a”} // 1
 Case “ab” —-> {“ab”, ”ba”} // 2
 Case “abc” —-> ?
 
 */

#include <iostream>
using namespace std;

int memo[1000];
int perm(int n){
    memo[0]=0;
    memo[1]=1;
    memo[2]=2;
    
    for(int i=3; i<=n; i++){
        memo[i] = memo[i-1]*i;
    }
    
    return memo[n];
    
}

int main() {
    int m;
    cin >> m;
    cout <<perm(m)<<endl; /* 외부 함수의 리턴값을 출력하고 싶을 때 위의 함수를 cout 안에 넣자!!!기억해!!  */
    
    return 0;
}

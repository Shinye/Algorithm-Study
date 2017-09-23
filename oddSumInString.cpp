
/*
 주어진 문자열에서 홀수인 숫자들의 제곱의 합을 출력한다.
 예) "ab2v9bc13j5jf4jv21" -> 9^2 + 13^2 + 5^2 + 21^2 = 716
 */

#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int sumOfOddNum(string inputStr){
    string numTmpStr = "";
    int sum = 0;
    vector<int> numArr;
    
    for(int i=0; i<inputStr.size(); i++){
        // ASCII코드에서 숫자(0~9)의 범위를 넘어가는 것은 숫자가 아니라는 뜻이니 필터링을 해준다.
        if(inputStr[i] < '0' || inputStr[i] > '9'){
            // 만약 지금까지 임시 배열에 누적된 숫자들이 있다면
            if(numTmpStr != "") {
                // 이 숫자가 홀수인지 짝수인지 판별한다.
                if(stoi(numTmpStr)%2 != 0){
                    numArr.push_back(pow(stoi(numTmpStr),2));
                }
                numTmpStr = "";
                
            } else{
                continue;
            }
            
        } else {
            numTmpStr += inputStr[i];
        }
    }
    
    if(numTmpStr != "" && stoi(numTmpStr)%2 != 0){
        numArr.push_back(pow(stoi(numTmpStr),2));
        numTmpStr = "";
    }
   
    for(int j=0; j<numArr.size(); j++){
        sum += numArr[j];
    }

    return sum;
}

int main() {
    string str;
    getline(cin, str);
    
    cout << "주어진 문자열에서 홀수인 숫자들의 제곱의 합은 " << sumOfOddNum(str) << "입니다." << endl;;
    
    return 0;
}


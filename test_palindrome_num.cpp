#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

int getInput(){
    string line;
    int number = 0;
    getline(cin,line);
    try{
        number = stoi(line);
    } catch(exception& e){ //  exception추가
        number = -1;
    }

    return number;
}

string reverse(int number){
    string numToString = to_string(number);
    //int strToNum;
    int start=0;
    int end=numToString.size()-1;

    for(; start<end; start++,end--){
        swap(numToString[start], numToString[end]);
    }
    //strToNum = stoi(numToString);

    return numToString;
}

int main(){
    int num = getInput();
    int sum;
    int sumReverse;
    bool flag;

    int limit = 3;
    //string reverseNum_string;
    int reverseNum;

    while(limit--){
        reverseNum = stoi(reverse(num));
        sum = num+reverseNum;

        sumReverse = stoi(reverse(sum));

        cout << "num : " << num << "reverseNum : " << reverseNum << "sum : " << sum << "reverseSum : " << sumReverse << endl;

        if(sum == sumReverse){
            flag = true;
            cout << "final sum : " << sum << endl;
            break;
        } else {
            flag = false;
            num = sum;
        }
    }

    if(flag == false){
        cout << -1 << endl;
    }


    return 0;
}

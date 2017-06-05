/*
 여러 개의 자연수를 표준 입력(standard input)에서 읽은 후, 그 수들을 이어붙여서 만들 수 있는 가장 큰 수와 가장 작은 수의 합을 구하세요.
 •	주어지는 입력은 10개 이하이며, 각각 2자리 이하의 자연수입니다.
 •	숫자는 공백으로만 구분됩니다.
 •	숫자를 이어붙일 때 입력된 각 숫자들을 반드시 한 번씩 사용해야 합니다.

 [예시 1]
 입력이 1 2 3일 경우, 만들 수 있는 가장 큰 수는 321이고 가장 작은 수는 123이며 두 수의 합은 444이다.
 따라서 결과는 다음과 같다.
 444

 [예시 2]
 입력이 2 9 10 21 24일 경우,
 만들 수 있는 가장 큰 수는 92422110이고, 가장 작은 수는 10212249이며 두 수의 합은 102634359
 따라서 결과는 다음과 같다.
 102634359

 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

vector<string> getInput(int limitnum){
    vector<string> tmp_arr;
    string str;
    getline(cin,str);

    istringstream foo(str);
    string token;

    while(getline(foo, token, ' ')){ // eof까지 while문을 돌린다.
        tmp_arr.push_back(token);
        if(tmp_arr.size() >= 10){
            break;
        }
    }

    return tmp_arr;
}

bool cmp_min(const string A, const string B){
    string tmpA = A, tmpB = B;

    if(tmpA.size() == 1){
        tmpA += tmpA;
    }
    if(tmpB.size() == 1){
        tmpB += tmpB;
    }

    return tmpA < tmpB;
}

bool cmp_max(const string A, const string B){
    string tmpA = A, tmpB = B;

    if(tmpA.size() == 1){
        tmpA += tmpA;
    }
    if(tmpB.size() == 1){
        tmpB += tmpB;
    }

    return tmpA > tmpB;
}


int main(){
    vector<string> tmp_array;
    string min_string = "";
    string max_string = "";
    int min_int;
    int max_int;
    int sum;


    int limitnum = 10;
    tmp_array = getInput(10);

    int length = tmp_array.size();

    sort(tmp_array.begin(),tmp_array.end(),cmp_min);
    for(int i=0; i<length; i++){
        string val;
        val = tmp_array[i];
        min_string += val;
    }

    sort(tmp_array.begin(), tmp_array.end(), cmp_max);
    for(int i=0; i<length; i++){
        string val;
        val = tmp_array[i];
        max_string += val;
    }

    min_int = stoi(min_string);
    max_int = stoi(max_string);
    sum = min_int+max_int;

    cout << sum << endl;

    return 0;
}

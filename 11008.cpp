#include <iostream>
#include <string>
#include <vector>

using namespace std;

int calc(string s, string p){
    int sLength = s.length();
    int pLength = p.length();
    string tmp="";
    int tmp_num=0;
    int cost = 0;
    int cost_tmp = 0;

    for(int i=0; i<sLength; i++){
        if(s[i] == p[tmp_num]){
            if(tmp_num == pLength-1) {
                cost+=1;
                tmp_num=0;
            } else {
                tmp_num+=1;
            }
        } else {
            if(tmp_num>0){
                cost = cost+tmp_num+1;
                tmp_num=0;
            } else{
                cost+=1;
            }
        }
    }
    return cost;
}

int main() {
    int t; // test case
    string s; // 작성하고자 하는 원래 문자열
    string p; //복사할 문자열
    cin >> t;
    vector <int> arr = {};
    int tmp;

    for(int i=0; i<t; i++){
        cin >> s >> p;
        tmp = calc(s,p);
        arr.push_back(tmp);
    }

    int arrSize = arr.size();
    for(int j=0; j<arrSize; j++){
        cout << arr[j] << endl;
    }

    return 0;
}

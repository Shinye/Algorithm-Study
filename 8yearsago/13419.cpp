#include <iostream>
#include <vector>
using namespace std;

int main(){
    
    string str;
    vector<string> strList; // 검사할 문자열들 저장하는 리스트
    
    
    int t; // 테스트 케이스 개수
    
    cin>>t;
    for(int j=0; j<t; j++){
        cin>>str;
        strList.push_back(str);
    }
    
    for(int k=0; k<t; k++) {
        string man1, man2;
        
        if(strList[k].size() % 2 == 0){ // 문자열 개수가 짝수인 경우
            for(int i=0; i<strList[k].size(); i++){
                if(i%2 == 0) {
                    man1 += strList[k][i];
                } else {
                    man2 += strList[k][i];
                }
            }
            cout << man1 << '\n';
            cout << man2 << '\n';
        }
        
        else{ //문자열 개수가 홀수인 경우
            if(strList[k].size() == 1){
                man1 = strList[k][0];
                man2 = strList[k][0];
                
                cout << man1 << '\n';
                cout << man2 << '\n';
            }
            else{
                for(int i=0; i<strList[k].size(); i++){
                    if(i%2 == 0) {
                        man1 += strList[k][i];
                    } else {
                        man2 += strList[k][i];
                    }
                }
                
                string temp1 = man1;
                string temp2 = man2;
                
                for(auto x:temp2){
                    if (man1[0] != x){
                        man1 += x;
                    } else {
                        break;
                    }
                }
                
                for(auto y:temp1){
                    if (man2[0] != y){
                        man2 += y;
                    } else {
                        break;
                    }
                }
                cout << man1 << '\n';
                cout << man2 << '\n';
            }
        }    
    }
}

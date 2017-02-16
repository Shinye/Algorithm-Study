#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    /*char c[] = "c string"; // c[0]=='c', c[1] == ' ', c[2] == 's' ...
    
    string s2 = c;
    cout << c[3] << endl;*/
    
    int cnt = 0;
    string s;
    while(cin >> s){
        cnt+=1;
    }
    
    cout << cnt << endl;
    return 0;
}


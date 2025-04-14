
/*
  문자열에서 처음으로 반복되지 않는 문자를 효율적으로 찾기
  ex) "teetr" -> 'r'
      "total" -> 'o'
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    string str;
    cin >> str;
    int index;
    int length = str.length();
    int dict[130];
    vector<int> indexNum;

    for(int i=0; i<130; i++){
        dict[i] = 0;
    }

    for(int j=0; j<length; j++){
        index = (int)str[j];
        cout << "index : " << index << endl;
        dict[index] += 1;
        indexNum.push_back(index);
    }

    int index_length = indexNum.size();
    for(int k = 0; k<index_length; k++){
        int num = indexNum[k];
        if(dict[num] == 1){
            cout << "알파벳 : " << (char)num << endl;
            return 0;
        }
    }

    return 0;
}

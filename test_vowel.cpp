#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
using namespace std;

vector<string> getWords(int limit){
    vector<string> arrTemp;
    string words;
    // 문자열 입력받음
    getline(cin,words);
    // 받은 문자열 stream변환
    istringstream iss(words);
    // stream변환한걸 벡터에 삽입
    string token;
    while(getline(iss,token,' ')){
        arrTemp.push_back(token);
        if(arrTemp.size()>10){
            break;
        }
    }
    return arrTemp;
}

int main(){
    vector<string> stringArr = getWords(10);
    int arrLength = stringArr.size();
    string moeum = "aeiou";
    int isMoeum_tmp = 0;
    int notMoeum_tmp = 0;
    int isMoeum = 0;
    int notMoeum = 0;

    for(int i=0; i<arrLength; i++){
        
        isMoeum_tmp = 0;
        notMoeum_tmp = 0;

        string token = stringArr[i];
        int tokenLength = token.size();
        cout<<"tokenlength : " << tokenLength << endl;

        for(int j=0; j<tokenLength; j++) {
            if(moeum.find(token[j]) != string::npos){
                notMoeum_tmp = 0;
                isMoeum_tmp +=1;
                if(isMoeum_tmp == 2){
                    isMoeum += 1;
                    cout << "this is moeum : " << token << endl;
                }

            } else {
                isMoeum_tmp = 0;
                notMoeum_tmp += 1;
                if(notMoeum_tmp == 3){
                    notMoeum += 1;
                    cout << "this is not moeum : " << token << endl;
                }
            }
        }
    }

    cout << "moeumResult : " << isMoeum << endl;
    cout << "notMoeumResult : " << notMoeum << endl;


    return 0;
}

/*int isVowel(){
 return 0;
 }

 int notVowel(){
 return 0;
 }*/

/*int main() {
    string words;
    vector<string> arr;

    while(cin>>words){
        arr.push_back(words);
    }

    int length = arr.size();


    int num_of_vowel = 0;
    int num_of_notVowel = 0;

    int isVowel = 0;
    int notVowel = 0;

    for(int i=0; i<length; i++){
        int word_length = arr[i].size();
        cout << "each word length : " << word_length << endl;

        if(isVowel == 1){
            num_of_vowel += 1;
        }
        if(notVowel == 1){
            num_of_notVowel += 1;
        }

        for(int j=0; j<word_length; j++) {

            if(j>0 && (isVowel==0 || notVowel==0)){
                if(arr[i][j-1]=='a'||arr[i][j-1]=='e'||arr[i][j-1]=='i'||arr[i][j-1]=='o'||arr[i][j-1]=='u'){
                    if(arr[i][j]=='a'||arr[i][j]=='e'||arr[i][j]=='i'||arr[i][j]=='o'||arr[i][j]=='u'){

                        cout << "===========" << endl;
                        //num_of_vowel+=1;
                        //cout << "number of vowel : " << num_of_vowel << endl;
                        isVowel = 1;
                        cout << "===========" << endl;
                    }
                } else if(arr[i][j-1]!='a'||arr[i][j-1]!='e'||arr[i][j-1]!='i'||arr[i][j-1]!='o'||arr[i][j-1]!='u'){
                    if(arr[i][j]!='a'||arr[i][j]!='e'||arr[i][j]!='i'||arr[i][j]!='o'||arr[i][j]!='u'){
                        cout << "===========" << endl;
                        //num_of_notVowel += 1;
                        //cout << "number of vowel : " << num_of_vowel << endl;
                        notVowel = 1;

                        cout << "===========" << endl;
                    }
                } else {}
            }
        }
    }

    //cout << "length : " << length << endl;
    //cout << "num : " << arr[0][2] << endl;

    return 0;
}*/

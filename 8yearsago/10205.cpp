#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int k; // data set의 개수
    int setNum = 1; // set number
    vector<pair<int,int>> actionPair;
    cin>>k;
    
    while(k>0){
        int h; // 히드라 머리 개수
        string action; // 공격 패턴
        
        cin>>h;
        cin>>action;
        
        for(auto x:action){
            if(x == 'c'){
                h+=1;
            } else if(x == 'b'){
                h-=1;
            } else{return 0;}
        }
        actionPair.push_back(make_pair(setNum, h));
        
        
        k--;
        setNum++;
    }
    
    int arrSize = actionPair.size();
    for(int i = 0; i<arrSize; i++){
        cout << "Data Set " << actionPair[i].first <<":"<<"\n";
        cout << actionPair[i].second<<"\n\n";
    }
}

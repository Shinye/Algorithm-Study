#include <iostream>
using namespace std;

int main(){
    int arr1[2];
    int arr2[2];
    int arr3[2];
    int arr4[2];
    
    for(int i=0; i<2; i++){
        cin >> arr1[i];
    }
    for(int i=0; i<2; i++){
        cin >> arr2[i];
    }
    for(int i=0; i<2; i++){
        cin >> arr3[i];
    }
    
    if(arr1[0] != arr2[0] && arr1[0] != arr3[0]){
        arr4[0] = arr1[0];
    } else if(arr1[0] == arr2[0]){
        arr4[0] = arr3[0];
    } else {
        arr4[0] = arr2[0];
    }
    
    if(arr1[1] != arr2[1] && arr1[1] != arr3[1]){
        arr4[1] = arr1[1];
    } else if(arr1[1] == arr2[1]){
        arr4[1] = arr3[1];
    } else {
        arr4[1] = arr2[1];
    }
    
    cout << arr4[0] << "," << arr4[1] << endl;
    
}

#include <iostream>
using namespace std;

int binarySearch(int answer, int *arr, int size){

    cout << "size : " << size << endl;
    int min = 0; int max = size-1;
    int avg;

    while(1){
        avg = (max+min)/2;
        cout << "avg : " << avg << endl;
        if(arr[avg] == answer){
            cout<< "found!" << endl;
            break;
        }
        else if(arr[avg] > answer){
            max = avg-1;
            cout << "max : " << max << endl;
        } else {
            min = avg+1;
            cout << "min : " << min << endl;
        }
    }
    return arr[avg];
}

int main(){
    int answer;
    cin >> answer;
    int arr[25] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

    cout << binarySearch(answer, arr, 25) << endl;;
}

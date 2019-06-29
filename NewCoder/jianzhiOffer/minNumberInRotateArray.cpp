#include<iostream>
#include<vector>
using namespace std;
//1 1 1 1 1 1 1 
//1 2 3 4 5 6 7 
//1 2 3 4 5 5 5 6 7 7 7 
int minNumberInRotateArray(vector<int> rotateArray) {
    if(rotateArray.size() == 0) return 0;
    for(int i = 0; i < rotateArray.size(); i++){
        if(rotateArray[i] > rotateArray[i + 1]) {
            return rotateArray[i + 1];
        }
    }
    return rotateArray[0];
}

int main() {
    return 0;
}
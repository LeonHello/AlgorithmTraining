#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void reOrderArray(vector<int> &array) {
    //1 2 3 4 5 6 7 8
    queue<int> tmp;
    for(vector<int>::iterator i = array.begin(); i != array.end();) {
        if(*i % 2 == 0) {
            tmp.push(*i);
            array.erase(i);
        }else i++;
    }
    while(!tmp.empty()){
        array.push_back(tmp.front());
        tmp.pop();
    }  
}

int main() {
    int arr[8] = {1,2,3,4,5,6,7,8};
    vector<int> a(arr, arr+8);
    reOrderArray(a);
    for(int i = 0; i < a.size(); i++) {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}
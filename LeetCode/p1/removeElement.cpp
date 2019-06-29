#include<iostream>
#include<vector>
using namespace std;

int removeElement(vector<int>& nums, int val) {
    for(vector<int>::iterator i = nums.begin(); i != nums.end(); i++){
        if(*i == val){
            nums.erase(i);
            i--;
        }
    }
    return nums.size();
}
int main(){
    int num[5] = {1,1,1,2,3};
    vector<int> nums(num, num + 5);
    cout<<removeElement(nums, 1)<<endl;
    return 0;
}
#include<iostream>
#include<vector>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    for(vector<int>::iterator i = nums.begin(); i != nums.end(); i++){
        for(vector<int>::iterator j = i + 1; j < nums.end();){
            if(*i == *j){
                nums.erase(j);
            }else{
                j++;
            }
        }
    }
    return nums.size();
}

int main(){
    int num[5] = {1,1,1,2,2};
    vector<int> nums(num, num + 5);
    removeDuplicates(nums);
    cout<<nums.size()<<endl;
    return 0;
}
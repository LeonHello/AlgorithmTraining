#include<iostream>
#include<vector>
#include<map>
using namespace std;
/*vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> res(2);
    map<int, int> mp;
    for (unsigned int i = 0; i < nums.size(); ++i) {
        map<int,int>::iterator it = mp.find(target - nums[i]);
        if (it != mp.end() && i != mp[target-nums[i]]) {
            if (i < mp[target - nums[i]]) {
                res[0] = i;
                res[1] = mp[target - nums[i]];
            } else {
                res[0] = mp[target - nums[i]];
                res[1] = i;
            }
            return res;
        }
        mp[nums[i]] = i;
    }
    return res;
}*/
vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> res(2);
    map<int, int> mp;
    for (unsigned int i = 0; i < nums.size(); ++i) {
        mp[nums[i]] = i;
    }
    for (unsigned int i = 0; i < nums.size(); ++i) {
        map<int,int>::iterator it = mp.find(target - nums[i]);
        if (it != mp.end() && i != mp[target-nums[i]]) {
            res[0] = i;
            res[1] = mp[target - nums[i]];
            return res;
        }
    }
    return res;
}
int main(){
    int arr[4] = {1,2,5,7};
    vector<int> num(arr, arr + 4);
    int target = 12;
    vector<int> res = twoSum(num, target);
    for(vector<int>::iterator i = res.begin(); i != res.end(); i++){
        cout<<*i<<endl;
    }
    cout<<num.size()<<endl;
    map<int, int> kv;
    kv[1000] = 100;
    kv[2000] = 200;
    map<int,int>::iterator it = kv.find(2000);
    cout<<it->second<<endl;
    for(map<int, int>::iterator i = kv.begin(); i != kv.end(); i++){
        cout<<i->first<<" "<<i->second<<endl;
    }
    return 0;
}
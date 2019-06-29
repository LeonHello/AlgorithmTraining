#include <iostream>
#include <vector>
using namespace std;
void dfs(vector<int> &nums, int S, int &res, int cnt, int sum)
{
    if (cnt == nums.size())
    {
        if (sum == S)
            res++;
        return;
    }
    dfs(nums, S, res, cnt + 1, sum + nums[cnt]);
    dfs(nums, S, res, cnt + 1, sum - nums[cnt]);
}
int findTargetSumWays(vector<int> &nums, int S)
{
    int res = 0;
    dfs(nums, S, res, 0, 0);
    return res;
}
int main(int argc, char **argv)
{
    int a[5] = {1,1,1,1,1};
    vector<int> arr(a, a+5);
    cout<<findTargetSumWays(arr, 3)<<endl;
    return 0;
}
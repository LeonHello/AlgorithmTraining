#include <iostream>
#include <vector>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
vector<vector<int> > res;
void dfs(TreeNode *root, vector<int> t, int sum)
{
    if (!root)
        return;
    t.push_back(root->val);
    if (!root->left && !root->right && root->val == sum)
    {
        res.push_back(t);
        t.pop_back();
        return;
    }
    dfs(root->left, t, sum - root->val);
    dfs(root->right, t, sum - root->val);
    t.pop_back();
}
vector<vector<int> > pathSum(TreeNode *root, int sum)
{
    vector<int> t;
    dfs(root, t, sum);
    return res;
}



int main(int argc, char *argv[])
{
    return 0;
}
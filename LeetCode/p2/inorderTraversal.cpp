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
vector<int> ans;
void inorderRecursion(TreeNode *root)
{
    if (!root)
        return;
    inorderRecursion(root->left);
    ans.push_back(root->val);
    inorderRecursion(root->right);
}
vector<int> inorderTraversal(TreeNode *root)
{
    inorderRecursion(root);
    return ans;
}
int main(int argc, char *argv[])
{
    return 0;
}
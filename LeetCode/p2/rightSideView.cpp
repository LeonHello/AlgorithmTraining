#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> rightSideView(TreeNode *root)
{
    vector<int> res;
    if (!root)
        return res;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        res.push_back(q.back()->val);
        queue<TreeNode *> qq;
        while (!q.empty())
        {
            TreeNode *t = q.front();
            q.pop();
            if (t->left)
            {
                qq.push(t->left);
            }
            if (t->right)
                qq.push(t->right);
        }
        q = qq;
    }
    return res;
}

int main(int argc, char *argv[])
{

    return 0;
}
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

int maxh = -1;
int res = -1;

void dfs(TreeNode *t, int h)
{
    if (!t)
        return;
    if (h > maxh)
    {
        maxh = h;
    }
    if (!t->right && !t->left && h >= maxh)
    {
        res = t->val;
        return;
    }

    dfs(t->right, h+1);

    dfs(t->left, h+1);
}

int findBottomLeftValue(TreeNode *root)
{
    dfs(root, 0);
    return res;
}

int findBottomLeftValue1(TreeNode *root)
{
    if (!root->left && !root->right)
        return root->val;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        queue<TreeNode *> qq;
        int flag = 0;
        while (!q.empty())
        {
            TreeNode *t = q.front();
            q.pop();
            if (t->left)
            {
                qq.push(t->left);
                if (t->left->left || t->left->right)
                    flag = 1;
            }
            if (t->right)
            {
                qq.push(t->right);
                if (t->right->left || t->right->right)
                    flag = 1;
            }
        }
        if (flag)
            q = qq;
        else
            return qq.front()->val;
    }
    return 0;
}

int main(int argc, char **argv)
{
    TreeNode root1(1);
    TreeNode root2(2);
    TreeNode root3(3);
    TreeNode root4(4);
    TreeNode root5(5);
    TreeNode root6(6);
    TreeNode root7(7);
    TreeNode root8(8);
    TreeNode root9(9);
    root1.left = &root2;
    root2.left = &root3;
    root3.left = &root4;
    root4.left = &root5;
    root5.left = &root6;
    root6.left = &root7;
    root6.right = &root8;
    root7.right = &root9;
    cout << findBottomLeftValue1(&root1) << endl;
    cout << findBottomLeftValue(&root1) << endl;
    cout << endl;
    return 0;
}
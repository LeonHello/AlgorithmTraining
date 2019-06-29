#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool isEqualTree(TreeNode *p, TreeNode *q)
{
    if (!p && !q)
        return true;
    if (!p || !q || p->val != q->val)
        return false;
    return isEqualTree(p->left, q->left) && isEqualTree(p->right, q->right);
}

bool isSubtree(TreeNode *s, TreeNode *t)
{
    bool res = false;
    if (s && t)
    {
        if (s->val == t->val)
            res = isEqualTree(s, t);
        if (!res)
            res = isSubtree(s->left, t) || isSubtree(s->right, t);
    }
    return res;
}

int main(int argc, char *argv[])
{
    return 0;
}
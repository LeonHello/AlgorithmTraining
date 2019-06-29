#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct TreeNode *reConstructBinaryTree(vector<int> pre, vector<int> vin) {
    int vinlen = vin.size();
    if (vinlen == 0)
        return NULL;

    vector<int> left_pre, right_pre, left_vin, right_vin;

    //创建根节点，根节点肯定是前序遍历的第一个数
    TreeNode *head = new TreeNode(pre[0]);

    //找到中序遍历根节点所在位置,存放于变量gen中
    int gen = 0;
    for (int i = 0; i < vinlen; i++) {
        if (vin[i] == pre[0]) {
            gen = i;
            break;
        }
    }
    //对于中序遍历，根节点左边的节点位于二叉树的左边，根节点右边的节点位于二叉树的右边
    //利用上述这点，对二叉树节点进行归并
    for (int i = 0; i < gen; i++) {
        left_vin.push_back(vin[i]);
        left_pre.push_back(pre[i + 1]);//前序第一个为根节点
    }

    for (int i = gen + 1; i < vinlen; i++) {
        right_vin.push_back(vin[i]);
        right_pre.push_back(pre[i]);
    }

    //和shell排序的思想类似，取出前序和中序遍历根节点左边和右边的子树
    //递归，再对其进行上述所有步骤，即再区分子树的左、右子子数，直到叶节点
    head->left = reConstructBinaryTree(left_pre, left_vin);
    head->right = reConstructBinaryTree(right_pre, right_vin);
    return head;
}

int main() {

    return 0;
}
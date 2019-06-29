#include<iostream>
using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};
class Solution {
	bool doesP1HasP2(TreeNode* p1, TreeNode* p2) {
		if(!p2) return true;
		if(!p1) return false;
		if(p1->val != p2->val) return false;
		return doesP1HasP2(p1->left, p2->left) && doesP1HasP2(p1->right, p2->right);
	}
public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
		bool res = false;
        if(!pRoot1 || !pRoot2) return res;
		if(pRoot1->val == pRoot2->val) res = doesP1HasP2(pRoot1, pRoot2);
		if(!res) res = HasSubtree(pRoot1->left, pRoot2);
		if(!res) res = HasSubtree(pRoot1->right, pRoot2);
		return res;
    }
};
int main() {
    return 0;
}
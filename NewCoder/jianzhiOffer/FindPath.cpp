#include<iostream>
#include<vector>
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
    vector<vector<int> > res;
    vector<int> tmp;
    void dfs(TreeNode* root, int e) {
        tmp.push_back(root->val);
        if(e - root->val == 0 && !root->left && !root->right) {
            res.push_back(tmp);
        }
        if(root->left) {
            dfs(root->left, e - root->val);
        }
        if(root->right) {
            dfs(root->right, e - root->val);
        }
        tmp.pop_back();
    }
public:
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        if(!root) return res;
        dfs(root, expectNumber);
        return res;
    }
};

int main() {

    return 0;
}
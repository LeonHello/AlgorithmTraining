#include<iostream>
#include<vector>
#include<queue>
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
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int> ans;
		if(root == NULL) return ans;
		queue<TreeNode*> q;
		q.push(root);
		while(!q.empty()) {
			TreeNode* front = q.front();
			ans.push_back(front->val);
			q.pop();
			if(front->left) q.push(front->left);
			if(front->right) q.push(front->right);
		}
		return ans;
    }
};

int main(){

    return 0;
}
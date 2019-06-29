#include<iostream>
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        if(pHead == nullptr) return nullptr;
        ListNode *ans = nullptr;
        ListNode *p = pHead;
        while(p){
            ListNode *tmp = p->next;
            p->next = ans;
            ans = p;
            p = tmp;
        }
        return ans;
    }
};

int main() {

    return 0;
}
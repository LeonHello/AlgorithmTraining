#include<iostream>
using namespace std;
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
    }
};

ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
    if(pHead1 == nullptr) return pHead2;
    if(pHead2 == nullptr) return pHead1;
    ListNode* p1 = pHead1;
    ListNode* p2 = pHead2;
    ListNode ans(0);
    ListNode* p = &ans;
    ListNode* cur = &ans;
    while(p1 && p2) {
        if(p1->val <= p2->val) {
            cur = p1;
            p1 = p1->next;
        }
        else {
            cur = p2;
            p2 = p2->next;
        }
        p->next = cur;
        p = cur;
    }
    if(p1) {
        p->next = p1;
    }
    if(p2) {
        p->next = p2;
    }
    return ans.next;
}
int main() {

    return 0;
}
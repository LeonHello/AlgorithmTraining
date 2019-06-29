#include<iostream>
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x): val(x), next(NULL) {}
};

ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
    if(pListHead == nullptr || k <= 0) return nullptr;
    ListNode start(-1);
    ListNode *first = &start;
    ListNode *second = &start;
    start.next = pListHead;
    while(k--) {
        if(second->next)
            second = second->next;
        else return nullptr;
    }
    while(second->next) {
        second = second->next;
        first = first->next;
    }
    return first->next;
}

int main() {
    return 0;
}
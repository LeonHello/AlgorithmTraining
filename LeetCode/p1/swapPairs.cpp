#include<iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x):val(x), next(nullptr){}
};
ListNode* swapPairs(ListNode* head) {
    if(head == nullptr || head->next == nullptr)return head;
    ListNode phead(0);
    phead.next = head;
    ListNode* h = &phead;
    while(h->next->next){
        ListNode* parent = h;
        ListNode* p = parent->next;
        ListNode* q = p->next;
        p->next = q->next;
        q->next = p;
        parent->next = q;
        h = h->next->next;
        if(h->next == nullptr) break;
    }
    return phead.next;
}
int main(int argc, char **argv) {
    
    return 0;
}
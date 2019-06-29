#include<iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
ListNode* deleteDuplicates(ListNode* head) {
    if(head == NULL) return head;
    ListNode* p = head;
    int temp = p->val;
    while(p->next){
        ListNode cur = *(p->next);
        if(cur.val == temp){
            //delete node
            p->next = cur.next;
        }
        else{
            //change the value of temp
            temp = cur.val;
            p = p->next;
        }
    }
    return head;
}

int main(){
    ListNode ans(-1);
    ListNode* p = &ans;
    deleteDuplicates(p);
    return 0;
}
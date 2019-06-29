#include<iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode ans(-1);
    ListNode* head = &ans;
    ListNode* p = head;
    
    int carry = 0;
    int sum = 0;
    int a = 0, b = 0;
    while(l1 || l2){
        if(l1)a = l1->val;
        else a = 0;
        if(l2)b = l2->val;
        else b = 0;
        sum = a + b + carry;
        if(sum > 9){
            carry = 1;
            sum %= 10;
        }
        else{
            carry = 0;
        }
        ListNode* newNode = new ListNode(sum);
        p->next = newNode;
        p = p->next;
        if(l1)l1 = l1->next;
        if(l2)l2 = l2->next;
    }
    if(carry){
        ListNode* newNode1 = new ListNode(1);
        p->next = newNode1;
        p = p->next;
    }
    return head->next;
}

int main(){

}
#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode start(0);
    ListNode* second = &start;
    start.next = head;
    ListNode* first = head;
    while(n--){
        first = first->next;
    }
    while(first != NULL){
        first = first->next;
        second = second->next;
    }
    second->next = second->next->next;
    return start.next;
}

int main(){

}
#include<iostream>
#include<vector>
using namespace std;
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x): val(x), next(NULL) {}
};

vector<int> printListFromTailToHead(ListNode* head) {
    vector<int> ans;
    ListNode* p = head;
    while(p){
        ans.push_back(p->val);
        p = p->next;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main(){
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    vector<int> a(arr, arr + 10);
    reverse(a.begin(), a.end());
    for(int i = 0; i < a.size(); i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}
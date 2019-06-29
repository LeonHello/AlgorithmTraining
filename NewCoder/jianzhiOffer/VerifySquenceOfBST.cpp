#include<iostream>
#include<vector>
using namespace std;
bool judge(vector<int> & a, int l, int r) {
    if(l >= r) return true;
    int i = r - 1;
    while(i >= l && a[i] > a[r]) i--;
    for(int j = l; j < i; j++) {
        if(a[j] > a[r])
            return false;
    }
    return judge(a, l, i) && judge(a, i + 1, r - 1);
}
bool VerifySquenceOfBST(vector<int> sequence) {
    if(sequence.size() == 0) return false;
    return judge(sequence, 0, sequence.size() - 1);
}


int main() {

    return 0;
}
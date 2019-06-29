#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
    bool Find(int target, vector<vector<int> > array){
        int RowNum = array.size();
        int ColNum = array[0].size(); 
        //从左下角开始查找，上面小，右边大
        int i, j;
        for(i = RowNum - 1, j = 0; i >= 0 && j < ColNum; ){
            if(target == array[i][j]) return true;
            if(target < array[i][j]){
                i--;
                continue;
            }
            if(target > array[i][j]){
                j++;
                continue;
            }
        }
        return false;
    }
};


int main(){

    cout<<endl;
    return 0;
}
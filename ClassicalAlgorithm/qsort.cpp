#include<iostream>
using namespace std;
int oneQsort(int *a, int low, int high){
    int temp = a[low];
    int j = high;
    int i = low;
    while(i < j){
        while(i < j && a[j] >= temp)
            j--;
        if(i < j){
            a[i] = a[j];
            // i++;
        }
        while(i < j && a[i] <= temp)
            i++;
        if(i < j){
            a[j] = a[i];
            // j--;
        }
    }
    a[i] = temp;
    return i;
}
void qSort(int *a, int low, int high){
    if(low >= high) return;
    int i = oneQsort(a, low, high);
    qSort(a, low, i - 1);
    qSort(a, i + 1, high);
}

int main(){
    int a[10] = {9,8,7,6,5,4,3,2,1,0};
    qSort(a, 0, 9);
    for(int i = 0; i < 10; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}
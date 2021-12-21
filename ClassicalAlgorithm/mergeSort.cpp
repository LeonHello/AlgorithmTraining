#include <iostream>
#include <vector>
using namespace std;

void mergeSort(vector<int> &nums, int left, int right)
{
    if (left == right)
        return;
    int mid = left + (right - left) / 2;
    mergeSort(nums, left, mid);
    mergeSort(nums, mid + 1, right);

    // 一次归并排序
    int i = left, j = mid + 1;
    vector<int> tmp;
    while (i <= mid && j <= right)
    {
        if (nums[i] < nums[j])
            tmp.push_back(nums[i++]);

        else
            tmp.push_back(nums[j++]);
    }
    while (i <= mid)
        tmp.push_back(nums[i++]);
    while (j <= right)
        tmp.push_back(nums[j++]);

    for (int k = left, l = 0; k <= right; ++k)
    {
        nums[k] = tmp[l++];
    }
}

int main(int argc, char *argv[])
{
    vector<int> a = {10, 100, 2999, -1, 909, 3, 4, 5, 6};
    mergeSort(a, 0, a.size() - 1);
    for (auto i : a)
        cout << i << " ";
    cout << endl;
    return 0;
}

#include <iostream>
#include <vector>
using namespace std;

void qSort(vector<int> &nums, int left, int right)
{
    if (left >= right)
        return;
    int tmp = nums[left];
    int i = left, j = right;
    while (i < j)
    {
        while (i < j && nums[j] > tmp)
            --j;
        if (i < j)
            nums[i++] = nums[j];
        while (i < j && nums[i] < tmp)
            ++i;
        if (i < j)
            nums[j--] = nums[i];
    }
    nums[i] = tmp;

    qSort(nums, left, i - 1);
    qSort(nums, i + 1, right);
}

int main(int argc, char *argv[])
{
    vector<int> a = {10, 100, 2999, -1, 909, 3, 4, 5, 6};
    qSort(a, 0, a.size() - 1);
    for (auto i : a)
        cout << i << " ";
    cout << endl;
    return 0;
}

#include <iostream>
#include <vector>
using namespace std;
void sortColors(vector<int> &nums)
{
    int p1 = 0;
    int p2 = nums.size() - 1;
    int cur = 0;
    while (cur <= p2)
    {
        if (nums[cur] == 0)
        {
            int temp = nums[p1];
            nums[p1] = nums[cur];
            nums[cur] = temp;
            cur++;
            p1++;
        }
        else if (nums[cur] == 2)
        {
            int temp = nums[p2];
            nums[p2] = nums[cur];
            nums[cur] = temp;
            p2--;
        }
        else
        {
            cur++;
        }
    }
}
int main(int argc, char *argv[])
{
    vector<int> t(10);
    for (int i = 0; i < t.size(); i++)
    {
        if (i % 3 == 0)
            t[i] = 0;
        else if (i % 3 == 1)
            t[i] = 1;
        else
            t[i] = 2;
    }
    for (int i = 0; i < t.size(); i++)
    {
        cout << t[i] << "  ";
    }
    cout << endl;
    sortColors(t);
    for (int i = 0; i < t.size(); i++)
    {
        cout << t[i] << "  ";
    }
    cout << endl;
    return 0;
}
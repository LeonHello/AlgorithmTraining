#include <iostream>
#include <vector>
using namespace std;
bool canFinish(int numCourses, vector<vector<int> > &prerequisites)
{
    int rudu[numCourses];
    memset(rudu, 0, sizeof(rudu));
    for (int i = 0; i < prerequisites.size(); ++i)
    {
        int s = prerequisites[i][0];
        rudu[s]++;
    }
    int i = 0;
    int cnt = 0;
    while (i != numCourses)
    {
        for (i = 0; i < numCourses; ++i)
        {
            if (rudu[i] == 0)
            {
                rudu[i] = -1;
                cnt++;
                break;
            }
        }
        for (int j = 0; j < prerequisites.size(); ++j)
        {
            if (i == prerequisites[j][1])
            {
                rudu[prerequisites[j][0]]--;
            }
        }
    }
    if (cnt == numCourses && cnt != 0)
        return true;
    else
        return false;
}

int main()
{
    return 0;
}
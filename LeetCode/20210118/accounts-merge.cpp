#include <bits/stdc++.h>
using namespace std;
class UFset
{
public:
    vector<int> fa;
    vector<int> rank;
    UFset(int n)
    {
        fa = vector<int>(n);
        rank = vector<int>(n,1);
        for (int i = 0; i < n; ++i)
            fa[i] = i;
    }
    int find(int x)
    {
        return x == fa[x] ? fa[x] : (fa[x] = find(fa[x]));
    }

    void merge(int x,int y){
        int xx = find(x);
        int yy = find(y);
        if(xx != yy){
            if(rank[xx] <= rank[yy]){
                fa[xx] = yy;
            }else fa[yy] = xx;
            if(rank[xx] == rank[yy]) rank[yy]++;
        }
    }

};
class Solution
{
public:
    vector<vector<string> > accountsMerge(vector<vector<string> > &accounts)
    {
        //给每个邮箱找到自己的账户id，账户id为0到accounts.size()-1
        unordered_map<string, int> um;
        int n = accounts.size();
        UFset ufset(n);
        for(int i = 0; i < n; ++i){
            int m = accounts[i].size();
            for(int j = 1; j < m; ++j){
                if(um.find(accounts[i][j]) == um.end()){
                    //没找到该邮箱
                    um[accounts[i][j]] = i;
                }else ufset.merge(i, um[accounts[i][j]]);
            }
        }
        //将账户id对应的所有邮箱找到
        unordered_map<int, vector<string> > umm;
        for(auto& [k,v] : um){
            umm[ufset.find(v)].push_back(k);
        }

        //转化为要求格式
        vector<vector<string> > res;
        for(auto& [k,v] : umm){
            vector<string> t(1, accounts[k][0]);
            sort(v.begin(), v.end());
            t.insert(t.end(), v.begin(), v.end());
            res.push_back(t);
        }
        return res;
    }
};

int main(int argc, char *argv[])
{
    vector<int> x = vector<int>(10,1);
    x.insert(x.end(), 11);
    cout<<x[10]<<endl;
    x.push_back(12);
    cout<<x[11]<<endl;
    cout << x.size()<<endl;
    return 0;
}

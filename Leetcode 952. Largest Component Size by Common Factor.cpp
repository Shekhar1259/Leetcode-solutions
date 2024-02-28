#include<bits/stdc++.h>
using namespace std;

class DSU
{
    public:
    vector<int> p,si;

    DSU(int n)
    {
        p.resize(n+1);
        si.resize(n+1,1);
        for(int i=0;i<=n;++i) p[i]=i;
    }

    int finduparent(int node)
    {
        if(p[node]==node)return node;

        return p[node]=finduparent(p[node]);
    }

    void union1(int u,int v)
    {
        int mp_u=finduparent(u);
        int mp_v=finduparent(v);
        if(mp_v==mp_u) return;

        if(si[mp_v]>si[mp_u])
        {
            si[mp_v]+=si[mp_u];
            p[mp_u]=mp_v;
        }
        else
        {
            si[mp_u]+=si[mp_v];
            p[mp_v]=mp_u;
        }
    }
};

set<int> p(int n)
{
    set<int> s;
    if(n%2==0)
    {
        s.insert(2);
        while(n%2==0) n/=2;
    }

    for(int i=3;i<=sqrt(n);++i)
    {
        if(n%i==0)
        {
            s.insert(i);
            while(n%i==0) n/=i;
        }
    }
    if(n>2) s.insert(n);

    return s;
}
class Solution {
public:
    int largestComponentSize(vector<int>& nums) {
        int n=nums.size();
        DSU ds(n);
        map<int,int> mp;
        for(int i=0;i<n;++i)
        {
            if(nums[i]!=1)
            {
                set<int> prime=p(nums[i]);
                for(auto it:prime)
                {
                    auto it1=mp.find(it);
                    if(it1==mp.end())
                    {
                        mp[it]=i;
                    }
                    else
                    {
                        ds.union1(i,it1->second);
                    }
                }

            }
            
        }
        int maxi=1;

        for(int i=0;i<n;++i)
        {
            maxi=max(maxi,ds.si[i]);
        }
        return maxi;

    }
};
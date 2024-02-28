class DSU
{
    public:
    vector<int> si,p;

    DSU(int n)
    {
        si.resize(n+1,1);
        p.resize(n+1);
        for(int i=0;i<=n;++i) p[i]=i;
    }

    int finduparent(int node)
    {
        if(node==p[node]) return node;

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

class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& p) {
        int m=p.size();
        int n=s.size();
        DSU ds(n);
        for(int i=0;i<m;++i)
        {
            ds.union1(p[i][0],p[i][1]);
        }

        map<int,multiset<char>> mp;
        for(int i=0;i<n;++i)
        {
            mp[ds.finduparent(i)].insert(s[i]);

        }

        string ans="";
        for(int i=0;i<n;++i)
        {
            int x=ds.finduparent(i);
            auto it=mp.find(x);
            if(it!=mp.end())
            {
                ans+= *(it->second.begin());
                it->second.erase(it->second.begin());
            }
        }

        return ans;
    }
};
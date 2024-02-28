class DSU
{
    public:
    vector<int> p,si;

    DSU(int n)
    {
        si.resize(n+1,1);
        p.resize(n+1);
        for(int i=0;i<=n;++i) p[i]=i;
    }
    int fp(int node)
    {
        if(p[node]==node) return node;

        return p[node]=fp(p[node]);
    }

    void union1(int u,int v)
    {
        int pu=fp(u);
        int pv=fp(v);

        if(pu==pv) return;

        if(si[pv]>si[pu])
        {
            si[pv]+=si[pu];
            p[pu]=pv;
        }
        else
        {
            si[pu]+=si[pv];
            p[pv]=pu;
        }
    }
};

class Solution {
public:
    int minScore(int n, vector<vector<int>>& r) {
        
        DSU ds(n);
        for(int i=0;i<r.size();++i)
        {
            ds.union1(r[i][0]-1,r[i][1]-1);

        }
        int par= ds.fp(n-1);
        //cerr<<par<<endl;
        int mini=1e9;

        for(int i=0;i<r.size();++i)
        {
            if(ds.fp(r[i][0]-1)==par) mini=min(mini,r[i][2]);
        }
        return mini;

    }
};
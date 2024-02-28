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
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        
        int n=vals.size();
        int ans=0;
        DSU ds(n);
        map<int,set<int>> mp;
        for(int i=0;i<n;++i)
        {
            mp[vals[i]].insert(i);
        }
        vector<vector<int>> adj(n);
        for(int i=0;i<edges.size();++i)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        for(auto it:mp)
        {
            for(auto it1 : it.second)
            {
                for(int i=0;i<adj[it1].size();++i)
                {
                    if(vals[adj[it1][i]]<=it.first)
                    {
                        ds.union1(it1,adj[it1][i]);
                    }
                }
            }

            map<int,int>  mp1;
            for(auto it1 : it.second)
            {
                mp1[ds.finduparent(it1)]++;
            }

            for(auto it1:mp1)
            {
                if(it1.second>=2)
                {
                    ans+=((it1.second *(it1.second-1))/2);
                }
            }
        }

    return ans+n;

    }
};
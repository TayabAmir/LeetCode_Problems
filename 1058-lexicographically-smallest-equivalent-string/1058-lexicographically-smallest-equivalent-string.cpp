class DSU
{
public:
    int V;
    vector<int> parent;

    DSU(int V)
    {
        this->V = V;
        parent.resize(V);

        for (int i = 0; i < V; i++)
        {
            parent[i] = i;
        }
    }

    int find(int node)
    {
        if (node != parent[node])
        {
            parent[node] = find(parent[node]);
        }
        return parent[node];
    }

    void unite(int u, int v) 
    {
        int p1 = find(u);
        int p2 = find(v);

        if(p1 == p2) return;
        if(p1 < p2) parent[p2] = p1;
        else parent[p1] = p2;
    }
};

class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string b) {
        DSU dsu(26);
        int n = s1.length();
        for(int i = 0; i < n; i++){
            dsu.unite(s1[i]-'a', s2[i]-'a');
        }
        string out = "";
        for(char c : b){
            out += (dsu.find(c-'a')+'a');
        }
        return out;
    }
};